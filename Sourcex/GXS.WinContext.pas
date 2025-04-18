//
// The graphics engine GLXEngine. The unit of GXScene for Delphi
//
unit GXS.WinContext;

(* Cross-platform context. *)

interface

{$I Stage.Defines.inc}

uses
  Winapi.Windows,
  Winapi.Messages,
  System.SysUtils,
  System.Classes,
  FMX.Forms,
  FMX.Dialogs,
  FMX.Platform.Win,


  GXS.Context,
  GXS.State,

  Stage.OpenGL4,
  Stage.Strings,
  Stage.VectorGeometry;

type
  // A context driver for standard Windows OpenGL
  TgxWinContext = class(TgxContext)
  protected
    FDC: HDC;
    FRC: HGLRC;
    FShareContext: TgxWinContext;
    FHPBUFFER: Integer;
    FiAttribs: packed array of Integer;
    FfAttribs: packed array of Single;
    FLegacyContextsOnly: Boolean;
    FSwapBufferSupported: Boolean;
    procedure SpawnLegacyContext(aDC: HDC); // used for WGL_pixel_format soup
    procedure CreateOldContext(aDC: HDC); virtual;
    procedure CreateNewContext(aDC: HDC); virtual;
    procedure ClearIAttribs;
    procedure AddIAttrib(attrib, value: Integer);
    procedure ChangeIAttrib(attrib, newValue: Integer);
    procedure DropIAttrib(attrib: Integer);
    procedure ClearFAttribs;
    procedure AddFAttrib(attrib, value: Single);
    procedure DestructionEarlyWarning(sender: TObject);
    procedure ChooseWGLFormat(DC: HDC; nMaxFormats: Cardinal; piFormats: PInteger; var nNumFormats: Integer; 
	  BufferCount: Integer = 1);
    procedure DoCreateContext(ADeviceHandle: THandle); override;
    procedure DoCreateMemoryContext(OutputDevice: THandle; Width, Height: Integer; BufferCount: Integer); override;
    function DoShareLists(aContext: TgxContext): Boolean; override;
    procedure DoDestroyContext; override;
    procedure DoActivate; override;
    procedure DoDeactivate; override;
    (* DoGetHandles must be implemented in child classes,
      and return the display + window *)
  public
    constructor Create; override;
    destructor Destroy; override;
    function IsValid: Boolean; override;
    procedure SwapBuffers; override;
    function RenderOutputDevice: Pointer; override;
    property DC: HDC read FDC;
    property RC: HGLRC read FRC;
  end;

function CreateTempWnd: HWND;

var
  (* This boolean controls a hook-based tracking of top-level forms destruction,
    with the purpose of being able to properly release OpenGL contexts before
    they are (improperly) released by some drivers upon top-level form
    destruction. *)
  vUseWindowTrackingHook: Boolean = True;

implementation // ------------------------------------------------------------

var
  vTrackingCount: Integer;
  vTrackedHwnd: array of HWND;
  vTrackedEvents: array of TNotifyEvent;
  vTrackingHook: HHOOK;

function TrackHookProc(nCode: Integer; wParam: wParam; lParam: lParam): Integer; stdcall;
var
  i: Integer;
  p: PCWPStruct;
begin
  if nCode = HC_ACTION then
  begin
    p := PCWPStruct(lParam);
    // if (p.message=WM_DESTROY) or (p.message=WM_CLOSE) then begin // destroy & close variant
    if p.message = WM_DESTROY then
    begin
      // special care must be taken by this loop, items may go away unexpectedly
      i := vTrackingCount - 1;
      while i >= 0 do
      begin
        if IsChild(p.HWND, vTrackedHwnd[i]) then
        begin
          // got one, send notification
          vTrackedEvents[i](nil);
        end;
        Dec(i);
        while i >= vTrackingCount do
          Dec(i);
      end;
    end;
    CallNextHookEx(vTrackingHook, nCode, wParam, lParam);
    Result := 0;
  end
  else
    Result := CallNextHookEx(vTrackingHook, nCode, wParam, lParam);
end;

procedure TrackWindow(h: HWND; notifyEvent: TNotifyEvent);
begin
  if not IsWindow(h) then
    Exit;
  if vTrackingCount = 0 then
    vTrackingHook := SetWindowsHookEx(WH_CALLWNDPROC, @TrackHookProc, 0, GetCurrentThreadID);
  Inc(vTrackingCount);
  SetLength(vTrackedHwnd, vTrackingCount);
  vTrackedHwnd[vTrackingCount - 1] := h;
  SetLength(vTrackedEvents, vTrackingCount);
  vTrackedEvents[vTrackingCount - 1] := notifyEvent;
end;

procedure UnTrackWindow(h: HWND);
var
  i, k: Integer;
begin
  if not IsWindow(h) then
    Exit;
  if vTrackingCount = 0 then
    Exit;
  k := 0;
  for i := 0 to MinInteger(vTrackingCount, Length(vTrackedHwnd)) - 1 do
  begin
    if vTrackedHwnd[i] <> h then
    begin
      if (k <> i) then
      begin
        vTrackedHwnd[k] := vTrackedHwnd[i];
        vTrackedEvents[k] := vTrackedEvents[i];
      end;
      Inc(k);
    end
  end;
  if (k >= vTrackingCount) then
    Exit;
  Dec(vTrackingCount);
  SetLength(vTrackedHwnd, vTrackingCount);
  SetLength(vTrackedEvents, vTrackingCount);
  if vTrackingCount = 0 then
    UnhookWindowsHookEx(vTrackingHook);
end;

var
  vUtilWindowClass: TWndClass = (style: 0; lpfnWndProc: @DefWindowProc;
  cbClsExtra: 0; cbWndExtra: 0; hInstance: 0; hIcon: 0;
  hCursor: 0; hbrBackground: 0; lpszMenuName: nil; lpszClassName: 'GXSUtilWindow');

function CreateTempWnd: HWND;
var
  classRegistered: Boolean;
  tempClass: TWndClass;
begin
  vUtilWindowClass.hInstance := hInstance;
  classRegistered := GetClassInfo(hInstance, vUtilWindowClass.lpszClassName, tempClass);
  if not classRegistered then
  ///  RegisterClass(vUtilWindowClass) - to do for FMX ;
  Result := CreateWindowEx(WS_EX_TOOLWINDOW, vUtilWindowClass.lpszClassName, '', WS_POPUP, 0, 0, 0, 0, 0, 0, hInstance, nil);
end;

// ------------------
// ------------------ TgxSceneContext ------------------
// ------------------

constructor TgxWinContext.Create;
begin
  inherited Create;
  ClearIAttribs;
  ClearFAttribs;
end;

destructor TgxWinContext.Destroy;
begin
  inherited Destroy;
end;

function SetupPalette(DC: HDC; PFD: TPixelFormatDescriptor): HPalette;
var
  nColors, i: Integer;
  LogPalette: TMaxLogPalette;
  RedMask, GreenMask, BlueMask: Byte;
begin
  nColors := 1 shl PFD.cColorBits;
  LogPalette.palVersion := $300;
  LogPalette.palNumEntries := nColors;
  RedMask := (1 shl PFD.cRedBits) - 1;
  GreenMask := (1 shl PFD.cGreenBits) - 1;
  BlueMask := (1 shl PFD.cBlueBits) - 1;
  with LogPalette, PFD do
    for i := 0 to nColors - 1 do
    begin
      palPalEntry[i].peRed := (((i shr cRedShift) and RedMask) * 255) div RedMask;
      palPalEntry[i].peGreen := (((i shr cGreenShift) and GreenMask) * 255) div GreenMask;
      palPalEntry[i].peBlue := (((i shr cBlueShift) and BlueMask) * 255) div BlueMask;
      palPalEntry[i].peFlags := 0;
    end;

  Result := CreatePalette(PLogPalette(@LogPalette)^);
  if Result <> 0 then
  begin
    SelectPalette(DC, Result, False);
    RealizePalette(DC);
  end
  else
    RaiseLastOSError;
end;

procedure TgxWinContext.ClearIAttribs;
begin
  SetLength(FiAttribs, 1);
  FiAttribs[0] := 0;
end;

procedure TgxWinContext.AddIAttrib(attrib, value: Integer);
var
  n: Integer;
begin
  n := Length(FiAttribs);
  SetLength(FiAttribs, n + 2);
  FiAttribs[n - 1] := attrib;
  FiAttribs[n] := value;
  FiAttribs[n + 1] := 0;
end;

procedure TgxWinContext.ChangeIAttrib(attrib, newValue: Integer);
var
  i: Integer;
begin
  i := 0;
  while i < Length(FiAttribs) do
  begin
    if FiAttribs[i] = attrib then
    begin
      FiAttribs[i + 1] := newValue;
      Exit;
    end;
    Inc(i, 2);
  end;
  AddIAttrib(attrib, newValue);
end;

procedure TgxWinContext.DropIAttrib(attrib: Integer);
var
  i: Integer;
begin
  i := 0;
  while i < Length(FiAttribs) do
  begin
    if FiAttribs[i] = attrib then
    begin
      Inc(i, 2);
      while i < Length(FiAttribs) do
      begin
        FiAttribs[i - 2] := FiAttribs[i];
        Inc(i);
      end;
      SetLength(FiAttribs, Length(FiAttribs) - 2);
      Exit;
    end;
    Inc(i, 2);
  end;
end;

procedure TgxWinContext.ClearFAttribs;
begin
  SetLength(FfAttribs, 1);
  FfAttribs[0] := 0;
end;

procedure TgxWinContext.AddFAttrib(attrib, value: Single);
var
  n: Integer;
begin
  n := Length(FfAttribs);
  SetLength(FfAttribs, n + 2);
  FfAttribs[n - 1] := attrib;
  FfAttribs[n] := value;
  FfAttribs[n + 1] := 0;
end;

procedure TgxWinContext.DestructionEarlyWarning(sender: TObject);
begin
  if IsValid then
    DestroyContext;
end;

procedure TgxWinContext.ChooseWGLFormat(DC: HDC; nMaxFormats: Cardinal; piFormats: PInteger; var nNumFormats: Integer;
  BufferCount: Integer);
const
  cAAToSamples: array [aaNone .. csa16xHQ] of Integer = (1, 2, 2, 4, 4, 6, 8, 16, 8, 8, 16, 16);
  cCSAAToSamples: array [csa8x .. csa16xHQ] of Integer = (4, 8, 4, 8);

  procedure ChoosePixelFormat;
  begin
    if not wglChoosePixelFormatARB(DC, @FiAttribs[0], @FfAttribs[0], 32, PGLint(piFormats), @nNumFormats) then
      nNumFormats := 0;
  end;

var
  float: Boolean;
  aa: TgxAntiAliasing;
begin
  // request hardware acceleration
  case FAcceleration of
    chaUnknown:
      AddIAttrib(WGL_ACCELERATION_ARB, WGL_GENERIC_ACCELERATION_ARB);
    chaHardware:
      AddIAttrib(WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB);
    chaSoftware:
      AddIAttrib(WGL_ACCELERATION_ARB, WGL_NO_ACCELERATION_ARB);
  end;

  float := (ColorBits = 64) or (ColorBits = 128); // float_type

  if float then
  begin // float_type
    if WGL_ATI_pixel_format_float then
    begin // NV40 uses ATI_float, with linear filtering
      AddIAttrib(WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_FLOAT_ATI);
    end
    else
    begin
      AddIAttrib(WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB);
      AddIAttrib(WGL_FLOAT_COMPONENTS_NV, GL_TRUE);
    end;
  end;

  if BufferCount > 1 then
    // 1 front buffer + (BufferCount-1) aux buffers
    AddIAttrib(WGL_AUX_BUFFERS_ARB, BufferCount - 1);

  AddIAttrib(WGL_COLOR_BITS_ARB, ColorBits);
  if AlphaBits > 0 then
    AddIAttrib(WGL_ALPHA_BITS_ARB, AlphaBits);
  AddIAttrib(WGL_DEPTH_BITS_ARB, DepthBits);
  if StencilBits > 0 then
    AddIAttrib(WGL_STENCIL_BITS_ARB, StencilBits);
  if AccumBits > 0 then
    AddIAttrib(WGL_ACCUM_BITS_ARB, AccumBits);
  if AuxBuffers > 0 then
    AddIAttrib(WGL_AUX_BUFFERS_ARB, AuxBuffers);
  if (AntiAliasing <> aaDefault) and WGL_ARB_multisample then
  begin
    if AntiAliasing = aaNone then
      AddIAttrib(WGL_SAMPLE_BUFFERS_ARB, GL_FALSE)
    else
    begin
      AddIAttrib(WGL_SAMPLE_BUFFERS_ARB, GL_TRUE);
      AddIAttrib(WGL_SAMPLES_ARB, cAAToSamples[AntiAliasing]);
      if (AntiAliasing >= csa8x) and (AntiAliasing <= csa16xHQ) then
        AddIAttrib(WGL_COLOR_SAMPLES_NV, cCSAAToSamples[AntiAliasing]);
    end;

  end;

  ClearFAttribs;
  ChoosePixelFormat;
  if (nNumFormats = 0) and (DepthBits >= 32) then
  begin
    // couldn't find 32+ bits depth buffer, 24 bits one available?
    ChangeIAttrib(WGL_DEPTH_BITS_ARB, 24);
    ChoosePixelFormat;
  end;
  if (nNumFormats = 0) and (DepthBits >= 24) then
  begin
    // couldn't find 24+ bits depth buffer, 16 bits one available?
    ChangeIAttrib(WGL_DEPTH_BITS_ARB, 16);
    ChoosePixelFormat;
  end;
  if (nNumFormats = 0) and (ColorBits >= 24) then
  begin
    // couldn't find 24+ bits color buffer, 16 bits one available?
    ChangeIAttrib(WGL_COLOR_BITS_ARB, 16);
    ChoosePixelFormat;
  end;
  if (nNumFormats = 0) and (AntiAliasing <> aaDefault) then
  begin
    // Restore DepthBits
    ChangeIAttrib(WGL_DEPTH_BITS_ARB, DepthBits);
    if (AntiAliasing >= csa8x) and (AntiAliasing <= csa16xHQ) then
    begin
      DropIAttrib(WGL_COLOR_SAMPLES_NV);
      case AntiAliasing of
        csa8x, csa8xHQ:
          AntiAliasing := aa8x;
        csa16x, csa16xHQ:
          AntiAliasing := aa16x;
      end;
      ChangeIAttrib(WGL_SAMPLES_ARB, cAAToSamples[AntiAliasing]);
    end;
    ChoosePixelFormat;

    if nNumFormats = 0 then
    begin
      aa := AntiAliasing;
      repeat
        Dec(aa);
        if aa = aaNone then
        begin
          // couldn't find AA buffer, try without
          DropIAttrib(WGL_SAMPLE_BUFFERS_ARB);
          DropIAttrib(WGL_SAMPLES_ARB);
          ChoosePixelFormat;
          break;
        end;
        ChangeIAttrib(WGL_SAMPLES_ARB, cAAToSamples[aa]);
        ChoosePixelFormat;
      until nNumFormats <> 0;
      AntiAliasing := aa;
    end;
  end;
  // Check DepthBits again
  if (nNumFormats = 0) and (DepthBits >= 32) then
  begin
    // couldn't find 32+ bits depth buffer, 24 bits one available?
    ChangeIAttrib(WGL_DEPTH_BITS_ARB, 24);
    ChoosePixelFormat;
  end;
  if (nNumFormats = 0) and (DepthBits >= 24) then
  begin
    // couldn't find 24+ bits depth buffer, 16 bits one available?
    ChangeIAttrib(WGL_DEPTH_BITS_ARB, 16);
    ChoosePixelFormat;
  end;
  if (nNumFormats = 0) and (ColorBits >= 24) then
  begin
    // couldn't find 24+ bits color buffer, 16 bits one available?
    ChangeIAttrib(WGL_COLOR_BITS_ARB, 16);
    ChoosePixelFormat;
  end;
  if nNumFormats = 0 then
  begin
    // ok, last attempt: no AA, restored depth and color,
    // relaxed hardware-acceleration request
    ChangeIAttrib(WGL_COLOR_BITS_ARB, ColorBits);
    ChangeIAttrib(WGL_DEPTH_BITS_ARB, DepthBits);
    DropIAttrib(WGL_ACCELERATION_ARB);
    ChoosePixelFormat;
  end;
end;

procedure TgxWinContext.CreateOldContext(aDC: HDC);
begin
  if not FLegacyContextsOnly then
  begin
    case Layer of
      clUnderlay2:  FRC := wglCreateLayerContext(aDC, -2);
      clUnderlay1:  FRC := wglCreateLayerContext(aDC, -1);
      clMainPlane:  FRC := wglCreateContext(aDC);
      clOverlay1:   FRC := wglCreateLayerContext(aDC, 1);
      clOverlay2:   FRC := wglCreateLayerContext(aDC, 2);
    end;
  end
  else
    FRC := wglCreateContext(aDC);

  if FRC = 0 then
    RaiseLastOSError;
  FDC := aDC;

  if not wglMakeCurrent(FDC, FRC) then
    raise EVXContext.Create(Format(strContextActivationFailed, [GetLastError, SysErrorMessage(GetLastError)]));

  if not FLegacyContextsOnly then
  begin
    if Assigned(FShareContext) and (FShareContext.RC <> 0) then
    begin
      if not wglShareLists(FShareContext.RC, FRC) then
{$IFDEF USE_LOGGING}
        GLSLogger.LogWarning(strFailedToShare)
{$ENDIF}
      else
      begin
        FSharedContexts.Add(FShareContext);
        PropagateSharedContext;
      end;
    end;
    //DebugMode := False;
    ReadExtensions(); //FGL.Initialize;
    MakeGLCurrent;
    // If we are using AntiAliasing, adjust filtering hints
    if AntiAliasing in [aa2xHQ, aa4xHQ, csa8xHQ, csa16xHQ] then
      // Hint for nVidia HQ modes (Quincunx etc.)
      gxStates.MultisampleFilterHint := hintNicest
    else
      gxStates.MultisampleFilterHint := hintDontCare;

    if rcoDebug in Options then
      ShowMessage(strDriverNotSupportDebugRC);
    if rcoOGL_ES in Options then
      ShowMessage(strDriverNotSupportOESRC);
    if gxStates.ForwardContext then
      ShowMessage(strDriverNotSupportFRC);
    gxStates.ForwardContext := False;
  end
  else
    ShowMessage(strTmpRC_Created);
end;

procedure TgxWinContext.CreateNewContext(aDC: HDC);
var
  bSuccess, bOES: Boolean;
begin
  bSuccess := False;
  bOES := False;

  try
    ClearIAttribs;
    // Initialize forward context
    if False { gxStates.ForwardContext } then
    begin
      if GL_VERSION_4_2 then
      begin
        AddIAttrib(WGL_CONTEXT_MAJOR_VERSION_ARB, 4);
        AddIAttrib(WGL_CONTEXT_MINOR_VERSION_ARB, 2);
      end
      else if GL_VERSION_4_1 then
      begin
        AddIAttrib(WGL_CONTEXT_MAJOR_VERSION_ARB, 4);
        AddIAttrib(WGL_CONTEXT_MINOR_VERSION_ARB, 1);
      end
      else if GL_VERSION_4_0 then
      begin
        AddIAttrib(WGL_CONTEXT_MAJOR_VERSION_ARB, 4);
        AddIAttrib(WGL_CONTEXT_MINOR_VERSION_ARB, 0);
      end
      else
        Abort;
      AddIAttrib(WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB);
      if rcoOGL_ES in Options then
        ShowMessage(strOESvsForwardRC);
    end
    else if rcoOGL_ES in Options then
    begin
      if WGL_EXT_create_context_es2_profile then
      begin
        AddIAttrib(WGL_CONTEXT_MAJOR_VERSION_ARB, 2);
        AddIAttrib(WGL_CONTEXT_MINOR_VERSION_ARB, 0);
        AddIAttrib(WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_ES2_PROFILE_BIT_EXT);
        bOES := True;
      end
      else
        ShowMessage(strDriverNotSupportOESRC);
    end;

    if rcoDebug in Options then
    begin
      AddIAttrib(WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB);
      ///DebugMode := True;
    end;

    case Layer of
      clUnderlay2: AddIAttrib(WGL_CONTEXT_LAYER_PLANE_ARB, -2);
      clUnderlay1: AddIAttrib(WGL_CONTEXT_LAYER_PLANE_ARB, -1);
      clOverlay1: AddIAttrib(WGL_CONTEXT_LAYER_PLANE_ARB, 1);
      clOverlay2: AddIAttrib(WGL_CONTEXT_LAYER_PLANE_ARB, 2);
    end;

    FRC := 0;
    if Assigned(FShareContext) then
    begin
      FRC := wglCreateContextAttribsARB(aDC, FShareContext.RC, @FiAttribs[0]);
      if FRC <> 0 then
      begin
        FSharedContexts.Add(FShareContext);
        PropagateSharedContext;
      end
      else
        ShowMessage(strFailedToShare)
    end;

    if FRC = 0 then
    begin
      FRC := wglCreateContextAttribsARB(aDC, 0, @FiAttribs[0]);
      if FRC = 0 then
      begin
        if gxStates.ForwardContext then
          ShowMessage(Format(strForwardContextFailed,
            [GetLastError, SysErrorMessage(GetLastError)]))
        else
          ShowMessage(Format(strBackwardContextFailed,
            [GetLastError, SysErrorMessage(GetLastError)]));
        Abort;
      end;
    end;

    FDC := aDC;

    if not wglMakeCurrent(FDC, FRC) then
    begin
      ShowMessage(Format(strContextActivationFailed, [GetLastError, SysErrorMessage(GetLastError)]));
      Abort;
    end;

    InitOpenGL; ///FGL.Initialize;
    MakeGLCurrent;
    // If we are using AntiAliasing, adjust filtering hints
    if AntiAliasing in [aa2xHQ, aa4xHQ, csa8xHQ, csa16xHQ] then
      // Hint for nVidia HQ modes (Quincunx etc.)
      gxStates.MultisampleFilterHint := hintNicest
    else
      gxStates.MultisampleFilterHint := hintDontCare;

    if gxStates.ForwardContext then
      ShowMessage(strFRC_created);
    if bOES then
      ShowMessage(strOESRC_created);
    bSuccess := True;
  finally
    gxStates.ForwardContext := gxStates.ForwardContext and bSuccess;
    PipelineTransformation.LoadMatricesEnabled := not gxStates.ForwardContext;
  end;
end;

procedure TgxWinContext.DoCreateContext(ADeviceHandle: THandle);
const
  cMemoryDCs = [OBJ_MEMDC, OBJ_METADC, OBJ_ENHMETADC];
  cBoolToInt: array [False .. True] of Integer = (GL_FALSE, GL_TRUE);
  cLayerToSet: array [TgxContextLayer] of Byte = (32, 16, 0, 1, 2);
var
  pfDescriptor: TPixelFormatDescriptor;
  pixelFormat, nbFormats, softwarePixelFormat: Integer;
  aType: DWORD;
  iFormats: array [0 .. 31] of Integer;
  tempWnd: HWND;
  tempDC: HDC;
  localDC: HDC;
  localRC: HGLRC;
  sharedRC: TgxWinContext;

  function CurrentPixelFormatIsHardwareAccelerated: Boolean;
  var
    localPFD: TPixelFormatDescriptor;
  begin
    Result := False;
    if pixelFormat = 0 then
      Exit;
    with localPFD do
    begin
      nSize := SizeOf(localPFD);
      nVersion := 1;
    end;
    DescribePixelFormat(ADeviceHandle, pixelFormat, SizeOf(localPFD), localPFD);
    Result := ((localPFD.dwFlags and PFD_GENERIC_FORMAT) = 0);
  end;

var
  i, iAttrib, iValue: Integer;
begin
  if vUseWindowTrackingHook and not FLegacyContextsOnly then
    TrackWindow(WindowFromDC(ADeviceHandle), DestructionEarlyWarning);

  // Just in case it didn't happen already.
  if not InitOpenGL then
    RaiseLastOSError;

  // Prepare PFD
  FillChar(pfDescriptor, SizeOf(pfDescriptor), 0);
  with pfDescriptor do
  begin
    nSize := SizeOf(pfDescriptor);
    nVersion := 1;
    dwFlags := PFD_SUPPORT_OPENGL;
    aType := GetObjectType(ADeviceHandle);
    if aType = 0 then
      RaiseLastOSError;
    if aType in cMemoryDCs then
      dwFlags := dwFlags or PFD_DRAW_TO_BITMAP
    else
      dwFlags := dwFlags or PFD_DRAW_TO_WINDOW;
    if rcoDoubleBuffered in Options then
      dwFlags := dwFlags or PFD_DOUBLEBUFFER;
    if rcoStereo in Options then
      dwFlags := dwFlags or PFD_STEREO;
    iPixelType := PFD_TYPE_RGBA;
    cColorBits := ColorBits;
    cDepthBits := DepthBits;
    cStencilBits := StencilBits;
    cAccumBits := AccumBits;
    cAlphaBits := AlphaBits;
    cAuxBuffers := AuxBuffers;
    case Layer of
      clUnderlay2, clUnderlay1:
        iLayerType := Byte(PFD_UNDERLAY_PLANE);
      clMainPlane:
        iLayerType := PFD_MAIN_PLANE;
      clOverlay1, clOverlay2:
        iLayerType := PFD_OVERLAY_PLANE;
    end;
    bReserved := cLayerToSet[Layer];
    if Layer <> clMainPlane then
      dwFlags := dwFlags or PFD_SWAP_LAYER_BUFFERS;

  end;
  pixelFormat := 0;

  // WGL_ARB_pixel_format is used if available
  //
  if not(IsMesaGL or FLegacyContextsOnly or (aType in cMemoryDCs)) then
  begin
    // the WGL mechanism is a little awkward: we first create a dummy context
    // on the TOP-level DC (ie. screen), to retrieve our pixelformat, create
    // our stuff, etc.
    tempWnd := CreateTempWnd;
    tempDC := GetDC(tempWnd);
    localDC := 0;
    localRC := 0;
    try
      SpawnLegacyContext(tempDC);
      try
        DoActivate;
        try
          ClearGLError;
          if WGL_ARB_pixel_format then
          begin
            // New pixel format selection via wglChoosePixelFormatARB
            ClearIAttribs;
            AddIAttrib(WGL_DRAW_TO_WINDOW_ARB, GL_TRUE);
            AddIAttrib(WGL_STEREO_ARB, cBoolToInt[rcoStereo in Options]);
            AddIAttrib(WGL_DOUBLE_BUFFER_ARB, cBoolToInt[rcoDoubleBuffered in Options]);

            ChooseWGLFormat(ADeviceHandle, 32, @iFormats, nbFormats);
            if nbFormats > 0 then
            begin
              if WGL_ARB_multisample and (AntiAliasing in [aaNone, aaDefault])
              then
              begin
                // Pick first non AntiAliased for aaDefault and aaNone modes
                iAttrib := WGL_SAMPLE_BUFFERS_ARB;
                for i := 0 to nbFormats - 1 do
                begin
                  pixelFormat := iFormats[i];
                  iValue := GL_FALSE;
                  wglGetPixelFormatAttribivARB(ADeviceHandle, pixelFormat, 0,  1, @iAttrib, @iValue);
                  if iValue = GL_FALSE then
                    break;
                end;
              end
              else
                pixelFormat := iFormats[0];
              if GetPixelFormat(ADeviceHandle) <> pixelFormat then
              begin
                if not SetPixelFormat(ADeviceHandle, pixelFormat, @pfDescriptor)
                then
                  RaiseLastOSError;
              end;
            end;
          end;
        finally
          DoDeactivate;
        end;
      finally
        sharedRC := FShareContext;
        DoDestroyContext;
        FShareContext := sharedRC;
        ShowMessage('Temporary rendering context destroyed');
      end;
    finally
      ReleaseDC(0, tempDC);
      DestroyWindow(tempWnd);
      FDC := localDC;
      FRC := localRC;
    end;
  end;

  if pixelFormat = 0 then
  begin
    // Legacy pixel format selection
    pixelFormat := ChoosePixelFormat(ADeviceHandle, @pfDescriptor);
    if (not(aType in cMemoryDCs)) and (not CurrentPixelFormatIsHardwareAccelerated) then
    begin
      softwarePixelFormat := pixelFormat;
      pixelFormat := 0;
    end
    else
      softwarePixelFormat := 0;
    if pixelFormat = 0 then
    begin
      // Failed on default params, try with 16 bits depth buffer
      pfDescriptor.cDepthBits := 16;
      pixelFormat := ChoosePixelFormat(ADeviceHandle, @pfDescriptor);
      if not CurrentPixelFormatIsHardwareAccelerated then
        pixelFormat := 0;
      if pixelFormat = 0 then
      begin
        // Failed, try with 16 bits color buffer
        pfDescriptor.cColorBits := 16;
        pixelFormat := ChoosePixelFormat(ADeviceHandle, @pfDescriptor);
      end;
      if not CurrentPixelFormatIsHardwareAccelerated then
      begin
        // Fallback to original, should be supported by software
        pixelFormat := softwarePixelFormat;
      end;
      if pixelFormat = 0 then
        RaiseLastOSError;
    end;
  end;

  if GetPixelFormat(ADeviceHandle) <> pixelFormat then
  begin
    if not SetPixelFormat(ADeviceHandle, pixelFormat, @pfDescriptor) then
      RaiseLastOSError;
  end;

  // Check the properties we just set.
  DescribePixelFormat(ADeviceHandle, pixelFormat, SizeOf(pfDescriptor), pfDescriptor);
  with pfDescriptor do
  begin
    if (dwFlags and PFD_NEED_PALETTE) <> 0 then
      SetupPalette(ADeviceHandle, pfDescriptor);
    FSwapBufferSupported := (dwFlags and PFD_SWAP_LAYER_BUFFERS) <> 0;
    if bReserved = 0 then
      FLayer := clMainPlane;
  end;

  if not FLegacyContextsOnly then
  begin
    if ((pfDescriptor.dwFlags and PFD_GENERIC_FORMAT) > 0) and (FAcceleration = chaHardware) then
    begin
      FAcceleration := chaSoftware;
      ShowMessage(strFailHWRC);
    end;
  end;

  if not FLegacyContextsOnly and WGL_ARB_create_context and (FAcceleration = chaHardware) then
    CreateNewContext(ADeviceHandle)
  else
    CreateOldContext(ADeviceHandle);

  if not FLegacyContextsOnly then
  begin
    // Share identifiers with other context if it deffined
    if (ServiceContext <> nil) and (Self <> ServiceContext) then
    begin
      if wglShareLists(TgxWinContext(ServiceContext).FRC, FRC) then
      begin
        FSharedContexts.Add(ServiceContext);
        PropagateSharedContext;
      end
      else
        ShowMessage('DoCreateContext - Failed to share contexts with resource context');
    end;
  end;
end;

procedure TgxWinContext.SpawnLegacyContext(aDC: HDC);
begin
  try
    FLegacyContextsOnly := True;
    try
      DoCreateContext(aDC);
    finally
      FLegacyContextsOnly := False;
    end;
  except
    on E: Exception do
    begin
      raise Exception.Create(strUnableToCreateLegacyContext + #13#10 + E.ClassName + ': ' + E.message);
    end;
  end;
end;

procedure TgxWinContext.DoCreateMemoryContext(OutputDevice: THandle; Width, Height: Integer; BufferCount: Integer);
var
  nbFormats: Integer;
  iFormats: array [0 .. 31] of Integer;
  iPBufferAttribs: array [0 .. 0] of Integer;
  localHPBuffer: Integer;
  localRC: HGLRC;
  localDC, tempDC: HDC;
  tempWnd: HWND;
  shareRC: TgxWinContext;
  pfDescriptor: TPixelFormatDescriptor;
  bOES: Boolean;
begin
  localHPBuffer := 0;
  localDC := 0;
  localRC := 0;
  bOES := False;
  // the WGL mechanism is a little awkward: we first create a dummy context
  // on the TOP-level DC (ie. screen), to retrieve our pixelformat, create
  // our stuff, etc.
  tempWnd := CreateTempWnd;
  tempDC := GetDC(tempWnd);
  try
    SpawnLegacyContext(tempDC);
    try
      DoActivate;
      try
        ClearGLError;
        if WGL_ARB_pixel_format and WGL_ARB_pbuffer then
        begin
          ClearIAttribs;
          AddIAttrib(WGL_DRAW_TO_PBUFFER_ARB, 1);
          ChooseWGLFormat(tempDC, 32, @iFormats, nbFormats, BufferCount);
          if nbFormats = 0 then
            raise EPBuffer.Create
              ('Format not supported for pbuffer operation.');
          iPBufferAttribs[0] := 0;

          localHPBuffer := wglCreatePbufferARB(tempDC, iFormats[0], Width,
            Height, @iPBufferAttribs[0]);
          if localHPBuffer = 0 then
            raise EPBuffer.Create('Unabled to create pbuffer.');
          try
            localDC := wglGetPbufferDCARB(localHPBuffer);
            if localDC = 0 then
              raise EPBuffer.Create('Unabled to create pbuffer''s DC.');
            try
              if WGL_ARB_create_context then
              begin
                // Modern creation style
                ClearIAttribs;
                // Initialize forward context
                if gxStates.ForwardContext then
                begin
                  if GL_VERSION_4_2 then
                  begin
                    AddIAttrib(WGL_CONTEXT_MAJOR_VERSION_ARB, 4);
                    AddIAttrib(WGL_CONTEXT_MINOR_VERSION_ARB, 2);
                  end
                  else if GL_VERSION_4_1 then
                  begin
                    AddIAttrib(WGL_CONTEXT_MAJOR_VERSION_ARB, 4);
                    AddIAttrib(WGL_CONTEXT_MINOR_VERSION_ARB, 1);
                  end
                  else if GL_VERSION_4_0 then
                  begin
                    AddIAttrib(WGL_CONTEXT_MAJOR_VERSION_ARB, 4);
                    AddIAttrib(WGL_CONTEXT_MINOR_VERSION_ARB, 0);
                  end
                  else
                    Abort;
                  AddIAttrib(WGL_CONTEXT_FLAGS_ARB,
                    WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB);
                  if rcoOGL_ES in Options then
                    ShowMessage(strOESvsForwardRC);
                end
                else if rcoOGL_ES in Options then
                begin
                  if WGL_EXT_create_context_es2_profile then
                  begin
                    AddIAttrib(WGL_CONTEXT_MAJOR_VERSION_ARB, 2);
                    AddIAttrib(WGL_CONTEXT_MINOR_VERSION_ARB, 0);
                    AddIAttrib(WGL_CONTEXT_FLAGS_ARB,
                      WGL_CONTEXT_ES2_PROFILE_BIT_EXT);
                  end
                  else
                    ShowMessage(strDriverNotSupportOESRC);
                end;

                if rcoDebug in Options then
                begin
                  AddIAttrib(WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB);
                  ///DebugMode := True;
                end;

                case Layer of
                  clUnderlay2:
                    AddIAttrib(WGL_CONTEXT_LAYER_PLANE_ARB, -2);
                  clUnderlay1:
                    AddIAttrib(WGL_CONTEXT_LAYER_PLANE_ARB, -1);
                  clOverlay1:
                    AddIAttrib(WGL_CONTEXT_LAYER_PLANE_ARB, 1);
                  clOverlay2:
                    AddIAttrib(WGL_CONTEXT_LAYER_PLANE_ARB, 2);
                end;

                localRC := wglCreateContextAttribsARB(localDC, 0,
                  @FiAttribs[0]);
                if localRC = 0 then
{$IFDEF USE_LOGGING}
                begin
                  if gxStates.ForwardContext then
                    GLSLogger.LogErrorFmt(cForwardContextFailed,
                      [GetLastError, SysErrorMessage(GetLastError)])
                  else
                    GLSLogger.LogErrorFmt(cBackwardContextFailed,
                      [GetLastError, SysErrorMessage(GetLastError)]);
                  Abort;
                end;
{$ELSE}
                raise Exception.Create('Unabled to create pbuffer''s RC.');
{$ENDIF}
              end
              else
              begin
                // Old creation style
                localRC := wglCreateContext(localDC);
                if localRC = 0 then
                begin
                  ShowMessage(Format(strBackwardContextFailed,
                    [GetLastError, SysErrorMessage(GetLastError)]));
                  Abort;
                end;
              end;

            except
              wglReleasePBufferDCARB(localHPBuffer, localDC);
              raise;
            end;
          except
            wglDestroyPBufferARB(localHPBuffer);
            raise;
          end;
        end
        else
          raise EPBuffer.Create('WGL_ARB_pbuffer support required.');
        CheckOpenGLError;
      finally
        DoDeactivate;
      end;
    finally
      shareRC := FShareContext;
      DoDestroyContext;
      FShareContext := shareRC;
    end;
  finally
    ReleaseDC(0, tempDC);
    DestroyWindow(tempWnd);
    FHPBUFFER := localHPBuffer;
    FDC := localDC;
    FRC := localRC;
  end;

  DescribePixelFormat(FDC, GetPixelFormat(FDC), SizeOf(pfDescriptor),
    pfDescriptor);
  if ((pfDescriptor.dwFlags and PFD_GENERIC_FORMAT) > 0) and
    (FAcceleration = chaHardware) then
  begin
    FAcceleration := chaSoftware;
    ShowMessage(strFailHWRC);
  end;

  Activate;
  InitOpenGL; ///FGL.Initialize;
  // If we are using AntiAliasing, adjust filtering hints
  if AntiAliasing in [aa2xHQ, aa4xHQ, csa8xHQ, csa16xHQ] then
    gxStates.MultisampleFilterHint := hintNicest
  else if AntiAliasing in [aa2x, aa4x, csa8x, csa16x] then
    gxStates.MultisampleFilterHint := hintFastest
  else
    gxStates.MultisampleFilterHint := hintDontCare;

  // Specific which color buffers are to be drawn into
  if BufferCount > 1 then
    glDrawBuffers(BufferCount, @MRT_BUFFERS);

  if (ServiceContext <> nil) and (Self <> ServiceContext) then
  begin
    if wglShareLists(TgxWinContext(ServiceContext).FRC, FRC) then
    begin
      FSharedContexts.Add(ServiceContext);
      PropagateSharedContext;
    end
    else
      ShowMessage('DoCreateContext - Failed to share contexts with resource context');
  end;

  if Assigned(FShareContext) and (FShareContext.RC <> 0) then
  begin
    if not wglShareLists(FShareContext.RC, FRC) then
      ShowMessage(strFailedToShare)
    else
    begin
      FSharedContexts.Add(FShareContext);
      PropagateSharedContext;
    end;
  end;
  Deactivate;
  if gxStates.ForwardContext then
    ShowMessage('PBuffer ' + strFRC_created);
  if bOES then
    ShowMessage('PBuffer ' + strOESRC_created);
  if not(gxStates.ForwardContext or bOES) then
    ShowMessage(strPBufferRC_created);
end;

function TgxWinContext.DoShareLists(aContext: TgxContext): Boolean;
begin
  if aContext is TgxWinContext then
  begin
    FShareContext := TgxWinContext(aContext);
    if FShareContext.RC <> 0 then
      Result := wglShareLists(FShareContext.RC, RC)
    else
      Result := False;
  end
  else
    raise Exception.Create(strIncompatibleContexts);
end;

procedure TgxWinContext.DoDestroyContext;
begin
  if vUseWindowTrackingHook then
    UnTrackWindow(WindowFromDC(FDC));

  if FHPBUFFER <> 0 then
  begin
    wglReleasePBufferDCARB(FHPBUFFER, FDC);
    wglDestroyPBufferARB(FHPBUFFER);
    FHPBUFFER := 0;
  end;

  if FRC <> 0 then
    if not wglDeleteContext(FRC) then
      ShowMessage(Format(strDeleteContextFailed,
        [GetLastError, SysErrorMessage(GetLastError)]));

  FRC := 0;
  FDC := 0;
  FShareContext := nil;
end;

procedure TgxWinContext.DoActivate;
begin
  if not wglMakeCurrent(FDC, FRC) then
  begin
    ShowMessage(Format(strContextActivationFailed,
      [GetLastError, SysErrorMessage(GetLastError)]));
    Abort;
  end;

  if not LoadOpenGL then
    InitOpenGL; ///FGL.Initialize(CurrentVXContext = nil);
end;

procedure TgxWinContext.DoDeactivate;
begin
  if not wglMakeCurrent(0, 0) then
  begin
    ShowMessage(Format(strContextDeactivationFailed,
      [GetLastError, SysErrorMessage(GetLastError)]));
    Abort;
  end;
end;

function TgxWinContext.IsValid: Boolean;
begin
  Result := (FRC <> 0);
end;

procedure TgxWinContext.SwapBuffers;
begin
  if (FDC <> 0) and (rcoDoubleBuffered in Options) then
    if FSwapBufferSupported then
    begin
      case Layer of
        clUnderlay2:
          wglSwapLayerBuffers(FDC, WGL_SWAP_UNDERLAY2);
        clUnderlay1:
          wglSwapLayerBuffers(FDC, WGL_SWAP_UNDERLAY1);
        clMainPlane: SwapBuffers(); /// Vcl - SwapBuffers(FDC)
        clOverlay1:
          wglSwapLayerBuffers(FDC, WGL_SWAP_OVERLAY1);
        clOverlay2:
          wglSwapLayerBuffers(FDC, WGL_SWAP_OVERLAY2);
      end;
    end
    else
    SwapBuffers(); /// Vcl - SwapBuffers(FDC);
end;

function TgxWinContext.RenderOutputDevice: Pointer;
begin
  Result := Pointer(FDC);
end;

initialization // ------------------------------------------------------------

RegisterContextClass(TgxWinContext);

end.

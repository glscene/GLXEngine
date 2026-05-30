unit fdEarth;

interface

uses
  Winapi.OpenGL,
  Winapi.OpenGLext,
  System.SysUtils,
  System.Classes,
  System.Types,
  System.Math,
  System.ImageList,

  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.ExtCtrls,
  Vcl.Imaging.Jpeg,
  Vcl.Imaging.pngimage,
  Vcl.Menus,
  Vcl.ComCtrls,
  Vcl.BaseImageCollection,
  Vcl.ImageCollection,
  Vcl.ImgList,
  Vcl.VirtualImageList,

  Stage.VectorTypes,
  Stage.VectorGeometry,
  GLS.Material,
  GLS.Cadencer,
  GLS.LensFlare,
  GLS.Scene,
  GLS.Objects,
  GLS.Coordinates,
  GLS.SkyDome,
  GLS.SceneViewer,
  GLS.Texture,
  GLS.RenderContextInfo,
  GLS.Color,
  GLS.State,
  Stage.Utils,
  GLS.Context,
  Stage.TextureFormat,
  GLSL.TextureShaders,
  GLS.BaseClasses,
  GLS.PersistentClasses,

  GLS.GeomObjects;

type
  TFormEarth = class(TForm)
    GLScene: TGLScene;
    GLSceneViewer: TGLSceneViewer;
    Camera: TGLCamera;
    sfEarth: TGLSphere;
    LightSourceSun: TGLLightSource;
    DirectOpenGL: TGLDirectOpenGL;
    GLCadencer: TGLCadencer;
    Timer: TTimer;
    sfLuna: TGLSphere;
    dcEarth: TGLDummyCube;
    dcLuna: TGLDummyCube;
    LensFlareSun: TGLLensFlare;
    GLPlanetMaps: TGLMaterialLibrary;
    GLEarthCombiner: TGLTexCombineShader;
    Cameracontroller: TGLCamera;
    SkyDome: TGLSkyDome;
    ConstellationLines: TGLLines;
    MainMenu: TMainMenu;
    File1: TMenuItem;
    Open1: TMenuItem;
    Save1: TMenuItem;
    SaveAs1: TMenuItem;
    Exit1: TMenuItem;
    N1: TMenuItem;
    miView: TMenuItem;
    Hide1: TMenuItem;
    Show1: TMenuItem;
    N3: TMenuItem;
    Help1: TMenuItem;
    About1: TMenuItem;
    PanelLeft: TPanel;
    tvPlanets: TTreeView;
    miConstLines: TMenuItem;
    VirtPlanetSymbols: TVirtualImageList;
    PlanetSymbols: TImageCollection;
    dcSolarSystem: TGLDummyCube;
    diskSaturnUp: TGLDisk;
    diskSaturnDn: TGLDisk;
    sfGlobe: TGLSphere;
    procedure FormCreate(Sender: TObject);
    procedure DirectOpenGLRender(Sender: TObject; var rci: TGLRenderContextInfo);
    procedure TimerTimer(Sender: TObject);
    procedure GLCadencerProgress(Sender: TObject; const deltaTime, newTime: Double);
    procedure GLSceneViewerMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState;
      X, Y: Integer);
    procedure GLSceneViewerMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure FormMouseWheel(Sender: TObject; Shift: TShiftState; WheelDelta: Integer;
      MousePos: TPoint; var Handled: Boolean);
    procedure GLSceneViewerDblClick(Sender: TObject);
    procedure FormKeyPress(Sender: TObject; var Key: Char);
    procedure GLSceneViewerBeforeRender(Sender: TObject);
    procedure Exit1Click(Sender: TObject);
    procedure tvPlanetsClick(Sender: TObject);
    procedure miConstLinesClick(Sender: TObject);
    procedure miConstBoundariesClick(Sender: TObject);
    procedure Hide1Click(Sender: TObject);
    procedure Show1Click(Sender: TObject);
    procedure FormShow(Sender: TObject);
  public
    ConstellationsAlpha: Single;
    TimeMultiplier: Single;
    mx, my, dmx, dmy: Integer;
    HighResResourcesLoaded: Boolean;
    CameraTimeSteps: Single;
    radius, invAtmosphereHeight: Single;
    sunPos, eyePos, lightingVector: TGLVector;
    diskNormal, diskRight, diskUp: TGLVector;
    procedure LoadHighResTexture(LibMat: TGLLibMaterial; const FileName: string);
  private
    FileName, Path: TFileName;
    procedure LoadConstellationLines;
    function AtmosphereColor(const rayStart, rayEnd: TGLVector): TGLColorVector;
    function ComputeColor(var rayDest: TGLVector; mayHitGround: Boolean): TGLColorVector;
  end;

var
  FormEarth: TFormEarth;

const
  cOpacity: Single = 5;
  // unrealisticly thick atmospheres look better :)
  cAtmosphereRadius: Single = 0.55;
  // use value slightly lower than actual radius, for antialiasing effect
  cEarthRadius: Single = 0.495;
  cLowAtmColor: TGLColorVector = (X: 1; Y: 1; Z: 1; W: 1);
  cHighAtmColor: TGLColorVector = (X: 0; Y: 0; Z: 1; W: 1);
  cIntDivTable: array [2 .. 20] of Single = (1 / 2, 1 / 3, 1 / 4, 1 / 5, 1 / 6, 1 / 7, 1 / 8, 1 / 9,
    1 / 10, 1 / 11, 1 / 12, 1 / 13, 1 / 14, 1 / 15, 1 / 16, 1 / 17, 1 / 18, 1 / 19, 1 / 20);

implementation //==============================================================

{$R *.dfm}

//-----------------------------------------------------------------------------
procedure TFormEarth.FormCreate(Sender: TObject);
begin
  Path := GetCurrentAssetPath();

  // dir for star catalog
  SetCurrentDir(Path + '\data');
  FileName := 'Yale_BSC.stars';
  SkyDome.Bands.Clear;
  if FileExists(FileName) then
    SkyDome.Stars.LoadStarsFile(FileName);
  LoadConstellationLines;
  TimeMultiplier := 1;

  tvPlanets.Select(tvPlanets.Items[3]);
  tvPlanets.FullExpand;
  // dir for maps of planets
  SetCurrentDir(Path + '\map');
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.FormShow(Sender: TObject);
begin
   miConstLinesClick(Sender);
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.GLSceneViewerBeforeRender(Sender: TObject);
begin
  LensFlareSun.PreRender(Sender as TGLSceneBuffer);
  // if no multitexturing or no combiner support, turn off city lights
  GLPlanetMaps.Materials[0].Shader := GLEarthCombiner;
  GLPlanetMaps.Materials[0].Texture2Name := 'earthNight';
end;

//-----------------------------------------------------------------------------
function TFormEarth.AtmosphereColor(const rayStart, rayEnd: TGLVector): TGLColorVector;
var
  i, n: Integer;
  atmPoint, normal: TGLVector;
  altColor: TGLColorVector;
  alt, rayLength, contrib, decay, intensity, invN: Single;

begin
  Result := clrTransparent;
  rayLength := VectorDistance(rayStart, rayEnd);
  n := Round(3 * rayLength * invAtmosphereHeight) + 2;
  if n > 10 then
    n := 10;
  invN := cIntDivTable[n]; // 1/n;
  contrib := rayLength * invN * cOpacity;
  decay := 1 - contrib * 0.5;
  contrib := contrib * (1 / 1.1);
  for i := n - 1 downto 0 do
  begin
    VectorLerp(rayStart, rayEnd, i * invN, atmPoint);
    // diffuse lighting normal
    normal := VectorNormalize(atmPoint);
    // diffuse lighting intensity
    intensity := VectorDotProduct(normal, lightingVector) + 0.1;
    if PInteger(@intensity)^ > 0 then
    begin
      // sample on the lit side
      intensity := intensity * contrib;
      alt := (VectorLength(atmPoint) - cEarthRadius) * invAtmosphereHeight;
      VectorLerp(cLowAtmColor, cHighAtmColor, alt, altColor);
      Result.X := Result.X * decay + altColor.X * intensity;
      Result.Y := Result.Y * decay + altColor.Y * intensity;
      Result.Z := Result.Z * decay + altColor.Z * intensity;
    end
    else
    begin
      // sample on the dark sid
      Result.X := Result.X * decay;
      Result.Y := Result.Y * decay;
      Result.Z := Result.Z * decay;
    end;
  end;
  Result.W := n * contrib * cOpacity * 0.1;
end;

//-----------------------------------------------------------------------------
function TFormEarth.ComputeColor(var rayDest: TGLVector; mayHitGround: Boolean): TGLColorVector;
var
  ai1, ai2, pi1, pi2: TGLVector;
  rayVector: TGLVector;
begin
  rayVector := VectorNormalize(VectorSubtract(rayDest, eyePos));
  if RayCastSphereIntersect(eyePos, rayVector, NullHmgPoint, cAtmosphereRadius, ai1, ai2) > 1 then
  begin
    // atmosphere hit
    if mayHitGround and (RayCastSphereIntersect(eyePos, rayVector, NullHmgPoint,
      cEarthRadius, pi1,
      pi2) > 0) then
    begin
      // hit ground
      Result := AtmosphereColor(ai1, pi1);
    end
    else
    begin
      // through atmosphere only
      Result := AtmosphereColor(ai1, ai2);
    end;
    rayDest := ai1;
  end
  else
    Result := clrTransparent;
end;

//-----------------------------------------------------------------------------
// DirectOpenGLRender for atmosphere
//-----------------------------------------------------------------------------
procedure TFormEarth.DirectOpenGLRender(Sender: TObject; var rci: TGLRenderContextInfo);

const
  cSlices = 60;
var
  i, j, k0, k1: Integer;
  cosCache, sinCache: array [0 .. cSlices] of Single;
  pVertex, pColor: PVectorArray;
begin
  sunPos := LightSourceSun.AbsolutePosition;
  eyePos := Camera.AbsolutePosition;

  diskNormal := VectorNegate(eyePos);
  NormalizeVector(diskNormal);
  diskRight := VectorCrossProduct(Camera.AbsoluteUp, diskNormal);
  NormalizeVector(diskRight);
  diskUp := VectorCrossProduct(diskNormal, diskRight);
  NormalizeVector(diskUp);

  invAtmosphereHeight := 1 / (cAtmosphereRadius - cEarthRadius);
  lightingVector := VectorNormalize(sunPos); // sun at infinity
  PrepareSinCosCache(sinCache, cosCache, 0, 360);

  GetMem(pVertex, 2 * (cSlices + 1) * SizeOf(TGLVector));
  GetMem(pColor, 2 * (cSlices + 1) * SizeOf(TGLVector));

  rci.GLStates.DepthWriteMask := False;
  rci.GLStates.Disable(stLighting);
  rci.GLStates.Enable(stBlend);
  rci.GLStates.SetBlendFunc(bfSrcAlpha, bfOneMinusSrcAlpha);
  for i := 0 to 13 do
  begin
    if i < 5 then
      radius := cEarthRadius * Sqrt(i * (1 / 5))
    else
      radius := cEarthRadius + (i - 5.1) * (cAtmosphereRadius - cEarthRadius) * (1 / 6.9);
    radius := SphereVisibleRadius(VectorLength(eyePos), radius);
    k0 := (i and 1) * (cSlices + 1);
    k1 := (cSlices + 1) - k0;
    for j := 0 to cSlices do
    begin
      VectorCombine(diskRight, diskUp, cosCache[j] * radius, sinCache[j] * radius, pVertex[k0 + j]);
      if i < 13 then
        pColor[k0 + j] := ComputeColor(pVertex[k0 + j], i <= 7);
      if i = 0 then
        Break;
    end;

    if i > 1 then
    begin
      if i = 13 then
      begin
        glBegin(GL_QUAD_STRIP);
        for j := cSlices downto 0 do
        begin
          glColor4fv(@pColor[k1 + j]);
          glVertex3fv(@pVertex[k1 + j]);
          glColor4fv(@clrTransparent);
          glVertex3fv(@pVertex[k0 + j]);
        end;
        glEnd;
      end
      else
      begin
        glBegin(GL_QUAD_STRIP);
        for j := cSlices downto 0 do
        begin
          glColor4fv(@pColor[k1 + j]);
          glVertex3fv(@pVertex[k1 + j]);
          glColor4fv(@pColor[k0 + j]);
          glVertex3fv(@pVertex[k0 + j]);
        end;
        glEnd;
      end;
    end
    else if i = 1 then
    begin
      glBegin(GL_TRIANGLE_FAN);
      glColor4fv(@pColor[k1]);
      glVertex3fv(@pVertex[k1]);
      for j := k0 + cSlices downto k0 do
      begin
        glColor4fv(@pColor[j]);
        glVertex3fv(@pVertex[j]);
      end;
      glEnd;
    end;
  end;
  rci.GLStates.DepthWriteMask := True;

  FreeMem(pVertex);
  FreeMem(pColor);
end;

//-----------------------------------------------------------------------------
// Constellation Lines
//-----------------------------------------------------------------------------
procedure TFormEarth.LoadConstellationLines;
var
  sl, line: TStrings;
  pos1, pos2: TAffineVector;
  i: Integer;

begin
  sl := TStringList.Create;
  line := TStringList.Create;
  sl.LoadFromFile('ConstellationLines.dat');
  for i := 0 to sl.Count - 1 do
  begin
    line.CommaText := sl[i];
    pos1 := LonLatToPos(StrToFloatDef(line[0], 0), StrToFloatDef(line[1], 0));
    ConstellationLines.AddNode(pos1);
    pos2 := LonLatToPos(StrToFloatDef(line[2], 0), StrToFloatDef(line[3], 0));
    ConstellationLines.AddNode(pos2);
  end;
  sl.Free;
  line.Free;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.miConstLinesClick(Sender: TObject);
begin
  ConstellationsAlpha := 0.5 - ConstellationsAlpha;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.miConstBoundariesClick(Sender: TObject);
begin
  ConstellationsAlpha := 0.5 - ConstellationsAlpha;
end;


//-----------------------------------------------------------------------------
procedure TFormEarth.TimerTimer(Sender: TObject);
begin
  Caption := Format('Earth ' + '%.1f FPS', [GLSceneViewer.FramesPerSecond]);
  GLSceneViewer.ResetPerformanceMonitor;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.tvPlanetsClick(Sender: TObject);
var
  I: Integer;
begin
  diskSaturnUp.Visible := False;
  diskSaturnDn.Visible := False;
  Camera.MoveTo(dcSolarSystem); // sfEarth
  Cameracontroller.MoveTo(dcSolarSystem); //sfEarth
  Camera.TargetObject := sfEarth;
  Cameracontroller.TargetObject := sfEarth;
  LensFlareSun.Visible := True;

//  for I := 0 to dcSolarSystem.Count - 1 do
//    dcSolarSystem.Children[I].Visible := False;
  case tvPlanets.Selected.StateIndex of
     0: begin // star sun
          sfGlobe.Material.LibMaterialName := 'sun';
          LensFlareSun.Visible := False;
        end;
     1: begin // planet mercury
          sfGlobe.Material.LibMaterialName := 'mercury';
        end;
     2: begin // planet venus
          sfGlobe.Material.LibMaterialName := 'venus';
        end;
     3: begin // planet earth
          sfGlobe.Material.LibMaterialName := 'earthDay';
        end;
     4: begin // moon Luna
           sfLuna.Material.LibMaterialName := 'moon';
           Camera.MoveTo(sfLuna);
           Cameracontroller.MoveTo(sfLuna);
           Camera.TargetObject := sfLuna;
           Cameracontroller.TargetObject := sfLuna;
        end;
     5: begin // planet Mars
          sfGlobe.Material.LibMaterialName := 'mars';
        end;
     6: begin // deimos
          // to be replaced with ffDeimos
          sfGlobe.Material.LibMaterialName := 'deimos';
        end;
     7: begin // phobos
          // to be replaced with ffPhobos
          sfGlobe.Material.LibMaterialName := 'phobos';
        end;
     8: begin // planet Jupiter
          sfGlobe.Material.LibMaterialName := 'jupiter';
        end;
     9: begin // moon Io
          sfGlobe.Material.LibMaterialName := 'io';
        end;
     10: begin // moon Europa
          sfGlobe.Material.LibMaterialName := 'europa';
        end;
     11: begin // moon Callisto
          sfGlobe.Material.LibMaterialName := 'callisto';
        end;
     12: begin // Ganymede
          sfGlobe.Material.LibMaterialName := 'ganymede';
        end;
     13: begin // planet Saturn
          sfGlobe.Material.LibMaterialName := 'saturn';
          // with rings
          diskSaturnUp.Visible := True;
          diskSaturnDn.Visible := True;
        end;
     14: begin // moon Enceladus
          sfGlobe.Material.LibMaterialName := 'enceladus';
        end;
     15: begin // moon Titan
          sfGlobe.Material.LibMaterialName := 'titan';
        end;
     16: begin // planet Uranus
          sfGlobe.Material.LibMaterialName := 'uranus';
        end;
     17: begin // planet Neptune
          sfGlobe.Material.LibMaterialName := 'neptune';
        end;
     18: begin // planet Pluto
          sfGlobe.Material.LibMaterialName := 'pluto';
        end;
     19: begin // moon Charon
          sfGlobe.Material.LibMaterialName := 'charon';
        end;
  end;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.GLCadencerProgress(Sender: TObject; const deltaTime, newTime: Double);
var
  d : Double;
  p : TAffineVector;
begin
  d := GMTDateTimeToJulianDay(Now-2+newTime*timeMultiplier);
  sfEarth.TurnAngle := sfEarth.TurnAngle + deltaTime * TimeMultiplier;

  p := ComputePlanetPosition(cSunOrbitalElements, d);
  ScaleVector(p, 0.5*cAUToKilometers*(1/cEarthRadius));
  LensFlareSun.Position.AsAffineVector := p;

  // moon rotates on itself and around earth (not sure about the rotation direction!)

   p := ComputePlanetPosition(cMoonOrbitalElements, d);
    ScaleVector(p, 0.5*cAUToKilometers*(1/cEarthRadius));

  dcLuna.TurnAngle := dcLuna.TurnAngle + deltaTime * TimeMultiplier / 29.5;
  sfLuna.TurnAngle := 180 - dcLuna.TurnAngle;

  // Honour camera movements
  if (dmy <> 0) or (dmx <> 0) then
  begin
    Cameracontroller.MoveAroundTarget(ClampValue(dmy * 0.3, -5, 5), ClampValue(dmx * 0.3, -5, 5));
    dmx := 0;
    dmy := 0;
  end;
  // This gives us smoother camera movements
  CameraTimeSteps := CameraTimeSteps + deltaTime;
  while CameraTimeSteps > 0.005 do
  begin
    Camera.Position.AsVector := VectorLerp(Camera.Position.AsVector,
      Cameracontroller.Position.AsVector, 0.05);
    CameraTimeSteps := CameraTimeSteps - 0.005;
  end;
  // Smooth constellation lines appearance/disappearance
  if ConstellationLines.LineColor.Alpha <> ConstellationsAlpha then
  begin
    ConstellationLines.LineColor.Alpha :=
      ClampValue(ConstellationLines.LineColor.Alpha +
      Sign(ConstellationsAlpha - ConstellationLines.LineColor.Alpha) * deltaTime, 0, 0.5);
    ConstellationLines.Visible := (ConstellationLines.LineColor.Alpha > 0);
  end;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.GLSceneViewerMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
begin
  mx := X;
  my := Y;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.GLSceneViewerMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
begin
  if Shift = [ssLeft] then
  begin
    dmx := dmx + (mx - X);
    dmy := dmy + (my - Y);
  end
  else if Shift = [ssRight] then
    Camera.FocalLength := Camera.FocalLength * Power(1.05, (my - Y) * 0.1);
  mx := X;
  my := Y;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.Hide1Click(Sender: TObject);
begin
  PanelLeft.Visible := False;
  dcEarth.Visible := False;
  dcSolarSystem.Visible := False;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.Show1Click(Sender: TObject);
begin
  PanelLeft.Visible := True;
  dcEarth.Visible := True;
  dcSolarSystem.Visible := True;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.FormMouseWheel(Sender: TObject; Shift: TShiftState; WheelDelta: Integer;
  MousePos: TPoint; var Handled: Boolean);
var
  f: Single;
begin
  if (WheelDelta > 0) or (Cameracontroller.Position.VectorLength > 0.90) then
  begin
    f := Power(1.05, WheelDelta * (1 / 120));
    Cameracontroller.AdjustDistanceToTarget(f);
  end;
  Handled := True;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.GLSceneViewerDblClick(Sender: TObject);
begin
  GLSceneViewer.OnMouseMove := nil;
  if WindowState = wsMaximized then
  begin
    WindowState := wsNormal;
    BorderStyle := bsSizeToolWin;
  end
  else
  begin
    BorderStyle := bsNone;
    WindowState := wsMaximized;
  end;
  GLSceneViewer.OnMouseMove := GLSceneViewerMouseMove;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.LoadHighResTexture(LibMat: TGLLibMaterial; const FileName: string);
begin
  if FileExists(FileName) then
  begin
    LibMat.Material.Texture.Compression := tcStandard;
    LibMat.Material.Texture.Image.LoadFromFile(FileName);
  end;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.FormKeyPress(Sender: TObject; var Key: Char);
begin
  case Key of
    #27:
      FormEarth.Close;
    'm', 'M':
      begin
        Camera.MoveTo(sfLuna);
        Cameracontroller.MoveTo(sfLuna);
        Camera.TargetObject := sfLuna;
        Cameracontroller.TargetObject := sfLuna;
      end;
    'e', 'E':
      begin
        Camera.MoveTo(dcEarth);
        Cameracontroller.MoveTo(dcEarth);
        Camera.TargetObject := dcEarth;
        Cameracontroller.TargetObject := dcEarth;
      end;
    'h':
      if not HighResResourcesLoaded then
      begin
        GLSceneViewer.Cursor := crHourGlass;
        try
          LoadHighResTexture(GLPlanetMaps.Materials[0], 'earth_4096.jpg');
          LoadHighResTexture(GLPlanetMaps.Materials[1], 'earth_night_4096.jpg');
          LoadHighResTexture(GLPlanetMaps.Materials[2], 'moon_2048.jpg');
          GLSceneViewer.Buffer.AntiAliasing := aa2x;
        finally
          GLSceneViewer.Cursor := crDefault;
        end;
        HighResResourcesLoaded := True;
      end;
    'c':
      ConstellationsAlpha := 0.5 - ConstellationsAlpha;
    '0' .. '9':
      TimeMultiplier := Power(Integer(Key) - Integer('0'), 3);
  end;
end;

//-----------------------------------------------------------------------------
procedure TFormEarth.Exit1Click(Sender: TObject);
begin
  Close;
end;

//-----------------------------------------------------------------------------
end.

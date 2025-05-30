//
// The graphics engine GLXEngine. The unit of GXScene for Delphi
//
unit GXSL.BumpShaders;

(*
   A GXSL shader that applies bump mapping.

    This is a collection of GLSL Bump shaders, comes in these variaties
         (to know what these abriviations mean, see GXSL.CustomShader.pas):

      - TgxslBumpShader
      - TgxslBumpShaderMT
      - TgxslBumpShaderAM
      - TgxslMLBumpShader
      - TgxslMLBumpShaderMT

    Notes:
     1) Alpha is a synthetic property, in real life your should set each
      color's Alpha individualy
     2) TgxslMLBumpShader takes all Light parameters directly
      from OpenGL (that includes TgxLightSource's)

    TODO:
      1) Implement IgxShaderDescription in all shaders.
*)

interface

uses
  Winapi.OpenGL,
  Winapi.OpenGLext,

  System.Classes,
  System.SysUtils,

  GXS.Context,
  Stage.VectorGeometry,
  Stage.VectorTypes,
  GXS.VectorLists,

  GXS.Texture,
  GXS.Scene,
  GXS.Cadencer,
  Stage.Strings,
  GXS.Color,
  GXS.RenderContextInfo,
  GXS.Material,
  GXS.Graphics,
  GXS.State,

  GXSL.CustomShader,
  GXSL.Shader,
  Stage.TextureFormat;

type
  TBumpMethod = (bmDot3TexCombiner, bmBasicARBFP);
  TBumpSpace = (bsObject, bsTangentExternal, bsTangentQuaternion);

  TBumpOption = (boDiffuseTexture2, // Use secondary texture as diffuse
    boSpecularTexture3, // Use tertiary texture as specular
    boUseSecondaryTexCoords, // Pass through secondary texcoords
    boLightAttenuation, // Use light attenuation
    boParallaxMapping // Enable parallax offset mapping
    );
  TBumpOptions = set of TBumpOption;
  TSpecularMode = (smOff, smBlinn, smPhong);

  EgxslBumpShaderException = class(EgxslShaderException);

  // An abstract class.
  TgxslBaseCustomBumpShader = class(TgxslCustomShader, IgxMaterialLibrarySupported)
  private
    FBumpHeight: Single;
    FBumpSmoothness: Integer;
    FSpecularPower: Single;
    FSpecularSpread: Single;
    FLightPower: Single;
    FMaterialLibrary: TgxMaterialLibrary;
    FNormalTexture: TgxTexture;
    FSpecularTexture: TgxTexture;
    FNormalTextureName: TgxLibMaterialName;
    FSpecularTextureName: TgxLibMaterialName;
    function GetNormalTextureName: TgxLibMaterialName;
    function GetSpecularTextureName: TgxLibMaterialName;
    procedure SetNormalTextureName(const Value: TgxLibMaterialName);
    procedure SetSpecularTextureName(const Value: TgxLibMaterialName);
    procedure SetSpecularTexture(const Value: TgxTexture);
    procedure SetNormalTexture(const Value: TgxTexture);
    // Implementing IGLMaterialLibrarySupported.
    function GetMaterialLibrary: TgxAbstractMaterialLibrary;
  protected
    procedure DoApply(var rci : TgxRenderContextInfo; Sender : TObject); override;
    function DoUnApply(var rci: TgxRenderContextInfo): Boolean; override;
    procedure SetMaterialLibrary(const Value: TgxMaterialLibrary); virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner : TComponent); override;
    property BumpHeight: Single read FBumpHeight write FBumpHeight;
    property BumpSmoothness: Integer read FBumpSmoothness write FBumpSmoothness;
    property SpecularPower: Single read FSpecularPower write FSpecularPower;
    property SpecularSpread: Single read FSpecularSpread write FSpecularSpread;
    property LightPower: Single read FLightPower write FLightPower;
    property NormalTexture: TgxTexture read FNormalTexture write SetNormalTexture;
    property SpecularTexture: TgxTexture read FSpecularTexture write SetSpecularTexture;
    property NormalTextureName: TgxLibMaterialName read GetNormalTextureName write SetNormalTextureName;
    property SpecularTextureName: TgxLibMaterialName read GetSpecularTextureName write SetSpecularTextureName;
    property MaterialLibrary: TgxMaterialLibrary read FMaterialLibrary write SetMaterialLibrary;
  end;

  // An abstract class.
  TgxslBaseCustomBumpShaderMT = class(TgxslBaseCustomBumpShader)
  private
    FMainTexture: TgxTexture;
    FMainTextureName: TgxLibMaterialName;
    function GetMainTextureName: string;
    procedure SetMainTextureName(const Value: string);
  protected
    procedure SetMaterialLibrary(const Value: TgxMaterialLibrary); override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    property MainTexture: TgxTexture read FMainTexture write FMainTexture;
    property MainTextureName: TgxLibMaterialName read GetMainTextureName write SetMainTextureName;
  end;

  // One Light shaders.
  TgxslCustomBumpShaderAM = class(TgxslBaseCustomBumpShaderMT)
  private
    FAmbientColor: TgxColor;
    FDiffuseColor: TgxColor;
    FSpecularColor: TgxColor;

    function GetAlpha: Single;
    procedure SetAlpha(const Value: Single);
  protected
    procedure DoApply(var rci : TgxRenderContextInfo; Sender : TObject); override;
    procedure DoInitialize(var rci : TgxRenderContextInfo; Sender : TObject); override;
  public
    constructor Create(AOwner : TComponent); override;
    destructor Destroy; override;
    property AmbientColor: TgxColor read FAmbientColor;
    property DiffuseColor: TgxColor read FDiffuseColor;
    property SpecularColor: TgxColor read FSpecularColor;
    property Alpha: Single read GetAlpha write SetAlpha;
  end;

  TgxslCustomBumpShaderMT = class(TgxslBaseCustomBumpShaderMT)
  protected
    procedure DoApply(var rci : TgxRenderContextInfo; Sender : TObject); override;
    procedure DoInitialize(var rci : TgxRenderContextInfo; Sender : TObject); override;
  end;

  TgxslCustomBumpShader = class(TgxslBaseCustomBumpShader, IgxShaderDescription)
  private
    // Implementing IGLShaderDescription.
    procedure SetShaderTextures(const Textures: array of TgxTexture);
    procedure GetShaderTextures(var Textures: array of TgxTexture);
    procedure SetShaderColorParams(const AAmbientColor, ADiffuseColor, ASpecularcolor: TVector4f);
    procedure GetShaderColorParams(var AAmbientColor, ADiffuseColor, ASpecularcolor: TVector4f);
    procedure SetShaderMiscParameters(const ACadencer: TgxCadencer; const AMatLib: TgxMaterialLibrary; const ALightSources: TgxLightSourceSet);
    procedure GetShaderMiscParameters(var ACadencer: TgxCadencer; var AMatLib: TgxMaterialLibrary; var ALightSources: TgxLightSourceSet);
    function GetShaderAlpha: Single;
    procedure SetShaderAlpha(const Value: Single);
    function GetShaderDescription: string;
  protected
    procedure DoApply(var rci : TgxRenderContextInfo; Sender : TObject); override;
    procedure DoInitialize(var rci : TgxRenderContextInfo; Sender : TObject); override;
  end;

  // MultiLight shaders.
  TgxslCustomMLBumpShader = class(TgxslBaseCustomBumpShader, IgxShaderDescription)
  private
    FLightSources: TgxLightSourceSet;
    FLightCompensation: Single;
    procedure SetLightSources(const Value: TgxLightSourceSet);
    procedure SetLightCompensation(const Value: Single);
    // Implementing IGLShaderDescription.
    procedure SetShaderTextures(const Textures: array of TgxTexture);
    procedure GetShaderTextures(var Textures: array of TgxTexture);
    procedure SetShaderColorParams(const AAmbientColor, ADiffuseColor, ASpecularcolor: TVector4f);
    procedure GetShaderColorParams(var AAmbientColor, ADiffuseColor, ASpecularcolor: TVector4f);
    procedure SetShaderMiscParameters(const ACadencer: TgxCadencer; const AMatLib: TgxMaterialLibrary; const ALightSources: TgxLightSourceSet);
    procedure GetShaderMiscParameters(var ACadencer: TgxCadencer; var AMatLib: TgxMaterialLibrary; var ALightSources: TgxLightSourceSet);
    function GetShaderAlpha: Single;
    procedure SetShaderAlpha(const Value: Single);
    function GetShaderDescription: string;
  protected
    procedure DoApply(var rci : TgxRenderContextInfo; Sender : TObject); override;
    procedure DoInitialize(var rci : TgxRenderContextInfo; Sender : TObject); override;
  public
    constructor Create(AOwner : TComponent); override;
    property LightSources: TgxLightSourceSet read FLightSources write SetLightSources default [1];
    { Setting LightCompensation to a value less than 1 decreeses individual
       light intensity when using multiple lights }
    property LightCompensation: Single read FLightCompensation write SetLightCompensation;
  end;

  TgxslCustomMLBumpShaderMT = class(TgxslBaseCustomBumpShaderMT)
  private
    FLightSources: TgxLightSourceSet;
    FLightCompensation: Single;
    procedure SetLightSources(const Value: TgxLightSourceSet);
    procedure SetLightCompensation(const Value: Single);
  protected
    procedure DoApply(var rci : TgxRenderContextInfo; Sender : TObject); override;
    procedure DoInitialize(var rci : TgxRenderContextInfo; Sender : TObject); override;
  public
    constructor Create(AOwner : TComponent); override;
    property LightSources: TgxLightSourceSet read FLightSources write SetLightSources default [1];
    (* Setting LightCompensation to a value less than 1 decreeses individual
       light intensity when using multiple lights *)
    property LightCompensation: Single read FLightCompensation write SetLightCompensation;
  end;

  // One light shaders.
  TgxslBumpShaderMT = class(TgxslCustomBumpShaderMT)
  published
    property MainTextureName;
    property NormalTextureName;
    property SpecularTextureName;
    property MaterialLibrary;
    property BumpHeight;
    property BumpSmoothness;
    property SpecularPower;
    property SpecularSpread;
    property LightPower;
  end;

  TgxslBumpShader = class(TgxslCustomBumpShader)
  published
    property NormalTextureName;
    property SpecularTextureName;
    property MaterialLibrary;
    property BumpHeight;
    property BumpSmoothness;
    property SpecularPower;
    property SpecularSpread;
    property LightPower;
  end;

  TgxslBumpShaderAM = class(TgxslCustomBumpShaderAM)
  published
    property AmbientColor;
    property DiffuseColor;
    property SpecularColor;
    property Alpha stored False;
    property MainTextureName;
    property NormalTextureName;
    property SpecularTextureName;
    property MaterialLibrary;
    property BumpHeight;
    property BumpSmoothness;
    property SpecularPower;
    property SpecularSpread;
    property LightPower;
  end;

  // Multi light shaders.
  TgxslMLBumpShader = class(TgxslCustomMLBumpShader)
  published
    property NormalTextureName;
    property SpecularTextureName;
    property MaterialLibrary;
    property BumpHeight;
    property BumpSmoothness;
    property SpecularPower;
    property SpecularSpread;
    property LightPower;
    property LightSources;
    property LightCompensation;
  end;

  TgxslMLBumpShaderMT = class(TgxslCustomMLBumpShaderMT)
  published
    property MainTextureName;
    property NormalTextureName;
    property SpecularTextureName;
    property MaterialLibrary;
    property BumpHeight;
    property BumpSmoothness;
    property SpecularPower;
    property SpecularSpread;
    property LightPower;
    property LightSources;
    property LightCompensation;
  end;

(*
   A shader that applies bump mapping.
   Notes:
   The normal map is expected to be the primary texture.

   The secondary texture is used for the diffuse texture,
   to enable set boDiffuseTexture2 in the BumpOptions property.

   The tertiary texture is used for the specular texture,
   to enable set boSpecularTexture3 in the BumpOptions property.
   The SpecularMode determines the specular highlight calculation
   (Blinn or Phong), smOff disables specular highlights in the
   shader.

   External tangent bump space expects tangent data under
   GL_TEXTURE1_ARB and binormal data under GL_TEXTURE2_ARB.

   The boUseSecondaryTexCoords bump option tells the shader to use
   the secondary texture coordinates for the diffuse and specular
   texture lookups.

*)

  // A generic bump shader
  TgxBumpShader = class(TgxShader)
  private
    FVertexProgramHandle: TgxVertexProgramHandle;
    FFragmentProgramHandle: TgxFragmentProgramHandle;
    FLightIDs: TgxIntegerList;
    FLightsEnabled: Integer;
    FBumpMethod: TBumpMethod;
    FBumpSpace: TBumpSpace;
    FBumpOptions: TBumpOptions;
    FSpecularMode: TSpecularMode;
    FDesignTimeEnabled: Boolean;
    FAmbientPass: Boolean;
    FDiffusePass: Boolean;
    FVertexProgram: TStringList;
    FFragmentProgram: TStringList;
    FParallaxOffset: Single;
    function GenerateVertexProgram: string;
    function GenerateFragmentProgram: string;
    procedure DoLightPass(var rci: TgxRenderContextInfo; lightID: Cardinal);
  protected
    procedure SetBumpMethod(const Value: TBumpMethod);
    procedure SetBumpSpace(const Value: TBumpSpace);
    procedure SetBumpOptions(const Value: TBumpOptions);
    procedure SetSpecularMode(const Value: TSpecularMode);
    procedure SetDesignTimeEnabled(const Value: Boolean);
    procedure SetParallaxOffset(const Value: Single);
    procedure Loaded; override;
    procedure DeleteVertexPrograms;
    procedure DeleteFragmentPrograms;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure DoApply(var rci: TgxRenderContextInfo; Sender: TObject); override;
    function DoUnApply(var rci: TgxRenderContextInfo): Boolean; override;
  published
    property BumpMethod: TBumpMethod read FBumpMethod write SetBumpMethod;
    property BumpSpace: TBumpSpace read FBumpSpace write SetBumpSpace;
    property BumpOptions: TBumpOptions read FBumpOptions write SetBumpOptions;
    property SpecularMode: TSpecularMode read FSpecularMode write SetSpecularMode;
    property DesignTimeEnabled: Boolean read FDesignTimeEnabled write SetDesignTimeEnabled;
    property ParallaxOffset: Single read FParallaxOffset write SetParallaxOffset;
  end;


//-----------------------------------------------------------------------------
implementation
//-----------------------------------------------------------------------------

procedure GetVertexProgramCode(const Code: TStrings);
begin
  with Code do
  begin
    Clear;
    Add('varying vec2 Texcoord; ');
    Add('varying vec3 ViewDirection; ');
    Add('varying vec3 LightDirection; ');
    Add(' ');
    Add('void main( void ) ');
    Add('{ ');
    Add('   gl_Position = ftransform(); ');
    Add('   Texcoord    = gl_MultiTexCoord0.xy; ');
    Add(' ');
    Add('   vec3 fvViewDirection   = (gl_ModelViewMatrix * gl_Vertex).xyz; ');
    Add('   vec3 fvLightDirection  =  gl_LightSource[0].position.xyz - fvViewDirection; ');
    Add(' ');
    Add('   vec3 fvNormal         = gl_NormalMatrix * gl_Normal; ');
    Add('   vec3 fvBinormal       = gl_NormalMatrix * gl_MultiTexCoord2.xyz; ');
    Add('   vec3 fvTangent        = gl_NormalMatrix * gl_MultiTexCoord1.xyz; ');
    Add(' ');
    Add('   ViewDirection.x  = dot( fvTangent, fvViewDirection ); ');
    Add('   ViewDirection.y  = dot( fvBinormal, fvViewDirection ); ');
    Add('   ViewDirection.z  = dot( fvNormal, fvViewDirection ); ');
    Add(' ');
    Add('   LightDirection.x  = dot( fvTangent, fvLightDirection ); ');
    Add('   LightDirection.y  = dot( fvBinormal, fvLightDirection ); ');
    Add('   LightDirection.z  = dot( fvNormal, fvLightDirection ); ');
    Add(' ');
    Add('   LightDirection = normalize(LightDirection); ');
    Add('   ViewDirection  = normalize(ViewDirection); ');
    Add('} ');
  end;
end;

procedure GetFragmentProgramCodeMP(const Code: TStrings; const UseSpecularMap: Boolean; const UseNormalMap: Boolean);
begin
  with Code do
  begin
    Clear;
    Add('uniform vec4 fvAmbient; ');
    Add('uniform vec4 fvSpecular; ');
    Add('uniform vec4 fvDiffuse; ');
    Add(' ');
    Add('uniform float fLightPower; ');
    Add('uniform float fSpecularPower; ');
    Add('uniform float fSpecularSpread; ');
    if UseNormalMap then
    begin
      Add('uniform sampler2D bumpMap; ');
      Add('uniform float fBumpHeight; ');
      Add('uniform float fBumpSmoothness; ');
    end;
    Add(' ');
    Add('uniform sampler2D baseMap; ');
    if UseSpecularMap then
      Add('uniform sampler2D specMap; ');
    Add(' ');
    Add('varying vec2 Texcoord; ');
    Add('varying vec3 ViewDirection; ');
    Add('varying vec3 LightDirection; ');
    Add(' ');
    Add('void main( void ) ');
    Add('{ ');
    if UseNormalMap then
      Add('   vec3  fvNormal = normalize( ( texture2D( bumpMap, Texcoord ).xyz * fBumpSmoothness) - fBumpHeight * fBumpSmoothness); ')
    else
      Add('   vec3  fvNormal = vec3(0.0, 0.0, 1);');
    Add(' ');
    Add('   float fNDotL           = dot( fvNormal, LightDirection ); ');
    Add('   vec3  fvReflection     = normalize( ( (fSpecularSpread * fvNormal ) * fNDotL ) - LightDirection ); ');
    Add(' ');
    Add('   float fRDotV           = max( dot( fvReflection, -ViewDirection ), 0.0 ); ');
    Add(' ');
    Add('   vec4  fvBaseColor      = texture2D( baseMap, Texcoord ); ');
    if UseSpecularMap then
      Add('   vec4  fvSpecColor      = texture2D( specMap, Texcoord ) * fvSpecular; ')
    else
      Add('   vec4  fvSpecColor      =                                  fvSpecular; ');
    Add(' ');
    Add('   vec4  fvTotalDiffuse   = clamp(fvDiffuse * fNDotL, 0.0, 1.0); ');
    Add(' ');
    Add('    //  (fvTotalDiffuse + 0.2) / 1.2 is used for removing artefacts on the non-lit side ');
    Add('   vec4  fvTotalSpecular  = clamp((pow(fRDotV, fSpecularPower ) ) * (fvTotalDiffuse + 0.2) / 1.2 * fvSpecColor, 0.0, 1.0); ');
    Add(' ');
    Add('   gl_FragColor = fLightPower * (fvBaseColor * ( fvAmbient + fvTotalDiffuse ) + fvTotalSpecular); ');
    Add('} ');
  end;
end;

procedure GetFragmentProgramCode(const Code: TStrings; const UseSpecularMap: Boolean; const UseNormalMap: Boolean);
begin
  with Code do
  begin
    Clear;
    Add('uniform float fLightPower; ');
    Add('uniform float fSpecularPower; ');
    Add('uniform float fSpecularSpread; ');
    if UseNormalMap then
    begin
      Add('uniform sampler2D bumpMap; ');
      Add('uniform float fBumpHeight; ');
      Add('uniform float fBumpSmoothness; ');
    end;
    Add(' ');
    Add('uniform sampler2D baseMap; ');
    if UseSpecularMap then
      Add('uniform sampler2D specMap; ');
    Add(' ');
    Add('varying vec2 Texcoord; ');
    Add('varying vec3 ViewDirection; ');
    Add('varying vec3 LightDirection; ');
    Add(' ');
    Add('void main( void ) ');
    Add('{ ');
    if UseNormalMap then
      Add('   vec3  fvNormal = normalize( ( texture2D( bumpMap, Texcoord ).xyz * fBumpSmoothness) - fBumpHeight * fBumpSmoothness); ')
    else
      Add('   vec3  fvNormal = vec3(0.0, 0.0, 1.0);');
    Add(' ');
    Add('   float fNDotL           = dot( fvNormal, LightDirection ); ');
    Add('   vec3  fvReflection     = normalize( ( (fSpecularSpread * fvNormal ) * fNDotL ) - LightDirection ); ');
    Add(' ');
    Add('   float fRDotV           = max(dot( fvReflection, -ViewDirection ), 0.0); ');
    Add(' '); 
    Add('   vec4  fvBaseColor      = texture2D( baseMap, Texcoord ); ');
    if UseSpecularMap then
      Add('   vec4  fvSpecColor      = texture2D( specMap, Texcoord ) * gl_LightSource[0].specular; ')
    else
      Add('   vec4  fvSpecColor      =                                  gl_LightSource[0].specular; ');
    Add(' ');
    Add('   vec4  fvTotalDiffuse   = clamp(gl_LightSource[0].diffuse * fNDotL, 0.0, 1.0); ');
    Add(' ');
    Add('    //  (fvTotalDiffuse + 0.2) / 1.2 is used for removing artefacts on the non-lit side ');
    Add('   vec4  fvTotalSpecular  = clamp((pow(fRDotV, fSpecularPower ) ) * (fvTotalDiffuse + 0.2) / 1.2 * fvSpecColor, 0.0, 1.0); ');
    Add(' ');
    Add('   gl_FragColor = fLightPower * (fvBaseColor * ( gl_LightSource[0].ambient + fvTotalDiffuse ) + fvTotalSpecular); ');
    Add('} ');
  end;
end;

procedure GetMLVertexProgramCode(const Code: TStrings);
begin
  with Code do
  begin
    Clear;
    Add('varying vec2 Texcoord; ');
    Add('varying vec3 ViewDirection; ');
    Add(' ');
    Add('varying vec3 fvViewDirection; ');
    Add('varying vec3 fvNormal; ');
    Add('varying vec3 fvBinormal; ');
    Add('varying vec3 fvTangent; ');
    Add(' ');
    Add('void main( void ) ');
    Add('{ ');
    Add('   gl_Position = ftransform(); ');
    Add('   Texcoord    = gl_MultiTexCoord0.xy; ');
    Add(' ');
    Add('   fvViewDirection   = (gl_ModelViewMatrix * gl_Vertex).xyz; ');
    Add(' ');
    Add('   fvNormal         = gl_NormalMatrix * gl_Normal; ');
    Add('   fvBinormal       = gl_NormalMatrix * gl_MultiTexCoord2.xyz; ');
    Add('   fvTangent        = gl_NormalMatrix * gl_MultiTexCoord1.xyz; ');
    Add(' ');
    Add('   ViewDirection.x  = dot( fvTangent, fvViewDirection ); ');
    Add('   ViewDirection.y  = dot( fvBinormal, fvViewDirection ); ');
    Add('   ViewDirection.z  = dot( fvNormal, fvViewDirection ); ');
    Add(' ');
    Add('   ViewDirection  = normalize(ViewDirection); ');
    Add('} ');
  end;
end;

procedure GetMLFragmentProgramCodeBeg(const Code: TStrings; const UseSpecularMap: Boolean; const UseNormalMap: Boolean);
begin
  with Code do
  begin
    Clear;
    Add('uniform float fLightPower; ');
    Add('uniform float fSpecularPower; ');
    Add('uniform float fSpecularSpread; ');
    if UseNormalMap then
    begin
      Add('uniform sampler2D bumpMap; ');
      Add('uniform float fBumpHeight; ');
      Add('uniform float fBumpSmoothness; ');
    end;
    Add(' ');
    Add('uniform sampler2D baseMap; ');
    if UseSpecularMap then
      Add('uniform sampler2D specMap; ');
    Add(' ');
    Add('varying vec2 Texcoord; ');
    Add('varying vec3 ViewDirection; ');
    Add(' ');
    Add('varying vec3 fvViewDirection; ');
    Add('varying vec3 fvNormal; ');
    Add('varying vec3 fvBinormal; ');
    Add('varying vec3 fvTangent; ');
    Add(' ');
    Add('void main( void ) ');
    Add('{ ');
    Add('   vec3 LightDirection;');
    Add('   vec3 fvLightDirection; ');
    Add(' ');
    if UseNormalMap then
      Add('   vec3  fvBumpNormal = normalize( ( texture2D( bumpMap, Texcoord ).xyz * fBumpSmoothness) - fBumpHeight * fBumpSmoothness); ')
    else
      Add('   vec3  fvBumpNormal = vec3(0.0, 0.0, 1);');
    Add(' ');
    Add('   float fNDotL        ; ');
    Add('   vec3  fvReflection  ; ');
    Add('   float fRDotV        ; ');
    Add('   vec4  fvBaseColor = texture2D( baseMap, Texcoord ); ');
    if UseSpecularMap then
      Add('   vec4 fvSpecColor      = texture2D( specMap, Texcoord ); ')
    else
      Add('   vec4 fvSpecColor      = vec4(1.0, 1.0, 1.0, 1.0); ');
    Add('   vec4  fvNewDiffuse  ; ');
    Add('   vec4  fvTotalDiffuse  = vec4(0, 0, 0, 0); ');
    Add('   vec4  fvTotalAmbient  = vec4(0, 0, 0, 0); ');
    Add('   vec4  fvTotalSpecular = vec4(0, 0, 0, 0); ');
  end;
end;

procedure GetMLFragmentProgramCodeMid(const Code: TStrings; const CurrentLight: Integer);
begin
  with Code do
  begin
    Add('   fvLightDirection  = gl_LightSource[' + IntToStr(CurrentLight) + '].position.xyz - fvViewDirection; ');
    Add(' ');
    Add('   LightDirection.x  = dot( fvTangent, fvLightDirection ); ');
    Add('   LightDirection.y  = dot( fvBinormal, fvLightDirection ); ');
    Add('   LightDirection.z  = dot( fvNormal, fvLightDirection ); ');
    Add('   LightDirection = normalize(LightDirection); ');
    Add(' ');
    Add('   fNDotL           = dot( fvBumpNormal, LightDirection ); ');
    Add('   fvReflection     = normalize( ( (fSpecularSpread * fvBumpNormal ) * fNDotL ) - LightDirection ); ');
    Add('   fRDotV           = max( dot( fvReflection, -ViewDirection ), 0.0 ); ');
    Add('   fvNewDiffuse     = clamp(gl_LightSource[' + IntToStr(CurrentLight) + '].diffuse * fNDotL, 0.0, 1.0); ');
    Add('   fvTotalDiffuse   = min(fvTotalDiffuse + fvNewDiffuse, 1.0); ');
    Add('   fvTotalSpecular  = min(fvTotalSpecular + clamp((pow(fRDotV, fSpecularPower ) ) * (fvNewDiffuse + 0.2) / 1.2 * (fvSpecColor * gl_LightSource[' + IntToStr(CurrentLight) + '].specular), 0.0, 1.0), 1.0); ');
    Add('   fvTotalAmbient   = fvTotalAmbient + gl_LightSource[' + IntToStr(CurrentLight) + '].ambient; ');
  end;
end;

procedure GetMLFragmentProgramCodeEnd(const Code: TStrings; const FLightCount: Integer; const FLightCompensation: Single);
var
  Temp: AnsiString;
begin
  with Code do
  begin
    Str((1 + (FLightCount  - 1) * FLightCompensation) / FLightCount :1 :1, Temp);
    if (FLightCount = 1) or (FLightCompensation = 1) then
      Add('   gl_FragColor = fLightPower * (fvBaseColor * ( fvTotalAmbient + fvTotalDiffuse ) + fvTotalSpecular); ')
    else
      Add('   gl_FragColor = fLightPower * (fvBaseColor * ( fvTotalAmbient + fvTotalDiffuse ) + fvTotalSpecular) * ' + string(Temp) + '; ');
    Add('} ');
  end;
end;


{ TgxslBaseCustomBumpShader }

constructor TgxslBaseCustomBumpShader.Create(AOwner: TComponent);
begin
  inherited;
  FSpecularPower := 6;
  FSpecularSpread := 1.5;
  FLightPower := 1;

  FBumpHeight := 0.5;
  FBumpSmoothness := 300;
  TStringList(VertexProgram.Code).OnChange := nil;
  TStringList(FragmentProgram.Code).OnChange := nil;
  VertexProgram.Enabled := True;
  FragmentProgram.Enabled := True;
end;

procedure TgxslBaseCustomBumpShader.DoApply(
  var rci: TgxRenderContextInfo; Sender: TObject);
begin
  // Don't inherit not to call the event.
  GetGXSLProg.UseProgramObject;

  Param['fSpecularPower'].AsVector1f := FSpecularPower;
  Param['fSpecularSpread'].AsVector1f := FSpecularSpread;
  Param['fLightPower'].AsVector1f := FLightPower;

  if FSpecularTexture <> nil then
    Param['specMap'].AsTexture2D[2] := FSpecularTexture;

{$IFNDEF USE_OPTIMIZATIONS}
  if FNormalTexture <> nil then
{$ENDIF}
  begin
    Param['bumpMap'].AsTexture2D[1] := FNormalTexture;
    Param['fBumpHeight'].AsVector1f := FBumpHeight;
    Param['fBumpSmoothness'].AsVector1f := FBumpSmoothness;
  end;
end;

function TgxslBaseCustomBumpShader.DoUnApply(
  var rci: TgxRenderContextInfo): Boolean;
begin
  //don't inherit not to call the event
  Result := False;
  GetGXSLProg.EndUseProgramObject;
end;

function TgxslBaseCustomBumpShader.GetMaterialLibrary: TgxAbstractMaterialLibrary;
begin
  Result := FMaterialLibrary;
end;

function TgxslBaseCustomBumpShader.GetNormalTextureName: TgxLibMaterialName;
begin
  Result := FMaterialLibrary.GetNameOfTexture(FNormalTexture);
  if Result = '' then Result := FNormalTextureName;
end;

function TgxslBaseCustomBumpShader.GetSpecularTextureName: TgxLibMaterialName;
begin
  Result := FMaterialLibrary.GetNameOfTexture(FSpecularTexture);
  if Result = '' then Result := FSpecularTextureName;
end;

procedure TgxslBaseCustomBumpShader.Notification(
  AComponent: TComponent; Operation: TOperation);
var
  Index: Integer;
begin
  inherited;
  if Operation = opRemove then
    if AComponent = FMaterialLibrary then
      if FMaterialLibrary <> nil then
      begin
        // Need to nil the textures that were ownned by it.
        if FNormalTexture <> nil then
        begin
          Index := FMaterialLibrary.Materials.GetTextureIndex(FNormalTexture);
          if Index <> -1 then
            SetNormalTexture(nil);
        end;

        if FSpecularTexture <> nil then
        begin
          Index := FMaterialLibrary.Materials.GetTextureIndex(FSpecularTexture);
          if Index <> -1 then
            SetSpecularTexture(nil);
        end;

        FMaterialLibrary := nil;
      end;
end;

procedure TgxslBaseCustomBumpShader.SetMaterialLibrary(
  const Value: TgxMaterialLibrary);
begin
  if FMaterialLibrary <> nil then
    FMaterialLibrary.RemoveFreeNotification(Self);
  FMaterialLibrary := Value;

  if FMaterialLibrary <> nil then
  begin
    FMaterialLibrary.FreeNotification(Self);

    if FNormalTextureName <> '' then
      SetNormalTextureName(FNormalTextureName);

    if FSpecularTextureName <> '' then
      SetSpecularTextureName(FSpecularTextureName);
  end
  else
  begin
    FNormalTextureName := '';
    FSpecularTextureName := '';
  end;
end;

procedure TgxslBaseCustomBumpShader.SetNormalTexture(
  const Value: TgxTexture);
begin
  FNormalTexture := Value;
  FinalizeShader;
end;

procedure TgxslBaseCustomBumpShader.SetNormalTextureName(
  const Value: TgxLibMaterialName);
begin
  if FMaterialLibrary = nil then
  begin
    FNormalTextureName := Value;
    if not (csLoading in ComponentState) then
      raise EgxslBumpShaderException.Create(strErrorEx + strMatLibNotDefined);
  end
  else
  begin
    SetNormalTexture(FMaterialLibrary.TextureByName(Value));
    FNormalTextureName := '';
  end;
end;

procedure TgxslBaseCustomBumpShader.SetSpecularTexture(
  const Value: TgxTexture);
begin
  FSpecularTexture := Value;
  FinalizeShader;
end;

procedure TgxslBaseCustomBumpShader.SetSpecularTextureName(
  const Value: TgxLibMaterialName);
begin
  if FMaterialLibrary = nil then
  begin
    FSpecularTextureName := Value;
    if not (csLoading in ComponentState) then
      raise EgxslBumpShaderException.Create(strErrorEx + strMatLibNotDefined);
  end
  else
  begin
    SetSpecularTexture(FMaterialLibrary.TextureByName(Value));
    FSpecularTextureName := '';
  end;
end;

{ TgxslBaseCustomBumpShaderMT }

function TgxslBaseCustomBumpShaderMT.GetMainTextureName: TgxLibMaterialName;
begin
  Result := FMaterialLibrary.GetNameOfTexture(FMainTexture);
  if Result = '' then Result := FMainTextureName;
end;

procedure TgxslBaseCustomBumpShaderMT.Notification(
  AComponent: TComponent; Operation: TOperation);
var
  Index: Integer;
begin
  if Operation = opRemove then
    if AComponent = FMaterialLibrary then
      if FMaterialLibrary <> nil then
      begin
        //need to nil the textures that were ownned by it
        if FMainTexture <> nil then
        begin
          Index := FMaterialLibrary.Materials.GetTextureIndex(FMainTexture);
          if Index <> -1 then
            FMainTexture := nil;
        end;
      end;
  inherited;
end;

procedure TgxslBaseCustomBumpShaderMT.SetMainTextureName(
  const Value: TgxLibMaterialName);
begin
  if FMaterialLibrary = nil then
  begin
    FMainTextureName := Value;
    if not (csLoading in ComponentState) then
      raise EgxslBumpShaderException.Create(strErrorEx + strMatLibNotDefined);
  end
  else
  begin
    FMainTexture := FMaterialLibrary.TextureByName(Value);
    FMainTextureName := '';
  end;
end;

procedure TgxslBaseCustomBumpShaderMT.SetMaterialLibrary(
  const Value: TgxMaterialLibrary);
begin
  inherited;
  if FMaterialLibrary <> nil then
  begin
    if FMainTextureName <> '' then
      SetMainTextureName(FMainTextureName);
  end
  else
    FMainTextureName := '';
end;

{ TgxslCustomBumpShaderAM }

constructor TgxslCustomBumpShaderAM.Create(AOwner: TComponent);
begin
  inherited;

  FAmbientColor := TgxColor.Create(Self);
  FDiffuseColor := TgxColor.Create(Self);
  FSpecularColor := TgxColor.Create(Self);

  // Setup initial parameters.
  FAmbientColor.SetColor(0.15, 0.15, 0.15, 1);
  FDiffuseColor.SetColor(1, 1, 1, 1);
  FSpecularColor.SetColor(1, 1, 1, 1);
end;

destructor TgxslCustomBumpShaderAM.Destroy;
begin
  FAmbientColor.Destroy;
  FDiffuseColor.Destroy;
  FSpecularColor.Destroy;

  inherited;
end;

procedure TgxslCustomBumpShaderAM.DoApply(var rci: TgxRenderContextInfo;
  Sender: TObject);
begin
  inherited;

  Param['fvAmbient'].AsVector4f := FAmbientColor.Color;
  Param['fvDiffuse'].AsVector4f := FDiffuseColor.Color;
  Param['fvSpecular'].AsVector4f := FSpecularColor.Color;

  Param['baseMap'].AsTexture2D[0] := FMainTexture;
end;

procedure TgxslCustomBumpShaderAM.DoInitialize(var rci : TgxRenderContextInfo; Sender : TObject);
begin
  GetVertexProgramCode(VertexProgram.Code);
  GetFragmentProgramCodeMP(FragmentProgram.Code, FSpecularTexture <> nil, FNormalTexture <> nil);
  VertexProgram.Enabled := True;
  FragmentProgram.Enabled := True;
  inherited;
end;

function TgxslCustomBumpShaderAM.GetAlpha: Single;
begin
  Result := (FAmbientColor.Alpha + FDiffuseColor.Alpha + FSpecularColor.Alpha) / 3;
end;

procedure TgxslCustomBumpShaderAM.SetAlpha(const Value: Single);
begin
  FAmbientColor.Alpha := Value;
  FDiffuseColor.Alpha := Value;
  FSpecularColor.Alpha := Value;
end;

{ TgxslCustomMLBumpShaderMT }

constructor TgxslCustomMLBumpShaderMT.Create(AOwner: TComponent);
begin
  inherited;

  FLightSources := [1];
  FLightCompensation := 1;
end;

procedure TgxslCustomMLBumpShaderMT.DoApply(var rci: TgxRenderContextInfo;
  Sender: TObject);
begin
  inherited;
  Param['baseMap'].AsTexture2D[0] := FMainTexture;
end;

procedure TgxslCustomMLBumpShaderMT.DoInitialize(var rci : TgxRenderContextInfo; Sender : TObject);
var
  I: Integer;
  lLightCount: Integer;
begin
  GetMLVertexProgramCode(VertexProgram.Code);
  
  with FragmentProgram.Code do
  begin
    GetMLFragmentProgramCodeBeg(FragmentProgram.Code, FSpecularTexture <> nil, FNormalTexture <> nil);

    lLightCount := 0;
    // Repeat for all lights.
    for I := 0 to gxsShaderMaxLightSources - 1 do
      if I + 1 in FLightSources then
      begin
        GetMLFragmentProgramCodeMid(FragmentProgram.Code, I);
        Inc(lLightCount);
      end;

    GetMLFragmentProgramCodeEnd(FragmentProgram.Code, lLightCount, FLightCompensation);
  end;
  VertexProgram.Enabled := True;
  FragmentProgram.Enabled := True;
  inherited;
end;

procedure TgxslCustomMLBumpShaderMT.SetLightCompensation(
  const Value: Single);
begin
  FLightCompensation := Value;
  FinalizeShader;
end;

procedure TgxslCustomMLBumpShaderMT.SetLightSources(
  const Value: TgxLightSourceSet);
begin
  Assert(Value <> [], strErrorEx + strShaderNeedsAtLeastOneLightSource);
  FLightSources := Value;
  FinalizeShader;
end;

{ TgxslCustomBumpShaderMT }

procedure TgxslCustomBumpShaderMT.DoApply(
  var rci: TgxRenderContextInfo; Sender: TObject);
begin
  inherited;
  Param['baseMap'].AsTexture2D[0] := FMainTexture;
end;

procedure TgxslCustomBumpShaderMT.DoInitialize(var rci : TgxRenderContextInfo; Sender : TObject);
begin
  GetVertexProgramCode(VertexProgram.Code);
  GetFragmentProgramCode(FragmentProgram.Code, FSpecularTexture <> nil, FNormalTexture <> nil);
  inherited;
end;

{ TgxslCustomBumpShader }

procedure TgxslCustomBumpShader.DoApply(var rci: TgxRenderContextInfo;
  Sender: TObject);
begin
  inherited;
  Param['baseMap'].AsVector1i := 0;  // Use the current texture.
end;

procedure TgxslCustomBumpShader.DoInitialize(var rci : TgxRenderContextInfo; Sender : TObject);
begin
  GetVertexProgramCode(VertexProgram.Code);
  GetFragmentProgramCode(FragmentProgram.Code, FSpecularTexture <> nil, FNormalTexture <> nil);
  VertexProgram.Enabled := True;
  FragmentProgram.Enabled := True;
  inherited;
end;


function TgxslCustomBumpShader.GetShaderAlpha: Single;
begin
  //ignore
  Result := -1;
end;

procedure TgxslCustomBumpShader.GetShaderColorParams(var AAmbientColor,
  ADiffuseColor, ASpecularcolor: TVector4f);
begin
  //ignore
  AAmbientColor := NullHmgVector;
  ADiffuseColor := NullHmgVector;
  ASpecularcolor := NullHmgVector;
end;

procedure TgxslCustomBumpShader.GetShaderTextures(
  var Textures: array of TgxTexture);
begin
  Textures[0] := FNormalTexture;
  Textures[1] := FSpecularTexture;
end;

procedure TgxslCustomBumpShader.GetShaderMiscParameters(var ACadencer: TgxCadencer;
  var AMatLib: TgxMaterialLibrary; var ALightSources: TgxLightSourceSet);
begin
  ACadencer := nil;
  AMatLib := FMaterialLibrary;
  ALightSources := [0];
end;

procedure TgxslCustomBumpShader.SetShaderAlpha(const Value: Single);
begin
  //ignore
end;

procedure TgxslCustomBumpShader.SetShaderColorParams(const AAmbientColor,
  ADiffuseColor, ASpecularcolor: TVector4f);
begin
  //ignore
end;

procedure TgxslCustomBumpShader.SetShaderMiscParameters(
  const ACadencer: TgxCadencer; const AMatLib: TgxMaterialLibrary;
  const ALightSources: TgxLightSourceSet);
begin
  SetMaterialLibrary(AMatLib);
end;

procedure TgxslCustomBumpShader.SetShaderTextures(
  const Textures: array of TgxTexture);
begin
  SetNormalTexture(Textures[0]);
  SetSpecularTexture(Textures[1]);
end;

function TgxslCustomBumpShader.GetShaderDescription: string;
begin
  Result := 'ShaderTexture1 is NormalMap, ShaderTexture2 is SpecularMap'
end;


{ TgxslCustomMLBumpShader }

constructor TgxslCustomMLBumpShader.Create(AOwner: TComponent);
begin
  inherited;

  FLightSources := [1];
  FLightCompensation := 1;
end;

procedure TgxslCustomMLBumpShader.DoApply(var rci: TgxRenderContextInfo;
  Sender: TObject);
begin
  inherited;
  Param['baseMap'].AsVector1i := 0;  // Use the current texture.
end;

procedure TgxslCustomMLBumpShader.DoInitialize(var rci : TgxRenderContextInfo; Sender : TObject);
var
  I: Integer;
  lLightCount: Integer;
begin
  GetMLVertexProgramCode(VertexProgram.Code);
  
  with FragmentProgram.Code do
  begin
    GetMLFragmentProgramCodeBeg(FragmentProgram.Code, FSpecularTexture <> nil, FNormalTexture <> nil);

    lLightCount := 0;

    // Repeat for all lights.
    for I := 0 to gxsShaderMaxLightSources - 1 do
      if I + 1 in FLightSources then
      begin
        GetMLFragmentProgramCodeMid(FragmentProgram.Code, I);
        Inc(lLightCount);
      end;

    GetMLFragmentProgramCodeEnd(FragmentProgram.Code, lLightCount, FLightCompensation);
  end;
  VertexProgram.Enabled := True;
  FragmentProgram.Enabled := True;
  inherited;
end;

procedure TgxslCustomMLBumpShader.SetLightCompensation(
  const Value: Single);
begin
  FLightCompensation := Value;
  FinalizeShader;
end;

procedure TgxslCustomMLBumpShader.SetLightSources(
  const Value: TgxLightSourceSet);
begin
  Assert(Value <> [], strErrorEx + strShaderNeedsAtLeastOneLightSource);
  FLightSources := Value;
  FinalizeShader;
end;

function TgxslCustomMLBumpShader.GetShaderAlpha: Single;
begin
  //ignore
  Result := -1;
end;

procedure TgxslCustomMLBumpShader.GetShaderColorParams(var AAmbientColor,
  ADiffuseColor, ASpecularcolor: TVector4f);
begin
  //ignore
  AAmbientColor := NullHmgVector;
  ADiffuseColor := NullHmgVector;
  ASpecularcolor := NullHmgVector;
end;

function TgxslCustomMLBumpShader.GetShaderDescription: string;
begin
  Result := 'ShaderTexture1 is NormalMap, ShaderTexture2 is SpecularMap';
end;

procedure TgxslCustomMLBumpShader.GetShaderMiscParameters(
  var ACadencer: TgxCadencer; var AMatLib: TgxMaterialLibrary;
  var ALightSources: TgxLightSourceSet);
begin
  ACadencer := nil;
  AMatLib := FMaterialLibrary;
  ALightSources := FLightSources;
end;

procedure TgxslCustomMLBumpShader.GetShaderTextures(
  var Textures: array of TgxTexture);
begin
  Textures[0] := FNormalTexture;
  Textures[1] := FSpecularTexture;
end;

procedure TgxslCustomMLBumpShader.SetShaderAlpha(const Value: Single);
begin
  //ignore
end;

procedure TgxslCustomMLBumpShader.SetShaderColorParams(const AAmbientColor,
  ADiffuseColor, ASpecularcolor: TVector4f);
begin
  //ignore
end;

procedure TgxslCustomMLBumpShader.SetShaderMiscParameters(
  const ACadencer: TgxCadencer; const AMatLib: TgxMaterialLibrary;
  const ALightSources: TgxLightSourceSet);
begin
  SetMaterialLibrary(AMatLib);
  SetLightSources(ALightSources);
end;

procedure TgxslCustomMLBumpShader.SetShaderTextures(
  const Textures: array of TgxTexture);
begin
  SetNormalTexture(Textures[0]);
  SetSpecularTexture(Textures[1]);
end;


// ------------------
// ------------------ TgxBumpShader ------------------
// ------------------

constructor TgxBumpShader.Create(AOwner: TComponent);
begin
  inherited;
  FLightIDs := TgxIntegerList.Create;
  FBumpMethod := bmDot3TexCombiner;
  FBumpSpace := bsObject;
  FBumpOptions := [];
  FSpecularMode := smOff;
  ShaderStyle := ssLowLevel;
  FParallaxOffset := 0.04;

  FVertexProgram := TStringList.Create;
  FFragmentProgram := TStringList.Create;
end;

destructor TgxBumpShader.Destroy;
begin
  DeleteVertexPrograms;
  DeleteFragmentPrograms;
  FLightIDs.Free;
  FVertexProgram.Free;
  FFragmentProgram.Free;
  inherited;
end;

procedure TgxBumpShader.Loaded;
begin
  inherited;
end;

function TgxBumpShader.GenerateVertexProgram: string;
var
  VP: TStringList;
  DoTangent, DoSpecular, DoParallaxOffset: Boolean;
  texcoord: Integer;
begin
  DoSpecular := (BumpMethod = bmBasicARBFP) and not (SpecularMode = smOff);
  DoTangent := (BumpSpace = bsTangentExternal) or (BumpSpace =
    bsTangentQuaternion);
  DoParallaxOffset := (BumpMethod = bmBasicARBFP) and (boParallaxMapping in
    BumpOptions) and DoTangent;

  VP := TStringList.Create;

  VP.Add('!!ARBvp1.0');
  VP.Add('OPTION ARB_position_invariant;');

  VP.Add('PARAM mv[4] = { state.matrix.modelview };');
  VP.Add('PARAM mvinv[4] = { state.matrix.modelview.inverse };');
  VP.Add('PARAM mvit[4] = { state.matrix.modelview.invtrans };');
  VP.Add('PARAM tex[4] = { state.matrix.texture[0] };');
  if boUseSecondaryTexCoords in BumpOptions then
    VP.Add('PARAM tex2[4] = { state.matrix.texture[1] };');
  VP.Add('PARAM lightPos = program.local[0];');
  VP.Add('PARAM lightAtten = program.local[1];');
  if BumpSpace = bsTangentExternal then
  begin
    VP.Add('ATTRIB tangent = vertex.texcoord[1];');
    VP.Add('ATTRIB binormal = vertex.texcoord[2];');
    VP.Add('ATTRIB normal = vertex.normal;');
  end;
  VP.Add('TEMP temp, temp2, light, eye, atten;');

  if (boLightAttenuation in BumpOptions) then
  begin

    VP.Add('   DP4 temp.x, mv[0], vertex.position;');
    VP.Add('   DP4 temp.y, mv[1], vertex.position;');
    VP.Add('   DP4 temp.z, mv[2], vertex.position;');
    VP.Add('   ADD light, lightPos, -temp;');

    VP.Add('   DP3 atten.y, light, light;');
    VP.Add('   RSQ atten.y, atten.y;');
    if BumpMethod = bmDot3TexCombiner then
    begin
      VP.Add('   RCP atten.y, atten.y;');
      VP.Add('   MUL atten.z, atten.y, atten.y;');
      VP.Add('   MAD atten.x, lightAtten.y, atten.y, lightAtten.x;');
      VP.Add('   MAD atten.x, lightAtten.z, atten.z, atten.x;');
      VP.Add('   RCP atten.x, atten.x;');
    end
    else if BumpMethod = bmBasicARBFP then
    begin
      // Store the distance in atten.x for ARBFP,
      // fragment program will calculate attenutation
      VP.Add('   RCP atten.x, atten.y;');
    end;

    VP.Add('   DP3 temp.x, mvinv[0], light;');
    VP.Add('   DP3 temp.y, mvinv[1], light;');
    VP.Add('   DP3 temp.z, mvinv[2], light;');
    VP.Add('   MOV light, temp;');
  end
  else
  begin
    VP.Add('   DP4 light.x, mvinv[0], lightPos;');
    VP.Add('   DP4 light.y, mvinv[1], lightPos;');
    VP.Add('   DP4 light.z, mvinv[2], lightPos;');
    VP.Add('   ADD light, light, -vertex.position;');
  end;

  if DoSpecular or DoParallaxOffset then
    VP.Add('   ADD eye, mvit[3], -vertex.position;');

  if DoTangent then
  begin
    if BumpSpace = bsTangentExternal then
    begin

      VP.Add('   DP3 temp.x, light, tangent;');
      VP.Add('   DP3 temp.y, light, binormal;');
      VP.Add('   DP3 temp.z, light, normal;');
      VP.Add('   MOV light, temp;');
      if DoSpecular or DoParallaxOffset then
      begin
        VP.Add('   DP3 temp.x, eye, tangent;');
        VP.Add('   DP3 temp.y, eye, binormal;');
        VP.Add('   DP3 temp.z, eye, normal;');
        VP.Add('   MOV eye, temp;');
      end;

    end
    else if BumpSpace = bsTangentQuaternion then
    begin

      VP.Add('   DP3 temp.x, light, light;');
      VP.Add('   RSQ temp.x, temp.x;');
      VP.Add('   MUL light, temp.x, light;');

      VP.Add('   MOV temp2.x, vertex.normal.y;');
      VP.Add('   ADD temp2.y, 0.0, -vertex.normal.x;');
      VP.Add('   MOV temp2.z, 0.0;');

      VP.Add('   DP3 temp.x, temp2, light;');
      VP.Add('   MUL temp.x, temp2.y, light.z;');
      VP.Add('   MAD temp.y, vertex.normal.z, light.x, temp.x;');
      VP.Add('   MUL temp.x, vertex.normal.y, light.z;');
      VP.Add('   MAD temp.z, vertex.normal.z, light.y, -temp.x;');
      VP.Add('   MUL temp.x, vertex.normal.y, light.y;');
      VP.Add('   MAD temp.x, vertex.normal.z, light.z, temp.x;');
      VP.Add('   MAD temp.w, -temp2.y, light.x, temp.x;');
      VP.Add('   MOV light, temp.yzwy;');

      if DoSpecular or DoParallaxOffset then
      begin
        VP.Add('   DP3 temp.x, temp2, eye;');
        VP.Add('   MUL temp.x, temp2.y, eye.z;');
        VP.Add('   MAD temp.y, vertex.normal.z, eye.x, temp.x;');
        VP.Add('   MUL temp.x, vertex.normal.y, eye.z;');
        VP.Add('   MAD temp.z, vertex.normal.z, eye.y, -temp.x;');
        VP.Add('   MUL temp.x, vertex.normal.y, eye.y;');
        VP.Add('   MAD temp.x, vertex.normal.z, eye.z, temp.x;');
        VP.Add('   MAD temp.w, -temp2.y, eye.x, temp.x;');
        VP.Add('   MOV eye, temp.yzwy;');
      end;

    end;
  end;

  if BumpMethod = bmDot3TexCombiner then
  begin

    if BumpSpace <> bsTangentQuaternion then
    begin
      VP.Add('   DP3 temp.x, light, light;');
      VP.Add('   RSQ temp, temp.x;');
      VP.Add('   MUL light, temp.x, light;');
    end;

    if boLightAttenuation in BumpOptions then
      VP.Add('   MUL light, atten.x, light;');

    VP.Add('   MAD result.color, light, 0.5, 0.5;');
    VP.Add('   MOV result.color.w, 1.0;');

  end
  else if BumpMethod = bmBasicARBFP then
  begin

    if boLightAttenuation in BumpOptions then
      VP.Add('   MOV light.w, atten.x;')
    else
      VP.Add('   MOV light.w, 0.0;');
    if DoSpecular or DoParallaxOffset then
      VP.Add('   MOV eye.w, 0.0;');

  end;

  texcoord := 0;

  VP.Add('   DP4 temp.x, vertex.texcoord[0], tex[0];');
  VP.Add('   DP4 temp.y, vertex.texcoord[0], tex[1];');
  VP.Add('   DP4 temp.z, vertex.texcoord[0], tex[2];');
  VP.Add('   DP4 temp.w, vertex.texcoord[0], tex[3];');
  VP.Add('   MOV result.texcoord[' + IntToStr(texcoord) + '], temp;');
  Inc(texcoord);

  if boUseSecondaryTexCoords in BumpOptions then
  begin
    VP.Add('   DP4 temp.x, vertex.texcoord[1], tex2[0];');
    VP.Add('   DP4 temp.y, vertex.texcoord[1], tex2[1];');
    VP.Add('   DP4 temp.z, vertex.texcoord[1], tex2[2];');
    VP.Add('   DP4 temp.w, vertex.texcoord[1], tex2[3];');
    VP.Add('   MOV result.texcoord[' + IntToStr(texcoord) + '], temp;');
    Inc(texcoord);
  end;

  if BumpMethod = bmDot3TexCombiner then
  begin
    if (boDiffuseTexture2 in BumpOptions)
      and not (boUseSecondaryTexCoords in BumpOptions) then
      VP.Add('   MOV result.texcoord[' + IntToStr(texcoord) + '], temp;');
  end
  else
  begin
    VP.Add('   MOV result.texcoord[' + IntToStr(texcoord) + '], light;');
    Inc(texcoord);
    if DoSpecular then
      VP.Add('   MOV result.texcoord[' + IntToStr(texcoord) + '], eye;');
  end;

  VP.Add('END');

  FVertexProgram.Assign(VP);
  Result := VP.Text;
  VP.Free;
end;

function TgxBumpShader.GenerateFragmentProgram: string;
var
  FP: TStringList;
  DoSpecular,
    DoTangent,
    DoParallaxOffset: Boolean;
  texcoord,
    normalTexCoords,
    diffTexCoords,
    specTexCoords,
    lightTexCoords,
    eyeTexCoords: Integer;
begin
  DoSpecular := not (SpecularMode = smOff);
  DoTangent := (BumpSpace = bsTangentExternal) or (BumpSpace =
    bsTangentQuaternion);
  DoParallaxOffset := (boParallaxMapping in BumpOptions) and DoTangent;

  texcoord := 0;
  normalTexCoords := texcoord;
  if boUseSecondaryTexCoords in BumpOptions then
    Inc(texcoord);
  diffTexCoords := texcoord;
  specTexCoords := texcoord;
  Inc(texcoord);
  lightTexCoords := texcoord;
  Inc(texcoord);
  eyeTexCoords := texcoord;

  FP := TStringList.Create;

  FP.Add('!!ARBfp1.0');

  FP.Add('PARAM lightDiffuse = program.local[0];');
  FP.Add('PARAM lightSpecular = program.local[1];');
  FP.Add('PARAM lightAtten = program.local[2];');
  FP.Add('PARAM materialDiffuse = state.material.diffuse;');
  FP.Add('PARAM materialSpecular = state.material.specular;');
  FP.Add('PARAM shininess = state.material.shininess;');
  FP.Add('TEMP temp, tex, light, eye, normal, col, diff, spec;');
  FP.Add('TEMP textureColor, reflect, atten, offset, texcoord;');

  if DoSpecular or DoParallaxOffset then
  begin
    // Get the eye vector
    FP.Add('   DP3 eye, fragment.texcoord[' + IntToStr(eyeTexCoords) +
      '], fragment.texcoord[' + IntToStr(eyeTexCoords) + '];');
    FP.Add('   RSQ eye, eye.x;');
    FP.Add('   MUL eye, fragment.texcoord[' + IntToStr(eyeTexCoords) +
      '], eye.x;');
  end;

  if DoParallaxOffset then
  begin
    // Get the parallax offset
    FP.Add('   TEX textureColor, fragment.texcoord[' + IntToStr(normalTexCoords)
      + '], texture[0], 2D;');
    FP.Add(Format('   MAD offset.x, textureColor.a, %f, %f;', [FParallaxOffset,
      -0.5 * FParallaxOffset]));
    FP.Add('   MUL offset, eye, offset.x;');
    FP.Add('   ADD texcoord, fragment.texcoord[' + IntToStr(normalTexCoords) +
      '], offset;');
  end
  else
    FP.Add('   MOV texcoord, fragment.texcoord[' + IntToStr(normalTexCoords) +
      '];');

  // Get the normalized normal vector
  FP.Add('   TEX textureColor, texcoord, texture[0], 2D;');
  FP.Add('   ADD normal, textureColor, -0.5;');
  FP.Add('   DP3 temp, normal, normal;');
  FP.Add('   RSQ temp, temp.x;');
  FP.Add('   MUL normal, normal, temp.x;');

  // Get the normalized light vector
  FP.Add('   MOV light, fragment.texcoord[' + IntToStr(lightTexCoords) + '];');
  if boLightAttenuation in BumpOptions then
    FP.Add('   MOV atten.x, light.w;');
  FP.Add('   DP3 light, light, light;');
  FP.Add('   RSQ light, light.x;');
  FP.Add('   MUL light, fragment.texcoord[' + IntToStr(lightTexCoords) +
    '], light.x;');

  // Calculate the diffuse color
  FP.Add('   DP3 diff, normal, light;');
  FP.Add('   MUL diff, diff, lightDiffuse;');
  FP.Add('   MUL diff, diff, materialDiffuse;');
  if boDiffuseTexture2 in BumpOptions then
  begin
    if DoParallaxOffset then
    begin
      FP.Add('   ADD temp, fragment.texcoord[' + IntToStr(diffTexCoords) +
        '], offset;');
      FP.Add('   TEX textureColor, temp, texture[1], 2D;');
    end
    else
      FP.Add('   TEX textureColor, fragment.texcoord[' + IntToStr(diffTexCoords)
        + '], texture[1], 2D;');
    FP.Add('   MUL diff, diff, textureColor;');
  end;

  if DoSpecular then
  begin
    case SpecularMode of
      smBlinn:
        begin
          FP.Add('   ADD eye, eye, light;');
          FP.Add('   DP3 temp, eye, eye;');
          FP.Add('   RSQ temp, temp.x;');
          FP.Add('   MUL eye, eye, temp.x;');
          FP.Add('   DP3_SAT spec, normal, eye;');
        end;
      smPhong:
        begin
          FP.Add('   DP3 reflect, normal, light;');
          FP.Add('   MUL reflect, reflect.x, normal;');
          FP.Add('   MUL reflect, 2.0, reflect;');
          FP.Add('   ADD reflect, reflect, -light;');
          FP.Add('   DP3_SAT spec, reflect, eye;');
        end;
    else
      Assert(False, 'Invalid specular mode!');
    end;

    FP.Add('   POW spec, spec.x, shininess.x;');
    FP.Add('   MUL spec, spec, materialSpecular;');
    FP.Add('   MUL spec, spec, lightSpecular;');
    if boSpecularTexture3 in BumpOptions then
    begin
      if DoParallaxOffset then
      begin
        FP.Add('   ADD temp, fragment.texcoord[' + IntToStr(specTexCoords) +
          '], offset;');
        FP.Add('   TEX textureColor, temp, texture[2], 2D;');
      end
      else
        FP.Add('   TEX textureColor, fragment.texcoord[' +
          IntToStr(specTexCoords) + '], texture[2], 2D;');
      FP.Add('   MUL spec, spec, textureColor;');
    end;
  end;

  // Output
  if DoSpecular then
    FP.Add('   ADD temp, diff, spec;')
  else
    FP.Add('   MOV temp, diff;');

  if boLightAttenuation in BumpOptions then
  begin
    FP.Add('   MUL atten.y, atten.x, atten.x;');
    FP.Add('   MAD atten.x, lightAtten.y, atten.x, lightAtten.x;');
    FP.Add('   MAD atten.x, lightAtten.z, atten.y, atten.x;');
    FP.Add('   RCP atten.x, atten.x;');
    FP.Add('   MUL temp, temp, atten.x;');
  end;

  FP.Add('   MOV_SAT result.color, temp;');
  FP.Add('   MOV result.color.w, 1.0;');

  FP.Add('END');

  FFragmentProgram.Assign(FP);
  Result := FP.Text;
  FP.Free;
end;

procedure TgxBumpShader.DoLightPass(var rci: TgxRenderContextInfo;
  lightID: Cardinal);
var
  dummyHandle, tempHandle: Integer;
  lightPos, lightAtten,
    materialDiffuse, lightDiffuse, lightSpecular: TVector4f;
begin
  FVertexProgramHandle.Enable;
  FVertexProgramHandle.Bind;

  // Set the light position to program.local[0]
  glGetLightfv(GL_LIGHT0 + FLightIDs[0], GL_POSITION, @lightPos.X);
  glProgramLocalParameter4fvARB(GL_VERTEX_PROGRAM_ARB, 0, @lightPos.X);

  // Set the light attenutation to program.local[1]
  lightAtten.X := rci.gxStates.LightConstantAtten[FLightIDs[0]];
  lightAtten.Y := rci.gxStates.LightLinearAtten[FLightIDs[0]];
  lightAtten.Z := rci.gxStates.LightQuadraticAtten[FLightIDs[0]];
  glProgramLocalParameter4fvARB(GL_VERTEX_PROGRAM_ARB, 1, @lightAtten.X);

  case FBumpMethod of
    bmDot3TexCombiner:
      begin
        rci.gxStates.ActiveTexture := 0;
        dummyHandle := rci.gxStates.TextureBinding[0, ttTexture2D];
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
        glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, GL_DOT3_RGB_ARB);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, GL_TEXTURE0_ARB);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, GL_PRIMARY_COLOR_ARB);

        rci.gxStates.ActiveTexture := 1;
        rci.gxStates.ActiveTextureEnabled[ttTexture2D] := True;
        tempHandle := rci.gxStates.TextureBinding[1, ttTexture2D];
        if tempHandle = 0 then
          rci.gxStates.TextureBinding[1, ttTexture2D] := dummyHandle;
        lightDiffuse := rci.gxStates.LightDiffuse[FLightIDs[0]];
        glGetMaterialfv(GL_FRONT, GL_DIFFUSE, @materialDiffuse);
        lightDiffuse.X := lightDiffuse.X * materialDiffuse.X;
        lightDiffuse.Y := lightDiffuse.Y * materialDiffuse.Y;
        lightDiffuse.Z := lightDiffuse.Z * materialDiffuse.Z;
        lightDiffuse.W := lightDiffuse.W * materialDiffuse.W;
        glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, @lightDiffuse);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
        glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, GL_MODULATE);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, GL_PREVIOUS_ARB);
        glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, GL_CONSTANT_COLOR_EXT);

        with rci.gxStates do
        begin
          ActiveTexture := 2;
          ActiveTextureEnabled[ttTexture2D] := False;
          ActiveTexture := 0;
        end;
      end;

    bmBasicARBFP:
      begin
        FFragmentProgramHandle.Enable;
        FFragmentProgramHandle.Bind;
        lightDiffuse := rci.gxStates.LightDiffuse[FLightIDs[0]];
        lightSpecular := rci.gxStates.LightSpecular[FLightIDs[0]];
        lightAtten.X := rci.gxStates.LightConstantAtten[FLightIDs[0]];

        glProgramLocalParameter4fvARB(GL_FRAGMENT_PROGRAM_ARB, 0,
          @lightDiffuse.X);
        glProgramLocalParameter4fvARB(GL_FRAGMENT_PROGRAM_ARB, 1,
          @lightSpecular.X);
        glProgramLocalParameter4fvARB(GL_FRAGMENT_PROGRAM_ARB, 2,
          @lightAtten.X);
      end;

  else
    Assert(False, 'Invalid bump method!');
  end;
end;

procedure TgxBumpShader.DoApply(var rci: TgxRenderContextInfo; Sender: TObject);
var
  maxTextures, i: Integer;
  ambient, LMaterialAmbient: TgxColorVector;
  success: Boolean;
begin
  if (csDesigning in ComponentState) and not DesignTimeEnabled then
    exit;
  if not Enabled then
    exit;

  glGetIntegerv(GL_MAX_TEXTURE_UNITS_ARB, @maxTextures);

  success := False;
  try
    /// if not GL_ARB_multitexture then raise Exception.Create('This shader requires GL_ARB_multitexture.');
    if (maxTextures < 3)
      and ((BumpMethod <> bmDot3TexCombiner) or (BumpSpace = bsTangentExternal)) then
      raise
        Exception.Create('The current shader settings require 3 or more texture units.');
    if (maxTextures < 4)
      and (BumpMethod <> bmDot3TexCombiner)
      and (boUseSecondaryTexCoords in BumpOptions)
      and (SpecularMode <> smOff) then
      raise
        Exception.Create('The current shader settings require 4 or more texture units.');

    if not Assigned(FVertexProgramHandle) then
    begin
      FVertexProgramHandle := TgxVertexProgramHandle.CreateAndAllocate;
      FVertexProgramHandle.LoadARBProgram(GenerateVertexProgram);
    end;

    if not Assigned(FFragmentProgramHandle) then
      if FBumpMethod = bmBasicARBFP then
      begin
        FFragmentProgramHandle := TgxFragmentProgramHandle.CreateAndAllocate;
        FFragmentProgramHandle.LoadARBProgram(GenerateFragmentProgram);
      end;

    success := True;

  finally
    if not success then
    begin
      Enabled := False;
      DesignTimeEnabled := False;
    end;
  end;

  FLightIDs.Clear;
  rci.gxStates.ActiveTexture := 0;
  if rci.gxStates.ActiveTextureEnabled[ttTexture2D] then
    for i := 0 to rci.gxStates.MaxLights - 1 do
    begin
      if rci.gxStates.LightEnabling[i] then
        FLightIDs.Add(i);
    end;
  FLightsEnabled := FLightIDs.Count;

  FAmbientPass := False;
  FDiffusePass := False;

  if FLightIDs.Count > 0 then
  begin

    rci.gxStates.DepthFunc := cfLEqual;
    rci.gxStates.Disable(stBlend);
    DoLightPass(rci, FLightIDs[0]);
    FLightIDs.Delete(0);

  end
  else
    with rci.gxStates do
    begin
      Disable(stLighting);
      ActiveTexture := 0;
      ActiveTextureEnabled[ttTexture2D] := False;
      ActiveTexture := 1;
      ActiveTextureEnabled[ttTexture2D] := False;
      ActiveTexture := 2;
      ActiveTextureEnabled[ttTexture2D] := False;
      ActiveTexture := 0;

      glGetFloatv(GL_LIGHT_MODEL_AMBIENT, @ambient);
      glGetMaterialfv(GL_FRONT, GL_AMBIENT, @LMaterialAmbient);
      ambient.X := ambient.X * LMaterialAmbient.X;
      ambient.Y := ambient.Y * LMaterialAmbient.Y;
      ambient.Z := ambient.Z * LMaterialAmbient.Z;
      glColor3fv(@ambient);

      FAmbientPass := True;

    end;
end;

function TgxBumpShader.DoUnApply(var rci: TgxRenderContextInfo): Boolean;
var
  ambient, LMaterialAmbient: TVector4f;
begin
  Result := False;
  if (csDesigning in ComponentState) and not DesignTimeEnabled then
    exit;
  if not Enabled then
    exit;

  if FLightIDs.Count > 0 then
    with rci.gxStates do
    begin

      DepthFunc := cfLEqual;
      Enable(stBlend);
      SetBlendFunc(bfOne, bfOne);

      DoLightPass(rci, FLightIDs[0]);
      FLightIDs.Delete(0);
      Result := True;
      Exit;

    end
  else if not FDiffusePass and (FLightsEnabled <> 0)
    and (boDiffuseTexture2 in BumpOptions)
    and (BumpMethod = bmDot3TexCombiner) then
    with rci.gxStates do
    begin

      Enable(stBlend);
      SetBlendFunc(bfDstColor, bfZero);

      ActiveTexture := 0;
      ActiveTextureEnabled[ttTexture2D] := False;
      ActiveTexture := 1;
      ActiveTextureEnabled[ttTexture2D] := True;
      glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
      ActiveTexture := 2;
      ActiveTextureEnabled[ttTexture2D] := False;
      ActiveTexture := 0;

      FDiffusePass := True;
      Result := True;
      Exit;

    end
  else if not FAmbientPass then
    with rci.gxStates do
    begin

      FVertexProgramHandle.Disable;
      if BumpMethod = bmBasicARBFP then
        FFragmentProgramHandle.Disable;

      Disable(stLighting);
      ActiveTexture := 0;
      ActiveTextureEnabled[ttTexture2D] := False;
      ActiveTexture := 1;
      ActiveTextureEnabled[ttTexture2D] := False;
      ActiveTexture := 2;
      ActiveTextureEnabled[ttTexture2D] := False;
      ActiveTexture := 0;

      DepthFunc := cfLEqual;
      Enable(stBlend);
      SetBlendFunc(bfOne, bfOne);

      glGetFloatv(GL_LIGHT_MODEL_AMBIENT, @ambient);
      glGetMaterialfv(GL_FRONT, GL_AMBIENT, @LMaterialAmbient);
      ambient.X := ambient.X * LMaterialAmbient.X;
      ambient.Y := ambient.Y * LMaterialAmbient.Y;
      ambient.Z := ambient.Z * LMaterialAmbient.Z;
      glColor3fv(@ambient);

      FAmbientPass := True;
      Result := True;
      Exit;

    end;

  FVertexProgramHandle.Disable;
  if BumpMethod = bmBasicARBFP then
    FFragmentProgramHandle.Disable;
end;

procedure TgxBumpShader.DeleteVertexPrograms;
begin
  FVertexProgramHandle.Free;
  FVertexProgramHandle := nil;
  FVertexProgram.Clear;
end;

procedure TgxBumpShader.DeleteFragmentPrograms;
begin
  FFragmentProgramHandle.Free;
  FFragmentProgramHandle := nil;
  FFragmentProgram.Clear;
end;

procedure TgxBumpShader.SetBumpMethod(const Value: TBumpMethod);
begin
  if Value <> FBumpMethod then
  begin
    FBumpMethod := Value;
    DeleteVertexPrograms;
    DeleteFragmentPrograms;
    NotifyChange(Self);
  end;
end;

procedure TgxBumpShader.SetBumpSpace(const Value: TBumpSpace);
begin
  if Value <> FBumpSpace then
  begin
    FBumpSpace := Value;
    DeleteVertexPrograms;
    DeleteFragmentPrograms;
    NotifyChange(Self);
  end;
end;

procedure TgxBumpShader.SetBumpOptions(const Value: TBumpOptions);
begin
  if Value <> FBumpOptions then
  begin
    FBumpOptions := Value;
    DeleteVertexPrograms;
    DeleteFragmentPrograms;
    NotifyChange(Self);
  end;
end;

procedure TgxBumpShader.SetSpecularMode(const Value: TSpecularMode);
begin
  if Value <> FSpecularMode then
  begin
    FSpecularMode := Value;
    DeleteVertexPrograms;
    DeleteFragmentPrograms;
    NotifyChange(Self);
  end;
end;

procedure TgxBumpShader.SetDesignTimeEnabled(const Value: Boolean);
begin
  if Value <> FDesignTimeEnabled then
  begin
    FDesignTimeEnabled := Value;
    NotifyChange(Self);
  end;
end;

procedure TgxBumpShader.SetParallaxOffset(const Value: Single);
begin
  if Value <> FParallaxOffset then
  begin
    FParallaxOffset := Value;
    DeleteVertexPrograms;
    DeleteFragmentPrograms;
    NotifyChange(Self);
  end;
end;


initialization
  RegisterClasses([TgxslBumpShaderMT, TgxslBumpShader, TgxslBumpShaderAM,
                   TgxslMLBumpShader, TgxslMLBumpShaderMT]);

end.


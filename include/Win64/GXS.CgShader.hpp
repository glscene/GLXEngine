// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.CgShader.pas' rev: 36.00 (Windows)

#ifndef GXS_CgShaderHPP
#define GXS_CgShaderHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.OpenGL.hpp>
#include <Winapi.OpenGLext.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.VectorLists.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.Texture.hpp>
#include <Stage.Strings.hpp>
#include <GXS.Cadencer.hpp>
#include <GXS.Context.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <Stage.TextureFormat.hpp>
#include <Cg.Import.hpp>
#include <Cg.GL.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Cgshader
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS ECGxShaderException;
class DELPHICLASS TCGxProgram;
class DELPHICLASS TCGxParameter;
class DELPHICLASS TCGxVertexProgram;
class DELPHICLASS TCGxFragmentProgram;
class DELPHICLASS TCGxCustomShader;
class DELPHICLASS TCGxCadencableCustomShader;
class DELPHICLASS TCGxShader;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION ECGxShaderException : public Gxs::Texture::EShaderException
{
	typedef Gxs::Texture::EShaderException inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECGxShaderException(const System::UnicodeString Msg) : Gxs::Texture::EShaderException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECGxShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Gxs::Texture::EShaderException(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ECGxShaderException(System::NativeUInt Ident)/* overload */ : Gxs::Texture::EShaderException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ECGxShaderException(System::PResStringRec ResStringRec)/* overload */ : Gxs::Texture::EShaderException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ECGxShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxs::Texture::EShaderException(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ECGxShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Gxs::Texture::EShaderException(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ECGxShaderException(const System::UnicodeString Msg, int AHelpContext) : Gxs::Texture::EShaderException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECGxShaderException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Gxs::Texture::EShaderException(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECGxShaderException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Gxs::Texture::EShaderException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECGxShaderException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Gxs::Texture::EShaderException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECGxShaderException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxs::Texture::EShaderException(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECGxShaderException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Gxs::Texture::EShaderException(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECGxShaderException() { }
	
};


typedef void __fastcall (__closure *TCGxApplyEvent)(TCGxProgram* CgProgram, System::TObject* Sender);

typedef void __fastcall (__closure *TCgUnApplyEvent)(TCGxProgram* CgProgram);

typedef void __fastcall (__closure *TCGxShaderEvent)(TCGxCustomShader* CgShader);

enum DECLSPEC_DENUM TCGxProgramType : unsigned char { ptVertex, ptFragment };

enum DECLSPEC_DENUM TCgVPProfile : unsigned char { vpDetectLatest, vp20, vp30, vp40, arbvp1 };

enum DECLSPEC_DENUM TCgFPProfile : unsigned char { fpDetectLatest, fp20, fp30, fp40, arbfp1 };

enum DECLSPEC_DENUM TPrecisionSetting : unsigned char { psFull, psFast };

class PASCALIMPLEMENTATION TCGxProgram : public Gxs::Baseclasses::TgxUpdateAbleObject
{
	typedef Gxs::Baseclasses::TgxUpdateAbleObject inherited;
	
private:
	Cg::Import::PCGcontext FCgContext;
	System::Classes::TStrings* FCode;
	System::UnicodeString FProgramName;
	Cg::Import::PCGprogram FHandle;
	System::Classes::TList* FParams;
	TCGxApplyEvent FOnApply;
	TCgUnApplyEvent FOnUnApply;
	System::Classes::TNotifyEvent FOnProgramChanged;
	bool FEnabled;
	bool FDetectProfile;
	TPrecisionSetting FPrecision;
	void __fastcall SetPrecision(const TPrecisionSetting Value);
	bool __fastcall GetManualNotification();
	void __fastcall SetManualNotification(const bool Value);
	
protected:
	TCGxProgramType FProgramType;
	Cg::Import::TCGprofile FProfile;
	void __fastcall SetCode(System::Classes::TStrings* const val);
	void __fastcall SetProgramName(const System::UnicodeString val);
	TCGxParameter* __fastcall GetParam(System::UnicodeString index);
	void __fastcall AddParamsItem(const Cg::Import::PCGparameter Param);
	void __fastcall BuildParamsList();
	void __fastcall ClearParamsList();
	
public:
	__fastcall virtual TCGxProgram(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TCGxProgram();
	virtual Cg::Import::TCGprofile __fastcall GetLatestProfile() = 0 ;
	virtual void __fastcall Initialize();
	void __fastcall Finalize();
	void __fastcall Apply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	void __fastcall UnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	TCGxParameter* __fastcall ParamByName(const System::UnicodeString name);
	__property TCGxParameter* Param[System::UnicodeString index] = {read=GetParam};
	__property System::Classes::TList* Params = {read=FParams};
	Cg::Import::PCGparameter __fastcall DirectParamByName(const System::UnicodeString name);
	int __fastcall ParamCount();
	System::UnicodeString __fastcall GetProfileStringA();
	void __fastcall LoadFromFile(const System::UnicodeString fileName);
	void __fastcall ListCompilation(System::Classes::TStrings* Output);
	void __fastcall ListParameters(System::Classes::TStrings* Output);
	void __fastcall SetParam(System::UnicodeString ParamName, float SingleVal)/* overload */;
	void __fastcall SetParam(System::UnicodeString ParamName, const Stage::Vectortypes::TVector2f &Vector2fVal)/* overload */;
	void __fastcall SetParam(System::UnicodeString ParamName, const Stage::Vectortypes::TVector3f &Vector3fVal)/* overload */;
	void __fastcall SetParam(System::UnicodeString ParamName, const Stage::Vectortypes::TVector4f &Vector4fVal)/* overload */;
	void __fastcall SetStateMatrix(System::UnicodeString ParamName, unsigned matrix, unsigned Transform);
	void __fastcall SetTexture(System::UnicodeString ParamName, unsigned TextureID);
	System::UnicodeString __fastcall LongName();
	__property Cg::Import::TCGprofile DirectProfile = {read=FProfile, write=FProfile, nodefault};
	__property System::Classes::TNotifyEvent OnProgramChanged = {read=FOnProgramChanged, write=FOnProgramChanged};
	__property bool ManualNotification = {read=GetManualNotification, write=SetManualNotification, default=0};
	
__published:
	__property System::Classes::TStrings* Code = {read=FCode, write=SetCode};
	__property System::UnicodeString ProgramName = {read=FProgramName, write=SetProgramName};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property TPrecisionSetting Precision = {read=FPrecision, write=SetPrecision, default=0};
	__property TCGxApplyEvent OnApply = {read=FOnApply, write=FOnApply};
	__property TCgUnApplyEvent OnUnApply = {read=FOnUnApply, write=FOnUnApply};
};


class PASCALIMPLEMENTATION TCGxParameter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TCGxProgram* FOwner;
	System::UnicodeString FName;
	Cg::Import::PCGparameter FHandle;
	Cg::Import::TCGtype FValueType;
	Cg::Import::TCGenum FDirection;
	Cg::Import::TCGenum FVariability;
	
protected:
	System::UnicodeString __fastcall TypeMismatchMessage();
	void __fastcall CheckValueType(Cg::Import::TCGtype aType)/* overload */;
	void __fastcall CheckValueType(const Cg::Import::TCGtype *types, const System::NativeInt types_High)/* overload */;
	void __fastcall CheckAllTextureTypes();
	void __fastcall CheckAllScalarTypes();
	void __fastcall CheckAllVector2fTypes();
	void __fastcall CheckAllVector3fTypes();
	void __fastcall CheckAllVector4fTypes();
	void __fastcall SetAsVector2f(const Stage::Vectortypes::TVector2f &val);
	void __fastcall SetAsVector3f(const Stage::Vectortypes::TVector3f &val);
	void __fastcall SetAsVector4f(const Stage::Vectortypes::TVector4f &val);
	
public:
	__fastcall virtual TCGxParameter();
	__fastcall virtual ~TCGxParameter();
	void __fastcall SetAsScalar(const float val)/* overload */;
	void __fastcall SetAsScalar(const bool val)/* overload */;
	void __fastcall SetAsVector(const Stage::Vectortypes::TVector2f &val)/* overload */;
	void __fastcall SetAsVector(const Stage::Vectortypes::TVector3f &val)/* overload */;
	void __fastcall SetAsVector(const Stage::Vectortypes::TVector4f &val)/* overload */;
	void __fastcall SetAsVector(const float *val, const System::NativeInt val_High)/* overload */;
	void __fastcall SetAsStateMatrix(unsigned matrix, unsigned Transform);
	void __fastcall SetAsMatrix(const Stage::Vectortypes::TMatrix4f &val);
	void __fastcall SetAsTexture(unsigned TextureID);
	void __fastcall SetAsTexture1D(unsigned TextureID);
	void __fastcall SetAsTexture2D(unsigned TextureID);
	void __fastcall SetAsTexture3D(unsigned TextureID);
	void __fastcall SetAsTextureCUBE(unsigned TextureID);
	void __fastcall SetAsTextureRECT(unsigned TextureID);
	void __fastcall SetToTextureOf(Gxs::Material::TgxLibMaterial* LibMaterial);
	void __fastcall EnableTexture();
	void __fastcall DisableTexture();
	void __fastcall SetParameterPointer(Gxs::Vectorlists::TgxVectorList* Values)/* overload */;
	void __fastcall SetParameterPointer(Gxs::Vectorlists::TgxAffineVectorList* Values)/* overload */;
	void __fastcall EnableClientState();
	void __fastcall DisableClientState();
	System::UnicodeString __fastcall LongName();
	__property TCGxProgram* Owner = {read=FOwner};
	__property System::UnicodeString Name = {read=FName};
	__property Cg::Import::TCGtype ValueType = {read=FValueType, nodefault};
	__property Cg::Import::PCGparameter Handle = {read=FHandle, write=FHandle};
	__property Cg::Import::TCGenum Direction = {read=FDirection, write=FDirection, nodefault};
	__property Cg::Import::TCGenum Variability = {read=FVariability, write=FVariability, nodefault};
	__property Stage::Vectortypes::TVector4f AsVector = {write=SetAsVector4f};
	__property Stage::Vectorgeometry::TAffineVector AsAffineVector = {write=SetAsVector3f};
	__property Stage::Vectortypes::TVector2f AsVector2f = {write=SetAsVector2f};
};


class PASCALIMPLEMENTATION TCGxVertexProgram : public TCGxProgram
{
	typedef TCGxProgram inherited;
	
private:
	TCgVPProfile FVPProfile;
	void __fastcall SetVPProfile(TCgVPProfile v);
	
public:
	__fastcall virtual TCGxVertexProgram(System::Classes::TPersistent* AOwner);
	virtual Cg::Import::TCGprofile __fastcall GetLatestProfile();
	
__published:
	__property TCgVPProfile Profile = {read=FVPProfile, write=SetVPProfile, default=0};
public:
	/* TCGxProgram.Destroy */ inline __fastcall virtual ~TCGxVertexProgram() { }
	
};


class PASCALIMPLEMENTATION TCGxFragmentProgram : public TCGxProgram
{
	typedef TCGxProgram inherited;
	
private:
	TCgFPProfile FFPProfile;
	bool FManageTexture;
	void __fastcall SetFPProfile(TCgFPProfile v);
	void __fastcall SetManageTexture(const bool Value);
	
public:
	__fastcall virtual TCGxFragmentProgram(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Initialize();
	virtual Cg::Import::TCGprofile __fastcall GetLatestProfile();
	
__published:
	__property TCgFPProfile Profile = {read=FFPProfile, write=SetFPProfile, default=0};
	__property bool ManageTexture = {read=FManageTexture, write=SetManageTexture, default=0};
public:
	/* TCGxProgram.Destroy */ inline __fastcall virtual ~TCGxFragmentProgram() { }
	
};


class PASCALIMPLEMENTATION TCGxCustomShader : public Gxs::Material::TgxShader
{
	typedef Gxs::Material::TgxShader inherited;
	
private:
	TCGxVertexProgram* FVertexProgram;
	TCGxFragmentProgram* FFragmentProgram;
	TCGxShaderEvent FOnInitialize;
	bool FDesignEnable;
	
protected:
	void __fastcall SetVertexProgram(TCGxVertexProgram* const val);
	void __fastcall SetOnApplyVertexProgram(const TCGxApplyEvent val);
	TCGxApplyEvent __fastcall GetOnApplyVertexProgram();
	void __fastcall SetOnUnApplyVertexProgram(const TCgUnApplyEvent val);
	TCgUnApplyEvent __fastcall GetOnUnApplyVertexProgram();
	void __fastcall SetFragmentProgram(TCGxFragmentProgram* const val);
	void __fastcall SetOnApplyFragmentProgram(const TCGxApplyEvent val);
	TCGxApplyEvent __fastcall GetOnApplyFragmentProgram();
	void __fastcall SetOnUnApplyFragmentProgram(const TCgUnApplyEvent val);
	TCgUnApplyEvent __fastcall GetOnUnApplyFragmentProgram();
	TCGxShaderEvent __fastcall GetOnInitialize();
	void __fastcall SetOnInitialize(const TCGxShaderEvent val);
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall DoFinalize();
	virtual void __fastcall DoApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual bool __fastcall DoUnApply(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci);
	bool __fastcall IsProfileSupported(Cg::Import::TCGprofile Profile);
	__property TCGxApplyEvent OnApplyVP = {read=GetOnApplyVertexProgram, write=SetOnApplyVertexProgram};
	__property TCGxApplyEvent OnApplyFP = {read=GetOnApplyFragmentProgram, write=SetOnApplyFragmentProgram};
	__property TCgUnApplyEvent OnUnApplyVP = {read=GetOnUnApplyVertexProgram, write=SetOnUnApplyVertexProgram};
	__property TCgUnApplyEvent OnUnApplyFP = {read=GetOnUnApplyFragmentProgram, write=SetOnUnApplyFragmentProgram};
	__property TCGxShaderEvent OnInitialize = {read=GetOnInitialize, write=SetOnInitialize};
	__property bool DesignEnable = {read=FDesignEnable, write=FDesignEnable, default=0};
	__property TCGxVertexProgram* VertexProgram = {read=FVertexProgram, write=SetVertexProgram};
	__property TCGxFragmentProgram* FragmentProgram = {read=FFragmentProgram, write=SetFragmentProgram};
	
public:
	__fastcall virtual TCGxCustomShader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCGxCustomShader();
	void __fastcall LoadShaderPrograms(const System::UnicodeString VPFilename, const System::UnicodeString FPFilename);
	virtual bool __fastcall ShaderSupported();
};


class PASCALIMPLEMENTATION TCGxCadencableCustomShader : public TCGxCustomShader
{
	typedef TCGxCustomShader inherited;
	
private:
	Gxs::Cadencer::TgxCadencer* FCadencer;
	void __fastcall SetCadencer(Gxs::Cadencer::TgxCadencer* const Value);
	
protected:
	virtual void __fastcall DoInitialize(Gxs::Rendercontextinfo::TgxRenderContextInfo &rci, System::TObject* Sender);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__property Gxs::Cadencer::TgxCadencer* Cadencer = {read=FCadencer, write=SetCadencer};
public:
	/* TCGxCustomShader.Create */ inline __fastcall virtual TCGxCadencableCustomShader(System::Classes::TComponent* AOwner) : TCGxCustomShader(AOwner) { }
	/* TCGxCustomShader.Destroy */ inline __fastcall virtual ~TCGxCadencableCustomShader() { }
	
};


class PASCALIMPLEMENTATION TCGxShader : public TCGxCustomShader
{
	typedef TCGxCustomShader inherited;
	
__published:
	__property DesignEnable = {default=0};
	__property ShaderStyle = {default=1};
	__property FailedInitAction = {default=1};
	__property VertexProgram;
	__property FragmentProgram;
	__property OnApplyVP;
	__property OnApplyFP;
	__property OnUnApplyVP;
	__property OnUnApplyFP;
	__property OnInitialize;
public:
	/* TCGxCustomShader.Create */ inline __fastcall virtual TCGxShader(System::Classes::TComponent* AOwner) : TCGxCustomShader(AOwner) { }
	/* TCGxCustomShader.Destroy */ inline __fastcall virtual ~TCGxShader() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::UnicodeString IncludeFilePath;
extern DELPHI_PACKAGE bool __fastcall IsCgProfileSupported(Cg::Import::TCGprofile Profile);
}	/* namespace Cgshader */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CGSHADER)
using namespace Gxs::Cgshader;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CgShaderHPP

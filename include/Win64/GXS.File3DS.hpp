// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.File3DS.pas' rev: 36.00 (Windows)

#ifndef GXS_File3DSHPP
#define GXS_File3DSHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <Stage.Strings.hpp>
#include <Stage.OpenGL4.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Objects.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.Texture.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GXS.Context.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.File3DSSceneObjects.hpp>
#include <Stage.VectorTypes.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Material.hpp>
#include <Formatx.m3DS.hpp>
#include <Formatx.m3DSTypes.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace File3ds
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EGLFile3DS;
struct TgxFile3DSAnimationData;
class DELPHICLASS TgxFile3DSAnimationKeys;
class DELPHICLASS TgxFile3DSScaleAnimationKeys;
class DELPHICLASS TgxFile3DSRotationAnimationKeys;
class DELPHICLASS TgxFile3DSPositionAnimationKeys;
class DELPHICLASS TgxFile3DSColorAnimationKeys;
class DELPHICLASS TTgxFile3DSPositionAnimationKeys;
class DELPHICLASS TgxFile3DSSpotLightCutOffAnimationKeys;
class DELPHICLASS TgxFile3DSLightHotSpotAnimationKeys;
class DELPHICLASS TgxFile3DSRollAnimationKeys;
class DELPHICLASS TgxFile3DSAnimationKeyList;
class DELPHICLASS TgxFile3DSDummyObject;
class DELPHICLASS TgxFile3DSMeshObject;
class DELPHICLASS TgxFile3DSOmniLightObject;
class DELPHICLASS TgxFile3DSSpotLightObject;
class DELPHICLASS TgxFile3DSCameraObject;
class DELPHICLASS Tgx3DSVectorFile;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION EGLFile3DS : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EGLFile3DS(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EGLFile3DS(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EGLFile3DS(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EGLFile3DS(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLFile3DS(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EGLFile3DS(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EGLFile3DS(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EGLFile3DS(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLFile3DS(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EGLFile3DS(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLFile3DS(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EGLFile3DS(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EGLFile3DS() { }
	
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TgxFile3DSAnimationData
{
public:
	Stage::Vectortypes::TMatrix4f ModelMatrix;
	Stage::Vectortypes::TVector4f Color;
	Stage::Vectorgeometry::TAffineVector TargetPos;
	float SpotLightCutOff;
	float HotSpot;
	float Roll;
};
#pragma pack(pop)


class PASCALIMPLEMENTATION TgxFile3DSAnimationKeys : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
	
private:
	typedef System::DynamicArray<Formatx::M3dstypes::TKeyHeader3DS> _TgxFile3DSAnimationKeys__1;
	
	
private:
	int FNumKeys;
	_TgxFile3DSAnimationKeys__1 FKeys;
	void __fastcall InterpolateFrame(int &I, double &w, const double AFrame);
	
protected:
	float __fastcall InterpolateValue(const float *AValues, const System::NativeInt AValues_High, const double AFrame)/* overload */;
	Stage::Vectorgeometry::TAffineVector __fastcall InterpolateValue(const Stage::Vectortypes::TVector3f *AValues, const System::NativeInt AValues_High, const double AFrame)/* overload */;
	Stage::Vectortypes::TMatrix4f __fastcall InterpolateValue(const Formatx::M3dstypes::TKFRotKey3DS *AValues, const System::NativeInt AValues_High, const double AFrame)/* overload */;
	
public:
	virtual void __fastcall LoadData(const int ANumKeys, const Formatx::M3dstypes::PKeyHeaderList Keys, const void * AData);
	virtual void __fastcall Apply(TgxFile3DSAnimationData &DataTransf, const double AFrame) = 0 ;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxFile3DSAnimationKeys() : Gxs::Persistentclasses::TgxPersistentObject() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSAnimationKeys(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxFile3DSAnimationKeys() { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSScaleAnimationKeys : public TgxFile3DSAnimationKeys
{
	typedef TgxFile3DSAnimationKeys inherited;
	
	
private:
	typedef System::DynamicArray<Stage::Vectortypes::TVector3f> _TgxFile3DSScaleAnimationKeys__1;
	
	
private:
	_TgxFile3DSScaleAnimationKeys__1 FScale;
	
public:
	virtual void __fastcall LoadData(const int ANumKeys, const Formatx::M3dstypes::PKeyHeaderList Keys, const void * AData);
	virtual void __fastcall Apply(TgxFile3DSAnimationData &DataTransf, const double AFrame);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxFile3DSScaleAnimationKeys() : TgxFile3DSAnimationKeys() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSScaleAnimationKeys(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSAnimationKeys(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxFile3DSScaleAnimationKeys() { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSRotationAnimationKeys : public TgxFile3DSAnimationKeys
{
	typedef TgxFile3DSAnimationKeys inherited;
	
	
private:
	typedef System::DynamicArray<Formatx::M3dstypes::TKFRotKey3DS> _TgxFile3DSRotationAnimationKeys__1;
	
	
private:
	_TgxFile3DSRotationAnimationKeys__1 FRot;
	
public:
	virtual void __fastcall LoadData(const int ANumKeys, const Formatx::M3dstypes::PKeyHeaderList Keys, const void * AData);
	virtual void __fastcall Apply(TgxFile3DSAnimationData &DataTransf, const double AFrame);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxFile3DSRotationAnimationKeys() : TgxFile3DSAnimationKeys() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSRotationAnimationKeys(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSAnimationKeys(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxFile3DSRotationAnimationKeys() { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSPositionAnimationKeys : public TgxFile3DSAnimationKeys
{
	typedef TgxFile3DSAnimationKeys inherited;
	
	
private:
	typedef System::DynamicArray<Stage::Vectortypes::TVector3f> _TgxFile3DSPositionAnimationKeys__1;
	
	
private:
	_TgxFile3DSPositionAnimationKeys__1 FPos;
	
public:
	virtual void __fastcall LoadData(const int ANumKeys, const Formatx::M3dstypes::PKeyHeaderList Keys, const void * AData);
	virtual void __fastcall Apply(TgxFile3DSAnimationData &DataTransf, const double AFrame);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxFile3DSPositionAnimationKeys() : TgxFile3DSAnimationKeys() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSPositionAnimationKeys(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSAnimationKeys(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxFile3DSPositionAnimationKeys() { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSColorAnimationKeys : public TgxFile3DSAnimationKeys
{
	typedef TgxFile3DSAnimationKeys inherited;
	
	
private:
	typedef System::DynamicArray<Stage::Vectortypes::TVector3f> _TgxFile3DSColorAnimationKeys__1;
	
	
private:
	_TgxFile3DSColorAnimationKeys__1 FCol;
	
public:
	virtual void __fastcall LoadData(const int ANumKeys, const Formatx::M3dstypes::PKeyHeaderList Keys, const void * AData);
	virtual void __fastcall Apply(TgxFile3DSAnimationData &DataTransf, const double AFrame);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxFile3DSColorAnimationKeys() : TgxFile3DSAnimationKeys() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSColorAnimationKeys(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSAnimationKeys(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxFile3DSColorAnimationKeys() { }
	
};


class PASCALIMPLEMENTATION TTgxFile3DSPositionAnimationKeys : public TgxFile3DSAnimationKeys
{
	typedef TgxFile3DSAnimationKeys inherited;
	
	
private:
	typedef System::DynamicArray<Stage::Vectortypes::TVector3f> _TTgxFile3DSPositionAnimationKeys__1;
	
	
private:
	_TTgxFile3DSPositionAnimationKeys__1 FTPos;
	
public:
	virtual void __fastcall LoadData(const int ANumKeys, const Formatx::M3dstypes::PKeyHeaderList Keys, const void * AData);
	virtual void __fastcall Apply(TgxFile3DSAnimationData &DataTransf, const double AFrame);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TTgxFile3DSPositionAnimationKeys() : TgxFile3DSAnimationKeys() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TTgxFile3DSPositionAnimationKeys(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSAnimationKeys(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TTgxFile3DSPositionAnimationKeys() { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSSpotLightCutOffAnimationKeys : public TgxFile3DSAnimationKeys
{
	typedef TgxFile3DSAnimationKeys inherited;
	
	
private:
	typedef System::DynamicArray<float> _TgxFile3DSSpotLightCutOffAnimationKeys__1;
	
	
private:
	_TgxFile3DSSpotLightCutOffAnimationKeys__1 FFall;
	
public:
	virtual void __fastcall LoadData(const int ANumKeys, const Formatx::M3dstypes::PKeyHeaderList Keys, const void * AData);
	virtual void __fastcall Apply(TgxFile3DSAnimationData &DataTransf, const double AFrame);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxFile3DSSpotLightCutOffAnimationKeys() : TgxFile3DSAnimationKeys() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSSpotLightCutOffAnimationKeys(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSAnimationKeys(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxFile3DSSpotLightCutOffAnimationKeys() { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSLightHotSpotAnimationKeys : public TgxFile3DSAnimationKeys
{
	typedef TgxFile3DSAnimationKeys inherited;
	
	
private:
	typedef System::DynamicArray<float> _TgxFile3DSLightHotSpotAnimationKeys__1;
	
	
private:
	_TgxFile3DSLightHotSpotAnimationKeys__1 FHot;
	
public:
	virtual void __fastcall LoadData(const int ANumKeys, const Formatx::M3dstypes::PKeyHeaderList Keys, const void * AData);
	virtual void __fastcall Apply(TgxFile3DSAnimationData &DataTransf, const double AFrame);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxFile3DSLightHotSpotAnimationKeys() : TgxFile3DSAnimationKeys() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSLightHotSpotAnimationKeys(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSAnimationKeys(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxFile3DSLightHotSpotAnimationKeys() { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSRollAnimationKeys : public TgxFile3DSAnimationKeys
{
	typedef TgxFile3DSAnimationKeys inherited;
	
	
private:
	typedef System::DynamicArray<float> _TgxFile3DSRollAnimationKeys__1;
	
	
private:
	_TgxFile3DSRollAnimationKeys__1 FRoll;
	
public:
	virtual void __fastcall LoadData(const int ANumKeys, const Formatx::M3dstypes::PKeyHeaderList Keys, const void * AData);
	virtual void __fastcall Apply(TgxFile3DSAnimationData &DataTransf, const double AFrame);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxFile3DSRollAnimationKeys() : TgxFile3DSAnimationKeys() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSRollAnimationKeys(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSAnimationKeys(reader) { }
	/* TgxPersistentObject.Destroy */ inline __fastcall virtual ~TgxFile3DSRollAnimationKeys() { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSAnimationKeyList : public Gxs::Persistentclasses::TgxPersistentObject
{
	typedef Gxs::Persistentclasses::TgxPersistentObject inherited;
	
	
private:
	typedef System::DynamicArray<TgxFile3DSAnimationKeys*> _TgxFile3DSAnimationKeyList__1;
	
	
private:
	_TgxFile3DSAnimationKeyList__1 FAnimKeysList;
	
protected:
	void __fastcall ApplyAnimKeys(TgxFile3DSAnimationData &DataTransf, const double AFrame);
	
public:
	void __fastcall AddKeys(TgxFile3DSAnimationKeys* const AItem);
	void __fastcall ClearKeys();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
	__fastcall virtual ~TgxFile3DSAnimationKeyList();
public:
	/* TgxPersistentObject.Create */ inline __fastcall virtual TgxFile3DSAnimationKeyList() : Gxs::Persistentclasses::TgxPersistentObject() { }
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSAnimationKeyList(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Persistentclasses::TgxPersistentObject(reader) { }
	
};


enum DECLSPEC_DENUM TgxFile3DSAnimKeysClassType : unsigned char { ctScale, ctRot, ctPos, ctCol, ctTPos, ctFall, ctHot, ctRoll };

class PASCALIMPLEMENTATION TgxFile3DSDummyObject : public Gxs::Vectorfileobjects::TgxMorphableMeshObject
{
	typedef Gxs::Vectorfileobjects::TgxMorphableMeshObject inherited;
	
private:
	TgxFile3DSAnimationKeyList* FAnimList;
	void *FAnimData;
	TgxFile3DSAnimationData FRefTranf;
	TgxFile3DSAnimationData FAnimTransf;
	TgxFile3DSDummyObject* FParent;
	Formatx::M3dstypes::String64 FParentName;
	bool FStatic;
	
public:
	virtual void __fastcall LoadAnimation(const void * AData);
	virtual void __fastcall SetFrame(const double AFrame);
	virtual void __fastcall MorphTo(int morphTargetIndex);
	virtual void __fastcall Lerp(int morphTargetIndex1, int morphTargetIndex2, float lerpFactor);
	virtual void __fastcall GetExtents(/* out */ Stage::Vectorgeometry::TAffineVector &min, /* out */ Stage::Vectorgeometry::TAffineVector &max)/* overload */;
	virtual Gxs::Vectorlists::TgxAffineVectorList* __fastcall ExtractTriangles(Gxs::Vectorlists::TgxAffineVectorList* texCoords = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0), Gxs::Vectorlists::TgxAffineVectorList* normals = (Gxs::Vectorlists::TgxAffineVectorList*)(0x0));
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__fastcall virtual TgxFile3DSDummyObject();
	__fastcall virtual ~TgxFile3DSDummyObject();
	__property TgxFile3DSAnimationKeyList* AnimList = {read=FAnimList};
	__property TgxFile3DSDummyObject* Parent = {read=FParent, write=FParent};
	__property TgxFile3DSAnimationData RefrenceTransf = {read=FRefTranf, write=FRefTranf};
public:
	/* TgxMeshObject.CreateOwned */ inline __fastcall TgxFile3DSDummyObject(Gxs::Vectorfileobjects::TgxMeshObjectList* aOwner) : Gxs::Vectorfileobjects::TgxMorphableMeshObject(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSDummyObject(Gxs::Persistentclasses::TgxVirtualReader* reader) : Gxs::Vectorfileobjects::TgxMorphableMeshObject(reader) { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  GetExtents(/* out */ Gxs::Geometrybb::TAABB &aabb){ Gxs::Vectorfileobjects::TgxMeshObject::GetExtents(aabb); }
	
};


class PASCALIMPLEMENTATION TgxFile3DSMeshObject : public TgxFile3DSDummyObject
{
	typedef TgxFile3DSDummyObject inherited;
	
public:
	virtual void __fastcall LoadAnimation(const void * AData);
	virtual void __fastcall BuildList(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci);
public:
	/* TgxFile3DSDummyObject.Create */ inline __fastcall virtual TgxFile3DSMeshObject() : TgxFile3DSDummyObject() { }
	/* TgxFile3DSDummyObject.Destroy */ inline __fastcall virtual ~TgxFile3DSMeshObject() { }
	
public:
	/* TgxMeshObject.CreateOwned */ inline __fastcall TgxFile3DSMeshObject(Gxs::Vectorfileobjects::TgxMeshObjectList* aOwner) : TgxFile3DSDummyObject(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSMeshObject(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSDummyObject(reader) { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSOmniLightObject : public TgxFile3DSDummyObject
{
	typedef TgxFile3DSDummyObject inherited;
	
private:
	Gxs::File3dssceneobjects::TgxFile3DSLight* FLightSrc;
	Formatx::M3dstypes::String64 FLightSrcName;
	
public:
	__fastcall virtual TgxFile3DSOmniLightObject();
	virtual void __fastcall LoadData(Gxs::Vectorfileobjects::TgxBaseMesh* const AOwner, const Formatx::M3dstypes::PLight3DS AData);
	virtual void __fastcall LoadAnimation(const void * AData);
	virtual void __fastcall SetFrame(const double AFrame);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
	__fastcall virtual ~TgxFile3DSOmniLightObject();
public:
	/* TgxMeshObject.CreateOwned */ inline __fastcall TgxFile3DSOmniLightObject(Gxs::Vectorfileobjects::TgxMeshObjectList* aOwner) : TgxFile3DSDummyObject(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSOmniLightObject(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSDummyObject(reader) { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSSpotLightObject : public TgxFile3DSOmniLightObject
{
	typedef TgxFile3DSOmniLightObject inherited;
	
public:
	virtual void __fastcall LoadData(Gxs::Vectorfileobjects::TgxBaseMesh* const AOwner, const Formatx::M3dstypes::PLight3DS AData);
	virtual void __fastcall LoadAnimation(const void * AData);
	virtual void __fastcall SetFrame(const double AFrame);
public:
	/* TgxFile3DSOmniLightObject.Create */ inline __fastcall virtual TgxFile3DSSpotLightObject() : TgxFile3DSOmniLightObject() { }
	/* TgxFile3DSOmniLightObject.Destroy */ inline __fastcall virtual ~TgxFile3DSSpotLightObject() { }
	
public:
	/* TgxMeshObject.CreateOwned */ inline __fastcall TgxFile3DSSpotLightObject(Gxs::Vectorfileobjects::TgxMeshObjectList* aOwner) : TgxFile3DSOmniLightObject(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSSpotLightObject(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSOmniLightObject(reader) { }
	
};


class PASCALIMPLEMENTATION TgxFile3DSCameraObject : public TgxFile3DSDummyObject
{
	typedef TgxFile3DSDummyObject inherited;
	
private:
	Gxs::Objects::TgxDummyCube* FTargetObj;
	Gxs::File3dssceneobjects::TgxFile3DSCamera* FCameraSrc;
	Formatx::M3dstypes::String64 FCameraSrcName;
	
public:
	__fastcall virtual TgxFile3DSCameraObject();
	void __fastcall LoadData(Gxs::Vectorfileobjects::TgxBaseMesh* Owner, Formatx::M3dstypes::PCamera3DS AData);
	virtual void __fastcall LoadAnimation(const void * AData);
	virtual void __fastcall SetFrame(const double AFrame);
	DYNAMIC void __fastcall WriteToFiler(Gxs::Persistentclasses::TgxVirtualWriter* Writer);
	DYNAMIC void __fastcall ReadFromFiler(Gxs::Persistentclasses::TgxVirtualReader* Reader);
	__fastcall virtual ~TgxFile3DSCameraObject();
public:
	/* TgxMeshObject.CreateOwned */ inline __fastcall TgxFile3DSCameraObject(Gxs::Vectorfileobjects::TgxMeshObjectList* aOwner) : TgxFile3DSDummyObject(aOwner) { }
	
public:
	/* TgxPersistentObject.CreateFromFiler */ inline __fastcall TgxFile3DSCameraObject(Gxs::Persistentclasses::TgxVirtualReader* reader) : TgxFile3DSDummyObject(reader) { }
	
};


class PASCALIMPLEMENTATION Tgx3DSVectorFile : public Gxs::Vectorfileobjects::TgxVectorFile
{
	typedef Gxs::Vectorfileobjects::TgxVectorFile inherited;
	
public:
	__classmethod virtual Gxs::Applicationfileio::TDataFileCapabilities __fastcall Capabilities();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* aStream);
public:
	/* TgxVectorFile.Create */ inline __fastcall virtual Tgx3DSVectorFile(System::Classes::TPersistent* aOwner) : Gxs::Vectorfileobjects::TgxVectorFile(aOwner) { }
	
public:
	/* TgxDataFile.Destroy */ inline __fastcall virtual ~Tgx3DSVectorFile() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool vFile3DS_UseTextureEx;
extern DELPHI_PACKAGE bool vFile3DS_EnableAnimation;
extern DELPHI_PACKAGE bool vFile3DS_FixDefaultUpAxisY;
extern DELPHI_PACKAGE int vFile3DS_LoadedStaticFrame;
}	/* namespace File3ds */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_FILE3DS)
using namespace Gxs::File3ds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_File3DSHPP

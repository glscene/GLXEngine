// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.CUDA.Graphics.pas' rev: 36.00 (Windows)

#ifndef GXS_CUDA_GraphicsHPP
#define GXS_CUDA_GraphicsHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <FMX.Dialogs.hpp>
#include <CUDA.Import.hpp>
#include <GXS.CUDA.API.hpp>
#include <GXS.Context.hpp>
#include <GXS.State.hpp>
#include <GXS.Scene.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Material.hpp>
#include <GXS.Texture.hpp>
#include <GXSL.Shader.hpp>
#include <GXSL.Parameter.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.BaseClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Cuda
{
namespace Graphics
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCUDAVertexAttribute;
class DELPHICLASS TCUDAVertexAttributes;
class DELPHICLASS TgxCustomFeedBackMesh;
class DELPHICLASS TgxFeedBackMesh;
class DELPHICLASS TCUDAImageResource;
class DELPHICLASS TCUDAGeometryResource;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TOnBeforeKernelLaunch)(TCUDAVertexAttribute* Sender);

class PASCALIMPLEMENTATION TCUDAVertexAttribute : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FName;
	Gxsl::Parameter::TgxSLDataType FType;
	Gxs::Cuda::Api::TCUDAFunction* FFunc;
	int FLocation;
	TOnBeforeKernelLaunch FOnBeforeKernelLaunch;
	void __fastcall SetName(const System::UnicodeString AName);
	void __fastcall SetType(Gxsl::Parameter::TgxSLDataType AType);
	void __fastcall SetFunc(Gxs::Cuda::Api::TCUDAFunction* AFunc);
	int __fastcall GetLocation();
	HIDESBASE TCUDAVertexAttributes* __fastcall GetOwner();
	
public:
	__fastcall virtual TCUDAVertexAttribute(System::Classes::TCollection* ACollection);
	void __fastcall NotifyChange(System::TObject* Sender);
	__property int Location = {read=GetLocation, nodefault};
	
__published:
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property Gxsl::Parameter::TgxSLDataType GLSLType = {read=FType, write=SetType, nodefault};
	__property Gxs::Cuda::Api::TCUDAFunction* KernelFunction = {read=FFunc, write=SetFunc};
	__property TOnBeforeKernelLaunch OnBeforeKernelLaunch = {read=FOnBeforeKernelLaunch, write=FOnBeforeKernelLaunch};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TCUDAVertexAttribute() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TCUDAVertexAttributes : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TCUDAVertexAttribute* operator[](int Index) { return this->Attributes[Index]; }
	
private:
	void __fastcall SetItems(int Index, TCUDAVertexAttribute* const AValue);
	TCUDAVertexAttribute* __fastcall GetItems(int Index);
	
public:
	__fastcall TCUDAVertexAttributes(System::Classes::TComponent* AOwner);
	void __fastcall NotifyChange(System::TObject* Sender);
	System::UnicodeString __fastcall MakeUniqueName(const System::UnicodeString ANameRoot);
	TCUDAVertexAttribute* __fastcall GetAttributeByName(const System::UnicodeString AName);
	HIDESBASE TCUDAVertexAttribute* __fastcall Add();
	__property TCUDAVertexAttribute* Attributes[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TCUDAVertexAttributes() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TFeedBackMeshPrimitive : unsigned char { fbmpPoint, fbmpLine, fbmpTriangle };

enum DECLSPEC_DENUM TFeedBackMeshLaunching : unsigned char { fblCommon, fblOnePerAtttribute };

class PASCALIMPLEMENTATION TgxCustomFeedBackMesh : public Gxs::Scene::TgxBaseSceneObject
{
	typedef Gxs::Scene::TgxBaseSceneObject inherited;
	
private:
	Gxs::Cuda::Api::TCUDAGraphicResource* FGeometryResource;
	TCUDAVertexAttributes* FAttributes;
	Gxs::Context::TgxVertexArrayHandle* FVAO;
	Gxs::Context::TgxVBOArrayBufferHandle* FVBO;
	Gxs::Context::TgxVBOElementArrayHandle* FEBO;
	TFeedBackMeshPrimitive FPrimitiveType;
	int FVertexNumber;
	int FElementNumber;
	Gxsl::Shader::TGXSLShader* FShader;
	Gxs::Cuda::Api::TCUDAFunction* FCommonFunc;
	TFeedBackMeshLaunching FLaunching;
	bool FBlend;
	void __fastcall SetAttributes(TCUDAVertexAttributes* AValue);
	void __fastcall SetPrimitiveType(TFeedBackMeshPrimitive AValue);
	void __fastcall SetVertexNumber(int AValue);
	void __fastcall SetElementNumber(int AValue);
	void __fastcall SetShader(Gxsl::Shader::TGXSLShader* AShader);
	void __fastcall SetCommonFunc(Gxs::Cuda::Api::TCUDAFunction* AFunc);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall RefreshAttributes();
	void __fastcall AllocateHandles();
	void __fastcall LaunchKernels();
	__property TCUDAVertexAttributes* Attributes = {read=FAttributes, write=SetAttributes};
	__property Gxsl::Shader::TGXSLShader* Shader = {read=FShader, write=SetShader};
	__property TFeedBackMeshPrimitive PrimitiveType = {read=FPrimitiveType, write=SetPrimitiveType, default=0};
	__property int VertexNumber = {read=FVertexNumber, write=SetVertexNumber, default=1};
	__property int ElementNumber = {read=FElementNumber, write=SetElementNumber, default=0};
	__property Gxs::Cuda::Api::TCUDAFunction* CommonKernelFunction = {read=FCommonFunc, write=SetCommonFunc};
	__property TFeedBackMeshLaunching Launching = {read=FLaunching, write=FLaunching, default=0};
	__property bool Blend = {read=FBlend, write=FBlend, default=0};
	
public:
	__fastcall virtual TgxCustomFeedBackMesh(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxCustomFeedBackMesh();
	virtual void __fastcall DoRender(Gxs::Rendercontextinfo::TgxRenderContextInfo &ARci, bool ARenderSelf, bool ARenderChildren);
	__property Gxs::Context::TgxVBOArrayBufferHandle* ArrayBufferHandle = {read=FVBO};
	__property Gxs::Context::TgxVBOElementArrayHandle* ElementArrayHandle = {read=FEBO};
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxCustomFeedBackMesh(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : Gxs::Scene::TgxBaseSceneObject(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TgxFeedBackMesh : public TgxCustomFeedBackMesh
{
	typedef TgxCustomFeedBackMesh inherited;
	
__published:
	__property Attributes;
	__property Shader;
	__property PrimitiveType = {default=0};
	__property VertexNumber = {default=1};
	__property ElementNumber = {default=0};
	__property CommonKernelFunction;
	__property Launching = {default=0};
	__property Blend = {default=0};
	__property ObjectsSorting = {default=0};
	__property VisibilityCulling = {default=0};
	__property Direction;
	__property PitchAngle = {default=0};
	__property Position;
	__property RollAngle = {default=0};
	__property Scale;
	__property ShowAxes = {default=0};
	__property TurnAngle = {default=0};
	__property Up;
	__property Visible = {default=1};
	__property Pickable = {default=1};
	__property OnProgress;
	__property OnPicked;
	__property Behaviours;
	__property Effects;
public:
	/* TgxCustomFeedBackMesh.Create */ inline __fastcall virtual TgxFeedBackMesh(System::Classes::TComponent* AOwner) : TgxCustomFeedBackMesh(AOwner) { }
	/* TgxCustomFeedBackMesh.Destroy */ inline __fastcall virtual ~TgxFeedBackMesh() { }
	
public:
	/* TgxBaseSceneObject.CreateAsChild */ inline __fastcall TgxFeedBackMesh(Gxs::Scene::TgxBaseSceneObject* aParentOwner) : TgxCustomFeedBackMesh(aParentOwner) { }
	
};


class PASCALIMPLEMENTATION TCUDAImageResource : public Gxs::Cuda::Api::TCUDAGraphicResource
{
	typedef Gxs::Cuda::Api::TCUDAGraphicResource inherited;
	
private:
	Gxs::Material::TgxMaterialLibrary* fMaterialLibrary;
	Gxs::Material::TgxLibMaterialName fTextureName;
	void __fastcall SetMaterialLibrary(Gxs::Material::TgxMaterialLibrary* const Value);
	void __fastcall SetTextureName(const Gxs::Material::TgxLibMaterialName Value);
	
protected:
	virtual void __fastcall AllocateHandles();
	virtual void __fastcall DestroyHandles();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TCUDAImageResource(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCUDAImageResource();
	virtual void __fastcall MapResources();
	virtual void __fastcall UnMapResources();
	virtual void __fastcall BindArrayToTexture(Gxs::Cuda::Api::TCUDAMemData* &cudaArray, System::LongWord ALeyer, System::LongWord ALevel);
	
__published:
	__property Gxs::Material::TgxLibMaterialName TextureName = {read=fTextureName, write=SetTextureName};
	__property Gxs::Material::TgxMaterialLibrary* MaterialLibrary = {read=fMaterialLibrary, write=SetMaterialLibrary};
	__property Mapping = {default=0};
};


class PASCALIMPLEMENTATION TCUDAGeometryResource : public Gxs::Cuda::Api::TCUDAGraphicResource
{
	typedef Gxs::Cuda::Api::TCUDAGraphicResource inherited;
	
private:
	TgxCustomFeedBackMesh* FFeedBackMesh;
	void __fastcall SetFeedBackMesh(TgxCustomFeedBackMesh* const Value);
	System::LongWord __fastcall GetAttribArraySize(TCUDAVertexAttribute* AAttr);
	
protected:
	virtual void __fastcall AllocateHandles();
	virtual void __fastcall DestroyHandles();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual System::LongWord __fastcall GetAttributeArraySize(const System::UnicodeString AName);
	virtual void * __fastcall GetAttributeArrayAddress(const System::UnicodeString AName);
	virtual System::LongWord __fastcall GetElementArrayDataSize();
	virtual void * __fastcall GetElementArrayAddress();
	
public:
	__fastcall virtual TCUDAGeometryResource(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCUDAGeometryResource();
	virtual void __fastcall MapResources();
	virtual void __fastcall UnMapResources();
	__property System::LongWord AttributeDataSize[const System::UnicodeString AttribName] = {read=GetAttributeArraySize};
	__property void * AttributeDataAddress[const System::UnicodeString AttribName] = {read=GetAttributeArrayAddress};
	__property System::LongWord IndexDataSize = {read=GetElementArrayDataSize, nodefault};
	__property void * IndexDataAddress = {read=GetElementArrayAddress};
	
__published:
	__property TgxCustomFeedBackMesh* FeedBackMesh = {read=FFeedBackMesh, write=SetFeedBackMesh};
	__property Mapping = {default=0};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Graphics */
}	/* namespace Cuda */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CUDA_GRAPHICS)
using namespace Gxs::Cuda::Graphics;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_CUDA)
using namespace Gxs::Cuda;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_CUDA_GraphicsHPP

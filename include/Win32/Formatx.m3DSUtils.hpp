// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Formatx.m3DSUtils.pas' rev: 36.00 (Windows)

#ifndef Formatx_m3DSUtilsHPP
#define Formatx_m3DSUtilsHPP

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
#include <Formatx.m3DS.hpp>
#include <Formatx.m3DSTypes.hpp>
#include <Formatx.m3DSConst.hpp>
#include <Stage.Strings.hpp>

//-- user supplied -----------------------------------------------------------

namespace Formatx
{
namespace M3dsutils
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall ShowError(const System::UnicodeString ErrorMessage);
extern DELPHI_PACKAGE void __fastcall ShowErrorFormatted(const System::UnicodeString ErrorMessage, const System::TVarRec *Args, const System::NativeInt Args_High);
extern DELPHI_PACKAGE Formatx::M3dstypes::TMeshSet3DS __fastcall GetMeshSet(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE Formatx::M3dstypes::TAtmosphere3DS __fastcall GetAtmosphere(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE Formatx::M3dstypes::TBackground3DS __fastcall GetBackground(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE Formatx::M3dstypes::TViewport3DS __fastcall GetViewport(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ChunkTagToString(System::Word Tag);
extern DELPHI_PACKAGE void __fastcall ChunkHeaderReport(System::Classes::TStrings* &Strings, Formatx::M3dstypes::PChunk3DS Chunk, int IndentLevel);
extern DELPHI_PACKAGE void __fastcall DumpKeyHeader(System::Classes::TStrings* Strings, const Formatx::M3dstypes::TKeyHeader3DS &Key, int IndentLevel);
extern DELPHI_PACKAGE void __fastcall DumpChunk(Formatx::M3ds::TFile3DS* const Source, System::Classes::TStrings* &Strings, Formatx::M3dstypes::PChunk3DS Chunk, int IndentLevel, Formatx::M3dstypes::TDumpLevel DumpLevel);
extern DELPHI_PACKAGE void __fastcall AddChild(Formatx::M3dstypes::PChunk3DS Parent, Formatx::M3dstypes::PChunk3DS Child);
extern DELPHI_PACKAGE void __fastcall AddChildOrdered(Formatx::M3dstypes::PChunk3DS Parent, Formatx::M3dstypes::PChunk3DS Child);
extern DELPHI_PACKAGE Formatx::M3dstypes::PChunk3DS __fastcall FindChunk(Formatx::M3dstypes::PChunk3DS Top, System::Word Tag);
extern DELPHI_PACKAGE Formatx::M3dstypes::PChunk3DS __fastcall FindNextChunk(Formatx::M3dstypes::PChunk3DS Local, System::Word Tag);
extern DELPHI_PACKAGE void __fastcall FreeChunkData(Formatx::M3dstypes::PChunk3DS &Chunk);
extern DELPHI_PACKAGE void __fastcall InitChunk(Formatx::M3dstypes::PChunk3DS &Chunk);
extern DELPHI_PACKAGE void __fastcall ReleaseChunk(Formatx::M3dstypes::PChunk3DS &Chunk);
extern DELPHI_PACKAGE void __fastcall ReleaseChunkList(Formatx::M3dstypes::PChunkList3DS &List);
extern DELPHI_PACKAGE int __fastcall GetMaterialCount(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE void __fastcall ReleaseMaterial(Formatx::M3dstypes::PMaterial3DS Mat);
extern DELPHI_PACKAGE Formatx::M3dstypes::PChunk3DS __fastcall FindNamedObjectByIndex(Formatx::M3ds::TFile3DS* Source, const Formatx::M3dstypes::TDatabase3DS &DB, System::Word AType, int Index);
extern DELPHI_PACKAGE void __fastcall DeleteChunk(Formatx::M3dstypes::PChunk3DS &Chunk);
extern DELPHI_PACKAGE int __fastcall GetChunkValue(System::Word Tag);
extern DELPHI_PACKAGE Formatx::M3dstypes::TMaterial3DS __fastcall GetMaterialByIndex(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, int Index);
extern DELPHI_PACKAGE int __fastcall GetMeshCount(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE void __fastcall ReleaseMeshObj(Formatx::M3dstypes::PMesh3DS Mesh);
extern DELPHI_PACKAGE Formatx::M3dstypes::TMesh3DS __fastcall GetMeshByIndex(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, int Index);
extern DELPHI_PACKAGE int __fastcall GetOmnilightCount(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE int __fastcall GetSpotlightCount(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE void __fastcall ReleaseLight(Formatx::M3dstypes::PLight3DS Light);
extern DELPHI_PACKAGE Formatx::M3dstypes::TLight3DS __fastcall GetOmnilightByIndex(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, int Index);
extern DELPHI_PACKAGE Formatx::M3dstypes::TLight3DS __fastcall GetSpotlightByIndex(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, int Index);
extern DELPHI_PACKAGE void __fastcall ReleaseCamera(Formatx::M3dstypes::PCamera3DS Camera);
extern DELPHI_PACKAGE int __fastcall GetCameraCount(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE Formatx::M3dstypes::TCamera3DS __fastcall GetCameraByIndex(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, int Index);
extern DELPHI_PACKAGE Formatx::M3dstypes::TKFSets3DS __fastcall GetKFSettings(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE void __fastcall ReleaseCameraMotion(Formatx::M3dstypes::PKFCamera3DS Camera);
extern DELPHI_PACKAGE void __fastcall GetCameraNodeNameList(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, System::Classes::TStringList* List);
extern DELPHI_PACKAGE int __fastcall GetCameraNodeCount(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE Formatx::M3dstypes::TKFCamera3DS __fastcall GetCameraMotion(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::PChunk3DS CamChunk, Formatx::M3dstypes::PChunk3DS TargetChunk);
extern DELPHI_PACKAGE Formatx::M3dstypes::TKFCamera3DS __fastcall GetCameraMotionByIndex(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, int Index);
extern DELPHI_PACKAGE void __fastcall ReleaseAmbientLightMotion(Formatx::M3dstypes::PKFAmbient3DS Light);
extern DELPHI_PACKAGE Formatx::M3dstypes::TKFAmbient3DS __fastcall GetAmbientLightMotion(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE void __fastcall InitObjectMotion(Formatx::M3dstypes::TKFMesh3DS &Obj, unsigned NewNPKeys, unsigned NewNRKeys, unsigned NewNSKeys, unsigned NewNMKeys, unsigned NewNHKeys);
extern DELPHI_PACKAGE void __fastcall ReleaseObjectMotion(Formatx::M3dstypes::PKFMesh3DS Obj);
extern DELPHI_PACKAGE int __fastcall GetObjectNodeCount(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE void __fastcall GetObjectNodeNameList(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, System::Classes::TStringList* List);
extern DELPHI_PACKAGE Formatx::M3dstypes::TKFMesh3DS __fastcall GetObjectMotionByName(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, const System::UnicodeString Name);
extern DELPHI_PACKAGE Formatx::M3dstypes::TKFMesh3DS __fastcall GetObjectMotionByIndex(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, unsigned Index);
extern DELPHI_PACKAGE void __fastcall ReleaseOmnilightMotion(Formatx::M3dstypes::PKFOmni3DS Light);
extern DELPHI_PACKAGE unsigned __fastcall GetOmnilightNodeCount(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE void __fastcall GetOmnilightNodeNameList(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, System::Classes::TStringList* List);
extern DELPHI_PACKAGE Formatx::M3dstypes::TKFOmni3DS __fastcall GetOmnilightMotionByName(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, const System::UnicodeString Name);
extern DELPHI_PACKAGE Formatx::M3dstypes::TKFOmni3DS __fastcall GetOmnilightMotionByIndex(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, unsigned Index);
extern DELPHI_PACKAGE void __fastcall ReleaseSpotlightMotion(Formatx::M3dstypes::PKFSpot3DS Spot);
extern DELPHI_PACKAGE unsigned __fastcall GetSpotlightNodeCount(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE void __fastcall GetSpotlightNodeNameList(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, System::Classes::TStringList* List);
extern DELPHI_PACKAGE Formatx::M3dstypes::TKFSpot3DS __fastcall GetSpotlightMotionByName(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, const System::UnicodeString Name);
extern DELPHI_PACKAGE Formatx::M3dstypes::TKFSpot3DS __fastcall GetSpotlightMotionByIndex(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB, unsigned Index);
extern DELPHI_PACKAGE Formatx::M3dstypes::TReleaseLevel __fastcall GetM3dMagicRelease(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE Formatx::M3dstypes::TReleaseLevel __fastcall GetMeshRelease(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE Formatx::M3dstypes::TReleaseLevel __fastcall GetKfRelease(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
extern DELPHI_PACKAGE Formatx::M3dstypes::TReleaseLevel __fastcall GetDatabaseRelease(Formatx::M3ds::TFile3DS* const Source, Formatx::M3dstypes::TDatabase3DS &DB);
}	/* namespace M3dsutils */
}	/* namespace Formatx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATX_M3DSUTILS)
using namespace Formatx::M3dsutils;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FORMATX)
using namespace Formatx;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Formatx_m3DSUtilsHPP

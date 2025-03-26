// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXS.HeightTileFileHDS.pas' rev: 36.00 (Windows)

#ifndef GXS_HeightTileFileHDSHPP
#define GXS_HeightTileFileHDSHPP

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
#include <GXS.HeightData.hpp>
#include <GXS.HeightTileFile.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gxs
{
namespace Heighttilefilehds
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TgxHeightTileFileHDS;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TgxHeightTileFileHDS : public Gxs::Heightdata::TgxHeightDataSource
{
	typedef Gxs::Heightdata::TgxHeightDataSource inherited;
	
private:
	bool FInfiniteWrap;
	bool FInverted;
	System::UnicodeString FHTFFileName;
	Gxs::Heighttilefile::TgxHeightTileFile* FHTF;
	int FMinElevation;
	
protected:
	void __fastcall SetHTFFileName(const System::UnicodeString val);
	void __fastcall SetInfiniteWrap(bool val);
	void __fastcall SetInverted(bool val);
	void __fastcall SetMinElevation(int val);
	
public:
	__fastcall virtual TgxHeightTileFileHDS(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TgxHeightTileFileHDS();
	virtual void __fastcall StartPreparingData(Gxs::Heightdata::TgxHeightData* HeightData);
	virtual int __fastcall Width();
	virtual int __fastcall Height();
	Gxs::Heighttilefile::TgxHeightTileFile* __fastcall OpenHTF();
	
__published:
	__property System::UnicodeString HTFFileName = {read=FHTFFileName, write=SetHTFFileName};
	__property bool InfiniteWrap = {read=FInfiniteWrap, write=SetInfiniteWrap, default=1};
	__property bool Inverted = {read=FInverted, write=SetInverted, default=1};
	__property int MinElevation = {read=FMinElevation, write=SetMinElevation, default=-32768};
	__property MaxPoolSize;
	__property DefaultHeight = {default=0};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Heighttilefilehds */
}	/* namespace Gxs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS_HEIGHTTILEFILEHDS)
using namespace Gxs::Heighttilefilehds;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXS)
using namespace Gxs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXS_HeightTileFileHDSHPP

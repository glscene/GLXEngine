// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'uGBEPathFinder.pas' rev: 36.00 (Windows)

#ifndef uGBEPathFinderHPP
#define uGBEPathFinderHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <System.UITypes.hpp>
#include <System.Classes.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Generics.Defaults.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ugbepathfinder
{
//-- forward type declarations -----------------------------------------------
struct TGBENoeud;
class DELPHICLASS TGBEPathFinder;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TGBENoeud
{
public:
	int CoutDeplacement;
	int Heuristique;
	int EstimationCout;
	System::Types::TPoint Position;
	System::Types::TPoint Parent;
};


enum DECLSPEC_DENUM TGBEPathFinderMode : unsigned char { DeplacementsMinimum, CoutMinimum };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGBEPathFinder : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TGBENoeud fNoeudDepart;
	TGBENoeud fNoeudArrivee;
	System::Generics::Collections::TDictionary__2<System::Types::TPoint,TGBENoeud>* ListeNoeudsPossibles;
	System::Generics::Collections::TDictionary__2<System::Types::TPoint,TGBENoeud>* ListeNoeudsVoisins;
	int flGrille;
	int fhGrille;
	int fCoutDeplacementCote;
	int fCoutDeplacementDiagonal;
	bool fAutoriserDeplacementDiagonal;
	bool fQuePremiereEtape;
	TGBEPathFinderMode fMode;
	int __fastcall CalculerCoutArrivee(const System::Types::TPoint &Point);
	void __fastcall OptimiserChemin();
	TGBENoeud __fastcall RechercheCoutTotalMin(System::Generics::Collections::TDictionary__2<System::Types::TPoint,TGBENoeud>* Liste);
	void __fastcall ListerVoisins(const TGBENoeud &UnNoeud);
	System::Generics::Collections::TDictionary__2<System::Types::TPoint,TGBENoeud>* ListeChemin;
	System::Generics::Collections::TDictionary__2<System::Types::TPoint,TGBENoeud>* ListeNoeudsObstacles;
	__fastcall virtual TGBEPathFinder();
	__fastcall virtual ~TGBEPathFinder();
	bool __fastcall RechercherChemin();
	__property TGBENoeud NoeudDepart = {read=fNoeudDepart, write=fNoeudDepart};
	__property TGBENoeud NoeudArrivee = {read=fNoeudArrivee, write=fNoeudArrivee};
	__property int LargeurGrille = {read=flGrille, write=flGrille, nodefault};
	__property int HauteurGrille = {read=fhGrille, write=fhGrille, nodefault};
	__property int CoutDeplacementCote = {read=fCoutDeplacementCote, write=fCoutDeplacementCote, nodefault};
	__property int CoutDeplacementDiagonal = {read=fCoutDeplacementDiagonal, write=fCoutDeplacementDiagonal, nodefault};
	__property bool AutoriserDeplacementDiagonal = {read=fAutoriserDeplacementDiagonal, write=fAutoriserDeplacementDiagonal, nodefault};
	__property bool QuePremiereEtape = {read=fQuePremiereEtape, write=fQuePremiereEtape, nodefault};
	__property TGBEPathFinderMode Mode = {read=fMode, write=fMode, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Ugbepathfinder */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_UGBEPATHFINDER)
using namespace Ugbepathfinder;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// uGBEPathFinderHPP

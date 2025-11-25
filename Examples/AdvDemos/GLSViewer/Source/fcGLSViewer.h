//---------------------------------------------------------------------------

#ifndef fcGLSViewerH
#define fcGLSViewerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ActnMenus.hpp>
#include <Vcl.BandActn.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.StdStyleActnCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "GLS.AsyncTimer.hpp"
#include "GLS.BaseClasses.hpp"
#include "GLS.Cadencer.hpp"
#include "GLS.Coordinates.hpp"
#include "GLS.Graph.hpp"
#include "GLS.Material.hpp"
#include "GLS.Objects.hpp"
#include "GLS.GeomObjects.hpp"
#include "GLS.MultiPolygon.hpp"
#include "GLS.Extrusion.hpp"
#include "GLS.Scene.hpp"
#include "GLS.SceneViewer.hpp"
#include "GLS.SimpleNavigation.hpp"
#include "GLS.VectorFileObjects.hpp"
#include "GLS.SkyDome.hpp"
#include "GLS.Navigator.hpp"

//---------------------------------------------------------------------------
class TFormViewer : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar;
	TGLSceneViewer *snViewer;
	TControlBar *ControlBar;
	TActionToolBar *atbTools;
	TActionToolBar *atbView;
	TActionToolBar *atbFile;
	TActionMainMenuBar *amMenuBar;
	TPanel *PanelLeft;
	TTreeView *tvScene;
	TGLScene *Scene;
	TGLCamera *Camera;
	TGLLightSource *LightSource;
	TGLXYZGrid *XYZGrid;
	TGLCube *CubeLines;
	TGLDummyCube *dcObject;
	TGLFreeForm *ffObject;
	TGLDummyCube *dcAxis;
	TGLDummyCube *dcWorld;
	TGLPoints *GLPoints;
	TGLMaterialLibrary *MaterialLib;
	TGLCadencer *Cadencer;
	TTimer *Timer;
	TActionManager *ActionManager;
	TAction *acOptimizeMesh;
	TAction *acProcessInvertNormals;
	TAction *acReverseRendering;
	TAction *acConvertToTriangles;
	TAction *acProcessStripify;
	TAction *acToolsOptions;
	TAction *acToolsFaceCulling;
	TAction *acToolsTexturing;
	TAction *acToolsLighting;
	TAction *acToolsNaviCube;
	TCustomizeActionBars *acToolsCustomize;
	TAction *acToolsShowFPS;
	TAction *acViewSmoothShading;
	TAction *acViewFlatShading;
	TAction *acViewFlatLines;
	TAction *acViewHiddenLines;
	TAction *acViewWireFrame;
	TAction *acViewZoomIn;
	TAction *acViewZoomOut;
	TAction *acViewReset;
	TAction *acFileOpen;
	TAction *acFilePick;
	TAction *acFileOpenTexLib;
	TAction *acFileSaveAs;
	TAction *acFileSaveTextures;
	TAction *acSaveTreeView;
	TAction *acLoadTreeView;
	TAction *acFileExit;
	THelpContents *acHelpContents;
	THelpTopicSearch *acHelpTopicSearch;
	TAction *acHelpGLSHomePage;
	TAction *acHelpAbout;
	TAction *acAADefault;
	TAction *acAA2X;
	TAction *acAA4X;
	TEditUndo *acEditUndo;
	TEditCut *acEditCut;
	TEditCopy *acEditCopy;
	TEditPaste *acEditPaste;
	TEditSelectAll *acEditSelectAll;
	TEditDelete *acEditDelete;
	TAction *acAA8X;
	TAction *acAA16X;
	TAction *acCSA8X;
	TAction *acCSA16X;
	TAction *acPoints;
	TAction *acToolsInfo;
	TAction *acSpheres;
	TImageList *ImageListMenu;
	TGLAsyncTimer *AsyncTimer;
	TGLSimpleNavigation *GLSimpleNavigation;
	TImageList *ImageListObjects;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	void __fastcall tvSceneClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
	TFileName AssetPath;
	TFileName TextureDir;
	// Base objects
	TGLLines *Lines;
	TGLPlane *Plane;
	TGLPolygon *Polygon;
	TGLCube *Cube;
	TGLFrustrum *Frustrum;
	TGLSphere *Sphere;
	TGLDisk *Disk;
	TGLCone *Cone;
	TGLCylinder *Cylinder;
	TGLCapsule *Capsule;
	TGLDodecahedron *Dodecahedron;
	TGLIcosahedron *Icosahedron;
	TGLHexahedron *Hexahedron;
	TGLOctahedron *Octahedron;
	TGLTetrahedron *Tetrahedron;
//	TGLSuperEllipsoid *SuperEllipsoid;
	// Advanced objects
	TGLAnnulus *Annulus;
	TGLArrowLine *ArrowLine;
	TGLArrowArc *ArrowArc;
	TGLMultiPolygon *MultiPolygon;
	TGLRevolutionSolid *RevolutionSolid;
	TGLExtrusionSolid *ExtrusionSolid;
	// Mesh objects
	TGLActor *Actor;
	TGLFreeForm *FreeForm;
	TGLMeshObject *MeshObject;
	// Environment objects
	TGLSkyBox *SkyBox;
	TGLSkyDome *SkyDome;
	TGLEarthSkyDome *EarthSkyDome;

/*
	void DoResetCamera;
	void SetupFreeFormShading;
	void ApplyShadeModeToMaterial(aMaterial: TGLMaterial);
	void ApplyShadeMode;
	void ApplyFSAA;
	void ApplyFaceCull;
	void ApplyTexturing;
	void ApplyFPS;
	void DoOpen(const FileName: String);
*/

public:		// User declarations
	__fastcall TFormViewer(TComponent* Owner);
	bool md, nthShow;
	int mx, my;
	TGLShader *hlShader;
	/// StringlastFileName;
	bool lastLoadWithTextures;
/*
	void ApplyBgColor;
	void ReadIniFile; override;
	void WriteIniFile;
*/

};


//---------------------------------------------------------------------------
extern PACKAGE TFormViewer *FormViewer;
//---------------------------------------------------------------------------
#endif

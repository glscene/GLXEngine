// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLScene_Physics_DT.dpk' rev: 36.00 (Windows)

#ifndef GLScene_Physics_DTHPP
#define GLScene_Physics_DTHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>	// (rtl)
#include <SysInit.hpp>
#include <GLS.Physics.Register.hpp>
#include <System.UITypes.hpp>	// (rtl)
#include <Winapi.Windows.PkgHelper.hpp>	// (rtl)
#include <Winapi.PsAPI.hpp>	// (rtl)
#include <System.Character.hpp>	// (rtl)
#include <System.Internal.ExcUtils.hpp>	// (rtl)
#include <System.SysUtils.hpp>	// (rtl)
#include <System.VarUtils.hpp>	// (rtl)
#include <System.Variants.hpp>	// (rtl)
#include <System.TypInfo.hpp>	// (rtl)
#include <System.Math.hpp>	// (rtl)
#include <System.Generics.Defaults.hpp>	// (rtl)
#include <System.TimeSpan.hpp>	// (rtl)
#include <System.SyncObjs.hpp>	// (rtl)
#include <System.Rtti.hpp>	// (rtl)
#include <System.Classes.hpp>	// (rtl)
#include <Winapi.OpenGL.PkgHelper.hpp>	// (rtl)
#include <Stage.VectorGeometry.hpp>	// (GLScene_RT)
#include <GLS.PersistentClasses.hpp>	// (GLScene_RT)
#include <GLS.VectorLists.hpp>	// (GLScene_RT)
#include <Stage.Logger.hpp>	// (GLScene_RT)
#include <Stage.Manager.hpp>	// (GLScene_RT)
#include <GLS.XCollection.hpp>	// (GLScene_RT)
#include <System.DateUtils.hpp>	// (rtl)
#include <System.IOUtils.hpp>	// (rtl)
#include <System.IniFiles.hpp>	// (rtl)
#include <System.Win.Registry.hpp>	// (rtl)
#include <System.UIConsts.hpp>	// (rtl)
#include <Vcl.Graphics.hpp>	// (vcl)
#include <System.Messaging.hpp>	// (rtl)
#include <System.Actions.hpp>	// (rtl)
#include <Vcl.ActnList.hpp>	// (vcl)
#include <System.HelpIntfs.hpp>	// (rtl)
#include <Winapi.UxTheme.hpp>	// (rtl)
#include <System.AnsiStrings.hpp>	// (rtl)
#include <Vcl.GraphUtil.hpp>	// (vcl)
#include <Vcl.StdCtrls.hpp>	// (vcl)
#include <Vcl.Clipbrd.hpp>	// (vcl)
#include <Vcl.Printers.hpp>	// (vcl)
#include <Vcl.ComCtrls.hpp>	// (vcl)
#include <Vcl.Dialogs.hpp>	// (vcl)
#include <Vcl.ExtCtrls.hpp>	// (vcl)
#include <Vcl.Themes.hpp>	// (vcl)
#include <System.Win.ComObj.hpp>	// (rtl)
#include <Winapi.FlatSB.hpp>	// (rtl)
#include <Vcl.Forms.hpp>	// (vcl)
#include <Vcl.Menus.hpp>	// (vcl)
#include <Winapi.MsCTF.PkgHelper.hpp>	// (rtl)
#include <Vcl.Controls.hpp>	// (vcl)
#include <Stage.Utils.hpp>	// (GLScene_RT)
#include <GLS.OpenGLAdapter.hpp>	// (GLScene_RT)
#include <GLS.Color.hpp>	// (GLScene_RT)
#include <GLS.XOpenGL.hpp>	// (GLScene_RT)
#include <GLS.Context.hpp>	// (GLScene_RT)
#include <Vcl.Imaging.pngimage.hpp>	// (vclimg)
#include <Vcl.Buttons.hpp>	// (vcl)
#include <Vcl.ExtDlgs.hpp>	// (vcl)
#include <GLS.Graphics.hpp>	// (GLScene_RT)
#include <Vcl.Imaging.jpeg.hpp>	// (vclimg)
#include <GLS.Coordinates.hpp>	// (GLScene_RT)
#include <GLS.Texture.hpp>	// (GLScene_RT)
#include <GLS.Material.hpp>	// (GLScene_RT)
#include <GLS.Scene.hpp>	// (GLScene_RT)
#include <GLS.Objects.hpp>	// (GLScene_RT)
#include <GLS.HeightData.hpp>	// (GLScene_RT)
#include <GLS.Mesh.hpp>	// (GLScene_RT)
#include <GLS.MeshUtils.hpp>	// (GLScene_RT)
#include <GLS.VectorFileObjects.hpp>	// (GLScene_RT)
#include <GLS.GeomObjects.hpp>	// (GLScene_RT)
#include <GLS.MultiPolygon.hpp>	// (GLScene_RT)
#include <GLS.SpaceText.hpp>	// (GLScene_RT)
#include <GLS.Isolines.hpp>	// (GLScene_RT)
#include <GLS.ROAMPatch.hpp>	// (GLScene_RT)
#include <GLS.TerrainRenderer.hpp>	// (GLScene_RT)
#include <GLS.Graph.hpp>	// (GLScene_RT)
#include <ODE.Import.hpp>	// (GLScene_Physics_RT)
#include <GLS.WindowsContext.hpp>	// (GLScene_RT)
#include <GLS.SceneViewer.hpp>	// (GLScene_RT)
#include <GLS.VerletTypes.hpp>	// (GLScene_RT)
#include <GLS.ODEManager.hpp>	// (GLScene_Physics_RT)
#include <GLS.NGDManager.hpp>	// (GLScene_Physics_RT)
#include <GLS.Behaviours.hpp>	// (GLScene_RT)
#include <GLS.PhysInertias.hpp>	// (GLScene_Physics_RT)
#include <GLS.PhysForces.hpp>	// (GLScene_Physics_RT)
#include <GLS.PhysManager.hpp>	// (GLScene_Physics_RT)
// PRG_EXT: .bpl
// BPI_DIR: ..\lib\Win32
// OBJ_DIR: ..\lib\Win32
// OBJ_EXT: .obj

//-- user supplied -----------------------------------------------------------

namespace Glscene_physics_dt
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
}	/* namespace Glscene_physics_dt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLSCENE_PHYSICS_DT)
using namespace Glscene_physics_dt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLScene_Physics_DTHPP

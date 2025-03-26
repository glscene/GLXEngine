// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXScene_Sounds_RT.dpk' rev: 36.00 (Windows)

#ifndef GXScene_Sounds_RTHPP
#define GXScene_Sounds_RTHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>	// (rtl)
#include <SysInit.hpp>
#include <GXS.Sounds.FMOD.hpp>
#include <GXS.Sounds.BASS.hpp>
#include <GXS.Sounds.OpenAL.hpp>
#include <GXS.Sounds.WaveOut.hpp>
#include <BASS.Import.hpp>
#include <FMOD.errors.hpp>
#include <FMOD.Import.hpp>
#include <FMOD.presets.hpp>
#include <FMOD.types.hpp>
#include <OpenAL.Import.hpp>
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
#include <System.Messaging.hpp>	// (rtl)
#include <System.Actions.hpp>	// (rtl)
#include <System.Devices.hpp>	// (rtl)
#include <System.UIConsts.hpp>	// (rtl)
#include <System.AnsiStrings.hpp>	// (rtl)
#include <FMX.Utils.hpp>	// (fmx)
#include <FMX.Text.hpp>	// (fmx)
#include <FMX.Graphics.hpp>	// (fmx)
#include <FMX.BehaviorManager.hpp>	// (fmx)
#include <FMX.Styles.hpp>	// (fmx)
#include <FMX.Types3D.hpp>	// (fmx)
#include <FMX.Filter.Custom.hpp>	// (fmx)
#include <FMX.Effects.hpp>	// (fmx)
#include <FMX.MultiResBitmap.hpp>	// (fmx)
#include <FMX.Ani.hpp>	// (fmx)
#include <System.DateUtils.hpp>	// (rtl)
#include <System.IOUtils.hpp>	// (rtl)
#include <FMX.ImgList.hpp>	// (fmx)
#include <Winapi.D2D1.hpp>	// (rtl)
#include <Winapi.UxTheme.hpp>	// (rtl)
#include <FMX.DialogService.hpp>	// (fmx)
#include <FMX.Menus.hpp>	// (fmx)
#include <Winapi.MsCTF.PkgHelper.hpp>	// (rtl)
#include <System.Win.ComObj.hpp>	// (rtl)
#include <FMX.Helpers.Win.hpp>	// (fmx)
#include <FMX.Objects.hpp>	// (fmx)
#include <System.IniFiles.hpp>	// (rtl)
#include <System.Win.Registry.hpp>	// (rtl)
#include <Winapi.GDIPOBJ.hpp>	// (rtl)
#include <FMX.Canvas.D2D.hpp>	// (fmx)
#include <FMX.Canvas.GDIP.hpp>	// (fmx)
#include <FMX.Printer.hpp>	// (fmx)
#include <FMX.Presentation.Factory.hpp>	// (fmx)
#include <FMX.Controls.Win.hpp>	// (fmx)
#include <FMX.Presentation.Win.hpp>	// (fmx)
#include <FMX.Presentation.Win.Style.hpp>	// (fmx)
#include <FMX.Styles.Objects.hpp>	// (fmx)
#include <FMX.Styles.Switch.hpp>	// (fmx)
#include <FMX.Switch.Style.hpp>	// (fmx)
#include <FMX.Switch.Win.hpp>	// (fmx)
#include <FMX.StdCtrls.hpp>	// (fmx)
#include <FMX.InertialMovement.hpp>	// (fmx)
#include <FMX.Layouts.hpp>	// (fmx)
#include <FMX.Clipboard.Win.hpp>	// (fmx)
#include <FMX.ScrollBox.Win.hpp>	// (fmx)
#include <FMX.ScrollBox.hpp>	// (fmx)
#include <FMX.ScrollBox.Style.hpp>	// (fmx)
#include <FMX.MagnifierGlass.hpp>	// (fmx)
#include <FMX.Edit.Style.New.hpp>	// (fmx)
#include <FMX.Edit.Win.hpp>	// (fmx)
#include <FMX.Edit.hpp>	// (fmx)
#include <FMX.DialogHelper.hpp>	// (fmx)
#include <FMX.Dialogs.Win.hpp>	// (fmx)
#include <FMX.TextLayout.GPU.hpp>	// (fmx)
#include <FMX.Canvas.GPU.hpp>	// (fmx)
#include <FMX.Context.DX9.hpp>	// (fmx)
#include <FMX.Context.DX11.hpp>	// (fmx)
#include <System.Win.InternetExplorer.hpp>	// (rtl)
#include <Winapi.EdgeUtils.hpp>	// (rtl)
#include <FMX.WebBrowser.Win.hpp>	// (fmx)
#include <FMX.WebBrowser.hpp>	// (fmx)
#include <FMX.ListBox.hpp>	// (fmx)
#include <FMX.DateTimeCtrls.hpp>	// (fmx)
#include <FMX.ExtCtrls.hpp>	// (fmx)
#include <FMX.Calendar.Style.hpp>	// (fmx)
#include <FMX.Calendar.hpp>	// (fmx)
#include <FMX.Pickers.hpp>	// (fmx)
#include <FMX.Platform.Win.hpp>	// (fmx)
#include <FMX.Gestures.Win.hpp>	// (fmx)
#include <FMX.Gestures.hpp>	// (fmx)
#include <FMX.Controls.hpp>	// (fmx)
#include <FMX.Header.hpp>	// (fmx)
#include <FMX.Forms.hpp>	// (fmx)
#include <FMX.Platform.hpp>	// (fmx)
#include <FMX.Types.hpp>	// (fmx)
#include <FMX.DialogService.Sync.hpp>	// (fmx)
#include <FMX.Dialogs.hpp>	// (fmx)
#include <Stage.VectorGeometry.hpp>	// (GXScene_RT)
#include <GXS.PersistentClasses.hpp>	// (GXScene_RT)
#include <GXS.XCollection.hpp>	// (GXScene_RT)
#include <Winapi.OpenGL.PkgHelper.hpp>	// (rtl)
#include <Stage.Utils.hpp>	// (GXScene_RT)
#include <GXS.ImageUtils.hpp>	// (GXScene_RT)
#include <GXS.SoundFileObjects.hpp>	// (GXScene_RT)
#include <Stage.Logger.hpp>	// (GXScene_RT)
#include <GXS.Coordinates.hpp>	// (GXScene_RT)
#include <GXS.VectorLists.hpp>	// (GXScene_RT)
#include <GXS.Color.hpp>	// (GXScene_RT)
#include <GXS.XOpenGL.hpp>	// (GXScene_RT)
#include <GXS.Context.hpp>	// (GXScene_RT)
#include <Stage.OpenGL4.hpp>	// (GXScene_RT)
#include <GXS.Graphics.hpp>	// (GXScene_RT)
#include <GXS.Texture.hpp>	// (GXScene_RT)
#include <GXS.Material.hpp>	// (GXScene_RT)
#include <GXS.Scene.hpp>	// (GXScene_RT)
#include <GXS.Cadencer.hpp>	// (GXScene_RT)
#include <GXS.SoundManager.hpp>	// (GXScene_RT)
// PRG_EXT: .bpl
// BPI_DIR: ..\lib\Win32
// OBJ_DIR: ..\lib\Win32
// OBJ_EXT: .obj

//-- user supplied -----------------------------------------------------------

namespace Gxscene_sounds_rt
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
}	/* namespace Gxscene_sounds_rt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSCENE_SOUNDS_RT)
using namespace Gxscene_sounds_rt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXScene_Sounds_RTHPP

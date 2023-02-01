﻿// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLScene_Cg_RT.dpk' rev: 35.00 (Windows)

#ifndef Glscene_cg_rtHPP
#define Glscene_cg_rtHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// (rtl)
#include <SysInit.hpp>
#include <Cg.GL.hpp>
#include <Cg.Import.hpp>
#include <Cg.Shader.hpp>
#include <Cg.BombShader.hpp>
#include <Cg.PostTransformationShader.hpp>
#include <System.Types.hpp>	// (rtl)
#include <System.UITypes.hpp>	// (rtl)
#include <Winapi.Windows.hpp>	// (rtl)
#include <System.SysConst.hpp>	// (rtl)
#include <Winapi.ImageHlp.hpp>	// (rtl)
#include <Winapi.SHFolder.hpp>	// (rtl)
#include <Winapi.PsAPI.hpp>	// (rtl)
#include <System.RTLConsts.hpp>	// (rtl)
#include <System.Character.hpp>	// (rtl)
#include <System.Internal.ExcUtils.hpp>	// (rtl)
#include <System.SysUtils.hpp>	// (rtl)
#include <System.Math.hpp>	// (rtl)
#include <Winapi.OpenGL.hpp>	// (rtl)
#include <Winapi.Messages.hpp>	// (rtl)
#include <System.VarUtils.hpp>	// (rtl)
#include <System.Variants.hpp>	// (rtl)
#include <Winapi.ActiveX.hpp>	// (rtl)
#include <System.TypInfo.hpp>	// (rtl)
#include <System.Hash.hpp>	// (rtl)
#include <System.Generics.Defaults.hpp>	// (rtl)
#include <System.Generics.Collections.hpp>	// (rtl)
#include <System.Rtti.hpp>	// (rtl)
#include <System.TimeSpan.hpp>	// (rtl)
#include <System.Diagnostics.hpp>	// (rtl)
#include <System.Classes.hpp>	// (rtl)
#include <Winapi.OpenGLext.hpp>	// (rtl)
#include <GLS.VectorTypes.hpp>	// (GLScene_RT)
#include <GLS.OpenGLTokens.hpp>	// (GLScene_RT)
#include <GLS.VectorGeometry.hpp>	// (GLScene_RT)
#include <GLS.Strings.hpp>	// (GLScene_RT)
#include <Winapi.Qos.hpp>	// (rtl)
#include <Winapi.Winsock2.hpp>	// (rtl)
#include <Winapi.IpExport.hpp>	// (rtl)
#include <Winapi.ShellAPI.hpp>	// (rtl)
#include <System.Messaging.hpp>	// (rtl)
#include <System.Actions.hpp>	// (rtl)
#include <Winapi.Wincodec.hpp>	// (rtl)
#include <Winapi.CommCtrl.hpp>	// (rtl)
#include <Winapi.RegStr.hpp>	// (rtl)
#include <Winapi.WinInet.hpp>	// (rtl)
#include <Winapi.UrlMon.hpp>	// (rtl)
#include <Winapi.ObjectArray.hpp>	// (rtl)
#include <Winapi.StructuredQueryCondition.hpp>	// (rtl)
#include <Winapi.PropSys.hpp>	// (rtl)
#include <Winapi.MSXMLIntf.hpp>	// (rtl)
#include <Winapi.ShlObj.hpp>	// (rtl)
#include <Winapi.KnownFolders.hpp>	// (rtl)
#include <System.Masks.hpp>	// (rtl)
#include <System.StrUtils.hpp>	// (rtl)
#include <System.DateUtils.hpp>	// (rtl)
#include <System.IOUtils.hpp>	// (rtl)
#include <System.IniFiles.hpp>	// (rtl)
#include <System.Win.Registry.hpp>	// (rtl)
#include <System.UIConsts.hpp>	// (rtl)
#include <Vcl.Consts.hpp>	// (vcl)
#include <Vcl.Graphics.hpp>	// (vcl)
#include <System.Contnrs.hpp>	// (rtl)
#include <System.ImageList.hpp>	// (rtl)
#include <System.SyncObjs.hpp>	// (rtl)
#include <Winapi.UxTheme.hpp>	// (rtl)
#include <Winapi.MultiMon.hpp>	// (rtl)
#include <Winapi.Imm.hpp>	// (rtl)
#include <Vcl.ActnList.hpp>	// (vcl)
#include <Winapi.TpcShrd.hpp>	// (rtl)
#include <System.AnsiStrings.hpp>	// (rtl)
#include <System.Win.ComConst.hpp>	// (rtl)
#include <System.Win.ComObj.hpp>	// (rtl)
#include <Winapi.MsCTF.hpp>	// (rtl)
#include <Winapi.Dwmapi.hpp>	// (rtl)
#include <System.Win.Crtl.hpp>	// (rtl)
#include <System.ZLib.hpp>	// (rtl)
#include <Vcl.GraphUtil.hpp>	// (vcl)
#include <Winapi.MsInkAut.hpp>	// (rtl)
#include <Winapi.PenInputPanel.hpp>	// (rtl)
#include <Vcl.Controls.hpp>	// (vcl)
#include <Vcl.StdCtrls.hpp>	// (vcl)
#include <System.MaskUtils.hpp>	// (rtl)
#include <Vcl.Clipbrd.hpp>	// (vcl)
#include <Vcl.Mask.hpp>	// (vcl)
#include <Winapi.CommDlg.hpp>	// (rtl)
#include <Winapi.WinSpool.hpp>	// (rtl)
#include <Vcl.Printers.hpp>	// (vcl)
#include <Winapi.RichEdit.hpp>	// (rtl)
#include <Vcl.ToolWin.hpp>	// (vcl)
#include <Vcl.ListActns.hpp>	// (vcl)
#include <Vcl.ComStrs.hpp>	// (vcl)
#include <Vcl.StdActns.hpp>	// (vcl)
#include <Vcl.ComCtrls.hpp>	// (vcl)
#include <System.WideStrUtils.hpp>	// (rtl)
#include <Winapi.Dlgs.hpp>	// (rtl)
#include <System.HelpIntfs.hpp>	// (rtl)
#include <Vcl.Dialogs.hpp>	// (vcl)
#include <Vcl.ExtCtrls.hpp>	// (vcl)
#include <Vcl.Themes.hpp>	// (vcl)
#include <Vcl.ImgList.hpp>	// (vcl)
#include <Vcl.Menus.hpp>	// (vcl)
#include <System.Win.Taskbar.hpp>	// (rtl)
#include <System.Win.TaskbarCore.hpp>	// (rtl)
#include <Winapi.ShellScaling.hpp>	// (rtl)
#include <Winapi.FlatSB.hpp>	// (rtl)
#include <Vcl.Forms.hpp>	// (vcl)
#include <Vcl.Buttons.hpp>	// (vcl)
#include <Vcl.ExtDlgs.hpp>	// (vcl)
#include <GLS.Utils.hpp>	// (GLScene_RT)
#include <GLS.PersistentClasses.hpp>	// (GLScene_RT)
#include <GLS.VectorLists.hpp>	// (GLScene_RT)
#include <Vcl.Imaging.JConsts.hpp>	// (vclimg)
#include <Vcl.Imaging.jpeg.hpp>	// (vclimg)
#include <Vcl.Imaging.pnglang.hpp>	// (vclimg)
#include <Vcl.Imaging.pngimage.hpp>	// (vclimg)
#include <GLS.BaseClasses.hpp>	// (GLScene_RT)
#include <GLS.Logger.hpp>	// (GLScene_RT)
#include <GLS.OpenGLAdapter.hpp>	// (GLScene_RT)
#include <GLS.XOpenGL.hpp>	// (GLScene_RT)
#include <GLS.PipelineTransformation.hpp>	// (GLScene_RT)
#include <GLS.Context.hpp>	// (GLScene_RT)
#include <GLS.TextureFormat.hpp>	// (GLScene_RT)
#include <GLS.Color.hpp>	// (GLScene_RT)
#include <GLS.State.hpp>	// (GLScene_RT)
#include <GLS.ApplicationFileIO.hpp>	// (GLScene_RT)
#include <GLS.ImageUtils.hpp>	// (GLScene_RT)
#include <GLS.Graphics.hpp>	// (GLScene_RT)
#include <GLS.Coordinates.hpp>	// (GLScene_RT)
#include <GLS.RenderContextInfo.hpp>	// (GLScene_RT)
#include <GLS.XCollection.hpp>	// (GLScene_RT)
#include <GLS.Silhouette.hpp>	// (GLScene_RT)
#include <GLS.GeometryBB.hpp>	// (GLScene_RT)
#include <GLS.Material.hpp>	// (GLScene_RT)
#include <GLS.Selection.hpp>	// (GLScene_RT)
#include <GLS.Scene.hpp>	// (GLScene_RT)
#include <GLS.Texture.hpp>	// (GLScene_RT)
#include <GLS.Cadencer.hpp>	// (GLScene_RT)
#include <GLSL.ShaderParameter.hpp>	// (GLScene_RT)
#include <GLSL.CustomShader.hpp>	// (GLScene_RT)
// PRG_EXT: .bpl
// BPI_DIR: ..\lib\Win64
// OBJ_DIR: ..\lib\Win64
// OBJ_EXT: .o

//-- user supplied -----------------------------------------------------------

namespace Glscene_cg_rt
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
}	/* namespace Glscene_cg_rt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLSCENE_CG_RT)
using namespace Glscene_cg_rt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Glscene_cg_rtHPP
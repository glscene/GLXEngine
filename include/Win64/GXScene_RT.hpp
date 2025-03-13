// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GXScene_RT.dpk' rev: 36.00 (Windows)

#ifndef GXScene_RTHPP
#define GXScene_RTHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>	// (rtl)
#include <SysInit.hpp>
#include <Formatx.DDSImage.hpp>
#include <Formatx.HDRImage.hpp>
#include <Formatx.TGA.hpp>
#include <GXS.AnimatedSprite.hpp>
#include <GXS.ApplicationFileIO.hpp>
#include <GXS.ArchiveManager.hpp>
#include <GXS.AsyncHDS.hpp>
#include <GXS.AsyncTimer.hpp>
#include <GXS.Atmosphere.hpp>
#include <GXS.AVIRecorder.hpp>
#include <GXS.BaseClasses.hpp>
#include <GXS.BSP.hpp>
#include <GXS.BaseMeshSilhouette.hpp>
#include <GXS.Behaviours.hpp>
#include <GXS.BitmapFont.hpp>
#include <GXS.Blur.hpp>
#include <GXS.BumpMapping.hpp>
#include <GXS.BumpmapHDS.hpp>
#include <GXS.Cadencer.hpp>
#include <GXS.CameraController.hpp>
#include <GXS.Canvas.hpp>
#include <GXS.CelShader.hpp>
#include <GXS.Collision.hpp>
#include <GXS.CompositeImage.hpp>
#include <GXS.Coordinates.hpp>
#include <GXS.Console.hpp>
#include <GXS.Context.hpp>
#include <GXS.DCE.hpp>
#include <GXS.DCEMisc.hpp>
#include <GXS.EParticleMasksManager.hpp>
#include <GXS.EllipseCollision.hpp>
#include <GXS.ExplosionFx.hpp>
#include <GXS.Extrusion.hpp>
#include <GXS.FBO.hpp>
#include <GXS.FBORenderer.hpp>
#include <GXS.FPSMovement.hpp>
#include <GXS.Feedback.hpp>
#include <GXS.FileASE.hpp>
#include <GXS.File3DS.hpp>
#include <GXS.File3DSSceneObjects.hpp>
#include <GXS.FileB3D.hpp>
#include <GXS.FileBMP.hpp>
#include <GXS.FileGRD.hpp>
#include <GXS.FileGTS.hpp>
#include <GXS.FileDDS.hpp>
#include <GXS.FileDXF.hpp>
#include <GXS.FileHDR.hpp>
#include <GXS.FileGLTF.hpp>
#include <GXS.FileJPEG.hpp>
#include <GXS.FileLMTS.hpp>
#include <GXS.FileLWO.hpp>
#include <GXS.FileMD3.hpp>
#include <GXS.FileMD5.hpp>
#include <GXS.FileMDC.hpp>
#include <GXS.FileMP3.hpp>
#include <GXS.FileMS3D.hpp>
#include <GXS.FileNMF.hpp>
#include <GXS.FileNurbs.hpp>
#include <GXS.FileOBJ.hpp>
#include <GXS.FileOCT.hpp>
#include <GXS.FilePLY.hpp>
#include <GXS.FilePNG.hpp>
#include <GXS.FileQ3BSP.hpp>
#include <GXS.FileSMD.hpp>
#include <GXS.FileSTL.hpp>
#include <GXS.FileTGA.hpp>
#include <GXS.FileTIN.hpp>
#include <GXS.FileVRML.hpp>
#include <GXS.FileWAV.hpp>
#include <GXS.FileX.hpp>
#include <GXS.FireFX.hpp>
#include <GXS.FullScreenViewer.hpp>
#include <GXS.PolygonTesselation.hpp>
#include <GXS.GameMenu.hpp>
#include <GXS.GeomObjects.hpp>
#include <GXS.Gizmo.hpp>
#include <GXS.GizmoEx.hpp>
#include <GXS.Graph.hpp>
#include <GXS.Graphics.hpp>
#include <GXS.Gui.hpp>
#include <GXS.DynamicTexture.hpp>
#include <GXS.HUDObjects.hpp>
#include <GXS.HeightData.hpp>
#include <GXS.HeightTileFile.hpp>
#include <GXS.HeightTileFileHDS.hpp>
#include <GXS.HiddenLineShader.hpp>
#include <GXS.ImageUtils.hpp>
#include <GXS.Imposter.hpp>
#include <GXS.Isolines.hpp>
#include <GXS.Isosurface.hpp>
#include <GXS.Joystick.hpp>
#include <GXS.LensFlare.hpp>
#include <GXS.LinePFX.hpp>
#include <GXS.Material.hpp>
#include <GXS.MaterialMultiProxy.hpp>
#include <GXS.MaterialScript.hpp>
#include <GXS.Mesh.hpp>
#include <GXS.MeshBuilder.hpp>
#include <GXS.MeshCSG.hpp>
#include <GXS.MeshLines.hpp>
#include <GXS.MeshOptimizer.hpp>
#include <GXS.MeshUtils.hpp>
#include <GXS.Mirror.hpp>
#include <GXS.Movement.hpp>
#include <GXS.MultiMaterialShader.hpp>
#include <GXS.MultiPolygon.hpp>
#include <GXS.MultiProxy.hpp>
#include <GXS.MultisampleImage.hpp>
#include <GXS.Navigator.hpp>
#include <GXS.Nodes.hpp>
#include <GXS.ObjectManager.hpp>
#include <GXS.Objects.hpp>
#include <GXS.Octree.hpp>
#include <GXS.OpenGLAdapter.hpp>
#include <GXS.InitOpenGL.hpp>
#include <GXS.OutlineShader.hpp>
#include <GXS.ParametricSurfaces.hpp>
#include <GXS.ParticleFX.hpp>
#include <GXS.Particles.hpp>
#include <GXS.Perlin.hpp>
#include <GXS.PerlinPFX.hpp>
#include <GXS.PictureRegisteredFormats.hpp>
#include <GXS.Portal.hpp>
#include <GXSL.PostEffects.hpp>
#include <GXS.ProcTextures.hpp>
#include <GXS.ProjectedTextures.hpp>
#include <GXS.ProxyObjects.hpp>
#include <GXS.ROAMPatch.hpp>
#include <GXS.Ragdoll.hpp>
#include <GXS.RandomHDS.hpp>
#include <GXS.RenderContextInfo.hpp>
#include <GXS.Scene.hpp>
#include <GXS.WinContext.hpp>
#include <GXS.SceneViewer.hpp>
#include <GXS.Screen.hpp>
#include <GXS.ScreenSaver.hpp>
#include <GXS.Selection.hpp>
#include <GXS.ShadowHDS.hpp>
#include <GXS.ShadowPlane.hpp>
#include <GXS.ShadowVolume.hpp>
#include <GXS.Silhouette.hpp>
#include <GXS.SimpleNavigation.hpp>
#include <GXS.Skydome.hpp>
#include <GXS.SmoothNavigator.hpp>
#include <GXS.SoundManager.hpp>
#include <GXS.SoundFileObjects.hpp>
#include <GXS.SpaceText.hpp>
#include <GXS.SpatialPartitioning.hpp>
#include <GXS.State.hpp>
#include <GXS.TerrainRenderer.hpp>
#include <GXS.TexLensFlare.hpp>
#include <GXS.Texture.hpp>
#include <GXS.TextureCombiners.hpp>
#include <GXS.TextureImageEditors.hpp>
#include <GXS.TexturedHDS.hpp>
#include <GXS.ThorFX.hpp>
#include <GXS.TilePlane.hpp>
#include <GXS.TimeEventsMgr.hpp>
#include <GXS.Trail.hpp>
#include <GXS.Tree.hpp>
#include <GXS.VectorFileObjects.hpp>
#include <GXS.VerletClothify.hpp>
#include <GXS.VerletTypes.hpp>
#include <GXS.WaterPlane.hpp>
#include <GXS.Windows.hpp>
#include <GXS.WindowsFont.hpp>
#include <GXS.zBuffer.hpp>
#include <GXS.PAKArchive.hpp>
#include <GXS.SpacePartition.hpp>
#include <GXS.XOpenGL.hpp>
#include <GXS.ViewerOpenGL.hpp>
#include <GXSL.AsmShader.hpp>
#include <GXSL.BumpShaders.hpp>
#include <GXSL.CustomShader.hpp>
#include <GXSL.DiffuseSpecularShader.hpp>
#include <GXSL.PhongShader.hpp>
#include <GXSL.PostShaders.hpp>
#include <GXSL.ProjectedTextures.hpp>
#include <GXSL.Shader.hpp>
#include <GXSL.ShaderCombiner.hpp>
#include <GXSL.TextureShaders.hpp>
#include <GXSL.Parameter.hpp>
#include <GXSL.UserShader.hpp>
#include <GXSL.ShaderParameter.hpp>
#include <GXSL.ShapeShaders.hpp>
#include <GXSL.LineShaders.hpp>
#include <GXSL.MultiMaterialShader.hpp>
#include <GXS.ScriptBase.hpp>
#include <GXS.SmartObjects.hpp>
#include <GXS.CyborgManager.hpp>
#include <GXS.PersistentClasses.hpp>
#include <GXS.VectorLists.hpp>
#include <GXS.Color.hpp>
#include <GXS.CurvesAndSurfaces.hpp>
#include <GXS.GeometryBB.hpp>
#include <GXS.XCollection.hpp>
#include <Formatx.DXTC.hpp>
#include <Formatx.VFW.hpp>
#include <Formatx.m3DS.hpp>
#include <Formatx.m3DSConst.hpp>
#include <Formatx.m3DSTypes.hpp>
#include <Formatx.m3DSUtils.hpp>
#include <Formatx.MD3.hpp>
#include <Formatx.MD2.hpp>
#include <Formatx.LWO.hpp>
#include <Formatx.OCT.hpp>
#include <Formatx.Q3BSP.hpp>
#include <Formatx.X.hpp>
#include <Formatx.VRML.hpp>
#include <Formatx.Q3MD3.hpp>
#include <Formatx.B3D.hpp>
#include <gnugettext.hpp>
#include <GnuGetTextInit.hpp>
#include <PasDblStrUtils.hpp>
#include <PasGLTF.hpp>
#include <PasJSON.hpp>
#include <Stage.AnimationUtils.hpp>
#include <Stage.Generics.hpp>
#include <Stage.Keyboard.hpp>
#include <Stage.Logger.hpp>
#include <Stage.Manager.hpp>
#include <Stage.OpenGL4.hpp>
#include <Stage.OpenGLTokens.hpp>
#include <Stage.PipelineTransform.hpp>
#include <Stage.Polynomials.hpp>
#include <Stage.RandomLib.hpp>
#include <Stage.RedBlackTree.hpp>
#include <Stage.RGBE.hpp>
#include <Stage.Spline.hpp>
#include <Stage.Strings.hpp>
#include <Stage.TextureFormat.hpp>
#include <Stage.Triangulation.hpp>
#include <Stage.Utils.hpp>
#include <Stage.VectorGeometry.hpp>
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorTypesExt.hpp>
#include <System.Types.hpp>	// (rtl)
#include <System.UITypes.hpp>	// (rtl)
#include <Winapi.Windows.PkgHelper.hpp>	// (rtl)
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
#include <Winapi.OpenGL.PkgHelper.hpp>	// (rtl)
#include <Winapi.OpenGL.hpp>	// (rtl)
#include <Winapi.Messages.hpp>	// (rtl)
#include <System.VarUtils.hpp>	// (rtl)
#include <System.Variants.hpp>	// (rtl)
#include <Winapi.ActiveX.hpp>	// (rtl)
#include <System.TypInfo.hpp>	// (rtl)
#include <System.Hash.hpp>	// (rtl)
#include <System.Generics.Defaults.hpp>	// (rtl)
#include <System.Generics.Collections.hpp>	// (rtl)
#include <System.TimeSpan.hpp>	// (rtl)
#include <System.Diagnostics.hpp>	// (rtl)
#include <System.SyncObjs.hpp>	// (rtl)
#include <System.Rtti.hpp>	// (rtl)
#include <System.Classes.hpp>	// (rtl)
#include <System.Messaging.hpp>	// (rtl)
#include <System.Math.Vectors.hpp>	// (rtl)
#include <System.Actions.hpp>	// (rtl)
#include <System.ImageList.hpp>	// (rtl)
#include <FMX.Consts.hpp>	// (fmx)
#include <System.Win.Devices.hpp>	// (rtl)
#include <System.Devices.hpp>	// (rtl)
#include <System.Analytics.hpp>	// (rtl)
#include <System.UIConsts.hpp>	// (rtl)
#include <FMX.BehaviorManager.hpp>	// (fmx)
#include <FMX.Styles.hpp>	// (fmx)
#include <FMX.VirtualKeyboard.hpp>	// (fmx)
#include <System.StrUtils.hpp>	// (rtl)
#include <System.AnsiStrings.hpp>	// (rtl)
#include <System.Win.Crtl.hpp>	// (rtl)
#include <System.RegularExpressionsAPI.hpp>	// (rtl)
#include <System.RegularExpressionsConsts.hpp>	// (rtl)
#include <System.RegularExpressionsCore.hpp>	// (rtl)
#include <System.RegularExpressions.hpp>	// (rtl)
#include <FMX.Utils.hpp>	// (fmx)
#include <FMX.Text.hpp>	// (fmx)
#include <FMX.TextLayout.hpp>	// (fmx)
#include <FMX.Materials.hpp>	// (fmx)
#include <FMX.Surfaces.hpp>	// (fmx)
#include <FMX.Types3D.hpp>	// (fmx)
#include <FMX.Filter.hpp>	// (fmx)
#include <FMX.Filter.Custom.hpp>	// (fmx)
#include <FMX.Effects.hpp>	// (fmx)
#include <FMX.MultiResBitmap.hpp>	// (fmx)
#include <FMX.Ani.hpp>	// (fmx)
#include <FMX.AcceleratorKey.hpp>	// (fmx)
#include <Winapi.CommCtrl.hpp>	// (rtl)
#include <Winapi.Qos.hpp>	// (rtl)
#include <Winapi.Winsock2.hpp>	// (rtl)
#include <Winapi.IpExport.hpp>	// (rtl)
#include <Winapi.ShellAPI.hpp>	// (rtl)
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
#include <System.DateUtils.hpp>	// (rtl)
#include <System.IOUtils.hpp>	// (rtl)
#include <FMX.ImgList.hpp>	// (fmx)
#include <Winapi.DxgiFormat.hpp>	// (rtl)
#include <Winapi.Wincodec.hpp>	// (rtl)
#include <Winapi.MultiMon.hpp>	// (rtl)
#include <Winapi.DXTypes.hpp>	// (rtl)
#include <Winapi.DxgiType.hpp>	// (rtl)
#include <Winapi.DXGI.hpp>	// (rtl)
#include <Winapi.D3DCommon.hpp>	// (rtl)
#include <Winapi.D2D1.hpp>	// (rtl)
#include <Winapi.UxTheme.hpp>	// (rtl)
#include <FMX.DialogService.Sync.hpp>	// (fmx)
#include <FMX.Dialogs.hpp>	// (fmx)
#include <FMX.DialogService.hpp>	// (fmx)
#include <FMX.Menus.hpp>	// (fmx)
#include <Winapi.Imm.hpp>	// (rtl)
#include <Winapi.MsCTF.PkgHelper.hpp>	// (rtl)
#include <System.Win.ComConst.hpp>	// (rtl)
#include <System.Win.ComObj.hpp>	// (rtl)
#include <Winapi.MsCTF.hpp>	// (rtl)
#include <Winapi.ShellScaling.hpp>	// (rtl)
#include <FMX.Helpers.Win.hpp>	// (fmx)
#include <FMX.FontGlyphs.Win.hpp>	// (fmx)
#include <FMX.FontGlyphs.hpp>	// (fmx)
#include <FMX.Objects.hpp>	// (fmx)
#include <Winapi.TpcShrd.hpp>	// (rtl)
#include <Winapi.MsInkAut.hpp>	// (rtl)
#include <Winapi.Manipulations.hpp>	// (rtl)
#include <Winapi.RtsCom.hpp>	// (rtl)
#include <FMX.ZOrder.hpp>	// (fmx)
#include <FMX.ZOrder.Win.hpp>	// (fmx)
#include <System.IniFiles.hpp>	// (rtl)
#include <System.Win.Registry.hpp>	// (rtl)
#include <Winapi.CommDlg.hpp>	// (rtl)
#include <Winapi.MMSystem.hpp>	// (rtl)
#include <FMX.MediaLibrary.hpp>	// (fmx)
#include <Winapi.WinSpool.hpp>	// (rtl)
#include <Winapi.DirectDraw.hpp>	// (rtl)
#include <Winapi.GDIPAPI.hpp>	// (rtl)
#include <Winapi.GDIPOBJ.hpp>	// (rtl)
#include <Winapi.GDIPUTIL.hpp>	// (rtl)
#include <FMX.FontManager.hpp>	// (fmx)
#include <Winapi.D3D10.hpp>	// (rtl)
#include <Winapi.D3D10_1.hpp>	// (rtl)
#include <FMX.Canvas.D2D.hpp>	// (fmx)
#include <FMX.FontManager.Win.hpp>	// (fmx)
#include <FMX.Canvas.GDIP.hpp>	// (fmx)
#include <FMX.Printer.Win.hpp>	// (fmx)
#include <FMX.Printer.hpp>	// (fmx)
#include <FMX.StdActns.hpp>	// (fmx)
#include <FMX.Presentation.Messages.hpp>	// (fmx)
#include <FMX.Controls.Model.hpp>	// (fmx)
#include <FMX.Presentation.Factory.hpp>	// (fmx)
#include <FMX.Presentation.Style.hpp>	// (fmx)
#include <FMX.Controls.Win.hpp>	// (fmx)
#include <FMX.Presentation.Win.hpp>	// (fmx)
#include <FMX.Presentation.Style.Common.hpp>	// (fmx)
#include <FMX.Presentation.Win.Style.hpp>	// (fmx)
#include <FMX.Controls.Presentation.hpp>	// (fmx)
#include <FMX.Styles.Objects.hpp>	// (fmx)
#include <FMX.Styles.Switch.hpp>	// (fmx)
#include <FMX.Switch.Style.hpp>	// (fmx)
#include <FMX.Platform.Metrics.hpp>	// (fmx)
#include <FMX.Switch.Win.hpp>	// (fmx)
#include <FMX.StdCtrls.hpp>	// (fmx)
#include <FMX.InertialMovement.hpp>	// (fmx)
#include <FMX.Layouts.hpp>	// (fmx)
#include <FMX.Clipboard.Win.hpp>	// (fmx)
#include <FMX.Clipboard.hpp>	// (fmx)
#include <FMX.Text.UndoManager.hpp>	// (fmx)
#include <FMX.ScrollBox.Win.hpp>	// (fmx)
#include <FMX.ScrollBox.hpp>	// (fmx)
#include <FMX.ScrollBox.Style.hpp>	// (fmx)
#include <FMX.Text.LinesLayout.hpp>	// (fmx)
#include <FMX.Text.SelectionController.hpp>	// (fmx)
#include <FMX.Text.AutoscrollController.hpp>	// (fmx)
#include <FMX.SpellChecker.hpp>	// (fmx)
#include <FMX.Text.SpellingManager.hpp>	// (fmx)
#include <FMX.Text.IMERender.hpp>	// (fmx)
#include <FMX.Text.TextEditor.hpp>	// (fmx)
#include <FMX.MagnifierGlass.hpp>	// (fmx)
#include <FMX.Text.InteractiveSelectors.hpp>	// (fmx)
#include <FMX.Edit.Style.New.hpp>	// (fmx)
#include <FMX.Edit.Win.hpp>	// (fmx)
#include <FMX.Edit.hpp>	// (fmx)
#include <FMX.Dialogs.Default.hpp>	// (fmx)
#include <FMX.DialogHelper.hpp>	// (fmx)
#include <FMX.Dialogs.Win.hpp>	// (fmx)
#include <Winapi.Direct3D9.hpp>	// (rtl)
#include <FMX.Materials.Canvas.hpp>	// (fmx)
#include <FMX.Canvas.GPU.Helpers.hpp>	// (fmx)
#include <FMX.TextLayout.GPU.hpp>	// (fmx)
#include <FMX.StrokeBuilder.hpp>	// (fmx)
#include <FMX.Canvas.GPU.hpp>	// (fmx)
#include <FMX.Context.DX9.hpp>	// (fmx)
#include <Winapi.D3D11.hpp>	// (rtl)
#include <FMX.Context.DX11.hpp>	// (fmx)
#include <FMX.Forms.Border.hpp>	// (fmx)
#include <FMX.Forms.Border.Win.hpp>	// (fmx)
#include <FMX.MultiTouch.hpp>	// (fmx)
#include <FMX.MultiTouch.Win.hpp>	// (fmx)
#include <System.Win.StdVCL.hpp>	// (rtl)
#include <System.Win.OleControls.hpp>	// (rtl)
#include <System.Win.OleServers.hpp>	// (rtl)
#include <System.Win.InternetExplorer.hpp>	// (rtl)
#include <System.Win.IEInterfaces.hpp>	// (rtl)
#include <Winapi.WebView2.hpp>	// (rtl)
#include <Winapi.EdgeUtils.hpp>	// (rtl)
#include <FMX.Controls.Ole.hpp>	// (fmx)
#include <FMX.WebBrowser.Win.hpp>	// (fmx)
#include <FMX.WebBrowser.hpp>	// (fmx)
#include <FMX.KeyMapping.hpp>	// (fmx)
#include <FMX.AcceleratorKey.Win.hpp>	// (fmx)
#include <FMX.Platform.Screen.Win.hpp>	// (fmx)
#include <FMX.Platform.SaveState.Win.hpp>	// (fmx)
#include <FMX.Platform.Device.Win.hpp>	// (fmx)
#include <FMX.Platform.Metrics.Win.hpp>	// (fmx)
#include <FMX.ListBox.Selection.hpp>	// (fmx)
#include <FMX.ListBox.hpp>	// (fmx)
#include <FMX.DateTimeCtrls.Types.hpp>	// (fmx)
#include <FMX.DateTimeCtrls.hpp>	// (fmx)
#include <FMX.ExtCtrls.hpp>	// (fmx)
#include <FMX.Calendar.Style.hpp>	// (fmx)
#include <FMX.Calendar.hpp>	// (fmx)
#include <FMX.Pickers.Default.hpp>	// (fmx)
#include <FMX.Pickers.hpp>	// (fmx)
#include <FMX.VirtualKeyboard.Win.hpp>	// (fmx)
#include <FMX.Platform.Timer.Win.hpp>	// (fmx)
#include <FMX.Platform.Logger.Win.hpp>	// (fmx)
#include <FMX.Platform.Menu.Win.hpp>	// (fmx)
#include <FMX.Platform.Win.hpp>	// (fmx)
#include <FMX.Gestures.Win.hpp>	// (fmx)
#include <FMX.Gestures.hpp>	// (fmx)
#include <FMX.Controls.hpp>	// (fmx)
#include <FMX.Header.hpp>	// (fmx)
#include <FMX.Forms.hpp>	// (fmx)
#include <FMX.Platform.Common.hpp>	// (fmx)
#include <FMX.Platform.hpp>	// (fmx)
#include <FMX.ActnList.hpp>	// (fmx)
#include <FMX.Types.hpp>	// (fmx)
#include <FMX.Graphics.hpp>	// (fmx)
#include <Winapi.OpenGLext.hpp>	// (rtl)
#include <FMX.Controls3D.hpp>	// (fmx)
#include <FMX.MaterialSources.hpp>	// (fmx)
#include <FMX.Import.hpp>	// (fmx)
#include <FMX.Objects3D.hpp>	// (fmx)
#include <FMX.Viewport3D.hpp>	// (fmx)
#include <System.Contnrs.hpp>	// (rtl)
#include <FMX.Memo.Types.hpp>	// (fmx)
#include <FMX.Memo.Style.New.hpp>	// (fmx)
#include <FMX.Memo.Win.hpp>	// (fmx)
#include <FMX.Memo.hpp>	// (fmx)
// PRG_EXT: .bpl
// BPI_DIR: ..\lib\Win64
// OBJ_DIR: ..\lib\Win64
// OBJ_EXT: .o

//-- user supplied -----------------------------------------------------------

namespace Gxscene_rt
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
}	/* namespace Gxscene_rt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GXSCENE_RT)
using namespace Gxscene_rt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GXScene_RTHPP

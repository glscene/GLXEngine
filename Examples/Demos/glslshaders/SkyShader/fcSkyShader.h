//---------------------------------------------------------------------------

#ifndef fcSkyShaderH
#define fcSkyShaderH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "GLS.BaseClasses.hpp"
#include "GLS.Cadencer.hpp"
#include "GLS.Coordinates.hpp"
#include "GLS.GeomObjects.hpp"
#include "GLS.Objects.hpp"
#include "GLS.Texture.hpp"
#include "GLS.Scene.hpp"
#include "GLS.SceneViewer.hpp"
//---------------------------------------------------------------------------
class TFormSkyShader : public TForm
{
__published:	// IDE-managed Components
	TGLSceneViewer *SceneViewer;
	TGLScene *GLScene1;
	TGLDummyCube *DummyCam;
	TGLCamera *Camera;
	TGLDirectOpenGL *DirectOGL;
	TGLTorus *Thor;
	TGLSphere *Sphere;
	TGLSphere *Sky;
	TGLCadencer *Cadencer;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TFileName Path;
	TGLProgramHandle *GLSL_Sky;
	TGLProgramHandle *GLSL_Obj;
	TGLTexture *Cubemap;
	__fastcall TFormSkyShader(TComponent* Owner);
	void __fastcall LoadCubemap();

};
//---------------------------------------------------------------------------
extern PACKAGE TFormSkyShader *FormSkyShader;
//---------------------------------------------------------------------------
#endif

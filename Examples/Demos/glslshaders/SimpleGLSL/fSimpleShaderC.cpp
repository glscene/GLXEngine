//--------------------------------------------------------------
#include <sysutils.hpp>
#include <math.h>
#include <vcl.h>

#pragma hdrstop

#include "fSimpleShaderC.h"

#include "Stage.Keyboard.hpp"
#include "GLS.Context.hpp"
#include "GLS.File3DS.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Stage.OpenGLTokens"
#pragma link "Stage.Keyboard"
#pragma link "GLS.OpenGLAdapter"
#pragma link "GLS.BitmapFont"
#pragma link "GLS.Cadencer"
#pragma link "GLS.GeomObjects"
#pragma link "GLS.HUDObjects"
#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.Texture"
#pragma link "GLSL.UserShader"
#pragma link "GLS.VectorFileObjects"
#pragma link "GLS.SceneViewer"
#pragma link "GLS.WindowsFont"
#pragma link "GLS.Context"
#pragma link "GLS.File3DS"

#pragma link "GLS.BaseClasses"
#pragma link "GLS.Coordinates"

#pragma link "GLS.Material"
#pragma link "GLS.SimpleNavigation"
#pragma resource "*.dfm"

TForm1* Form1;
int CurrShader = 0;
AnsiString CurrShaderName = "Blinn";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject* Sender)
{
    Path = GetCurrentAssetPath();

    // Loading static models
    SetCurrentDir(Path + "\\model");
    GLFreeForm1->LoadFromFile("teapot.3ds");

    // Then loading textures.
    SetCurrentDir(Path + "\\texture");
    MatLib->LibMaterialByName("Brick01")
        ->Material->Texture->Image->LoadFromFile("mur_NormalMap.bmp");
    MatLib->LibMaterialByName("Brick02")
        ->Material->Texture->Image->LoadFromFile("mur_Ambiant.bmp");
    MatLib->LibMaterialByName("Brick03")
        ->Material->Texture->Image->LoadFromFile("mur_Hauteur.bmp");

    ShaderActived = false;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::GLCadencer1Progress(
    TObject* Sender, const double deltaTime, const double newTime)
{
    if (IsKeyDown('1')) {
        CurrShaderName = "Blinn";
        CurrShader = 0;
    } else if (IsKeyDown('2')) {
        CurrShaderName = "Lambert";
        CurrShader = 1;
    } else if (IsKeyDown('3')) {
		CurrShaderName = "Phong";
        CurrShader = 2;
    } else if (IsKeyDown('4')) {
        CurrShaderName = "Rim";
        CurrShader = 3;
    } else if (IsKeyDown('5')) {
        CurrShaderName = "SharpSpecular";
        CurrShader = 4;
    } else if (IsKeyDown('6')) {
        CurrShaderName = "Sheen";
        CurrShader = 5;
    } else if (IsKeyDown('7')) {
        CurrShaderName = "ThinPlastic";
        CurrShader = 6;
    } else if (IsKeyDown('8')) {
        CurrShaderName = "Velvet";
        CurrShader = 7;
    }
    if (IsKeyDown('9')) {
        CurrShaderName = "TEST TEXTURE BUMP";
		CurrShader = 7;  // was 8
	}
	if (IsKeyDown('0')) {
		CurrShaderName = "TEST Toon";
		CurrShader = 7;  // was 9
    }
    if (CurrShader != 8) {
        DummyLight->Position->X = sin(DegToRad(newTime * 15)) * 65;
        DummyLight->Position->Z = sin(DegToRad(newTime * 15)) * 65;
    }
    GLSceneViewer1->Invalidate();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::GLUserShader1DoApply(
    TObject* Sender, TGLRenderContextInfo &rci)
{
    TVector3f vec, VecCol1, VecCol2;
    TGLLibMaterial* libMat;

    GLSLProg[CurrShader]->UseProgramObject();

    if ((CurrShader != 8) && (CurrShader != 9))
        GLSLProg[CurrShader]->Uniform4f["light"] = Light->AbsolutePosition;
    if ((CurrShader == 8)) {
        // initialize the heightmap
        libMat = MatLib->LibMaterialByName("Brick01");
        {
            libMat->PrepareBuildList();
            glActiveTextureARB(GL_TEXTURE0_ARB);
            glBindTexture(GL_TEXTURE_2D, libMat->Material->Texture->Handle);
            GLSLProg[CurrShader]->Uniform1i["Normal"] = 0;
            glActiveTextureARB(GL_TEXTURE0_ARB);
        }
        libMat = MatLib->LibMaterialByName("Brick02");
        {
            libMat->PrepareBuildList();
            glActiveTextureARB(GL_TEXTURE1_ARB);
            glBindTexture(GL_TEXTURE_2D, libMat->Material->Texture->Handle);
            GLSLProg[CurrShader]->Uniform1i["base_tex"] = 1;
            glActiveTextureARB(GL_TEXTURE0_ARB);
        }
        libMat = MatLib->LibMaterialByName("Brick03");
        {
			libMat->PrepareBuildList();
            glActiveTextureARB(GL_TEXTURE2_ARB);
            glBindTexture(GL_TEXTURE_2D, libMat->Material->Texture->Handle);
            GLSLProg[CurrShader]->Uniform1i["Base_Height"] = 2;
            glActiveTextureARB(GL_TEXTURE0_ARB);
        }
        GLSLProg[CurrShader]->Uniform1f["u_invRad"] = 0.001;
        vec.X = 0.42200005;
        vec.Y = -0.04999996;
        vec.Z = 0;
        GLSLProg[CurrShader]->Uniform3f["cBumpSize"] = vec;
    }
    if ((CurrShader == 9)) {
        VecCol1.X = 0.5;
        VecCol1.Y = 0.25;
        VecCol1.Z = 0.2;
        GLSLProg[CurrShader]->Uniform3f["DiffuseColor"] = VecCol1;
        VecCol2.X = 0.95;
        VecCol2.Y = 0.45;
        VecCol2.Z = 0.3;
        GLSLProg[CurrShader]->Uniform3f["PhongColor"] = VecCol2;
        GLSLProg[CurrShader]->Uniform1f["Edge"] = 0.25;
        GLSLProg[CurrShader]->Uniform1f["Phong"] = 0.5540001;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GLUserShader1DoUnApply(
    TObject* Sender, int Pass, TGLRenderContextInfo &rci, bool &Continue)
{
    GLSLProg[CurrShader]->EndUseProgramObject();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject* Sender)
{
    Caption = Format("Simple GLSL Shader [%.2f FPS]",
        ARRAYOFCONST((GLSceneViewer1->FramesPerSecond())));
    GLHUDText1->Text =
        "Stage.Keyboard [1,2,3,4,5,6,7,8,9,0 ] Current Shader: " + CurrShaderName;
    GLSceneViewer1->ResetPerformanceMonitor();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GLSceneViewer1MouseDown(
    TObject* Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    mx = X;
    my = Y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GLSceneViewer1MouseMove(
    TObject* Sender, TShiftState Shift, int X, int Y)
{
    if (Shift.Contains(ssRight))
        Cam->MoveAroundTarget(my - Y, mx - X);
    mx = X;
    my = Y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject* Sender, TCloseAction &Action)
{
    GLCadencer1->Enabled = false;
    Timer1->Enabled = false;
    ShaderActived = false;
    for (int i = 0; i < MAXSHADERS; i++) {
        GLSLProg[i]->Free();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheel(TObject* Sender, TShiftState Shift,
    int WheelDelta, TPoint &MousePos, bool &Handled)
{
    Cam->AdjustDistanceToTarget(Power(1.1, WheelDelta / 120));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GLDOInitializeRender(
    TObject* Sender, TGLRenderContextInfo &rci)
{
    bool Continue;
    if (!ShaderActived) /// Should be (! ShaderActived)
    {
        if (!((GL_SHADER_OBJECT_ARB) && (GL_VERTEX_PROGRAM_ARB) &&
                (GL_VERTEX_SHADER_ARB) && (GL_FRAGMENT_SHADER_ARB)))
        {
            ShowMessage(
                "Your hardware does not support GLSL to execute this demo!");
            //	  return (void) NULL; <- It's not necessary
        }

        // Loading shaders
        SetCurrentDir(Path + "\\shader");
        //Blinn Shader
        GLSLProg[0] = new TGLProgramHandle(true);
        GLSLProg[0]->AddShader(__classid(TGLVertexShaderHandle),
            LoadAnsiStringFromFile("vertex.glsl"), true);
        GLSLProg[0]->AddShader(__classid(TGLFragmentShaderHandle),
            LoadAnsiStringFromFile("blinn.glsl"), true);
		//Lambert Shader
        GLSLProg[1] = new TGLProgramHandle(true);
        GLSLProg[1]->AddShader(__classid(TGLVertexShaderHandle),
            LoadAnsiStringFromFile("vertex.glsl"), true);
        GLSLProg[1]->AddShader(__classid(TGLFragmentShaderHandle),
            LoadAnsiStringFromFile("lambert.glsl"), true);
        //Phong Shader
        GLSLProg[2] = new TGLProgramHandle(true);
        GLSLProg[2]->AddShader(__classid(TGLVertexShaderHandle),
            LoadAnsiStringFromFile("vertex.glsl"), true);
        GLSLProg[2]->AddShader(__classid(TGLFragmentShaderHandle),
            LoadAnsiStringFromFile("phong.glsl"), true);
        //Rim Shader
        GLSLProg[3] = new TGLProgramHandle(true);
        GLSLProg[3]->AddShader(__classid(TGLVertexShaderHandle),
            LoadAnsiStringFromFile("vertex.glsl"), true);
        GLSLProg[3]->AddShader(__classid(TGLFragmentShaderHandle),
            LoadAnsiStringFromFile("rim.glsl"), true);
        //SharpSpecular Shader
        GLSLProg[4] = new TGLProgramHandle(true);
        GLSLProg[4]->AddShader(__classid(TGLVertexShaderHandle),
            LoadAnsiStringFromFile("vertex.glsl"), true);
        GLSLProg[4]->AddShader(__classid(TGLFragmentShaderHandle),
            LoadAnsiStringFromFile("sharpspecular.glsl"), true);
        //Sheen Shader
        GLSLProg[5] = new TGLProgramHandle(true);
        GLSLProg[5]->AddShader(__classid(TGLVertexShaderHandle),
            LoadAnsiStringFromFile("vertex.glsl"), true);
        GLSLProg[5]->AddShader(__classid(TGLFragmentShaderHandle),
            LoadAnsiStringFromFile("sheen.glsl"), true);
        //ThinPlastic Shader
        GLSLProg[6] = new TGLProgramHandle(true);
        GLSLProg[6]->AddShader(__classid(TGLVertexShaderHandle),
            LoadAnsiStringFromFile("vertex.glsl"), true);
        GLSLProg[6]->AddShader(__classid(TGLFragmentShaderHandle),
            LoadAnsiStringFromFile("thinplastic.glsl"), true);
        //Velvet Shader
        GLSLProg[7] = new TGLProgramHandle(true);
        GLSLProg[7]->AddShader(__classid(TGLVertexShaderHandle),
            LoadAnsiStringFromFile("vertex.glsl"), true);
        GLSLProg[7]->AddShader(__classid(TGLFragmentShaderHandle),
            LoadAnsiStringFromFile("velvet.glsl"), true);
        //TEST Texture Bump
        GLSLProg[8] = new TGLProgramHandle(true);
        GLSLProg[8]->AddShader(__classid(TGLVertexShaderHandle),
            LoadAnsiStringFromFile("bump2.vert"), true);
        GLSLProg[8]->AddShader(__classid(TGLFragmentShaderHandle),
            LoadAnsiStringFromFile("bump2.frag"), true);
        //TEST Toon
        GLSLProg[9] = new TGLProgramHandle(true);
        GLSLProg[9]->AddShader(__classid(TGLVertexShaderHandle),
            LoadAnsiStringFromFile("toon.vert"), true);
        GLSLProg[9]->AddShader(__classid(TGLFragmentShaderHandle),
            LoadAnsiStringFromFile("toon.frag"), true);

        for (int i = 0; i < MAXSHADERS; i++) {
            if (!GLSLProg[i]->LinkProgram())
                throw Exception(GLSLProg[i]->InfoLog());
            if (!GLSLProg[i]->ValidateProgram())
                throw Exception(GLSLProg[i]->InfoLog());
        }
        glGetError();
        ShaderActived = true;
    } else if (ShaderActived) {
        GLUserShader1DoApply(this, rci);
		if (CurrShader != 8) {
			glPushMatrix();
            glColor4fv(
                GLSphere1->Material->FrontProperties->Diffuse->AsAddress());
            GLSphere1->DoRender(rci, true, false);
            glPopMatrix();
            glPushMatrix();
            glTranslatef(1, 0, 0);
            glColor4fv(
                GLCone1->Material->FrontProperties->Diffuse->AsAddress());
            GLCone1->DoRender(rci, true, false);
            glPopMatrix();
            glPushMatrix();
            glTranslatef(0, -1, 0);
            glScalef(0.015, 0.015, 0.015);
            glRotatef(90, -1, 0, 0);
            glColor4fv(
                GLFreeForm1->Material->FrontProperties->Diffuse->AsAddress());
            GLFreeForm1->DoRender(rci, true, false);
            glPopMatrix();
            glPushMatrix();
            glTranslatef(-1, 0, 0);
            glColor4fv(
                GLCube1->Material->FrontProperties->Diffuse->AsAddress());
            GLCube1->DoRender(rci, true, false);
            glPopMatrix();
        } else {
            glPushMatrix();
            GLCube1->DoRender(rci, true, false);
            glPopMatrix();
        }
    }
    GLUserShader1DoUnApply(this, 0, rci, Continue);
}
//---------------------------------------------------------------------------


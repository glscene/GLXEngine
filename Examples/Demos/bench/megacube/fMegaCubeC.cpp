//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fMegaCubeC.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma link "GLS.Cadencer"
#pragma link "GLS.Coordinates"

#pragma link "GLS.Objects"
#pragma link "GLS.Scene"
#pragma link "GLS.SimpleNavigation"
#pragma link "GLS.SceneViewer"
#pragma resource "*.dfm"
TFormMegacube* FormMegacube;

const int cSize = 5;

//---------------------------------------------------------------------------
__fastcall TFormMegacube::TFormMegacube(TComponent* Owner) : TForm(Owner) {}

//---------------------------------------------------------------------------
void __fastcall TFormMegacube::FormCreate(TObject* Sender)
{
    int x, y, z;
    TGLCube* cube;
    float factor, cubeSize;

    // bench only creation and 1st render (with lists builds, etc...)
    factor = 70 / (cSize * 2 + 1);
    cubeSize = 0.4 * factor;
    for (x = -cSize; x < cSize; x++)
        for (y = -cSize; y < cSize; y++)
            for (z = -cSize; z < cSize; z++) {
                cube = (TGLCube*)(DummyCube1->AddNewChild(__classid(TGLCube)));
                cube->Position->AsVector =
                    PointMake(factor * x, factor * y, factor * z);
                cube->CubeWidth = cubeSize;
                cube->CubeHeight = cubeSize;
                cube->CubeDepth = cubeSize;
                cube->Material->FrontProperties->Diffuse->Color =
                    VectorLerp(clrYellow, clrRed,
                        (float)(x * x + y * y + z * z) / (cSize * cSize * 3));

                // uncomment following lines to stress OpenGL with more color changes calls

                //cube->Material->FrontProperties->Ambient->Color=VectorLerp(clrYellow, clrRed, (x*x+y*y+z*z)/(cSize*cSize*3));
                //cube->Material->FrontProperties->Emission->Color=VectorLerp(clrYellow, clrRed, (x*x+y*y+z*z)/(cSize*cSize*3));
                //cube->Material->FrontProperties->Specular->Color=VectorLerp(clrYellow, clrRed, (x*x+y*y+z*z)/(cSize*cSize*3));
            }
}
//---------------------------------------------------------------------------
void __fastcall TFormMegacube::GLCadencer1Progress(
    TObject* Sender, const double deltaTime, const double newTime)
{
    DummyCube1->TurnAngle = 90 * newTime; // 90� per second
}
//---------------------------------------------------------------------------


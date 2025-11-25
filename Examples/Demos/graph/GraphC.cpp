//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("points\fcPoints.cpp", FormPoints);
USEFORM("splines\fñSplines.cpp", FormSplines);
USEFORM("heightfield\fñHeightfield.cpp", FormHeightField);
USEFORM("fcGraph.cpp", FormGraph);
USEFORM("fxy\fcFxy.cpp", FormFxy);
USEFORM("projection\fcProjection.cpp", FormProjection);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormGraph), &FormGraph);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

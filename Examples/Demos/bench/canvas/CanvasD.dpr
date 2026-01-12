(* Benchmark for GLCanvas.

   This project pits TGLCanvas against TCanvas in direct mode (hardware
   acceleration should be available on both sides).
   You may usually bet on TGLCanvas being 3 to 5 times faster, but on fast 3D
   hardware, or when PenWidth is not 1, the performance ratio can reach 1:100.
   However, this is not really an apples-to-apples comparison, because GDI
   (or any other software implementations) are useless when it comes to drawing
   to an OpenGL buffer, so, this is more to show that GLCanvas is far from
   a "decelerator" if you have some 2D stuff to draw on your 3D Scene.

   Figures for PenWidth = 1, GLCanvas / GDI
   CPU         Graphics Board    Lines          Ellipses         Points       TextOut
*)
program CanvasD;

uses
  Forms,
  fdCanvas in 'fdCanvas.pas' {FormCanvas};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormCanvas, FormCanvas);
  Application.Run;
end.

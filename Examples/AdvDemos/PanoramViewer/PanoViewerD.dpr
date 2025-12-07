(*
  Simple spherical panorama viewer

  The sample input images and other resources on how to make 
  your own spherical or cylindrical panorama:
    http://www.philohome.com
    http://www.fh-furtwangen.de/~dersch/
    http://www.panoguide.com/
    http://home.no.net/dmaurer/~dersch/Index.htm
  Why IPIX patents regarding use of fisheye photos are questionable:
    http://www.worldserver.com/turk/quicktimevr/fisheye.html
*)

program PanoViewerD;

uses
  Forms,
  fdPanoViewer in 'fdPanoViewer.pas' {FormPamorama};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TFormPamorama, FormPamorama);
  Application.Run;
end.

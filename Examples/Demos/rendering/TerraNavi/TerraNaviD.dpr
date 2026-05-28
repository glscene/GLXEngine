{: Using the TOctreeSpacePartition for visibility culling.

  Demo by HRLI slightly reworked to be a quadtree demo and committed by MF.
}
program TerraNaviD;

uses
  Forms,
  fdTerraNavi in 'fdTerraNavi.pas' {FormTerraNavi};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFormTerraNavi, FormTerraNavi);
  Application.Run;
end.

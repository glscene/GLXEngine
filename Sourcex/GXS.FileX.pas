//
// The graphics engine GLXEngine. The unit of GXScene for Delphi
//
unit GXS.FileX;

(* Simple X format support for Microsoft's favorite format *)

interface

{$I Stage.Defines.inc}

uses
  System.Classes,
  System.SysUtils,

  Stage.VectorTypes,
  GXS.VectorFileObjects,
  GXS.ApplicationFileIO,
  Stage.VectorGeometry,
  GXS.Texture,
  GXS.VectorLists,
  GXS.Material,

  Formatx.X;

type
  TgxXVectorFile = class(TgxVectorFile)
  public
    class function Capabilities: TDataFileCapabilities; override;
    procedure LoadFromStream(aStream: TStream); override;
  end;

// ==========================================================
implementation
// ==========================================================

class function TgxXVectorFile.Capabilities: TDataFileCapabilities;
begin
  Result := [dfcRead];
end;

procedure TgxXVectorFile.LoadFromStream(aStream: TStream);
var
  DXFile: TDXFile;

  procedure RecursDXFile(DXNode: TDXNode);
  var
    i, j, k, l, vertcount: integer;
    mo: TgxMeshObject;
    mat: TMatrix4f;
    libmat: TgxLibMaterial;
    fg: TFGVertexNormalTexIndexList;
    str: String;
  begin
    mat := IdentityHMGMatrix;
    if Assigned(DXNode.Owner) then
      if DXNode.Owner is TDXFrame then
      begin
        mat := TDXFrame(DXNode.Owner).GlobalMatrix;
        TransposeMatrix(mat);
      end;

    if DXNode is TDXMesh then
    begin
      mo := TgxMeshObject.CreateOwned(Owner.MeshObjects);
      mo.Mode := momFaceGroups;
      mo.Vertices.Assign(TDXMesh(DXNode).Vertices);
      mo.Vertices.TransformAsPoints(mat);
      mo.Normals.Assign(TDXMesh(DXNode).Normals);
      mo.Normals.TransformAsVectors(mat);
      mo.TexCoords.Assign(TDXMesh(DXNode).TexCoords);

      if TDXMesh(DXNode).MaterialList.Count > 0 then
      begin
        // Add the materials
        if (Owner.UseMeshMaterials) and Assigned(Owner.MaterialLibrary) then
        begin
          for i := 0 to TDXMesh(DXNode).MaterialList.Count - 1 do
          begin
            str := TDXMesh(DXNode).MaterialList.Items[i].Texture;
            if FileExists(str) then
              libmat := Owner.MaterialLibrary.AddTextureMaterial('', str)
            else
              libmat := Owner.MaterialLibrary.Materials.Add;

            libmat.Name := Format('%s_%d', [DXNode.Name, i]);
            with libmat.Material.FrontProperties do
            begin
              Diffuse.Color := TDXMesh(DXNode).MaterialList.Items[i].Diffuse;
              Shininess := Round(TDXMesh(DXNode).MaterialList.Items[i]
                .SpecPower / 2);
              Specular.Color :=
                VectorMake(TDXMesh(DXNode).MaterialList.Items[i].Specular);
              Emission.Color :=
                VectorMake(TDXMesh(DXNode).MaterialList.Items[i].Emissive);
            end;
          end;
        end;

        // Add the facegroups (separate since material library
        // can be unassigned)
        for i := 0 to TDXMesh(DXNode).MaterialList.Count - 1 do
        begin
          fg := TFGVertexNormalTexIndexList.CreateOwned(mo.FaceGroups);
          fg.MaterialName := Format('%s_%d', [DXNode.Name, i]);
        end;

        // Now add the indices per material
        vertcount := 0;
        for i := 0 to TDXMesh(DXNode).VertCountIndices.Count - 1 do
        begin
          if (i < TDXMesh(DXNode).MaterialIndices.Count) then
          begin
            j := TDXMesh(DXNode).MaterialIndices[i];
            k := TDXMesh(DXNode).VertCountIndices[i];
            for l := vertcount to vertcount + k - 1 do
            begin
              TFGVertexNormalTexIndexList(mo.FaceGroups[j])
                .VertexIndices.Add(TDXMesh(DXNode).VertexIndices[l]);
              if mo.TexCoords.Count > 0 then
                TFGVertexNormalTexIndexList(mo.FaceGroups[j])
                  .TexCoordIndices.Add(TDXMesh(DXNode).VertexIndices[l]);
              if TDXMesh(DXNode).NormalIndices.Count > 0 then
                TFGVertexNormalTexIndexList(mo.FaceGroups[j])
                  .NormalIndices.Add(TDXMesh(DXNode).NormalIndices[l])
            end;
            vertcount := vertcount + k;
          end;
        end;

      end
      else
      begin
        fg := TFGVertexNormalTexIndexList.CreateOwned(mo.FaceGroups);
        fg.NormalIndices.Assign(TDXMesh(DXNode).NormalIndices);
        fg.VertexIndices.Assign(TDXMesh(DXNode).VertexIndices);
      end;

    end;

    for i := 0 to DXNode.Count - 1 do
      RecursDXFile(TDXNode(DXNode[i]));
  end;

begin
  DXFile := TDXFile.Create;
  try
    DXFile.LoadFromStream(aStream);
    RecursDXFile(DXFile.RootNode);
  finally
    DXFile.Free;
  end;
end;

initialization

RegisterVectorFileFormat('x', 'DirectX Model files', TgxXVectorFile);

end.

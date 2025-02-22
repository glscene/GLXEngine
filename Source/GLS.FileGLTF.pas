//
// The graphics engine GLXEngine. The unit of GLScene for Delphi
//
unit GLS.FileGLTF;

(* glTF/glb formats implementation. *)

interface

uses
  System.Classes,
  System.SysUtils,

  GLS.PersistentClasses,
  GLS.VectorFileObjects,
  GLS.Texture,
  GLS.ApplicationFileIO,
  Stage.VectorTypes,
  GLS.VectorLists,
  Stage.VectorGeometry,
  GLS.Material,
  Stage.Utils,
  PasGLTF;

type
  (* The glTF format is a runtime asset delivery format
    for GL APIs: WebGL, OpenGL ES OpenGL and Vulkan. *)
  TGLglTFVectorFile = class(TGLVectorFile)
  public
    class function Capabilities: TGLDataFileCapabilities; override;
    procedure LoadFromStream(aStream: TStream); override;
    procedure SaveToStream(aStream: TStream); override;
  end;


{$IFDEF USE_MULTITHREAD}
  threadvar
{$ELSE}
  var
{$ENDIF}
  glTFUseEmbeddedColors: Boolean;

// ------------------------------------------------------------------
implementation
// ------------------------------------------------------------------

// ------------------
// ------------------ TGLTFVectorFile ------------------
// ------------------


class function TGLglTFVectorFile.Capabilities: TGLDataFileCapabilities;
begin
  Result := [dfcRead, dfcWrite];
end;

procedure TGLglTFVectorFile.LoadFromStream(aStream: TStream);

  procedure AllocateMaterial(const name: String);
  var
    matLib: TGLMaterialLibrary;
  begin
    if Owner is TGLBaseMesh then
    begin
      matLib := TGLBaseMesh(GetOwner).MaterialLibrary;
      if Assigned(matLib) then
      begin
        if matLib.Materials.GetLibMaterialByName(name) = nil then
        begin
          if CompareText(name, 'null.bmp') <> 0 then
          begin
            try
              matLib.AddTextureMaterial(name, name)
            except
              on E: ETexture do
              begin
                if not Owner.IgnoreMissingTextures then
                  raise;
              end;
            end;
          end
          else
            matLib.AddTextureMaterial(name, '');
        end;
      end;
    end;
  end;

var
  i, j, k, nVert, nTex, firstFrame: Integer;
  nbBones, boneID: Integer;
  mesh: TGLSkeletonMeshObject;
  sl, tl: TStringList;
  bone: TGLSkeletonBone;
  frame: TGLSkeletonFrame;
  faceGroup: TFGVertexNormalTexIndexList;
  v: TAffineVector;

  boneIDs: TGLVertexBoneWeightDynArray;
  weightCount: Integer;
begin
  sl := TStringList.Create;
  tl := TStringList.Create;
  try
    sl.LoadFromStream(aStream);
    /// then reading glTF/GLB files to assign in TGLSkeletonMeshObject
    if sl[0] <> 'gltf' then 
      raise Exception.Create('GLB extention required');
    if sl[1] <> 'nodes' then
      raise Exception.Create('nodes not found');

(*
    if sl[1] <> 'glb' then  // needs also .bin and .png files for anim and textures 
      raise Exception.Create('GLTF extention required');
    if sl[1] <> 'nodes' then
      raise Exception.Create('nodes not found');
*)

    if sl.IndexOf('triangles') >= 0 then
    begin
      mesh := TGLSkeletonMeshObject.CreateOwned(Owner.MeshObjects);
      mesh.Mode := momFaceGroups;
    end
    else if Owner.MeshObjects.Count > 0 then
      mesh := (Owner.MeshObjects[0] as TGLSkeletonMeshObject)
    else
      raise Exception.Create('Cant load glTF with an animation');
    // read skeleton nodes
    i := 2;
    if Owner.Skeleton.RootBones.Count = 0 then
    begin
      // new bone structure
      while sl[i] <> 'end' do
      begin
        tl.CommaText := sl[i];
        with Owner.Skeleton do
          if (tl[2] <> '-1') then
            bone := TGLSkeletonBone.CreateOwned
              (RootBones.BoneByID(StrToInt(tl[2])))
          else
            bone := TGLSkeletonBone.CreateOwned(RootBones);
        if Assigned(bone) then
        begin
          bone.boneID := StrToInt(tl[0]);
          bone.name := tl[1];
        end;
        Inc(i);
      end;
    end
    else
    begin
      // animation file, skip structure
      while sl[i] <> 'end' do
        Inc(i);
    end;
	
    Inc(i);
    if sl[i] <> 'skeleton' then
      raise Exception.Create('skeleton not found');
    Inc(i);
    // read animation time frames
    nbBones := Owner.Skeleton.RootBones.BoneCount - 1;
    firstFrame := Owner.Skeleton.Frames.Count;
    while sl[i] <> 'end' do
    begin
      if Copy(sl[i], 1, 5) <> 'time ' then
        raise Exception.Create('time not found, got: ' + sl[i]);
      frame := TGLSkeletonFrame.CreateOwned(Owner.Skeleton.Frames);
      frame.name := ResourceName + ' ' + sl[i];
      Inc(i);
      while Pos(Copy(sl[i], 1, 1), ' 1234567890') > 0 do
      begin
        tl.CommaText := sl[i];
        while StrToInt(tl[0]) > frame.Position.Count do
        begin
          frame.Position.Add(NullVector);
          frame.Rotation.Add(NullVector);
        end;
        frame.Position.Add(GLStrToFloatDef(tl[1],0),
          GLStrToFloatDef(tl[2],0), GLStrToFloatDef(tl[3],0));
        v := AffineVectorMake(GLStrToFloatDef(tl[4],0),
          GLStrToFloatDef(tl[5],0), GLStrToFloatDef(tl[6],0));
        frame.Rotation.Add(v);
        Inc(i);
      end;
      while frame.Position.Count < nbBones do
      begin
        frame.Position.Add(NullVector);
        frame.Rotation.Add(NullVector);
      end;
      Assert(frame.Position.Count = nbBones, 'Invalid number of bones in frame '
        + IntToStr(Owner.Skeleton.Frames.Count));
    end;
    if Owner is TGLActor then
      with TGLActor(Owner).Animations.Add do
      begin
        k := Pos('.', ResourceName);
        if k > 0 then
          Name := Copy(ResourceName, 1, k - 1)
        else
          Name := ResourceName;
        Reference := aarSkeleton;
        StartFrame := firstFrame;
        EndFrame := Self.Owner.Skeleton.Frames.Count - 1;
      end;
    Inc(i);
    if (i < sl.Count) and (sl[i] = 'triangles') then
    begin
      // read optional mesh data
      Inc(i);
      if mesh.BonesPerVertex < 1 then
        mesh.BonesPerVertex := 1;
      faceGroup := nil;

      while sl[i] <> 'end' do
      begin
        if (faceGroup = nil) or (faceGroup.MaterialName <> sl[i]) then
        begin
          faceGroup := TFGVertexNormalTexIndexList.CreateOwned(mesh.FaceGroups);
          faceGroup.Mode := fgmmTriangles;
          faceGroup.MaterialName := sl[i];
          AllocateMaterial(sl[i]);
        end;
        Inc(i);

        for k := 1 to 3 do
          with mesh do
          begin
            tl.CommaText := sl[i];

            if tl.Count > 9 then
            begin
              // specifies bones and weights
              weightCount := StrToInt(tl[9]);
              SetLength(boneIDs, weightCount);
              for j := 0 to weightCount - 1 do
              begin
                boneIDs[j].boneID := StrToInt(tl[10 + j * 2]);
                boneIDs[j].Weight := GLStrToFloatDef(tl[11 + j * 2],0);
              end;

              nVert := FindOrAdd(boneIDs,
                AffineVectorMake(GLStrToFloatDef(tl[1],0),
                GLStrToFloatDef(tl[2],0), GLStrToFloatDef(tl[3],0)),
                AffineVectorMake(GLStrToFloatDef(tl[4],0),
                GLStrToFloatDef(tl[5],0), GLStrToFloatDef(tl[6],0)));
              nTex := TexCoords.FindOrAdd
                (AffineVectorMake(GLStrToFloatDef(tl[7],0), GLStrToFloatDef(tl[8],0),0));
              faceGroup.Add(nVert, nVert, nTex);
              Inc(i);
            end
            else
            begin
              // simple format
              boneID := StrToInt(tl[0]);
              nVert := FindOrAdd(boneID,
                AffineVectorMake(GLStrToFloatDef(tl[1],0),
                GLStrToFloatDef(tl[2],0), GLStrToFloatDef(tl[3],0)),
                AffineVectorMake(GLStrToFloatDef(tl[4],0),
                GLStrToFloatDef(tl[5],8), GLStrToFloatDef(tl[6],0)));
              nTex := TexCoords.FindOrAdd
                (AffineVectorMake(GLStrToFloatDef(tl[7],0), GLStrToFloatDef(tl[8],0), 0));
              faceGroup.Add(nVert, nVert, nTex);
              Inc(i);
            end;
          end;
      end;
      Owner.Skeleton.RootBones.PrepareGlobalMatrices;
      mesh.PrepareBoneMatrixInvertedMeshes;
    end;
  finally
    tl.Free;
    sl.Free;
  end;
end;

procedure TGLglTFVectorFile.SaveToStream(aStream: TStream);
var
  str, nodes: TStrings;
  i, j, k, l, b: Integer;
  p, r, v, n, t: TAffineVector;

  procedure GetNodesFromBonesRecurs(bone: TGLSkeletonBone; ParentID: Integer;
    bl: TStrings);
  var
    i: Integer;
  begin
    bl.Add(Format('%3d "%s" %3d', [bone.boneID, bone.name, ParentID]));
    for i := 0 to bone.Count - 1 do
      GetNodesFromBonesRecurs(bone.Items[i], bone.boneID, bl);
  end;

begin
  str := TStringList.Create;
  nodes := TStringList.Create;
  try
    str.Add('version 1');

    // Add the bones
    str.Add('nodes');
    for i := 0 to Owner.Skeleton.RootBones.Count - 1 do
    begin
      GetNodesFromBonesRecurs(Owner.Skeleton.RootBones[i], -1, nodes);
    end;
    str.AddStrings(nodes);
    str.Add('end');

    // Now add the relavent frames
    if Owner.Skeleton.Frames.Count > 0 then
    begin
      str.Add('skeleton');
      for i := 0 to Owner.Skeleton.Frames.Count - 1 do
      begin
        str.Add(Format('time %d', [i]));
        for j := 0 to Owner.Skeleton.Frames[i].Position.Count - 1 do
        begin
          p := Owner.Skeleton.Frames[i].Position[j];
          r := Owner.Skeleton.Frames[i].Rotation[j];
          str.Add(StringReplace(Format('%3d %.6f %.6f %.6f %.6f %.6f %.6f',
            [j, p.X, p.Y, p.Z, r.X, r.Y, r.Z]), ',', '.', [rfReplaceAll]));
        end;
      end;
      str.Add('end');
    end;

    // Add the mesh data
    if Owner.MeshObjects.Count > 0 then
    begin
      str.Add('triangles');
      for i := 0 to Owner.MeshObjects.Count - 1 do
        if Owner.MeshObjects[i] is TGLSkeletonMeshObject then
          with TGLSkeletonMeshObject(Owner.MeshObjects[i]) do
          begin
            for j := 0 to FaceGroups.Count - 1 do
              with TFGVertexNormalTexIndexList(FaceGroups[j]) do
              begin
                for k := 0 to (VertexIndices.Count div 3) - 1 do
                begin
                  str.Add(MaterialName);
                  for l := 0 to 2 do
                  begin
                    v := Vertices[VertexIndices[3 * k + l]];
                    n := Normals[NormalIndices[3 * k + l]];
                    t := TexCoords[TexCoordIndices[3 * k + l]];
                    b := VerticesBonesWeights^[VertexIndices[3 * k + l]]^
                      [0].boneID;
                    str.Add(StringReplace
                      (Format('%3d %.4f %.4f %.4f %.4f %.4f %.4f %.4f %.4f',
                      [b, v.X, v.Y, v.Z, n.X, n.Y, n.Z, t.X, t.Y]), ',', '.',
                      [rfReplaceAll]));
                  end;
                end;
              end;
          end;
      str.Add('end');
    end;

    str.SaveToStream(aStream);
  finally
    str.Free;
    nodes.Free;
  end;
end;

// ------------------------------------------------------------------
initialization
// ------------------------------------------------------------------

glTFUseEmbeddedColors := False;

RegisterVectorFileFormat('gltf', 'ASCII glTF files', TGLglTFVectorFile);
RegisterVectorFileFormat('glb', 'Binary glTF files', TGLglTFVectorFile);

end.

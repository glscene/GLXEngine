program MaterialsD;

uses
  Vcl.Forms,
  fdMaterials in 'fdMaterials.pas' {FormMaterials},
  fdCubemap in 'cubemap\fdCubemap.pas' {FormCubeMap},
  fdCustomQuad in 'customquad\fdCustomQuad.pas' {FormCustomQuad},
  fdDynTexture in 'dynamictexture\fdDynTexture.pas' {FormDynamicTexture},
  fdDynCubemap in 'dyncubemap\fdDynCubemap.pas' {FormDynCubeMap},
  fdMatScript in 'MaterialScript\fdMatScript.pas' {FormMatScript},
  fdMirror in 'mirror\fdMirror.pas' {FormMirror},
  fdMultiMaterial in 'multimaterial\fdMultiMaterial.pas' {FormMultiMat},
  fdMultiPass in 'multipass\fdMultiPass.pas' {FormMultiPass},
  fdMultiTexture in 'multitexture\fdMultiTexture.pas' {FormMultiTexture},
  fdObjMaterial in 'objmaterial\fdObjMaterial.pas' {FormMO},
  fdProcClouds in 'proceduralclouds\fdProcClouds.pas' {FormClouds},
  fdTexAnim in 'texanim\fdTexAnim.pas' {FormTexAnim},
  fdTexCombine in 'texcombine\fdTexCombine.pas' {FormTexCombine},
  fdTexFormat in 'texformat\fdTexFormat.pas' {FormTexFormat},
  fdTransparAdv in 'TransparAdv\fdTransparAdv.pas' {FormTransparAdv},
  fdTransparency in 'transparency\fdTransparency.pas' {FormTransparency};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TFormMaterials, FormMaterials);
  Application.CreateForm(TFormCubeMap, FormCubeMap);
  Application.CreateForm(TFormCustomQuad, FormCustomQuad);
  Application.CreateForm(TFormDynamicTexture, FormDynamicTexture);
  Application.CreateForm(TFormDynCubeMap, FormDynCubeMap);
  Application.CreateForm(TFormMatScript, FormMatScript);
  Application.CreateForm(TFormMirror, FormMirror);
  Application.CreateForm(TFormMultiMat, FormMultiMat);
  Application.CreateForm(TFormMultiPass, FormMultiPass);
  Application.CreateForm(TFormMultiTexture, FormMultiTexture);
  Application.CreateForm(TFormMO, FormMO);
  Application.CreateForm(TFormClouds, FormClouds);
  Application.CreateForm(TFormTexAnim, FormTexAnim);
  Application.CreateForm(TFormTexCombine, FormTexCombine);
  Application.CreateForm(TFormTexFormat, FormTexFormat);
  Application.CreateForm(TFormTransparAdv, FormTransparAdv);
  Application.CreateForm(TFormTransparency, FormTransparency);
  Application.Run;
end.

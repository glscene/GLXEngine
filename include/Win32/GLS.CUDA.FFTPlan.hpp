// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.CUDA.FFTPlan.pas' rev: 36.00 (Windows)

#ifndef GLS_CUDA_FFTPlanHPP
#define GLS_CUDA_FFTPlanHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <GLS.CUDA.Context.hpp>
#include <GLS.CUDA.APIComps.hpp>
#include <CUDA.Import.hpp>
#include <CUDA.FourierTransform.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Cuda
{
namespace Fftplan
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCUDAFFTPlan;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TCUDAFFTransform : unsigned char { fftRealToComplex, fftComplexToReal, fftComplexToComplex, fftDoubleToDoubleComplex, fftDoubleComplexToDouble, fftDoubleComplexToDoubleComplex };

enum DECLSPEC_DENUM TCUDAFFTdir : unsigned char { fftdForward, fftdInverse };

class PASCALIMPLEMENTATION TCUDAFFTPlan : public Gls::Cuda::Apicomps::TCUDAComponent
{
	typedef Gls::Cuda::Apicomps::TCUDAComponent inherited;
	
private:
	Cuda::Fouriertransform::TcufftHandle FHandle;
	int FWidth;
	int FHeight;
	int FDepth;
	int FBatch;
	int FSize;
	int FPaddedSize;
	TCUDAFFTransform FTransform;
	Cuda::Fouriertransform::TcufftResult FStatus;
	void __fastcall SetWidth(int Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetDepth(int Value);
	void __fastcall SetBatch(int Value);
	void __fastcall SetTransform(TCUDAFFTransform Value);
	
protected:
	virtual void __fastcall AllocateHandles();
	virtual void __fastcall DestroyHandles();
	__classmethod void __fastcall CheckLib();
	
public:
	__fastcall virtual TCUDAFFTPlan(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCUDAFFTPlan();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Execute(Gls::Cuda::Apicomps::TCUDAMemData* ASrc, Gls::Cuda::Apicomps::TCUDAMemData* ADst, const TCUDAFFTdir ADir = (TCUDAFFTdir)(0x0));
	
__published:
	__property int Width = {read=FWidth, write=SetWidth, default=256};
	__property int Height = {read=FHeight, write=SetHeight, default=0};
	__property int Depth = {read=FDepth, write=SetDepth, default=0};
	__property int Batch = {read=FBatch, write=SetBatch, default=1};
	__property TCUDAFFTransform Transform = {read=FTransform, write=SetTransform, default=0};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Fftplan */
}	/* namespace Cuda */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_CUDA_FFTPLAN)
using namespace Gls::Cuda::Fftplan;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_CUDA)
using namespace Gls::Cuda;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_CUDA_FFTPlanHPP

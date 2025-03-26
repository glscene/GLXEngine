// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GLS.VectorLists.pas' rev: 36.00 (Windows)

#ifndef GLS_VectorListsHPP
#define GLS_VectorListsHPP

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
#include <Stage.VectorTypes.hpp>
#include <Stage.VectorGeometry.hpp>
#include <GLS.PersistentClasses.hpp>

//-- user supplied -----------------------------------------------------------

namespace Gls
{
namespace Vectorlists
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TGLBaseList;
class DELPHICLASS TGLBaseVectorList;
class DELPHICLASS TGLAffineVectorList;
class DELPHICLASS TGLVectorList;
class DELPHICLASS TGLTexPointList;
class DELPHICLASS TGLIntegerList;
class DELPHICLASS TGLSingleList;
class DELPHICLASS TGLDoubleList;
class DELPHICLASS TGLByteList;
class DELPHICLASS TGLQuaternionList;
struct TGL4ByteData;
class DELPHICLASS TGL4ByteList;
class DELPHICLASS TGLLongWordList;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TGLBaseListOption : unsigned char { bloExternalMemory, bloSetCountResetsMemory };

typedef System::Set<TGLBaseListOption, TGLBaseListOption::bloExternalMemory, TGLBaseListOption::bloSetCountResetsMemory> TGLBaseListOptions;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLBaseList : public Gls::Persistentclasses::TGLPersistentObject
{
	typedef Gls::Persistentclasses::TGLPersistentObject inherited;
	
private:
	int FCount;
	int FCapacity;
	int FGrowthDelta;
	Stage::Vectorgeometry::PByteArray FBufferItem;
	TGLBaseListOptions FOptions;
	System::LongWord FRevision;
	System::UnicodeString FTagString;
	
protected:
	Stage::Vectorgeometry::PByteArray FBaseList;
	int FItemSize;
	void __fastcall SetCount(int Val);
	virtual void __fastcall SetCapacity(int NewCapacity);
	Stage::Vectorgeometry::PByteArray __fastcall BufferItem();
	bool __fastcall GetSetCountResetsMemory();
	void __fastcall SetSetCountResetsMemory(const bool Val);
	virtual void __fastcall ReadItemsData(System::Classes::TReader* AReader);
	virtual void __fastcall WriteItemsData(System::Classes::TWriter* AWriter);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* AFiler);
	
public:
	__fastcall virtual TGLBaseList();
	__fastcall virtual ~TGLBaseList();
	virtual void __fastcall Assign(System::Classes::TPersistent* Src);
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* reader);
	void __fastcall AddNulls(unsigned nbVals);
	void __fastcall InsertNulls(int Index, unsigned nbVals);
	void __fastcall AdjustCapacityToAtLeast(const int size);
	int __fastcall DataSize();
	void __fastcall UseMemory(void * rangeStart, int rangeCapacity);
	void __fastcall Flush();
	void __fastcall Clear();
	void __fastcall Delete(int Index);
	void __fastcall DeleteItems(int Index, unsigned nbVals);
	void __fastcall Exchange(int index1, int index2);
	void __fastcall Move(int curIndex, int newIndex);
	void __fastcall Reverse();
	__property int Count = {read=FCount, write=SetCount, nodefault};
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	__property int GrowthDelta = {read=FGrowthDelta, write=FGrowthDelta, nodefault};
	__property bool SetCountResetsMemory = {read=GetSetCountResetsMemory, write=SetSetCountResetsMemory, nodefault};
	__property System::UnicodeString TagString = {read=FTagString, write=FTagString};
	__property System::LongWord Revision = {read=FRevision, write=FRevision, nodefault};
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLBaseList(Gls::Persistentclasses::TGLVirtualReader* reader) : Gls::Persistentclasses::TGLPersistentObject(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLBaseVectorList : public TGLBaseList
{
	typedef TGLBaseList inherited;
	
protected:
	Stage::Vectorgeometry::PFloatArray __fastcall GetItemAddress(int Index);
	
public:
	DYNAMIC void __fastcall WriteToFiler(Gls::Persistentclasses::TGLVirtualWriter* writer);
	DYNAMIC void __fastcall ReadFromFiler(Gls::Persistentclasses::TGLVirtualReader* reader);
	virtual void __fastcall GetExtents(/* out */ Stage::Vectorgeometry::TAffineVector &min, /* out */ Stage::Vectorgeometry::TAffineVector &max);
	Stage::Vectorgeometry::TAffineVector __fastcall Sum();
	virtual void __fastcall Normalize();
	float __fastcall MaxSpacing(TGLBaseVectorList* list2);
	virtual void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta)/* overload */;
	virtual void __fastcall Translate(TGLBaseVectorList* const delta)/* overload */;
	virtual void __fastcall TranslateInv(TGLBaseVectorList* const delta)/* overload */;
	virtual void __fastcall Lerp(TGLBaseVectorList* const list1, TGLBaseVectorList* const list2, float lerpFactor) = 0 ;
	void __fastcall AngleLerp(TGLBaseVectorList* const list1, TGLBaseVectorList* const list2, float lerpFactor);
	void __fastcall AngleCombine(TGLBaseVectorList* const list1, float intensity);
	virtual void __fastcall Combine(TGLBaseVectorList* const list2, float factor);
	__property Stage::Vectorgeometry::PFloatArray ItemAddress[int Index] = {read=GetItemAddress};
public:
	/* TGLBaseList.Create */ inline __fastcall virtual TGLBaseVectorList() : TGLBaseList() { }
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGLBaseVectorList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLBaseVectorList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLAffineVectorList : public TGLBaseVectorList
{
	typedef TGLBaseVectorList inherited;
	
public:
	Stage::Vectorgeometry::TAffineVector operator[](int Index) { return this->Items[Index]; }
	
private:
	Stage::Vectorgeometry::PAffineVectorArray FList;
	
protected:
	Stage::Vectorgeometry::TAffineVector __fastcall Get(int Index);
	void __fastcall Put(int Index, const Stage::Vectorgeometry::TAffineVector &item);
	virtual void __fastcall SetCapacity(int NewCapacity);
	
public:
	__fastcall virtual TGLAffineVectorList();
	virtual void __fastcall Assign(System::Classes::TPersistent* Src);
	int __fastcall Add(const Stage::Vectorgeometry::TAffineVector &item)/* overload */;
	int __fastcall Add(const Stage::Vectortypes::TGLVector &item)/* overload */;
	void __fastcall Add(const Stage::Vectorgeometry::TAffineVector &i1, const Stage::Vectorgeometry::TAffineVector &i2)/* overload */;
	void __fastcall Add(const Stage::Vectorgeometry::TAffineVector &i1, const Stage::Vectorgeometry::TAffineVector &i2, const Stage::Vectorgeometry::TAffineVector &i3)/* overload */;
	int __fastcall Add(const Stage::Vectortypes::TVector2f &item)/* overload */;
	int __fastcall Add(const Stage::Vectorgeometry::TTexPoint &item)/* overload */;
	int __fastcall Add(const float X, const float Y)/* overload */;
	int __fastcall Add(const float X, const float Y, const float Z)/* overload */;
	int __fastcall Add(const int X, const int Y, const int Z)/* overload */;
	int __fastcall AddNC(const int X, const int Y, const int Z)/* overload */;
	int __fastcall Add(const Stage::Vectorgeometry::PIntegerArray xy, const int Z)/* overload */;
	int __fastcall AddNC(const Stage::Vectorgeometry::PIntegerArray xy, const int Z)/* overload */;
	void __fastcall Add(TGLAffineVectorList* const list)/* overload */;
	void __fastcall Push(const Stage::Vectorgeometry::TAffineVector &Val);
	Stage::Vectorgeometry::TAffineVector __fastcall Pop();
	void __fastcall Insert(int Index, const Stage::Vectorgeometry::TAffineVector &item);
	int __fastcall IndexOf(const Stage::Vectorgeometry::TAffineVector &item);
	int __fastcall FindOrAdd(const Stage::Vectorgeometry::TAffineVector &item);
	__property Stage::Vectorgeometry::TAffineVector Items[int Index] = {read=Get, write=Put/*, default*/};
	__property Stage::Vectorgeometry::PAffineVectorArray List = {read=FList};
	virtual void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta)/* overload */;
	HIDESBASE void __fastcall Translate(const Stage::Vectorgeometry::TAffineVector &delta, int base, int nb)/* overload */;
	void __fastcall TranslateItem(int Index, const Stage::Vectorgeometry::TAffineVector &delta);
	void __fastcall TranslateItems(int Index, const Stage::Vectorgeometry::TAffineVector &delta, int nb);
	void __fastcall CombineItem(int Index, const Stage::Vectorgeometry::TAffineVector &vector, const float f);
	void __fastcall TransformAsPoints(const Stage::Vectortypes::TGLMatrix &matrix);
	void __fastcall TransformAsVectors(const Stage::Vectortypes::TGLMatrix &matrix)/* overload */;
	void __fastcall TransformAsVectors(const Stage::Vectorgeometry::TAffineMatrix &matrix)/* overload */;
	virtual void __fastcall Normalize();
	virtual void __fastcall Lerp(TGLBaseVectorList* const list1, TGLBaseVectorList* const list2, float lerpFactor);
	void __fastcall Scale(float factor)/* overload */;
	void __fastcall Scale(const Stage::Vectorgeometry::TAffineVector &factors)/* overload */;
public:
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGLAffineVectorList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLAffineVectorList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseVectorList(reader) { }
	
	/* Hoisted overloads: */
	
public:
	inline void __fastcall  Translate(TGLBaseVectorList* const delta){ TGLBaseVectorList::Translate(delta); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLVectorList : public TGLBaseVectorList
{
	typedef TGLBaseVectorList inherited;
	
public:
	Stage::Vectortypes::TGLVector operator[](int Index) { return this->Items[Index]; }
	
private:
	Stage::Vectorgeometry::PVectorArray FList;
	
protected:
	Stage::Vectortypes::TGLVector __fastcall Get(int Index);
	void __fastcall Put(int Index, const Stage::Vectortypes::TGLVector &item);
	virtual void __fastcall SetCapacity(int NewCapacity);
	
public:
	__fastcall virtual TGLVectorList();
	virtual void __fastcall Assign(System::Classes::TPersistent* Src);
	int __fastcall Add(const Stage::Vectortypes::TGLVector &item)/* overload */;
	int __fastcall Add(const Stage::Vectorgeometry::TAffineVector &item, float w)/* overload */;
	int __fastcall Add(const float X, const float Y, const float Z, const float w)/* overload */;
	void __fastcall Add(const Stage::Vectorgeometry::TAffineVector &i1, const Stage::Vectorgeometry::TAffineVector &i2, const Stage::Vectorgeometry::TAffineVector &i3, float w)/* overload */;
	int __fastcall AddVector(const Stage::Vectorgeometry::TAffineVector &item)/* overload */;
	int __fastcall AddPoint(const Stage::Vectorgeometry::TAffineVector &item)/* overload */;
	int __fastcall AddPoint(const float X, const float Y, const float Z = 0.000000E+00f)/* overload */;
	void __fastcall Push(const Stage::Vectortypes::TGLVector &Val);
	Stage::Vectortypes::TGLVector __fastcall Pop();
	int __fastcall IndexOf(const Stage::Vectortypes::TGLVector &item);
	int __fastcall FindOrAdd(const Stage::Vectortypes::TGLVector &item);
	int __fastcall FindOrAddPoint(const Stage::Vectorgeometry::TAffineVector &item);
	void __fastcall Insert(int Index, const Stage::Vectortypes::TGLVector &item);
	__property Stage::Vectortypes::TGLVector Items[int Index] = {read=Get, write=Put/*, default*/};
	__property Stage::Vectorgeometry::PVectorArray List = {read=FList};
	virtual void __fastcall Lerp(TGLBaseVectorList* const list1, TGLBaseVectorList* const list2, float lerpFactor);
public:
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGLVectorList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLVectorList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseVectorList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLTexPointList : public TGLBaseVectorList
{
	typedef TGLBaseVectorList inherited;
	
public:
	Stage::Vectorgeometry::TTexPoint operator[](int Index) { return this->Items[Index]; }
	
private:
	Stage::Vectorgeometry::PTexPointArray FList;
	
protected:
	Stage::Vectorgeometry::TTexPoint __fastcall Get(int Index);
	void __fastcall Put(int Index, const Stage::Vectorgeometry::TTexPoint &item);
	virtual void __fastcall SetCapacity(int NewCapacity);
	
public:
	__fastcall virtual TGLTexPointList();
	virtual void __fastcall Assign(System::Classes::TPersistent* Src);
	int __fastcall IndexOf(const Stage::Vectorgeometry::TTexPoint &item);
	int __fastcall FindOrAdd(const Stage::Vectorgeometry::TTexPoint &item);
	int __fastcall Add(const Stage::Vectorgeometry::TTexPoint &item)/* overload */;
	int __fastcall Add(const Stage::Vectortypes::TVector2f &item)/* overload */;
	int __fastcall Add(const float texS, const float Text)/* overload */;
	int __fastcall Add(const int texS, const int Text)/* overload */;
	int __fastcall AddNC(const int texS, const int Text)/* overload */;
	int __fastcall Add(const Stage::Vectorgeometry::PIntegerArray texST)/* overload */;
	int __fastcall AddNC(const Stage::Vectorgeometry::PIntegerArray texST)/* overload */;
	void __fastcall Push(const Stage::Vectorgeometry::TTexPoint &Val);
	Stage::Vectorgeometry::TTexPoint __fastcall Pop();
	void __fastcall Insert(int Index, const Stage::Vectorgeometry::TTexPoint &item);
	__property Stage::Vectorgeometry::TTexPoint Items[int Index] = {read=Get, write=Put/*, default*/};
	__property Stage::Vectorgeometry::PTexPointArray List = {read=FList};
	HIDESBASE void __fastcall Translate(const Stage::Vectorgeometry::TTexPoint &delta);
	void __fastcall ScaleAndTranslate(const Stage::Vectorgeometry::TTexPoint &scale, const Stage::Vectorgeometry::TTexPoint &delta)/* overload */;
	void __fastcall ScaleAndTranslate(const Stage::Vectorgeometry::TTexPoint &scale, const Stage::Vectorgeometry::TTexPoint &delta, int base, int nb)/* overload */;
	virtual void __fastcall Lerp(TGLBaseVectorList* const list1, TGLBaseVectorList* const list2, float lerpFactor);
public:
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGLTexPointList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLTexPointList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseVectorList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLIntegerList : public TGLBaseList
{
	typedef TGLBaseList inherited;
	
public:
	int operator[](int Index) { return this->Items[Index]; }
	
private:
	Stage::Vectorgeometry::PIntegerArray FList;
	
protected:
	int __fastcall Get(int Index);
	void __fastcall Put(int Index, const int item);
	virtual void __fastcall SetCapacity(int newCapacity);
	
public:
	__fastcall virtual TGLIntegerList();
	virtual void __fastcall Assign(System::Classes::TPersistent* src);
	int __fastcall Add(const int item)/* overload */;
	int __fastcall AddNC(const int item)/* overload */;
	void __fastcall Add(const int i1, const int i2)/* overload */;
	void __fastcall Add(const int i1, const int i2, const int i3)/* overload */;
	void __fastcall Add(TGLIntegerList* const AList)/* overload */;
	void __fastcall Push(const int Val);
	int __fastcall Pop();
	void __fastcall Insert(int Index, const int item);
	void __fastcall Remove(const int item);
	int __fastcall IndexOf(int item);
	__property int Items[int Index] = {read=Get, write=Put/*, default*/};
	__property Stage::Vectorgeometry::PIntegerArray List = {read=FList};
	void __fastcall AddSerie(int aBase, int aDelta, int aCount);
	void __fastcall AddIntegers(const System::PInteger First, int n)/* overload */;
	void __fastcall AddIntegers(TGLIntegerList* const aList)/* overload */;
	void __fastcall AddIntegers(const int *anArray, const System::NativeInt anArray_High)/* overload */;
	int __fastcall MinInteger();
	int __fastcall MaxInteger();
	void __fastcall Sort();
	void __fastcall SortAndRemoveDuplicates();
	int __fastcall BinarySearch(const int Value)/* overload */;
	int __fastcall BinarySearch(const int Value, bool returnBestFit, bool &found)/* overload */;
	int __fastcall AddSorted(const int Value, const bool ignoreDuplicates = false);
	void __fastcall RemoveSorted(const int Value);
	void __fastcall Offset(int delta)/* overload */;
	void __fastcall Offset(int delta, const int base, const int nb)/* overload */;
public:
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGLIntegerList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLIntegerList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseList(reader) { }
	
};

#pragma pack(pop)

typedef System::StaticArray<float, 134217728> TGLSingleArrayList;

typedef TGLSingleArrayList *PGLSingleArrayList;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLSingleList : public TGLBaseList
{
	typedef TGLBaseList inherited;
	
public:
	float operator[](int Index) { return this->Items[Index]; }
	
private:
	PGLSingleArrayList FList;
	
protected:
	float __fastcall Get(int Index);
	void __fastcall Put(int Index, const float item);
	virtual void __fastcall SetCapacity(int NewCapacity);
	
public:
	__fastcall virtual TGLSingleList();
	virtual void __fastcall Assign(System::Classes::TPersistent* Src);
	int __fastcall Add(const float item)/* overload */;
	void __fastcall Add(const float i1, const float i2)/* overload */;
	void __fastcall AddSingles(const System::PSingle First, int n)/* overload */;
	void __fastcall AddSingles(const float *anArray, const System::NativeInt anArray_High)/* overload */;
	void __fastcall Push(const float Val);
	float __fastcall Pop();
	void __fastcall Insert(int Index, const float item);
	__property float Items[int Index] = {read=Get, write=Put/*, default*/};
	__property PGLSingleArrayList List = {read=FList};
	void __fastcall AddSerie(float aBase, float aDelta, int aCount);
	void __fastcall Offset(float delta)/* overload */;
	void __fastcall Offset(TGLSingleList* const delta)/* overload */;
	void __fastcall Scale(float factor);
	void __fastcall Sqr();
	void __fastcall Sqrt();
	float __fastcall Sum();
	float __fastcall Min();
	float __fastcall Max();
public:
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGLSingleList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLSingleList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseList(reader) { }
	
};

#pragma pack(pop)

typedef System::StaticArray<double, 134217728> TGLDoubleArrayList;

typedef TGLDoubleArrayList *PGLDoubleArrayList;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLDoubleList : public TGLBaseList
{
	typedef TGLBaseList inherited;
	
public:
	double operator[](int Index) { return this->Items[Index]; }
	
private:
	PGLDoubleArrayList FList;
	
protected:
	double __fastcall Get(int Index);
	void __fastcall Put(int Index, const double item);
	virtual void __fastcall SetCapacity(int NewCapacity);
	
public:
	__fastcall virtual TGLDoubleList();
	virtual void __fastcall Assign(System::Classes::TPersistent* Src);
	int __fastcall Add(const double item);
	void __fastcall Push(const double Val);
	double __fastcall Pop();
	void __fastcall Insert(int Index, const double item);
	__property double Items[int Index] = {read=Get, write=Put/*, default*/};
	__property PGLDoubleArrayList List = {read=FList};
	void __fastcall AddSerie(double aBase, double aDelta, int aCount);
	void __fastcall Offset(double delta)/* overload */;
	void __fastcall Offset(TGLDoubleList* const delta)/* overload */;
	void __fastcall Scale(double factor);
	void __fastcall Sqr();
	void __fastcall Sqrt();
	double __fastcall Sum();
	float __fastcall Min();
	float __fastcall Max();
public:
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGLDoubleList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLDoubleList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLByteList : public TGLBaseList
{
	typedef TGLBaseList inherited;
	
public:
	System::Byte operator[](int Index) { return this->Items[Index]; }
	
private:
	Stage::Vectorgeometry::PByteArray FList;
	
protected:
	System::Byte __fastcall Get(int Index);
	void __fastcall Put(int Index, const System::Byte item);
	virtual void __fastcall SetCapacity(int NewCapacity);
	
public:
	__fastcall virtual TGLByteList();
	virtual void __fastcall Assign(System::Classes::TPersistent* Src);
	int __fastcall Add(const System::Byte item);
	void __fastcall Insert(int Index, const System::Byte item);
	__property System::Byte Items[int Index] = {read=Get, write=Put/*, default*/};
	__property Stage::Vectorgeometry::PByteArray List = {read=FList};
public:
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGLByteList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLByteList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLQuaternionList : public TGLBaseVectorList
{
	typedef TGLBaseVectorList inherited;
	
public:
	Stage::Vectorgeometry::TQuaternion operator[](int Index) { return this->Items[Index]; }
	
private:
	Stage::Vectorgeometry::PQuaternionArray FList;
	
protected:
	Stage::Vectorgeometry::TQuaternion __fastcall Get(int Index);
	void __fastcall Put(int Index, const Stage::Vectorgeometry::TQuaternion &item);
	virtual void __fastcall SetCapacity(int NewCapacity);
	
public:
	__fastcall virtual TGLQuaternionList();
	virtual void __fastcall Assign(System::Classes::TPersistent* Src);
	int __fastcall Add(const Stage::Vectorgeometry::TQuaternion &item)/* overload */;
	int __fastcall Add(const Stage::Vectorgeometry::TAffineVector &item, float w)/* overload */;
	int __fastcall Add(const float X, const float Y, const float Z, const float W)/* overload */;
	void __fastcall Push(const Stage::Vectorgeometry::TQuaternion &Val);
	Stage::Vectorgeometry::TQuaternion __fastcall Pop();
	int __fastcall IndexOf(const Stage::Vectorgeometry::TQuaternion &item);
	int __fastcall FindOrAdd(const Stage::Vectorgeometry::TQuaternion &item);
	void __fastcall Insert(int Index, const Stage::Vectorgeometry::TQuaternion &item);
	__property Stage::Vectorgeometry::TQuaternion Items[int Index] = {read=Get, write=Put/*, default*/};
	__property Stage::Vectorgeometry::PQuaternionArray List = {read=FList};
	virtual void __fastcall Lerp(TGLBaseVectorList* const list1, TGLBaseVectorList* const list2, float lerpFactor);
	virtual void __fastcall Combine(TGLBaseVectorList* const list2, float factor);
public:
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGLQuaternionList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLQuaternionList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseVectorList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGL4ByteData
{
	
private:
	struct DECLSPEC_DRECORD _TGL4ByteData__1
	{
	public:
		System::StaticArray<System::Byte, 4> Value;
	};
	
	
	struct DECLSPEC_DRECORD _TGL4ByteData__2
	{
	public:
		int Value;
	};
	
	
	struct DECLSPEC_DRECORD _TGL4ByteData__3
	{
	public:
		unsigned Value;
	};
	
	
	struct DECLSPEC_DRECORD _TGL4ByteData__4
	{
	public:
		float Value;
	};
	
	
	struct DECLSPEC_DRECORD _TGL4ByteData__5
	{
	public:
		System::StaticArray<System::Word, 2> Value;
	};
	
	
	
	
public:
	union
	{
		struct 
		{
			_TGL4ByteData__5 Word;
		};
		struct 
		{
			_TGL4ByteData__4 Float;
		};
		struct 
		{
			_TGL4ByteData__3 UInt;
		};
		struct 
		{
			_TGL4ByteData__2 Int;
		};
		struct 
		{
			_TGL4ByteData__1 Bytes;
		};
		
	};
};
#pragma pack(pop)


typedef System::StaticArray<TGL4ByteData, 134217728> TGL4ByteArrayList;

typedef TGL4ByteArrayList *PG4ByteArrayList;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGL4ByteList : public TGLBaseList
{
	typedef TGLBaseList inherited;
	
public:
	TGL4ByteData operator[](int Index) { return this->Items[Index]; }
	
private:
	PG4ByteArrayList FList;
	
protected:
	TGL4ByteData __fastcall Get(int Index);
	void __fastcall Put(int Index, const TGL4ByteData item);
	virtual void __fastcall SetCapacity(int NewCapacity);
	
public:
	__fastcall virtual TGL4ByteList();
	virtual void __fastcall Assign(System::Classes::TPersistent* Src);
	int __fastcall Add(const TGL4ByteData item)/* overload */;
	void __fastcall Add(const float i1)/* overload */;
	void __fastcall Add(const float i1, const float i2)/* overload */;
	void __fastcall Add(const float i1, const float i2, const float i3)/* overload */;
	void __fastcall Add(const float i1, const float i2, const float i3, const float i4)/* overload */;
	void __fastcall Add(const int i1)/* overload */;
	void __fastcall Add(const int i1, const int i2)/* overload */;
	void __fastcall Add(const int i1, const int i2, const int i3)/* overload */;
	void __fastcall Add(const int i1, const int i2, const int i3, const int i4)/* overload */;
	void __fastcall Add(const unsigned i1)/* overload */;
	void __fastcall Add(const unsigned i1, const unsigned i2)/* overload */;
	void __fastcall Add(const unsigned i1, const unsigned i2, const unsigned i3)/* overload */;
	void __fastcall Add(const unsigned i1, const unsigned i2, const unsigned i3, const unsigned i4)/* overload */;
	void __fastcall Add(TGL4ByteList* const AList)/* overload */;
	void __fastcall Push(const TGL4ByteData Val);
	TGL4ByteData __fastcall Pop();
	void __fastcall Insert(int Index, const TGL4ByteData item);
	__property TGL4ByteData Items[int Index] = {read=Get, write=Put/*, default*/};
	__property PG4ByteArrayList List = {read=FList};
public:
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGL4ByteList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGL4ByteList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseList(reader) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TGLLongWordList : public TGLBaseList
{
	typedef TGLBaseList inherited;
	
public:
	System::LongWord operator[](int Index) { return this->Items[Index]; }
	
private:
	Stage::Vectorgeometry::PLongWordArray FList;
	
protected:
	System::LongWord __fastcall Get(int Index);
	void __fastcall Put(int Index, const System::LongWord item);
	virtual void __fastcall SetCapacity(int newCapacity);
	
public:
	__fastcall virtual TGLLongWordList();
	virtual void __fastcall Assign(System::Classes::TPersistent* src);
	int __fastcall Add(const System::LongWord item)/* overload */;
	int __fastcall AddNC(const System::LongWord item)/* overload */;
	void __fastcall Add(const System::LongWord i1, const System::LongWord i2)/* overload */;
	void __fastcall Add(const System::LongWord i1, const System::LongWord i2, const System::LongWord i3)/* overload */;
	void __fastcall Add(TGLLongWordList* const AList)/* overload */;
	void __fastcall Push(const System::LongWord Val);
	System::LongWord __fastcall Pop();
	void __fastcall Insert(int Index, const System::LongWord item);
	void __fastcall Remove(const System::LongWord item);
	System::LongWord __fastcall IndexOf(int item);
	__property System::LongWord Items[int Index] = {read=Get, write=Put/*, default*/};
	__property Stage::Vectorgeometry::PLongWordArray List = {read=FList};
	void __fastcall AddLongWords(const System::PLongWord First, int n)/* overload */;
	void __fastcall AddLongWords(TGLLongWordList* const aList)/* overload */;
	void __fastcall AddLongWords(const unsigned *anArray, const System::NativeInt anArray_High)/* overload */;
public:
	/* TGLBaseList.Destroy */ inline __fastcall virtual ~TGLLongWordList() { }
	
public:
	/* TGLPersistentObject.CreateFromFiler */ inline __fastcall TGLLongWordList(Gls::Persistentclasses::TGLVirtualReader* reader) : TGLBaseList(reader) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall QuickSortLists(int startIndex, int endIndex, TGLSingleList* refList, System::Classes::TList* objList)/* overload */;
extern DELPHI_PACKAGE void __fastcall QuickSortLists(int startIndex, int endIndex, TGLSingleList* refList, TGLBaseList* objList)/* overload */;
extern DELPHI_PACKAGE void __fastcall FastQuickSortLists(int startIndex, int endIndex, TGLSingleList* const refList, Gls::Persistentclasses::TGLPersistentObjectList* const objList);
}	/* namespace Vectorlists */
}	/* namespace Gls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS_VECTORLISTS)
using namespace Gls::Vectorlists;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_GLS)
using namespace Gls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GLS_VectorListsHPP

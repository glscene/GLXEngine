(*****************************************************************************
                          GLScene Graphics Engine
******************************************************************************)
unit Stage.VectorLists;
(*
  Misc. lists of vectors and entities
  The registered classes are:
  [TGSAffineVectorList, TGSVectorList, TGSTexPointList,
     TGSSingleList, TGSDoubleList, TGS4ByteList, TGSLongWordList]
*)
interface

{$I Stage.Defines.inc}

uses
  System.Classes,
  System.SysUtils,

  Stage.VectorTypes,
  Stage.VectorGeometry,
  Stage.PersistentClasses;

type
  TGSBaseListOption = (bloExternalMemory, bloSetCountResetsMemory);
  TGSBaseListOptions = set of TGSBaseListOption;

  // Base class for lists, introduces common behaviours
  TGSBaseList = class(TGSPersistentObject)
  private
    FCount: Integer;
    FCapacity: Integer;
    FGrowthDelta: Integer;
    FBufferItem: PByteArray;
    FOptions: TGSBaseListOptions;
    FRevision: LongWord;
    FTagString: string;
  protected
    // The base list pointer (untyped)
    FBaseList: PByteArray;
    // Must be defined by all subclasses in their constructor(s)
    FItemSize: Integer;
    procedure SetCount(Val: Integer);  inline;
    (* Only function where list may be alloc'ed & freed.
    Resizes the array pointed by FBaseList, adjust the subclass's
    typed pointer accordingly if any *)
    procedure SetCapacity(NewCapacity: Integer); virtual;
    function BufferItem: PByteArray;  inline;
    function GetSetCountResetsMemory: Boolean; inline;
    procedure SetSetCountResetsMemory(const Val: Boolean);
    procedure ReadItemsData(AReader : TReader); virtual;
    procedure WriteItemsData(AWriter : TWriter); virtual;
    procedure DefineProperties(AFiler: TFiler); override;
  public
    constructor Create; override;
    destructor Destroy; override;
    procedure Assign(Src: TPersistent); override;
    procedure WriteToFiler(writer: TGSVirtualWriter); override;
    procedure ReadFromFiler(reader: TGSVirtualReader); override;
    procedure AddNulls(nbVals: Cardinal);
    procedure InsertNulls(Index: Integer; nbVals: Cardinal);
    procedure AdjustCapacityToAtLeast(const size: Integer);
    function DataSize: Integer;
    (*Tell the list to use the specified range instead of its own.
     rangeCapacity should be expressed in bytes.
     The allocated memory is NOT managed by the list, current content
     if copied to the location, if the capacity is later changed, regular
     memory will be allocated, and the specified range no longer used *)
    procedure UseMemory(rangeStart: Pointer; rangeCapacity: Integer);
    // Empties the list without altering capacity
    procedure Flush; inline;
    // Empties the list and release
    procedure Clear;
    procedure Delete(Index: Integer);
    procedure DeleteItems(Index: Integer; nbVals: Cardinal);
    procedure Exchange(index1, index2: Integer); inline;
    procedure Move(curIndex, newIndex: Integer); inline;
    procedure Reverse;
    // Nb of items in the list. When assigning a Count, added items are reset to zero
    property Count: Integer read FCount write SetCount;
    // Current list capacity. Not persistent
    property Capacity: Integer read FCapacity write SetCapacity;
    // List growth granularity. Not persistent
    property GrowthDelta: Integer read FGrowthDelta write FGrowthDelta;
    (* If true (default value) adjusting count will reset added values.
     Switching this option to true will turn off this memory reset,
     which can improve performance is that having empty values isn't required. *)
    property SetCountResetsMemory: Boolean read GetSetCountResetsMemory write SetSetCountResetsMemory;
    property TagString: string read FTagString write FTagString;
    // Increase by one after every content changes
    property Revision: LongWord read FRevision write FRevision;
  end;

  // Base class for vector lists, introduces common behaviours
  TGSBaseVectorList = class(TGSBaseList)
  protected
    function GetItemAddress(Index: Integer): PFloatArray; inline;
  public
    procedure WriteToFiler(writer: TGSVirtualWriter); override;
    procedure ReadFromFiler(reader: TGSVirtualReader); override;
    procedure GetExtents(out min, max: TAffineVector); virtual;
    function Sum: TAffineVector;
    procedure Normalize; virtual;
    function MaxSpacing(list2: TGSBaseVectorList): Single;
    procedure Translate(const delta: TAffineVector); overload; virtual;
    procedure Translate(const delta: TGSBaseVectorList); overload; virtual;
    procedure TranslateInv(const delta: TGSBaseVectorList); overload; virtual;
    (*Replace content of the list with lerp results between the two given lists.
     Note: you can't Lerp with Self!!! *)
    procedure Lerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single); virtual; abstract;
    (* Replace content of the list with angle lerp between the two given lists.
    Note: you can't Lerp with Self!!! *)
    procedure AngleLerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single);
    procedure AngleCombine(const list1: TGSBaseVectorList; intensity: Single);
    //Linear combination of Self with another list. Self[i]:=Self[i]+list2[i]*factor
    procedure Combine(const list2: TGSBaseVectorList; factor: Single); virtual;
    property ItemAddress[Index: Integer]: PFloatArray read GetItemAddress;
  end;

  (*A list of TAffineVector.
   Similar to TList, but using TAffineVector as items.
   The list has stack-like push/pop methods *)
  TGSAffineVectorList = class(TGSBaseVectorList)
  private
    FList: PAffineVectorArray;
  protected
    function Get(Index: Integer): TAffineVector; inline;
    procedure Put(Index: Integer; const item: TAffineVector); inline;
    procedure SetCapacity(NewCapacity: Integer); override;
  public
    constructor Create; override;
    procedure Assign(Src: TPersistent); override;
    function Add(const item: TAffineVector): Integer; overload;
    function Add(const item: TGSVector): Integer; overload;
    procedure Add(const i1, i2: TAffineVector); overload;
    procedure Add(const i1, i2, i3: TAffineVector); overload;
    function Add(const item: TVector2f): Integer; overload;
    function Add(const item: TTexPoint): Integer; overload;
    function Add(const X, Y: Single): Integer; overload;
    function Add(const X, Y, Z: Single): Integer; overload;
    function Add(const X, Y, Z: Integer): Integer; overload;
    // Add (3 ints, no capacity check)
    function AddNC(const X, Y, Z: Integer): Integer; overload;
    // Add (2 ints in array + 1)
    function Add(const xy: PIntegerArray; const Z: Integer): Integer; overload;
    // AddNC (2 ints in array + 1, no capacity check)
    function AddNC(const xy: PIntegerArray; const Z: Integer): Integer; overload;
    procedure Add(const list: TGSAffineVectorList); overload;
    procedure Push(const Val: TAffineVector);
    function Pop: TAffineVector;
    procedure Insert(Index: Integer; const item: TAffineVector); inline;
    function IndexOf(const item: TAffineVector): Integer;
    function FindOrAdd(const item: TAffineVector): Integer;
    property Items[Index: Integer]: TAffineVector read Get write Put; default;
    property List: PAffineVectorArray read FList;
    procedure Translate(const delta: TAffineVector); overload; override;
    procedure Translate(const delta: TAffineVector; base, nb: Integer); overload;
    // Translates the given item
    procedure TranslateItem(Index: Integer; const delta: TAffineVector);
    // Translates given items
    procedure TranslateItems(Index: Integer; const delta: TAffineVector; nb: Integer);
    // Combines the given item
    procedure CombineItem(Index: Integer; const vector: TAffineVector; const f: Single);
    (*Transforms all items by the matrix as if they were points.
      ie. the translation component of the matrix is honoured. *)
    procedure TransformAsPoints(const matrix: TGSMatrix);
    (* Transforms all items by the matrix as if they were vectors.
       ie. the translation component of the matrix is not honoured. *)
    procedure TransformAsVectors(const matrix: TGSMatrix); overload;
    procedure TransformAsVectors(const matrix: TAffineMatrix); overload;
    procedure Normalize; override;
    procedure Lerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single); override;
    procedure Scale(factor: Single); overload;
    procedure Scale(const factors: TAffineVector); overload;
  end;

  (* A list of TGLVectors.
   Similar to TList, but using TGSVector as items.
   The list has stack-like push/pop methods *)
  TGSVectorList = class(TGSBaseVectorList)
  private
    FList: PVectorArray;
  protected
    function Get(Index: Integer): TGSVector; inline;
    procedure Put(Index: Integer; const item: TGSVector); inline;
    procedure SetCapacity(NewCapacity: Integer); override;
  public
    constructor Create; override;
    procedure Assign(Src: TPersistent); override;
    function Add(const item: TGSVector): Integer; overload; inline;
    function Add(const item: TAffineVector; w: Single): Integer; overload; inline;
    function Add(const X, Y, Z, w: Single): Integer; overload; inline;
    procedure Add(const i1, i2, i3: TAffineVector; w: Single); overload; inline;
    function AddVector(const item: TAffineVector): Integer; overload;
    function AddPoint(const item: TAffineVector): Integer; overload;
    function AddPoint(const X, Y: Single; const Z: Single = 0): Integer; overload;
    procedure Push(const Val: TGSVector);
    function Pop: TGSVector;
    function IndexOf(const item: TGSVector): Integer;
    function FindOrAdd(const item: TGSVector): Integer;
    function FindOrAddPoint(const item: TAffineVector): Integer;
    procedure Insert(Index: Integer; const item: TGSVector);
    property Items[Index: Integer]: TGSVector read Get write Put; default;
    property List: PVectorArray read FList;
    procedure Lerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single); override;
  end;

  (* A list of TGLTexPoint. Similar to TList, but using TTexPoint as items.
     The list has stack-like push/pop methods. *)
  TGSTexPointList = class(TGSBaseVectorList)
  private
    FList: PTexPointArray;
  protected
    function Get(Index: Integer): TTexPoint;
    procedure Put(Index: Integer; const item: TTexPoint);
    procedure SetCapacity(NewCapacity: Integer); override;
  public
    constructor Create; override;
    procedure Assign(Src: TPersistent); override;
    function IndexOf(const item: TTexpoint): Integer;
    function FindOrAdd(const item: TTexpoint): Integer;
    function Add(const item: TTexPoint): Integer; overload;
    function Add(const item: TVector2f): Integer; overload;
    function Add(const texS, Text: Single): Integer; overload;
    function Add(const texS, Text: Integer): Integer; overload;
    function AddNC(const texS, Text: Integer): Integer; overload;
    function Add(const texST: PIntegerArray): Integer; overload;
    function AddNC(const texST: PIntegerArray): Integer; overload;
    procedure Push(const Val: TTexPoint);
    function Pop: TTexPoint;
    procedure Insert(Index: Integer; const item: TTexPoint);
    property Items[Index: Integer]: TTexPoint read Get write Put; default;
    property List: PTexPointArray read FList;
    procedure Translate(const delta: TTexPoint);
    procedure ScaleAndTranslate(const scale, delta: TTexPoint); overload;
    procedure ScaleAndTranslate(const scale, delta: TTexPoint; base, nb: Integer); overload;
    procedure Lerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single); override;
  end;

  (*  A list of Integers. Similar to TList, but using TTexPoint as items.
     The list has stack-like push/pop methods. *)
  TGSIntegerList = class(TGSBaseList)
  private
    FList: PIntegerArray;
  protected
    function Get(Index: Integer): Integer; inline;
    procedure Put(Index: Integer; const item: Integer); inline;
    procedure SetCapacity(newCapacity: Integer); override;
  public
    constructor Create; override;
    procedure Assign(src: TPersistent); override;
    function Add(const item: Integer): Integer; overload; inline;
    function AddNC(const item: Integer): Integer; overload; inline;
    procedure Add(const i1, i2: Integer); overload; inline;
    procedure Add(const i1, i2, i3: Integer); overload; inline;
    procedure Add(const AList: TGSIntegerList); overload; inline;
    procedure Push(const Val: Integer); inline;
    function Pop: Integer; inline;
    procedure Insert(Index: Integer; const item: Integer); inline;
    procedure Remove(const item: Integer); inline;
    function IndexOf(item: Integer): Integer; inline;
    property Items[Index: Integer]: Integer read Get write Put; default;
    property List: PIntegerArray read FList;
    // Adds count items in an arithmetic serie. Items are (aBase),(aBase+aDelta)...(aBase+(aCount-1)*aDelta)
    procedure AddSerie(aBase, aDelta, aCount: Integer);
    // Add n integers at the address starting at (and including) first
    procedure AddIntegers(const First: PInteger; n: Integer); overload;
    // Add all integers from aList into the list
    procedure AddIntegers(const aList: TGSIntegerList); overload;
    // Add all integers from anArray into the list
    procedure AddIntegers(const anArray: array of Integer); overload;
    // Returns the minimum integer item, zero if list is empty
    function MinInteger: Integer;
    // Returns the maximum integer item, zero if list is empty
    function MaxInteger: Integer;
    // Sort items in ascending order
    procedure Sort;
    // Sort items in ascending order and remove duplicated integers
    procedure SortAndRemoveDuplicates;
    // Locate a value in a sorted list
    function BinarySearch(const Value: Integer): Integer; overload;
    (* Locate a value in a sorted list.
      If ReturnBestFit is set to true, the routine will return the position
      of the largest value that's smaller than the sought value. Found will
      be set to True if the exact value was found, False if a "BestFit" was found *)
    function BinarySearch(const Value: Integer; returnBestFit: Boolean; var found: Boolean): Integer; overload;
    (* Add integer to a sorted list.
      Maintains the list sorted. If you have to add "a lot" of integers
      at once, use the Add method then Sort the list for better performance. *)
    function AddSorted(const Value: Integer; const ignoreDuplicates: Boolean = False): Integer;
    // Removes an integer from a sorted list
    procedure RemoveSorted(const Value: Integer);
    // Adds delta to all items in the list
    procedure Offset(delta: Integer); overload;
    procedure Offset(delta: Integer; const base, nb: Integer); overload;
  end;

  TGSSingleArrayList = array[0..MaxInt shr 4] of Single;
  PGSSingleArrayList = ^TGSSingleArrayList;

  (* A list of Single. Similar to TList, but using Single as items.
    The list has stack-like push/pop methods *)
  TGSSingleList = class(TGSBaseList)
  private
    FList: PGSSingleArrayList;
  protected
    function Get(Index: Integer): Single; inline;
    procedure Put(Index: Integer; const item: Single); inline;
    procedure SetCapacity(NewCapacity: Integer); override;
  public
    constructor Create; override;
    procedure Assign(Src: TPersistent); override;
    function Add(const item: Single): Integer; overload; inline;
    procedure Add(const i1, i2: Single); overload; inline;
    procedure AddSingles(const First: PSingle; n: Integer); overload; inline;
    procedure AddSingles(const anArray: array of Single); overload;
    procedure Push(const Val: Single); inline;
    function Pop: Single; inline;
    procedure Insert(Index: Integer; const item: Single); inline;
    property Items[Index: Integer]: Single read Get write Put; default;
    property List: PGSSingleArrayList read FList;
    procedure AddSerie(aBase, aDelta: Single; aCount: Integer);
    // Adds delta to all items in the list
    procedure Offset(delta: Single); overload;
    (* Adds to each item the corresponding item in the delta list.
       Performs 'Items[i]:=Items[i]+delta[i]'.
       If both lists don't have the same item count, an exception is raised *)
    procedure Offset(const delta: TGSSingleList); overload;
    // Multiplies all items by factor
    procedure Scale(factor: Single);
    // Square all items
    procedure Sqr;
    // SquareRoot all items
    procedure Sqrt;
    // Computes the sum of all elements
    function Sum: Single;
    function Min: Single;
    function Max: Single;
  end;

  TGSDoubleArrayList = array[0..MaxInt shr 4] of Double;
  PGSDoubleArrayList = ^TGSDoubleArrayList;

  (* A list of Double. Similar to TList, but using Double as items.
    The list has stack-like push/pop methods *)
  TGSDoubleList = class(TGSBaseList)
  private
    FList: PGSDoubleArrayList;
  protected
    function Get(Index: Integer): Double;
    procedure Put(Index: Integer; const item: Double);
    procedure SetCapacity(NewCapacity: Integer); override;
  public
    constructor Create; override;
    procedure Assign(Src: TPersistent); override;
    function Add(const item: Double): Integer;
    procedure Push(const Val: Double);
    function Pop: Double;
    procedure Insert(Index: Integer; const item: Double);
    property Items[Index: Integer]: Double read Get write Put; default;
    property List: PGSDoubleArrayList read FList;
    procedure AddSerie(aBase, aDelta: Double; aCount: Integer);
    // Adds delta to all items in the list
    procedure Offset(delta: Double); overload;
    (* Adds to each item the corresponding item in the delta list.
      Performs 'Items[i] := Items[i] + delta[i]'.
      If both lists don't have the same item count, an exception is raised *)
    procedure Offset(const delta: TGSDoubleList); overload;
    // Multiplies all items by factor
    procedure Scale(factor: Double);
    // Square all items
    procedure Sqr;
    // SquareRoot all items
    procedure Sqrt;
    // Computes the sum of all elements
    function Sum: Double;
    function Min: Single;
    function Max: Single;
  end;

  // A list of bytes. Similar to TList, but using Byte as items
  TGSByteList = class(TGSBaseList)
  private
    FList: PByteArray;
  protected
    function Get(Index: Integer): Byte; inline;
    procedure Put(Index: Integer; const item: Byte); inline;
    procedure SetCapacity(NewCapacity: Integer); override;
  public
    constructor Create; override;
    procedure Assign(Src: TPersistent); override;
    function Add(const item: Byte): Integer; inline;
    procedure Insert(Index: Integer; const item: Byte); inline;
    property Items[Index: Integer]: Byte read Get write Put; default;
    property List: PByteArray read FList;
  end;

  (* A list of TQuaternion. Similar to TList, but using TQuaternion as items.
    The list has stack-like push/pop methods *)
  TGSQuaternionList = class(TGSBaseVectorList)
  private
    FList: PQuaternionArray;
  protected
    function Get(Index: Integer): TQuaternion;
    procedure Put(Index: Integer; const item: TQuaternion);
    procedure SetCapacity(NewCapacity: Integer); override;
  public
    constructor Create; override;
    procedure Assign(Src: TPersistent); override;
    function Add(const item: TQuaternion): Integer; overload;
    function Add(const item: TAffineVector; w: Single): Integer; overload;
    function Add(const X, Y, Z, W: Single): Integer; overload;
    procedure Push(const Val: TQuaternion);
    function Pop: TQuaternion;
    function IndexOf(const item: TQuaternion): Integer;
    function FindOrAdd(const item: TQuaternion): Integer;
    procedure Insert(Index: Integer; const item: TQuaternion);
    property Items[Index: Integer]: TQuaternion read Get write Put; default;
    property List: PQuaternionArray read FList;
    // Lerps corresponding quaternions from both lists using QuaternionSlerp
    procedure Lerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single); override;
    (* Multiplies corresponding quaternions after the second quaternion is
      lerped with the IdentityQuaternion using factor. This allows for weighted
      combining of rotation transforms using quaternions *)
    procedure Combine(const list2: TGSBaseVectorList; factor: Single); override;
  end;

  // 4 byte union contain access like Integer, Single and four Byte
	TGS4ByteData = packed record
    case Byte of
    0 : (Bytes : record Value : array[0..3] of Byte; end);
    1 : (Int   : record Value : Integer; end);
    2 : (UInt  : record Value : Cardinal; end);
    3 : (Float : record Value : Single; end);
    4 : (Word  : record Value : array[0..1] of Word; end);
  end;

  TGS4ByteArrayList = array[0..MaxInt shr 4] of TGS4ByteData;
  PGS4ByteArrayList = ^TGS4ByteArrayList;

  // A list of TGS4ByteData
  TGS4ByteList = class(TGSBaseList)
  private
    FList: PGS4ByteArrayList;
  protected
    function  Get(Index: Integer): TGS4ByteData;
    procedure Put(Index: Integer; const item: TGS4ByteData);
    procedure SetCapacity(NewCapacity: Integer); override;
  public
    constructor Create; override;
    procedure Assign(Src: TPersistent); override;
    function  Add(const item: TGS4ByteData): Integer; overload;
    procedure Add(const i1: Single); overload;
    procedure Add(const i1, i2: Single); overload;
    procedure Add(const i1, i2, i3: Single); overload;
    procedure Add(const i1, i2, i3, i4: Single); overload;
    procedure Add(const i1: Integer); overload;
    procedure Add(const i1, i2: Integer); overload;
    procedure Add(const i1, i2, i3: Integer); overload;
    procedure Add(const i1, i2, i3, i4: Integer); overload;
    procedure Add(const i1: Cardinal); overload;
    procedure Add(const i1, i2: Cardinal); overload;
    procedure Add(const i1, i2, i3: Cardinal); overload;
    procedure Add(const i1, i2, i3, i4: Cardinal); overload;
    procedure Add(const AList: TGS4ByteList); overload;
    procedure Push(const Val: TGS4ByteData);
    function  Pop: TGS4ByteData;
    procedure Insert(Index: Integer; const item: TGS4ByteData);
    property Items[Index: Integer]: TGS4ByteData read Get write Put; default;
    property List: PGS4ByteArrayList read FList;
  end;

  TGSLongWordList = class(TGSBaseList)
  private
    FList: PLongWordArray;
  protected
    function Get(Index: Integer): LongWord;
    procedure Put(Index: Integer; const item: LongWord);
    procedure SetCapacity(newCapacity: Integer); override;
  public
    constructor Create; override;
    procedure Assign(src: TPersistent); override;
    function Add(const item: LongWord): Integer; overload;
    function AddNC(const item: LongWord): Integer; overload;
    procedure Add(const i1, i2: LongWord); overload;
    procedure Add(const i1, i2, i3: LongWord); overload;
    procedure Add(const AList: TGSLongWordList); overload;
    procedure Push(const Val: LongWord);
    function Pop: LongWord;
    procedure Insert(Index: Integer; const item: LongWord);
    procedure Remove(const item: LongWord);
    function IndexOf(item: Integer): LongWord;
    property Items[Index: Integer]: LongWord read Get write Put; default;
    property List: PLongWordArray read FList;
    // Add n integers at the address starting at (and including) first
    procedure AddLongWords(const First: PLongWord; n: Integer); overload;
    // Add all integers from aList into the list
    procedure AddLongWords(const aList: TGSLongWordList); overload;
    // Add all integers from anArray into the list
    procedure AddLongWords(const anArray: array of LongWord); overload;
  end;

// Sort the refList in ascending order, ordering objList (TList) on the way
procedure QuickSortLists(startIndex, endIndex: Integer; refList: TGSSingleList; objList: TList); overload;
// Sort the refList in ascending order, ordering objList (TGSBaseList) on the way
procedure QuickSortLists(startIndex, endIndex: Integer; refList: TGSSingleList; objList: TGSBaseList); overload;
(* Sort the refList in ascending order, ordering objList on the way.
   Use if, and *ONLY* if refList contains only values superior or equal to 1 *)
procedure FastQuickSortLists(startIndex, endIndex: Integer; const refList: TGSSingleList; const objList: TGSPersistentObjectList);


implementation //============================================================

const
  cDefaultListGrowthDelta = 16;

//---------------------------------------------------------------------------
procedure QuickSortLists(startIndex, endIndex: Integer; refList: TGSSingleList; objList: TList);
var
  I, J: Integer;
  P:    Single;
begin
  if endIndex - startIndex > 1 then
  begin
    repeat
      I := startIndex;
      J := endIndex;
      P := refList.List^[(I + J) shr 1];
      repeat
        while Single(refList.List^[I]) < P do
          Inc(I);
        while Single(refList.List^[J]) > P do
          Dec(J);
        if I <= J then
        begin
          refList.Exchange(I, J);
          objList.Exchange(I, J);
          Inc(I);
          Dec(J);
        end;
      until I > J;
      if startIndex < J then
        QuickSortLists(startIndex, J, refList, objList);
      startIndex := I;
    until I >= endIndex;
  end
  else
  if endIndex - startIndex > 0 then
  begin
    p := refList.List^[startIndex];
    if refList.List^[endIndex] < p then
    begin
      refList.Exchange(startIndex, endIndex);
      objList.Exchange(startIndex, endIndex);
    end;
  end;
end;

//---------------------------------------------------------------------------
procedure QuickSortLists(startIndex, endIndex: Integer; refList: TGSSingleList; objList: TGSBaseList);
var
  I, J: Integer;
  P:    Single;
begin
  if endIndex - startIndex > 1 then
  begin
    repeat
      I := startIndex;
      J := endIndex;
      P := refList.List^[(I + J) shr 1];
      repeat
        while Single(refList.List^[I]) < P do
          Inc(I);
        while Single(refList.List^[J]) > P do
          Dec(J);
        if I <= J then
        begin
          refList.Exchange(I, J);
          objList.Exchange(I, J);
          Inc(I);
          Dec(J);
        end;
      until I > J;
      if startIndex < J then
        QuickSortLists(startIndex, J, refList, objList);
      startIndex := I;
    until I >= endIndex;
  end
  else
  if endIndex - startIndex > 0 then
  begin
    p := refList.List^[startIndex];
    if refList.List^[endIndex] < p then
    begin
      refList.Exchange(startIndex, endIndex);
      objList.Exchange(startIndex, endIndex);
    end;
  end;
end;

//---------------------------------------------------------------------------
procedure FastInsertionSortLists(startIndex, endIndex: Integer; const ppl: PIntegerArray; const oppl: PPointerArray); inline;
var
  oTemp:  Pointer;
  I, J:   Integer;
  Temp:   Integer;
begin
  for I := startIndex + 1 to endIndex do
  begin
    J := i-1;
    Temp := ppl^[I];
    oTemp := oppl^[I];
    while (J>=startIndex) and (Temp < ppl^[J]) do
    begin
      ppl^[J+1] := ppl^[J];
      oppl^[J+1] := oppl^[J];
      Dec(j);
    end;
    ppl^[J+1] := Temp;
    oppl^[J+1] := oTemp;
  end;
end;

//---------------------------------------------------------------------------
procedure FastQuickSortLists(startIndex, endIndex: Integer; const refList: TGSSingleList; const objList: TGSPersistentObjectList);
var
  ppl:      PIntegerArray;
  oTemp:    Pointer;
  oppl:     PPointerArray;
  I, J:     Integer;
  p, Temp:  Integer;
begin
  // All singles are >=1, so IEEE format allows comparing them as if they were integers
  ppl := PIntegerArray(@refList.List[0]);
  oppl := PPointerArray(objList.List);
  if endIndex > startIndex + 1 then
  begin
    if (endIndex-startIndex)<16 then
    begin
      FastInsertionSortLists(startIndex, endIndex, ppl, oppl);
    end else
    begin
      repeat
        I := startIndex;
        J := endIndex;
        p := PInteger(@refList.List[(I + J) shr 1])^;
        repeat
          while ppl^[I] < p do
            Inc(I);
          while ppl^[J] > p do
            Dec(J);
          if I <= J then
          begin
            // swap integers
            Temp := ppl^[I];
            ppl^[I] := ppl^[J];
            ppl^[J] := Temp;
            // swap pointers
            oTemp := oppl^[I];
            oppl^[I] := oppl^[J];
            oppl^[J] := oTemp;
            Inc(I);
            Dec(J);
          end;
        until I > J;
        if startIndex < J then
          FastQuickSortLists(startIndex, J, refList, objList);
        startIndex := I;
      until I >= endIndex;
    end;

  end else if endIndex > startIndex then
  begin
    if ppl^[endIndex] < ppl^[startIndex] then
    begin
      I := endIndex;
      J := startIndex;
      // swap integers
      Temp := ppl^[I];
      ppl^[I] := ppl^[J];
      ppl^[J] := Temp;
      // swap pointers
      oTemp := oppl^[I];
      oppl^[I] := oppl^[J];
      oppl^[J] := oTemp;
    end;
  end;
end;

// ------------------
// ------------------ TGSBaseList ------------------
// ------------------
constructor TGSBaseList.Create;
begin
  inherited Create;
  FOptions := [bloSetCountResetsMemory];
end;

destructor TGSBaseList.Destroy;
begin
  Clear;
  if Assigned(FBufferItem) then
    FreeMem(FBufferItem);
  inherited;
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.Assign(Src: TPersistent);
begin
  if (Src is TGSBaseList) then
  begin
    SetCapacity(TGSBaseList(Src).Count);
    FGrowthDelta := TGSBaseList(Src).FGrowthDelta;
    FCount := FCapacity;
    FTagString := TGSBaseList(Src).FTagString;
    Inc(FRevision);
  end
  else
    inherited;
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.DefineProperties(AFiler: TFiler);
begin
  inherited DefineProperties(AFiler);
  AFiler.DefineProperty('Items', ReadItemsData, WriteItemsData, True);
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.ReadItemsData(AReader: TReader);
var
  lData: AnsiString;
  lOutputText: string;
begin
  lOutputText := AReader.ReadString;
  SetLength(lData, Length(lOutputText) div 2 + 1);
  HexToBin(PChar(lOutputText), PAnsiChar(lData), Length(lData));
  LoadFromString(string(lData));
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.WriteItemsData(AWriter: TWriter);
var
  lData: AnsiString;
  lOutputText: String;
begin
  lData := AnsiString(SaveToString);
  SetLength(lOutputText, Length(lData) * 2);
  BinToHex(PAnsiChar(lData), PChar(lOutputText), Length(lData));
  AWriter.WriteString(lOutputText);
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.WriteToFiler(writer: TGSVirtualWriter);
begin
  inherited;
  with writer do
  begin
    WriteInteger(0); // Archive Version 0
    WriteInteger(Count);
    WriteInteger(FItemSize);
    if Count > 0 then
      write(FBaseList[0], Count * FItemSize);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.ReadFromFiler(reader: TGSVirtualReader);
var
  archiveVersion: Integer;
begin
  inherited;
  archiveVersion := reader.ReadInteger;
  if archiveVersion = 0 then
    with reader do
    begin
      FCount := ReadInteger;
      FItemSize := ReadInteger;
      SetCapacity(Count);
      if Count > 0 then
        read(FBaseList[0], Count * FItemSize);
    end
  else
    RaiseFilerException(archiveVersion);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.SetCount(Val: Integer);
begin
  Assert(Val >= 0);
  if Val > FCapacity then
    SetCapacity(Val);
  if (Val > FCount) and (bloSetCountResetsMemory in FOptions) then
    FillChar(FBaseList[FItemSize * FCount], (Val - FCount) * FItemSize, 0);
  FCount := Val;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.SetCapacity(newCapacity: Integer);
begin
  if newCapacity <> FCapacity then
  begin
    if bloExternalMemory in FOptions then
    begin
      Exclude(FOptions, bloExternalMemory);
      FBaseList := nil;
    end;
    ReallocMem(FBaseList, newCapacity * FItemSize);
    FCapacity := newCapacity;
    Inc(FRevision);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.AddNulls(nbVals: Cardinal);
begin
  if Integer(nbVals) + Count > Capacity then
    SetCapacity(Integer(nbVals) + Count);
  FillChar(FBaseList[FCount * FItemSize], Integer(nbVals) * FItemSize, 0);
  FCount := FCount + Integer(nbVals);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.InsertNulls(Index: Integer; nbVals: Cardinal);
var
  nc: Integer;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if nbVals > 0 then
  begin
    nc := FCount + Integer(nbVals);
    if nc > FCapacity then
      SetCapacity(nc);
    if Index < FCount then
      System.Move(FBaseList[Index * FItemSize],
        FBaseList[(Index + Integer(nbVals)) * FItemSize],
        (FCount - Index) * FItemSize);
    FillChar(FBaseList[Index * FItemSize], Integer(nbVals) * FItemSize, 0);
    FCount := nc;
    Inc(FRevision);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.AdjustCapacityToAtLeast(const size: Integer);
begin
  if Capacity < size then
    Capacity := size;
end;

//---------------------------------------------------------------------------
function TGSBaseList.DataSize: Integer;
begin
  Result := FItemSize * FCount;
end;

//---------------------------------------------------------------------------
function TGSBaseList.BufferItem: PByteArray;
begin
  if not Assigned(FBufferItem) then
    GetMem(FBufferItem, FItemSize);
  Result := FBufferItem;
end;

//---------------------------------------------------------------------------
function TGSBaseList.GetSetCountResetsMemory: Boolean;
begin
  Result := (bloSetCountResetsMemory in FOptions);
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.SetSetCountResetsMemory(const Val: Boolean);
begin
  if Val then
    Include(FOptions, bloSetCountResetsMemory)
  else
    Exclude(FOptions, bloSetCountResetsMemory);
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.UseMemory(rangeStart: Pointer; rangeCapacity: Integer);
begin
  rangeCapacity := rangeCapacity div FItemSize;
  if rangeCapacity < FCount then
    Exit;
  // transfer data
  System.Move(FBaseList^, rangeStart^, FCount * FItemSize);
  if not (bloExternalMemory in FOptions) then
  begin
    FreeMem(FBaseList);
    Include(FOptions, bloExternalMemory);
  end;
  FBaseList := rangeStart;
  FCapacity := rangeCapacity;
  SetCapacity(FCapacity); // notify subclasses
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.Flush;
begin
  if Assigned(Self) then
  begin
    SetCount(0);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.Clear;
begin
  if Assigned(Self) then
  begin
    SetCount(0);
    SetCapacity(0);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.Delete(Index: Integer);
begin
{$IFOPT R+}
    Assert(Cardinal(index) < Cardinal(FCount));
{$ENDIF}
  Dec(FCount);
  if Index < FCount then
    System.Move(FBaseList[(Index + 1) * FItemSize],
      FBaseList[Index * FItemSize],
      (FCount - Index) * FItemSize);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.DeleteItems(Index: Integer; nbVals: Cardinal);
begin
{$IFOPT R+}
    Assert(Cardinal(index) < Cardinal(FCount));
{$ENDIF}
  if nbVals > 0 then
  begin
    if Index + Integer(nbVals) < FCount then
    begin
      System.Move(FBaseList[(Index + Integer(nbVals)) * FItemSize],
        FBaseList[Index * FItemSize],
        (FCount - Index - Integer(nbVals)) * FItemSize);
    end;
    Dec(FCount, nbVals);
    Inc(FRevision);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.Exchange(index1, index2: Integer);
var
  buf: Integer;
  p:   PIntegerArray;
begin
{$IFOPT R+}
    Assert((Cardinal(index1) < Cardinal(FCount)) and (Cardinal(index2) < Cardinal(FCount)));
{$ENDIF}
  if FItemSize = 4 then
  begin
    p := PIntegerArray(FBaseList);
    buf := p^[index1];
    p^[index1] := p^[index2];
    p^[index2] := buf;
  end
  else
  begin
    System.Move(FBaseList[index1 * FItemSize], BufferItem[0], FItemSize);
    System.Move(FBaseList[index2 * FItemSize], FBaseList[index1 * FItemSize], FItemSize);
    System.Move(BufferItem[0], FBaseList[index2 * FItemSize], FItemSize);
  end;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.Move(curIndex, newIndex: Integer);
begin
  if curIndex <> newIndex then
  begin
{$IFOPT R+}
        Assert(Cardinal(newIndex) < Cardinal(Count));
        Assert(Cardinal(curIndex) < Cardinal(Count));
{$ENDIF}
    if FItemSize = 4 then
      PInteger(BufferItem)^ := PInteger(@FBaseList[curIndex * FItemSize])^
    else
      System.Move(FBaseList[curIndex * FItemSize], BufferItem[0], FItemSize);
    if curIndex < newIndex then
    begin
      // curIndex+1 necessarily exists since curIndex<newIndex and newIndex<Count
      System.Move(FBaseList[(curIndex + 1) * FItemSize], FBaseList[curIndex * FItemSize],
        (newIndex - curIndex) * FItemSize);
    end
    else
    begin
      // newIndex+1 necessarily exists since newIndex<curIndex and curIndex<Count
      System.Move(FBaseList[newIndex * FItemSize], FBaseList[(newIndex + 1) * FItemSize],
        (curIndex - newIndex) * FItemSize);
    end;
    if FItemSize = 4 then
      PInteger(@FBaseList[newIndex * FItemSize])^ := PInteger(BufferItem)^
    else
      System.Move(BufferItem[0], FBaseList[newIndex * FItemSize], FItemSize);
    Inc(FRevision);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSBaseList.Reverse;
var
  s, e: Integer;
begin
  s := 0;
  e := Count - 1;
  while s < e do
  begin
    Exchange(s, e);
    Inc(s);
    Dec(e);
  end;
  Inc(FRevision);
end;

// ------------------
// ------------------ TGSBaseVectorList ------------------
// ------------------
procedure TGSBaseVectorList.WriteToFiler(writer: TGSVirtualWriter);
begin
  inherited;
  if Self is TGSTexPointList then
    exit;
  with writer do
  begin
    WriteInteger(0); // Archive Version 0
    // nothing
  end;
end;

//---------------------------------------------------------------------------
procedure TGSBaseVectorList.ReadFromFiler(reader: TGSVirtualReader);
var
  archiveVersion: Integer;
begin
  inherited;
  if Self is TGSTexPointList then
    exit;
  archiveVersion := reader.ReadInteger;
  if archiveVersion = 0 then
    with reader do
    begin
      // nothing
    end
  else
    RaiseFilerException(archiveVersion);
end;

//---------------------------------------------------------------------------
procedure TGSBaseVectorList.GetExtents(out min, max: TAffineVector);
var
  I, K: Integer;
  f:    Single;
  ref:  PFloatArray;
const
  cBigValue: Single   = 1E50;
  cSmallValue: Single = -1E50;
begin
  SetVector(min, cBigValue, cBigValue, cBigValue);
  SetVector(max, cSmallValue, cSmallValue, cSmallValue);
  for I := 0 to Count - 1 do
  begin
    ref := ItemAddress[I];
    for K := 0 to 2 do
    begin
      f := ref^[K];
      if f < min.V[K] then
        min.V[K] := f;
      if f > max.V[K] then
        max.V[K] := f;
    end;
  end;
end;

//---------------------------------------------------------------------------
function TGSBaseVectorList.Sum: TAffineVector;
var
  I: Integer;
begin
  Result := NullVector;
  for I := 0 to Count - 1 do
    AddVector(Result, PAffineVector(ItemAddress[I])^);
end;

//---------------------------------------------------------------------------
procedure TGSBaseVectorList.Normalize;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    NormalizeVector(PAffineVector(ItemAddress[I])^);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSBaseVectorList.MaxSpacing(list2: TGSBaseVectorList): Single;
var
  I: Integer;
  s: Single;
begin
  Assert(list2.Count = Count);
  Result := 0;
  for I := 0 to Count - 1 do
  begin
    s := VectorSpacing(PAffineVector(ItemAddress[I])^,
      PAffineVector(list2.ItemAddress[I])^);
    if s > Result then
      Result := s;
  end;
end;

//---------------------------------------------------------------------------
procedure TGSBaseVectorList.Translate(const delta: TAffineVector);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    AddVector(PAffineVector(ItemAddress[I])^, delta);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSBaseVectorList.Translate(const delta: TGSBaseVectorList);
var
  I: Integer;
begin
  Assert(Count <= delta.Count);
  for I := 0 to Count - 1 do
    AddVector(PAffineVector(ItemAddress[I])^, PAffineVector(delta.ItemAddress[I])^);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSBaseVectorList.TranslateInv(const delta: TGSBaseVectorList);
var
  I: Integer;
begin
  Assert(Count <= delta.Count);
  for I := 0 to Count - 1 do
    SubtractVector(PAffineVector(ItemAddress[I])^, PAffineVector(delta.ItemAddress[I])^);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSBaseVectorList.AngleLerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single);
var
  I: Integer;
begin
  Assert(list1.Count = list2.Count);
  if list1 <> list2 then
  begin
    if lerpFactor = 0 then
      Assign(list1)
    else
    if lerpFactor = 1 then
      Assign(list2)
    else
    begin
      Capacity := list1.Count;
      FCount := list1.Count;
      for I := 0 to list1.Count - 1 do
        PAffineVector(ItemAddress[I])^ := VectorAngleLerp(PAffineVector(list1.ItemAddress[I])^,
          PAffineVector(list2.ItemAddress[I])^,
          lerpFactor);
    end;
  end
  else
    Assign(list1);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSBaseVectorList.AngleCombine(const list1: TGSBaseVectorList; intensity: Single);
var
  I: Integer;
begin
  Assert(list1.Count = Count);
  for I := 0 to Count - 1 do
    PAffineVector(ItemAddress[I])^ := VectorAngleCombine(PAffineVector(ItemAddress[I])^,
      PAffineVector(list1.ItemAddress[I])^,
      intensity);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSBaseVectorList.Combine(const list2: TGSBaseVectorList; factor: Single);
var
  I: Integer;
begin
  Assert(list2.Count >= Count);
  for I := 0 to Count - 1 do
    CombineVector(PAffineVector(ItemAddress[I])^,
      PAffineVector(list2.ItemAddress[I])^,
      factor);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSBaseVectorList.GetItemAddress(Index: Integer): PFloatArray;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := PFloatArray(@FBaseList[Index * FItemSize]);
end;

// ------------------
// ------------------ TGSAffineVectorList ------------------
// ------------------
constructor TGSAffineVectorList.Create;
begin
  FItemSize := SizeOf(TAffineVector);
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Assign(Src: TPersistent);
begin
  if Assigned(Src) then
  begin
    inherited;
    if (Src is TGSAffineVectorList) then
      System.Move(TGSAffineVectorList(Src).FList^, FList^, FCount * SizeOf(TAffineVector));
  end
  else
    Clear;
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.Add(const item: TAffineVector): Integer;
var LItem: TAffineVector;
begin
  Result := FCount;
  if Result = FCapacity then
  begin
    LItem := item;
    SetCapacity(FCapacity + FGrowthDelta);
	FList^[Result] := LItem;
  end
  else
  FList^[Result] := Item;
  Inc(FCount);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.Add(const item: TGSVector): Integer;
begin
  Result := Add(PAffineVector(@item)^);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Add(const i1, i2: TAffineVector);
begin
  Inc(FCount, 2);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[FCount - 2] := i1;
  FList^[FCount - 1] := i2;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Add(const i1, i2, i3: TAffineVector);
begin
  Inc(FCount, 3);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[FCount - 3] := i1;
  FList^[FCount - 2] := i2;
  FList^[FCount - 1] := i3;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.Add(const item: TVector2f): Integer;
begin
  Result := Add(AffineVectorMake(item.X, item.Y, 0));
end;

function TGSAffineVectorList.Add(const item: TTexPoint): Integer;
begin
  Result := Add(AffineVectorMake(item.S, item.T, 0));
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.Add(const X, Y: Single): Integer;
var
  v: PAffineVector;
begin
  Result := FCount;
  Inc(FCount);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  v := @List[Result];
  v^.X := X;
  v^.Y := Y;
  v^.Z := 0;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.Add(const X, Y, Z: Single): Integer;
var
  v: PAffineVector;
begin
  Result := FCount;
  Inc(FCount);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  v := @List[Result];
  v^.X := X;
  v^.Y := Y;
  v^.Z := Z;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.Add(const X, Y, Z: Integer): Integer;
var
  v: PAffineVector;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  v := @List[Result];
  v^.X := X;
  v^.Y := Y;
  v^.Z := Z;
  Inc(FCount);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.AddNC(const X, Y, Z: Integer): Integer;
var
  v: PAffineVector;
begin
  Result := FCount;
  v := @List[Result];
  v^.X := X;
  v^.Y := Y;
  v^.Z := Z;
  Inc(FCount);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.Add(const xy: PIntegerArray; const Z: Integer): Integer;
var
  v: PAffineVector;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  v := @List[Result];
  v^.X := xy^[0];
  v^.Y := xy^[1];
  v^.Z := Z;
  Inc(FCount);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.AddNC(const xy: PIntegerArray; const Z: Integer): Integer;
var
  v: PAffineVector;
begin
  Result := FCount;
  v := @List[Result];
  v^.X := xy^[0];
  v^.Y := xy^[1];
  v^.Z := Z;
  Inc(FCount);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Add(const list: TGSAffineVectorList);
begin
  if Assigned(list) and (list.Count > 0) then
  begin
    if Count + list.Count > Capacity then
      Capacity := Count + list.Count;
    System.Move(list.FList[0], FList[Count], list.Count * SizeOf(TAffineVector));
    Inc(FCount, list.Count);
  end;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.Get(Index: Integer): TAffineVector;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := FList^[Index];
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Insert(Index: Integer; const Item: TAffineVector);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[Index], FList[Index + 1],
      (FCount - Index) * SizeOf(TAffineVector));
  FList^[Index] := Item;
  Inc(FCount);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.IndexOf(const item: TAffineVector): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to Count - 1 do
    if VectorEquals(item, FList^[I]) then
    begin
      Result := I;
      Break;
    end;
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.FindOrAdd(const item: TAffineVector): Integer;
begin
  Result := IndexOf(item);
  if Result < 0 then
  begin
    Result := Add(item);
    Inc(FRevision);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Put(Index: Integer; const Item: TAffineVector);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  FList^[Index] := Item;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.SetCapacity(NewCapacity: Integer);
begin
  inherited;
  FList := PAffineVectorArray(FBaseList);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Push(const Val: TAffineVector);
begin
  Add(Val);
end;

//---------------------------------------------------------------------------
function TGSAffineVectorList.Pop: TAffineVector;
begin
  if FCount > 0 then
  begin
    Result := Get(FCount - 1);
    Delete(FCount - 1);
    Inc(FRevision);
  end
  else
    Result := NullVector;
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Translate(const delta: TAffineVector);
begin
  VectorArrayAdd(FList, delta, Count, FList);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Translate(const delta: TAffineVector; base, nb: Integer);
begin
  VectorArrayAdd(@FList[base], delta, nb, @FList[base]);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.TranslateItem(Index: Integer; const delta: TAffineVector);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  AddVector(FList^[Index], delta);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.TranslateItems(Index: Integer; const delta: TAffineVector; nb: Integer);
begin
  nb := Index + nb;
{$IFOPT R+}
    Assert(Cardinal(index) < Cardinal(FCount));
    if nb > FCount then
        nb := FCount;
{$ENDIF}
  VectorArrayAdd(@FList[Index], delta, nb - Index, @FList[Index]);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.CombineItem(Index: Integer; const vector: TAffineVector; const f: Single);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  CombineVector(FList^[Index], vector, @f);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.TransformAsPoints(const matrix: TGSMatrix);
var
  I: Integer;
begin
  for I := 0 to FCount - 1 do
    FList^[I] := VectorTransform(FList^[I], matrix);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.TransformAsVectors(const matrix: TGSMatrix);
var
  m: TAffineMatrix;
begin
  if FCount > 0 then
  begin
    SetMatrix(m, matrix);
    TransformAsVectors(m);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.TransformAsVectors(const matrix: TAffineMatrix);
var
  I: Integer;
begin
  for I := 0 to FCount - 1 do
    FList^[I] := VectorTransform(FList^[I], matrix);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Normalize;
begin
  NormalizeVectorArray(List, Count);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Lerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single);
begin
  if (list1 is TGSAffineVectorList) and (list2 is TGSAffineVectorList) then
  begin
    Assert(list1.Count = list2.Count);
    Capacity := list1.Count;
    FCount := list1.Count;
    VectorArrayLerp(TGSAffineVectorList(list1).List, TGSAffineVectorList(list2).List,
      lerpFactor, FCount, List);
    Inc(FRevision);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Scale(factor: Single);
begin
  if (Count > 0) and (factor <> 1) then
  begin
    ScaleFloatArray(@FList[0].X, Count * 3, factor);
    Inc(FRevision);
  end;
end;

//---------------------------------------------------------------------------
procedure TGSAffineVectorList.Scale(const factors: TAffineVector);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    ScaleVector(FList^[I], factors);
  Inc(FRevision);
end;

// ------------------
// ------------------ TGSVectorList ------------------
// ------------------
constructor TGSVectorList.Create;
begin
  FItemSize := SizeOf(TGSVector);
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

//---------------------------------------------------------------------------
procedure TGSVectorList.Assign(Src: TPersistent);
begin
  if Assigned(Src) then
  begin
    inherited;
    if (Src is TGSVectorList) then
      System.Move(TGSVectorList(Src).FList^, FList^, FCount * SizeOf(TGSVector));
  end
  else
    Clear;
end;

//---------------------------------------------------------------------------
function TGSVectorList.Add(const item: TGSVector): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSVectorList.Add(const item: TAffineVector; w: Single): Integer;
begin
  Result := Add(VectorMake(item, w));
end;

//---------------------------------------------------------------------------
function TGSVectorList.Add(const X, Y, Z, w: Single): Integer;
begin
  Result := Add(VectorMake(X, Y, Z, w));
end;

//---------------------------------------------------------------------------
procedure TGSVectorList.Add(const i1, i2, i3: TAffineVector; w: Single);
begin
  Inc(FCount, 3);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  PAffineVector(@FList[FCount - 3])^ := i1;
  FList^[FCount - 3].W := w;
  PAffineVector(@FList[FCount - 2])^ := i2;
  FList^[FCount - 2].W := w;
  PAffineVector(@FList[FCount - 1])^ := i3;
  FList^[FCount - 1].W := w;
end;

//---------------------------------------------------------------------------
function TGSVectorList.AddVector(const item: TAffineVector): Integer;
begin
  Result := Add(VectorMake(item));
end;

//---------------------------------------------------------------------------
function TGSVectorList.AddPoint(const item: TAffineVector): Integer;
begin
  Result := Add(PointMake(item));
end;

//---------------------------------------------------------------------------
function TGSVectorList.AddPoint(const X, Y: Single; const Z: Single = 0): Integer;
begin
  Result := Add(PointMake(X, Y, Z));
end;

//---------------------------------------------------------------------------
function TGSVectorList.Get(Index: Integer): TGSVector;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := FList^[Index];
end;

//---------------------------------------------------------------------------
procedure TGSVectorList.Insert(Index: Integer; const Item: TGSVector);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[Index], FList[Index + 1],
      (FCount - Index) * SizeOf(TGSVector));
  FList^[Index] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSVectorList.Put(Index: Integer; const Item: TGSVector);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  FList^[Index] := Item;
end;

//---------------------------------------------------------------------------
procedure TGSVectorList.SetCapacity(NewCapacity: Integer);
begin
  inherited;
  FList := PVectorArray(FBaseList);
end;

//---------------------------------------------------------------------------
procedure TGSVectorList.Push(const Val: TGSVector);
begin
  Add(Val);
end;

//---------------------------------------------------------------------------
function TGSVectorList.Pop: TGSVector;
begin
  if FCount > 0 then
  begin
    Result := Get(FCount - 1);
    Delete(FCount - 1);
  end
  else
    Result := NullHmgVector;
end;

//---------------------------------------------------------------------------
function TGSVectorList.IndexOf(const item: TGSVector): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to Count - 1 do
    if VectorEquals(item, FList^[I]) then
    begin
      Result := I;
      Break;
    end;
end;

//---------------------------------------------------------------------------
function TGSVectorList.FindOrAdd(const item: TGSVector): Integer;
begin
  Result := IndexOf(item);
  if Result < 0 then
    Result := Add(item);
end;

//---------------------------------------------------------------------------
function TGSVectorList.FindOrAddPoint(const item: TAffineVector): Integer;
var
  ptItem: TGSVector;
begin
  MakePoint(ptItem, item);
  Result := IndexOf(ptItem);
  if Result < 0 then
    Result := Add(ptItem);
end;

//---------------------------------------------------------------------------
procedure TGSVectorList.Lerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single);
begin
  if (list1 is TGSVectorList) and (list2 is TGSVectorList) then
  begin
    Assert(list1.Count = list2.Count);
    Capacity := list1.Count;
    FCount := list1.Count;
    VectorArrayLerp(TGSVectorList(list1).List, TGSVectorList(list2).List,
      lerpFactor, FCount, List);
  end;
end;

// ------------------
// ------------------ TGSTexPointList ------------------
// ------------------
constructor TGSTexPointList.Create;
begin
  FItemSize := SizeOf(TTexPoint);
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

//---------------------------------------------------------------------------
procedure TGSTexPointList.Assign(Src: TPersistent);
begin
  if Assigned(Src) then
  begin
    inherited;
    if (Src is TGSTexPointList) then
      System.Move(TGSTexPointList(Src).FList^, FList^, FCount * SizeOf(TTexPoint));
  end
  else
    Clear;
end;

//---------------------------------------------------------------------------
function TGSTexPointList.IndexOf(const item: TTexpoint): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to Count - 1 do
    if TexpointEquals(FList^[I], item) then
    begin
      Result := I;
      Break;
    end;
end;

//---------------------------------------------------------------------------
function TGSTexPointList.FindOrAdd(const item: TTexPoint): Integer;
begin
  Result := IndexOf(item);
  if Result < 0 then
    Result := Add(item);
end;

//---------------------------------------------------------------------------
function TGSTexPointList.Add(const item: TTexPoint): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSTexPointList.Add(const item: TVector2f): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := PTexPoint(@Item)^;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSTexPointList.Add(const texS, Text: Single): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  with FList^[Result] do
  begin
    s := texS;
    t := Text;
  end;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSTexPointList.Add(const texS, Text: Integer): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  with FList^[Result] do
  begin
    s := texS;
    t := Text;
  end;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSTexPointList.AddNC(const texS, Text: Integer): Integer;
begin
  Result := FCount;
  with FList^[Result] do
  begin
    s := texS;
    t := Text;
  end;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSTexPointList.Add(const texST: PIntegerArray): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  with FList^[Result] do
  begin
    s := texST^[0];
    t := texST^[1];
  end;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSTexPointList.AddNC(const texST: PIntegerArray): Integer;
begin
  Result := FCount;
  with FList^[Result] do
  begin
    s := texST^[0];
    t := texST^[1];
  end;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSTexPointList.Get(Index: Integer): TTexPoint;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := FList^[Index];
end;

//---------------------------------------------------------------------------
procedure TGSTexPointList.Insert(Index: Integer; const Item: TTexPoint);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[Index], FList[Index + 1],
      (FCount - Index) * SizeOf(TTexPoint));
  FList^[Index] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSTexPointList.Put(Index: Integer; const Item: TTexPoint);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  FList^[Index] := Item;
end;

//---------------------------------------------------------------------------
procedure TGSTexPointList.SetCapacity(NewCapacity: Integer);
begin
  inherited;
  FList := PTexPointArray(FBaseList);
end;

//---------------------------------------------------------------------------
procedure TGSTexPointList.Push(const Val: TTexPoint);
begin
  Add(Val);
end;

//---------------------------------------------------------------------------
function TGSTexPointList.Pop: TTexPoint;
begin
  if FCount > 0 then
  begin
    Result := Get(FCount - 1);
    Delete(FCount - 1);
  end
  else
    Result := NullTexPoint;
end;

//---------------------------------------------------------------------------
procedure TGSTexPointList.Translate(const delta: TTexPoint);
begin
  TexPointArrayAdd(List, delta, FCount, FList);
end;

//---------------------------------------------------------------------------
procedure TGSTexPointList.ScaleAndTranslate(const scale, delta: TTexPoint);
begin
  TexPointArrayScaleAndAdd(FList, delta, FCount, scale, FList);
end;

//---------------------------------------------------------------------------
procedure TGSTexPointList.ScaleAndTranslate(const scale, delta: TTexPoint; base, nb: Integer);
var
  p: PTexPointArray;
begin
  p := @FList[base];
  TexPointArrayScaleAndAdd(p, delta, nb, scale, p);
end;

//---------------------------------------------------------------------------
procedure TGSTexPointList.Lerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single);
begin
  if (list1 is TGSTexPointList) and (list2 is TGSTexPointList) then
  begin
    Assert(list1.Count = list2.Count);
    Capacity := list1.Count;
    FCount := list1.Count;
    VectorArrayLerp(TGSTexPointList(list1).List, TGSTexPointList(list2).List,
      lerpFactor, FCount, List);
  end;
end;

// ------------------
// ------------------ TGSIntegerList ------------------
// ------------------
constructor TGSIntegerList.Create;
begin
  FItemSize := SizeOf(Integer);
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Assign(Src: TPersistent);
begin
  if Assigned(Src) then
  begin
    inherited;
    if (Src is TGSIntegerList) then
      System.Move(TGSIntegerList(Src).FList^, FList^, FCount * SizeOf(Integer));
  end
  else
    Clear;
end;

//---------------------------------------------------------------------------
function TGSIntegerList.Add(const item: Integer): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSIntegerList.AddNC(const item: Integer): Integer;
begin
  Result := FCount;
  FList^[Result] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Add(const i1, i2: Integer);
var
  tmpList : PIntegerArray;
begin
  Inc(FCount, 2);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 2];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Add(const i1, i2, i3: Integer);
var
  tmpList : PIntegerArray;
begin
  Inc(FCount, 3);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 3];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  tmpList^[2] := i3;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Add(const AList: TGSIntegerList);
begin
  if Assigned(AList) and (AList.Count > 0) then
  begin
    if Count + AList.Count > Capacity then
      Capacity := Count + AList.Count;
    System.Move(AList.FList[0], FList[Count], AList.Count * SizeOf(Integer));
    Inc(FCount, AList.Count);
  end;
end;

//---------------------------------------------------------------------------
function TGSIntegerList.Get(Index: Integer): Integer;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := FList^[Index];
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Insert(Index: Integer; const Item: Integer);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[Index], FList[Index + 1], (FCount - Index) * SizeOf(Integer));
  FList^[Index] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Remove(const item: Integer);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    if FList^[I] = item then
    begin
      System.Move(FList[I + 1], FList[I], (FCount - 1 - I) * SizeOf(Integer));
      Dec(FCount);
      Break;
    end;
  end;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Put(Index: Integer; const Item: Integer);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  FList^[Index] := Item;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.SetCapacity(NewCapacity: Integer);
begin
  inherited;
  FList := PIntegerArray(FBaseList);
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Push(const Val: Integer);
begin
  Add(Val);
end;

//---------------------------------------------------------------------------
function TGSIntegerList.Pop: Integer;
begin
  if FCount > 0 then
  begin
    Result := FList^[FCount - 1];
    Delete(FCount - 1);
  end
  else
    Result := 0;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.AddSerie(aBase, aDelta, aCount: Integer);
var
  tmpList : PInteger;
  I:    Integer;
begin
  if aCount <= 0 then
    Exit;
  AdjustCapacityToAtLeast(Count + aCount);
  tmpList := @FList[Count];
  for I := Count to Count + aCount - 1 do
  begin
    tmpList^ := aBase;
    Inc(tmpList);
    aBase := aBase + aDelta;
  end;
  FCount := Count + aCount;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.AddIntegers(const First: PInteger; n: Integer);
begin
  if n < 1 then
    Exit;
  AdjustCapacityToAtLeast(Count + n);
  System.Move(First^, FList[FCount], n * SizeOf(Integer));
  FCount := FCount + n;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.AddIntegers(const aList: TGSIntegerList);
begin
  if not Assigned(aList) then
    Exit;
  AddIntegers(@aList.List[0], aList.Count);
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.AddIntegers(const anArray: array of Integer);
var
  n: Integer;
begin
  n := Length(anArray);
  if n > 0 then
    AddIntegers(@anArray[0], n);
end;

//---------------------------------------------------------------------------
function IntegerSearch(item: Integer; list: PIntegerVector; Count: Integer): Integer; register; inline;
var i : integer;
begin
  result:=-1;
  for i := 0 to Count-1 do begin
    if list^[i]=item then begin
      result:=i;
      break;
    end;
  end;
end;

//---------------------------------------------------------------------------
function TGSIntegerList.IndexOf(item: Integer): Integer; register;
begin
  Result := IntegerSearch(item, FList, FCount);
end;

//---------------------------------------------------------------------------
function TGSIntegerList.MinInteger: Integer;
var
  I: Integer;
  locList: PIntegerVector;
begin
  if FCount > 0 then
  begin
    locList := FList;
    Result := locList^[0];
    for I := 1 to FCount - 1 do
      if locList^[I] < Result then
        Result := locList^[I];
  end
  else
    Result := 0;
end;

//---------------------------------------------------------------------------
function TGSIntegerList.MaxInteger: Integer;
var
  I: Integer;
  locList: PIntegerVector;
begin
  if FCount > 0 then
  begin
    locList := FList;
    Result := locList^[0];
    for I := 1 to FCount - 1 do
      if locList^[I] > Result then
        Result := locList^[I];
  end
  else
    Result := 0;
end;

//---------------------------------------------------------------------------
procedure IntegerQuickSort(sortList: PIntegerArray; left, right: Integer);
var
  I, J: Integer;
  p, t: Integer;
begin
  repeat
    I := left;
    J := right;
    p := sortList^[(left + right) shr 1];
    repeat
      while sortList^[I] < p do
        Inc(I);
      while sortList^[J] > p do
        Dec(J);
      if I <= J then
      begin
        t := sortList^[I];
        sortList^[I] := sortList^[J];
        sortList^[J] := t;
        Inc(I);
        Dec(J);
      end;
    until I > J;
    if left < J then
      IntegerQuickSort(sortList, left, J);
    left := I;
  until I >= right;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Sort;
begin
  if (FList <> nil) and (Count > 1) then
    IntegerQuickSort(FList, 0, Count - 1);
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.SortAndRemoveDuplicates;
var
  I, J, lastVal: Integer;
  localList:     PIntegerArray;
begin
  if (FList <> nil) and (Count > 1) then
  begin
    IntegerQuickSort(FList, 0, Count - 1);
    J := 0;
    localList := FList;
    lastVal := localList^[J];
    for I := 1 to Count - 1 do
    begin
      if localList^[I] <> lastVal then
      begin
        lastVal := localList^[I];
        Inc(J);
        localList^[J] := lastVal;
      end;
    end;
    FCount := J + 1;
  end;
end;

//---------------------------------------------------------------------------
function TGSIntegerList.BinarySearch(const Value: Integer): Integer;
var
  found: Boolean;
begin
  Result := BinarySearch(Value, False, found);
end;

//---------------------------------------------------------------------------
function TGSIntegerList.BinarySearch(const Value: Integer; returnBestFit: Boolean; var found: Boolean): Integer;
var
  Index:   Integer;
  min, max, mid: Integer;
  intList: PIntegerArray;
begin
  // Assume we won't find it
  found := False;
  // If the list is empty, we won't find the sought value!
  if Count = 0 then
  begin
    Result := -1;
    Exit;
  end;

  min := -1; // ONE OFF!
  max := Count; // ONE OFF!

  // We now know that Min and Max AREN'T the values!
  Index := -1;
  intList := List;
  repeat
    // Find the middle of the current scope
    mid := (min + max) shr 1;
    // Reduce the search scope by half
    if intList^[mid] <= Value then
    begin
      // Is this the one?
      if intList^[mid] = Value then
      begin
        Index := mid;
        found := True;
        Break;
      end
      else
        min := mid;
    end
    else
      max := mid;
  until min + 1 = max;

  if returnBestFit then
  begin
    if Index >= 0 then
      Result := Index
    else
      Result := min;
  end
  else
    Result := Index;
end;

//---------------------------------------------------------------------------
function TGSIntegerList.AddSorted(const Value: Integer; const ignoreDuplicates: Boolean = False): Integer;
var
  Index: Integer;
  found: Boolean;
begin
  Index := BinarySearch(Value, True, found);
  if ignoreDuplicates and Found then
    Result := -1
  else
  begin
    Insert(Index + 1, Value);
    Result := Index + 1;
  end;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.RemoveSorted(const Value: Integer);
var
  Index: Integer;
begin
  Index := BinarySearch(Value);
  if Index >= 0 then
    Delete(Index);
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Offset(delta: Integer);
var
  I: Integer;
  locList: PIntegerArray;
begin
  locList := FList;
  for I := 0 to FCount - 1 do
    locList^[I] := locList^[I] + delta;
end;

//---------------------------------------------------------------------------
procedure TGSIntegerList.Offset(delta: Integer; const base, nb: Integer);
var
  I: Integer;
  locList: PIntegerArray;
begin
  locList := FList;
  for I := base to base + nb - 1 do
    locList^[I] := locList^[I] + delta;
end;

// ------------------
// ------------------ TGSSingleList ------------------
// ------------------
constructor TGSSingleList.Create;
begin
  FItemSize := SizeOf(Single);
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.Assign(Src: TPersistent);
begin
  if Assigned(Src) then
  begin
    inherited;
    if (Src is TGSSingleList) then
      System.Move(TGSSingleList(Src).FList^, FList^, FCount * SizeOf(Single));
  end
  else
    Clear;
end;

//---------------------------------------------------------------------------
function TGSSingleList.Add(const item: Single): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.Add(const i1, i2: Single);
var
  tmpList : PSingleArray;
begin
  Inc(FCount, 2);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 2];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.AddSingles(const First: PSingle; n: Integer);
begin
  if n < 1 then
    Exit;
  AdjustCapacityToAtLeast(Count + n);
  System.Move(First^, FList[FCount], n * SizeOf(Single));
  FCount := FCount + n;
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.AddSingles(const anArray: array of Single);
var
  n: Integer;
begin
  n := Length(anArray);
  if n > 0 then
    AddSingles(@anArray[0], n);
end;

//---------------------------------------------------------------------------
function TGSSingleList.Get(Index: Integer): Single;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := FList^[Index];
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.Insert(Index: Integer; const Item: Single);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[Index], FList[Index + 1],
      (FCount - Index) * SizeOf(Single));
  FList^[Index] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.Put(Index: Integer; const Item: Single);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  FList^[Index] := Item;
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.SetCapacity(NewCapacity: Integer);
begin
  inherited;
  FList := PGSSingleArrayList(FBaseList);
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.Push(const Val: Single);
begin
  Add(Val);
end;

//---------------------------------------------------------------------------
function TGSSingleList.Pop: Single;
begin
  if FCount > 0 then
  begin
    Result := Get(FCount - 1);
    Delete(FCount - 1);
  end
  else
    Result := 0;
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.AddSerie(aBase, aDelta: Single; aCount: Integer);
var
  tmpList : PSingle;
  I:    Integer;
begin
  if aCount <= 0 then
    Exit;
  AdjustCapacityToAtLeast(Count + aCount);
  tmpList := @FList[Count];
  for I := Count to Count + aCount - 1 do
  begin
    tmpList^ := aBase;
    Inc(tmpList);
    aBase := aBase + aDelta;
  end;
  FCount := Count + aCount;
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.Offset(delta: Single);
begin
  OffsetFloatArray(PFloatVector(FList), FCount, delta);
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.Offset(const delta: TGSSingleList);
begin
  if FCount = delta.FCount then
    OffsetFloatArray(PFloatVector(FList), PFloatVector(delta.FList), FCount)
  else
    raise Exception.Create('SingleList count do not match');
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.Scale(factor: Single);
begin
  ScaleFloatArray(PFloatVector(FList), FCount, factor);
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.Sqr;
var
  I: Integer;
  locList: PGSSingleArrayList;
begin
  locList := FList;
  for I := 0 to Count - 1 do
    locList^[I] := locList^[I] * locList^[I];
end;

//---------------------------------------------------------------------------
procedure TGSSingleList.Sqrt;
var
  I: Integer;
  locList: PGSSingleArrayList;
begin
  locList := FList;
  for I := 0 to Count - 1 do
    locList^[I] := System.Sqrt(locList^[I]);
end;

//---------------------------------------------------------------------------
function TGSSingleList.Sum: Single;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to FCount-1 do
    Result := Result + FList^[i];
end;

//---------------------------------------------------------------------------
function TGSSingleList.Min: Single;
var
  I: Integer;
  locList: PGSSingleArrayList;
begin
  if FCount > 0 then
  begin
    locList := FList;
    Result := locList^[0];
    for I := 1 to FCount - 1 do
      if locList^[I] < Result then
        Result := locList^[I];
  end
  else
    Result := 0;
end;

//---------------------------------------------------------------------------
function TGSSingleList.Max: Single;
var
  I: Integer;
  locList: PGSSingleArrayList;
begin
  if FCount > 0 then
  begin
    locList := FList;
    Result := locList^[0];
    for I := 1 to FCount - 1 do
      if locList^[I] > Result then
        Result := locList^[I];
  end
  else
    Result := 0;
end;

// ------------------
// ------------------ TGSByteList ------------------
// ------------------
constructor TGSByteList.Create;
begin
  FItemSize := SizeOf(Byte);
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

//---------------------------------------------------------------------------
procedure TGSByteList.Assign(Src: TPersistent);
begin
  if Assigned(Src) then
  begin
    inherited;
    if (Src is TGSByteList) then
      System.Move(TGSByteList(Src).FList^, FList^, FCount * SizeOf(Byte));
  end
  else
    Clear;
end;

//---------------------------------------------------------------------------
function TGSByteList.Add(const item: Byte): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSByteList.Get(Index: Integer): Byte;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := FList^[Index];
end;

//---------------------------------------------------------------------------
procedure TGSByteList.Insert(Index: Integer; const Item: Byte);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[Index], FList[Index + 1],
      (FCount - Index) * SizeOf(Byte));
  FList^[Index] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSByteList.Put(Index: Integer; const Item: Byte);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  FList^[Index] := Item;
end;

//---------------------------------------------------------------------------
procedure TGSByteList.SetCapacity(NewCapacity: Integer);
begin
  inherited;
  FList := PByteArray(FBaseList);
end;

// ------------------
// ------------------ TGSDoubleList ------------------
// ------------------
constructor TGSDoubleList.Create;
begin
  FItemSize := SizeOf(Double);
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.Assign(Src: TPersistent);
begin
  if Assigned(Src) then
  begin
    inherited;
    if (Src is TGSDoubleList) then
      System.Move(TGSDoubleList(Src).FList^, FList^, FCount * SizeOf(Double));
  end
  else
    Clear;
end;

//---------------------------------------------------------------------------
function TGSDoubleList.Add(const item: Double): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSDoubleList.Get(Index: Integer): Double;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := FList^[Index];
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.Insert(Index: Integer; const Item: Double);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[Index], FList[Index + 1],
      (FCount - Index) * SizeOf(Double));
  FList^[Index] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.Put(Index: Integer; const Item: Double);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  FList^[Index] := Item;
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.SetCapacity(NewCapacity: Integer);
begin
  inherited;
  FList := PGSDoubleArrayList(FBaseList);
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.Push(const Val: Double);
begin
  Add(Val);
end;

//---------------------------------------------------------------------------
function TGSDoubleList.Pop: Double;
begin
  if FCount > 0 then
  begin
    Result := Get(FCount - 1);
    Delete(FCount - 1);
  end
  else
    Result := 0;
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.AddSerie(aBase, aDelta: Double; aCount: Integer);
var
  tmpList: PDouble;
  I:    Integer;
begin
  if aCount <= 0 then
    Exit;
  AdjustCapacityToAtLeast(Count + aCount);
  tmpList := @FList[Count];
  for I := Count to Count + aCount - 1 do
  begin
    tmpList^ := aBase;
    Inc(tmpList);
    aBase := aBase + aDelta;
  end;
  FCount := Count + aCount;
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.Offset(delta: Double);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    FList^[I] := FList^[I] + delta;
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.Offset(const delta: TGSDoubleList);
var
  I: Integer;
begin
  if FCount = delta.FCount then
    for I := 0 to Count - 1 do
      FList^[I] := FList^[I] + delta[I]
  else
    raise Exception.Create('DoubleList count do not match');
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.Scale(factor: Double);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    FList^[I] := FList^[I] * factor;
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.Sqr;
var
  I: Integer;
  locList: PGSDoubleArrayList;
begin
  locList := FList;
  for I := 0 to Count - 1 do
    locList^[I] := locList^[I] * locList^[I];
end;

//---------------------------------------------------------------------------
procedure TGSDoubleList.Sqrt;
var
  I: Integer;
  locList: PGSDoubleArrayList;
begin
  locList := FList;
  for I := 0 to Count - 1 do
    locList^[I] := System.Sqrt(locList^[I]);
end;

//---------------------------------------------------------------------------
function TGSDoubleList.Sum: Double;
var
  i: Integer;
begin
    Result := 0;
    for i := 0 to FCount-1 do
    Result := Result + FList^[i];
end;

//---------------------------------------------------------------------------
function TGSDoubleList.Min: Single;
var
  I: Integer;
  locList: PGSDoubleArrayList;
begin
  if FCount > 0 then
  begin
    locList := FList;
    Result := locList^[0];
    for I := 1 to FCount - 1 do
      if locList^[I] < Result then
        Result := locList^[I];
  end
  else
    Result := 0;
end;

//---------------------------------------------------------------------------
function TGSDoubleList.Max: Single;
var
  I: Integer;
  locList: PGSDoubleArrayList;
begin
  if FCount > 0 then
  begin
    locList := FList;
    Result := locList^[0];
    for I := 1 to FCount - 1 do
      if locList^[I] > Result then
        Result := locList^[I];
  end
  else
    Result := 0;
end;

// ------------------
// ------------------ TGSQuaternionList ------------------
// ------------------
constructor TGSQuaternionList.Create;
begin
  FItemSize := SizeOf(TQuaternion);
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

//---------------------------------------------------------------------------
procedure TGSQuaternionList.Assign(Src: TPersistent);
begin
  if Assigned(Src) then
  begin
    inherited;
    if (Src is TGSQuaternionList) then
      System.Move(TGSQuaternionList(Src).FList^, FList^, FCount * SizeOf(TQuaternion));
  end
  else
    Clear;
end;

//---------------------------------------------------------------------------
function TGSQuaternionList.Add(const item: TQuaternion): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSQuaternionList.Add(const item: TAffineVector; w: Single): Integer;
begin
  Result := Add(QuaternionMake([item.X, item.Y, item.Z], w));
end;

//---------------------------------------------------------------------------
function TGSQuaternionList.Add(const X, Y, Z, w: Single): Integer;
begin
  Result := Add(QuaternionMake([X, Y, Z], w));
end;

//---------------------------------------------------------------------------
function TGSQuaternionList.Get(Index: Integer): TQuaternion;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := FList^[Index];
end;

//---------------------------------------------------------------------------
procedure TGSQuaternionList.Insert(Index: Integer; const Item: TQuaternion);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[Index], FList[Index + 1],
      (FCount - Index) * SizeOf(TQuaternion));
  FList^[Index] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSQuaternionList.Put(Index: Integer; const Item: TQuaternion);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  FList^[Index] := Item;
end;

//---------------------------------------------------------------------------
procedure TGSQuaternionList.SetCapacity(NewCapacity: Integer);
begin
  inherited;
  FList := PQuaternionArray(FBaseList);
end;

//---------------------------------------------------------------------------
procedure TGSQuaternionList.Push(const Val: TQuaternion);
begin
  Add(Val);
end;

//---------------------------------------------------------------------------
function TGSQuaternionList.Pop: TQuaternion;
begin
  if FCount > 0 then
  begin
    Result := Get(FCount - 1);
    Delete(FCount - 1);
  end
  else
    Result := IdentityQuaternion;
end;

//---------------------------------------------------------------------------
function TGSQuaternionList.IndexOf(const item: TQuaternion): Integer;
var
  I: Integer;
  curItem: PQuaternion;
begin
  for I := 0 to Count - 1 do
  begin
    curItem := @FList[I];
    if (item.RealPart = curItem^.RealPart) and VectorEquals(item.ImagPart, curItem^.ImagPart) then
    begin
      Result := I;
      Exit;
    end;
  end;
  Result := -1;
end;

//---------------------------------------------------------------------------
function TGSQuaternionList.FindOrAdd(const item: TQuaternion): Integer;
begin
  Result := IndexOf(item);
  if Result < 0 then
    Result := Add(item);
end;

//---------------------------------------------------------------------------
procedure TGSQuaternionList.Lerp(const list1, list2: TGSBaseVectorList; lerpFactor: Single);
var
  I: Integer;
begin
  if (list1 is TGSQuaternionList) and (list2 is TGSQuaternionList) then
  begin
    Assert(list1.Count = list2.Count);
    Capacity := list1.Count;
    FCount := list1.Count;
    for I := 0 to FCount - 1 do
      Put(I, QuaternionSlerp(TGSQuaternionList(list1)[I], TGSQuaternionList(list2)[I], lerpFactor));
  end;
end;

//---------------------------------------------------------------------------
procedure TGSQuaternionList.Combine(const list2: TGSBaseVectorList; factor: Single);

  procedure CombineQuaternion(var q1: TQuaternion; const q2: TQuaternion; factor: Single);
  begin
    q1 := QuaternionMultiply(q1, QuaternionSlerp(IdentityQuaternion, q2, factor));
  end;

var
  I: Integer;
begin
  Assert(list2.Count >= Count);
  if list2 is TGSQuaternionList then
  begin
    for I := 0 to Count - 1 do
    begin
      CombineQuaternion(PQuaternion(ItemAddress[I])^,
        PQuaternion(list2.ItemAddress[I])^,
        factor);
    end;
  end
  else
    inherited;
end;

// ------------------
// ------------------ TGS4ByteList ------------------
// ------------------
constructor TGS4ByteList.Create;
begin
  FItemSize := SizeOf(TGS4ByteList);
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Assign(Src: TPersistent);
begin
  if Assigned(Src) then
  begin
    inherited;
    if (Src is TGS4ByteList) then
      System.Move(TGS4ByteList(Src).FList^, FList^, FCount * SizeOf(TGS4ByteData));
  end
  else
    Clear;
end;

//---------------------------------------------------------------------------
function TGS4ByteList.Add(const item: TGS4ByteData): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := Item;
  Inc(FCount);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1: Single);
var
  tmpList: PSingle;
begin
  Inc(FCount);
  if FCount >= FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 1];
  tmpList^ := i1;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1, i2: Single);
var
  tmpList: PSingleArray;
begin
  Inc(FCount, 2);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 2];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1, i2, i3: Single);
var
  tmpList: PSingleArray;
begin
  Inc(FCount, 3);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 3];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  tmpList^[2] := i3;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1, i2, i3, i4: Single);
var
  tmpList: PSingleArray;
begin
  Inc(FCount, 4);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 4];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  tmpList^[2] := i3;
  tmpList^[3] := i4;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1: Integer);
var
  tmpList: PInteger;
begin
  Inc(FCount);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 1];
  tmpList^ := i1;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1, i2: Integer);
var
  tmpList: PIntegerArray;
begin
  Inc(FCount, 2);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 2];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1, i2, i3: Integer);
var
  tmpList: PIntegerArray;
begin
  Inc(FCount, 3);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 3];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  tmpList^[2] := i3;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1, i2, i3, i4: Integer);
var
  tmpList: PIntegerArray;
begin
  Inc(FCount, 4);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 4];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  tmpList^[2] := i3;
  tmpList^[3] := i4;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1: Cardinal);
var
  tmpList: PLongWord;
begin
  Inc(FCount);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 1];
  tmpList^ := i1;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1, i2: Cardinal);
var
  tmpList: PLongWordArray;
begin
  Inc(FCount, 2);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 2];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1, i2, i3: Cardinal);
var
  tmpList: PLongWordArray;
begin
  Inc(FCount, 3);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 3];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  tmpList^[2] := i3;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const i1, i2, i3, i4: Cardinal);
var
  tmpList: PLongWordArray;
begin
  Inc(FCount, 4);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 4];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  tmpList^[2] := i3;
  tmpList^[3] := i4;
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Add(const AList: TGS4ByteList);
begin
  if Assigned(AList) and (AList.Count > 0) then
  begin
    if Count + AList.Count > Capacity then
      Capacity := Count + AList.Count;
    System.Move(AList.FList[0], FList[Count], AList.Count * SizeOf(TGS4ByteData));
    Inc(FCount, AList.Count);
    Inc(FRevision);
  end;
end;

//---------------------------------------------------------------------------
function TGS4ByteList.Get(Index: Integer): TGS4ByteData;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := FList^[Index];
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Insert(Index: Integer; const Item: TGS4ByteData);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[Index], FList[Index + 1],
      (FCount - Index) * SizeOf(TGS4ByteData));
  FList^[Index] := Item;
  Inc(FCount);
  Inc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Put(Index: Integer; const Item: TGS4ByteData);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  FList^[Index] := Item;
  INc(FRevision);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.SetCapacity(NewCapacity: Integer);
begin
  inherited;
  FList := PGS4ByteArrayList(FBaseList);
end;

//---------------------------------------------------------------------------
procedure TGS4ByteList.Push(const Val: TGS4ByteData);
begin
  Add(Val);
end;

//---------------------------------------------------------------------------
function TGS4ByteList.Pop: TGS4ByteData;
const
  Zero : TGS4ByteData = ( Int: (Value:0) );
begin
  if FCount > 0 then
  begin
    Result := Get(FCount - 1);
    Delete(FCount - 1);
  end
  else
    Result := Zero;
end;

// ------------------
// ------------------ TGSLongWordList ------------------
// ------------------
constructor TGSLongWordList.Create;
begin
  FItemSize := SizeOf(LongWord);
  inherited Create;
  FGrowthDelta := cDefaultListGrowthDelta;
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.Assign(Src: TPersistent);
begin
  if Assigned(Src) then
  begin
    inherited;
    if (Src is TGSLongWordList) then
      System.Move(TGSLongWordList(Src).FList^, FList^, FCount * SizeOf(LongWord));
  end
  else
    Clear;
end;

//---------------------------------------------------------------------------
function TGSLongWordList.Add(const item: LongWord): Integer;
begin
  Result := FCount;
  if Result = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  FList^[Result] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
function TGSLongWordList.AddNC(const item: LongWord): Integer;
begin
  Result := FCount;
  FList^[Result] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.Add(const i1, i2: LongWord);
var
  tmpList : PLongWordArray;
begin
  Inc(FCount, 2);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 2];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.Add(const i1, i2, i3: LongWord);
var
  tmpList : PLongWordArray;
begin
  Inc(FCount, 3);
  while FCount > FCapacity do
    SetCapacity(FCapacity + FGrowthDelta);
  tmpList := @FList[FCount - 3];
  tmpList^[0] := i1;
  tmpList^[1] := i2;
  tmpList^[2] := i3;
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.Add(const AList: TGSLongWordList);
begin
  if Assigned(AList) and (AList.Count > 0) then
  begin
    if Count + AList.Count > Capacity then
      Capacity := Count + AList.Count;
    System.Move(AList.FList[0], FList[Count], AList.Count * SizeOf(LongWord));
    Inc(FCount, AList.Count);
  end;
end;

//---------------------------------------------------------------------------
function TGSLongWordList.Get(Index: Integer): LongWord;
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  Result := FList^[Index];
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.Insert(Index: Integer; const Item: LongWord);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  if FCount = FCapacity then
    SetCapacity(FCapacity + FGrowthDelta);
  if Index < FCount then
    System.Move(FList[Index], FList[Index + 1], (FCount - Index) * SizeOf(LongWord));
  FList^[Index] := Item;
  Inc(FCount);
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.Remove(const item: LongWord);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    if FList^[I] = item then
    begin
      System.Move(FList[I + 1], FList[I], (FCount - 1 - I) * SizeOf(LongWord));
      Dec(FCount);
      Break;
    end;
  end;
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.Put(Index: Integer; const Item: LongWord);
begin
{$IFOPT R+}
    Assert(Cardinal(Index) < Cardinal(FCount));
{$ENDIF}
  FList^[Index] := Item;
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.SetCapacity(NewCapacity: Integer);
begin
  inherited;
  FList := PLongWordArray(FBaseList);
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.Push(const Val: LongWord);
begin
  Add(Val);
end;

//---------------------------------------------------------------------------
function TGSLongWordList.Pop: LongWord;
begin
  if FCount > 0 then
  begin
    Result := FList^[FCount - 1];
    Delete(FCount - 1);
  end
  else
    Result := 0;
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.AddLongWords(const First: PLongWord; n: Integer);
begin
  if n < 1 then
    Exit;
  AdjustCapacityToAtLeast(Count + n);
  System.Move(First^, FList[FCount], n * SizeOf(LongWord));
  FCount := FCount + n;
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.AddLongWords(const aList: TGSLongWordList);
begin
  if not Assigned(aList) then
    Exit;
  AddLongWords(@aList.List[0], aList.Count);
end;

//---------------------------------------------------------------------------
procedure TGSLongWordList.AddLongWords(const anArray: array of LongWord);
var
  n: Integer;
begin
  n := Length(anArray);
  if n > 0 then
    AddLongWords(@anArray[0], n);
end;

//---------------------------------------------------------------------------
function LongWordSearch(item: LongWord; list: PLongWordVector; Count: Integer): Integer; register;
var i : integer;
begin
  result:=-1;
  for i := 0 to Count-1 do begin
    if list^[i]=item then begin
      result:=i;
      break;
    end;
  end;
end;

//---------------------------------------------------------------------------
function TGSLongWordList.IndexOf(item: Integer): LongWord; register;
begin
  Result := LongWordSearch(item, FList, FCount);
end;

initialization //============================================================

  RegisterClasses([TGSAffineVectorList, TGSVectorList, TGSTexPointList, TGSSingleList,
                   TGSDoubleList, TGS4ByteList, TGSLongWordList]);

end.


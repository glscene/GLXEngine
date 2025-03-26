// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ODE.Import.pas' rev: 36.00 (Windows)

#ifndef ODE_ImportHPP
#define ODE_ImportHPP

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
#include <ModuleLoader.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ode
{
namespace Import
{
//-- forward type declarations -----------------------------------------------
struct TdxJointGroup;
struct TdxJointLimitMotor;
struct TdMass;
struct TdxAutoDisable;
struct TdxDampingParameters;
struct TdxContactParameters;
struct TdxQuickStepParameters;
struct TdObject;
struct TdxJointNode;
struct TJointInfo1;
struct TJointInfo2;
struct TdxJoint;
struct TdxJointBall;
struct TdxJointHinge;
struct TdxJointUniversial;
struct TdxJointPR;
struct TdxJointPiston;
struct TdxJointSlider;
struct TdxJointHinge2;
struct TdxJointAMotor;
struct TdxJointLMotor;
struct TdxJointPlane2D;
struct TdxJointFixed;
struct TdxPosR;
struct TdxBody;
class DELPHICLASS TBodyList;
struct TdxWorld;
struct TdJointFeedback;
struct TdSurfaceParameters;
struct TdContactGeom;
struct TdContact;
struct TdGeomClass;
struct TdxTriMeshData;
struct TdxHeightfieldData;
struct TdGeomSpaceData;
struct TdxGeom;
class DELPHICLASS TGeomList;
struct TdxSpace;
struct TdxHashSpace;
struct TdxQuadTreeSpace;
//-- type declarations -------------------------------------------------------
typedef int TJointFlag;

typedef int TdContactType;

typedef int TBodyFlags;

typedef float TdReal;

typedef float *PdReal;

typedef TdxJointGroup *PdxJointGroup;

typedef PdxJointGroup TdJointGroupID;

struct DECLSPEC_DRECORD TdxJointGroup
{
public:
	int num;
	void *stack;
};


typedef TdxJointLimitMotor *PdxJointLimitMotor;

struct DECLSPEC_DRECORD TdxJointLimitMotor
{
public:
	TdReal vel;
	TdReal fmax;
	TdReal lostop;
	TdReal histop;
	TdReal fudge_factor;
	TdReal normal_cfm;
	TdReal stop_erp;
	TdReal stop_sfm;
	TdReal bounce;
	int limit;
	TdReal limit_err;
};


typedef System::StaticArray<float, 16> TdRealArray;

typedef TdRealArray *PdRealArray;

typedef System::StaticArray<float, 4> TdVector3;

typedef TdVector3 *PdVector3;

typedef System::StaticArray<System::StaticArray<float, 4>, 3> Td3Axis;

typedef Td3Axis *Pd3Axis;

typedef System::StaticArray<int, 3> TdInteger3;

typedef TdInteger3 *PdInteger3;

typedef System::StaticArray<TdxJointLimitMotor, 3> TdxJointLimitMotor3;

typedef TdxJointLimitMotor3 *PdxJointLimitMotor3;

typedef System::StaticArray<float, 4> TdVector4;

typedef TdVector4 *PdVector4;

typedef System::StaticArray<float, 12> TdMatrix3;

typedef TdMatrix3 *PdMatrix3;

typedef System::StaticArray<System::StaticArray<float, 4>, 3> TdMatrix3_As3x4;

typedef TdMatrix3_As3x4 *PdMatrix3_As3x4;

typedef System::StaticArray<float, 16> TdMatrix4;

typedef TdMatrix4 *PdMatrix4;

typedef System::StaticArray<float, 48> TdMatrix6;

typedef TdMatrix6 *PdMatrix6;

typedef TdVector4 TdQuaternion;

typedef TdVector4 *PdQuaternion;

typedef System::StaticArray<float, 6> TdAABB;

struct DECLSPEC_DRECORD TdMass
{
public:
	TdReal mass;
	TdVector4 c;
	TdMatrix3 I;
};


typedef TdMass *PdMass;

struct DECLSPEC_DRECORD TdxAutoDisable
{
public:
	TdReal idle_time;
	int idle_steps;
	TdReal linear_average_threashold;
	TdReal angular_average_threashold;
	System::LongWord average_samples;
};


struct DECLSPEC_DRECORD TdxDampingParameters
{
public:
	TdReal linear_scale;
	TdReal angular_scale;
	TdReal linear_threahold;
	TdReal angular_threashold;
};


struct DECLSPEC_DRECORD TdxContactParameters
{
public:
	TdReal max_vel;
	TdReal min_depth;
};


struct DECLSPEC_DRECORD TdxQuickStepParameters
{
public:
	int num_iterations;
	TdReal w;
};


typedef TdxGeom *PdxGeom;

typedef PdxGeom *PPdxGeom;

typedef void __cdecl (*TdMovedCallback)(PdxGeom o1);

typedef int __fastcall (*TdTriCallback)(PdxGeom TriMesh, PdxGeom RefObject, int TriangleIndex);

typedef void __fastcall (*TdTriArrayCallback)(PdxGeom TriMesh, PdxGeom RefObject, System::PIntegerArray TriIndices, int TriCount);

typedef int __fastcall (*TdTriRayCallback)(PdxGeom TriMesh, PdxGeom Ray, int TriangleIndex, TdReal u, TdReal v);

typedef TdxWorld *PdxWorld;

typedef TdObject *PdObject;

typedef PdObject *PPdObject;

struct DECLSPEC_DRECORD TdObject
{
public:
	PdxWorld World;
	PdObject next;
	PPdObject tome;
	void *userdata;
	int tag;
};


typedef TdxBody *PdxBody;

typedef TdxJoint *PdxJoint;

typedef PdxJoint TdJointID;

typedef TdxJointNode *PdxJointNode;

struct DECLSPEC_DRECORD TdxJointNode
{
public:
	PdxJoint joint;
	PdxBody body;
	PdxJointNode next;
};


struct DECLSPEC_DRECORD TJointInfo1
{
public:
	int m;
	int nub;
};


struct DECLSPEC_DRECORD TJointInfo2
{
public:
	TdReal fps;
	TdReal erp;
	PdReal J1l;
	PdReal J1a;
	PdReal J2l;
	PdReal J2a;
	int rowskip;
	PdReal c;
	PdReal cfm;
	PdReal lo;
	PdReal hi;
	int *findex;
};


struct DECLSPEC_DRECORD TdxJoint
{
public:
	TdObject baseObject;
	TJointInfo1 Info1;
	TJointInfo2 Info2;
};


typedef TdxJoint TdxJointNull;

typedef TdxJointBall *PdxJointBall;

struct DECLSPEC_DRECORD TdxJointBall
{
public:
	TdxJoint BaseJoint;
	TdVector3 anchor1;
	TdVector3 anchor2;
	TdReal erp;
	TdReal cfm;
};


typedef TdxJointHinge *PdxJointHinge;

struct DECLSPEC_DRECORD TdxJointHinge
{
public:
	TdxJoint BaseJoint;
	TdVector3 anchor1;
	TdVector3 anchor2;
	TdVector3 axis1;
	TdVector3 axis2;
	TdQuaternion qrel;
	TdxJointLimitMotor limot;
};


typedef TdxJointUniversial *PdxJointUniversial;

struct DECLSPEC_DRECORD TdxJointUniversial
{
public:
	TdxJoint BaseJoint;
	TdVector3 anchor1;
	TdVector3 anchor2;
	TdVector3 axis1;
	TdVector3 axis2;
	TdQuaternion qrel1;
	TdQuaternion qrel2;
	TdxJointLimitMotor limot1;
	TdxJointLimitMotor limot2;
};


typedef TdxJointPR *PdxJointPR;

struct DECLSPEC_DRECORD TdxJointPR
{
public:
	TdxJoint BaseJoint;
	TdVector3 anchor2;
	TdVector3 axisR1;
	TdVector3 axisR2;
	TdVector3 axisP1;
	TdQuaternion qrel;
	TdVector3 offset;
	TdxJointLimitMotor limotR;
	TdxJointLimitMotor limotP;
};


typedef TdxJointPiston *PdxJointPiston;

struct DECLSPEC_DRECORD TdxJointPiston
{
public:
	TdxJoint BaseJoint;
	TdVector3 axis1;
	TdVector3 axis2;
	TdQuaternion qrel;
	TdVector3 anchor1;
	TdVector3 anchor2;
	TdxJointLimitMotor limotP;
	TdxJointLimitMotor limotR;
};


typedef TdxJointSlider *PdxJointSlider;

struct DECLSPEC_DRECORD TdxJointSlider
{
public:
	TdxJoint BaseJoint;
	TdVector3 axis1;
	TdQuaternion qrel;
	TdVector3 offset;
	TdxJointLimitMotor limot;
};


typedef TdxJointHinge2 *PdxJointHinge2;

struct DECLSPEC_DRECORD TdxJointHinge2
{
public:
	TdxJoint BaseJoint;
	TdVector3 anchor1;
	TdVector3 anchor2;
	TdVector3 axis1;
	TdVector3 axis2;
	TdReal c0;
	TdReal s0;
	TdVector3 v1;
	TdVector3 v2;
	TdxJointLimitMotor limot1;
	TdxJointLimitMotor limot2;
	TdReal susp_erp;
	TdReal susp_cfm;
};


struct DECLSPEC_DRECORD TdxJointAMotor
{
public:
	TdxJoint BaseJoint;
	int num;
	int mode;
	TdInteger3 rel;
	Td3Axis axis;
	TdxJointLimitMotor3 limot;
	TdVector3 angle;
	TdVector3 reference1;
	TdVector3 reference2;
};


struct DECLSPEC_DRECORD TdxJointLMotor
{
public:
	TdxJoint BaseJoint;
	int num;
	TdInteger3 rel;
	Td3Axis axis;
	TdxJointLimitMotor3 limot;
};


struct DECLSPEC_DRECORD TdxJointPlane2D
{
public:
	TdxJoint BaseJoint;
	int row_motor_x;
	int row_motor_y;
	int row_motor_angle;
	TdxJointLimitMotor motor_x;
	TdxJointLimitMotor motor_y;
	TdxJointLimitMotor motor_angle;
};


struct DECLSPEC_DRECORD TdxJointFixed
{
public:
	TdxJoint BaseJoint;
	TdQuaternion qrel;
	TdVector3 offset;
	TdReal erp;
	TdReal cfm;
};


typedef TdxPosR *PdxPosR;

struct DECLSPEC_DRECORD TdxPosR
{
public:
	TdVector3 pos;
	TdMatrix3 R;
};


struct DECLSPEC_DRECORD TdxBody
{
public:
	TdObject baseObject;
	System::Byte Padding;
	TdJointID firstjoint;
	int flags;
	PdxGeom geom;
	TdMass mass;
	TdMatrix3 invI;
	TdReal invMass;
	TdxPosR posr;
	TdQuaternion q;
	TdVector3 lvel;
	TdVector3 avel;
	TdVector3 facc;
	TdVector3 tacc;
	TdVector3 finite_rot_axis;
	TdxAutoDisable adis;
	TdReal adis_timeleft;
	int adis_stepsleft;
	PdVector3 average_lvel_buffer;
	PdVector3 average_avel_buffer;
	System::LongWord average_counter;
	int average_ready;
	TdMovedCallback moved_callback;
	TdxDampingParameters dampingp;
	TdReal max_angular_speed;
};


class PASCALIMPLEMENTATION TBodyList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	PdxBody operator[](int I) { return this->Items[I]; }
	
private:
	PdxBody __fastcall GetItems(int I);
	void __fastcall SetItems(int I, const PdxBody Value);
	
public:
	__property PdxBody Items[int I] = {read=GetItems, write=SetItems/*, default*/};
	void __fastcall DeleteAllBodies();
public:
	/* TList.Destroy */ inline __fastcall virtual ~TBodyList() { }
	
public:
	/* TObject.Create */ inline __fastcall TBodyList() : System::Classes::TList() { }
	
};


struct DECLSPEC_DRECORD TdxWorld
{
public:
	PdxBody firstbody;
	PdxJoint firstjoint;
	int nb;
	int nj;
	TdVector3 gravity;
	TdReal global_erp;
	TdReal global_cfm;
	TdxAutoDisable adis;
	int body_flags;
	TdxQuickStepParameters qs;
	TdxContactParameters contactp;
	TdxDampingParameters dampingp;
	TdReal max_angular_speed;
};


struct DECLSPEC_DRECORD TdJointFeedback
{
public:
	TdVector3 f1;
	TdVector3 t1;
	TdVector3 f2;
	TdVector3 t2;
};


typedef TdJointFeedback *PTdJointFeedback;

enum DECLSPEC_DENUM TdErrorType : unsigned char { d_ERR_UNKNOWN, d_ERR_IASSERT, d_ERR_UASSERT, d_ERR_LCP };

enum DECLSPEC_DENUM TdJointTypeNumbers : unsigned char { dJointTypeNone, dJointTypeBall, dJointTypeHinge, dJointTypeSlider, dJointTypeContact, dJointTypeUniversal, dJointTypeHinge2, dJointTypeFixed, dJointTypeNull, dJointTypeAMotor, dJointTypeLMotor, dJointTypePlane2D, dJointTypePR, dJointTypePU, dJointTypePiston };

enum DECLSPEC_DENUM TdAngularMotorModeNumbers : unsigned char { dAMotorUser, dAMotorEuler };

struct DECLSPEC_DRECORD TdSurfaceParameters
{
public:
	int mode;
	TdReal mu;
	TdReal mu2;
	TdReal bounce;
	TdReal bounce_vel;
	TdReal soft_erp;
	TdReal soft_cfm;
	TdReal motion1;
	TdReal motion2;
	TdReal motionN;
	TdReal slip1;
	TdReal slip2;
};


struct DECLSPEC_DRECORD TdContactGeom
{
public:
	TdVector3 pos;
	TdVector3 normal;
	TdReal depth;
	PdxGeom g1;
	PdxGeom g2;
	int side1;
	int side2;
};


typedef TdContactGeom *PdContactGeom;

struct DECLSPEC_DRECORD TdContact
{
public:
	TdSurfaceParameters surface;
	TdContactGeom geom;
	TdVector3 fdir1;
};


typedef TdContact *PdContact;

typedef void __cdecl (*TdNearCallback)(void * data, PdxGeom o1, PdxGeom o2);

typedef int __cdecl (*TdColliderFn)(PdxGeom o1, PdxGeom o2, int flags, PdContactGeom contact, int skip);

typedef TdColliderFn __cdecl (*TdGetColliderFnFn)(int num);

typedef void __cdecl (*TdGetAABBFn)(PdxGeom g, TdAABB &aabb);

typedef void __cdecl (*TdGeomDtorFn)(PdxGeom o);

typedef int __cdecl (*TdAABBTestFn)(PdxGeom o1, PdxGeom o2, const TdAABB &aabb2);

struct DECLSPEC_DRECORD TdGeomClass
{
public:
	int bytes;
	TdGetColliderFnFn collider;
	TdGetAABBFn aabb;
	TdAABBTestFn aabb_test;
	TdGeomDtorFn dtor;
};


typedef TdGeomClass *PdGeomClass;

typedef TdxSpace *PdxSpace;

typedef System::StaticArray<float, 65536> TdRealHugeArray;

typedef TdRealHugeArray *PdRealHugeArray;

typedef System::StaticArray<int, 65536> TdIntegerArray;

typedef TdIntegerArray *PdIntegerArray;

typedef System::StaticArray<System::StaticArray<float, 4>, 65536> TdVector3Array;

typedef TdVector3Array *PdVector3Array;

struct DECLSPEC_DRECORD TdxTriMeshData
{
public:
	System::Byte unknown;
};


typedef TdxTriMeshData *PdxTriMeshData;

struct DECLSPEC_DRECORD TdxHeightfieldData
{
public:
	TdReal m_fWidth;
	TdReal m_fDepth;
	TdReal m_fSampleWidth;
	TdReal m_fSampleDepth;
	TdReal m_fInvSampleWidth;
	TdReal m_fInvSampleDepth;
	TdReal m_fHalfWidth;
	TdReal m_fHalfDepth;
	TdReal m_fMinHeight;
	TdReal m_fMaxHeight;
	TdReal m_fThickness;
	TdReal m_fScale;
	TdReal m_fOffset;
	int m_nWidthSamples;
	int m_nDepthSamples;
	int m_bCopyHeightData;
	int m_bWrapMode;
	int m_nGetHeightMode;
	void *m_pHeightData;
	void *m_pUserData;
	PdContactGeom m_contacts;
};


typedef TdxHeightfieldData *PdxHeightfieldData;

typedef TdxSpace *PdxSimpleSpace;

typedef TdxHashSpace *PdxHashSpace;

struct DECLSPEC_DRECORD TdGeomSpaceData
{
public:
	PdxGeom next;
};


struct DECLSPEC_DRECORD TdxGeom
{
public:
	int _type;
	System::Byte Padding;
	int gflags;
	void *data;
	PdxBody body;
	PdxGeom body_next;
	PdxPosR final_posr;
	PdxPosR offset_posr;
	PdxGeom next;
	PPdxGeom tome;
	PdxSpace parent_space;
	TdAABB aabb;
	System::LongWord category_bits;
	System::LongWord collide_bits;
};


class PASCALIMPLEMENTATION TGeomList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	PdxGeom operator[](int I) { return this->Items[I]; }
	
private:
	PdxGeom __fastcall GetItems(int I);
	void __fastcall SetItems(int I, const PdxGeom Value);
	
public:
	__property PdxGeom Items[int I] = {read=GetItems, write=SetItems/*, default*/};
	void __fastcall DeleteAllGeoms(bool DeleteDataAsObject = false);
public:
	/* TList.Destroy */ inline __fastcall virtual ~TGeomList() { }
	
public:
	/* TObject.Create */ inline __fastcall TGeomList() : System::Classes::TList() { }
	
};


struct DECLSPEC_DRECORD TdxSpace
{
public:
	TdxGeom baseGeom;
	int count;
	PdxGeom first;
	int cleanup;
	int current_index;
	PdxGeom current_geom;
	int lock_count;
};


typedef TdxSpace TdxSimpleSpace;

struct DECLSPEC_DRECORD TdxHashSpace
{
public:
	TdxSpace BaseSpace;
	int global_minlevel;
	int global_maxlevel;
};


struct DECLSPEC_DRECORD TdxQuadTreeSpace
{
public:
	TdxSpace BaseSpace;
	void *Blocks;
	void *DirtyList;
};


typedef int TJointParams;

//-- var, const, procedure ---------------------------------------------------
#define ODEDLL L"ode64s.dll"
static _DELPHI_CONST System::Int8 TRIMESH_FACE_NORMALS = System::Int8(0x0);
static _DELPHI_CONST System::Int8 TRIMESH_LAST_TRANSFORMATION = System::Int8(0x1);
static _DELPHI_CONST unsigned CONTACTS_UNIMPORTANT = unsigned(0x80000000);
extern DELPHI_PACKAGE TJointFlag dJOINT_INGROUP;
extern DELPHI_PACKAGE TJointFlag dJOINT_REVERSE;
extern DELPHI_PACKAGE TJointFlag dJOINT_TWOBODIES;
extern DELPHI_PACKAGE TdContactType dContactMu2;
extern DELPHI_PACKAGE TdContactType dContactFDir1;
extern DELPHI_PACKAGE TdContactType dContactBounce;
extern DELPHI_PACKAGE TdContactType dContactSoftERP;
extern DELPHI_PACKAGE TdContactType dContactSoftCFM;
extern DELPHI_PACKAGE TdContactType dContactMotion1;
extern DELPHI_PACKAGE TdContactType dContactMotion2;
extern DELPHI_PACKAGE TdContactType dContactMotionN;
extern DELPHI_PACKAGE TdContactType dContactSlip1;
extern DELPHI_PACKAGE TdContactType dContactSlip2;
extern DELPHI_PACKAGE TdContactType dContactApprox0;
extern DELPHI_PACKAGE TdContactType dContactApprox1_1;
extern DELPHI_PACKAGE TdContactType dContactApprox1_2;
extern DELPHI_PACKAGE TdContactType dContactApprox1;
extern DELPHI_PACKAGE TBodyFlags dxBodyFlagFiniteRotation;
extern DELPHI_PACKAGE TBodyFlags dxBodyFlagFiniteRotationAxis;
extern DELPHI_PACKAGE TBodyFlags dxBodyDisabled;
extern DELPHI_PACKAGE TBodyFlags dxBodyNoGravity;
static _DELPHI_CONST System::Int8 _priv_dParamLoStop = System::Int8(0x0);
static _DELPHI_CONST System::Word _priv_dParamLoStop2 = System::Word(0x100);
static _DELPHI_CONST System::Word _priv_dParamLoStop3 = System::Word(0x200);
extern DELPHI_PACKAGE TJointParams dParamLoStop;
extern DELPHI_PACKAGE TJointParams dParamHiStop;
extern DELPHI_PACKAGE TJointParams dParamVel;
extern DELPHI_PACKAGE TJointParams dParamFMax;
extern DELPHI_PACKAGE TJointParams dParamFudgeFactor;
extern DELPHI_PACKAGE TJointParams dParamBounce;
extern DELPHI_PACKAGE TJointParams dParamCFM;
extern DELPHI_PACKAGE TJointParams dParamStopERP;
extern DELPHI_PACKAGE TJointParams dParamStopCFM;
extern DELPHI_PACKAGE TJointParams dParamSuspensionERP;
extern DELPHI_PACKAGE TJointParams dParamSuspensionCFM;
extern DELPHI_PACKAGE TJointParams dParamERP;
extern DELPHI_PACKAGE TJointParams dParamGroup1;
extern DELPHI_PACKAGE TJointParams dParamLoStop1;
extern DELPHI_PACKAGE TJointParams dParamHiStop1;
extern DELPHI_PACKAGE TJointParams dParamVel1;
extern DELPHI_PACKAGE TJointParams dParamFMax1;
extern DELPHI_PACKAGE TJointParams dParamFudgeFactor1;
extern DELPHI_PACKAGE TJointParams dParamBounce1;
extern DELPHI_PACKAGE TJointParams dParamCFM1;
extern DELPHI_PACKAGE TJointParams dParamStopERP1;
extern DELPHI_PACKAGE TJointParams dParamStopCFM1;
extern DELPHI_PACKAGE TJointParams dParamSuspensionERP1;
extern DELPHI_PACKAGE TJointParams dParamSuspensionCFM1;
extern DELPHI_PACKAGE TJointParams dParamERP1;
extern DELPHI_PACKAGE TJointParams dParamGroup2;
extern DELPHI_PACKAGE TJointParams dParamLoStop2;
extern DELPHI_PACKAGE TJointParams dParamHiStop2;
extern DELPHI_PACKAGE TJointParams dParamVel2;
extern DELPHI_PACKAGE TJointParams dParamFMax2;
extern DELPHI_PACKAGE TJointParams dParamFudgeFactor2;
extern DELPHI_PACKAGE TJointParams dParamBounce2;
extern DELPHI_PACKAGE TJointParams dParamCFM2;
extern DELPHI_PACKAGE TJointParams dParamStopERP2;
extern DELPHI_PACKAGE TJointParams dParamStopCFM2;
extern DELPHI_PACKAGE TJointParams dParamSuspensionERP2;
extern DELPHI_PACKAGE TJointParams dParamSuspensionCFM2;
extern DELPHI_PACKAGE TJointParams dParamERP2;
extern DELPHI_PACKAGE TJointParams dParamGroup3;
extern DELPHI_PACKAGE TJointParams dParamLoStop3;
extern DELPHI_PACKAGE TJointParams dParamHiStop3;
extern DELPHI_PACKAGE TJointParams dParamVel3;
extern DELPHI_PACKAGE TJointParams dParamFMax3;
extern DELPHI_PACKAGE TJointParams dParamFudgeFactor3;
extern DELPHI_PACKAGE TJointParams dParamBounce3;
extern DELPHI_PACKAGE TJointParams dParamCFM3;
extern DELPHI_PACKAGE TJointParams dParamStopERP3;
extern DELPHI_PACKAGE TJointParams dParamStopCFM3;
extern DELPHI_PACKAGE TJointParams dParamSuspensionERP3;
extern DELPHI_PACKAGE TJointParams dParamSuspensionCFM3;
extern DELPHI_PACKAGE TJointParams dParamERP3;
extern DELPHI_PACKAGE TJointParams dParamGroup;
extern "C" void __cdecl dInitODE(void);
extern "C" int __cdecl dInitODE2(System::LongWord uiInitFlags);
extern "C" void __cdecl dCloseODE(void);
extern "C" PdxWorld __cdecl dWorldCreate(void);
extern "C" void __cdecl dWorldDestroy(const PdxWorld World);
extern "C" TdReal __cdecl dWorldGetCFM(const PdxWorld World);
extern "C" TdReal __cdecl dWorldGetERP(const PdxWorld World);
extern "C" void __cdecl dWorldGetGravity(const PdxWorld World, TdVector3 &gravity);
extern "C" void __cdecl dWorldImpulseToForce(const PdxWorld World, const TdReal stepsize, const TdReal ix, const TdReal iy, const TdReal iz, TdVector3 &force);
extern "C" void __cdecl dWorldSetCFM(const PdxWorld World, TdReal cfm);
extern "C" void __cdecl dWorldSetERP(const PdxWorld World, TdReal erp);
extern "C" void __cdecl dWorldSetGravity(const PdxWorld World, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dWorldSetContactMaxCorrectingVel(const PdxWorld World, const TdReal vel);
extern "C" TdReal __cdecl dWorldGetContactMaxCorrectingVel(const PdxWorld World);
extern "C" void __cdecl dWorldSetContactSurfaceLayer(const PdxWorld World, const TdReal depth);
extern "C" TdReal __cdecl dWorldGetContactSurfaceLayer(const PdxWorld World);
extern "C" void __cdecl dWorldExportDIF(const PdxWorld World, unsigned fileHandle, const char * world_name);
extern "C" TdReal __cdecl dWorldGetLinearDampingThreshold(const PdxWorld World);
extern "C" void __cdecl dWorldSetLinearDampingThreshold(const PdxWorld World, const TdReal threshold);
extern "C" TdReal __cdecl dWorldGetAngularDampingThreshold(const PdxWorld World);
extern "C" void __cdecl dWorldSetAngularDampingThreshold(const PdxWorld World, const TdReal threshold);
extern "C" TdReal __cdecl dWorldGetLinearDamping(const PdxWorld World);
extern "C" void __cdecl dWorldSetLinearDamping(const PdxWorld World, const TdReal scale);
extern "C" TdReal __cdecl dWorldGetAngularDamping(const PdxWorld World);
extern "C" void __cdecl dWorldSetAngularDamping(const PdxWorld World, const TdReal scale);
extern "C" void __cdecl dWorldSetDamping(const PdxWorld World, const TdReal linear_scale, const TdReal angular_scale);
extern "C" TdReal __cdecl dWorldGetMaxAngularSpeed(const PdxWorld World);
extern "C" void __cdecl dWorldSetMaxAngularSpeed(const PdxWorld World, const TdReal max_speed);
extern "C" void __cdecl dWorldStep(const PdxWorld World, const TdReal stepsize);
extern "C" void __cdecl dWorldQuickStep(const PdxWorld World, const TdReal stepsize);
extern "C" void __cdecl dWorldSetQuickStepNumIterations(const PdxWorld World, const int num);
extern "C" int __cdecl dWorldGetQuickStepNumIterations(const PdxWorld World);
extern "C" void __cdecl dWorldSetQuickStepW(const PdxWorld World, const TdReal param);
extern "C" TdReal __cdecl dWorldGetQuickStepW(const PdxWorld World);
extern "C" TdReal __cdecl dWorldGetAutoDisableLinearAverageThreshold(const PdxWorld World);
extern "C" void __cdecl dWorldSetAutoDisableLinearAverageThreshold(const PdxWorld World, TdReal linear_average_threshold);
extern "C" TdReal __cdecl dWorldGetAutoDisableAngularAverageThreshold(const PdxWorld World);
extern "C" void __cdecl dWorldSetAutoDisableAngularAverageThreshold(const PdxWorld World, TdReal linear_average_threshold);
extern "C" TdReal __cdecl dWorldGetAutoDisableAverageSamplesCount(const PdxWorld World);
extern "C" void __cdecl dWorldSetAutoDisableAverageSamplesCount(const PdxWorld World, TdReal linear_average_threshold);
extern "C" TdReal __cdecl dWorldGetAutoDisableLinearThreshold(const PdxWorld World);
extern "C" void __cdecl dWorldSetAutoDisableLinearThreshold(const PdxWorld World, TdReal linThreshold);
extern "C" TdReal __cdecl dWorldGetAutoDisableAngularThreshold(const PdxWorld World);
extern "C" void __cdecl dWorldSetAutoDisableAngularThreshold(const PdxWorld World, TdReal angThreshold);
extern "C" int __cdecl dWorldGetAutoDisableSteps(const PdxWorld World);
extern "C" void __cdecl dWorldSetAutoDisableSteps(const PdxWorld World, int steps);
extern "C" TdReal __cdecl dWorldGetAutoDisableTime(const PdxWorld World);
extern "C" void __cdecl dWorldSetAutoDisableTime(const PdxWorld World, TdReal time);
extern "C" int __cdecl dWorldGetAutoDisableFlag(const PdxWorld World);
extern "C" void __cdecl dWorldSetAutoDisableFlag(const PdxWorld World, int do_auto_disable);
extern "C" void __cdecl dBodyAddForce(const PdxBody body, const TdReal fx, const TdReal fy, const TdReal fz);
extern "C" void __cdecl dBodyAddForceAtPos(const PdxBody body, const TdReal fx, const TdReal fy, const TdReal fz, const TdReal px, const TdReal py, const TdReal pz);
extern "C" void __cdecl dBodyAddForceAtRelPos(const PdxBody body, const TdReal fx, const TdReal fy, const TdReal fz, const TdReal px, const TdReal py, const TdReal pz);
extern "C" void __cdecl dBodyAddRelForce(const PdxBody body, const TdReal fx, const TdReal fy, const TdReal fz);
extern "C" void __cdecl dBodyAddRelForceAtPos(const PdxBody body, const TdReal fx, const TdReal fy, const TdReal fz, const TdReal px, const TdReal py, const TdReal pz);
extern "C" void __cdecl dBodyAddRelForceAtRelPos(const PdxBody body, const TdReal fx, const TdReal fy, const TdReal fz, const TdReal px, const TdReal py, const TdReal pz);
extern "C" void __cdecl dBodyAddRelTorque(const PdxBody body, const TdReal fx, const TdReal fy, const TdReal fz);
extern "C" void __cdecl dBodyAddTorque(const PdxBody body, const TdReal fx, const TdReal fy, const TdReal fz);
extern "C" PdxBody __cdecl dBodyCreate(const PdxWorld World);
extern "C" void __cdecl dBodyDestroy(const PdxBody body);
extern "C" void __cdecl dBodyDisable(const PdxBody body);
extern "C" void __cdecl dBodyEnable(const PdxBody body);
extern "C" PdVector3 __cdecl dBodyGetAngularVel(const PdxBody body);
extern "C" void __cdecl dBodyGetFiniteRotationAxis(const PdxBody body, TdVector3 &result);
extern "C" int __cdecl dBodyGetFiniteRotationMode(const PdxBody body);
extern "C" PdVector3 __cdecl dBodyGetForce(const PdxBody body);
extern "C" int __cdecl dBodyGetGravityMode(const PdxBody body);
extern "C" TdJointID __cdecl dBodyGetJoint(const PdxBody body, const int index);
extern "C" PdVector3 __cdecl dBodyGetLinearVel(const PdxBody body);
extern "C" void __cdecl dBodyGetMass(const PdxBody body, TdMass &mass);
extern "C" int __cdecl dBodyGetNumJoints(const PdxBody body);
extern "C" void __cdecl dBodyGetPointVel(const PdxBody body, const TdReal px, const TdReal py, const TdReal pz, TdVector3 &result);
extern "C" void __cdecl dBodyGetPosRelPoint(const PdxBody body, const TdReal px, const TdReal py, const TdReal pz, TdVector3 &result);
extern "C" PdVector3 __cdecl dBodyGetPosition(const PdxBody body);
extern "C" PdQuaternion __cdecl dBodyGetQuaternion(const PdxBody body);
extern "C" void __cdecl dBodyGetRelPointPos(const PdxBody body, const TdReal px, const TdReal py, const TdReal pz, TdVector3 &result);
extern "C" void __cdecl dBodyGetRelPointVel(const PdxBody body, const TdReal px, const TdReal py, const TdReal pz, TdVector3 &result);
extern "C" PdMatrix3 __cdecl dBodyGetRotation(const PdxBody body);
extern "C" PdVector3 __cdecl dBodyGetTorque(const PdxBody body);
extern "C" int __cdecl dBodyIsEnabled(const PdxBody body);
extern "C" void __cdecl dBodySetAngularVel(const PdxBody body, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dBodySetFiniteRotationAxis(const PdxBody body, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dBodySetFiniteRotationMode(const PdxBody body, const int mode);
extern "C" void __cdecl dBodySetForce(const PdxBody body, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dBodySetGravityMode(const PdxBody body, const int mode);
extern "C" void __cdecl dBodySetLinearVel(const PdxBody body, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dBodySetMass(const PdxBody body, const PdMass mass);
extern "C" void __cdecl dBodySetPosition(const PdxBody body, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dBodySetQuaternion(const PdxBody body, const TdQuaternion &q);
extern "C" void __cdecl dBodySetRotation(const PdxBody body, const TdMatrix3 &R);
extern "C" void __cdecl dBodySetTorque(const PdxBody body, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dBodyVectorFromWorld(const PdxBody body, const TdReal px, const TdReal py, const TdReal pz, TdVector3 &result);
extern "C" void __cdecl dBodyVectorToWorld(const PdxBody body, const TdReal px, const TdReal py, const TdReal pz, TdVector3 &result);
extern "C" void __cdecl dBodySetData(const PdxBody body, void * data);
extern "C" void * __cdecl dBodyGetData(const PdxBody body);
extern "C" void __cdecl dBodySetMovedCallback(const PdxBody body, TdMovedCallback callback);
extern "C" void __cdecl dBodyCopyPosition(const PdxBody body, const TdVector3 &pos);
extern "C" void __cdecl dBodyCopyRotation(const PdxBody body, const TdMatrix3 &R);
extern "C" void __cdecl dBodyCopyQuaternion(const PdxBody body, const TdQuaternion &quat);
extern "C" void __cdecl dBodySetLinearDamping(const PdxBody body, TdReal scale);
extern "C" TdReal __cdecl dBodyGetLinearDamping(const PdxBody body);
extern "C" void __cdecl dBodySetAngularDamping(const PdxBody body, TdReal scale);
extern "C" TdReal __cdecl dBodyGetAngularDamping(const PdxBody body);
extern "C" void __cdecl dBodySetDamping(const PdxBody body, TdReal linear_scale, TdReal angular_scale);
extern "C" TdReal __cdecl dBodyGetLinearDampingThreshold(const PdxBody body);
extern "C" void __cdecl dBodySetLinearDampingThreshold(const PdxBody body, TdReal threshold);
extern "C" TdReal __cdecl dBodyGetAngularDampingThreshold(const PdxBody body);
extern "C" void __cdecl dBodySetAngularDampingThreshold(const PdxBody body, TdReal threshold);
extern "C" void __cdecl dBodySetDampingDefaults(const PdxBody body, TdReal threshold);
extern "C" void __cdecl dBodySetMaxAngularSpeed(const PdxBody body, TdReal max_speed);
extern "C" TdReal __cdecl dBodyGetMaxAngularSpeed(const PdxBody body);
extern "C" TdReal __cdecl dBodyGetAutoDisableLinearThreshold(const PdxBody body);
extern "C" void __cdecl dBodySetAutoDisableLinearThreshold(const PdxBody body, TdReal linThreshold);
extern "C" TdReal __cdecl dBodyGetAutoDisableAngularThreshold(const PdxBody body);
extern "C" void __cdecl dBodySetAutoDisableAngularThreshold(const PdxBody body, TdReal angThreshold);
extern "C" int __cdecl dBodyGetAutoDisableSteps(const PdxBody body);
extern "C" void __cdecl dBodySetAutoDisableSteps(const PdxBody body, int steps);
extern "C" TdReal __cdecl dBodyGetAutoDisableTime(const PdxBody body);
extern "C" void __cdecl dBodySetAutoDisableTime(const PdxBody body, TdReal time);
extern "C" int __cdecl dBodyGetAutoDisableFlag(const PdxBody body);
extern "C" void __cdecl dBodySetAutoDisableFlag(const PdxBody body, int do_auto_disable);
extern "C" void __cdecl dBodySetAutoDisableDefaults(const PdxBody body);
extern "C" void __cdecl dBodySetAutoDisableAverageSamplesCount(const PdxBody body, System::LongWord average_samples_count);
extern "C" void __cdecl dJointGroupDestroy(const TdJointGroupID dJointGroupID);
extern "C" TdJointGroupID __cdecl dJointGroupCreate(const int max_size);
extern "C" void __cdecl dJointGroupEmpty(const TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointAttach(const TdJointID dJointID, const PdxBody body1, const PdxBody body2);
extern "C" void __cdecl dJointDestroy(const TdJointID dJointID);
extern "C" void * __cdecl dJointGetData(const TdJointID dJointID);
extern "C" void __cdecl dJointSetData(const TdJointID dJointID, void * data);
extern "C" void __cdecl dJointSetFeedback(const TdJointID dJointID, PTdJointFeedback Feedback);
extern "C" PTdJointFeedback __cdecl dJointGetFeedback(const TdJointID dJointID);
extern "C" int __cdecl dJointGetType(const TdJointID dJointID);
extern "C" PdxBody __cdecl dJointGetBody(const TdJointID dJointID, const int index);
extern "C" TdJointID __cdecl dJointCreateContact(const PdxWorld World, TdJointGroupID dJointGroupID, const PdContact dContact);
extern "C" TdJointID __cdecl dJointCreateAMotor(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointSetAMotorAngle(const TdJointID dJointID, const int anum, const TdReal angle);
extern "C" TdReal __cdecl dJointGetAMotorAngle(const TdJointID dJointID, const int anum);
extern "C" void __cdecl dJointSetAMotorAxis(const TdJointID dJointID, const int anum, const int rel, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetAMotorAxis(const TdJointID dJointID, const int anum, TdVector3 &result);
extern "C" void __cdecl dJointSetAMotorNumAxes(const TdJointID dJointID, const int num);
extern "C" int __cdecl dJointGetAMotorNumAxes(const TdJointID dJointID);
extern "C" void __cdecl dJointSetAMotorParam(const TdJointID dJointID, const TJointParams parameter, const TdReal Value);
extern "C" TdReal __cdecl dJointGetAMotorParam(const TdJointID dJointID, const TJointParams parameter);
extern "C" void __cdecl dJointSetAMotorMode(const TdJointID dJointID, const TdAngularMotorModeNumbers mode);
extern "C" int __cdecl dJointGetAMotorMode(const TdJointID dJointID);
extern "C" void __cdecl dJointAddAMotorTorques(const TdJointID dJointID, TdReal torque1, TdReal torque2, TdReal torque3);
extern "C" TdReal __cdecl dJointGetAMotorAngleRate(const TdJointID dJointID, const int anum);
extern "C" int __cdecl dJointGetAMotorAxisRel(const TdJointID dJointID, const int anum);
extern "C" TdJointID __cdecl dJointCreateLMotor(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointSetLMotorAxis(const TdJointID dJointID, const int anum, const int rel, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetLMotorAxis(const TdJointID dJointID, const int anum, TdVector3 &result);
extern "C" void __cdecl dJointSetLMotorNumAxes(const TdJointID dJointID, const int num);
extern "C" int __cdecl dJointGetLMotorNumAxes(const TdJointID dJointID);
extern "C" void __cdecl dJointSetLMotorParam(const TdJointID dJointID, const TJointParams parameter, const TdReal Value);
extern "C" TdReal __cdecl dJointGetLMotorParam(const TdJointID dJointID, const TJointParams parameter);
extern "C" TdJointID __cdecl dJointCreateBall(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointSetBallAnchor(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetBallAnchor(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointGetBallAnchor2(const TdJointID dJointID, TdVector3 &result);
extern "C" TdJointID __cdecl dJointCreateHinge(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointSetHingeAnchor(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetHingeAnchor(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointGetHingeAnchor2(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetHingeAxis(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetHingeAxis(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetHingeParam(const TdJointID dJointID, const TJointParams parameter, const TdReal Value);
extern "C" TdReal __cdecl dJointGetHingeParam(const TdJointID dJointID, const TJointParams parameter);
extern "C" TdReal __cdecl dJointGetHingeAngle(const TdJointID dJointID);
extern "C" TdReal __cdecl dJointGetHingeAngleRate(const TdJointID dJointID);
extern "C" void __cdecl dJointAddHingeTorque(const TdJointID dJointID, TdReal torque);
extern "C" TdJointID __cdecl dJointCreateHinge2(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointSetHinge2Anchor(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetHinge2Anchor(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointGetHinge2Anchor2(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetHinge2Axis1(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetHinge2Axis1(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetHinge2Axis2(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetHinge2Axis2(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetHinge2Param(const TdJointID dJointID, const TJointParams parameter, const TdReal Value);
extern "C" TdReal __cdecl dJointGetHinge2Param(const TdJointID dJointID, const TJointParams parameter);
extern "C" TdReal __cdecl dJointGetHinge2Angle1(const TdJointID dJointID);
extern "C" TdReal __cdecl dJointGetHinge2Angle1Rate(const TdJointID dJointID);
extern "C" TdReal __cdecl dJointGetHinge2Angle2Rate(const TdJointID dJointID);
extern "C" void __cdecl dJointAddHinge2Torques(const TdJointID dJointID, TdReal torque1, TdReal torque2);
extern "C" void __cdecl dJointCorrectHinge2(const TdJointID dJointID);
extern "C" TdJointID __cdecl dJointCreateSlider(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointSetSliderAxis(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetSliderAxis(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetSliderParam(const TdJointID dJointID, const TJointParams parameter, const TdReal Value);
extern "C" TdReal __cdecl dJointGetSliderParam(const TdJointID dJointID, const TJointParams parameter);
extern "C" TdReal __cdecl dJointGetSliderPosition(const TdJointID dJointID);
extern "C" TdReal __cdecl dJointGetSliderPositionRate(const TdJointID dJointID);
extern "C" void __cdecl dJointAddSliderForce(const TdJointID dJointID, TdReal force);
extern "C" TdJointID __cdecl dJointCreateUniversal(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointGetUniversalAnchor(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointGetUniversalAnchor2(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetUniversalAxis1(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetUniversalAxis1(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetUniversalAxis2(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetUniversalAxis2(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetUniversalParam(const TdJointID dJointID, const TJointParams parameter, const TdReal Value);
extern "C" TdReal __cdecl dJointGetUniversalParam(const TdJointID dJointID, const TJointParams parameter);
extern "C" TdReal __cdecl dJointGetUniversalAngle1(const TdJointID dJointID);
extern "C" TdReal __cdecl dJointGetUniversalAngle2(const TdJointID dJointID);
extern "C" TdReal __cdecl dJointGetUniversalAngle1Rate(const TdJointID dJointID);
extern "C" TdReal __cdecl dJointGetUniversalAngle2Rate(const TdJointID dJointID);
extern "C" void __cdecl dJointSetUniversalAnchor(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointAddUniversalTorques(const TdJointID dJointID, TdReal torque1, TdReal torque2);
extern "C" TdJointID __cdecl dJointCreateFixed(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointSetFixed(const TdJointID dJointID);
extern "C" TdJointID __cdecl dJointCreatePlane2D(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointSetPlane2DXParam(const TdJointID dJointID, const int parameter, const TdReal Value);
extern "C" void __cdecl dJointSetPlane2DYParam(const TdJointID dJointID, const int parameter, const TdReal Value);
extern "C" void __cdecl dJointSetPlane2DAngleParam(const TdJointID dJointID, const int parameter, const TdReal Value);
extern "C" TdJointID __cdecl dJointCreatePR(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointSetPRAnchor(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointSetPRAxis1(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetPRAxis1(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetPRAxis2(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetPRAxis2(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetPRParam(const TdJointID dJointID, const TJointParams parameter, const TdReal Value);
extern "C" TdReal __cdecl dJointGetPRParam(const TdJointID dJointID, int parameter);
extern "C" void __cdecl dJointAddPRTorque(const TdJointID dJointID, TdReal torque);
extern "C" TdJointID __cdecl dJointCreatePiston(const PdxWorld World, TdJointGroupID dJointGroupID);
extern "C" void __cdecl dJointSetPistonAnchor(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetPistonAnchor(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointGetPistonAnchor2(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetPistonAxis(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z);
extern "C" void __cdecl dJointGetPistonAxis(const TdJointID dJointID, TdVector3 &result);
extern "C" void __cdecl dJointSetPistonParam(const TdJointID dJointID, const TJointParams parameter, const TdReal Value);
extern "C" TdReal __cdecl dJointGetPistonParam(const TdJointID dJointID, int parameter);
extern "C" void __cdecl dJointSetPistonAxisDelta(const TdJointID dJointID, const TdReal x, const TdReal y, const TdReal z, const TdReal ax, const TdReal ay, const TdReal az);
extern "C" void __cdecl dJointAddPistonForce(const TdJointID dJointID, TdReal force);
extern "C" TdReal __cdecl dJointGetPistonPosition(const TdJointID dJointID);
extern "C" TdReal __cdecl dJointGetPistonAngle(const TdJointID dJointID);
extern "C" TdReal __cdecl dJointGetPistonAngleRate(const TdJointID dJointID);
extern "C" TdReal __cdecl dJointGetPistonRate(const TdJointID dJointID);
extern "C" PdxGeom __cdecl dCreateGeom(int classnum);
extern "C" void __cdecl dGeomDestroy(const PdxGeom geom);
extern "C" int __cdecl dCreateGeomClass(const TdGeomClass &classptr);
extern "C" int __cdecl dGeomGetClass(const PdxGeom geom);
extern "C" void * __cdecl dGeomGetClassData(PdxGeom o);
extern "C" PdxSpace __cdecl dGeomGetSpace(const PdxGeom geom);
extern "C" int __cdecl dGeomIsSpace(const PdxGeom geom);
extern "C" void __cdecl dGeomSetBody(const PdxGeom geom, PdxBody body);
extern "C" PdxBody __cdecl dGeomGetBody(const PdxGeom geom);
extern "C" void __cdecl dGeomSetPosition(const PdxGeom geom, const TdReal x, const TdReal y, const TdReal z);
extern "C" PdVector3 __cdecl dGeomGetPosition(const PdxGeom geom);
extern "C" void __cdecl dGeomSetRotation(const PdxGeom geom, const TdMatrix3 &R);
extern "C" PdMatrix3 __cdecl dGeomGetRotation(const PdxGeom geom);
extern "C" void __cdecl dGeomSetQuaternion(const PdxGeom geom, const void *TdQuaternion);
extern "C" void __cdecl dGeomGetQuaternion(const PdxGeom geom, TdQuaternion &result);
extern "C" void __cdecl dGeomCopyPosition(const PdxGeom geom, const TdVector3 &pos);
extern "C" void __cdecl dGeomCopyRotation(const PdxGeom geom, const TdMatrix3 &R);
extern "C" void __cdecl dGeomCopyQuaternion(const PdxGeom geom, const TdQuaternion &quat);
extern "C" void __cdecl dGeomSetData(const PdxGeom geom, void * data);
extern "C" void * __cdecl dGeomGetData(const PdxGeom geom);
extern "C" void __cdecl dGeomEnable(const PdxGeom geom);
extern "C" void __cdecl dGeomDisable(const PdxGeom geom);
extern "C" int __cdecl dGeomIsEnabled(const PdxGeom geom);
extern "C" void __cdecl dGeomGetAABB(const PdxGeom geom, TdAABB &aabb);
extern "C" void __cdecl dGeomSetCategoryBits(const PdxGeom geom, unsigned bits);
extern "C" unsigned __cdecl dGeomGetCategoryBits(const PdxGeom geom);
extern "C" void __cdecl dGeomSetCollideBits(const PdxGeom geom, unsigned bits);
extern "C" unsigned __cdecl dGeomGetCollideBits(const PdxGeom geom);
extern "C" void __cdecl dGeomSetOffsetPosition(const PdxGeom geom, TdReal x, TdReal y, TdReal z);
extern "C" PdVector3 __cdecl dGeomGetOffsetPosition(const PdxGeom geom);
extern "C" void __cdecl dGeomSetOffsetRotation(const PdxGeom geom, const TdMatrix3 &R);
extern "C" PdVector3 __cdecl dGeomGetOffsetRotation(const PdxGeom geom);
extern "C" void __cdecl dGeomSetOffsetQuaternion(const PdxGeom geom, const TdQuaternion &q);
extern "C" void __cdecl dGeomGetOffsetQuaternion(const PdxGeom geom, TdQuaternion &q);
extern "C" void __cdecl dGeomClearOffset(const PdxGeom geom);
extern "C" void __cdecl dGeomSetOffsetWorldPosition(const PdxGeom geom, TdReal x, TdReal y, TdReal z);
extern "C" void __cdecl dGeomSetOffsetWorldRotation(const PdxGeom geom, const TdMatrix3 &R);
extern "C" void __cdecl dGeomSetOffsetWorldQuaternion(const PdxGeom geom, const TdQuaternion &q);
extern "C" void __cdecl dGeomCopyOffsetPosition(const PdxGeom geom, TdVector3 &pos);
extern "C" void __cdecl dGeomCopyOffsetRotation(const PdxGeom geom, TdMatrix3 &R);
extern "C" void __cdecl dGeomIsOffset(const PdxGeom geom);
extern "C" PdxGeom __cdecl dCreateGeomTransform(const PdxSpace Space);
extern "C" void __cdecl dGeomTransformSetGeom(const PdxGeom geom, const PdxGeom obj);
extern "C" PdxGeom __cdecl dGeomTransformGetGeom(const PdxGeom geom);
extern "C" void __cdecl dGeomTransformSetInfo(const PdxGeom geom, int mode);
extern "C" int __cdecl dGeomTransformGetInfo(const PdxGeom geom);
extern "C" void __cdecl dGeomTransformSetCleanup(const PdxGeom geom, const int mode);
extern "C" int __cdecl dGeomTransformGetCleanup(const PdxGeom geom);
extern "C" PdxGeom __cdecl dCreateBox(const PdxSpace Space, const TdReal lx, const TdReal ly, const TdReal lz);
extern "C" void __cdecl dGeomBoxGetLengths(const PdxGeom geom, TdVector3 &result);
extern "C" void __cdecl dGeomBoxSetLengths(const PdxGeom geom, const TdReal lx, const TdReal ly, const TdReal lz);
extern "C" TdReal __cdecl dGeomBoxPointDepth(const PdxGeom geom, const TdReal x, const TdReal y, const TdReal z);
extern "C" PdxGeom __cdecl dCreateCylinder(const PdxSpace Space, TdReal R, TdReal lz);
extern "C" void __cdecl dGeomCylinderSetParams(const PdxGeom geom, TdReal radius, TdReal length);
extern "C" void __cdecl dGeomCylinderGetParams(const PdxGeom geom, TdReal &radius, TdReal &length);
extern "C" PdxGeom __cdecl dCreateCapsule(const PdxSpace Space, const TdReal radius, const TdReal length);
extern "C" void __cdecl dGeomCapsuleSetParams(const PdxGeom geom, const TdReal radius, const TdReal length);
extern "C" void __cdecl dGeomCapsuleGetParams(const PdxGeom geom, TdReal &radius, TdReal &length);
extern "C" TdReal __cdecl dGeomCapsulePointDepth(const PdxGeom geom, const TdReal x, const TdReal y, const TdReal z);
extern "C" PdxGeom __cdecl dCreatePlane(const PdxSpace Space, const TdReal a, const TdReal b, const TdReal c, const TdReal d);
extern "C" void __cdecl dGeomPlaneSetParams(const PdxGeom geom, const TdReal a, const TdReal b, const TdReal c, const TdReal d);
extern "C" void __cdecl dGeomPlaneGetParams(const PdxGeom geom, TdVector4 &result);
extern "C" TdReal __cdecl dGeomPlanePointDepth(const PdxGeom geom, const TdReal x, const TdReal y, const TdReal z);
extern "C" PdxGeom __cdecl dCreateSphere(const PdxSpace Space, const TdReal radius);
extern "C" void __cdecl dGeomSphereSetRadius(const PdxGeom geom, const TdReal radius);
extern "C" TdReal __cdecl dGeomSphereGetRadius(const PdxGeom geom);
extern "C" TdReal __cdecl dGeomSpherePointDepth(const PdxGeom geom, const TdReal x, const TdReal y, const TdReal z);
extern "C" PdxGeom __cdecl dCreateConvex(const PdxSpace Space, PdReal _planes, System::LongWord _planecount, PdReal _points, System::LongWord _pointcount, const System::LongWord _polygons);
extern "C" void __cdecl dGeomSetConvex(const PdxGeom geom, PdReal _planes, System::LongWord _planecount, PdReal _points, System::LongWord _pointcount, const System::LongWord _polygons);
extern "C" PdxGeom __cdecl dCreateHeightfield(const PdxSpace Space, PdxHeightfieldData data, int bPlaceable);
extern "C" PdxHeightfieldData __cdecl dGeomHeightfieldDataCreate(void);
extern "C" void __cdecl dGeomHeightfieldDataDestroy(PdxHeightfieldData data);
extern "C" void __cdecl dGeomHeightfieldSetHeightfieldData(const PdxGeom geom, PdxHeightfieldData data);
extern "C" PdxHeightfieldData __cdecl dGeomHeightfieldGetHeightfieldData(const PdxGeom geom);
extern "C" TdReal __cdecl dGeomHeightfieldDataSetBounds(PdxHeightfieldData data, TdReal minHeight, TdReal MaxHeight);
extern "C" PdxGeom __cdecl dCreateRay(const PdxSpace Space, TdReal length);
extern "C" void __cdecl dGeomRaySet(const PdxGeom geom, TdReal px, TdReal py, TdReal pz, TdReal dx, TdReal dy, TdReal dz);
extern "C" void __cdecl dGeomRayGet(const PdxGeom geom, TdVector3 &start, TdVector3 &dir);
extern "C" void __cdecl dGeomRaySetLength(const PdxGeom geom, TdReal length);
extern "C" TdReal __cdecl dGeomRayGetLength(const PdxGeom geom);
extern "C" void __cdecl dGeomRaySetParams(const PdxGeom geom, int FirstContact, int BackfacCull);
extern "C" void __cdecl dGeomRayGetParams(const PdxGeom geom, int &FirstContact, int &BackfacCull);
extern "C" void __cdecl dGeomRaySetClosestHit(const PdxGeom geom, int closestHit);
extern "C" int __cdecl dGeomRayGetClosestHit(const PdxGeom geom);
extern "C" PdxGeom __cdecl dCreateTriMesh(const PdxSpace Space, PdxTriMeshData data, TdTriCallback callback, TdTriArrayCallback ArrayCallback, TdTriRayCallback RayCallback);
extern "C" void __cdecl dGeomTriMeshSetData(PdxGeom g, PdxTriMeshData data);
extern "C" PdxTriMeshData __cdecl dGeomTriMeshGetData(PdxGeom g);
extern "C" PdxTriMeshData __cdecl dGeomTriMeshGetTriMeshDataID(PdxGeom g);
extern "C" void __cdecl dGeomTriMeshDataUpdate(PdxTriMeshData g);
extern "C" int __cdecl dGeomTriMeshIsTCEnabled(PdxGeom g, int geomClass);
extern "C" void __cdecl dGeomTriMeshEnableTC(PdxGeom g, int geomClass, int enable);
extern "C" void __cdecl dGeomTriMeshClearTCCache(PdxGeom g);
extern "C" int __cdecl dGeomTriMeshGetTriangleCount(PdxGeom g);
extern "C" void __cdecl dGeomTriMeshGetTriangle(PdxGeom g, int index, PdVector3 v0, PdVector3 v1, PdVector3 v2);
extern "C" void __cdecl dGeomTriMeshGetPoint(PdxGeom g, int index, TdReal u, TdReal v, const TdVector3 &result);
extern "C" void * __cdecl dGeomTriMeshGetArrayCallback(PdxGeom g);
extern "C" void * __cdecl dGeomTriMeshGetRayCallback(PdxGeom g);
extern "C" void __cdecl dGeomTriMeshSetArrayCallback(PdxGeom g, void * ArrayCallback);
extern "C" void __cdecl dGeomTriMeshSetRayCallback(PdxGeom g, void * RayCallback);
extern "C" void __cdecl dGeomTriMeshSetCallback(PdxGeom g, void * callback);
extern "C" void * __cdecl dGeomTriMeshGetCallback(PdxGeom g);
extern "C" void __cdecl dGeomTriMeshDataDestroy(PdxTriMeshData g);
extern "C" PdxTriMeshData __cdecl dGeomTriMeshDataCreate(void);
extern "C" void __cdecl dGeomTriMeshDataSet(PdxTriMeshData g, int data_id, void * data);
extern "C" void __cdecl dGeomTriMeshDataBuildSimple(PdxTriMeshData g, PdVector3Array Vertices, int VertexCount, PdIntegerArray Indices, int IndexCount);
extern "C" void __cdecl dGeomTriMeshDataBuildSimple1(PdxTriMeshData g, PdVector3Array Vertices, int VertexCount, PdIntegerArray Indices, int IndexCount, PdVector3Array Normals);
extern "C" void __cdecl dGeomTriMeshDataBuildDouble(PdxTriMeshData g, PdVector3Array Vertices, int VertexStride, int VertexCount, PdIntegerArray Indices, int IndexCount, int TriStride);
extern "C" void __cdecl dGeomTriMeshDataBuildDouble1(PdxTriMeshData g, PdVector3Array Vertices, int VertexStride, int VertexCount, PdIntegerArray Indices, int IndexCount, int TriStride, PdVector3Array Normals);
extern "C" void __cdecl dGeomTriMeshDataBuildSingle(PdxTriMeshData g, PdVector3Array Vertices, int VertexStride, int VertexCount, PdIntegerArray Indices, int IndexCount, int TriStride);
extern "C" void __cdecl dGeomTriMeshDataBuildSingle1(PdxTriMeshData g, PdVector3Array Vertices, int VertexStride, int VertexCount, PdIntegerArray Indices, int IndexCount, int TriStride, PdVector3Array Normals);
extern "C" void __cdecl dInfiniteAABB(PdxGeom geom, TdAABB &aabb);
extern "C" void __cdecl dSpaceDestroy(const PdxSpace Space);
extern "C" PdxSpace __cdecl dSimpleSpaceCreate(PdxSpace Space);
extern "C" PdxSpace __cdecl dHashSpaceCreate(PdxSpace Space);
extern "C" PdxSpace __cdecl dQuadTreeSpaceCreate(const PdxSpace Space, const TdVector3 &Center, const TdVector3 &Extents, const int depth);
extern "C" void __cdecl dSpaceAdd(const PdxSpace Space, const PdxGeom geom);
extern "C" void __cdecl dSpaceRemove(const PdxSpace Space, const PdxGeom geom);
extern "C" void __cdecl dSpaceClean(const PdxSpace Space);
extern "C" int __cdecl dSpaceQuery(const PdxSpace Space, const PdxGeom geom);
extern "C" int __cdecl dSpaceGetNumGeoms(const PdxSpace Space);
extern "C" PdxGeom __cdecl dSpaceGetGeom(const PdxSpace Space, const int I);
extern "C" void __cdecl dHashSpaceSetLevels(const PdxSpace Space, const int minlevel, const int maxlevel);
extern "C" void __cdecl dHashSpaceGetLevels(const PdxSpace Space, int &minlevel, int &maxlevel);
extern "C" void __cdecl dSpaceSetCleanup(PdxSpace Space, const int mode);
extern "C" int __cdecl dSpaceGetCleanup(PdxSpace Space);
extern "C" int __cdecl dCollide(PdxGeom o1, PdxGeom o2, int flags, TdContactGeom &contact, int skip);
extern "C" void __cdecl dSpaceCollide(const PdxSpace Space, void * data, TdNearCallback callback);
extern "C" void __cdecl dSpaceCollide2(PdxGeom o1, PdxGeom o2, void * data, TdNearCallback callback);
extern "C" void __cdecl dMassSetParameters(TdMass &m, TdReal themass, TdReal cgx, TdReal cgy, TdReal cgz, TdReal I11, TdReal I22, TdReal I33, TdReal I12, TdReal I13, TdReal I23);
extern "C" void __cdecl dMassAdd(TdMass &a, TdMass &b);
extern "C" void __cdecl dMassAdjust(TdMass &m, TdReal newmass);
extern "C" void __cdecl dMassTranslate(TdMass &m, TdReal x, TdReal y, TdReal z);
extern "C" void __cdecl dMassRotate(TdMass &m, TdMatrix3 &R);
extern "C" void __cdecl dMassSetZero(TdMass &m);
extern "C" void __cdecl dMassSetBox(TdMass &m, TdReal density, TdReal lx, TdReal ly, TdReal lz);
extern "C" void __cdecl dMassSetBoxTotal(TdMass &m, TdReal total_mass, TdReal lx, TdReal ly, TdReal lz);
extern "C" void __cdecl dMassSetCylinder(TdMass &m, TdReal density, int direction, TdReal radius, TdReal length);
extern "C" void __cdecl dMassSetCylinderTotal(TdMass &m, TdReal total_mass, int direction, TdReal radius, TdReal length);
extern "C" void __cdecl dMassSetCapsule(TdMass &m, TdReal density, int direction, TdReal radius, TdReal length);
extern "C" void __cdecl dMassSetCapsuleTotal(TdMass &m, TdReal total_mass, int direction, TdReal radius, TdReal length);
extern "C" void __cdecl dMassSetSphere(TdMass &m, TdReal density, TdReal radius);
extern "C" void __cdecl dMassSetSphereTotal(TdMass &m, TdReal total_mass, TdReal radius);
extern "C" void __cdecl dMassSetTrimesh(TdMass &m, TdReal density, PdxGeom TriMesh);
extern "C" void __cdecl dMassSetTrimeshTotal(TdMass &m, TdReal total_mass, PdxGeom TriMesh);
extern "C" void __cdecl dQFromAxisAndAngle(TdQuaternion &q, const TdReal ax, const TdReal ay, const TdReal az, const TdReal angle);
extern "C" void __cdecl dRFromAxisAndAngle(TdMatrix3 &R, const TdReal ax, const TdReal ay, const TdReal az, const TdReal angle);
extern "C" void __cdecl dRSetIdentity(TdMatrix3 &R);
extern "C" void __cdecl dQSetIdentity(TdQuaternion &q);
extern "C" void __cdecl dRFromEulerAngles(TdMatrix3 &R, const TdReal phi, const TdReal theta, const TdReal psi);
extern "C" void __cdecl dRFrom2Axes(TdMatrix3 &R, const TdReal ax, const TdReal ay, const TdReal az, const TdReal bx, const TdReal by, const TdReal bz);
extern "C" void __cdecl dRFromZAxis(TdMatrix3 &R, const TdReal ax, const TdReal ay, const TdReal az);
extern "C" void __cdecl dMultiply0(const PdReal a, const PdReal b, const PdReal c, int p, int q, int R);
extern "C" void __cdecl dMultiply1(const PdReal a, const PdReal b, const PdReal c, int p, int q, int R);
extern "C" void __cdecl dMultiply2(const PdReal a, const PdReal b, const PdReal c, int p, int q, int R);
extern "C" void __cdecl dQMultiply0(TdQuaternion &qa, const TdQuaternion &qb, const TdQuaternion &qc);
extern "C" void __cdecl dQMultiply1(TdQuaternion &qa, const TdQuaternion &qb, const TdQuaternion &qc);
extern "C" void __cdecl dQMultiply2(TdQuaternion &qa, const TdQuaternion &qb, const TdQuaternion &qc);
extern "C" void __cdecl dQMultiply3(TdQuaternion &qa, const TdQuaternion &qb, const TdQuaternion &qc);
extern "C" void __cdecl dRfromQ(TdMatrix3 &R, const TdQuaternion &q);
extern "C" void __cdecl dQfromR(TdQuaternion &q, const TdMatrix3 &R);
extern "C" void __cdecl dDQfromW(TdVector4 &dq, const TdVector3 &w, const TdQuaternion &q);
extern "C" void __cdecl dNormalize3(TdVector3 &a);
extern "C" void __cdecl dNormalize4(TdVector4 &a);
extern "C" void __cdecl dClosestLineSegmentPoints(const TdVector3 &a1, const TdVector3 &a2, const TdVector3 &b1, const TdVector3 &b2, TdVector3 &cp1, TdVector3 &cp2);
extern "C" int __cdecl dBoxTouchesBox(const TdVector3 &_p1, const TdMatrix3 &R1, const TdVector3 &side1, const TdVector3 &_p2, const TdMatrix3 &R2, const TdVector3 &side2);
extern "C" TdReal __cdecl dMaxDifference(PdReal a, PdReal b, int n, int m);
extern "C" void __cdecl dMakeRandomVector(TdVector3 &n1, int a, TdReal f);
extern "C" int __cdecl dAreConnected(PdxBody a, PdxBody b);
extern "C" int __cdecl dAreConnectedExcluding(PdxBody a, PdxBody b, TdJointTypeNumbers joint_type);
extern "C" void __cdecl dMakeRandomMatrix(PdRealArray a, int n, int m, TdReal range);
extern "C" void __cdecl dClearUpperTriangle(PdRealArray a, int n);
extern "C" unsigned __cdecl dRandGetSeed(void);
extern "C" void __cdecl dRandSetSeed(const unsigned s);
extern "C" int __cdecl dRandInt(const int n);
extern "C" TdReal __cdecl dRandReal(void);
extern "C" int __cdecl dTestRand(void);
extern "C" void __cdecl dTestMatrixComparison(void);
extern "C" void __cdecl dTestSolveLCP(void);
static _DELPHI_CONST System::Int8 MaxUserClasses = System::Int8(0x4);
extern DELPHI_PACKAGE int dSphereClass;
extern DELPHI_PACKAGE int dBoxClass;
extern DELPHI_PACKAGE int dCapsuleClass;
extern DELPHI_PACKAGE int dCylinderClass;
extern DELPHI_PACKAGE int dPlaneClass;
extern DELPHI_PACKAGE int dRayClass;
extern DELPHI_PACKAGE int dConvexClass;
extern DELPHI_PACKAGE int dGeomTransformClass;
extern DELPHI_PACKAGE int dTriMeshClass;
extern DELPHI_PACKAGE int dHeightFieldClass;
extern DELPHI_PACKAGE int dFirstSpaceClass;
extern DELPHI_PACKAGE int dSimpleSpaceClass;
extern DELPHI_PACKAGE int dHashSpaceClass;
extern DELPHI_PACKAGE int dSweepAndPruneSpaceClass;
extern DELPHI_PACKAGE int dQuadTreeSpaceClass;
extern DELPHI_PACKAGE int dLastSpaceClass;
extern DELPHI_PACKAGE int dFirstUserClass;
extern DELPHI_PACKAGE int dLastUserClass;
extern DELPHI_PACKAGE int dGeomNumClasses;
extern DELPHI_PACKAGE bool IsODEInitialized;
extern DELPHI_PACKAGE bool DisabledDebugGeom;
extern DELPHI_PACKAGE bool DisabledDebugCollision;
extern DELPHI_PACKAGE float __fastcall dDot(const PdVector3 a, const PdVector3 b)/* overload */;
extern DELPHI_PACKAGE TdReal __fastcall dDot(const TdVector3 &a, const TdVector3 &b)/* overload */;
extern DELPHI_PACKAGE TdReal __fastcall dDOT14(const TdRealArray &a, const TdRealArray &b)/* overload */;
extern DELPHI_PACKAGE float __fastcall dDOT14(const PdRealArray a, const PdRealArray b)/* overload */;
extern DELPHI_PACKAGE void __fastcall dMULTIPLY0_331(TdVector3 &a, const TdMatrix3 &b, const TdVector3 &c);
extern DELPHI_PACKAGE void __fastcall dMULTIPLY0_333(TdMatrix3 &a, const TdMatrix3 &b, const TdMatrix3 &c);
extern DELPHI_PACKAGE TdVector3 __fastcall Vector3ScalarMul(const TdVector3 &a, const TdReal Scalar);
extern DELPHI_PACKAGE TdVector3 __fastcall Vector3ADD(const TdVector3 &a, const TdVector3 &b);
extern DELPHI_PACKAGE TdVector3 __fastcall Vector3SUB(const TdVector3 &a, const TdVector3 &b);
extern DELPHI_PACKAGE TdReal __fastcall Vector3Length(const TdVector3 &a);
extern DELPHI_PACKAGE TdVector3 __fastcall Vector3Cross(const TdVector3 &v1, const TdVector3 &v2);
extern DELPHI_PACKAGE TdVector3 __fastcall Vector3Make(const TdReal x, const TdReal y, const TdReal z);
extern DELPHI_PACKAGE void __fastcall VerifyDelphiODE(PdxBody body, PdxGeom geom);
extern DELPHI_PACKAGE bool __fastcall InitODE(System::WideChar * ADllName);
extern DELPHI_PACKAGE void __fastcall CloseODE(void);
}	/* namespace Import */
}	/* namespace Ode */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_ODE_IMPORT)
using namespace Ode::Import;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_ODE)
using namespace Ode;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ODE_ImportHPP

// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NGD.Import.pas' rev: 36.00 (Windows)

#ifndef NGD_ImportHPP
#define NGD_ImportHPP

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

//-- user supplied -----------------------------------------------------------

namespace Ngd
{
namespace Import
{
//-- forward type declarations -----------------------------------------------
struct TNewtonMaterialData;
struct TNewtonCollisionMaterial;
struct TNewtonBoxParam;
struct TNewtonSphereParam;
struct TNewtonCylinderParam;
struct TNewtonCapsuleParam;
struct TNewtonConeParam;
struct TNewtonTaperedCapsuleParam;
struct TNewtonTaperedCylinderParam;
struct TNewtonChamferCylinderParam;
struct TNewtonConvexHullParam;
struct TNewtonCompoundCollisionParam;
struct TNewtonCollisionTreeParam;
struct TNewtonDeformableMeshParam;
struct TNewtonHeightFieldCollisionParam;
struct TNewtonSceneCollisionParam;
#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonCollisionNullParam
{
};
#pragma pack(pop)


struct TNewtonCollisionInfoRecord;
struct NewtonJointRecord;
struct NewtonUserMeshCollisionCollideDesc;
struct NewtonWorldConvexCastReturnInfo;
struct NewtonUserMeshCollisionRayHitDesc;
struct NewtonHingeSliderUpdateDesc;
struct NewtonUserContactPoint;
struct NewtonMeshDoubleData;
struct NewtonMeshFloatData;
struct NewtonMeshVertexFormat;
//-- type declarations -------------------------------------------------------
typedef float dFloat;

typedef double dFloat64;

typedef __int64 dLong;

typedef float *PdFloat;

typedef double *PdFloat64;

typedef __int64 *PdLong;

typedef System::Extended Long_double;

typedef System::Int8 __Int8;

typedef short __Int16;

typedef System::LongInt __Int32;

typedef __int64 __Int64;

typedef System::Int8 nchar;

typedef System::Byte unsigned_char;

typedef short Short;

typedef System::Word unsigned_short;

typedef System::LongInt Long;

typedef System::LongWord unsigned_long;

typedef unsigned unsigned_int;

typedef unsigned size_t;

typedef System::StaticArray<System::WideChar, 256> charArray;

typedef System::Int8 *P__int8;

typedef short *P__int16;

typedef int *P__int32;

typedef __int64 *P__int64;

typedef System::Int8 *P2Char;

typedef System::Byte *PUnsigned_char;

typedef short *PShort;

typedef System::Word *PUnsigned_short;

typedef int *PLong;

typedef unsigned *PUnsigned_long;

typedef unsigned *PUnsigned_int;

typedef unsigned *Psize_t;

typedef System::Extended *PLong_double;

typedef charArray *PCharArray;

typedef bool Bool;

typedef void * Pvoid;

typedef bool *PBool;

typedef void * PNewtonMesh;

typedef void * PNewtonBody;

typedef void * PNewtonWorld;

typedef void * PNewtonJoint;

typedef void * PNewtonMaterial;

typedef void * PNewtonCollision;

typedef void * PNewtonDeformableMeshSegment;

typedef void * PNewtonFracturedCompoundMeshPart;

typedef void * PNewtonSerializeHandle;

typedef void * PNewtonMeshHandle;

typedef void * PNewtonMeshVertex;

typedef void * PNewtonMeshPoint;

typedef void * PNewtonMeshEdge;

typedef void * PNewtonMeshFace;

typedef void * PNewtonSceneProxy;

typedef void * PNewtonBreakableComponentMesh;

typedef void * PNewtonListener;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonMaterialData
{
public:
	void *m_ptr;
	dLong m_int;
	dFloat m_float;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonCollisionMaterial
{
public:
	dLong m_userId;
	TNewtonMaterialData m_userData;
	System::StaticArray<TNewtonMaterialData, 6> m_userParam;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonBoxParam
{
public:
	dFloat m_x;
	dFloat m_y;
	dFloat m_z;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonSphereParam
{
public:
	dFloat m_radio;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonCylinderParam
{
public:
	dFloat m_radio;
	dFloat m_height;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonCapsuleParam
{
public:
	dFloat m_radio;
	dFloat m_height;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonConeParam
{
public:
	dFloat m_radio;
	dFloat m_height;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonTaperedCapsuleParam
{
public:
	dFloat m_radio0;
	dFloat m_radio1;
	dFloat m_height;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonTaperedCylinderParam
{
public:
	dFloat m_radio0;
	dFloat m_radio1;
	dFloat m_height;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonChamferCylinderParam
{
public:
	dFloat m_radio;
	dFloat m_height;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonConvexHullParam
{
public:
	int m_vertexCount;
	int m_vertexStrideInBytes;
	int m_faceCount;
	PdFloat m_vertex;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonCompoundCollisionParam
{
public:
	int m_chidrenCount;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonCollisionTreeParam
{
public:
	int m_vertexCount;
	int m_indexCount;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonDeformableMeshParam
{
public:
	int m_vertexCount;
	int m_triangleCount;
	int m_vertexStrideInBytes;
	System::PWord m_indexList;
	PdFloat m_vertexList;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonHeightFieldCollisionParam
{
public:
	int m_width;
	int m_height;
	int m_gridsDiagonals;
	int m_elevationDataType;
	dFloat m_verticalScale;
	dFloat m_horizonalScale_x;
	dFloat m_horizonalScale_z;
	void *m_vertialElevation;
	System::WideChar *m_atributes;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonSceneCollisionParam
{
public:
	int m_childrenProxyCount;
};
#pragma pack(pop)


typedef TNewtonCollisionInfoRecord *PNewtonCollisionInfoRecord;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TNewtonCollisionInfoRecord
{
public:
	System::StaticArray<System::StaticArray<float, 4>, 4> m_offsetMatrix;
	TNewtonCollisionMaterial m_collisionMaterial;
	int m_collisionType;
	
public:
	union
	{
		struct 
		{
			TNewtonSceneCollisionParam sdSceneCollision;
		};
		struct 
		{
			TNewtonHeightFieldCollisionParam sdHeightfield;
		};
		struct 
		{
			TNewtonCollisionTreeParam sdTree;
		};
		struct 
		{
			TNewtonCompoundCollisionParam sdCompound;
		};
		struct 
		{
			
		};
		struct 
		{
			TNewtonConvexHullParam sdConvexhull;
		};
		struct 
		{
			TNewtonChamferCylinderParam sdChamfercylinder;
		};
		struct 
		{
			TNewtonCylinderParam sdCylinder;
		};
		struct 
		{
			TNewtonCapsuleParam sdCapsule;
		};
		struct 
		{
			TNewtonSphereParam sdSphere;
		};
		struct 
		{
			TNewtonConeParam shapedata;
		};
		struct 
		{
			TNewtonBoxParam sdbox;
		};
		
	};
};
#pragma pack(pop)


typedef NewtonJointRecord *PNewtonJointRecord;

#pragma pack(push,1)
struct DECLSPEC_DRECORD NewtonJointRecord
{
public:
	System::StaticArray<System::StaticArray<float, 4>, 4> m_attachmenMatrix_0;
	System::StaticArray<System::StaticArray<float, 4>, 4> m_attachmenMatrix_1;
	System::StaticArray<float, 3> m_minLinearDof;
	System::StaticArray<float, 3> m_maxLinearDof;
	System::StaticArray<float, 3> m_minAngularDof;
	System::StaticArray<float, 3> m_maxAngularDof;
	PNewtonBody m_attachBody_0;
	PNewtonBody m_attachBody_1;
	System::StaticArray<float, 16> m_extraParameters;
	int m_bodiesCollisionOn;
	System::StaticArray<float, 32> m_descriptionType;
};
#pragma pack(pop)


typedef NewtonUserMeshCollisionCollideDesc *PNewtonUserMeshCollisionCollideDesc;

struct DECLSPEC_DRECORD NewtonUserMeshCollisionCollideDesc
{
public:
	System::StaticArray<float, 4> m_boxP0;
	System::StaticArray<float, 4> m_boxP1;
	System::StaticArray<float, 4> m_boxDistanceTravel;
	int m_threadNumber;
	int m_faceCount;
	int m_vertexStrideInBytes;
	dFloat m_skinThickness;
	void *m_userData;
	PNewtonBody m_objBody;
	PNewtonBody m_polySoupBody;
	PNewtonCollision m_objCollision;
	PNewtonCollision m_polySoupCollision;
	float *m_vertex;
	int *m_faceIndexCount;
	int *m_faceVertexIndex;
};


typedef NewtonWorldConvexCastReturnInfo *PNewtonWorldConvexCastReturnInfo;

struct DECLSPEC_DRECORD NewtonWorldConvexCastReturnInfo
{
public:
	System::StaticArray<float, 4> m_point;
	System::StaticArray<float, 4> m_normal;
	System::StaticArray<float, 4> m_normalOnHitPoint;
	int m_contactID;
	PNewtonBody m_hitBody;
	dFloat m_penetration;
};


typedef NewtonUserMeshCollisionRayHitDesc *PNewtonUserMeshCollisionRayHitDesc;

struct DECLSPEC_DRECORD NewtonUserMeshCollisionRayHitDesc
{
public:
	System::StaticArray<float, 4> m_p0;
	System::StaticArray<float, 4> m_p1;
	System::StaticArray<float, 4> m_normalOut;
	int m_userIdOut;
	void *m_userData;
};


typedef NewtonHingeSliderUpdateDesc *PNewtonHingeSliderUpdateDesc;

#pragma pack(push,1)
struct DECLSPEC_DRECORD NewtonHingeSliderUpdateDesc
{
public:
	dFloat m_accel;
	dFloat m_minFriction;
	dFloat m_maxFriction;
	dFloat m_timestep;
};
#pragma pack(pop)


typedef NewtonUserContactPoint *PNewtonUserContactPoint;

#pragma pack(push,1)
struct DECLSPEC_DRECORD NewtonUserContactPoint
{
public:
	System::StaticArray<float, 4> m_point;
	System::StaticArray<float, 4> m_normal;
	dLong m_shapeId0;
	dLong m_shapeId1;
	dFloat m_penetration;
	System::StaticArray<int, 3> m_unused;
};
#pragma pack(pop)


typedef NewtonMeshDoubleData *PNewtonMeshDoubleData;

#pragma pack(push,1)
struct DECLSPEC_DRECORD NewtonMeshDoubleData
{
public:
	PdFloat64 m_data;
	int *m_indexList;
	int m_strideInBytes;
};
#pragma pack(pop)


typedef NewtonMeshFloatData *PNewtonMeshFloatData;

#pragma pack(push,1)
struct DECLSPEC_DRECORD NewtonMeshFloatData
{
public:
	PdFloat m_data;
	int *m_indexList;
	int m_strideInBytes;
};
#pragma pack(pop)


typedef NewtonMeshVertexFormat *PNewtonMeshVertexFormat;

#pragma pack(push,1)
struct DECLSPEC_DRECORD NewtonMeshVertexFormat
{
public:
	int m_faceCount;
	int *m_faceIndexCount;
	int *m_faceMaterial;
	NewtonMeshDoubleData m_vertex;
	NewtonMeshFloatData m_normal;
	NewtonMeshFloatData m_binormal;
	NewtonMeshFloatData m_uv0;
	NewtonMeshFloatData m_uv1;
	NewtonMeshFloatData m_vertexColor;
};
#pragma pack(pop)


typedef void * __cdecl (*NewtonAllocMemory)(int sizeInBytes);

typedef NewtonAllocMemory *PNewtonAllocMemory;

typedef void __cdecl (*NewtonFreeMemory)(void * ptr, int sizeInBytes);

typedef NewtonFreeMemory *PNewtonFreeMemory;

typedef void __cdecl (*NewtonDestroyWorld)(const PNewtonWorld NewtonWorld);

typedef NewtonDestroyWorld *PNewtonDestroyWorld;

typedef unsigned __cdecl (*NewtonGetTicksCountCallback)(void);

typedef NewtonGetTicksCountCallback *PNewtonGetTicksCountCallback;

typedef void __cdecl (*NewtonSerialize)(void * serializeHandle, const void * buffer, size_t size);

typedef NewtonSerialize *PNewtonSerialize;

typedef void __cdecl (*NewtonDeserialize)(void * serializeHandle, void * buffer, size_t size);

typedef NewtonDeserialize *PNewtonDeserialize;

typedef void __cdecl (*NewtonUserMeshCollisionDestroyCallback)(void * descData);

typedef NewtonUserMeshCollisionDestroyCallback *PNewtonUserMeshCollisionDestroyCallback;

typedef void __cdecl (*NewtonUserMeshCollisionCollideCallback)(PNewtonUserMeshCollisionCollideDesc NewtonUserMeshCollisionCollideDesc);

typedef NewtonUserMeshCollisionCollideCallback *PNewtonUserMeshCollisionCollideCallback;

typedef int __cdecl (*NewtonUserMeshCollisionRayHitCallback)(PNewtonUserMeshCollisionRayHitDesc NewtonUserMeshCollisionRayHitDesc);

typedef NewtonUserMeshCollisionRayHitCallback *PNewtonUserMeshCollisionRayHitCallback;

typedef void __cdecl (*NewtonUserMeshCollisionGetCollisionInfo)(void * userData, PNewtonCollisionInfoRecord infoRecord);

typedef NewtonUserMeshCollisionGetCollisionInfo *PNewtonUserMeshCollisionGetCollisionInfo;

typedef int __cdecl (*NewtonUserMeshCollisionGetFacesInAABB)(void * userData, const PdFloat p0, const PdFloat p1, const PdFloat vertexArray, System::PInteger vertexCount, System::PInteger vertexStrideInBytes, const System::PInteger indexList, int maxIndexCount, const System::PInteger userDataList);

typedef NewtonUserMeshCollisionGetFacesInAABB *PNewtonUserMeshCollisionGetFacesInAABB;

typedef dFloat __cdecl (*NewtonCollisionTreeRayCastCallback)(const PNewtonBody Body, const PNewtonCollision TreeCollision, dFloat interception, PdFloat normal, int faceId, void * usedData);

typedef NewtonCollisionTreeRayCastCallback *PNewtonCollisionTreeRayCastCallback;

typedef dFloat __cdecl (*NewtonHeightFieldRayCastCallback)(const PNewtonBody Body, const PNewtonCollision HeightFieldCollision, dFloat interception, int Row, int Col, PdFloat normal, int faceId, void * usedData);

typedef NewtonHeightFieldRayCastCallback *PNewtonHeightFieldRayCastCallback;

typedef void __cdecl (*NewtonTreeCollisionCallback)(const PNewtonBody bodyWithTreeCollision, const PNewtonBody Body, int faceId, const PdFloat vertex, int vertexStrideInBytes);

typedef NewtonTreeCollisionCallback *PNewtonTreeCollisionCallback;

typedef void __cdecl (*NewtonBodyDestructor)(const PNewtonBody Body);

typedef NewtonBodyDestructor *PNewtonBodyDestructor;

typedef void __cdecl (*NewtonApplyForceAndTorque)(const PNewtonBody Body, dFloat timestep, int threadIndex);

typedef NewtonApplyForceAndTorque *PNewtonApplyForceAndTorque;

typedef void __cdecl (*NewtonSetTransform)(const PNewtonBody Body, const PdFloat matrix, int threadIndex);

typedef NewtonSetTransform *PNewtonSetTransform;

typedef int __cdecl (*NewtonIslandUpdate)(const PNewtonWorld World, void * islandHandle, int bodyCount);

typedef NewtonIslandUpdate *PNewtonIslandUpdate;

typedef void __cdecl (*NewtonBodyLeaveWorld)(const PNewtonBody Body, int threadIndex);

typedef NewtonBodyLeaveWorld *PNewtonBodyLeaveWorld;

typedef void __cdecl (*NewtonDestroyBodyByExeciveForce)(const PNewtonBody Body, const PNewtonJoint contact);

typedef NewtonDestroyBodyByExeciveForce *PNewtonDestroyBodyByExeciveForce;

typedef void __cdecl (*NewtonCollisionDestructor)(const PNewtonWorld World, const PNewtonCollision collision);

typedef NewtonCollisionDestructor *PNewtonCollisionDestructor;

typedef int __cdecl (*NewtonCollisionCompoundBreakableCallback)(const PNewtonMesh Mesh, void * userData, PdFloat planeMatrixOut);

typedef NewtonCollisionCompoundBreakableCallback *PNewtonCollisionCompoundBreakableCallback;

typedef int __cdecl (*NewtonGetBuoyancyPlane)(const int collisionID, void * context, const PdFloat globalSpaceMatrix, PdFloat globalSpacePlane);

typedef NewtonGetBuoyancyPlane *PNewtonGetBuoyancyPlane;

typedef unsigned __cdecl (*NewtonWorldRayPrefilterCallback)(const PNewtonBody Body, const PNewtonCollision collision, void * userData);

typedef NewtonWorldRayPrefilterCallback *PNewtonWorldRayPrefilterCallback;

typedef dFloat __cdecl (*NewtonWorldRayFilterCallback)(const PNewtonBody Body, const PdFloat hitNormal, int collisionID, void * userData, dFloat intersetParam);

typedef NewtonWorldRayFilterCallback *PNewtonWorldRayFilterCallback;

typedef int __cdecl (*NewtonOnAABBOverlap)(const PNewtonMaterial material, const PNewtonBody body0, const PNewtonBody body1, int threadIndex);

typedef NewtonOnAABBOverlap *PNewtonOnAABBOverlap;

typedef void __cdecl (*NewtonContactsProcess)(const PNewtonJoint contact, dFloat timestep, int threadIndex);

typedef NewtonContactsProcess *PNewtonContactsProcess;

typedef void __cdecl (*NewtonBodyIterator)(const PNewtonBody Body, void * userData);

typedef NewtonBodyIterator *PNewtonBodyIterator;

typedef void __cdecl (*NewtonJointIterator)(const PNewtonJoint joint, void * userData);

typedef NewtonJointIterator *PNewtonJointIterator;

typedef void __cdecl (*NewtonCollisionIterator)(void * userData, int vertexCount, const PdFloat FaceArray, int faceId);

typedef NewtonCollisionIterator *PNewtonCollisionIterator;

typedef void __cdecl (*NewtonBallCallBack)(const PNewtonJoint ball, dFloat timestep);

typedef NewtonBallCallBack *PNewtonBallCallBack;

typedef unsigned_int __cdecl (*NewtonHingeCallBack)(const PNewtonJoint hinge, PNewtonHingeSliderUpdateDesc desc);

typedef NewtonHingeCallBack *PNewtonHingeCallBack;

typedef unsigned_int __cdecl (*NewtonSliderCallBack)(const PNewtonJoint slider, PNewtonHingeSliderUpdateDesc desc);

typedef NewtonSliderCallBack *PNewtonSliderCallBack;

typedef unsigned_int __cdecl (*NewtonUniversalCallBack)(const PNewtonJoint universal, PNewtonHingeSliderUpdateDesc desc);

typedef NewtonUniversalCallBack *PNewtonUniversalCallBack;

typedef unsigned_int __cdecl (*NewtonCorkscrewCallBack)(const PNewtonJoint corkscrew, PNewtonHingeSliderUpdateDesc desc);

typedef NewtonCorkscrewCallBack *PNewtonCorkscrewCallBack;

typedef void __cdecl (*NewtonUserBilateralCallBack)(const PNewtonJoint userJoint, dFloat timestep, int threadIndex);

typedef NewtonUserBilateralCallBack *PNewtonUserBilateralCallBack;

typedef void __cdecl (*NewtonUserBilateralGetInfoCallBack)(const PNewtonJoint userJoint, PNewtonJointRecord info);

typedef NewtonUserBilateralGetInfoCallBack *PNewtonUserBilateralGetInfoCallBack;

typedef void __cdecl (*NewtonConstraintDestructor)(const PNewtonJoint me);

typedef NewtonConstraintDestructor *PNewtonConstraintDestructor;

typedef System::DynamicArray<void *> TCollisionPrimitiveArray;

//-- var, const, procedure ---------------------------------------------------
#define NewtonDLL L"newton32.dll"
static _DELPHI_CONST System::Int8 NEWTON_MAJOR_VERSION = System::Int8(0x3);
static _DELPHI_CONST System::Int8 NEWTON_MINOR_VERSION = System::Int8(0xf);
static _DELPHI_CONST System::Int8 NEWTON_BROADPHASE_DEFAULT = System::Int8(0x0);
static _DELPHI_CONST System::Int8 NEWTON_PROFILER_WORLD_UPDATE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 NEWTON_DYNAMIC_BODY = System::Int8(0x0);
static _DELPHI_CONST System::Int8 NEWTON_PROFILER_COLLISION_UPDATE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 NEWTON_PROFILER_COLLISION_UPDATE_BROAD_PHASE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 NEWTON_PROFILER_COLLISION_UPDATE_NARROW_PHASE = System::Int8(0x3);
static _DELPHI_CONST System::Int8 NEWTON_PROFILER_DYNAMICS_UPDATE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 NEWTON_PROFILER_DYNAMICS_CONSTRAINT_GRAPH = System::Int8(0x5);
static _DELPHI_CONST System::Int8 NEWTON_PROFILER_FORCE_CALLBACK_UPDATE = System::Int8(0x6);
static _DELPHI_CONST System::Int8 NEWTON_PROFILER_DYNAMICS_SOLVE_CONSTRAINT_GRAPH = System::Int8(0x7);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_SPHERE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_CAPSULE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_CYLINDER = System::Int8(0x2);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_CHAMFERCYLINDER = System::Int8(0x3);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_BOX = System::Int8(0x4);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_CONE = System::Int8(0x5);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_CONVEXHULL = System::Int8(0x6);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_NULL = System::Int8(0x7);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_COMPOUND = System::Int8(0x8);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_TREE = System::Int8(0x9);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_HEIGHTFIELD = System::Int8(0xa);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_CLOTH_PATCH = System::Int8(0xb);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_DEFORMABLE_SOLID = System::Int8(0xc);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_USERMESH = System::Int8(0xd);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_SCENE = System::Int8(0xe);
static _DELPHI_CONST System::Int8 SERIALIZE_ID_FRACTURED_COMPOUND = System::Int8(0xf);
extern "C" int __cdecl NewtonWorldGetVersion(const PNewtonWorld NewtonWorld);
extern "C" int __cdecl NewtonWorldFloatSize(const PNewtonWorld NewtonWorld);
extern "C" PNewtonWorld __cdecl NewtonCreate(NewtonAllocMemory malloc, NewtonFreeMemory mfree);
extern "C" void __cdecl NewtonDestroy(const PNewtonWorld NewtonWorld);
extern "C" void __cdecl NewtonDestroyAllBodies(const PNewtonWorld NewtonWorld);
extern "C" int __cdecl NewtonGetMemoryUsed(void);
extern "C" void __cdecl NewtonSetMemorySystem(NewtonAllocMemory malloc, NewtonFreeMemory mfree);
extern "C" void __cdecl NewtonUpdate(const PNewtonWorld NewtonWorld, dFloat timestep);
extern "C" void __cdecl NewtonInvalidateCache(const PNewtonWorld NewtonWorld);
extern "C" void __cdecl NewtonCollisionUpdate(const PNewtonWorld NewtonWorld);
extern "C" void __cdecl NewtonSetSolverModel(const PNewtonWorld NewtonWorld, int Model);
extern "C" void __cdecl NewtonSetPlatformArchitecture(const PNewtonWorld NewtonWorld, int mode);
extern "C" int __cdecl NewtonGetPlatformArchitecture(const PNewtonWorld NewtonWorld, PCharArray description);
extern "C" void __cdecl NewtonSetMultiThreadSolverOnSingleIsland(const PNewtonWorld NewtonWorld, int mode);
extern "C" int __cdecl NewtonGetMultiThreadSolverOnSingleIsland(const PNewtonWorld NewtonWorld);
extern "C" void __cdecl NewtonSetPerformanceClock(const PNewtonWorld NewtonWorld, PNewtonGetTicksCountCallback NewtonGetTicksCountCallback);
extern "C" unsigned __cdecl NewtonReadPerformanceTicks(const PNewtonWorld NewtonWorld, unsigned performanceEntry);
extern "C" unsigned __cdecl NewtonReadThreadPerformanceTicks(const PNewtonWorld NewtonWorld, unsigned threadIndex);
extern "C" void __cdecl NewtonWorldCriticalSectionLock(const PNewtonWorld NewtonWorld);
extern "C" void __cdecl NewtonWorldCriticalSectionUnlock(const PNewtonWorld NewtonWorld);
extern "C" void __cdecl NewtonSetThreadsCount(const PNewtonWorld NewtonWorld, int threads);
extern "C" int __cdecl NewtonGetThreadsCount(const PNewtonWorld NewtonWorld);
extern "C" int __cdecl NewtonGetMaxThreadsCount(const PNewtonWorld NewtonWorld);
extern "C" void __cdecl NewtonSetFrictionModel(const PNewtonWorld NewtonWorld, int Model);
extern "C" void __cdecl NewtonSetMinimumFrameRate(const PNewtonWorld NewtonWorld, dFloat frameRate);
extern "C" void __cdecl NewtonSetBodyLeaveWorldEvent(const PNewtonWorld NewtonWorld, PNewtonBodyLeaveWorld callback);
extern "C" void __cdecl NewtonSetWorldSize(const PNewtonWorld NewtonWorld, const PdFloat minPoint, const PdFloat maxPoint);
extern "C" void __cdecl NewtonSetIslandUpdateEvent(const PNewtonWorld NewtonWorld, PNewtonIslandUpdate NewtonIslandUpdate);
extern "C" void __cdecl NewtonSetCollisionDestructor(const PNewtonWorld NewtonWorld, PNewtonCollisionDestructor callback);
extern "C" void __cdecl NewtonSetDestroyBodyByExeciveForce(const PNewtonWorld NewtonWorld, PNewtonDestroyBodyByExeciveForce callback);
extern "C" void __cdecl NewtonWorldForEachJointDo(const PNewtonWorld NewtonWorld, PNewtonJointIterator callback, void * userData);
extern "C" void __cdecl NewtonWorldForEachBodyInAABBDo(const PNewtonWorld NewtonWorld, const PdFloat p0, const PdFloat p1, PNewtonBodyIterator callback, void * userData);
extern "C" void __cdecl NewtonWorldSetUserData(const PNewtonWorld NewtonWorld, void * userData);
extern "C" void * __cdecl NewtonWorldGetUserData(const PNewtonWorld NewtonWorld);
extern "C" void __cdecl NewtonWorldSetDestructorCallBack(const PNewtonWorld NewtonWorld, PNewtonDestroyWorld NewtonDestroyWorld);
extern "C" PNewtonDestroyWorld __cdecl NewtonWorldGetDestructorCallBack(const PNewtonWorld NewtonWorld);
extern "C" void __cdecl NewtonWorldRayCast(const PNewtonWorld NewtonWorld, const PdFloat p0, const PdFloat p1, PNewtonWorldRayFilterCallback filter, void * userData, NewtonWorldRayPrefilterCallback prefilter);
extern "C" int __cdecl NewtonWorldConvexCast(const PNewtonWorld NewtonWorld, const PdFloat matrix, const PdFloat target, const PNewtonCollision shape, PdFloat hitParam, void * userData, NewtonWorldRayPrefilterCallback prefilter, PNewtonWorldConvexCastReturnInfo info, int maxContactsCount, int threadIndex);
extern "C" int __cdecl NewtonWorldGetBodyCount(const PNewtonWorld NewtonWorld);
extern "C" int __cdecl NewtonWorldGetConstraintCount(const PNewtonWorld NewtonWorld);
extern "C" PNewtonBody __cdecl NewtonIslandGetBody(const void * island, int bodyIndex);
extern "C" void __cdecl NewtonIslandGetBodyAABB(const void * island, int bodyIndex, PdFloat p0, PdFloat p1);
extern "C" int __cdecl NewtonMaterialCreateGroupID(const PNewtonWorld NewtonWorld);
extern "C" int __cdecl NewtonMaterialGetDefaultGroupID(const PNewtonWorld NewtonWorld);
extern "C" void __cdecl NewtonMaterialDestroyAllGroupID(const PNewtonWorld NewtonWorld);
extern "C" void * __cdecl NewtonMaterialGetUserData(const PNewtonWorld NewtonWorld, int id0, int id1);
extern "C" void __cdecl NewtonMaterialSetSurfaceThickness(const PNewtonWorld NewtonWorld, int id0, int id1, dFloat thickness);
extern "C" void __cdecl NewtonMaterialSetContinuousCollisionMode(const PNewtonWorld NewtonWorld, int id0, int id1, int state);
extern "C" void __cdecl NewtonMaterialSetCollisionCallback(const PNewtonWorld NewtonWorld, int id0, int id1, void * userData, PNewtonOnAABBOverlap AABBOverlap, PNewtonContactsProcess process);
extern "C" void __cdecl NewtonMaterialSetDefaultSoftness(const PNewtonWorld NewtonWorld, int id0, int id1, dFloat value);
extern "C" void __cdecl NewtonMaterialSetDefaultElasticity(const PNewtonWorld NewtonWorld, int id0, int id1, dFloat elasticCoef);
extern "C" void __cdecl NewtonMaterialSetDefaultCollidable(const PNewtonWorld NewtonWorld, int id0, int id1, int state);
extern "C" void __cdecl NewtonMaterialSetDefaultFriction(const PNewtonWorld NewtonWorld, int id0, int id1, dFloat staticFriction, dFloat kineticFriction);
extern "C" PNewtonMaterial __cdecl NewtonWorldGetFirstMaterial(const PNewtonWorld NewtonWorld);
extern "C" PNewtonMaterial __cdecl NewtonWorldGetNextMaterial(const PNewtonWorld NewtonWorld, const PNewtonMaterial material);
extern "C" PNewtonBody __cdecl NewtonWorldGetFirstBody(const PNewtonWorld NewtonWorld);
extern "C" PNewtonBody __cdecl NewtonWorldGetNextBody(const PNewtonWorld NewtonWorld, const PNewtonBody curBody);
extern "C" void * __cdecl NewtonMaterialGetMaterialPairUserData(const PNewtonMaterial material);
extern "C" unsigned_int __cdecl NewtonMaterialGetContactFaceAttribute(const PNewtonMaterial material);
extern "C" PNewtonCollision __fastcall NewtonMaterialGetBodyCollidingShape(const PNewtonMaterial material, const PNewtonBody Body);
extern "C" unsigned_int __cdecl NewtonMaterialGetBodyCollisionID(const PNewtonMaterial material, PNewtonBody Body);
extern "C" dFloat __cdecl NewtonMaterialGetContactNormalSpeed(const PNewtonMaterial material);
extern "C" void __cdecl NewtonMaterialGetContactForce(const PNewtonMaterial material, const PNewtonBody Body, PdFloat Force);
extern "C" void __cdecl NewtonMaterialGetContactPositionAndNormal(const PNewtonMaterial material, const PNewtonBody Body, const PdFloat Posit, const PdFloat normal);
extern "C" void __cdecl NewtonMaterialGetContactTangentDirections(const PNewtonMaterial material, const PNewtonBody Body, const PdFloat Dir0, const PdFloat Dir1);
extern "C" dFloat __cdecl NewtonMaterialGetContactTangentSpeed(const PNewtonMaterial material, int index);
extern "C" void __cdecl NewtonMaterialSetContactSoftness(const PNewtonMaterial material, dFloat softness);
extern "C" void __cdecl NewtonMaterialSetContactElasticity(const PNewtonMaterial material, dFloat restitution);
extern "C" void __cdecl NewtonMaterialSetContactFrictionState(const PNewtonMaterial material, int state, int index);
extern "C" void __cdecl NewtonMaterialSetContactFrictionCoef(const PNewtonMaterial material, dFloat staticFrictionCoef, dFloat kineticFrictionCoef, int index);
extern "C" void __cdecl NewtonMaterialSetContactNormalAcceleration(const PNewtonMaterial material, dFloat accel);
extern "C" void __cdecl NewtonMaterialSetContactNormalDirection(const PNewtonMaterial material, PdFloat directionVector);
extern "C" void __cdecl NewtonMaterialSetContactTangentAcceleration(const PNewtonMaterial material, dFloat accel, int index);
extern "C" void __cdecl NewtonMaterialContactRotateTangentDirections(const PNewtonMaterial material, const PdFloat directionVector);
extern "C" PNewtonCollision __cdecl NewtonCreateNull(const PNewtonWorld NewtonWorld);
extern "C" PNewtonCollision __cdecl NewtonCreateSphere(const PNewtonWorld NewtonWorld, dFloat radiusX, dFloat radiusY, dFloat radiusZ, int shapeID, const PdFloat offsetMatrix);
extern "C" PNewtonCollision __cdecl NewtonCreateBox(const PNewtonWorld NewtonWorld, dFloat dx, dFloat dy, dFloat dz, int shapeID, const PdFloat offsetMatrix);
extern "C" PNewtonCollision __cdecl NewtonCreateCone(const PNewtonWorld NewtonWorld, dFloat radius, dFloat height, int shapeID, const PdFloat offsetMatrix);
extern "C" PNewtonCollision __cdecl NewtonCreateCapsule(const PNewtonWorld NewtonWorld, dFloat radius, dFloat height, int shapeID, const PdFloat offsetMatrix);
extern "C" PNewtonCollision __cdecl NewtonCreateCylinder(const PNewtonWorld NewtonWorld, dFloat radius, dFloat height, int shapeID, const PdFloat offsetMatrix);
extern "C" PNewtonCollision __cdecl NewtonCreateChamferCylinder(const PNewtonWorld NewtonWorld, dFloat raduis, dFloat height, int shapeID, const PdFloat offsetMatrix);
extern "C" PNewtonCollision __cdecl NewtonCreateConvexHull(const PNewtonWorld NewtonWorld, int count, const PdFloat vertexCloud, int strideInBytes, dFloat tolerance, int shapeID, const PdFloat offsetMatrix);
extern "C" PNewtonCollision __cdecl NewtonCreateConvexHullFromMesh(const PNewtonWorld NewtonWorld, PNewtonMesh мesh, dFloat tolerance, int shapeID);
extern "C" PNewtonCollision __cdecl NewtonCreateConvexHullModifier(const PNewtonWorld NewtonWorld, const PNewtonCollision convexHullCollision, int shapeID);
extern "C" void __cdecl NewtonConvexHullModifierGetMatrix(const PNewtonCollision convexHullCollision, PdFloat matrix);
extern "C" void __cdecl NewtonConvexHullModifierSetMatrix(const PNewtonCollision convexHullCollision, const PdFloat matrix);
extern "C" int __cdecl NewtonCollisionIsTriggerVolume(const PNewtonCollision convexCollision);
extern "C" void __cdecl NewtonCollisionSetAsTriggerVolume(const PNewtonCollision convexCollision, int trigger);
extern "C" void __cdecl NewtonCollisionSetMaxBreakImpactImpulse(const PNewtonCollision convexHullCollision, dFloat maxImpactImpulse);
extern "C" dFloat __cdecl NewtonCollisionGetMaxBreakImpactImpulse(const PNewtonCollision convexHullCollision);
extern "C" void __cdecl NewtonCollisionSetUserID(const PNewtonCollision convexCollision, unsigned_int id);
extern "C" unsigned_int __cdecl NewtonCollisionGetUserID(const PNewtonCollision convexCollision);
extern "C" int __cdecl NewtonConvexHullGetFaceIndices(const PNewtonCollision convexHullCollision, int face, System::PInteger faceIndices);
extern "C" dFloat __cdecl NewtonConvexCollisionCalculateVolume(const PNewtonCollision convexCollision);
extern "C" void __cdecl NewtonConvexCollisionCalculateInertialMatrix(const PNewtonCollision convexCollision, PdFloat inertia, PdFloat origin);
extern "C" void __cdecl NewtonCollisionMakeUnique(const PNewtonWorld NewtonWorld, const PNewtonCollision collision);
extern "C" void __cdecl NewtonReleaseCollision(const PNewtonWorld NewtonWorld, const PNewtonCollision collision);
extern "C" int __cdecl NewtonAddCollisionReference(const PNewtonCollision collision);
extern "C" PNewtonCollision __cdecl NewtonCreateCompoundCollision(const PNewtonWorld NewtonWorld, int count, const TCollisionPrimitiveArray collisionPrimitiveArray, int shapeID);
extern "C" PNewtonCollision __cdecl NewtonCreateCompoundCollisionFromMesh(const PNewtonWorld NewtonWorld, const PNewtonMesh Mesh, int maxSubShapesCount, int shapeID, int subShapeID);
extern "C" PNewtonCollision __cdecl NewtonCreateUserMeshCollision(const PNewtonWorld NewtonWorld, const PdFloat minBox, const PdFloat maxBox, void * userData, NewtonUserMeshCollisionCollideCallback collideCallback, NewtonUserMeshCollisionRayHitCallback rayHitCallback, NewtonUserMeshCollisionDestroyCallback destroyCallback, NewtonUserMeshCollisionGetCollisionInfo getInfoCallback, NewtonUserMeshCollisionGetFacesInAABB facesInAABBCallback, int shapeID);
extern "C" PNewtonCollision __cdecl NewtonCreateSceneCollision(const PNewtonWorld NewtonWorld, int shapeID);
extern "C" PNewtonSceneProxy __cdecl NewtonSceneCollisionCreateProxy(PNewtonCollision scene, PNewtonCollision collision);
extern "C" void __cdecl NewtonSceneCollisionDestroyProxy(PNewtonCollision scene, PNewtonSceneProxy Proxy);
extern "C" void __cdecl NewtonSceneProxySetMatrix(PNewtonSceneProxy Proxy, const PdFloat matrix);
extern "C" void __cdecl NewtonSceneProxyGetMatrix(PNewtonSceneProxy Proxy, PdFloat matrix);
extern "C" void __cdecl NewtonSceneSetProxyUserData(const PNewtonSceneProxy Proxy, void * userData);
extern "C" void * __cdecl NewtonSceneGetProxyUserData(const PNewtonSceneProxy Proxy);
extern "C" PNewtonSceneProxy __cdecl NewtonSceneGetFirstProxy(const PNewtonCollision scene);
extern "C" PNewtonSceneProxy __cdecl NewtonSceneGetNextProxy(const PNewtonCollision scene, const PNewtonSceneProxy Proxy);
extern "C" void __cdecl NewtonSceneCollisionOptimize(PNewtonCollision scene);
extern "C" PNewtonCollision __cdecl NewtonCreateCompoundBreakable(const PNewtonWorld NewtonWorld, int meshCount, const PNewtonMesh SolidsArray, const System::PInteger ShapeIDArray, PdFloat Densities, System::PInteger internalFaceMaterial, int shapeID, int debrisID, dFloat DebrisSeparationGap);
extern "C" void __cdecl NewtonCompoundBreakableResetAnchoredPieces(const PNewtonCollision compoundBreakable);
extern "C" void __cdecl NewtonCompoundBreakableSetAnchoredPieces(const PNewtonCollision compoundBreakable, int fixshapesCount, PdFloat matrixPallete, PNewtonCollision fixedShapesArray);
extern "C" int __cdecl NewtonCompoundBreakableGetVertexCount(const PNewtonCollision compoundBreakable);
extern "C" void __cdecl NewtonCompoundBreakableGetVertexStreams(const PNewtonCollision compoundBreakable, int vertexStrideInByte, PdFloat vertex, int normalStrideInByte, PdFloat normal, int uvStrideInByte, PdFloat uv);
extern "C" PNewtonBreakableComponentMesh __cdecl NewtonBreakableGetMainMesh(const PNewtonCollision compoundBreakable);
extern "C" PNewtonBreakableComponentMesh __cdecl NewtonBreakableGetFirstComponent(const PNewtonCollision compoundBreakable);
extern "C" PNewtonBreakableComponentMesh __cdecl NewtonBreakableGetNextComponent(const PNewtonBreakableComponentMesh component);
extern "C" void __cdecl NewtonBreakableBeginDelete(const PNewtonCollision compoundBreakable);
extern "C" PNewtonBody __cdecl NewtonBreakableCreateDebrieBody(const PNewtonCollision compoundBreakable, const PNewtonBreakableComponentMesh component);
extern "C" void __cdecl NewtonBreakableDeleteComponent(const PNewtonCollision compoundBreakable, const PNewtonBreakableComponentMesh component);
extern "C" void __cdecl NewtonBreakableEndDelete(const PNewtonCollision compoundBreakable);
extern "C" int __cdecl NewtonBreakableGetComponentsInRadius(const PNewtonCollision compoundBreakable, const PdFloat position, dFloat radius, PNewtonBreakableComponentMesh Segments, int maxCount);
extern "C" void * __cdecl NewtonBreakableGetFirstSegment(const PNewtonBreakableComponentMesh BreakableComponent);
extern "C" void * __cdecl NewtonBreakableGetNextSegment(const void * Segment);
extern "C" int __cdecl NewtonBreakableSegmentGetMaterial(const void * Segment);
extern "C" int __cdecl NewtonBreakableSegmentGetIndexCount(const void * Segment);
extern "C" int __cdecl NewtonBreakableSegmentGetIndexStream(PNewtonCollision compoundBreakable, const PNewtonBreakableComponentMesh MeshOwner, const void * Segment, System::PInteger index);
extern "C" int __cdecl NewtonBreakableSegmentGetIndexStreamShort(PNewtonCollision compoundBreakable, const PNewtonBreakableComponentMesh MeshOwner, const void * Segment, PShort index);
extern "C" PNewtonCollision __cdecl NewtonCreateCollisionFromSerialization(const PNewtonWorld NewtonWorld, PNewtonDeserialize deserializeFunction, void * serializeHandle);
extern "C" void __cdecl NewtonCollisionSerialize(const PNewtonWorld NewtonWorld, const PNewtonCollision collision, PNewtonSerialize serializeFunction, void * serializeHandle);
extern "C" void __cdecl NewtonCollisionGetInfo(const PNewtonCollision collision, PNewtonCollisionInfoRecord collisionInfo);
extern "C" PNewtonCollision __cdecl NewtonCreateHeightFieldCollision(const PNewtonWorld NewtonWorld, int width, int height, int gridDiagonals, PUnsigned_short elevationMap, P2Char attributeMap, dFloat horizontalScale, dFloat verticalScale, int shapeID);
extern "C" void __cdecl NewtonHeightFieldSetUserRayCastCallback(const PNewtonCollision TreeCollision, PNewtonHeightFieldRayCastCallback rayHitCallback);
extern "C" PNewtonCollision __cdecl NewtonCreateTreeCollision(const PNewtonWorld NewtonWorld, int shapeID);
extern "C" PNewtonCollision __cdecl NewtonCreateTreeCollisionFromMesh(const PNewtonWorld NewtonWorld, const PNewtonMesh Mesh, int shapeID);
extern "C" void __cdecl NewtonTreeCollisionSetUserRayCastCallback(const PNewtonCollision TreeCollision, PNewtonCollisionTreeRayCastCallback rayHitCallback);
extern "C" void __cdecl NewtonTreeCollisionBeginBuild(const PNewtonCollision TreeCollision);
extern "C" void __cdecl NewtonTreeCollisionAddFace(const PNewtonCollision TreeCollision, int vertexCount, const PdFloat vertexPtr, int strideInBytes, int faceAttribute);
extern "C" void __cdecl NewtonTreeCollisionEndBuild(const PNewtonCollision TreeCollision, int optimize);
extern "C" int __cdecl NewtonTreeCollisionGetFaceAtribute(const PNewtonCollision TreeCollision, const System::PInteger faceIndexArray);
extern "C" void __cdecl NewtonTreeCollisionSetFaceAtribute(const PNewtonCollision TreeCollision, const System::PInteger faceIndexArray, int attribute);
extern "C" int __cdecl NewtonTreeCollisionGetVertexListIndexListInAABB(const PNewtonCollision TreeCollision, const PdFloat p0, const PdFloat p1, const PdFloat vertexArray, System::PInteger vertexCount, System::PInteger vertexStrideInBytes, const System::PInteger indexList, int maxIndexCount, const System::PInteger faceAttribute);
extern "C" void __cdecl NewtonStaticCollisionSetDebugCallback(const PNewtonCollision staticCollision, PNewtonTreeCollisionCallback userCallback);
extern "C" int __cdecl NewtonCollisionPointDistance(const PNewtonWorld NewtonWorld, const PdFloat point, const PNewtonCollision collision, const PdFloat matrix, PdFloat contact, PdFloat normal, int threadIndex);
extern "C" int __cdecl NewtonCollisionClosestPoint(const PNewtonWorld NewtonWorld, const PNewtonCollision collsionA, const PdFloat matrixA, const PNewtonCollision collisionB, const PdFloat matrixB, PdFloat contactA, PdFloat contactB, PdFloat normalAB, int threadIndex);
extern "C" int __cdecl NewtonCollisionCollide(const PNewtonWorld NewtonWorld, int maxSize, const PNewtonCollision collsionA, const PdFloat matrixA, const PNewtonCollision collisionB, const PdFloat matrixB, PdFloat contacts, PdFloat normals, PdFloat penetration, int threadIndex);
extern "C" int __cdecl NewtonCollisionCollideContinue(const PNewtonWorld NewtonWorld, int maxSize, const dFloat timestep, const PNewtonCollision collsionA, const PdFloat matrixA, const PdFloat velocA, const dFloat omegaA, const PNewtonCollision collsionB, const PdFloat matrixB, const PdFloat velocB, const dFloat omegaB, PdFloat timeOfImpact, PdFloat contacts, PdFloat normals, PdFloat penetration, int threadIndex);
extern "C" void __cdecl NewtonCollisionSupportVertex(const PNewtonCollision collision, const PdFloat dir, PdFloat vertex);
extern "C" dFloat __cdecl NewtonCollisionRayCast(const PNewtonCollision collision, const PdFloat p0, const PdFloat p1, PdFloat normals, System::PInteger attribute);
extern "C" void __cdecl NewtonCollisionCalculateAABB(const PNewtonCollision collision, const PdFloat matrix, PdFloat p0, PdFloat p1);
extern "C" void __cdecl NewtonCollisionForEachPolygonDo(const PNewtonCollision collision, const PdFloat matrix, NewtonCollisionIterator callback, void * userData);
extern "C" void __cdecl NewtonSetEulerAngle(const PdFloat eulersAngles, PdFloat matrix);
extern "C" void __cdecl NewtonGetEulerAngle(const PdFloat matrix, PdFloat eulersAngles);
extern "C" dFloat __cdecl NewtonCalculateSpringDamperAcceleration(dFloat dt, dFloat ks, dFloat x, dFloat kd, dFloat s);
extern "C" PNewtonBody __cdecl NewtonCreateBody(const PNewtonWorld NewtonWorld, const PNewtonCollision collision, const PdFloat matrix);
extern "C" void __cdecl NewtonDestroyBody(const PNewtonWorld NewtonWorld, const PNewtonBody Body);
extern "C" void __cdecl NewtonBodyAddForce(const PNewtonBody Body, const PdFloat Force);
extern "C" void __cdecl NewtonBodyAddTorque(const PNewtonBody Body, const PdFloat torque);
extern "C" void __cdecl NewtonBodyCalculateInverseDynamicsForce(const PNewtonBody Body, dFloat timestep, const PdFloat desiredVeloc, PdFloat forceOut);
extern "C" void __cdecl NewtonBodySetMatrix(const PNewtonBody Body, const PdFloat matrix);
extern "C" void __cdecl NewtonBodySetMatrixRecursive(const PNewtonBody Body, const PdFloat matrix);
extern "C" void __cdecl NewtonBodySetMassMatrix(const PNewtonBody Body, dFloat mass, dFloat Ixx, dFloat Iyy, dFloat Izz);
extern "C" void __cdecl NewtonBodySetMaterialGroupID(const PNewtonBody Body, int id);
extern "C" void __cdecl NewtonBodySetContinuousCollisionMode(const PNewtonBody Body, int state);
extern "C" void __cdecl NewtonBodySetJointRecursiveCollision(const PNewtonBody Body, unsigned_int state);
extern "C" void __cdecl NewtonBodySetOmega(const PNewtonBody Body, const PdFloat omega);
extern "C" void __cdecl NewtonBodySetVelocity(const PNewtonBody Body, const PdFloat velocity);
extern "C" void __cdecl NewtonBodySetForce(const PNewtonBody Body, const PdFloat Force);
extern "C" void __cdecl NewtonBodySetTorque(const PNewtonBody Body, const PdFloat torque);
extern "C" void __cdecl NewtonBodySetCentreOfMass(const PNewtonBody Body, const PdFloat com);
extern "C" void __cdecl NewtonBodySetLinearDamping(const PNewtonBody Body, dFloat linearDamp);
extern "C" void __cdecl NewtonBodySetAngularDamping(const PNewtonBody Body, const PdFloat angularDamp);
extern "C" void __cdecl NewtonBodySetUserData(const PNewtonBody Body, void * userData);
extern "C" void __cdecl NewtonBodySetCollision(const PNewtonBody Body, const PNewtonCollision collision);
extern "C" int __cdecl NewtonBodyGetSleepState(const PNewtonBody Body);
extern "C" int __cdecl NewtonBodyGetAutoSleep(const PNewtonBody Body);
extern "C" void __cdecl NewtonBodySetAutoSleep(const PNewtonBody Body, int state);
extern "C" int __cdecl NewtonBodyGetFreezeState(const PNewtonBody Body);
extern "C" void __cdecl NewtonBodySetFreezeState(const PNewtonBody Body, int state);
extern "C" void __cdecl NewtonBodySetDestructorCallback(const PNewtonBody Body, NewtonBodyDestructor callback);
extern "C" void __cdecl NewtonBodySetTransformCallback(const PNewtonBody Body, NewtonSetTransform callback);
extern "C" NewtonSetTransform __cdecl NewtonBodyGetTransformCallback(const PNewtonBody Body);
extern "C" void __cdecl NewtonBodySetForceAndTorqueCallback(const PNewtonBody Body, NewtonApplyForceAndTorque callback);
extern "C" NewtonApplyForceAndTorque __cdecl NewtonBodyGetForceAndTorqueCallback(const PNewtonBody Body);
extern "C" void * __cdecl NewtonBodyGetUserData(const PNewtonBody Body);
extern "C" PNewtonWorld __cdecl NewtonBodyGetWorld(const PNewtonBody Body);
extern "C" PNewtonCollision __cdecl NewtonBodyGetCollision(const PNewtonBody Body);
extern "C" int __cdecl NewtonBodyGetMaterialGroupID(const PNewtonBody Body);
extern "C" int __cdecl NewtonBodyGetContinuousCollisionMode(const PNewtonBody Body);
extern "C" int __cdecl NewtonBodyGetJointRecursiveCollision(const PNewtonBody Body);
extern "C" void __cdecl NewtonBodyGetMatrix(const PNewtonBody Body, PdFloat matrix);
extern "C" void __cdecl NewtonBodyGetRotation(const PNewtonBody Body, PdFloat rotation);
extern "C" void __cdecl NewtonBodyGetMassMatrix(const PNewtonBody Body, PdFloat mass, PdFloat Ixx, PdFloat Iyy, PdFloat Izz);
extern "C" void __cdecl NewtonBodyGetInvMass(const PNewtonBody Body, PdFloat invMass, PdFloat invIxx, PdFloat invIyy, PdFloat invIzz);
extern "C" void __cdecl NewtonBodyGetOmega(const PNewtonBody Body, PdFloat vector);
extern "C" void __cdecl NewtonBodyGetVelocity(const PNewtonBody Body, PdFloat vector);
extern "C" void __cdecl NewtonBodyGetForce(const PNewtonBody Body, PdFloat vector);
extern "C" void __cdecl NewtonBodyGetTorque(const PNewtonBody Body, PdFloat vector);
extern "C" void __cdecl NewtonBodyGetForceAcc(const PNewtonBody Body, PdFloat vector);
extern "C" void __cdecl NewtonBodyGetTorqueAcc(const PNewtonBody Body, PdFloat vector);
extern "C" void __cdecl NewtonBodyGetCentreOfMass(const PNewtonBody Body, PdFloat com);
extern "C" dFloat __cdecl NewtonBodyGetLinearDamping(const PNewtonBody Body);
extern "C" void __cdecl NewtonBodyGetAngularDamping(const PNewtonBody Body, PdFloat vector);
extern "C" void __cdecl NewtonBodyGetAABB(const PNewtonBody Body, PdFloat p0, PdFloat p1);
extern "C" void __cdecl NewtonBodyGetFreezeTreshold(const PNewtonBody Body, PdFloat freezeSpeed2, PdFloat freezeOmega2);
extern "C" PNewtonJoint __cdecl NewtonBodyGetFirstJoint(const PNewtonBody Body);
extern "C" PNewtonJoint __cdecl NewtonBodyGetNextJoint(const PNewtonBody Body, const PNewtonJoint joint);
extern "C" PNewtonJoint __cdecl NewtonBodyGetFirstContactJoint(const PNewtonBody Body);
extern "C" PNewtonJoint __cdecl NewtonBodyGetNextContactJoint(const PNewtonBody Body, const PNewtonJoint contactJoint);
extern "C" void * __cdecl NewtonContactJointGetFirstContact(const PNewtonJoint contactJoint);
extern "C" void * __cdecl NewtonContactJointGetNextContact(const PNewtonJoint contactJoint, void * contact);
extern "C" int __cdecl NewtonContactJointGetContactCount(const PNewtonJoint contactJoint);
extern "C" void __cdecl NewtonContactJointRemoveContact(const PNewtonJoint contactJoint, void * contact);
extern "C" PNewtonMaterial __cdecl NewtonContactGetMaterial(const void * contact);
extern "C" void __cdecl NewtonBodyAddBuoyancyForce(const PNewtonBody Body, dFloat fluidDensity, dFloat fluidLinearViscosity, dFloat fluidAngularViscosity, const PdFloat gravityVector, NewtonGetBuoyancyPlane buoyancyPlane, void * context);
extern "C" void __cdecl NewtonBodyAddImpulse(const PNewtonBody Body, const PdFloat pointDeltaVeloc, const PdFloat pointPosit);
extern "C" void __cdecl NewtonBodyApplyImpulseArray(const PNewtonBody Body, int ImpuleCount, int StrideInByte, const PdFloat impulseArray, const PdFloat pointArray);
extern "C" void * __cdecl NewtonJointGetUserData(const PNewtonJoint joint);
extern "C" void __cdecl NewtonJointSetUserData(const PNewtonJoint joint, void * userData);
extern "C" PNewtonBody __cdecl NewtonJointGetBody0(const PNewtonJoint joint);
extern "C" PNewtonBody __cdecl NewtonJointGetBody1(const PNewtonJoint joint);
extern "C" void __cdecl NewtonJointGetInfo(const PNewtonJoint joint, PNewtonJointRecord info);
extern "C" int __cdecl NewtonJointGetCollisionState(const PNewtonJoint joint);
extern "C" void __cdecl NewtonJointSetCollisionState(const PNewtonJoint joint, int state);
extern "C" dFloat __cdecl NewtonJointGetStiffness(const PNewtonJoint joint);
extern "C" void __cdecl NewtonJointSetStiffness(const PNewtonJoint joint, dFloat state);
extern "C" void __cdecl NewtonDestroyJoint(const PNewtonWorld NewtonWorld, const PNewtonJoint joint);
extern "C" void __cdecl NewtonJointSetDestructor(const PNewtonJoint joint, NewtonConstraintDestructor _destructor);
extern "C" PNewtonJoint __cdecl NewtonConstraintCreateBall(const PNewtonWorld NewtonWorld, const PdFloat pivotPoint, const PNewtonBody childBody, const PNewtonBody parentBody);
extern "C" void __cdecl NewtonBallSetUserCallback(const PNewtonJoint ball, NewtonBallCallBack callback);
extern "C" void __cdecl NewtonBallGetJointAngle(const PNewtonJoint ball, PdFloat angle);
extern "C" void __cdecl NewtonBallGetJointOmega(const PNewtonJoint ball, PdFloat omega);
extern "C" void __cdecl NewtonBallGetJointForce(const PNewtonJoint ball, PdFloat Force);
extern "C" void __cdecl NewtonBallSetConeLimits(const PNewtonJoint ball, const PdFloat pin, dFloat maxConeAngle, dFloat maxTwistAngle);
extern "C" PNewtonJoint __cdecl NewtonConstraintCreateHinge(const PNewtonWorld NewtonWorld, const PdFloat pivotPoint, const PdFloat pinDir, const PNewtonBody childBody, const PNewtonBody parentBody);
extern "C" void __cdecl NewtonHingeSetUserCallback(const PNewtonJoint hinge, NewtonHingeCallBack callback);
extern "C" dFloat __cdecl NewtonHingeGetJointAngle(const PNewtonJoint hinge);
extern "C" dFloat __cdecl NewtonHingeGetJointOmega(const PNewtonJoint hinge);
extern "C" void __cdecl NewtonHingeGetJointForce(const PNewtonJoint hinge, PdFloat Force);
extern "C" dFloat __cdecl NewtonHingeCalculateStopAlpha(const PNewtonJoint hinge, const PNewtonHingeSliderUpdateDesc desc, dFloat angle);
extern "C" PNewtonJoint __cdecl NewtonConstraintCreateSlider(const PNewtonWorld NewtonWorld, const PdFloat pivotPoint, const PdFloat pinDir, const PNewtonBody childBody, const PNewtonBody parentBody);
extern "C" void __cdecl NewtonSliderSetUserCallback(const PNewtonJoint slider, NewtonSliderCallBack callback);
extern "C" dFloat __cdecl NewtonSliderGetJointPosit(const PNewtonJoint slider);
extern "C" dFloat __cdecl NewtonSliderGetJointVeloc(const PNewtonJoint slider);
extern "C" void __cdecl NewtonSliderGetJointForce(const PNewtonJoint slider, PdFloat Force);
extern "C" dFloat __cdecl NewtonSliderCalculateStopAccel(const PNewtonJoint slider, const PNewtonHingeSliderUpdateDesc desc, dFloat position);
extern "C" PNewtonJoint __cdecl NewtonConstraintCreateCorkscrew(const PNewtonWorld NewtonWorld, const PdFloat pivotPoint, const PdFloat pinDir, const PNewtonBody childBody, const PNewtonBody parentBody);
extern "C" void __cdecl NewtonCorkscrewSetUserCallback(const PNewtonJoint corkscrew, NewtonCorkscrewCallBack callback);
extern "C" dFloat __cdecl NewtonCorkscrewGetJointPosit(const PNewtonJoint corkscrew);
extern "C" dFloat __cdecl NewtonCorkscrewGetJointAngle(const PNewtonJoint corkscrew);
extern "C" dFloat __cdecl NewtonCorkscrewGetJointVeloc(const PNewtonJoint corkscrew);
extern "C" dFloat __cdecl NewtonCorkscrewGetJointOmega(const PNewtonJoint corkscrew);
extern "C" void __cdecl NewtonCorkscrewGetJointForce(const PNewtonJoint corkscrew, PdFloat Force);
extern "C" dFloat __cdecl NewtonCorkscrewCalculateStopAlpha(const PNewtonJoint corkscrew, const PNewtonHingeSliderUpdateDesc desc, dFloat angle);
extern "C" dFloat __cdecl NewtonCorkscrewCalculateStopAccel(const PNewtonJoint corkscrew, const PNewtonHingeSliderUpdateDesc desc, dFloat position);
extern "C" PNewtonJoint __cdecl NewtonConstraintCreateUniversal(const PNewtonWorld NewtonWorld, const PdFloat pivotPoint, const PdFloat pinDir0, const PdFloat pinDir1, const PNewtonBody childBody, const PNewtonBody parentBody);
extern "C" void __cdecl NewtonUniversalSetUserCallback(const PNewtonJoint universal, NewtonUniversalCallBack callback);
extern "C" dFloat __cdecl NewtonUniversalGetJointAngle0(const PNewtonJoint universal);
extern "C" dFloat __cdecl NewtonUniversalGetJointAngle1(const PNewtonJoint universal);
extern "C" dFloat __cdecl NewtonUniversalGetJointOmega0(const PNewtonJoint universal);
extern "C" dFloat __cdecl NewtonUniversalGetJointOmega1(const PNewtonJoint universal);
extern "C" void __cdecl NewtonUniversalGetJointForce(const PNewtonJoint universal, PdFloat Force);
extern "C" dFloat __cdecl NewtonUniversalCalculateStopAlpha0(const PNewtonJoint universal, const PNewtonHingeSliderUpdateDesc desc, dFloat angle);
extern "C" dFloat __cdecl NewtonUniversalCalculateStopAlpha1(const PNewtonJoint universal, const PNewtonHingeSliderUpdateDesc desc, dFloat angle);
extern "C" PNewtonJoint __cdecl NewtonConstraintCreateUpVector(const PNewtonWorld NewtonWorld, const PdFloat pinDir, const PNewtonBody Body);
extern "C" void __cdecl NewtonUpVectorGetPin(const PNewtonJoint upVector, PdFloat pin);
extern "C" void __cdecl NewtonUpVectorSetPin(const PNewtonJoint upVector, const PdFloat pin);
extern "C" PNewtonJoint __cdecl NewtonConstraintCreateUserJoint(const PNewtonWorld NewtonWorld, int MaxDOF, PNewtonUserBilateralCallBack callback, PNewtonUserBilateralGetInfoCallBack GetInfo, const PNewtonBody childBody, const PNewtonBody parentBody);
extern "C" void __cdecl NewtonUserJointSetFeedbackCollectorCallback(const PNewtonJoint joint, PNewtonUserBilateralCallBack GetFeedback);
extern "C" void __cdecl NewtonUserJointAddLinearRow(const PNewtonJoint joint, const PdFloat pivot0, const PdFloat pivot1, const PdFloat dir);
extern "C" void __cdecl NewtonUserJointAddAngularRow(const PNewtonJoint joint, dFloat RelativeAngle, const PdFloat dir);
extern "C" void __cdecl NewtonUserJointAddGeneralRow(const PNewtonJoint joint, const PdFloat Jacobian0, const PdFloat Jacobian1);
extern "C" void __cdecl NewtonUserJointSetRowMinimumFriction(const PNewtonJoint joint, dFloat Friction);
extern "C" void __cdecl NewtonUserJointSetRowMaximumFriction(const PNewtonJoint joint, dFloat Friction);
extern "C" void __cdecl NewtonUserJointSetRowAcceleration(const PNewtonJoint joint, dFloat Acceleration);
extern "C" void __cdecl NewtonUserJointSetRowSpringDamperAcceleration(const PNewtonJoint joint, dFloat springK, dFloat springD);
extern "C" void __cdecl NewtonUserJointSetRowStiffness(const PNewtonJoint joint, dFloat Stiffness);
extern "C" dFloat __cdecl NewtonUserJointGetRowForce(const PNewtonJoint joint, int Row);
extern "C" PNewtonMesh __cdecl NewtonMeshCreate(const PNewtonWorld World);
extern "C" PNewtonMesh __cdecl NewtonMeshCreateFromMesh(const PNewtonMesh Mesh);
extern "C" PNewtonMesh __cdecl NewtonMeshCreateFromCollision(const PNewtonCollision collision);
extern "C" PNewtonMesh __cdecl NewtonMeshConvexHull(const PNewtonWorld NewtonWorld, int count, const PdFloat vertexCloud, int strideInBytes, dFloat tolerance);
extern "C" PNewtonMesh __cdecl NewtonMeshCreatePlane(const PNewtonWorld World, const PdFloat locationMatrix, dFloat width, dFloat breadth, int material, const PdFloat textureMatrix0, const void *textureMatrix1);
extern "C" void __cdecl NewtonMeshDestroy(const PNewtonMesh Mesh);
extern "C" void __cdecl NewtonMeshCalculateOOBB(const PNewtonMesh Mesh, const PdFloat matrix, PdFloat x, PdFloat y, PdFloat z);
extern "C" void __cdecl NewtonMesApplyTransform(const PNewtonMesh Mesh, const PdFloat matrix);
extern "C" void __cdecl NewtonMeshCalculateVertexNormals(const PNewtonMesh Mesh, dFloat angleInRadians);
extern "C" void __cdecl NewtonMeshApplySphericalMapping(const PNewtonMesh Mesh, int material);
extern "C" void __cdecl NewtonMeshApplyBoxMapping(const PNewtonMesh Mesh, int front, int side, int top);
extern "C" void __cdecl NewtonMeshApplyCylindricalMapping(const PNewtonMesh Mesh, int cylinderMaterial, int capMaterial);
extern "C" int __cdecl NewtonMeshIsOpenMesh(const PNewtonMesh Mesh);
extern "C" void __cdecl NewtonMeshFixTJoints(const PNewtonMesh Mesh);
extern "C" void __cdecl NewtonMeshPolygonize(const PNewtonMesh Mesh);
extern "C" void __cdecl NewtonMeshTriangulate(const PNewtonMesh Mesh);
extern "C" PNewtonMesh __cdecl NewtonMeshUnion(const PNewtonMesh Mesh, PNewtonMesh clipper, PdFloat clipperMatrix);
extern "C" PNewtonMesh __cdecl NewtonMeshDifference(const PNewtonMesh Mesh, PNewtonMesh clipper, PdFloat clipperMatrix);
extern "C" PNewtonMesh __cdecl NewtonMeshIntersection(const PNewtonMesh Mesh, PNewtonMesh clipper, PdFloat clipperMatrix);
extern "C" void __cdecl NewtonMeshClip(const PNewtonMesh Mesh, const PNewtonMesh clipper, const PdFloat clipperMatrix, const PNewtonMesh topMesh, const PNewtonMesh bottomMesh);
extern "C" void __cdecl NewtonMeshPlaneClip(const PNewtonMesh Mesh, const PdFloat planeMatrix, const PdFloat PlaneTextureMatrix, int PlaneMaterial, const PNewtonMesh topMesh, const PNewtonMesh bottomMesh);
extern "C" PNewtonMesh __cdecl NewtonMeshConvexDecomposition(const PNewtonMesh Mesh, int maxCount);
extern "C" PNewtonMesh __cdecl NewtonMeshVoronoiDecomposition(const PNewtonMesh Mesh, int PointCount, int PointStrideInBytes, const PdFloat PointCloud, int InternalMaterial, const PdFloat TextureMatrix);
extern "C" void __cdecl NewtonRemoveUnusedVertices(const PNewtonMesh Mesh, System::PInteger vertexRemapTable);
extern "C" void __cdecl NewtonMeshBeginFace(const PNewtonMesh Mesh);
extern "C" void __cdecl NewtonMeshAddFace(const PNewtonMesh Mesh, int vertexCount, const PdFloat vertex, int strideInBytes, int materialIndex);
extern "C" void __cdecl NewtonMeshEndFace(const PNewtonMesh Mesh);
extern "C" void __cdecl NewtonMeshBuildFromVertexListIndexList(const PNewtonMesh Mesh, int FaceCount, const System::PInteger faceIndexCount, const System::PInteger faceMaterialIndex, const PdFloat vertex, int vertexStrideInBytes, const System::PInteger vertexIndex, const PdFloat normal, int normalStrideInBytes, const System::PInteger normalIndex, const PdFloat uv0, int uv0StrideInBytes, const System::PInteger uv0Index, const PdFloat uv1, int uv1StrideInBytes, const System::PInteger uv1Index);
extern "C" void __cdecl NewtonMeshGetVertexStreams(const PNewtonMesh Mesh, int vertexStrideInByte, PdFloat vertex, int normalStrideInByte, PdFloat normal, int uvStrideInByte0, PdFloat uv0, int uvStrideInByte1, PdFloat uv1);
extern "C" void __cdecl NewtonMeshGetIndirectVertexStreams(const PNewtonMesh Mesh, int vertexStrideInByte, PdFloat vertex, System::PInteger vertexIndices, System::PInteger vertexCount, int normalStrideInByte, PdFloat normal, System::PInteger normalIndices, System::PInteger normalCount, int uvStrideInByte0, PdFloat uv0, System::PInteger uvIndices0, System::PInteger uvCount0, int uvStrideInByte1, PdFloat uv1, System::PInteger uvIndices1, System::PInteger uvCount1);
extern "C" void * __cdecl NewtonMeshBeginHandle(const PNewtonMesh Mesh);
extern "C" void __cdecl NewtonMeshEndHandle(const PNewtonMesh Mesh, void * Handle);
extern "C" int __cdecl NewtonMeshFirstMaterial(const PNewtonMesh Mesh, void * Handle);
extern "C" int __cdecl NewtonMeshNextMaterial(const PNewtonMesh Mesh, void * Handle, int materialID);
extern "C" int __cdecl NewtonMeshMaterialGetMaterial(const PNewtonMesh Mesh, void * Handle, int materialID);
extern "C" int __cdecl NewtonMeshMaterialGetIndexCount(const PNewtonMesh Mesh, void * Handle, int materialID);
extern "C" void __cdecl NewtonMeshMaterialGetIndexStream(const PNewtonMesh Mesh, void * Handle, int materialID, System::PInteger index);
extern "C" void __cdecl NewtonMeshMaterialGetIndexStreamShort(const PNewtonMesh Mesh, void * Handle, int materialID, PShort index);
extern "C" PNewtonMesh __cdecl NewtonMeshCreateFirstSingleSegment(const PNewtonMesh Mesh);
extern "C" PNewtonMesh __cdecl NewtonMeshCreateNextSingleSegment(const PNewtonMesh Mesh, PNewtonMesh Segment);
extern "C" PNewtonMesh __cdecl NewtonMeshCreateFirstLayer(const PNewtonMesh Mesh);
extern "C" PNewtonMesh __cdecl NewtonMeshCreateNextLayer(const PNewtonMesh Mesh, const PNewtonMesh Segment);
extern "C" int __cdecl NewtonMeshGetTotalFaceCount(const PNewtonMesh Mesh);
extern "C" int __cdecl NewtonMeshGetTotalIndexCount(const PNewtonMesh Mesh);
extern "C" void __cdecl NewtonMeshGetFaces(const PNewtonMesh Mesh, const System::PInteger faceIndexCount, System::PInteger faceMaterial, System::PInteger faceIndices);
extern "C" int __cdecl NewtonMeshGetPointCount(const PNewtonMesh Mesh);
extern "C" int __cdecl NewtonMeshGetPointStrideInByte(const PNewtonMesh Mesh);
extern "C" PdFloat __cdecl NewtonMeshGetPointArray(const PNewtonMesh Mesh);
extern "C" PdFloat __cdecl NewtonMeshGetNormalArray(const PNewtonMesh Mesh);
extern "C" PdFloat __cdecl NewtonMeshGetUV0Array(const PNewtonMesh Mesh);
extern "C" PdFloat __cdecl NewtonMeshGetUV1Array(const PNewtonMesh Mesh);
extern "C" int __cdecl NewtonMeshGetVertexCount(const PNewtonMesh Mesh);
extern "C" int __cdecl NewtonMeshGetVertexStrideInByte(const PNewtonMesh Mesh);
extern "C" PdFloat __cdecl NewtonMeshGetVertexArray(const PNewtonMesh Mesh);
extern "C" void * __cdecl NewtonMeshGetFirstVertex(const PNewtonMesh Mesh);
extern "C" void * __cdecl NewtonMeshGetNextVertex(const PNewtonMesh Mesh, const void * vertex);
extern "C" int __cdecl NewtonMeshGetVertexIndex(const PNewtonMesh Mesh, const void * vertex);
extern "C" void * __cdecl NewtonMeshGetFirstPoint(const PNewtonMesh Mesh);
extern "C" void * __cdecl NewtonMeshGetNextPoint(const PNewtonMesh Mesh, const void * point);
extern "C" int __cdecl NewtonMeshGetPointIndex(const PNewtonMesh Mesh, const void * point);
extern "C" int __cdecl NewtonMeshGetVertexIndexFromPoint(const PNewtonMesh Mesh, const void * point);
extern "C" void * __cdecl NewtonMeshGetFirstEdge(const PNewtonMesh Mesh);
extern "C" void * __cdecl NewtonMeshGetNextEdge(const PNewtonMesh Mesh, const void * Edge);
extern "C" void __cdecl NewtonMeshGetEdgeIndices(const PNewtonMesh Mesh, const void * Edge, System::PInteger v0, System::PInteger v1);
extern "C" void * __cdecl NewtonMeshGetFirstFace(const PNewtonMesh Mesh);
extern "C" void * __cdecl NewtonMeshGetNextFace(const PNewtonMesh Mesh, const void * face);
extern "C" int __cdecl NewtonMeshIsFaceOpen(const PNewtonMesh Mesh, const void * face);
extern "C" int __cdecl NewtonMeshGetFaceMaterial(const PNewtonMesh Mesh, const void * face);
extern "C" int __cdecl NewtonMeshGetFaceIndexCount(const PNewtonMesh Mesh, const void * face);
extern "C" void __cdecl NewtonMeshGetFaceIndices(const PNewtonMesh Mesh, const void * face, System::PInteger Indices);
extern "C" void __cdecl NewtonMeshGetFacePointIndices(const PNewtonMesh Mesh, const void * face, System::PInteger Indices);
}	/* namespace Import */
}	/* namespace Ngd */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_NGD_IMPORT)
using namespace Ngd::Import;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_NGD)
using namespace Ngd;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NGD_ImportHPP

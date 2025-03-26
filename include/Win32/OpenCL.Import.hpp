// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OpenCL.Import.pas' rev: 36.00 (Windows)

#ifndef OpenCL_ImportHPP
#define OpenCL_ImportHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <OpenCL.Platform.hpp>

//-- user supplied -----------------------------------------------------------

namespace Opencl
{
namespace Import
{
//-- forward type declarations -----------------------------------------------
struct DECLSPEC_DRECORD T_cl_platform_id
{
};


struct DECLSPEC_DRECORD T_cl_device_id
{
};


struct DECLSPEC_DRECORD T_cl_context
{
};


struct DECLSPEC_DRECORD T_cl_command_queue
{
};


struct DECLSPEC_DRECORD T_cl_mem
{
};


struct DECLSPEC_DRECORD T_cl_program
{
};


struct DECLSPEC_DRECORD T_cl_kernel
{
};


struct DECLSPEC_DRECORD T_cl_event
{
};


struct DECLSPEC_DRECORD T_cl_sampler
{
};


struct Tcl_image_format;
struct Tcl_image_desc;
struct Tcl_buffer_region;
//-- type declarations -------------------------------------------------------
typedef T_cl_platform_id *Tcl_platform_id;

typedef Tcl_platform_id *Pcl_platform_id;

typedef T_cl_device_id *Tcl_device_id;

typedef Tcl_device_id *Pcl_device_id;

typedef T_cl_context *Tcl_context;

typedef Tcl_context *Pcl_context;

typedef T_cl_command_queue *Tcl_command_queue;

typedef Tcl_command_queue *Pcl_command_queue;

typedef T_cl_mem *Tcl_mem;

typedef Tcl_mem *Pcl_mem;

typedef T_cl_program *Tcl_program;

typedef Tcl_program *Pcl_program;

typedef T_cl_kernel *Tcl_kernel;

typedef Tcl_kernel *Pcl_kernel;

typedef T_cl_event *Tcl_event;

typedef Tcl_event *Pcl_event;

typedef T_cl_sampler *Tcl_sampler;

typedef Tcl_sampler *Pcl_sampler;

typedef Opencl::Platform::Tcl_uint Tcl_bool;

typedef unsigned *Pcl_bool;

typedef Opencl::Platform::Tcl_ulong Tcl_bitfield;

typedef unsigned __int64 *Pcl_bitfield;

typedef Tcl_bitfield Tcl_device_type;

typedef unsigned __int64 *Pcl_device_type;

typedef Opencl::Platform::Tcl_uint Tcl_platform_info;

typedef unsigned *Pcl_platform_info;

typedef Opencl::Platform::Tcl_uint Tcl_device_info;

typedef unsigned *Pcl_device_info;

typedef Tcl_bitfield Tcl_device_fp_config;

typedef unsigned __int64 *Pcl_device_fp_config;

typedef Opencl::Platform::Tcl_uint Tcl_device_mem_cache_type;

typedef unsigned *Pcl_device_mem_cache_type;

typedef Opencl::Platform::Tcl_uint Tcl_device_local_mem_type;

typedef unsigned *Pcl_device_local_mem_type;

typedef Tcl_bitfield Tcl_device_exec_capabilities;

typedef unsigned __int64 *Pcl_device_exec_capabilities;

typedef Tcl_bitfield Tcl_device_svm_capabilities;

typedef unsigned __int64 *Pcl_device_svm_capabilities;

typedef Tcl_bitfield Tcl_command_queue_properties;

typedef unsigned __int64 *Pcl_command_queue_properties;

typedef Opencl::Platform::intptr_t Tcl_device_partition_property;

typedef unsigned *Pcl_device_partition_property;

typedef Tcl_bitfield Tcl_device_affinity_domain;

typedef unsigned __int64 *Pcl_device_affinity_domain;

typedef Opencl::Platform::intptr_t Tcl_context_properties;

typedef unsigned *Pcl_context_properties;

typedef Opencl::Platform::Tcl_uint Tcl_context_info;

typedef unsigned *Pcl_context_info;

typedef Tcl_bitfield Tcl_queue_properties;

typedef unsigned __int64 *Pcl_queue_properties;

typedef Opencl::Platform::Tcl_uint Tcl_command_queue_info;

typedef unsigned *Pcl_command_queue_info;

typedef Opencl::Platform::Tcl_uint Tcl_channel_order;

typedef unsigned *Pcl_channel_order;

typedef Opencl::Platform::Tcl_uint Tcl_channel_type;

typedef unsigned *Pcl_channel_type;

typedef Tcl_bitfield Tcl_mem_flags;

typedef unsigned __int64 *Pcl_mem_flags;

typedef Tcl_bitfield Tcl_svm_mem_flags;

typedef unsigned __int64 *Pcl_svm_mem_flags;

typedef Opencl::Platform::Tcl_uint Tcl_mem_object_type;

typedef unsigned *Pcl_mem_object_type;

typedef Opencl::Platform::Tcl_uint Tcl_mem_info;

typedef unsigned *Pcl_mem_info;

typedef Tcl_bitfield Tcl_mem_migration_flag;

typedef unsigned __int64 *Pcl_mem_migration_flag;

typedef Opencl::Platform::Tcl_uint Tcl_image_info;

typedef unsigned *Pcl_image_info;

typedef Opencl::Platform::Tcl_uint Tcl_buffer_create_type;

typedef unsigned *Pcl_buffer_create_type;

typedef Opencl::Platform::Tcl_uint Tcl_addressing_mode;

typedef unsigned *Pcl_addressing_mode;

typedef Opencl::Platform::Tcl_uint Tcl_filter_mode;

typedef unsigned *Pcl_filter_mode;

typedef Opencl::Platform::Tcl_uint Tcl_sampler_info;

typedef unsigned *Pcl_sampler_info;

typedef Tcl_bitfield Tcl_map_flags;

typedef unsigned __int64 *Pcl_map_flags;

typedef Opencl::Platform::intptr_t Tcl_pipe_properties;

typedef unsigned *Pcl_pipe_properties;

typedef Opencl::Platform::Tcl_uint Tcl_pipe_info;

typedef unsigned *Pcl_pipe_info;

typedef Opencl::Platform::Tcl_uint Tcl_program_info;

typedef unsigned *Pcl_program_info;

typedef Opencl::Platform::Tcl_uint Tcl_program_build_info;

typedef unsigned *Pcl_program_build_info;

typedef Opencl::Platform::Tcl_uint Tcl_program_binary_type;

typedef unsigned *Pcl_program_binary_type;

typedef Opencl::Platform::Tcl_int Tcl_build_status;

typedef int *Pcl_build_status;

typedef Opencl::Platform::Tcl_uint Tcl_kernel_info;

typedef unsigned *Pcl_kernel_info;

typedef Opencl::Platform::Tcl_uint Tcl_kernel_arg_info;

typedef unsigned *Pcl_kernel_arg_info;

typedef Opencl::Platform::Tcl_uint Tcl_kernel_arg_address_qualifier;

typedef unsigned *Pcl_kernel_arg_address_qualifier;

typedef Opencl::Platform::Tcl_uint Tcl_kernel_arg_access_qualifier;

typedef unsigned *Pcl_kernel_arg_access_qualifier;

typedef Tcl_bitfield Tcl_kernel_arg_type_qualifier;

typedef unsigned __int64 *Pcl_kernel_arg_type_qualifier;

typedef Opencl::Platform::Tcl_uint Tcl_kernel_work_group_info;

typedef unsigned *Pcl_kernel_work_group_info;

typedef Opencl::Platform::Tcl_uint Tcl_kernel_sub_group_info;

typedef unsigned *Pcl_kernel_sub_group_info;

typedef Opencl::Platform::Tcl_uint Tcl_event_info;

typedef unsigned *Pcl_event_info;

typedef Opencl::Platform::Tcl_uint Tcl_command_type;

typedef unsigned *Pcl_command_type;

typedef Opencl::Platform::Tcl_uint Tcl_profiling_info;

typedef unsigned *Pcl_profiling_info;

typedef Tcl_bitfield Tcl_sampler_properties;

typedef unsigned __int64 *Pcl_sampler_properties;

typedef Opencl::Platform::Tcl_uint Tcl_kernel_exec_info;

typedef unsigned *Pcl_kernel_exec_info;

#pragma pack(push,1)
struct DECLSPEC_DRECORD Tcl_image_format
{
public:
	Tcl_channel_order image_channel_order;
	Tcl_channel_type image_channel_data_type;
};
#pragma pack(pop)


typedef Tcl_image_format *Pcl_image_format;

#pragma pack(push,1)
struct DECLSPEC_DRECORD Tcl_image_desc
{
public:
	Tcl_mem_object_type image_type;
	System::NativeUInt image_width;
	System::NativeUInt image_height;
	System::NativeUInt image_depth;
	System::NativeUInt image_array_size;
	System::NativeUInt image_row_pitch;
	System::NativeUInt image_slice_pitch;
	Opencl::Platform::Tcl_uint num_mip_levels;
	Opencl::Platform::Tcl_uint num_samples;
	
public:
	union
	{
		struct 
		{
			Pcl_mem mem_object;
		};
		struct 
		{
			Pcl_mem buffer;
		};
		
	};
};
#pragma pack(pop)


typedef Tcl_image_desc *Pcl_image_desc;

#pragma pack(push,1)
struct DECLSPEC_DRECORD Tcl_buffer_region
{
public:
	System::NativeUInt origin;
	System::NativeUInt size;
};
#pragma pack(pop)


typedef Tcl_buffer_region *Pcl_buffer_region;

typedef void __stdcall (*Tcl_context_notify)(char * errinfo, void * private_info, System::NativeUInt size, void * user_data);

typedef void __stdcall (*Tcl_destructor_notify)(Pcl_mem memobj, void * user_data);

typedef void __stdcall (*Tcl_programbuilt_notify)(Pcl_program _program, void * user_data);

typedef void __stdcall (*Tcl_event_notify)(Pcl_event event, Opencl::Platform::Tcl_int num_event, void * user_data);

typedef void __stdcall (*Tcl_EnqueueNativeKernel)(void);

typedef void __stdcall (*Tcl_EnqueueSVM_fn)(void);

//-- var, const, procedure ---------------------------------------------------
#define LibOpenCL L"OpenCL.dll"
static _DELPHI_CONST System::Int8 CL_SUCCESS = System::Int8(0x0);
static _DELPHI_CONST System::Int8 CL_DEVICE_NOT_FOUND = System::Int8(-1);
static _DELPHI_CONST System::Int8 CL_DEVICE_NOT_AVAILABLE = System::Int8(-2);
static _DELPHI_CONST System::Int8 CL_COMPILER_NOT_AVAILABLE = System::Int8(-3);
static _DELPHI_CONST System::Int8 CL_MEM_OBJECT_ALLOCATION_FAILURE = System::Int8(-4);
static _DELPHI_CONST System::Int8 CL_OUT_OF_RESOURCES = System::Int8(-5);
static _DELPHI_CONST System::Int8 CL_OUT_OF_HOST_MEMORY = System::Int8(-6);
static _DELPHI_CONST System::Int8 CL_PROFILING_INFO_NOT_AVAILABLE = System::Int8(-7);
static _DELPHI_CONST System::Int8 CL_MEM_COPY_OVERLAP = System::Int8(-8);
static _DELPHI_CONST System::Int8 CL_IMAGE_FORMAT_MISMATCH = System::Int8(-9);
static _DELPHI_CONST System::Int8 CL_IMAGE_FORMAT_NOT_SUPPORTED = System::Int8(-10);
static _DELPHI_CONST System::Int8 CL_BUILD_PROGRAM_FAILURE = System::Int8(-11);
static _DELPHI_CONST System::Int8 CL_MAP_FAILURE = System::Int8(-12);
static _DELPHI_CONST System::Int8 CL_MISALIGNED_SUB_BUFFER_OFFSET = System::Int8(-13);
static _DELPHI_CONST System::Int8 CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST = System::Int8(-14);
static _DELPHI_CONST System::Int8 CL_COMPILE_PROGRAM_FAILURE = System::Int8(-15);
static _DELPHI_CONST System::Int8 CL_LINKER_NOT_AVAILABLE = System::Int8(-16);
static _DELPHI_CONST System::Int8 CL_LINK_PROGRAM_FAILURE = System::Int8(-17);
static _DELPHI_CONST System::Int8 CL_DEVICE_PARTITION_FAILED = System::Int8(-18);
static _DELPHI_CONST System::Int8 CL_KERNEL_ARG_INFO_NOT_AVAILABLE = System::Int8(-19);
static _DELPHI_CONST System::Int8 CL_INVALID_VALUE = System::Int8(-30);
static _DELPHI_CONST System::Int8 CL_INVALID_DEVICE_TYPE = System::Int8(-31);
static _DELPHI_CONST System::Int8 CL_INVALID_PLATFORM = System::Int8(-32);
static _DELPHI_CONST System::Int8 CL_INVALID_DEVICE = System::Int8(-33);
static _DELPHI_CONST System::Int8 CL_INVALID_CONTEXT = System::Int8(-34);
static _DELPHI_CONST System::Int8 CL_INVALID_QUEUE_PROPERTIES = System::Int8(-35);
static _DELPHI_CONST System::Int8 CL_INVALID_COMMAND_QUEUE = System::Int8(-36);
static _DELPHI_CONST System::Int8 CL_INVALID_HOST_PTR = System::Int8(-37);
static _DELPHI_CONST System::Int8 CL_INVALID_MEM_OBJECT = System::Int8(-38);
static _DELPHI_CONST System::Int8 CL_INVALID_IMAGE_FORMAT_DESCRIPTOR = System::Int8(-39);
static _DELPHI_CONST System::Int8 CL_INVALID_IMAGE_SIZE = System::Int8(-40);
static _DELPHI_CONST System::Int8 CL_INVALID_SAMPLER = System::Int8(-41);
static _DELPHI_CONST System::Int8 CL_INVALID_BINARY = System::Int8(-42);
static _DELPHI_CONST System::Int8 CL_INVALID_BUILD_OPTIONS = System::Int8(-43);
static _DELPHI_CONST System::Int8 CL_INVALID_PROGRAM = System::Int8(-44);
static _DELPHI_CONST System::Int8 CL_INVALID_PROGRAM_EXECUTABLE = System::Int8(-45);
static _DELPHI_CONST System::Int8 CL_INVALID_KERNEL_NAME = System::Int8(-46);
static _DELPHI_CONST System::Int8 CL_INVALID_KERNEL_DEFINITION = System::Int8(-47);
static _DELPHI_CONST System::Int8 CL_INVALID_KERNEL = System::Int8(-48);
static _DELPHI_CONST System::Int8 CL_INVALID_ARG_INDEX = System::Int8(-49);
static _DELPHI_CONST System::Int8 CL_INVALID_ARG_VALUE = System::Int8(-50);
static _DELPHI_CONST System::Int8 CL_INVALID_ARG_SIZE = System::Int8(-51);
static _DELPHI_CONST System::Int8 CL_INVALID_KERNEL_ARGS = System::Int8(-52);
static _DELPHI_CONST System::Int8 CL_INVALID_WORK_DIMENSION = System::Int8(-53);
static _DELPHI_CONST System::Int8 CL_INVALID_WORK_GROUP_SIZE = System::Int8(-54);
static _DELPHI_CONST System::Int8 CL_INVALID_WORK_ITEM_SIZE = System::Int8(-55);
static _DELPHI_CONST System::Int8 CL_INVALID_GLOBAL_OFFSET = System::Int8(-56);
static _DELPHI_CONST System::Int8 CL_INVALID_EVENT_WAIT_LIST = System::Int8(-57);
static _DELPHI_CONST System::Int8 CL_INVALID_EVENT = System::Int8(-58);
static _DELPHI_CONST System::Int8 CL_INVALID_OPERATION = System::Int8(-59);
static _DELPHI_CONST System::Int8 CL_INVALID_GL_OBJECT = System::Int8(-60);
static _DELPHI_CONST System::Int8 CL_INVALID_BUFFER_SIZE = System::Int8(-61);
static _DELPHI_CONST System::Int8 CL_INVALID_MIP_LEVEL = System::Int8(-62);
static _DELPHI_CONST System::Int8 CL_INVALID_GLOBAL_WORK_SIZE = System::Int8(-63);
static _DELPHI_CONST System::Int8 CL_INVALID_PROPERTY = System::Int8(-64);
static _DELPHI_CONST System::Int8 CL_INVALID_IMAGE_DESCRIPTOR = System::Int8(-65);
static _DELPHI_CONST System::Int8 CL_INVALID_COMPILER_OPTIONS = System::Int8(-66);
static _DELPHI_CONST System::Int8 CL_INVALID_LINKER_OPTIONS = System::Int8(-67);
static _DELPHI_CONST System::Int8 CL_INVALID_DEVICE_PARTITION_COUNT = System::Int8(-68);
static _DELPHI_CONST System::Int8 CL_INVALID_PIPE_SIZE = System::Int8(-69);
static _DELPHI_CONST System::Int8 CL_INVALID_DEVICE_QUEUE = System::Int8(-70);
static _DELPHI_CONST System::Int8 CL_INVALID_SPEC_ID = System::Int8(-71);
static _DELPHI_CONST System::Int8 CL_MAX_SIZE_RESTRICTION_EXCEEDED = System::Int8(-72);
static _DELPHI_CONST System::Int8 CL_VERSION_1_0 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_VERSION_1_1 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_VERSION_1_2 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_VERSION_2_0 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_VERSION_2_1 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_VERSION_2_2 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_FALSE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 CL_TRUE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_BLOCKING = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_NON_BLOCKING = System::Int8(0x0);
static _DELPHI_CONST System::Word CL_PLATFORM_PROFILE = System::Word(0x900);
static _DELPHI_CONST System::Word CL_PLATFORM_VERSION = System::Word(0x901);
static _DELPHI_CONST System::Word CL_PLATFORM_NAME = System::Word(0x902);
static _DELPHI_CONST System::Word CL_PLATFORM_VENDOR = System::Word(0x903);
static _DELPHI_CONST System::Word CL_PLATFORM_EXTENSIONS = System::Word(0x904);
static _DELPHI_CONST System::Word CL_PLATFORM_HOST_TIMER_RESOLUTION = System::Word(0x905);
static _DELPHI_CONST System::Int8 CL_DEVICE_TYPE_DEFAULT = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_DEVICE_TYPE_CPU = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_DEVICE_TYPE_GPU = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CL_DEVICE_TYPE_ACCELERATOR = System::Int8(0x8);
static _DELPHI_CONST System::Int8 CL_DEVICE_TYPE_CUSTOM = System::Int8(0x10);
static _DELPHI_CONST unsigned CL_DEVICE_TYPE_ALL = unsigned(0xffffffff);
static _DELPHI_CONST System::Word CL_DEVICE_TYPE = System::Word(0x1000);
static _DELPHI_CONST System::Word CL_DEVICE_VENDOR_ID = System::Word(0x1001);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_COMPUTE_UNITS = System::Word(0x1002);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS = System::Word(0x1003);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_WORK_GROUP_SIZE = System::Word(0x1004);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_WORK_ITEM_SIZES = System::Word(0x1005);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR = System::Word(0x1006);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT = System::Word(0x1007);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT = System::Word(0x1008);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG = System::Word(0x1009);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT = System::Word(0x100a);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE = System::Word(0x100b);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_CLOCK_FREQUENCY = System::Word(0x100c);
static _DELPHI_CONST System::Word CL_DEVICE_ADDRESS_BITS = System::Word(0x100d);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_READ_IMAGE_ARGS = System::Word(0x100e);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_WRITE_IMAGE_ARGS = System::Word(0x100f);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_MEM_ALLOC_SIZE = System::Word(0x1010);
static _DELPHI_CONST System::Word CL_DEVICE_IMAGE2D_MAX_WIDTH = System::Word(0x1011);
static _DELPHI_CONST System::Word CL_DEVICE_IMAGE2D_MAX_HEIGHT = System::Word(0x1012);
static _DELPHI_CONST System::Word CL_DEVICE_IMAGE3D_MAX_WIDTH = System::Word(0x1013);
static _DELPHI_CONST System::Word CL_DEVICE_IMAGE3D_MAX_HEIGHT = System::Word(0x1014);
static _DELPHI_CONST System::Word CL_DEVICE_IMAGE3D_MAX_DEPTH = System::Word(0x1015);
static _DELPHI_CONST System::Word CL_DEVICE_IMAGE_SUPPORT = System::Word(0x1016);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_PARAMETER_SIZE = System::Word(0x1017);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_SAMPLERS = System::Word(0x1018);
static _DELPHI_CONST System::Word CL_DEVICE_MEM_BASE_ADDR_ALIGN = System::Word(0x1019);
static _DELPHI_CONST System::Word CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE = System::Word(0x101a);
static _DELPHI_CONST System::Word CL_DEVICE_SINGLE_FP_CONFIG = System::Word(0x101b);
static _DELPHI_CONST System::Word CL_DEVICE_GLOBAL_MEM_CACHE_TYPE = System::Word(0x101c);
static _DELPHI_CONST System::Word CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE = System::Word(0x101d);
static _DELPHI_CONST System::Word CL_DEVICE_GLOBAL_MEM_CACHE_SIZE = System::Word(0x101e);
static _DELPHI_CONST System::Word CL_DEVICE_GLOBAL_MEM_SIZE = System::Word(0x101f);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE = System::Word(0x1020);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_CONSTANT_ARGS = System::Word(0x1021);
static _DELPHI_CONST System::Word CL_DEVICE_LOCAL_MEM_TYPE = System::Word(0x1022);
static _DELPHI_CONST System::Word CL_DEVICE_LOCAL_MEM_SIZE = System::Word(0x1023);
static _DELPHI_CONST System::Word CL_DEVICE_ERROR_CORRECTION_SUPPORT = System::Word(0x1024);
static _DELPHI_CONST System::Word CL_DEVICE_PROFILING_TIMER_RESOLUTION = System::Word(0x1025);
static _DELPHI_CONST System::Word CL_DEVICE_ENDIAN_LITTLE = System::Word(0x1026);
static _DELPHI_CONST System::Word CL_DEVICE_AVAILABLE = System::Word(0x1027);
static _DELPHI_CONST System::Word CL_DEVICE_COMPILER_AVAILABLE = System::Word(0x1028);
static _DELPHI_CONST System::Word CL_DEVICE_EXECUTION_CAPABILITIES = System::Word(0x1029);
static _DELPHI_CONST System::Word CL_DEVICE_QUEUE_PROPERTIES = System::Word(0x102a);
static _DELPHI_CONST System::Word CL_DEVICE_QUEUE_ON_HOST_PROPERTIES = System::Word(0x102a);
static _DELPHI_CONST System::Word CL_DEVICE_NAME = System::Word(0x102b);
static _DELPHI_CONST System::Word CL_DEVICE_VENDOR = System::Word(0x102c);
static _DELPHI_CONST System::Word CL_DRIVER_VERSION = System::Word(0x102d);
static _DELPHI_CONST System::Word CL_DEVICE_PROFILE = System::Word(0x102e);
static _DELPHI_CONST System::Word CL_DEVICE_VERSION = System::Word(0x102f);
static _DELPHI_CONST System::Word CL_DEVICE_EXTENSIONS = System::Word(0x1030);
static _DELPHI_CONST System::Word CL_DEVICE_PLATFORM = System::Word(0x1031);
static _DELPHI_CONST System::Word CL_DEVICE_DOUBLE_FP_CONFIG = System::Word(0x1032);
static _DELPHI_CONST System::Word CL_DEVICE_HALF_FP_CONFIG = System::Word(0x1033);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF = System::Word(0x1034);
static _DELPHI_CONST System::Word CL_DEVICE_HOST_UNIFIED_MEMORY = System::Word(0x1035);
static _DELPHI_CONST System::Word CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR = System::Word(0x1036);
static _DELPHI_CONST System::Word CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT = System::Word(0x1037);
static _DELPHI_CONST System::Word CL_DEVICE_NATIVE_VECTOR_WIDTH_INT = System::Word(0x1038);
static _DELPHI_CONST System::Word CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG = System::Word(0x1039);
static _DELPHI_CONST System::Word CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT = System::Word(0x103a);
static _DELPHI_CONST System::Word CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE = System::Word(0x103b);
static _DELPHI_CONST System::Word CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF = System::Word(0x103c);
static _DELPHI_CONST System::Word CL_DEVICE_OPENCL_C_VERSION = System::Word(0x103d);
static _DELPHI_CONST System::Word CL_DEVICE_LINKER_AVAILABLE = System::Word(0x103e);
static _DELPHI_CONST System::Word CL_DEVICE_BUILT_IN_KERNELS = System::Word(0x103f);
static _DELPHI_CONST System::Word CL_DEVICE_IMAGE_MAX_BUFFER_SIZE = System::Word(0x1040);
static _DELPHI_CONST System::Word CL_DEVICE_IMAGE_MAX_ARRAY_SIZE = System::Word(0x1041);
static _DELPHI_CONST System::Word CL_DEVICE_PARENT_DEVICE = System::Word(0x1042);
static _DELPHI_CONST System::Word CL_DEVICE_PARTITION_MAX_SUB_DEVICES = System::Word(0x1043);
static _DELPHI_CONST System::Word CL_DEVICE_PARTITION_PROPERTIES = System::Word(0x1044);
static _DELPHI_CONST System::Word CL_DEVICE_PARTITION_AFFINITY_DOMAIN = System::Word(0x1045);
static _DELPHI_CONST System::Word CL_DEVICE_PARTITION_TYPE = System::Word(0x1046);
static _DELPHI_CONST System::Word CL_DEVICE_REFERENCE_COUNT = System::Word(0x1047);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_INTEROP_USER_SYNC = System::Word(0x1048);
static _DELPHI_CONST System::Word CL_DEVICE_PRINTF_BUFFER_SIZE = System::Word(0x1049);
static _DELPHI_CONST System::Word CL_DEVICE_IMAGE_PITCH_ALIGNMENT = System::Word(0x104a);
static _DELPHI_CONST System::Word CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT = System::Word(0x104b);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_READ_WRITE_IMAGE_ARGS = System::Word(0x104c);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_GLOBAL_VARIABLE_SIZE = System::Word(0x104d);
static _DELPHI_CONST System::Word CL_DEVICE_QUEUE_ON_DEVICE_PROPERTIES = System::Word(0x104e);
static _DELPHI_CONST System::Word CL_DEVICE_QUEUE_ON_DEVICE_PREFERRED_SIZE = System::Word(0x104f);
static _DELPHI_CONST System::Word CL_DEVICE_QUEUE_ON_DEVICE_MAX_SIZE = System::Word(0x1050);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_ON_DEVICE_QUEUES = System::Word(0x1051);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_ON_DEVICE_EVENTS = System::Word(0x1052);
static _DELPHI_CONST System::Word CL_DEVICE_SVM_CAPABILITIES = System::Word(0x1053);
static _DELPHI_CONST System::Word CL_DEVICE_GLOBAL_VARIABLE_PREFERRED_TOTAL_SIZE = System::Word(0x1054);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_PIPE_ARGS = System::Word(0x1055);
static _DELPHI_CONST System::Word CL_DEVICE_PIPE_MAX_ACTIVE_RESERVATIONS = System::Word(0x1056);
static _DELPHI_CONST System::Word CL_DEVICE_PIPE_MAX_PACKET_SIZE = System::Word(0x1057);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_PLATFORM_ATOMIC_ALIGNMENT = System::Word(0x1058);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_GLOBAL_ATOMIC_ALIGNMENT = System::Word(0x1059);
static _DELPHI_CONST System::Word CL_DEVICE_PREFERRED_LOCAL_ATOMIC_ALIGNMENT = System::Word(0x105a);
static _DELPHI_CONST System::Word CL_DEVICE_IL_VERSION = System::Word(0x105b);
static _DELPHI_CONST System::Word CL_DEVICE_MAX_NUM_SUB_GROUPS = System::Word(0x105c);
static _DELPHI_CONST System::Word CL_DEVICE_SUB_GROUP_INDEPENDENT_FORWARD_PROGRESS = System::Word(0x105d);
static _DELPHI_CONST System::Int8 CL_FP_DENORM = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_FP_INF_NAN = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_FP_ROUND_TO_NEAREST = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CL_FP_ROUND_TO_ZERO = System::Int8(0x8);
static _DELPHI_CONST System::Int8 CL_FP_ROUND_TO_INF = System::Int8(0x10);
static _DELPHI_CONST System::Int8 CL_FP_FMA = System::Int8(0x20);
static _DELPHI_CONST System::Int8 CL_FP_SOFT_FLOAT = System::Int8(0x40);
static _DELPHI_CONST System::Byte CL_FP_CORRECTLY_ROUNDED_DIVIDE_SQRT = System::Byte(0x80);
static _DELPHI_CONST System::Int8 CL_NONE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 CL_READ_ONLY_CACHE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_READ_WRITE_CACHE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_LOCAL = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_GLOBAL = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_EXEC_KERNEL = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_EXEC_NATIVE_KERNEL = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_QUEUE_PROFILING_ENABLE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_QUEUE_ON_DEVICE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CL_QUEUE_ON_DEVICE_DEFAULT = System::Int8(0x8);
static _DELPHI_CONST System::Word CL_CONTEXT_REFERENCE_COUNT = System::Word(0x1080);
static _DELPHI_CONST System::Word CL_CONTEXT_DEVICES = System::Word(0x1081);
static _DELPHI_CONST System::Word CL_CONTEXT_PROPERTIES = System::Word(0x1082);
static _DELPHI_CONST System::Word CL_CONTEXT_NUM_DEVICES = System::Word(0x1083);
static _DELPHI_CONST System::Word CL_CONTEXT_PLATFORM = System::Word(0x1084);
static _DELPHI_CONST System::Word CL_CONTEXT_INTEROP_USER_SYNC = System::Word(0x1085);
static _DELPHI_CONST System::Word CL_DEVICE_PARTITION_EQUALLY = System::Word(0x1086);
static _DELPHI_CONST System::Word CL_DEVICE_PARTITION_BY_COUNTS = System::Word(0x1087);
static _DELPHI_CONST System::Int8 CL_DEVICE_PARTITION_BY_COUNTS_LIST_END = System::Int8(0x0);
static _DELPHI_CONST System::Word CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN = System::Word(0x1088);
static _DELPHI_CONST System::Int8 CL_DEVICE_AFFINITY_DOMAIN_NUMA = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE = System::Int8(0x10);
static _DELPHI_CONST System::Int8 CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE = System::Int8(0x20);
static _DELPHI_CONST System::Int8 CL_DEVICE_SVM_COARSE_GRAIN_BUFFER = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_DEVICE_SVM_FINE_GRAIN_BUFFER = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_DEVICE_SVM_FINE_GRAIN_SYSTEM = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CL_DEVICE_SVM_ATOMICS = System::Int8(0x8);
static _DELPHI_CONST System::Word CL_QUEUE_CONTEXT = System::Word(0x1090);
static _DELPHI_CONST System::Word CL_QUEUE_DEVICE = System::Word(0x1091);
static _DELPHI_CONST System::Word CL_QUEUE_REFERENCE_COUNT = System::Word(0x1092);
static _DELPHI_CONST System::Word CL_QUEUE_PROPERTIES = System::Word(0x1093);
static _DELPHI_CONST System::Word CL_QUEUE_SIZE = System::Word(0x1094);
static _DELPHI_CONST System::Word CL_QUEUE_DEVICE_DEFAULT = System::Word(0x1095);
static _DELPHI_CONST System::Int8 CL_MEM_READ_WRITE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_MEM_WRITE_ONLY = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_MEM_READ_ONLY = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CL_MEM_USE_HOST_PTR = System::Int8(0x8);
static _DELPHI_CONST System::Int8 CL_MEM_ALLOC_HOST_PTR = System::Int8(0x10);
static _DELPHI_CONST System::Int8 CL_MEM_COPY_HOST_PTR = System::Int8(0x20);
static _DELPHI_CONST System::Byte CL_MEM_HOST_WRITE_ONLY = System::Byte(0x80);
static _DELPHI_CONST System::Word CL_MEM_HOST_READ_ONLY = System::Word(0x100);
static _DELPHI_CONST System::Word CL_MEM_HOST_NO_ACCESS = System::Word(0x200);
static _DELPHI_CONST System::Word CL_MEM_SVM_FINE_GRAIN_BUFFER = System::Word(0x400);
static _DELPHI_CONST System::Word CL_MEM_SVM_ATOMICS = System::Word(0x800);
static _DELPHI_CONST System::Word CL_MEM_KERNEL_READ_AND_WRITE = System::Word(0x1000);
static _DELPHI_CONST System::Int8 CL_MIGRATE_MEM_OBJECT_HOST = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED = System::Int8(0x2);
static _DELPHI_CONST System::Word CL_R = System::Word(0x10b0);
static _DELPHI_CONST System::Word CL_A = System::Word(0x10b1);
static _DELPHI_CONST System::Word CL_RG = System::Word(0x10b2);
static _DELPHI_CONST System::Word CL_RA = System::Word(0x10b3);
static _DELPHI_CONST System::Word CL_RGB = System::Word(0x10b4);
static _DELPHI_CONST System::Word CL_RGBA = System::Word(0x10b5);
static _DELPHI_CONST System::Word CL_BGRA = System::Word(0x10b6);
static _DELPHI_CONST System::Word CL_ARGB = System::Word(0x10b7);
static _DELPHI_CONST System::Word CL_INTENSITY = System::Word(0x10b8);
static _DELPHI_CONST System::Word CL_LUMINANCE = System::Word(0x10b9);
static _DELPHI_CONST System::Word CL_Rx = System::Word(0x10ba);
static _DELPHI_CONST System::Word CL_RGx = System::Word(0x10bb);
static _DELPHI_CONST System::Word CL_RGBx = System::Word(0x10bc);
static _DELPHI_CONST System::Word CL_DEPTH = System::Word(0x10bd);
static _DELPHI_CONST System::Word CL_DEPTH_STENCIL = System::Word(0x10be);
static _DELPHI_CONST System::Word CL_sRGB = System::Word(0x10bf);
static _DELPHI_CONST System::Word CL_sRGBx = System::Word(0x10c0);
static _DELPHI_CONST System::Word CL_sRGBA = System::Word(0x10c1);
static _DELPHI_CONST System::Word CL_sBGRA = System::Word(0x10c2);
static _DELPHI_CONST System::Word CL_ABGR = System::Word(0x10c3);
static _DELPHI_CONST System::Word CL_SNORM_INT8 = System::Word(0x10d0);
static _DELPHI_CONST System::Word CL_SNORM_INT16 = System::Word(0x10d1);
static _DELPHI_CONST System::Word CL_UNORM_INT8 = System::Word(0x10d2);
static _DELPHI_CONST System::Word CL_UNORM_INT16 = System::Word(0x10d3);
static _DELPHI_CONST System::Word CL_UNORM_SHORT_565 = System::Word(0x10d4);
static _DELPHI_CONST System::Word CL_UNORM_SHORT_555 = System::Word(0x10d5);
static _DELPHI_CONST System::Word CL_UNORM_INT_101010 = System::Word(0x10d6);
static _DELPHI_CONST System::Word CL_SIGNED_INT8 = System::Word(0x10d7);
static _DELPHI_CONST System::Word CL_SIGNED_INT16 = System::Word(0x10d8);
static _DELPHI_CONST System::Word CL_SIGNED_INT32 = System::Word(0x10d9);
static _DELPHI_CONST System::Word CL_UNSIGNED_INT8 = System::Word(0x10da);
static _DELPHI_CONST System::Word CL_UNSIGNED_INT16 = System::Word(0x10db);
static _DELPHI_CONST System::Word CL_UNSIGNED_INT32 = System::Word(0x10dc);
static _DELPHI_CONST System::Word CL_HALF_FLOAT = System::Word(0x10dd);
static _DELPHI_CONST System::Word CL_FLOAT = System::Word(0x10de);
static _DELPHI_CONST System::Word CL_UNORM_INT24 = System::Word(0x10df);
static _DELPHI_CONST System::Word CL_UNORM_INT_101010_2 = System::Word(0x10e0);
static _DELPHI_CONST System::Word CL_MEM_OBJECT_BUFFER = System::Word(0x10f0);
static _DELPHI_CONST System::Word CL_MEM_OBJECT_IMAGE2D = System::Word(0x10f1);
static _DELPHI_CONST System::Word CL_MEM_OBJECT_IMAGE3D = System::Word(0x10f2);
static _DELPHI_CONST System::Word CL_MEM_OBJECT_IMAGE2D_ARRAY = System::Word(0x10f3);
static _DELPHI_CONST System::Word CL_MEM_OBJECT_IMAGE1D = System::Word(0x10f4);
static _DELPHI_CONST System::Word CL_MEM_OBJECT_IMAGE1D_ARRAY = System::Word(0x10f5);
static _DELPHI_CONST System::Word CL_MEM_OBJECT_IMAGE1D_BUFFER = System::Word(0x10f6);
static _DELPHI_CONST System::Word CL_MEM_OBJECT_PIPE = System::Word(0x10f7);
static _DELPHI_CONST System::Word CL_MEM_TYPE = System::Word(0x1100);
static _DELPHI_CONST System::Word CL_MEM_FLAGS = System::Word(0x1101);
static _DELPHI_CONST System::Word CL_MEM_SIZE = System::Word(0x1102);
static _DELPHI_CONST System::Word CL_MEM_HOST_PTR = System::Word(0x1103);
static _DELPHI_CONST System::Word CL_MEM_MAP_COUNT = System::Word(0x1104);
static _DELPHI_CONST System::Word CL_MEM_REFERENCE_COUNT = System::Word(0x1105);
static _DELPHI_CONST System::Word CL_MEM_CONTEXT = System::Word(0x1106);
static _DELPHI_CONST System::Word CL_MEM_ASSOCIATED_MEMOBJECT = System::Word(0x1107);
static _DELPHI_CONST System::Word CL_MEM_OFFSET = System::Word(0x1108);
static _DELPHI_CONST System::Word CL_MEM_USES_SVM_POINTER = System::Word(0x1109);
static _DELPHI_CONST System::Word CL_IMAGE_FORMAT = System::Word(0x1110);
static _DELPHI_CONST System::Word CL_IMAGE_ELEMENT_SIZE = System::Word(0x1111);
static _DELPHI_CONST System::Word CL_IMAGE_ROW_PITCH = System::Word(0x1112);
static _DELPHI_CONST System::Word CL_IMAGE_SLICE_PITCH = System::Word(0x1113);
static _DELPHI_CONST System::Word CL_IMAGE_WIDTH = System::Word(0x1114);
static _DELPHI_CONST System::Word CL_IMAGE_HEIGHT = System::Word(0x1115);
static _DELPHI_CONST System::Word CL_IMAGE_DEPTH = System::Word(0x1116);
static _DELPHI_CONST System::Word CL_IMAGE_ARRAY_SIZE = System::Word(0x1117);
static _DELPHI_CONST System::Word CL_IMAGE_BUFFER = System::Word(0x1118);
static _DELPHI_CONST System::Word CL_IMAGE_NUM_MIP_LEVELS = System::Word(0x1119);
static _DELPHI_CONST System::Word CL_IMAGE_NUM_SAMPLES = System::Word(0x111a);
static _DELPHI_CONST System::Word CL_PIPE_PACKET_SIZE = System::Word(0x1120);
static _DELPHI_CONST System::Word CL_PIPE_MAX_PACKETS = System::Word(0x1121);
static _DELPHI_CONST System::Word CL_ADDRESS_NONE = System::Word(0x1130);
static _DELPHI_CONST System::Word CL_ADDRESS_CLAMP_TO_EDGE = System::Word(0x1131);
static _DELPHI_CONST System::Word CL_ADDRESS_CLAMP = System::Word(0x1132);
static _DELPHI_CONST System::Word CL_ADDRESS_REPEAT = System::Word(0x1133);
static _DELPHI_CONST System::Word CL_ADDRESS_MIRRORED_REPEAT = System::Word(0x1134);
static _DELPHI_CONST System::Word CL_FILTER_NEAREST = System::Word(0x1140);
static _DELPHI_CONST System::Word CL_FILTER_LINEAR = System::Word(0x1141);
static _DELPHI_CONST System::Word CL_SAMPLER_REFERENCE_COUNT = System::Word(0x1150);
static _DELPHI_CONST System::Word CL_SAMPLER_CONTEXT = System::Word(0x1151);
static _DELPHI_CONST System::Word CL_SAMPLER_NORMALIZED_COORDS = System::Word(0x1152);
static _DELPHI_CONST System::Word CL_SAMPLER_ADDRESSING_MODE = System::Word(0x1153);
static _DELPHI_CONST System::Word CL_SAMPLER_FILTER_MODE = System::Word(0x1154);
static _DELPHI_CONST System::Word CL_SAMPLER_MIP_FILTER_MODE = System::Word(0x1155);
static _DELPHI_CONST System::Word CL_SAMPLER_LOD_MIN = System::Word(0x1156);
static _DELPHI_CONST System::Word CL_SAMPLER_LOD_MAX = System::Word(0x1157);
static _DELPHI_CONST System::Int8 CL_MAP_READ = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_MAP_WRITE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_MAP_WRITE_INVALIDATE_REGION = System::Int8(0x4);
static _DELPHI_CONST System::Word CL_PROGRAM_REFERENCE_COUNT = System::Word(0x1160);
static _DELPHI_CONST System::Word CL_PROGRAM_CONTEXT = System::Word(0x1161);
static _DELPHI_CONST System::Word CL_PROGRAM_NUM_DEVICES = System::Word(0x1162);
static _DELPHI_CONST System::Word CL_PROGRAM_DEVICES = System::Word(0x1163);
static _DELPHI_CONST System::Word CL_PROGRAM_SOURCE = System::Word(0x1164);
static _DELPHI_CONST System::Word CL_PROGRAM_BINARY_SIZES = System::Word(0x1165);
static _DELPHI_CONST System::Word CL_PROGRAM_BINARIES = System::Word(0x1166);
static _DELPHI_CONST System::Word CL_PROGRAM_NUM_KERNELS = System::Word(0x1167);
static _DELPHI_CONST System::Word CL_PROGRAM_KERNEL_NAMES = System::Word(0x1168);
static _DELPHI_CONST System::Word CL_PROGRAM_IL = System::Word(0x1169);
static _DELPHI_CONST System::Word CL_PROGRAM_SCOPE_GLOBAL_CTORS_PRESENT = System::Word(0x116a);
static _DELPHI_CONST System::Word CL_PROGRAM_SCOPE_GLOBAL_DTORS_PRESENT = System::Word(0x116b);
static _DELPHI_CONST System::Word CL_PROGRAM_BUILD_STATUS = System::Word(0x1181);
static _DELPHI_CONST System::Word CL_PROGRAM_BUILD_OPTIONS = System::Word(0x1182);
static _DELPHI_CONST System::Word CL_PROGRAM_BUILD_LOG = System::Word(0x1183);
static _DELPHI_CONST System::Word CL_PROGRAM_BINARY_TYPE = System::Word(0x1184);
static _DELPHI_CONST System::Word CL_PROGRAM_BUILD_GLOBAL_VARIABLE_TOTAL_SIZE = System::Word(0x1185);
static _DELPHI_CONST System::Int8 CL_PROGBRAM_BINARY_TYPE_NONE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 CL_PROGRAM_BINARY_TYPE_COMPILED_OBJECT = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_PROGRAM_BINARY_TYPE_LIBRARY = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_PROGRAM_BINARY_TYPE_EXECUTABLE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CL_BUILD_SUCCESS = System::Int8(0x0);
static _DELPHI_CONST System::Int8 CL_BUILD_NONE = System::Int8(-1);
static _DELPHI_CONST System::Int8 CL_BUILD_ERROR = System::Int8(-2);
static _DELPHI_CONST System::Int8 CL_BUILD_IN_PROGRESS = System::Int8(-3);
static _DELPHI_CONST System::Word CL_KERNEL_FUNCTION_NAME = System::Word(0x1190);
static _DELPHI_CONST System::Word CL_KERNEL_NUM_ARGS = System::Word(0x1191);
static _DELPHI_CONST System::Word CL_KERNEL_REFERENCE_COUNT = System::Word(0x1192);
static _DELPHI_CONST System::Word CL_KERNEL_CONTEXT = System::Word(0x1193);
static _DELPHI_CONST System::Word CL_KERNEL_PROGRAM = System::Word(0x1194);
static _DELPHI_CONST System::Word CL_KERNEL_ATTRIBUTES = System::Word(0x1195);
static _DELPHI_CONST System::Word CL_KERNEL_MAX_NUM_SUB_GROUPS = System::Word(0x11b9);
static _DELPHI_CONST System::Word CL_KERNEL_COMPILE_NUM_SUB_GROUPS = System::Word(0x11ba);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_ADDRESS_QUALIFIER = System::Word(0x1196);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_ACCESS_QUALIFIER = System::Word(0x1197);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_TYPE_NAME = System::Word(0x1198);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_TYPE_QUALIFIER = System::Word(0x1199);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_NAME = System::Word(0x119a);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_ADDRESS_GLOBAL = System::Word(0x119b);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_ADDRESS_LOCAL = System::Word(0x119c);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_ADDRESS_CONSTANT = System::Word(0x119d);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_ADDRESS_PRIVATE = System::Word(0x119e);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_ACCESS_READ_ONLY = System::Word(0x11a0);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_ACCESS_WRITE_ONLY = System::Word(0x11a1);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_ACCESS_READ_WRITE = System::Word(0x11a2);
static _DELPHI_CONST System::Word CL_KERNEL_ARG_ACCESS_NONE = System::Word(0x11a3);
static _DELPHI_CONST System::Int8 CL_KERNEL_ARG_TYPE_NONE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 CL_KERNEL_ARG_TYPE_CONST = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_KERNEL_ARG_TYPE_RESTRICT = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_KERNEL_ARG_TYPE_VOLATILE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CL_KERNEL_ARG_TYPE_PIPE = System::Int8(0x8);
static _DELPHI_CONST System::Word CL_KERNEL_WORK_GROUP_SIZE = System::Word(0x11b0);
static _DELPHI_CONST System::Word CL_KERNEL_COMPILE_WORK_GROUP_SIZE = System::Word(0x11b1);
static _DELPHI_CONST System::Word CL_KERNEL_LOCAL_MEM_SIZE = System::Word(0x11b2);
static _DELPHI_CONST System::Word CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE = System::Word(0x11b3);
static _DELPHI_CONST System::Word CL_KERNEL_PRIVATE_MEM_SIZE = System::Word(0x11b4);
static _DELPHI_CONST System::Word CL_KERNEL_GLOBAL_WORK_SIZE = System::Word(0x11b5);
static _DELPHI_CONST System::Word CL_KERNEL_MAX_SUB_GROUP_SIZE_FOR_NDRANGE = System::Word(0x2033);
static _DELPHI_CONST System::Word CL_KERNEL_SUB_GROUP_COUNT_FOR_NDRANGE = System::Word(0x2034);
static _DELPHI_CONST System::Word CL_KERNEL_LOCAL_SIZE_FOR_SUB_GROUP_COUNT = System::Word(0x11b8);
static _DELPHI_CONST System::Word CL_KERNEL_EXEC_INFO_SVM_PTRS = System::Word(0x11b6);
static _DELPHI_CONST System::Word CL_KERNEL_EXEC_INFO_SVM_FINE_GRAIN_SYSTEM = System::Word(0x11b7);
static _DELPHI_CONST System::Word CL_EVENT_COMMAND_QUEUE = System::Word(0x11d0);
static _DELPHI_CONST System::Word CL_EVENT_COMMAND_TYPE = System::Word(0x11d1);
static _DELPHI_CONST System::Word CL_EVENT_REFERENCE_COUNT = System::Word(0x11d2);
static _DELPHI_CONST System::Word CL_EVENT_COMMAND_EXECUTION_STATUS = System::Word(0x11d3);
static _DELPHI_CONST System::Word CL_EVENT_CONTEXT = System::Word(0x11d4);
static _DELPHI_CONST System::Word CL_COMMAND_NDRANGE_KERNEL = System::Word(0x11f0);
static _DELPHI_CONST System::Word CL_COMMAND_TASK = System::Word(0x11f1);
static _DELPHI_CONST System::Word CL_COMMAND_NATIVE_KERNEL = System::Word(0x11f2);
static _DELPHI_CONST System::Word CL_COMMAND_READ_BUFFER = System::Word(0x11f3);
static _DELPHI_CONST System::Word CL_COMMAND_WRITE_BUFFER = System::Word(0x11f4);
static _DELPHI_CONST System::Word CL_COMMAND_COPY_BUFFER = System::Word(0x11f5);
static _DELPHI_CONST System::Word CL_COMMAND_READ_IMAGE = System::Word(0x11f6);
static _DELPHI_CONST System::Word CL_COMMAND_WRITE_IMAGE = System::Word(0x11f7);
static _DELPHI_CONST System::Word CL_COMMAND_COPY_IMAGE = System::Word(0x11f8);
static _DELPHI_CONST System::Word CL_COMMAND_COPY_IMAGE_TO_BUFFER = System::Word(0x11f9);
static _DELPHI_CONST System::Word CL_COMMAND_COPY_BUFFER_TO_IMAGE = System::Word(0x11fa);
static _DELPHI_CONST System::Word CL_COMMAND_MAP_BUFFER = System::Word(0x11fb);
static _DELPHI_CONST System::Word CL_COMMAND_MAP_IMAGE = System::Word(0x11fc);
static _DELPHI_CONST System::Word CL_COMMAND_UNMAP_MEM_OBJECT = System::Word(0x11fd);
static _DELPHI_CONST System::Word CL_COMMAND_MARKER = System::Word(0x11fe);
static _DELPHI_CONST System::Word CL_COMMAND_ACQUIRE_GL_OBJECTS = System::Word(0x11ff);
static _DELPHI_CONST System::Word CL_COMMAND_RELEASE_GL_OBJECTS = System::Word(0x1200);
static _DELPHI_CONST System::Word CL_COMMAND_READ_BUFFER_RECT = System::Word(0x1201);
static _DELPHI_CONST System::Word CL_COMMAND_WRITE_BUFFER_RECT = System::Word(0x1202);
static _DELPHI_CONST System::Word CL_COMMAND_COPY_BUFFER_RECT = System::Word(0x1203);
static _DELPHI_CONST System::Word CL_COMMAND_USER = System::Word(0x1204);
static _DELPHI_CONST System::Word CL_COMMAND_BARRIER = System::Word(0x1205);
static _DELPHI_CONST System::Word CL_COMMAND_MIGRATE_MEM_OBJECTS = System::Word(0x1206);
static _DELPHI_CONST System::Word CL_COMMAND_FILL_BUFFER = System::Word(0x1207);
static _DELPHI_CONST System::Word CL_COMMAND_FILL_IMAGE = System::Word(0x1208);
static _DELPHI_CONST System::Word CL_COMMAND_SVM_FREE = System::Word(0x1209);
static _DELPHI_CONST System::Word CL_COMMAND_SVM_MEMCPY = System::Word(0x120a);
static _DELPHI_CONST System::Word CL_COMMAND_SVM_MEMFILL = System::Word(0x120b);
static _DELPHI_CONST System::Word CL_COMMAND_SVM_MAP = System::Word(0x120c);
static _DELPHI_CONST System::Word CL_COMMAND_SVM_UNMAP = System::Word(0x120d);
static _DELPHI_CONST System::Int8 CL_COMPLETE = System::Int8(0x0);
static _DELPHI_CONST System::Int8 CL_RUNNING = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CL_SUBMITTED = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CL_QUEUED = System::Int8(0x3);
static _DELPHI_CONST System::Word CL_BUFFER_CREATE_TYPE_REGION = System::Word(0x1220);
static _DELPHI_CONST System::Word CL_PROFILING_COMMAND_QUEUED = System::Word(0x1280);
static _DELPHI_CONST System::Word CL_PROFILING_COMMAND_SUBMIT = System::Word(0x1281);
static _DELPHI_CONST System::Word CL_PROFILING_COMMAND_START = System::Word(0x1282);
static _DELPHI_CONST System::Word CL_PROFILING_COMMAND_END = System::Word(0x1283);
static _DELPHI_CONST System::Word CL_PROFILING_COMMAND_COMPLETE = System::Word(0x1284);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetPlatformIDs(Opencl::Platform::Tcl_uint num_entries, Pcl_platform_id platforms, Opencl::Platform::Pcl_uint num_platforms);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetPlatformInfo(Tcl_platform_id cl_platform, Tcl_platform_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetDeviceIDs(Pcl_platform_id _platform, Tcl_device_type device_type, Opencl::Platform::Tcl_uint num_entries, Pcl_device_id devices, Opencl::Platform::Pcl_uint num_devices);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetDeviceInfo(Pcl_device_id device, Tcl_device_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clCreateSubDevices(Pcl_device_id in_device, Pcl_device_partition_property properties, Opencl::Platform::Tcl_uint num_devices, Pcl_device_id out_devices, Opencl::Platform::Pcl_uint num_devices_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clRetainDevice(Pcl_device_id device);
extern "C" Opencl::Platform::Tcl_int __stdcall clReleaseDevice(Pcl_device_id device);
extern "C" Opencl::Platform::Tcl_int __stdcall clSetDefaultDeviceCommandQueue(Pcl_context context, Pcl_device_id device, Pcl_command_queue command_queue);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetDeviceAndHostTimer(Pcl_device_id device, Opencl::Platform::Pcl_ulong device_timestamp, Opencl::Platform::Pcl_ulong host_timestamp);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetHostTimer(Pcl_device_id device, Opencl::Platform::Pcl_ulong host_timestamp);
extern "C" Pcl_context __stdcall clCreateContext(Pcl_context_properties properties, Opencl::Platform::Tcl_uint num_devices, Pcl_device_id devices, Tcl_context_notify pfn_notify, void * user_data, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Pcl_context __stdcall clCreateContextFromType(Pcl_context_properties properties, Tcl_device_type device_type, Tcl_context_notify pfn_notify, void * user_data, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clRetainContext(Pcl_context context);
extern "C" Opencl::Platform::Tcl_int __stdcall clReleaseContext(Pcl_context context);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetContextInfo(Pcl_context context, Tcl_context_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Pcl_command_queue __stdcall clCreateCommandQueue(Pcl_context context, Pcl_device_id device, Tcl_command_queue_properties properties, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clRetainCommandQueue(Pcl_command_queue command_queue);
extern "C" Opencl::Platform::Tcl_int __stdcall clReleaseCommandQueue(Pcl_command_queue command_queue);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetCommandQueueInfo(Pcl_command_queue command_queue, Tcl_command_queue_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Pcl_mem __stdcall clCreateBuffer(Pcl_context context, Tcl_mem_flags flags, System::NativeUInt size, void * host_ptr, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Pcl_mem __stdcall clCreateSubBuffer(Pcl_mem buffer, Tcl_mem_flags flags, Tcl_buffer_create_type buffer_create_type, void * buffer_create_info, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Pcl_mem __stdcall clCreateImage(Pcl_context context, Tcl_mem_flags flags, Pcl_image_format image_format, Pcl_image_desc image_desc, void * host_ptr, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Pcl_mem __stdcall clCreatePipe(Pcl_context context, Tcl_mem_flags flags, Opencl::Platform::Tcl_uint pipe_packet_size, Opencl::Platform::Tcl_uint pipe_max_packets, Pcl_pipe_properties properties, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clRetainMemObject(Pcl_mem memobj);
extern "C" Opencl::Platform::Tcl_int __stdcall clReleaseMemObject(Pcl_mem memobj);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetSupportedImageFormats(Pcl_context context, Tcl_mem_flags flags, Tcl_mem_object_type image_type, Opencl::Platform::Tcl_uint num_entries, Pcl_image_format image_formats, Opencl::Platform::Pcl_uint num_image_formats);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetMemObjectInfo(Pcl_mem memobj, Tcl_mem_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetImageInfo(Pcl_mem image, Tcl_image_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetPipeInfo(Pcl_mem pipe, Tcl_pipe_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clSetMemObjectDestructorCallback(Pcl_mem memobj, Tcl_destructor_notify pfn_notify, void * user_data);
extern "C" void * __stdcall clSVMAlloc(Pcl_context context, Tcl_svm_mem_flags flags, System::NativeUInt size, Opencl::Platform::Tcl_uint alignment);
extern "C" void __stdcall clSVMFree(Pcl_context context, void * svm_pointer);
extern "C" Pcl_sampler __stdcall clCreateSamplerWithProperties(Pcl_context context, Pcl_sampler_properties normalized_coords, Tcl_addressing_mode addressing_mode, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clRetainSampler(Pcl_sampler sampler);
extern "C" Opencl::Platform::Tcl_int __stdcall clReleaseSampler(Pcl_sampler sampler);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetSamplerInfo(Pcl_sampler sampler, Tcl_sampler_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Pcl_program __stdcall clCreateProgramWithSource(Pcl_context context, Opencl::Platform::Tcl_uint count, System::PPAnsiChar strings, Opencl::Platform::Psize_t lengths, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Pcl_program __stdcall clCreateProgramWithBinary(Pcl_context context, Opencl::Platform::Tcl_uint num_devices, Pcl_device_id device_list, Opencl::Platform::Psize_t lengths, Winapi::Windows::PByte binaries, Opencl::Platform::Pcl_int binary_status, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Pcl_program __stdcall clCreateProgramWithBuiltInKernels(Pcl_context context, Opencl::Platform::Tcl_uint num_devices, Pcl_device_id device_list, Opencl::Platform::Pcl_char kernel_names, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Pcl_program __stdcall clCreateProgramWithIL(Pcl_context context, void * il, System::NativeUInt length, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clRetainProgram(Pcl_program _program);
extern "C" Opencl::Platform::Tcl_int __stdcall clReleaseProgram(Pcl_program _program);
extern "C" Opencl::Platform::Tcl_int __stdcall clBuildProgram(Pcl_program _program, Opencl::Platform::Tcl_uint num_devices, Pcl_device_id device_list, Opencl::Platform::Pcl_char options, Tcl_programbuilt_notify pfn_notify, void * user_data);
extern "C" Opencl::Platform::Tcl_int __stdcall clCompileProgram(Pcl_program _program, Opencl::Platform::Tcl_uint num_devices, Pcl_device_id device_list, Opencl::Platform::Pcl_char options, Opencl::Platform::Tcl_uint num_input_headers, Pcl_program input_headers, System::PPAnsiChar header_include_names, Tcl_programbuilt_notify pfn_notify, void * user_data);
extern "C" Pcl_program __stdcall clLinkProgram(Pcl_context context, Opencl::Platform::Tcl_uint num_devices, Pcl_device_id device_list, Opencl::Platform::Pcl_char options, Opencl::Platform::Pcl_uint num_input_programs, Pcl_program input_programs, Tcl_programbuilt_notify pfn_notify, void * user_data, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clUnloadPlatformCompiler(void);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetProgramInfo(Pcl_program _program, Tcl_program_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetProgramBuildInfo(Pcl_program _program, Pcl_device_id device, Tcl_program_build_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Pcl_kernel __stdcall clCreateKernel(Pcl_program _program, char * kernel_name, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clCreateKernelsInProgram(Pcl_program _program, Opencl::Platform::Tcl_uint num_kernels, Pcl_kernel kernels, Opencl::Platform::Pcl_uint num_kernels_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clCloneKernel(Pcl_kernel source_kernel, Opencl::Platform::Pcl_int errocode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clRetainKernel(Pcl_kernel kernel);
extern "C" Opencl::Platform::Tcl_int __stdcall clReleaseKernel(Pcl_kernel kernel);
extern "C" Opencl::Platform::Tcl_int __stdcall clSetKernelArg(Pcl_kernel kernel, Opencl::Platform::Tcl_uint arg_index, System::NativeUInt arg_size, void * arg_value);
extern "C" Opencl::Platform::Tcl_int __stdcall clSetKernelArgSVMPointer(Pcl_kernel kernel, Opencl::Platform::Tcl_uint arg_index, void * arg_value);
extern "C" Opencl::Platform::Tcl_int __stdcall clSetKernelExecInfo(Pcl_kernel kernel, Tcl_kernel_exec_info param_name, System::NativeUInt param_value_size, void * param_value);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetKernelInfo(Pcl_kernel kernel, Tcl_kernel_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetKernelArgInfo(Pcl_kernel kernel, Opencl::Platform::Tcl_uint arg_indx, Tcl_kernel_arg_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetKernelWorkGroupInfo(Pcl_kernel kernel, Pcl_device_id device, Tcl_kernel_work_group_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetKernelSubGroupInfo(Pcl_kernel kernel, Pcl_device_id device, Tcl_kernel_sub_group_info param_name, System::NativeUInt input_value_size, void * input_value, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clWaitForEvents(Opencl::Platform::Tcl_uint num_events, Pcl_event event_list);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetEventInfo(Pcl_event event, Tcl_event_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Pcl_event __stdcall clCreateUserEvent(Pcl_context context, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clRetainEvent(Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clReleaseEvent(Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clSetUserEventStatus(Pcl_event event, Opencl::Platform::Tcl_int execution_status);
extern "C" Opencl::Platform::Tcl_int __stdcall clSetEventCallback(Pcl_event event, Opencl::Platform::Tcl_int command_exec_callback_type, Tcl_event_notify pfn_notify, void * user_data);
extern "C" Opencl::Platform::Tcl_int __stdcall clGetEventProfilingInfo(Pcl_event event, Tcl_profiling_info param_name, System::NativeUInt param_value_size, void * param_value, Opencl::Platform::Psize_t param_value_size_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clFlush(Pcl_command_queue command_queue);
extern "C" Opencl::Platform::Tcl_int __stdcall clFinish(Pcl_command_queue command_queue);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueReadBuffer(Pcl_command_queue command_queue, Pcl_mem buffer, Tcl_bool blocking_read, System::NativeUInt offset, System::NativeUInt size, void * ptr, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueReadBufferRect(Pcl_command_queue command_queue, Pcl_mem buffer, Tcl_bool blocking_read, Opencl::Platform::Psize_t buffer_offset, Opencl::Platform::Psize_t host_offset, Opencl::Platform::Psize_t region, System::NativeUInt buffer_row_pitch, System::NativeUInt buffer_slice_pitch, System::NativeUInt host_row_pitch, System::NativeUInt host_slice_pitch, void * ptr, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueWriteBuffer(Pcl_command_queue command_queue, Pcl_mem buffer, Tcl_bool blocking_write, System::NativeUInt offset, System::NativeUInt size, void * ptr, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueWriteBufferRect(Pcl_command_queue command_queue, Pcl_mem buffer, Tcl_bool blocking_write, Opencl::Platform::Psize_t buffer_offset, Opencl::Platform::Psize_t host_offset, Opencl::Platform::Psize_t region, System::NativeUInt buffer_row_pitch, System::NativeUInt buffer_slice_pitch, System::NativeUInt host_row_pitch, System::NativeUInt host_slice_pitch, void * ptr, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueFillBuffer(Pcl_command_queue command_queue, Pcl_mem buffer, void * pattern, System::NativeUInt pattern_size, System::NativeUInt offset, System::NativeUInt size, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueCopyBuffer(Pcl_command_queue command_queue, Pcl_mem src_buffer, Pcl_mem dst_buffer, System::NativeUInt src_offset, System::NativeUInt dst_offset, System::NativeUInt size, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueCopyBufferRect(Pcl_command_queue command_queue, Pcl_mem src_buffer, Pcl_mem dst_buffer, System::NativeUInt src_offset, System::NativeUInt dst_offset, System::NativeUInt region, System::NativeUInt src_row_pitch, System::NativeUInt src_slice_pitch, System::NativeUInt dst_row_pitch, System::NativeUInt dst_slice_pitch, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueReadImage(Pcl_command_queue command_queue, Pcl_mem image, Tcl_bool blocking_read, Opencl::Platform::Psize_t origin, Opencl::Platform::Psize_t region, System::NativeUInt row_pitch, System::NativeUInt slice_pitch, void * ptr, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueWriteImage(Pcl_command_queue command_queue, Pcl_mem image, Tcl_bool blocking_write, Opencl::Platform::Psize_t origin, Opencl::Platform::Psize_t region, System::NativeUInt input_row_pitch, System::NativeUInt input_slice_pitch, void * ptr, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueFillImage(Pcl_command_queue command_queue, Pcl_mem image, void * fill_color, Opencl::Platform::Psize_t origin, Opencl::Platform::Psize_t region, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueCopyImage(Pcl_command_queue command_queue, Pcl_mem src_image, Pcl_mem dst_image, Opencl::Platform::Psize_t src_origin, Opencl::Platform::Psize_t dst_origin, Opencl::Platform::Psize_t region, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueCopyImageToBuffer(Pcl_command_queue command_queue, Pcl_mem src_image, Pcl_mem dst_buffer, Opencl::Platform::Psize_t src_origin, Opencl::Platform::Psize_t region, System::NativeUInt dst_offset, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueCopyBufferToImage(Pcl_command_queue command_queue, Pcl_mem src_buffer, Pcl_mem dst_image, System::NativeUInt src_offset, Opencl::Platform::Psize_t dst_origin, Opencl::Platform::Psize_t region, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" void * __stdcall clEnqueueMapBuffer(Pcl_command_queue command_queue, Pcl_mem buffer, Pcl_bool blocking_map, Tcl_map_flags map_flags, System::NativeUInt offset, System::NativeUInt cb, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event, Opencl::Platform::Pcl_int errcode_ret);
extern "C" void * __stdcall clEnqueueMapImage(Pcl_command_queue command_queue, Pcl_mem image, Tcl_bool blocking_map, Tcl_map_flags map_flags, Opencl::Platform::Psize_t origin, Opencl::Platform::Psize_t region, Opencl::Platform::Psize_t image_row_pitch, Opencl::Platform::Psize_t image_slice_pitch, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event, Opencl::Platform::Pcl_int errcode_ret);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueUnmapMemObject(Pcl_command_queue command_queue, Pcl_mem memobj, void * mapped_ptr, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueMigrateMemObjects(Pcl_command_queue command_queue, Opencl::Platform::Tcl_uint num_mem_objects, Pcl_mem mem_objects, Tcl_mem_flags flags, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueNDRangeKernel(Pcl_command_queue command_queue, Pcl_kernel kernel, Opencl::Platform::Tcl_uint work_dim, Opencl::Platform::Psize_t global_work_offset, Opencl::Platform::Psize_t global_work_size, Opencl::Platform::Psize_t local_work_size, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueNativeKernel(Pcl_command_queue command_queue, Tcl_EnqueueNativeKernel user_func, void * args, System::NativeUInt cb_args, Opencl::Platform::Tcl_uint num_mem_objects, Pcl_mem mem_list, System::PPointer args_mem_loc, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueMarkerWithWaitList(Pcl_command_queue command_queue, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueBarrierWithWaitList(Pcl_command_queue command_queue, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueSVMFree(Pcl_command_queue command_queue, Opencl::Platform::Tcl_uint num_svm_pointers, void * args, Tcl_EnqueueSVM_fn pfn_free_func, void * user_data, Pcl_mem mem_list, System::PPointer args_mem_loc, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueSVMMemcpy(Pcl_command_queue command_queue, Opencl::Platform::Tcl_uint num_svm_pointers, void * args, void * user_data, Pcl_mem mem_list, System::PPointer args_mem_loc, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueSVMMap(Pcl_command_queue command_queue, Opencl::Platform::Tcl_uint num_svm_pointers, void * args, void * user_data, Pcl_mem mem_list, System::PPointer args_mem_loc, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueSVMUnmap(Pcl_command_queue command_queue, void * svm_ptr, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueSVMmigrateMem(Pcl_command_queue command_queue, Opencl::Platform::Tcl_uint num_svm_pointers, System::PPointer svm_pointers, Opencl::Platform::Psize_t sizes, Tcl_mem_flags flags, Opencl::Platform::Tcl_uint num_events_in_wait_list, Pcl_event event_wait_list, Pcl_event event);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueWaitForEvents(Pcl_command_queue command_queue, Opencl::Platform::Tcl_uint num_events, Pcl_event event_list);
extern "C" Opencl::Platform::Tcl_int __stdcall clEnqueueBarrier(Pcl_command_queue command_queue);
extern "C" void * __stdcall clGetExtensionFunctionAddressForPlatform(Pcl_platform_id _platform, Opencl::Platform::Pcl_char func_name);
extern DELPHI_PACKAGE bool __fastcall InitOpenCL(void);
extern DELPHI_PACKAGE void __fastcall CloseOpenCL(void);
extern DELPHI_PACKAGE bool __fastcall InitFromLibraryOpenCL(const System::WideString CLName);
extern DELPHI_PACKAGE bool __fastcall IsInitializedOpenCL(void);
}	/* namespace Import */
}	/* namespace Opencl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_OPENCL_IMPORT)
using namespace Opencl::Import;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_OPENCL)
using namespace Opencl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OpenCL_ImportHPP

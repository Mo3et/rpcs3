#pragma once

#include "Emu/PSP2/ErrorCodes.h"
#include "Emu/PSP2/Modules/Common.h"

// Kernel internal TLS manager (TODO)
class arm_tls_manager
{
	std::array<atomic_t<bool>, 128> m_map{};

public:
	const u32 vaddr;
	const u32 fsize;
	const u32 vsize;
	const u32 start;

	// Initialize from ELF process parameters
	arm_tls_manager(u32 vaddr, u32 fsize, u32 vsize);

	// Allocate and initialize TLS
	u32 alloc();

	// Deallocate by address
	void free(u32 addr);
};

// Error Codes
enum SceLibKernelError : u32
{
	SCE_KERNEL_ERROR_ERROR                                        = 0x80020001,
	SCE_KERNEL_ERROR_NOT_IMPLEMENTED                              = 0x80020002,
	SCE_KERNEL_ERROR_INVALID_ARGUMENT                             = 0x80020003,
	SCE_KERNEL_ERROR_INVALID_ARGUMENT_SIZE                        = 0x80020004,
	SCE_KERNEL_ERROR_INVALID_FLAGS                                = 0x80020005,
	SCE_KERNEL_ERROR_ILLEGAL_SIZE                                 = 0x80020006,
	SCE_KERNEL_ERROR_ILLEGAL_ADDR                                 = 0x80020007,
	SCE_KERNEL_ERROR_UNSUP                                        = 0x80020008,
	SCE_KERNEL_ERROR_ILLEGAL_MODE                                 = 0x80020009,
	SCE_KERNEL_ERROR_ILLEGAL_ALIGNMENT                            = 0x8002000A,
	SCE_KERNEL_ERROR_NOSYS                                        = 0x8002000B,
	SCE_KERNEL_ERROR_DEBUG_ERROR                                  = 0x80021000,
	SCE_KERNEL_ERROR_ILLEGAL_DIPSW_NUMBER                         = 0x80021001,
	SCE_KERNEL_ERROR_CPU_ERROR                                    = 0x80022000,
	SCE_KERNEL_ERROR_MMU_ILLEGAL_L1_TYPE                          = 0x80022001,
	SCE_KERNEL_ERROR_MMU_L2_INDEX_OVERFLOW                        = 0x80022002,
	SCE_KERNEL_ERROR_MMU_L2_SIZE_OVERFLOW                         = 0x80022003,
	SCE_KERNEL_ERROR_INVALID_CPU_AFFINITY                         = 0x80022004,
	SCE_KERNEL_ERROR_INVALID_MEMORY_ACCESS                        = 0x80022005,
	SCE_KERNEL_ERROR_INVALID_MEMORY_ACCESS_PERMISSION             = 0x80022006,
	SCE_KERNEL_ERROR_VA2PA_FAULT                                  = 0x80022007,
	SCE_KERNEL_ERROR_VA2PA_MAPPED                                 = 0x80022008,
	SCE_KERNEL_ERROR_VALIDATION_CHECK_FAILED                      = 0x80022009,
	SCE_KERNEL_ERROR_SYSMEM_ERROR                                 = 0x80024000,
	SCE_KERNEL_ERROR_INVALID_PROCESS_CONTEXT                      = 0x80024001,
	SCE_KERNEL_ERROR_UID_NAME_TOO_LONG                            = 0x80024002,
	SCE_KERNEL_ERROR_VARANGE_IS_NOT_PHYSICAL_CONTINUOUS           = 0x80024003,
	SCE_KERNEL_ERROR_PHYADDR_ERROR                                = 0x80024100,
	SCE_KERNEL_ERROR_NO_PHYADDR                                   = 0x80024101,
	SCE_KERNEL_ERROR_PHYADDR_USED                                 = 0x80024102,
	SCE_KERNEL_ERROR_PHYADDR_NOT_USED                             = 0x80024103,
	SCE_KERNEL_ERROR_NO_IOADDR                                    = 0x80024104,
	SCE_KERNEL_ERROR_PHYMEM_ERROR                                 = 0x80024300,
	SCE_KERNEL_ERROR_ILLEGAL_PHYPAGE_STATUS                       = 0x80024301,
	SCE_KERNEL_ERROR_NO_FREE_PHYSICAL_PAGE                        = 0x80024302,
	SCE_KERNEL_ERROR_NO_FREE_PHYSICAL_PAGE_UNIT                   = 0x80024303,
	SCE_KERNEL_ERROR_PHYMEMPART_NOT_EMPTY                         = 0x80024304,
	SCE_KERNEL_ERROR_NO_PHYMEMPART_LPDDR2                         = 0x80024305,
	SCE_KERNEL_ERROR_NO_PHYMEMPART_CDRAM                          = 0x80024306,
	SCE_KERNEL_ERROR_FIXEDHEAP_ERROR                              = 0x80024400,
	SCE_KERNEL_ERROR_FIXEDHEAP_ILLEGAL_SIZE                       = 0x80024401,
	SCE_KERNEL_ERROR_FIXEDHEAP_ILLEGAL_INDEX                      = 0x80024402,
	SCE_KERNEL_ERROR_FIXEDHEAP_INDEX_OVERFLOW                     = 0x80024403,
	SCE_KERNEL_ERROR_FIXEDHEAP_NO_CHUNK                           = 0x80024404,
	SCE_KERNEL_ERROR_UID_ERROR                                    = 0x80024500,
	SCE_KERNEL_ERROR_INVALID_UID                                  = 0x80024501,
	SCE_KERNEL_ERROR_SYSMEM_UID_INVALID_ARGUMENT                  = 0x80024502,
	SCE_KERNEL_ERROR_SYSMEM_INVALID_UID_RANGE                     = 0x80024503,
	SCE_KERNEL_ERROR_SYSMEM_NO_VALID_UID                          = 0x80024504,
	SCE_KERNEL_ERROR_SYSMEM_CANNOT_ALLOCATE_UIDENTRY              = 0x80024505,
	SCE_KERNEL_ERROR_NOT_PROCESS_UID                              = 0x80024506,
	SCE_KERNEL_ERROR_NOT_KERNEL_UID                               = 0x80024507,
	SCE_KERNEL_ERROR_INVALID_UID_CLASS                            = 0x80024508,
	SCE_KERNEL_ERROR_INVALID_UID_SUBCLASS                         = 0x80024509,
	SCE_KERNEL_ERROR_UID_CANNOT_FIND_BY_NAME                      = 0x8002450A,
	SCE_KERNEL_ERROR_VIRPAGE_ERROR                                = 0x80024600,
	SCE_KERNEL_ERROR_ILLEGAL_VIRPAGE_TYPE                         = 0x80024601,
	SCE_KERNEL_ERROR_BLOCK_ERROR                                  = 0x80024700,
	SCE_KERNEL_ERROR_ILLEGAL_BLOCK_ID                             = 0x80024701,
	SCE_KERNEL_ERROR_ILLEGAL_BLOCK_TYPE                           = 0x80024702,
	SCE_KERNEL_ERROR_BLOCK_IN_USE                                 = 0x80024703,
	SCE_KERNEL_ERROR_PARTITION_ERROR                              = 0x80024800,
	SCE_KERNEL_ERROR_ILLEGAL_PARTITION_ID                         = 0x80024801,
	SCE_KERNEL_ERROR_ILLEGAL_PARTITION_INDEX                      = 0x80024802,
	SCE_KERNEL_ERROR_NO_L2PAGETABLE                               = 0x80024803,
	SCE_KERNEL_ERROR_HEAPLIB_ERROR                                = 0x80024900,
	SCE_KERNEL_ERROR_ILLEGAL_HEAP_ID                              = 0x80024901,
	SCE_KERNEL_ERROR_OUT_OF_RANG                                  = 0x80024902,
	SCE_KERNEL_ERROR_HEAPLIB_NOMEM                                = 0x80024903,
	SCE_KERNEL_ERROR_SYSMEM_ADDRESS_SPACE_ERROR                   = 0x80024A00,
	SCE_KERNEL_ERROR_INVALID_ADDRESS_SPACE_ID                     = 0x80024A01,
	SCE_KERNEL_ERROR_INVALID_PARTITION_INDEX                      = 0x80024A02,
	SCE_KERNEL_ERROR_ADDRESS_SPACE_CANNOT_FIND_PARTITION_BY_ADDR  = 0x80024A03,
	SCE_KERNEL_ERROR_SYSMEM_MEMBLOCK_ERROR                        = 0x80024B00,
	SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK_TYPE                        = 0x80024B01,
	SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK_REMAP_TYPE                  = 0x80024B02,
	SCE_KERNEL_ERROR_NOT_PHY_CONT_MEMBLOCK                        = 0x80024B03,
	SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK_CODE                        = 0x80024B04,
	SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK_SIZE                        = 0x80024B05,
	SCE_KERNEL_ERROR_ILLEGAL_USERMAP_SIZE                         = 0x80024B06,
	SCE_KERNEL_ERROR_MEMBLOCK_TYPE_FOR_KERNEL_PROCESS             = 0x80024B07,
	SCE_KERNEL_ERROR_PROCESS_CANNOT_REMAP_MEMBLOCK                = 0x80024B08,
	SCE_KERNEL_ERROR_SYSMEM_PHYMEMLOW_ERROR                       = 0x80024C00,
	SCE_KERNEL_ERROR_CANNOT_ALLOC_PHYMEMLOW                       = 0x80024C01,
	SCE_KERNEL_ERROR_UNKNOWN_PHYMEMLOW_TYPE                       = 0x80024C02,
	SCE_KERNEL_ERROR_SYSMEM_BITHEAP_ERROR                         = 0x80024D00,
	SCE_KERNEL_ERROR_CANNOT_ALLOC_BITHEAP                         = 0x80024D01,
	SCE_KERNEL_ERROR_LOADCORE_ERROR                               = 0x80025000,
	SCE_KERNEL_ERROR_ILLEGAL_ELF_HEADER                           = 0x80025001,
	SCE_KERNEL_ERROR_ILLEGAL_SELF_HEADER                          = 0x80025002,
	SCE_KERNEL_ERROR_EXCPMGR_ERROR                                = 0x80027000,
	SCE_KERNEL_ERROR_ILLEGAL_EXCPCODE                             = 0x80027001,
	SCE_KERNEL_ERROR_ILLEGAL_EXCPHANDLER                          = 0x80027002,
	SCE_KERNEL_ERROR_NOTFOUND_EXCPHANDLER                         = 0x80027003,
	SCE_KERNEL_ERROR_CANNOT_RELEASE_EXCPHANDLER                   = 0x80027004,
	SCE_KERNEL_ERROR_INTRMGR_ERROR                                = 0x80027100,
	SCE_KERNEL_ERROR_ILLEGAL_CONTEXT                              = 0x80027101,
	SCE_KERNEL_ERROR_ILLEGAL_INTRCODE                             = 0x80027102,
	SCE_KERNEL_ERROR_ILLEGAL_INTRPARAM                            = 0x80027103,
	SCE_KERNEL_ERROR_ILLEGAL_INTRPRIORITY                         = 0x80027104,
	SCE_KERNEL_ERROR_ILLEGAL_TARGET_CPU                           = 0x80027105,
	SCE_KERNEL_ERROR_ILLEGAL_INTRFILTER                           = 0x80027106,
	SCE_KERNEL_ERROR_ILLEGAL_INTRTYPE                             = 0x80027107,
	SCE_KERNEL_ERROR_ILLEGAL_HANDLER                              = 0x80027108,
	SCE_KERNEL_ERROR_FOUND_HANDLER                                = 0x80027109,
	SCE_KERNEL_ERROR_NOTFOUND_HANDLER                             = 0x8002710A,
	SCE_KERNEL_ERROR_NO_MEMORY                                    = 0x8002710B,
	SCE_KERNEL_ERROR_DMACMGR_ERROR                                = 0x80027200,
	SCE_KERNEL_ERROR_ALREADY_QUEUED                               = 0x80027201,
	SCE_KERNEL_ERROR_NOT_QUEUED                                   = 0x80027202,
	SCE_KERNEL_ERROR_NOT_SETUP                                    = 0x80027203,
	SCE_KERNEL_ERROR_ON_TRANSFERRING                              = 0x80027204,
	SCE_KERNEL_ERROR_NOT_INITIALIZED                              = 0x80027205,
	SCE_KERNEL_ERROR_TRANSFERRED                                  = 0x80027206,
	SCE_KERNEL_ERROR_NOT_UNDER_CONTROL                            = 0x80027207,
	SCE_KERNEL_ERROR_SYSTIMER_ERROR                               = 0x80027300,
	SCE_KERNEL_ERROR_NO_FREE_TIMER                                = 0x80027301,
	SCE_KERNEL_ERROR_TIMER_NOT_ALLOCATED                          = 0x80027302,
	SCE_KERNEL_ERROR_TIMER_COUNTING                               = 0x80027303,
	SCE_KERNEL_ERROR_TIMER_STOPPED                                = 0x80027304,
	SCE_KERNEL_ERROR_THREADMGR_ERROR                              = 0x80028000,
	SCE_KERNEL_ERROR_DORMANT                                      = 0x80028001,
	SCE_KERNEL_ERROR_NOT_DORMANT                                  = 0x80028002,
	SCE_KERNEL_ERROR_UNKNOWN_THID                                 = 0x80028003,
	SCE_KERNEL_ERROR_CAN_NOT_WAIT                                 = 0x80028004,
	SCE_KERNEL_ERROR_ILLEGAL_THID                                 = 0x80028005,
	SCE_KERNEL_ERROR_THREAD_TERMINATED                            = 0x80028006,
	SCE_KERNEL_ERROR_DELETED                                      = 0x80028007,
	SCE_KERNEL_ERROR_WAIT_TIMEOUT                                 = 0x80028008,
	SCE_KERNEL_ERROR_NOTIFY_CALLBACK                              = 0x80028009,
	SCE_KERNEL_ERROR_WAIT_DELETE                                  = 0x8002800A,
	SCE_KERNEL_ERROR_ILLEGAL_ATTR                                 = 0x8002800B,
	SCE_KERNEL_ERROR_EVF_MULTI                                    = 0x8002800C,
	SCE_KERNEL_ERROR_WAIT_CANCEL                                  = 0x8002800D,
	SCE_KERNEL_ERROR_EVF_COND                                     = 0x8002800E,
	SCE_KERNEL_ERROR_ILLEGAL_COUNT                                = 0x8002800F,
	SCE_KERNEL_ERROR_ILLEGAL_PRIORITY                             = 0x80028010,
	SCE_KERNEL_ERROR_MUTEX_RECURSIVE                              = 0x80028011,
	SCE_KERNEL_ERROR_MUTEX_LOCK_OVF                               = 0x80028012,
	SCE_KERNEL_ERROR_MUTEX_NOT_OWNED                              = 0x80028013,
	SCE_KERNEL_ERROR_MUTEX_UNLOCK_UDF                             = 0x80028014,
	SCE_KERNEL_ERROR_MUTEX_FAILED_TO_OWN                          = 0x80028015,
	SCE_KERNEL_ERROR_FAST_MUTEX_RECURSIVE                         = 0x80028016,
	SCE_KERNEL_ERROR_FAST_MUTEX_LOCK_OVF                          = 0x80028017,
	SCE_KERNEL_ERROR_FAST_MUTEX_FAILED_TO_OWN                     = 0x80028018,
	SCE_KERNEL_ERROR_FAST_MUTEX_NOT_OWNED                         = 0x80028019,
	SCE_KERNEL_ERROR_FAST_MUTEX_OWNED                             = 0x8002801A,
	SCE_KERNEL_ERROR_ALARM_CAN_NOT_CANCEL                         = 0x8002801B,
	SCE_KERNEL_ERROR_INVALID_OBJECT_TYPE                          = 0x8002801C,
	SCE_KERNEL_ERROR_KERNEL_TLS_FULL                              = 0x8002801D,
	SCE_KERNEL_ERROR_ILLEGAL_KERNEL_TLS_INDEX                     = 0x8002801E,
	SCE_KERNEL_ERROR_KERNEL_TLS_BUSY                              = 0x8002801F,
	SCE_KERNEL_ERROR_DIFFERENT_UID_CLASS                          = 0x80028020,
	SCE_KERNEL_ERROR_UNKNOWN_UID                                  = 0x80028021,
	SCE_KERNEL_ERROR_SEMA_ZERO                                    = 0x80028022,
	SCE_KERNEL_ERROR_SEMA_OVF                                     = 0x80028023,
	SCE_KERNEL_ERROR_PMON_NOT_THREAD_MODE                         = 0x80028024,
	SCE_KERNEL_ERROR_PMON_NOT_CPU_MODE                            = 0x80028025,
	SCE_KERNEL_ERROR_ALREADY_REGISTERED                           = 0x80028026,
	SCE_KERNEL_ERROR_INVALID_THREAD_ID                            = 0x80028027,
	SCE_KERNEL_ERROR_ALREADY_DEBUG_SUSPENDED                      = 0x80028028,
	SCE_KERNEL_ERROR_NOT_DEBUG_SUSPENDED                          = 0x80028029,
	SCE_KERNEL_ERROR_CAN_NOT_USE_VFP                              = 0x8002802A,
	SCE_KERNEL_ERROR_RUNNING                                      = 0x8002802B,
	SCE_KERNEL_ERROR_EVENT_COND                                   = 0x8002802C,
	SCE_KERNEL_ERROR_MSG_PIPE_FULL                                = 0x8002802D,
	SCE_KERNEL_ERROR_MSG_PIPE_EMPTY                               = 0x8002802E,
	SCE_KERNEL_ERROR_ALREADY_SENT                                 = 0x8002802F,
	SCE_KERNEL_ERROR_CAN_NOT_SUSPEND                              = 0x80028030,
	SCE_KERNEL_ERROR_FAST_MUTEX_ALREADY_INITIALIZED               = 0x80028031,
	SCE_KERNEL_ERROR_FAST_MUTEX_NOT_INITIALIZED                   = 0x80028032,
	SCE_KERNEL_ERROR_THREAD_STOPPED                               = 0x80028033,
	SCE_KERNEL_ERROR_THREAD_SUSPENDED                             = 0x80028034,
	SCE_KERNEL_ERROR_NOT_SUSPENDED                                = 0x80028035,
	SCE_KERNEL_ERROR_WAIT_DELETE_MUTEX                            = 0x80028036,
	SCE_KERNEL_ERROR_WAIT_CANCEL_MUTEX                            = 0x80028037,
	SCE_KERNEL_ERROR_WAIT_DELETE_COND                             = 0x80028038,
	SCE_KERNEL_ERROR_WAIT_CANCEL_COND                             = 0x80028039,
	SCE_KERNEL_ERROR_LW_MUTEX_NOT_OWNED                           = 0x8002803A,
	SCE_KERNEL_ERROR_LW_MUTEX_LOCK_OVF                            = 0x8002803B,
	SCE_KERNEL_ERROR_LW_MUTEX_UNLOCK_UDF                          = 0x8002803C,
	SCE_KERNEL_ERROR_LW_MUTEX_RECURSIVE                           = 0x8002803D,
	SCE_KERNEL_ERROR_LW_MUTEX_FAILED_TO_OWN                       = 0x8002803E,
	SCE_KERNEL_ERROR_WAIT_DELETE_LW_MUTEX                         = 0x8002803F,
	SCE_KERNEL_ERROR_ILLEGAL_STACK_SIZE                           = 0x80028040,
	SCE_KERNEL_ERROR_RW_LOCK_RECURSIVE                            = 0x80028041,
	SCE_KERNEL_ERROR_RW_LOCK_LOCK_OVF                             = 0x80028042,
	SCE_KERNEL_ERROR_RW_LOCK_NOT_OWNED                            = 0x80028043,
	SCE_KERNEL_ERROR_RW_LOCK_UNLOCK_UDF                           = 0x80028044,
	SCE_KERNEL_ERROR_RW_LOCK_FAILED_TO_LOCK                       = 0x80028045,
	SCE_KERNEL_ERROR_RW_LOCK_FAILED_TO_UNLOCK                     = 0x80028046,
	SCE_KERNEL_ERROR_PROCESSMGR_ERROR                             = 0x80029000,
	SCE_KERNEL_ERROR_INVALID_PID                                  = 0x80029001,
	SCE_KERNEL_ERROR_INVALID_PROCESS_TYPE                         = 0x80029002,
	SCE_KERNEL_ERROR_PLS_FULL                                     = 0x80029003,
	SCE_KERNEL_ERROR_INVALID_PROCESS_STATUS                       = 0x80029004,
	SCE_KERNEL_ERROR_INVALID_BUDGET_ID                            = 0x80029005,
	SCE_KERNEL_ERROR_INVALID_BUDGET_SIZE                          = 0x80029006,
	SCE_KERNEL_ERROR_CP14_DISABLED                                = 0x80029007,
	SCE_KERNEL_ERROR_EXCEEDED_MAX_PROCESSES                       = 0x80029008,
	SCE_KERNEL_ERROR_PROCESS_REMAINING                            = 0x80029009,
	SCE_KERNEL_ERROR_IOFILEMGR_ERROR                              = 0x8002A000,
	SCE_KERNEL_ERROR_IO_NAME_TOO_LONG                             = 0x8002A001,
	SCE_KERNEL_ERROR_IO_REG_DEV                                   = 0x8002A002,
	SCE_KERNEL_ERROR_IO_ALIAS_USED                                = 0x8002A003,
	SCE_KERNEL_ERROR_IO_DEL_DEV                                   = 0x8002A004,
	SCE_KERNEL_ERROR_IO_WOULD_BLOCK                               = 0x8002A005,
	SCE_KERNEL_ERROR_MODULEMGR_START_FAILED                       = 0x8002D000,
	SCE_KERNEL_ERROR_MODULEMGR_STOP_FAIL                          = 0x8002D001,
	SCE_KERNEL_ERROR_MODULEMGR_IN_USE                             = 0x8002D002,
	SCE_KERNEL_ERROR_MODULEMGR_NO_LIB                             = 0x8002D003,
	SCE_KERNEL_ERROR_MODULEMGR_SYSCALL_REG                        = 0x8002D004,
	SCE_KERNEL_ERROR_MODULEMGR_NOMEM_LIB                          = 0x8002D005,
	SCE_KERNEL_ERROR_MODULEMGR_NOMEM_STUB                         = 0x8002D006,
	SCE_KERNEL_ERROR_MODULEMGR_NOMEM_SELF                         = 0x8002D007,
	SCE_KERNEL_ERROR_MODULEMGR_NOMEM                              = 0x8002D008,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_LIB                        = 0x8002D009,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_STUB                       = 0x8002D00A,
	SCE_KERNEL_ERROR_MODULEMGR_NO_FUNC_NID                        = 0x8002D00B,
	SCE_KERNEL_ERROR_MODULEMGR_NO_VAR_NID                         = 0x8002D00C,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_TYPE                       = 0x8002D00D,
	SCE_KERNEL_ERROR_MODULEMGR_NO_MOD_ENTRY                       = 0x8002D00E,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_PROC_PARAM                 = 0x8002D00F,
	SCE_KERNEL_ERROR_MODULEMGR_NO_MODOBJ                          = 0x8002D010,
	SCE_KERNEL_ERROR_MODULEMGR_NO_MOD                             = 0x8002D011,
	SCE_KERNEL_ERROR_MODULEMGR_NO_PROCESS                         = 0x8002D012,
	SCE_KERNEL_ERROR_MODULEMGR_OLD_LIB                            = 0x8002D013,
	SCE_KERNEL_ERROR_MODULEMGR_STARTED                            = 0x8002D014,
	SCE_KERNEL_ERROR_MODULEMGR_NOT_STARTED                        = 0x8002D015,
	SCE_KERNEL_ERROR_MODULEMGR_NOT_STOPPED                        = 0x8002D016,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_PROCESS_UID                = 0x8002D017,
	SCE_KERNEL_ERROR_MODULEMGR_CANNOT_EXPORT_LIB_TO_SHARED        = 0x8002D018,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_REL_INFO                   = 0x8002D019,
	SCE_KERNEL_ERROR_MODULEMGR_INVALID_REF_INFO                   = 0x8002D01A,
	SCE_KERNEL_ERROR_MODULEMGR_ELINK                              = 0x8002D01B,
	SCE_KERNEL_ERROR_MODULEMGR_NOENT                              = 0x8002D01C,
	SCE_KERNEL_ERROR_MODULEMGR_BUSY                               = 0x8002D01D,
	SCE_KERNEL_ERROR_MODULEMGR_NOEXEC                             = 0x8002D01E,
	SCE_KERNEL_ERROR_MODULEMGR_NAMETOOLONG                        = 0x8002D01F,
	SCE_KERNEL_ERROR_LIBRARYDB_NOENT                              = 0x8002D080,
	SCE_KERNEL_ERROR_LIBRARYDB_NO_LIB                             = 0x8002D081,
	SCE_KERNEL_ERROR_LIBRARYDB_NO_MOD                             = 0x8002D082,
	SCE_KERNEL_ERROR_AUTHFAIL                                     = 0x8002F000,
	SCE_KERNEL_ERROR_NO_AUTH                                      = 0x8002F001,
};

// PSP2 UID Class
enum : u32
{
	SCE_KERNEL_UID_CLASS_PROCESS = 0,
	SCE_KERNEL_THREADMGR_UID_CLASS_THREAD = 1,
	SCE_KERNEL_THREADMGR_UID_CLASS_SEMA = 2,
	SCE_KERNEL_THREADMGR_UID_CLASS_EVENT_FLAG = 3,
	SCE_KERNEL_THREADMGR_UID_CLASS_MUTEX = 4,
	SCE_KERNEL_THREADMGR_UID_CLASS_COND = 5,
	SCE_KERNEL_THREADMGR_UID_CLASS_TIMER = 6,
	SCE_KERNEL_THREADMGR_UID_CLASS_MSG_PIPE = 7,
	SCE_KERNEL_THREADMGR_UID_CLASS_CALLBACK = 8,
	SCE_KERNEL_THREADMGR_UID_CLASS_THREAD_EVENT = 9,
};

union SceKernelSysClock
{
	struct
	{
		le_t<u32> low;
		le_t<u32> hi;
	}
	u;

	le_t<u64> quad;
};

struct SceKernelCallFrame
{
	le_t<u32> sp;
	le_t<u32> pc;
};

// Memory Manager definitions

struct SceKernelMemBlockInfo
{
	le_t<u32> size;
	vm::lptr<void> mappedBase;
	le_t<u32> mappedSize;
	le_t<s32> memoryType; // SceKernelMemoryType
	le_t<u32> access;
};

struct SceKernelAllocMemBlockOpt
{
	le_t<u32> size;
	le_t<u32> attr;
	le_t<u32> alignment;
	le_t<s32> uidBaseBlock;
	vm::lcptr<char> strBaseBlockName;
};

// Thread Manager definitions (threads)

enum
{
	SCE_KERNEL_ATTR_TH_FIFO = 0,
	SCE_KERNEL_ATTR_TH_PRIO = 0x2000,

	SCE_KERNEL_ATTR_SINGLE  = 0,      // Event Flag only
	SCE_KERNEL_ATTR_MULTI   = 0x1000, // Event Flag only
};

using SceKernelThreadEntry = s32(u32 argSize, vm::ptr<void> pArgBlock);

struct SceKernelThreadOptParam
{
	le_t<u32> size;
	le_t<u32> attr;
};

struct SceKernelThreadInfo
{
	le_t<u32> size;
	le_t<s32> processId;
	char name[32];
	le_t<u32> attr;
	le_t<u32> status;
	vm::lptr<SceKernelThreadEntry> entry;
	vm::lptr<void> pStack;
	le_t<u32> stackSize;
	le_t<s32> initPriority;
	le_t<s32> currentPriority;
	le_t<s32> initCpuAffinityMask;
	le_t<s32> currentCpuAffinityMask;
	le_t<s32> currentCpuId;
	le_t<s32> lastExecutedCpuId;
	le_t<u32> waitType;
	le_t<s32> waitId;
	le_t<s32> exitStatus;
	SceKernelSysClock runClocks;
	le_t<u32> intrPreemptCount;
	le_t<u32> threadPreemptCount;
	le_t<u32> threadReleaseCount;
	le_t<s32> changeCpuCount;
	le_t<s32> fNotifyCallback;
	le_t<s32> reserved;
};

struct SceKernelThreadRunStatus
{
	le_t<u32> size;

	struct
	{
		le_t<s32> processId;
		le_t<s32> threadId;
		le_t<s32> priority;

	} cpuInfo[4];
};

struct SceKernelSystemInfo
{
	le_t<u32> size;
	le_t<u32> activeCpuMask;

	struct
	{
		SceKernelSysClock idleClock;
		le_t<u32> comesOutOfIdleCount;
		le_t<u32> threadSwitchCount;

	} cpuInfo[4];
};

// Thread Manager definitions (callbacks)

using SceKernelCallbackFunction = s32(s32 notifyId, s32 notifyCount, s32 notifyArg, vm::ptr<void> pCommon);

struct SceKernelCallbackInfo
{
	le_t<u32> size;
	le_t<s32> callbackId;
	char name[32];
	le_t<u32> attr;
	le_t<s32> threadId;
	vm::lptr<SceKernelCallbackFunction> callbackFunc;
	le_t<s32> notifyId;
	le_t<s32> notifyCount;
	le_t<s32> notifyArg;
	vm::lptr<void> pCommon;
};

// Thread Manager definitions (events)

using SceKernelThreadEventHandler = s32(s32 type, s32 threadId, s32 arg, vm::ptr<void> pCommon);

struct SceKernelEventInfo
{
	le_t<u32> size;
	le_t<s32> eventId;
	char name[32];
	le_t<u32> attr;
	le_t<u32> eventPattern;
	le_t<u64> userData;
	le_t<u32> numWaitThreads;
	le_t<s32> reserved[1];
};

struct SceKernelWaitEvent
{
	le_t<s32> eventId;
	le_t<u32> eventPattern;
};

struct SceKernelResultEvent
{
	le_t<s32> eventId;
	le_t<s32> result;
	le_t<u32> resultPattern;
	le_t<s32> reserved[1];
	le_t<u64> userData;
};

// Thread Manager definitions (event flags)

enum : u32
{
	SCE_KERNEL_EVF_WAITMODE_AND       = 0x00000000,
	SCE_KERNEL_EVF_WAITMODE_OR        = 0x00000001,
	SCE_KERNEL_EVF_WAITMODE_CLEAR_ALL = 0x00000002,
	SCE_KERNEL_EVF_WAITMODE_CLEAR_PAT = 0x00000004,
};

struct SceKernelEventFlagOptParam
{
	le_t<u32> size;
};

struct SceKernelEventFlagInfo
{
	le_t<u32> size;
	le_t<s32> evfId;
	char name[32];
	le_t<u32> attr;
	le_t<u32> initPattern;
	le_t<u32> currentPattern;
	le_t<s32> numWaitThreads;
};

// Thread Manager definitions (semaphores)

struct SceKernelSemaOptParam
{
	le_t<u32> size;
};

struct SceKernelSemaInfo
{
	le_t<u32> size;
	le_t<s32> semaId;
	char name[32];
	le_t<u32> attr;
	le_t<s32> initCount;
	le_t<s32> currentCount;
	le_t<s32> maxCount;
	le_t<s32> numWaitThreads;
};

struct psp2_semaphore
{
	static const u32 id_base = 1;
	static const u32 id_step = 1;
	static const u32 id_count = 32767;

	const std::string name; // IPC Name

	atomic_t<u32> ref{}; // IPC Ref Counter

	const u32 attr;
	const s32 max;

	atomic_t<s32> count;

	psp2_semaphore(const char* name, u32 attr, s32 count, s32 max)
		: name(name)
		, attr(attr)
		, max(max)
		, count(count)
	{
	}
};

// Thread Manager definitions (mutexes)

struct SceKernelMutexOptParam
{
	le_t<u32> size;
	le_t<s32> ceilingPriority;
};

struct SceKernelMutexInfo
{
	le_t<u32> size;
	le_t<s32> mutexId;
	char name[32];
	le_t<u32> attr;
	le_t<s32> initCount;
	le_t<s32> currentCount;
	le_t<s32> currentOwnerId;
	le_t<s32> numWaitThreads;
};

struct psp2_mutex
{
	static const u32 id_base = 1;
	static const u32 id_step = 1;
	static const u32 id_count = 32767;

	const std::string name; // IPC Name

	atomic_t<u32> ref{}; // IPC Ref Counter

	const u32 attr;

	atomic_t<s32> count;

	psp2_mutex(const char* name, u32 attr, s32 count)
		: name(name)
		, attr(attr)
		, count(count)
	{
	}
};

// Thread Manager definitions (lightweight mutexes)

struct SceKernelLwMutexWork
{
	le_t<s32> data[4];
};

struct SceKernelLwMutexOptParam
{
	le_t<u32> size;
};

struct SceKernelLwMutexInfo
{
	le_t<u32> size;
	le_t<s32> uid;
	char name[32];
	le_t<u32> attr;
	vm::lptr<SceKernelLwMutexWork> pWork;
	le_t<s32> initCount;
	le_t<s32> currentCount;
	le_t<s32> currentOwnerId;
	le_t<s32> numWaitThreads;
};

// Thread Manager definitions (condition variables)

struct SceKernelCondOptParam
{
	le_t<u32> size;
};

struct SceKernelCondInfo
{
	le_t<u32> size;
	le_t<s32> condId;
	char name[32];
	le_t<u32> attr;
	le_t<s32> mutexId;
	le_t<u32> numWaitThreads;
};

struct psp2_cond
{
	static const u32 id_base = 1;
	static const u32 id_step = 1;
	static const u32 id_count = 32767;

	const std::string name; // IPC Name

	atomic_t<u32> ref{}; // IPC Ref Counter

	const u32 attr;

	const std::shared_ptr<psp2_mutex> mutex;

	psp2_cond(const char* name, u32 attr, const std::shared_ptr<psp2_mutex>& mutex)
		: name(name)
		, attr(attr)
		, mutex(mutex)
	{
	}
};

// Thread Manager definitions (lightweight condition variables)

struct SceKernelLwCondWork
{
	le_t<s32> data[4];
};

struct SceKernelLwCondOptParam
{
	le_t<u32> size;
};

struct SceKernelLwCondInfo
{
	le_t<u32> size;
	le_t<s32> uid;
	char name[32];
	le_t<u32> attr;
	vm::lptr<SceKernelLwCondWork> pWork;
	vm::lptr<SceKernelLwMutexWork> pLwMutex;
	le_t<u32> numWaitThreads;
};

// Thread Manager definitions (timers)

struct SceKernelTimerOptParam
{
	le_t<u32> size;
};

struct SceKernelTimerInfo
{
	le_t<u32> size;
	le_t<s32> timerId;
	char name[32];
	le_t<u32> attr;
	le_t<s32> fActive;
	SceKernelSysClock baseTime;
	SceKernelSysClock currentTime;
	SceKernelSysClock schedule;
	SceKernelSysClock interval;
	le_t<s32> type;
	le_t<s32> fRepeat;
	le_t<s32> numWaitThreads;
	le_t<s32> reserved[1];
};

// Thread Manager definitions (reader/writer locks)

struct SceKernelRWLockOptParam
{
	le_t<u32> size;
};

struct SceKernelRWLockInfo
{
	le_t<u32> size;
	le_t<s32> rwLockId;
	char name[32];
	le_t<u32> attr;
	le_t<s32> lockCount;
	le_t<s32> writeOwnerId;
	le_t<s32> numReadWaitThreads;
	le_t<s32> numWriteWaitThreads;
};

// IO/File Manager definitions

struct SceIoStat
{
	le_t<s32> mode;
	le_t<u32> attr;
	le_t<s64> size;
	SceDateTime ctime;
	SceDateTime atime;
	SceDateTime mtime;
	le_t<u64> _private[6];
};

struct SceIoDirent
{
	SceIoStat d_stat;
	char d_name[256];
	vm::lptr<void> d_private;
	le_t<s32> dummy;
};

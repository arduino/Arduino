/*--------------------------------------------------------*/
/* F02\Types.h                                            */
/*                                                        */
/* Copyright (c) 2009-2011 Texas Instruments Incorporated */
/*                                                        */
/* F021 Flash API v1.00                                   */
/*--------------------------------------------------------*/

/*!
    \file F021\Types.h
    \brief Types used by the F021 API.

    These are the types used by the F021 API.

*/

#ifndef F021_TYPES_H_
#define F021_TYPES_H_

/*****************************************************************************/
/* GLOBAL DEFINITIONS                                                        */
/*****************************************************************************/
#if defined(__TI_TMS470_V7__)
#if !defined(__GNUC__)
#error "F021 Flash API requires GCC language extensions enabled"
#endif
#endif

#if defined(__ICCARM__)             /* IAR EWARM Compiler */
#define ATTRIBUTE_PACKED  __packed
#elif defined(__TMS320C28XX__)      /* TI CGT C28xx compilers */
#define ATTRIBUTE_PACKED
#else                               /* all other compilers */
#define ATTRIBUTE_PACKED    __attribute__((packed))
#endif

#define CPU_TYPE_8          8
#define CPU_TYPE_16         16
#define CPU_TYPE_32         32

#define MSB_FIRST           0
#define LSB_FIRST           1

#define HIGH_BYTE_FIRST     0
#define LOW_BYTE_FIRST      1

#ifndef TRUE
   #define TRUE              1
#endif

#ifndef FALSE
   #define FALSE             0
#endif

/*****************************************************************************/
/* REGISTER WIDTH                                                            */
/*****************************************************************************/
#define CPU_TYPE            CPU_TYPE_32

/*****************************************************************************/
/* ENDIANESS                                                                 */
/*****************************************************************************/
#define CPU_BIT_ORDER       LSB_FIRST

#if defined(_LITTLE_ENDIAN)
   #define CPU_BYTE_ORDER    LOW_BYTE_FIRST
#else
   #define CPU_BYTE_ORDER    HIGH_BYTE_FIRST
#endif

/*****************************************************************************/
/* TYPE DEFINITIONS                                                          */
/*****************************************************************************/
#if defined(__TMS320C28XX__)

typedef unsigned char       boolean;

typedef unsigned int           uint8; //This is 16bits in C28x
typedef unsigned int           uint16;
typedef unsigned long int      uint32;
typedef unsigned long long int uint64;

typedef unsigned int        uint16_least;
typedef unsigned long int   uint32_least;

typedef signed int          sint16_least;
typedef signed long int     sint32_least;

#ifndef DSP28_DATA_TYPES
typedef float                    float32;
typedef long double              float64;
#endif

#else

typedef unsigned char       boolean;

typedef unsigned char          uint8;
typedef unsigned short         uint16;
typedef unsigned int           uint32;
typedef unsigned long long int uint64;

typedef signed char          sint8;
typedef signed short         sint16;
typedef signed int           sint32;
typedef signed long long int sint64;

typedef unsigned int        uint8_least;
typedef unsigned int        uint16_least;
typedef unsigned int        uint32_least;

typedef signed int          sint8_least;
typedef signed int          sint16_least;
typedef signed int          sint32_least;

#ifndef DSP28_DATA_TYPES
typedef float               float32;
typedef double              float64;
#endif

#endif 

#if FALSE != 0
#define false FALSE
#endif
#if TRUE != 1
#define true TRUE
#endif
/*!
    \brief This is used to indicate which Cpu is being used.
*/
typedef enum
{
   Fapi_MasterCpu,
   Fapi_SlaveCpu0
}  ATTRIBUTE_PACKED Fapi_CpuSelectorType;

/*!
    \brief This is used to indicate what type of Cpu is being used.
*/
typedef enum
{
   ARM7,
   M3,
   R4,
   R4F,
   C28,
   Undefined
}  ATTRIBUTE_PACKED Fapi_CpuType;

/*!
    \brief This is used to indicate what type of Family is being used.
*/
typedef enum
{
   Family_FMC       = 0x00,
   Family_L2FMC     = 0x10,
   Family_Sonata    = 0x20,
   Family_Stellaris = 0x30,
   Family_Future    = 0x40
} ATTRIBUTE_PACKED Fapi_FamilyType;

/*!
    \brief This is used to indicate what type of Address is being used.
*/
typedef enum
{
   Fapi_Flash,
   Fapi_FlashEcc,
   Fapi_Otp,
   Fapi_OtpEcc,
   Fapi_Undefined
}  ATTRIBUTE_PACKED Fapi_AddressMemoryType;

/*!
    \brief This is used to return the information from the engineering row in the TI OTP.
*/
typedef struct
{
   uint32 u32AsicId;
   uint8  u8Revision;
   uint32 u32LotNumber;
   uint16 u16FlowCheck;
   uint16 u16WaferNumber;
   uint16 u16XCoordinate;
   uint16 u16YCoordinate;
}  ATTRIBUTE_PACKED Fapi_EngineeringRowType;

typedef struct
{
   uint32 au32StatusWord[4];
}  ATTRIBUTE_PACKED Fapi_FlashStatusWordType;

/*!
    \brief This contains all the possible modes used in the Fapi_IssueAsyncProgrammingCommand().
*/
typedef enum
{
   Fapi_AutoEccGeneration, /* This is the default mode for the command and will auto generate the ecc for the provided data buffer */
   Fapi_DataOnly,       /* Command will only process the data buffer */
   Fapi_EccOnly,        /* Command will only process the ecc buffer */
   Fapi_DataAndEcc         /* Command will process data and ecc buffers */
}  ATTRIBUTE_PACKED Fapi_FlashProgrammingCommandsType;

/*!
    \brief This is used to indicate which Flash bank is being used.
*/
typedef enum
{
   Fapi_FlashBank0,
   Fapi_FlashBank1,
   Fapi_FlashBank2,
   Fapi_FlashBank3,
   Fapi_FlashBank4,
   Fapi_FlashBank5,
   Fapi_FlashBank6,
   Fapi_FlashBank7
}  ATTRIBUTE_PACKED Fapi_FlashBankType;

/*!
    \brief This is used to indicate what F021 Bank Technology the bank is
*/
typedef enum
{
    Fapi_FLEP,
    Fapi_FLEE,
    Fapi_FLES,
    Fapi_FLHV,
    Fapi_TechTBD
}  ATTRIBUTE_PACKED Fapi_FlashBankTechType;

/*!
    \brief This is used to indicate which Flash sector is being used.
*/
typedef enum
{
   Fapi_FlashSector0,
   Fapi_FlashSector1,
   Fapi_FlashSector2,
   Fapi_FlashSector3,
   Fapi_FlashSector4,
   Fapi_FlashSector5,
   Fapi_FlashSector6,
   Fapi_FlashSector7,
   Fapi_FlashSector8,
   Fapi_FlashSector9,
   Fapi_FlashSector10,
   Fapi_FlashSector11,
   Fapi_FlashSector12,
   Fapi_FlashSector13,
   Fapi_FlashSector14,
   Fapi_FlashSector15,
   Fapi_FlashSector16,
   Fapi_FlashSector17,
   Fapi_FlashSector18,
   Fapi_FlashSector19,
   Fapi_FlashSector20,
   Fapi_FlashSector21,
   Fapi_FlashSector22,
   Fapi_FlashSector23,
   Fapi_FlashSector24,
   Fapi_FlashSector25,
   Fapi_FlashSector26,
   Fapi_FlashSector27,
   Fapi_FlashSector28,
   Fapi_FlashSector29,
   Fapi_FlashSector30,
   Fapi_FlashSector31,
   Fapi_FlashSector32,
   Fapi_FlashSector33,
   Fapi_FlashSector34,
   Fapi_FlashSector35,
   Fapi_FlashSector36,
   Fapi_FlashSector37,
   Fapi_FlashSector38,
   Fapi_FlashSector39,
   Fapi_FlashSector40,
   Fapi_FlashSector41,
   Fapi_FlashSector42,
   Fapi_FlashSector43,
   Fapi_FlashSector44,
   Fapi_FlashSector45,
   Fapi_FlashSector46,
   Fapi_FlashSector47,
   Fapi_FlashSector48,
   Fapi_FlashSector49,
   Fapi_FlashSector50,
   Fapi_FlashSector51,
   Fapi_FlashSector52,
   Fapi_FlashSector53,
   Fapi_FlashSector54,
   Fapi_FlashSector55,
   Fapi_FlashSector56,
   Fapi_FlashSector57,
   Fapi_FlashSector58,
   Fapi_FlashSector59,
   Fapi_FlashSector60,
   Fapi_FlashSector61,
   Fapi_FlashSector62,
   Fapi_FlashSector63
}  ATTRIBUTE_PACKED Fapi_FlashSectorType;

/*!
    \brief This contains all the possible Flash State Machine commands.
*/
typedef enum
{
   Fapi_ProgramData    = 0x0002,
   Fapi_EraseSector    = 0x0006,
   Fapi_EraseBank      = 0x0008,
   Fapi_ValidateSector = 0x000E,
   Fapi_ClearStatus    = 0x0010,
   Fapi_ProgramResume  = 0x0014,
   Fapi_EraseResume    = 0x0016,
   Fapi_ClearMore      = 0x0018
}  ATTRIBUTE_PACKED Fapi_FlashStateCommandsType;

typedef  uint32 Fapi_FlashStatusType;

/*!
    \brief This contains all the possible Flash State Machine commands.
*/
typedef enum
{
   Fapi_NormalRead = 0x0,
   Fapi_RM0        = 0x1,
   Fapi_RM1        = 0x2
}  ATTRIBUTE_PACKED Fapi_FlashReadMarginModeType;

/*!
    \brief This is the master type containing all possible returned status codes.
*/
typedef enum
{
   Fapi_Status_Success=0,           /* Function completed successfully */
   Fapi_Status_FsmBusy,             /* FSM is Busy */
   Fapi_Status_FsmReady,            /* FSM is Ready */
   Fapi_Status_AsyncBusy,           /* Async function operation is Busy */
   Fapi_Status_AsyncComplete,       /* Async function operation is Complete */
   Fapi_Error_Fail=500,             /* Generic Function Fail code */
   Fapi_Error_StateMachineTimeout,  /* State machine polling never returned ready and timed out */
   Fapi_Error_OtpChecksumMismatch,  /* Returned if OTP checksum does not match expected value */
   Fapi_Error_InvalidDelayValue,    /* Returned if the Calculated RWAIT value exceeds 15  - Legacy Error */
   Fapi_Error_InvalidHclkValue,     /* Returned if FClk is above max FClk value - FClk is a calculated from HClk and RWAIT/EWAIT */
   Fapi_Error_InvalidCpu,           /* Returned if the specified Cpu does not exist */
   Fapi_Error_InvalidBank,          /* Returned if the specified bank does not exist */
   Fapi_Error_InvalidAddress,       /* Returned if the specified Address does not exist in Flash or OTP */
   Fapi_Error_InvalidReadMode,      /* Returned if the specified read mode does not exist */
   Fapi_Error_AsyncIncorrectDataBufferLength,
   Fapi_Error_AsyncIncorrectEccBufferLength,
   Fapi_Error_AsyncDataEccBufferLengthMismatch,
   Fapi_Error_FeatureNotAvailable  /* FMC feature is not available on this device */
}  ATTRIBUTE_PACKED Fapi_StatusType;

#if defined(_LITTLE_ENDIAN)
typedef union
{
	volatile struct
   {
#if defined (_C28X)
      uint16 ChecksumLength:16;  /* 0x150 bits 15:0 */
      uint16 OtpVersion:16;      /* 0x150 bits 31:16 */
      uint32 OtpChecksum;        /* 0x154 bits 31:0 */
      uint16 NumberOfBanks:16;   /* 0x158 bits 15:0 */
      uint16 NumberOfSectors:16; /* 0x158 bits 31:16 */
      uint16 MemorySize:16;      /* 0x15C bits 15:0 */
      uint16 Package:16;         /* 0x15C bits 31:16 */
      uint16 SiliconRevision:8;  /* 0x160 bits 7:0 */
      uint16 AsicNumber_23_8:8; /* 0x160 bits 31:8 */
      uint16 AsicNumber_31_24:16; /* 0x160 bits 31:8 */
      uint32 LotNumber;          /* 0x164 bits 31:0 */
      uint16 WaferNumber:16;     /* 0x168 bits 15:0 */
      uint16 Flowbits:16;        /* 0x168 bits 31:16 */
      uint16 YCoordinate:16;     /* 0x16C bits 15:0 */
      uint16 XCoordinate:16;     /* 0x16C bits 31:16 */
      uint16 EVSU:8;             /* 0x170 bits 7:0 */
      uint16 PVSU:8;             /* 0x170 bits 15:8 */
      uint16 ESU:8;              /* 0x170 bits 23:16 */
      uint16 PSU:8;              /* 0x170 bits 31:24 */
      uint16 CVSU:12;            /* 0x174 bits 11:0 */
      uint16 Add_EXEZSU:4;       /* 0x174 bits 15:12 */ 
      uint16 PVAcc:8;            /* 0x174 bits 23:16 */
      uint16 RVSU:8;             /* 0x174 bits 31:24 */
      uint16 PVH2:8;             /* 0x178 bits 7:0 */
      uint16 PVH:8;              /* 0x178 bits 15:8 */
      uint16 RH:8;               /* 0x178 bits 23:16 */
      uint16 PH:8;               /* 0x178 bits 31:24 */  
      uint16 SmFrequency:12;     /* 0x17C bits 11:0 */
      uint16 VSTAT:4;            /* 0x17C bits 15:12 */
      uint16 Sequence:8;         /* 0x17C bits 23:16 */
      uint16 EH:8;               /* 0x17C bits 31:24 */
      uint16 VHV_EStep:16;       /* 0x180 bits 15:0 */
      uint16 VHV_EStart:16;      /* 0x180 bits 31:16 */
      uint16 MAX_PP:16;          /* 0x184 bits 15:0 */
      uint16 OtpReserved1:16;    /* 0x184 bits 31:16 */
      uint16 PROG_PW:16;         /* 0x188 bits 15:0 */
      uint16 MAX_EP:16;          /* 0x188 bits 31:16 */
      uint32 ERA_PW;             /* 0x18C bits 31:0 */
      uint16 VHV_E:16;           /* 0x190 bits 15:0 */
      uint16 VHV_P:16;           /* 0x190 bits 31:16 */
      uint16 VINH:8;             /* 0x194 bits 7:0 */
      uint16 VCG:8;              /* 0x194 bits 15:8 */
      uint16 VHV_PV:16;          /* 0x194 bits 31:16 */
      uint16 OtpReserved2:8;     /* 0x198 bits 7:0 */
      uint16 VRead:8;            /* 0x198 bits 15:8 */
      uint16 VWL_P:8;            /* 0x198 bits 23:16 */
      uint16 VSL_P:8;            /* 0x198 bits 31:24 */
      uint32 ApiChecksum;        /* 0x19C bits 15:0 */ 
      uint32 OtpReserved3;    /* 0x1A0 bits 31:0 */
      uint32 OtpReserved4;    /* 0x1A4 bits 31:0 */
      uint32 OtpReserved5;    /* 0x1A8 bits 31:0 */
      uint32 OtpReserved6;    /* 0x1AC bits 31:0 */       
#else
      uint32 ChecksumLength:16;  /* 0x150 bits 15:0 */
      uint32 OtpVersion:16;      /* 0x150 bits 31:16 */
      uint32 OtpChecksum;        /* 0x154 bits 31:0 */
      uint32 NumberOfBanks:16;   /* 0x158 bits 15:0 */
      uint32 NumberOfSectors:16; /* 0x158 bits 31:16 */
      uint32 MemorySize:16;      /* 0x15C bits 15:0 */
      uint32 Package:16;         /* 0x15C bits 31:16 */
      uint32 SiliconRevision:8;  /* 0x160 bits 7:0 */
      uint32 AsicNumber:24;       /* 0x160 bits 31:8 */      
      uint32 LotNumber;          /* 0x164 bits 31:0 */
      uint32 WaferNumber:16;     /* 0x168 bits 15:0 */
      uint32 Flowbits:16;        /* 0x168 bits 31:16 */
      uint32 YCoordinate:16;     /* 0x16C bits 15:0 */
      uint32 XCoordinate:16;     /* 0x16C bits 31:16 */
      uint32 EVSU:8;             /* 0x170 bits 7:0 */
      uint32 PVSU:8;             /* 0x170 bits 15:8 */
      uint32 ESU:8;              /* 0x170 bits 23:16 */
      uint32 PSU:8;              /* 0x170 bits 31:24 */
      uint32 CVSU:12;            /* 0x174 bits 11:0 */
      uint32 Add_EXEZSU:4;       /* 0x174 bits 15:12 */ 
      uint32 PVAcc:8;            /* 0x174 bits 23:16 */
      uint32 RVSU:8;             /* 0x174 bits 31:24 */
      uint32 PVH2:8;             /* 0x178 bits 7:0 */
      uint32 PVH:8;              /* 0x178 bits 15:8 */
      uint32 RH:8;               /* 0x178 bits 23:16 */
      uint32 PH:8;               /* 0x178 bits 31:24 */  
      uint32 SmFrequency:12;     /* 0x17C bits 11:0 */
      uint32 VSTAT:4;            /* 0x17C bits 15:12 */
      uint32 Sequence:8;         /* 0x17C bits 23:16 */
      uint32 EH:8;               /* 0x17C bits 31:24 */
      uint32 VHV_EStep:16;       /* 0x180 bits 15:0 */
      uint32 VHV_EStart:16;      /* 0x180 bits 31:16 */
      uint32 MAX_PP:16;          /* 0x184 bits 15:0 */
      uint32 OtpReserved1:16;    /* 0x184 bits 31:16 */
      uint32 PROG_PW:16;         /* 0x188 bits 15:0 */
      uint32 MAX_EP:16;          /* 0x188 bits 31:16 */
      uint32 ERA_PW;             /* 0x18C bits 31:0 */
      uint32 VHV_E:16;           /* 0x190 bits 15:0 */
      uint32 VHV_P:16;           /* 0x190 bits 31:16 */
      uint32 VINH:8;             /* 0x194 bits 7:0 */
      uint32 VCG:8;              /* 0x194 bits 15:8 */
      uint32 VHV_PV:16;          /* 0x194 bits 31:16 */
      uint32 OtpReserved2:8;     /* 0x198 bits 7:0 */
      uint32 VRead:8;            /* 0x198 bits 15:8 */
      uint32 VWL_P:8;            /* 0x198 bits 23:16 */
      uint32 VSL_P:8;            /* 0x198 bits 31:24 */
      uint32 ApiChecksum:32;     /* 0x19C bits 31:0 */
      uint32 OtpReserved3:32;    /* 0x1A0 bits 31:0 */
      uint32 OtpReserved4:32;    /* 0x1A4 bits 31:0 */
      uint32 OtpReserved5:32;    /* 0x1A8 bits 31:0 */
      uint32 OtpReserved6:32;    /* 0x1AC bits 31:0 */
#endif        
   } OTP_VALUE;
   volatile uint8  au8OtpWord[0x60];
   volatile uint16 au16OtpWord[0x30];
   volatile uint32 au32OtpWord[0x18];
}Fapi_TiOtpBytesType;
#else
typedef union
{
	volatile struct
   {
      uint32 OtpVersion:16;      /* 0x150 bits 31:16 */
      uint32 ChecksumLength:16;  /* 0x150 bits 15:0 */
      uint32 OtpChecksum;        /* 0x154 bits 31:0 */
      uint32 NumberOfSectors:16; /* 0x158 bits 31:16 */
      uint32 NumberOfBanks:16;   /* 0x158 bits 15:0 */
      uint32 Package:16;         /* 0x15C bits 31:16 */
      uint32 MemorySize:16;      /* 0x15C bits 15:0 */
      uint32 AsicNumber:24;      /* 0x160 bits 31:8 */
      uint32 SiliconRevision:8;  /* 0x160 bits 7:0 */
      uint32 LotNumber;          /* 0x164 bits 31:0 */
      uint32 Flowbits:16;        /* 0x168 bits 31:16 */
      uint32 WaferNumber:16;     /* 0x168 bits 15:0 */
      uint32 XCoordinate:16;     /* 0x16C bits 31:16 */
      uint32 YCoordinate:16;     /* 0x16C bits 15:0 */
      uint32 PSU:8;              /* 0x170 bits 31:24 */
      uint32 ESU:8;              /* 0x170 bits 23:16 */
      uint32 PVSU:8;             /* 0x170 bits 15:8 */
      uint32 EVSU:8;             /* 0x170 bits 7:0 */
      uint32 RVSU:8;             /* 0x174 bits 31:24 */
      uint32 PVAcc:8;            /* 0x174 bits 23:16 */
      uint32 Add_EXEZSU:4;       /* 0x174 bits 15:12 */ 
      uint32 CVSU:12;            /* 0x174 bits 11:0 */
      uint32 PH:8;               /* 0x178 bits 31:24 */  
      uint32 RH:8;               /* 0x178 bits 23:16 */
      uint32 PVH:8;              /* 0x178 bits 15:8 */
      uint32 PVH2:8;             /* 0x178 bits 7:0 */
      uint32 EH:8;               /* 0x17C bits 31:24 */
      uint32 Sequence:8;         /* 0x17C bits 23:16 */
      uint32 VSTAT:4;            /* 0x17C bits 15:12 */
      uint32 SmFrequency:12;     /* 0x17C bits 11:0 */
      uint32 VHV_EStart:16;      /* 0x180 bits 31:16 */
      uint32 VHV_EStep:16;       /* 0x180 bits 15:0 */
      uint32 OtpReserved1:16;    /* 0x184 bits 31:16 */
      uint32 MAX_PP:16;          /* 0x184 bits 15:0 */
      uint32 MAX_EP:16;          /* 0x188 bits 31:16 */
      uint32 PROG_PW:16;         /* 0x188 bits 15:0 */
      uint32 ERA_PW;             /* 0x18C bits 31:0 */
      uint32 VHV_P:16;           /* 0x190 bits 31:16 */
      uint32 VHV_E:16;           /* 0x190 bits 15:0 */
      uint32 VHV_PV:16;          /* 0x194 bits 31:16 */
      uint32 VCG:8;              /* 0x194 bits 15:8 */
      uint32 VINH:8;             /* 0x194 bits 7:0 */
      uint32 VSL_P:8;            /* 0x198 bits 31:24 */
      uint32 VWL_P:8;            /* 0x198 bits 23:16 */
      uint32 VRead:8;            /* 0x198 bits 15:8 */
      uint32 OtpReserved2:8;     /* 0x198 bits 7:0 */
      uint32 ApiChecksum:32;     /* 0x19C bits 31:0 */
      uint32 OtpReserved3:32;    /* 0x1A0 bits 31:0 */
      uint32 OtpReserved4:32;    /* 0x1A4 bits 31:0 */
      uint32 OtpReserved5:32;    /* 0x1A8 bits 31:0 */
      uint32 OtpReserved6:32;    /* 0x1AC bits 31:0 */
   } OTP_VALUE;
   volatile uint8  au8OtpWord[0x60];
   volatile uint16 au16OtpWord[0x30];
   volatile uint32 au32OtpWord[0x18];
}Fapi_TiOtpBytesType;
#endif

typedef struct TI_OTP_TYPE
{
   Fapi_TiOtpBytesType aOtpBank[8];
}Fapi_TiOtpType;

/*!
    \brief
*/
typedef enum
{
   Alpha_Internal,          /* For internal TI use only.  Not intended to be used by customers */
   Alpha,                   /* Early Engineering release.  May not be functionally complete */
   Beta_Internal,           /* For internal TI use only.  Not intended to be used by customers */
   Beta,                    /* Functionally complete, to be used for testing and validation */
   Production               /* Fully validated, functionally complete, ready for production use */
}  ATTRIBUTE_PACKED Fapi_ApiProductionStatusType;

typedef struct
{
   uint8  u8ApiMajorVersion;
   uint8  u8ApiMinorVersion;
   uint8  u8ApiRevision;
   Fapi_ApiProductionStatusType oApiProductionStatus;
   uint32 u32ApiBuildNumber;
   uint8  u8ApiTechnologyType;
   uint8  u8ApiTechnologyRevision;
   uint8  u8ApiEndianness;
   uint32 u32ApiCompilerVersion;
} Fapi_LibraryInfoType;

typedef struct
{
#if defined(_LITTLE_ENDIAN)
   uint16 u16NumberOfBanks;
   uint16 u16Reserved;   
   uint16 u16DeviceMemorySize;
   uint16 u16DevicePackage;   
   uint32 u32AsicId;
   uint32 u32LotNumber;
   uint16 u16WaferNumber;
   uint16 u16FlowCheck;   
   uint16 u16WaferYCoordinate;
   uint16 u16WaferXCoordinate;   
#else	
   uint16 u16Reserved;	
   uint16 u16NumberOfBanks;
   uint16 u16DevicePackage;
   uint16 u16DeviceMemorySize;
   uint32 u32AsicId;
   uint32 u32LotNumber;
   uint16 u16FlowCheck;
   uint16 u16WaferNumber;
   uint16 u16WaferXCoordinate;
   uint16 u16WaferYCoordinate;
#endif
} Fapi_DeviceInfoType;

typedef struct
{
    Fapi_FlashBankTechType oFlashBankTech;
    uint32 u32NumberOfSectors;
    uint32 u32BankStartAddress;
    uint8  au8SectorSizes[16];
} Fapi_FlashBankSectorsType;

#endif /*F021_TYPES_H_*/

#ifndef __PQ_HAL_ZME_H__
#define __PQ_HAL_ZME_H__

#include "hi_type.h"
#include "hi_drv_video.h"
#include "pq_hal_comm.h"


#define VDP_MMZ_SIZE    (288 + 240 + 192 + 192 +144) * 7 /* 按照最大的内存分配 */
#define VPSS_MMZ_SIZE   (464 + 400 + 336 + 336) * 7      /* 按照最大的内存分配 */

#define VID_OFFSET      0x800
#define WBC_OFFSET      0x400

#define VouBitValue(a)  (a)


/*-------------------Zme Convert Start---------------*/
typedef enum
{
    VZME_TAP_8T32P = 0,
    VZME_TAP_6T32P    ,
    VZME_TAP_4T32P    ,
    VZME_TAP_2T32P    ,

    VZME_TAP_BUTT
} VZME_TAP_E;

typedef enum
{
    VZME_VPSS_COEF_8T32P_LH   = 0,
    VZME_VPSS_COEF_6T32P_LV      ,
    VZME_VPSS_COEF_4T32P_LV      ,
    VZME_VPSS_COEF_4T32P_CH      ,
    VZME_VPSS_COEF_4T32P_CV      ,
    VZME_VPSS_COEF_8T32P_CH      ,
    VZME_VPSS_COEF_6T32P_CV      ,

    VZME_VPSS_COEF_TYPE_BUTT
} VZME_VPSS_COEF_TYPE_E;

typedef enum
{
    VZME_COEF_1         = 0,
    VZME_COEF_E1           ,
    VZME_COEF_075          ,
    VZME_COEF_05           ,
    VZME_COEF_033          ,
    VZME_COEF_025          ,
    VZME_COEF_0            ,

    VZME_COEF_RATIO_BUTT
} VZME_COEF_RATIO_E;

typedef struct
{
    /* Luma-Hor-8T32P */
    HI_U32 u32ZmeCoefAddrHL8_1;
    HI_U32 u32ZmeCoefAddrHL8_E1;
    HI_U32 u32ZmeCoefAddrHL8_075;
    HI_U32 u32ZmeCoefAddrHL8_05;
    HI_U32 u32ZmeCoefAddrHL8_033;
    HI_U32 u32ZmeCoefAddrHL8_025;
    HI_U32 u32ZmeCoefAddrHL8_0;

    /* Chroma-Hor-4T32P */
    HI_U32 u32ZmeCoefAddrHC4_1;
    HI_U32 u32ZmeCoefAddrHC4_E1;
    HI_U32 u32ZmeCoefAddrHC4_075;
    HI_U32 u32ZmeCoefAddrHC4_05;
    HI_U32 u32ZmeCoefAddrHC4_033;
    HI_U32 u32ZmeCoefAddrHC4_025;
    HI_U32 u32ZmeCoefAddrHC4_0;

    /* Luma-Vert-6T32P */
    HI_U32 u32ZmeCoefAddrVL6_1;
    HI_U32 u32ZmeCoefAddrVL6_E1;
    HI_U32 u32ZmeCoefAddrVL6_075;
    HI_U32 u32ZmeCoefAddrVL6_05;
    HI_U32 u32ZmeCoefAddrVL6_033;
    HI_U32 u32ZmeCoefAddrVL6_025;
    HI_U32 u32ZmeCoefAddrVL6_0;

    /* Chroma-Vert-4T32P */
    HI_U32 u32ZmeCoefAddrVC4_1;
    HI_U32 u32ZmeCoefAddrVC4_E1;
    HI_U32 u32ZmeCoefAddrVC4_075;
    HI_U32 u32ZmeCoefAddrVC4_05;
    HI_U32 u32ZmeCoefAddrVC4_033;
    HI_U32 u32ZmeCoefAddrVC4_025;
    HI_U32 u32ZmeCoefAddrVC4_0;

    /* H_L8C4:Luma-Hor-8T32P; Chroma-Hor-4T32P */
    HI_U32 u32ZmeCoefAddrHL8C4_1;
    HI_U32 u32ZmeCoefAddrHL8C4_E1;
    HI_U32 u32ZmeCoefAddrHL8C4_075;
    HI_U32 u32ZmeCoefAddrHL8C4_05;
    HI_U32 u32ZmeCoefAddrHL8C4_033;
    HI_U32 u32ZmeCoefAddrHL8C4_025;
    HI_U32 u32ZmeCoefAddrHL8C4_0;

    /* V_L6C4:Luma-Vert-6T32P; Chroma-Vert-4T32P */
    HI_U32 u32ZmeCoefAddrVL6C4_1;
    HI_U32 u32ZmeCoefAddrVL6C4_E1;
    HI_U32 u32ZmeCoefAddrVL6C4_075;
    HI_U32 u32ZmeCoefAddrVL6C4_05;
    HI_U32 u32ZmeCoefAddrVL6C4_033;
    HI_U32 u32ZmeCoefAddrVL6C4_025;
    HI_U32 u32ZmeCoefAddrVL6C4_0;

    /* V_L4C4:Luma-Vert-4T32P Chroma-Vert-4T32P */
    HI_U32 u32ZmeCoefAddrVL4C4_1;
    HI_U32 u32ZmeCoefAddrVL4C4_E1;
    HI_U32 u32ZmeCoefAddrVL4C4_075;
    HI_U32 u32ZmeCoefAddrVL4C4_05;
    HI_U32 u32ZmeCoefAddrVL4C4_033;
    HI_U32 u32ZmeCoefAddrVL4C4_025;
    HI_U32 u32ZmeCoefAddrVL4C4_0;

    /* Luma-Vert-4T32P */
    HI_U32 u32ZmeCoefAddrVL4_1;
    HI_U32 u32ZmeCoefAddrVL4_E1;
    HI_U32 u32ZmeCoefAddrVL4_075;
    HI_U32 u32ZmeCoefAddrVL4_05;
    HI_U32 u32ZmeCoefAddrVL4_033;
    HI_U32 u32ZmeCoefAddrVL4_025;
    HI_U32 u32ZmeCoefAddrVL4_0;

    /* Chroma-Hor-8T32P; add from 3798 and HiFoneB2 */
    HI_U32 u32ZmeCoefAddrHC8_1;
    HI_U32 u32ZmeCoefAddrHC8_E1;
    HI_U32 u32ZmeCoefAddrHC8_075;
    HI_U32 u32ZmeCoefAddrHC8_05;
    HI_U32 u32ZmeCoefAddrHC8_033;
    HI_U32 u32ZmeCoefAddrHC8_025;
    HI_U32 u32ZmeCoefAddrHC8_0;

    /* Chroma-Vert-6T32P */
    HI_U32 u32ZmeCoefAddrVC6_1;
    HI_U32 u32ZmeCoefAddrVC6_E1;
    HI_U32 u32ZmeCoefAddrVC6_075;
    HI_U32 u32ZmeCoefAddrVC6_05;
    HI_U32 u32ZmeCoefAddrVC6_033;
    HI_U32 u32ZmeCoefAddrVC6_025;
    HI_U32 u32ZmeCoefAddrVC6_0;

} ALG_VZME_COEF_ADDR_S;

typedef enum
{
    VZME_COEF_8T32P_LH = 0,
    VZME_COEF_6T32P_LV    ,
    VZME_COEF_4T32P_LV    ,
    VZME_COEF_4T32P_CH    ,
    VZME_COEF_4T32P_CV    ,
    VZME_COEF_8T32P_CH    ,
    VZME_COEF_6T32P_CV    ,

    VZME_COEF_TYPE_BUTT
} VZME_COEF_TYPE_E;

typedef enum
{
    VDTI_COEF_8T32P_LH  = 0,
    VDTI_COEF_2T32P_LV     ,
    VDTI_COEF_4T32P_CH     ,
    VDTI_COEF_2T32P_CV     ,

    VDTI_COEF_TYPE_BUTT
} VDTI_COEF_TYPE_E;

typedef struct hiALG_MMZ_BUF_S
{
    HI_U32 u32StartVirAddr;
    HI_U32 u32StartPhyAddr;
    HI_U32 u32Size;
} ALG_MMZ_BUF_S;

typedef struct
{
    ALG_MMZ_BUF_S stMBuf;
    ALG_VZME_COEF_ADDR_S stZmeCoefAddr;
} ALG_VZME_MEM_S;

typedef struct
{
    HI_S32 bits_0   : 10  ;
    HI_S32 bits_1   : 10  ;
    HI_S32 bits_2   : 10  ;
    HI_S32 bits_32  : 2   ;
    HI_S32 bits_38  : 8   ;
    HI_S32 bits_4   : 10  ;
    HI_S32 bits_5   : 10  ;
    HI_S32 bits_64  : 4   ;
    HI_S32 bits_66  : 6   ;
    HI_S32 bits_7   : 10  ;
    HI_S32 bits_8   : 10  ;
    HI_S32 bits_96  : 6   ;
    HI_S32 bits_94  : 4   ;
    HI_S32 bits_10  : 10  ;
    HI_S32 bits_11  : 10  ;
    HI_S32 bits_12  : 8   ;
} ZME_COEF_BIT_S;

typedef struct
{
    HI_U32          u32Size;
    ZME_COEF_BIT_S  stBit[12];
    HI_S32          s32CoefAttr[51];
} ZME_COEF_BITARRAY_S;

typedef struct Hi_VDP_SR_ZME_COEF_S
{
    HI_S16 s16HLCoef0[8];
    HI_S16 s16HLCoef1[8];
    HI_S16 s16HCCoef0[8];
    HI_S16 s16HCCoef1[8];

    HI_S16 s16VLCoef0[6];
    HI_S16 s16VLCoef1[6];
    HI_S16 s16VCCoef0[6];
    HI_S16 s16VCCoef1[6];

} VDP_SR_ZME_COEF_S;
/*-------------------Zme Convert End---------------*/

typedef enum tagVDP_LAYER_WBC_E
{
    VDP_LAYER_WBC_HD0  = 0,
    VDP_LAYER_WBC_GP0  = 1,
    VDP_LAYER_WBC_G0   = 2,
    VDP_LAYER_WBC_G4   = 3,
    VDP_LAYER_WBC_ME   = 4,
    VDP_LAYER_WBC_FI   = 5,
    VDP_LAYER_WBC_BMP  = 6,

    VDP_LAYER_WBC_BUTT
} VDP_LAYER_WBC_E;

typedef enum
{
    VDP_ZME_MODE_HOR = 0,
    VDP_ZME_MODE_VER    ,

    VDP_ZME_MODE_HORL   ,
    VDP_ZME_MODE_HORC   ,
    VDP_ZME_MODE_VERL   ,
    VDP_ZME_MODE_VERC   ,

    VDP_ZME_MODE_ALPHA  ,
    VDP_ZME_MODE_ALPHAV ,
    VDP_ZME_MODE_VERT   ,
    VDP_ZME_MODE_VERB   ,

    VDP_ZME_MODE_ALL    ,
    VDP_ZME_MODE_NONL   ,

    VDP_ZME_MODE_BUTT
} VDP_ZME_MODE_E;

typedef enum tagVDP_WBC_PARA_E
{
    VDP_WBC_PARA_ZME_HORL = 0  ,
    VDP_WBC_PARA_ZME_HORC      ,
    VDP_WBC_PARA_ZME_VERL      ,
    VDP_WBC_PARA_ZME_VERC      ,

    VDP_WBC_GTI_PARA_ZME_HORL  ,
    VDP_WBC_GTI_PARA_ZME_HORC  ,
    VDP_WBC_GTI_PARA_ZME_VERL  ,
    VDP_WBC_GTI_PARA_ZME_VERC  ,

    VDP_WBC_PARA_ZME_HOR       ,
    VDP_WBC_PARA_ZME_VER       ,

    VDP_WBC_PARA_BUTT
} VDP_WBC_PARA_E;

typedef enum
{
    VDP_SR_ZME_MODE_HOR = 0,
    VDP_SR_ZME_MODE_VER    ,

    VDP_SR_ZME_MODE_HORL   ,
    VDP_SR_ZME_MODE_HORC   ,
    VDP_SR_ZME_MODE_VERL   ,
    VDP_SR_ZME_MODE_VERC   ,

    VDP_SR_ZME_MODE_BUTT
} VDP_SR_ZME_MODE_E;

/* Vdp Yuv Format definition */
/* in logic register 0:422; 1:420; 2:444; in vdp definition is same to reg 0:420; 1:422; */
typedef enum tagVDP_PROC_FMT_E
{
    VDP_PROC_FMT_SP_422      = 0x0,
    VDP_PROC_FMT_SP_420      = 0x1,
    VDP_PROC_FMT_SP_444      = 0x2, /* plannar,in YUV color domain */
    VDP_PROC_FMT_RGB_888     = 0x3, /* package,in RGB color domain */
    VDP_PROC_FMT_RGB_444     = 0x4, /* plannar,in RGB color domain */

    VDP_PROC_FMT_BUTT
} VDP_PROC_FMT_E;

/* Vpss Yuv Format definition */
/* in logic register 0:422; 1:420; 2:444; but in vpss 0:420; 1:422; */
typedef enum hiPQ_ALG_ZME_FORMAT_E
{
    PQ_ALG_ZME_PIX_FORMAT_SP420 = 0,
    PQ_ALG_ZME_PIX_FORMAT_SP422,
    PQ_ALG_ZME_PIX_FORMAT_SP444,

    PQ_ALG_ZME_PIX_FORMAT_BUTT,
} PQ_ALG_ZME_FORMAT_E;

typedef enum tagVDP_VID_PARA_E
{
    VDP_VID_PARA_ZME_HORL = 0,
    VDP_VID_PARA_ZME_HORC    ,
    VDP_VID_PARA_ZME_VERL    ,
    VDP_VID_PARA_ZME_VERC    ,

    VDP_VID_PARA_ZME_HOR     ,
    VDP_VID_PARA_ZME_VER     ,

    VDP_VID_PARA_BUTT
} VDP_VID_PARA_E;

typedef enum tagVDP_ZME_LAYER_E
{
    VDP_ZME_LAYER_V0 = 0,
    VDP_ZME_LAYER_V1    ,
    VDP_ZME_LAYER_V2    ,
    VDP_ZME_LAYER_V3    ,
    VDP_ZME_LAYER_V4    ,
    VDP_ZME_LAYER_WBC0  ,
    VDP_ZME_LAYER_SR    ,

    VDP_ZME_LAYER_BUTT
} VDP_ZME_LAYER_E;

typedef enum hiVPSS_REG_PORT_E
{
    VPSS_REG_HD = 0 , /* HD      */
    VPSS_REG_SD     , /* SD      */
    VPSS_REG_STR    , /* STR     */
    VPSS_REG_HSC    , /* HScaler */

    VPSS_REG_BUTT
} VPSS_REG_PORT_E;

typedef enum
{
    REG_ZME_MODE_HOR = 0 ,
    REG_ZME_MODE_VER     ,

    REG_ZME_MODE_HORL    ,
    REG_ZME_MODE_HORC    ,
    REG_ZME_MODE_VERL    ,
    REG_ZME_MODE_VERC    ,

    REG_ZME_MODE_ALL     ,
    REG_ZME_MODE_NONL    ,

    REG_ZME_MODE_BUTT
} REG_ZME_MODE_E;

typedef struct
{
    HI_BOOL bZmeEnHL;  /* zme enable of horizontal luma: 0-off; 1-on*/
    HI_BOOL bZmeEnHC;
    HI_BOOL bZmeEnVL;
    HI_BOOL bZmeEnVC;

    HI_BOOL bZmeMdHL;  /* zme mode of horizontal luma: 0-copy mode; 1-FIR filter mode*/
    HI_BOOL bZmeMdHC;
    HI_BOOL bZmeMdVL;
    HI_BOOL bZmeMdVC;

    HI_BOOL bZmeMedHL; /* zme Median filter enable of horizontal luma: 0-off; 1-on*/
    HI_BOOL bZmeMedHC;
    HI_BOOL bZmeMedVL;
    HI_BOOL bZmeMedVC;

    HI_S32 s32ZmeOffsetHL;
    HI_S32 s32ZmeOffsetHC;
    HI_S32 s32ZmeOffsetVL;
    HI_S32 s32ZmeOffsetVC;
    HI_S32 s32ZmeOffsetVLBtm;
    HI_S32 s32ZmeOffsetVCBtm;

    HI_U32 u32ZmeWIn;      /* HIFoneB2 does not exist WIn */
    HI_U32 u32ZmeHIn;      /* HIFoneB2 does not exist HIn */
    HI_U32 u32ZmeWOut;
    HI_U32 u32ZmeHOut;

    HI_U32 u32ZmeRatioHL;
    HI_U32 u32ZmeRatioVL;
    HI_U32 u32ZmeRatioHC;
    HI_U32 u32ZmeRatioVC;

    HI_BOOL bZmeOrder;     /* zme order of hzme and vzme: 0-hzme first; 1-vzme first */
    HI_BOOL bZmeTapVC;     /* zme tap of vertical chroma: 0-4tap; 1-2tap */

    HI_U8  u8ZmeYCFmtIn;   /* video format for zme input vdp: 0-422; 1-420; 2-444  vpss: 0-420; 1-422; 2-444 */
    HI_U8  u8ZmeYCFmtOut;  /* video format for zme input vdp: 0-422; 1-420; 2-444  vpss: 0-420; 1-422; 2-444 */

    HI_U32 u32ZmeCoefAddrHL;
    HI_U32 u32ZmeCoefAddrHC;
    HI_U32 u32ZmeCoefAddrVL;
    HI_U32 u32ZmeCoefAddrVC;
} ALG_VZME_RTL_PARA_S;

HI_S32  PQ_HAL_SetZmeDefault(HI_BOOL bOnOff);
HI_VOID PQ_HAL_VdpLoadCoef(ALG_VZME_MEM_S *pstVZmeCoefMem);
HI_VOID PQ_HAL_VdpZmeRegCfg(HI_U32 u32LayerId, ALG_VZME_RTL_PARA_S *pstZmeRtlPara, HI_BOOL bFirEnable);
HI_VOID PQ_HAL_WbcZmeRegCfg(HI_U32 u32LayerId, ALG_VZME_RTL_PARA_S *pstZmeRtlPara, HI_BOOL bFirEnable);
HI_VOID PQ_HAL_SRZmeRegCfg(HI_U32 u32LayerId, ALG_VZME_RTL_PARA_S *pstZmeRtlPara, HI_BOOL bFirEnable);
HI_VOID PQ_HAL_VpssLoadCoef(HI_U32 *pu32CurAddr, HI_U32 u32PhyAddr, ALG_VZME_COEF_ADDR_S *pstAddrTmp);
HI_VOID PQ_HAL_VpssZmeRegCfg(HI_U32 u32LayerId, S_CAS_REGS_TYPE *pstReg, ALG_VZME_RTL_PARA_S *pstZmeRtlPara, HI_BOOL bFirEnable);


#endif



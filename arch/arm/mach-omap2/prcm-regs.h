/*
 * linux/arch/arm/mach-omap2/prcm-reg.h
 *
 * OMAP34XX Power Reset and Clock Management (PRCM) registers
 *
 * Copyright (C) 2007 Texas Instruments, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef __ARCH_ARM_MACH_OMAP3_PRCM_H
#define __ARCH_ARM_MACH_OMAP3_PRCM_H

#ifndef __ASSEMBLER__

/* 16 bit uses LDRH/STRH, base +/- offset_8 */
typedef struct { volatile u16 offset[256]; } __regbase16;
#define __REGV16(vaddr)			((__regbase16 *)((vaddr)&~0xff)) \
										->offset[((vaddr)&0xff)>>1]
#define __REG16(paddr)			__REGV16(io_p2v(paddr))

/* 8/32 bit uses LDR/STR, base +/- offset_12 */
typedef struct { volatile u8 offset[4096]; } __regbase8;
#define __REGV8(vaddr)			((__regbase8  *)((vaddr)&~4095)) \
									->offset[((vaddr)&4095)>>0]
#define __REG8(paddr)			__REGV8(io_p2v(paddr))

typedef struct { volatile u32 offset[4096]; } __regbase32;
#define __REGV32(vaddr)			((__regbase32 *)((vaddr)&~4095)) \
									->offset[((vaddr)&4095)>>2]
#define __REG32(paddr)			__REGV32(io_p2v(paddr))


#define PRM_REG32(offset)	__REG32(PRM_BASE + (offset))
#define CM_REG32(offset)	__REG32(CM_BASE + (offset))
#define SYSCONFIG_REG32(base, offset)           __REG32(base + offset)
#define DEFINE_REG(base, offset)                __REG32(base + offset)

#define CORE3_DPLL_MASK		0x7
/* MASK values for some DPLL/CLOCK/POWER registers  */
/* DPLL1/2/3/5 enable/put_in_bypass MASK */
#define DPLL_ENBIT_MASK		0xFFFFFFF8
/* DPLL4 enable/put_in_bypass MASK */
#define DPLL4_ENBIT_MASK	0xFFF8FFFF
/* DPLL1/2/4 Divisor(N) value MASK */
#define DPLL_N_MASK		0xFFFFFF80
/* DPLL3 Divisor(N_ value MASK */
#define DPLL3_N_MASK		0xFFFF80FF
/* System clock divisor MASK */
#define SYSCLK_DIV_MASK		0xFFFFFF3F
/* External output clock 1/2 control MASK */
#define EXTCLK_OUTCTRL_MASK	0xFFFFFF7F
/* Power domain IN_TRANSITION MASK */
#define PWSTST_INTRANS_MASK	0x00100000
/* Power Domain state MASK */
#define PWSTST_PWST_MASK	0x00000003

/* MASK values for core  memory and logic resource   */
#define PRCM_CORE_MEM1ONBITS            (0x3 << 16)
#define PRCM_CORE_MEM2ONBITS            (0x3 << 18)
#define PRCM_CORE_MEMBIT1               (0x1 << 8)
#define PRCM_CORE_MEMBIT2               (0x1 << 9)
#define PRCM_CORE_MEMBIT                (0x3 << 8)
#define PRCM_CORE_PWRSTATEBIT1           0x1
#define PRCM_CORE_PWRSTATEBIT2           0x2
#define PRCM_CORE_LOGICBIT              (0x1 << 2)
#define PRCM_CORE_PWRSTATEOFF            0x0

/* Bit fields in RSTST registers */
#define DOM_WKUP_RST		0x4
#define COREDOM_WKUP_RST	0x8

/* CM Module Registers */
/* IVA2_CM Registers */
#define CM_FCLKEN_IVA2		CM_REG32(0x0)
#define CM_CLKEN_PLL_IVA2	CM_REG32(0x4)
#define CM_IDLEST_IVA2		CM_REG32(0x20)
#define	CM_IDLEST_PLL_IVA2	CM_REG32(0x24)
#define	CM_AUTOIDLE_PLL_IVA2	CM_REG32(0x34)
#define CM_CLKSEL1_PLL_IVA2	CM_REG32(0x40)
#define CM_CLKSEL2_PLL_IVA2	CM_REG32(0x44)
#define CM_CLKSTCTRL_IVA2	CM_REG32(0x48)
#define CM_CLKSTST_IVA2		CM_REG32(0x4C)

/* OCP System Register CM */
#define CM_REVISION		CM_REG32(0x800)
#define CM_SYSCONFIG		CM_REG32(0x810)

/* MPU_CM Registers */
#define CM_CLKEN_PLL_MPU	CM_REG32(0x904)
#define CM_IDLEST_MPU		CM_REG32(0x920)
#define CM_IDLEST_PLL_MPU	CM_REG32(0x924)
#define CM_AUTOIDLE_PLL_MPU	CM_REG32(0x934)
#define CM_CLKSEL1_PLL_MPU	CM_REG32(0x940)
#define CM_CLKSEL2_PLL_MPU	CM_REG32(0x944)
#define CM_CLKSTCTRL_MPU	CM_REG32(0x948)
#define CM_CLKSTST_MPU		CM_REG32(0x94C)

/* CORE_CM Registers */
#define CM_FCLKEN1_CORE		CM_REG32(0xA00)
#define CM_ICLKEN1_CORE		CM_REG32(0xA10)
#define CM_ICLKEN2_CORE		CM_REG32(0xA14)
#define CM_IDLEST1_CORE		CM_REG32(0xA20)
#define CM_IDLEST2_CORE		CM_REG32(0xA24)
#define CM_AUTOIDLE1_CORE	CM_REG32(0xA30)
#define CM_AUTOIDLE2_CORE	CM_REG32(0xA34)
#define CM_CLKSEL_CORE		CM_REG32(0xA40)
#define CM_CLKSTCTRL_CORE	CM_REG32(0xA48)
#define CM_CLKSTST_CORE		CM_REG32(0xA4C)

#define CM_FCLKEN3_CORE		CM_REG32(0xA08)
#define CM_ICLKEN3_CORE		CM_REG32(0xA18)
#define CM_IDLEST3_CORE		CM_REG32(0xA28)
#define CM_AUTOIDLE3_CORE	CM_REG32(0xA38)

/* GFX_CM Registers */
#define CM_FCLKEN_SGX		CM_REG32(0xB00)
#define CM_ICLKEN_SGX		CM_REG32(0xB10)
#define CM_IDLEST_SGX		CM_REG32(0xB20)
#define CM_CLKSEL_SGX		CM_REG32(0xB40)
#define CM_SLEEPDEP_SGX		CM_REG32(0xB44)
#define CM_CLKSTCTRL_SGX	CM_REG32(0xB48)
#define CM_CLKSTST_SGX		CM_REG32(0xB4C)

/* WKUP_CM Registers */
#define CM_FCLKEN_WKUP		CM_REG32(0xC00)
#define CM_ICLKEN_WKUP		CM_REG32(0xC10)
#define CM_IDLEST_WKUP		CM_REG32(0xC20)
#define CM_AUTOIDLE_WKUP	CM_REG32(0xC30)
#define CM_CLKSEL_WKUP		CM_REG32(0xC40)

/* CM Clock control registers */
#define CM_CLKEN_PLL		CM_REG32(0xD00)
#define CM_IDLEST_CKGEN		CM_REG32(0xD20)
#define CM_AUTOIDLE_PLL		CM_REG32(0xD30)
#define CM_CLKSEL1_PLL		CM_REG32(0xD40)
#define CM_CLKSEL2_PLL		CM_REG32(0xD44)
#define CM_CLKSEL3_PLL		CM_REG32(0xD48)
#define CM_CLKOUT_CTRL		CM_REG32(0xD70)

#define CM_CLKEN2_PLL		CM_REG32(0xD04)
#define CM_IDLEST2_CKGEN	CM_REG32(0xD24)
#define CM_AUTOIDLE2_PLL	CM_REG32(0xD34)
#define CM_CLKSEL4_PLL		CM_REG32(0xD4C)
#define CM_CLKSEL5_PLL		CM_REG32(0xD50)

/* DSS_CM Registers */
#define CM_FCLKEN_DSS		CM_REG32(0xE00)
#define CM_ICLKEN_DSS		CM_REG32(0xE10)
#define CM_IDLEST_DSS		CM_REG32(0xE20)
#define CM_AUTOIDLE_DSS		CM_REG32(0xE30)
#define CM_CLKSEL_DSS		CM_REG32(0xE40)
#define CM_SLEEPDEP_DSS		CM_REG32(0xE44)
#define CM_CLKSTCTRL_DSS	CM_REG32(0xE48)
#define CM_CLKSTST_DSS		CM_REG32(0xE4C)

/* CAM_CM Registers */
#define CM_FCLKEN_CAM		CM_REG32(0xF00)
#define CM_ICLKEN_CAM		CM_REG32(0xF10)
#define CM_IDLEST_CAM		CM_REG32(0xF20)
#define CM_AUTOIDLE_CAM		CM_REG32(0xF30)
#define CM_CLKSEL_CAM		CM_REG32(0xF40)
#define CM_SLEEPDEP_CAM		CM_REG32(0xF44)
#define CM_CLKSTCTRL_CAM	CM_REG32(0xF48)
#define CM_CLKSTST_CAM		CM_REG32(0xF4C)

/* PER_CM Registers */
#define CM_FCLKEN_PER		CM_REG32(0x1000)
#define CM_ICLKEN_PER		CM_REG32(0x1010)
#define CM_IDLEST_PER		CM_REG32(0x1020)
#define CM_AUTOIDLE_PER		CM_REG32(0x1030)
#define CM_CLKSEL_PER		CM_REG32(0x1040)
#define CM_SLEEPDEP_PER		CM_REG32(0x1044)
#define CM_CLKSTCTRL_PER		CM_REG32(0x1048)
#define CM_CLKSTST_PER		CM_REG32(0x104C)

/* EMU_CM Registers */
#define CM_CLKSEL1_EMU		CM_REG32(0x1140)
#define CM_CLKSTCTRL_EMU	CM_REG32(0x1148)
#define CM_CLKSTST_EMU		CM_REG32(0x114C)
#define CM_CLKSEL2_EMU		CM_REG32(0x1150)
#define CM_CLKSEL3_EMU		CM_REG32(0x1154)

/* Global Registers CM */
#define CM_POLCTRL		CM_REG32(0x129C)

/* NEON_CM */
#define CM_IDLEST_NEON		CM_REG32(0x1320)
#define CM_CLKSTCTRL_NEON	CM_REG32(0x1348)

/* USBHOST_CM registers */
#define CM_FCLKEN_USBHOST 	CM_REG32(0x1400)
#define CM_ICLKEN_USBHOST 	CM_REG32(0x1410)
#define CM_IDLEST_USBHOST 	CM_REG32(0x1420)
#define CM_AUTOIDLE_USBHOST 	CM_REG32(0x1430)
#define CM_SLEEPDEP_USBHOST 	CM_REG32(0x1444)
#define CM_CLKSTCTRL_USBHOST 	CM_REG32(0x1448)
#define CM_CLKSTST_USBHOST 	CM_REG32(0x144C)

/* PRM Module Registers */
/* IVA2_PRM */
#define RM_RSTCTRL_IVA2		PRM_REG32(0x50)
#define RM_RSTST_IVA2		PRM_REG32(0x58)
#define PM_WKDEP_IVA2		PRM_REG32(0xC8)
#define PM_PWSTCTRL_IVA2	PRM_REG32(0xE0)
#define PM_PWSTST_IVA2		PRM_REG32(0xE4)
#define PM_PREPWSTST_IVA2	PRM_REG32(0xE8)
#define PRM_IRQSTATUS_IVA2	PRM_REG32(0xF8)
#define PRM_IRQENABLE_IVA2	PRM_REG32(0xFC)

/* OCP System Registers PRM */
#define PRM_REVISION		PRM_REG32(0x804)
#define PRM_SYSCONFIG		PRM_REG32(0x814)
#define PRM_IRQSTATUS_MPU	PRM_REG32(0x818)
#define PRM_IRQENABLE_MPU	PRM_REG32(0x81C)

/* MPU_PRM Registers */
#define RM_RSTST_MPU		PRM_REG32(0x958)
#define PM_WKDEP_MPU		PRM_REG32(0x9C8)
#define PM_EVGENCTRL_MPU	PRM_REG32(0x9D4)
#define PM_EVGENONTIM_MPU	PRM_REG32(0x9D8)
#define PM_EVGENOFFTIM_MPU	PRM_REG32(0x9DC)
#define PM_PWSTCTRL_MPU		PRM_REG32(0x9E0)
#define PM_PWSTST_MPU		PRM_REG32(0x9E4)
#define PM_PREPWSTST_MPU	PRM_REG32(0x9E8)

/* CORE_PRM Registers */
#define RM_RSTCTRL_CORE		PRM_REG32(0xA50)
#define RM_RSTST_CORE		PRM_REG32(0xA58)
#define PM_WKEN1_CORE		PRM_REG32(0xAA0)
#define PM_MPUGRPSEL1_CORE	PRM_REG32(0xAA4)
#define PM_IVA2GRPSEL1_CORE	PRM_REG32(0xAA8)
#define PM_WKST1_CORE		PRM_REG32(0xAB0)
#define PM_PWSTCTRL_CORE	PRM_REG32(0xAE0)
#define PM_PWSTST_CORE		PRM_REG32(0xAE4)
#define PM_PREPWSTST_CORE	PRM_REG32(0xAE8)
#define PM_PWSTCTRL_CORE_SARMASK	(1 << 4)

#define PM_WKST3_CORE		PRM_REG32(0xAB8)
#define PM_WKEN3_CORE		PRM_REG32(0xAF0)
#define PM_IVA2GRPSEL3_CORE	PRM_REG32(0xAF4)
#define PM_MPUGRPSEL3_CORE	PRM_REG32(0xAF8)

/* GFX_PRM Registers */
#define RM_RSTST_SGX		PRM_REG32(0xB58)
#define PM_WKDEP_SGX		PRM_REG32(0xBC8)
#define PM_PWSTCTRL_SGX		PRM_REG32(0xBE0)
#define PM_PWSTST_SGX		PRM_REG32(0xBE4)
#define PM_PREPWSTST_SGX	PRM_REG32(0xBE8)

/* WKUP_PRM Registers */
#define PM_WKEN_WKUP		PRM_REG32(0xCA0)
#define PM_MPUGRPSEL_WKUP	PRM_REG32(0xCA4)
#define PM_IVA2GRPSEL_WKUP	PRM_REG32(0xCA8)
#define PM_WKST_WKUP		PRM_REG32(0xCB0)

/* Clock control registers PRM */
#define PRM_CLKSEL		PRM_REG32(0xD40)
#define PRM_CLKOUT_CTRL		PRM_REG32(0xD70)

/* DSS_PRM registers */
#define RM_RSTST_DSS		PRM_REG32(0xE58)
#define PM_WKEN_DSS		PRM_REG32(0xEA0)
#define PM_WKDEP_DSS		PRM_REG32(0xEC8)
#define	PM_PWSTCTRL_DSS		PRM_REG32(0xEE0)
#define PM_PWSTST_DSS		PRM_REG32(0xEE4)
#define PM_PREPWSTST_DSS	PRM_REG32(0xEE8)

/* CAM_PRM registers */
#define RM_RSTST_CAM		PRM_REG32(0xF58)
#define PM_WKDEP_CAM		PRM_REG32(0xFC8)
#define PM_PWSTCTRL_CAM		PRM_REG32(0xFE0)
#define PM_PWSTST_CAM		PRM_REG32(0xFE4)
#define PM_PREPWSTST_CAM	PRM_REG32(0xFE8)

/* PER_PRM registers */
#define RM_RSTST_PER		PRM_REG32(0x1058)
#define PM_WKEN_PER		PRM_REG32(0x10A0)
#define PM_MPUGRPSEL_PER	PRM_REG32(0x10A4)
#define PM_IVA2GRPSEL_PER	PRM_REG32(0x10A8)
#define PM_WKST_PER		PRM_REG32(0x10B0)
#define PM_WKDEP_PER		PRM_REG32(0x10C8)
#define PM_PWSTCTRL_PER		PRM_REG32(0x10E0)
#define PM_PWSTST_PER		PRM_REG32(0x10E4)
#define PM_PREPWSTST_PER	PRM_REG32(0x10E8)

/* EMU_PRM registers */
#define RM_RSTST_EMU		PRM_REG32(0x1158)
#define PM_PWSTST_EMU		PRM_REG32(0x11E4)

/* Global Registers PRM */
#define PRM_VC_SMPS_SA		PRM_REG32(0x1220)
#define PRM_VC_SMPS_VOL_RA	PRM_REG32(0x1224)
#define PRM_VC_SMPS_CMD_RA	PRM_REG32(0x1228)
#define PRM_VC_CMD_VAL_0	PRM_REG32(0x122C)
#define PRM_VC_CMD_VAL_1	PRM_REG32(0x1230)
#define PRM_VC_CH_CONF		PRM_REG32(0x1234)
#define PRM_VC_I2C_CFG		PRM_REG32(0x1238)
#define PRM_VC_BYPASS_VAL	PRM_REG32(0x123C)
#define PRM_RSTCTRL		PRM_REG32(0x1250)
#define PRM_RSTTIME		PRM_REG32(0x1254)
#define PRM_RSTST		PRM_REG32(0x1258)
#define PRM_VOLTCTRL		PRM_REG32(0x1260)
#define PRM_SRAM_PCHARGE	PRM_REG32(0x1264)
#define PRM_CLKSRC_CTRL		PRM_REG32(0x1270)
#define PRM_VOLTSETUP1		PRM_REG32(0x1290)
#define PRM_VOLTOFFSET		PRM_REG32(0x1294)
#define PRM_CLKSETUP		PRM_REG32(0x1298)
#define PRM_POLCTRL		PRM_REG32(0x129C)
#define PRM_VOLTSETUP2		PRM_REG32(0x12A0)
#define PRM_VP1_CONFIG		PRM_REG32(0x12B0)
#define PRM_VP1_VSTEPMIN	PRM_REG32(0x12B4)
#define PRM_VP1_VSTEPMAX	PRM_REG32(0x12B8)
#define PRM_VP1_VLIMITTO	PRM_REG32(0x12BC)
#define PRM_VP1_VOLTAGE		PRM_REG32(0x12C0)
#define PRM_VP1_STATUS		PRM_REG32(0x12C4)
#define PRM_VP2_CONFIG		PRM_REG32(0x12D0)
#define PRM_VP2_VSTEPMIN	PRM_REG32(0x12D4)
#define PRM_VP2_VSTEPMAX	PRM_REG32(0x12D8)
#define PRM_VP2_VLIMITTO	PRM_REG32(0x12DC)
#define PRM_VP2_VOLTAGE		PRM_REG32(0x12E0)
#define PRM_VP2_STATUS		PRM_REG32(0x12E4)

/* NEON_PRM Registers */
#define RM_RSTST_NEON		PRM_REG32(0x1358)
#define PM_WKDEP_NEON		PRM_REG32(0x13C8)
#define PM_PWSTCTRL_NEON	PRM_REG32(0x13E0)
#define PM_PWSTST_NEON		PRM_REG32(0x13E4)
#define PM_PREPWSTST_NEON	PRM_REG32(0x13E8)

/* USBHOST_PRM Registers */
#define RM_RSTST_USBHOST 	PRM_REG32(0x1458)
#define PM_WKEN_USBHOST 	PRM_REG32(0x14A0)
#define PM_MPUGRPSEL_USBHOST 	PRM_REG32(0x14A4)
#define PM_IVA2GRPSEL_USBHOST 	PRM_REG32(0x14A8)
#define PM_WKST_USBHOST 	PRM_REG32(0x14B0)
#define PM_WKDEP_USBHOST 	PRM_REG32(0x14C8)
#define PM_PWSTCTRL_USBHOST 	PRM_REG32(0x14E0)
#define PM_PWSTST_USBHOST 	PRM_REG32(0x14E4)
#define PM_PREPWSTST_USBHOST 	PRM_REG32(0x14E8)
#define PM_PWSTCTRL_USBHOST_SARMASK	(0x1 << 4)


#else

#define __REG8(paddr)			io_p2v(paddr)
#define __REG16(paddr)			io_p2v(paddr)
#define __REG32(paddr)			io_p2v(paddr)

#endif

#define PRCM_GPIO1_BASE 	0x48310000

#define GPIO1_IRQSTATUS1        DEFINE_REG(PRCM_GPIO1_BASE, 0x18)
#define GPIO1_IRQSTATUS2        DEFINE_REG(PRCM_GPIO1_BASE, 0x28)
#define GPIO1_IRQENABLE1        DEFINE_REG(PRCM_GPIO1_BASE, 0x1C)
#define GPIO1_WAKEUPENABLE      DEFINE_REG(PRCM_GPIO1_BASE, 0x20)
#define GPIO1_SETIRQENABLE1     DEFINE_REG(PRCM_GPIO1_BASE, 0x64)

/* SYSCONFIG Registers */
/* CORE1 */
#define PRCM_SSI_BASE           0x48058000
#define PRCM_SSI_SYSCONFIG              SYSCONFIG_REG32(PRCM_SSI_BASE, 0x10)
#define PRCM_SDRC_BASE          0x6D000000
#define PRCM_SDRC_SYSCONFIG     SYSCONFIG_REG32(PRCM_SDRC_BASE, 0x10)
#define PRCM_SDMA_BASE  0x48056000
#define PRCM_SDMA_SYSCONFIG     SYSCONFIG_REG32(PRCM_SDMA_BASE, 0x2C)
#define PRCM_D2D_BASE           0x68003000
#define PRCM_D2D_SYSCONFIG      SYSCONFIG_REG32(PRCM_D2D_BASE, 0x2C)
#define PRCM_HSOTG_BASE 0x480AB000
#define PRCM_HSOTG_SYSCONFIG    SYSCONFIG_REG32(PRCM_HSOTG_BASE, 0x404)
#define PRCM_HSOTG_FORCESTDBY	SYSCONFIG_REG32(PRCM_HSOTG_BASE, 0x414)
#define PRCM_HDQ_BASE           0x480B2000
#define PRCM_HDQ_SYSCONFIG      SYSCONFIG_REG32(PRCM_HDQ_BASE, 0x14)
#define PRCM_OMAP_CTRL_BASE     0x48002000
#define PRCM_OMAP_CTRL_SYSCONFIG        \
        SYSCONFIG_REG32(PRCM_OMAP_CTRL_BASE, 0x10)
#define PRCM_MBOXES_BASE        0x48094000
#define PRCM_MBOXES_SYSCONFIG   SYSCONFIG_REG32(PRCM_MBOXES_BASE, 0x10)
#define PRCM_FAC_BASE           0x48092000
#define PRCM_FAC_SYSCONFIG      SYSCONFIG_REG32(PRCM_FAC_BASE, 0x18)
#define PRCM_MCBSP1_BASE        0x48074000
#define PRCM_MCBSP1_SYSCONFIG   SYSCONFIG_REG32(PRCM_MCBSP1_BASE, 0x8C)
#define PRCM_MCBSP5_BASE        0x48096000
#define PRCM_MCBSP5_SYSCONFIG   SYSCONFIG_REG32(PRCM_MCBSP5_BASE, 0x8C)
#define PRCM_GPT10_BASE 0x48086000
#define PRCM_GPT10_SYSCONFIG    SYSCONFIG_REG32(PRCM_GPT10_BASE, 0x10)
#define PRCM_GPT11_BASE 0x48088000
#define PRCM_GPT11_SYSCONFIG    SYSCONFIG_REG32(PRCM_GPT11_BASE, 0x10)
#define PRCM_UART1_BASE 0x4806A000
#define PRCM_UART1_SCR          SYSCONFIG_REG32(PRCM_UART1_BASE, 0x40)
#define PRCM_UART1_SSR          SYSCONFIG_REG32(PRCM_UART1_BASE, 0x44)
#define PRCM_UART1_SYSCONFIG    SYSCONFIG_REG32(PRCM_UART1_BASE, 0x54)
#define PRCM_UART1_WER          SYSCONFIG_REG32(PRCM_UART1_BASE, 0x5C)
#define PRCM_UART2_BASE 0x4806C000
#define PRCM_UART2_SCR          SYSCONFIG_REG32(PRCM_UART2_BASE, 0x40)
#define PRCM_UART2_SSR          SYSCONFIG_REG32(PRCM_UART2_BASE, 0x44)
#define PRCM_UART2_SYSCONFIG    SYSCONFIG_REG32(PRCM_UART2_BASE, 0x54)
#define PRCM_UART2_WER          SYSCONFIG_REG32(PRCM_UART2_BASE, 0x5C)
#define PRCM_I2C1_BASE          0x48070000
#define PRCM_I2C1_SYSCONFIG     SYSCONFIG_REG32(PRCM_I2C1_BASE, 0x20)
#define PRCM_I2C2_BASE          0x48072000
#define PRCM_I2C2_SYSCONFIG     SYSCONFIG_REG32(PRCM_I2C2_BASE, 0x20)
#define PRCM_I2C3_BASE          0x48060000
#define PRCM_I2C3_SYSCONFIG     SYSCONFIG_REG32(PRCM_I2C3_BASE, 0x20)
#define PRCM_MCSPI1_BASE        0x48098000
#define PRCM_MCSPI1_SYSCONFIG   SYSCONFIG_REG32(PRCM_MCSPI1_BASE, 0x10)
#define PRCM_MCSPI2_BASE        0x4809A000
#define PRCM_MCSPI2_SYSCONFIG           SYSCONFIG_REG32(PRCM_MCSPI2_BASE, 0x10)
#define PRCM_MCSPI3_BASE        0x480B8000
#define PRCM_MCSPI3_SYSCONFIG           SYSCONFIG_REG32(PRCM_MCSPI3_BASE, 0x10)
#define PRCM_MCSPI4_BASE        0x480BA000
#define PRCM_MCSPI4_SYSCONFIG           SYSCONFIG_REG32(PRCM_MCSPI4_BASE, 0x10)
#define PRCM_MMC1_BASE          0x4809C000
#define PRCM_MMC1_SYSCONFIG             SYSCONFIG_REG32(PRCM_MMC1_BASE, 0x10)
#define PRCM_MMC2_BASE          0x480B4000
#define PRCM_MMC2_SYSCONFIG     SYSCONFIG_REG32(PRCM_MMC2_BASE, 0x10)
#define PRCM_MMC3_BASE          0x480AD000
#define PRCM_MMC3_SYSCONFIG     SYSCONFIG_REG32(PRCM_MMC3_BASE, 0x10)
#define PRCM_MPU_INTC_BASE      0x48200000
#define PRCM_MPU_INTC_SYSCONFIG SYSCONFIG_REG32(PRCM_MPU_INTC_BASE, 0x10)
#define PRCM_SMS_BASE           0x6C000000
#define PRCM_SMS_SYSCONFIG      SYSCONFIG_REG32(PRCM_SMS_BASE, 0x10)
#define PRCM_GPMC_BASE  0x6E000000
#define PRCM_GPMC_SYSCONFIG     SYSCONFIG_REG32(PRCM_GPMC_BASE, 0x10)
/* WKUP */
#define PRCM_GPT1_BASE          0x48318000
#define PRCM_GPT1_SYSCONFIG     SYSCONFIG_REG32(PRCM_GPT1_BASE, 0x10)
#define PRCM_GPT12_BASE 0x48304000
#define PRCM_GPT12_SYSCONFIG    SYSCONFIG_REG32(PRCM_GPT12_BASE, 0x10)
#define PRCM_GPIO1_BASE 0x48310000
#define PRCM_GPIO1_SYSCONFIG    SYSCONFIG_REG32(PRCM_GPIO1_BASE, 0x10)
#define GPIO1_IRQSTATUS1        DEFINE_REG(PRCM_GPIO1_BASE, 0x18)
#define GPIO1_IRQSTATUS2        DEFINE_REG(PRCM_GPIO1_BASE, 0x28)
#define GPIO1_IRQENABLE1        DEFINE_REG(PRCM_GPIO1_BASE, 0x1C)
#define GPIO1_WAKEUPENABLE      DEFINE_REG(PRCM_GPIO1_BASE, 0x20)
#define GPIO1_SETIRQENABLE1     DEFINE_REG(PRCM_GPIO1_BASE, 0x64)
#define GPIO1_SETWKUENA         SYSCONFIG_REG32(PRCM_GPIO1_BASE, 0x84)
#define GPIO1_RISINGDETECT      SYSCONFIG_REG32(PRCM_GPIO1_BASE, 0x48)
#define GPIO1_FALLINGDETECT     SYSCONFIG_REG32(PRCM_GPIO1_BASE, 0x4C)
#define PRCM_WDT1_BASE  0x4830C010
#define PRCM_WDT1_SYSCONFIG     SYSCONFIG_REG32(PRCM_WDT1_BASE, 0x10)
#define PRCM_WDT2_BASE  0x48314000
#define PRCM_WDT2_SYSCONFIG     SYSCONFIG_REG32(PRCM_WDT2_BASE, 0x10)

/* DSS */
#define PRCM_DSS_BASE           0x48050000
#define PRCM_DSS_SYSCONFIG      SYSCONFIG_REG32(PRCM_DSS_BASE, 0x10)
#define PRCM_DISPC_BASE 0x48050400
#define PRCM_DISPC_SYSCONFIG    SYSCONFIG_REG32(PRCM_DISPC_BASE, 0x10)
#define PRCM_RFBI_BASE          0x48050800
#define PRCM_RFBI_SYSCONFIG     SYSCONFIG_REG32(PRCM_RFBI_BASE, 0x10)
/* CAM */
#define PRCM_CAM_BASE           0x480BC000
#define PRCM_CAM_SYSCONFIG      SYSCONFIG_REG32(PRCM_CAM_BASE, 0x04)
#define PRCM_CSI_BASE           0x480BC200
#define PRCM_CSIA_SYSCONFIG     SYSCONFIG_REG32(PRCM_CSI_BASE, 0x04)
#define PRCM_CSIB_SYSCONFIG     SYSCONFIG_REG32(PRCM_CSI_BASE, 0x204)
#define PRCM_MMU_BASE           0x480BD400
#define PRCM_MMU_SYSCONFIG      SYSCONFIG_REG32(PRCM_MMU_BASE, 0x10)
#define PRCM_ISP_CTRL_BASE              0x480BC000
#define PRCM_ISP_CTRL_SYSCONFIG SYSCONFIG_REG32(PRCM_ISP_CTRL_BASE, 0x40)
/* PER */
#define PRCM_MCBSP2_BASE        0x49022000
#define PRCM_MCBSP2_SYSCONFIG   SYSCONFIG_REG32(PRCM_MCBSP2_BASE, 0x8C)
#define PRCM_MCBSP3_BASE        0x49024000
#define PRCM_MCBSP3_SYSCONFIG   SYSCONFIG_REG32(PRCM_MCBSP3_BASE, 0x8C)
#define PRCM_MCBSP4_BASE        0x49026000
#define PRCM_MCBSP4_SYSCONFIG   SYSCONFIG_REG32(PRCM_MCBSP4_BASE, 0x8C)
#define PRCM_GPT2_BASE          0x49032000
#define PRCM_GPT2_SYSCONFIG     SYSCONFIG_REG32(PRCM_GPT2_BASE, 0x10)
#define PRCM_GPT3_BASE          0x49034000
#define PRCM_GPT3_SYSCONFIG     SYSCONFIG_REG32(PRCM_GPT3_BASE, 0x10)
#define PRCM_GPT4_BASE          0x49036000
#define PRCM_GPT4_SYSCONFIG     SYSCONFIG_REG32(PRCM_GPT4_BASE, 0x10)
#define PRCM_GPT5_BASE          0x49038000
#define PRCM_GPT5_SYSCONFIG     SYSCONFIG_REG32(PRCM_GPT5_BASE, 0x10)
#define PRCM_GPT6_BASE          0x4903A000
#define PRCM_GPT6_SYSCONFIG     SYSCONFIG_REG32(PRCM_GPT6_BASE, 0x10)
#define PRCM_GPT7_BASE          0x4903C010
#define PRCM_GPT7_SYSCONFIG     SYSCONFIG_REG32(PRCM_GPT7_BASE, 0x10)
#define PRCM_GPT8_BASE          0x4903E010
#define PRCM_GPT8_SYSCONFIG     SYSCONFIG_REG32(PRCM_GPT8_BASE, 0x10)
#define PRCM_GPT9_BASE          0x49040010
#define PRCM_GPT9_SYSCONFIG     SYSCONFIG_REG32(PRCM_GPT9_BASE, 0x10)
#define PRCM_UART3_BASE 0x49020000
#define PRCM_UART3_SCR          SYSCONFIG_REG32(PRCM_UART3_BASE, 0x40)
#define PRCM_UART3_SSR          SYSCONFIG_REG32(PRCM_UART3_BASE, 0x44)
#define PRCM_UART3_SYSCONFIG    SYSCONFIG_REG32(PRCM_UART3_BASE, 0x54)
#define PRCM_UART3_WER          SYSCONFIG_REG32(PRCM_UART3_BASE, 0x5C)
#define PRCM_WDT3_BASE  0x49030000
#define PRCM_WDT3_SYSCONFIG     SYSCONFIG_REG32(PRCM_WDT3_BASE, 0x10)
#define PRCM_GPIO2_BASE 0x49050000
#define PRCM_GPIO2_SYSCONFIG    SYSCONFIG_REG32(PRCM_GPIO2_BASE, 0x10)
#define PRCM_GPIO3_BASE 0x49052000
#define PRCM_GPIO3_SYSCONFIG    SYSCONFIG_REG32(PRCM_GPIO3_BASE, 0x10)
#define PRCM_GPIO4_BASE 0x49054000
#define PRCM_GPIO4_SYSCONFIG    SYSCONFIG_REG32(PRCM_GPIO4_BASE, 0x10)
#define PRCM_GPIO5_BASE 0x49056000
#define PRCM_GPIO5_SYSCONFIG    SYSCONFIG_REG32(PRCM_GPIO5_BASE, 0x10)
#define PRCM_GPIO6_BASE 0x49058000
#define PRCM_GPIO6_SYSCONFIG    SYSCONFIG_REG32(PRCM_GPIO6_BASE, 0x10)


/* SMART REFLEX REG BASE ADDRESS */
#define OMAP34XX_SR1_BASE	0x480C9000
#define OMAP34XX_SR2_BASE	0x480CB000

/* SMART REFLEX REG ADDRESS OFFSET */
#define SRCONFIG	0x00
#define SRSTATUS	0x04
#define SENVAL		0x08
#define SENMIN		0x0C
#define SENMAX		0x10
#define SENAVG		0x14
#define AVGWEIGHT	0x18
#define NVALUERECIPROCAL	0x1C
#define SENERROR	0x20
#define ERRCONFIG	0x24

#else


#define __REG8(paddr)           io_p2v(paddr)
#define __REG16(paddr)          io_p2v(paddr)
#define __REG32(paddr)          io_p2v(paddr)

#endif

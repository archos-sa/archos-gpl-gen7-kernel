/*
 * linux/arch/arm/mach-omap2/ti-compat.h
 *
 * Header file definitions to maintain compatibility with TI power
 * framework
 *
 * Copyright (C) 2007 Texas Instruments Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef _TI_COMPAT_H_
#define _TI_COMPAT_H_

#include <mach/hardware.h>

/* ! NOTE: this is _NOT_ OMAP3430_PRM_BASE */
#define PRM_BASE		(L4_WK_34XX_BASE + 0x6000)
/* ! NOTE: this is _not_ OMAP3430_CM_BASE */
#define CM_BASE			(L4_34XX_BASE + 0x4000)
#define SDRC_BASE		OMAP343X_SDRC_BASE
#define IC_BASE			OMAP34XX_IC_BASE
#define OMAP_CTRL_BASE          OMAP343X_CTRL_BASE

#undef OMAP_TIMER32K_BASE
#define OMAP_TIMER32K_BASE      IO_ADDRESS(OMAP2_32KSYNCT_BASE)

#define io_p2v(pa)		((pa) + IO_OFFSET)/* Works for L3 and L4 */
#define io_v2p(va)		((va) - IO_OFFSET)/* Works for L3 and L4 */

/* MPU INTC registers */
#define IC_REG32_34XX(offset)	__REG32(IC_BASE + (offset))
#define INTC_MIR_0		IC_REG32_34XX(0x084)
#define INTC_MIR_1		IC_REG32_34XX(0x0A4)
#define INTC_MIR_2		IC_REG32_34XX(0x0C4)
#define INTC_MIR_SET_0		IC_REG32_34XX(0x08C)
#define INTC_MIR_SET_1		IC_REG32_34XX(0x0AC)
#define INTC_MIR_SET_2		IC_REG32_34XX(0x0CC)
#define INTC_MIR_CLEAR_0	IC_REG32_34XX(0x094)
#define INTC_MIR_CLEAR_1	IC_REG32_34XX(0x0B4)
#define INTC_MIR_CLEAR_2	IC_REG32_34XX(0x0D4)
#define INTCPS_SYSCONFIG        IC_REG32_34XX(0x010)
#define INTCPS_PROTECTION       IC_REG32_34XX(0x04C)
#define INTCPS_IDLE             IC_REG32_34XX(0x050)
#define INTCPS_THRESHOLD        IC_REG32_34XX(0x068)
#define INTCPS_PENDING_IRQ0	IC_REG32_34XX(0x098)
#define INTCPS_PENDING_IRQ1	IC_REG32_34XX(0x0B8)
#define INTCPS_PENDING_IRQ2	IC_REG32_34XX(0x0D8)

/* IO CONFIG */
#define CONTROL_REG32_34XX(offset)	__REG32(OMAP_CTRL_BASE + (offset))
#define SCRATCHPAD_BASE			CONTROL_REG32_34XX(0x910)
#define SCRATCHPAD_ROM_BASE		CONTROL_REG32_34XX(0x860)
#define OMAP2_CONTROL_STATUS		(OMAP_CTRL_BASE + 0x2f0)
#define CONTROL_SYSCONFIG               CONTROL_REG32_34XX(0x010)
#define CONTROL_DEVCONF0		CONTROL_REG32_34XX(0x274)
#define CONTROL_DEVCONF1		CONTROL_REG32_34XX(0x2D8)
#define CONTROL_IVA2_BOOTMOD		CONTROL_REG32_34XX(0x404)
#define CONTROL_IVA2_BOOTADDR		CONTROL_REG32_34XX(0x400)
#define CONTROL_PBIAS_1			CONTROL_REG32_34XX(0x520)
#define CONTROL_PADCONF_MCBSP		CONTROL_REG32_34XX(0x168)
#define CONTROL_PADCONF_UART3_CTS	CONTROL_REG32_34XX(0x16A)
#define CONTROL_PADCONF_UART3_RX	CONTROL_REG32_34XX(0x16C)
#define CONTROL_PADCONF_UART3_TX	CONTROL_REG32_34XX(0x170)
#define CONTROL_PADCONF_UART1_CTS	CONTROL_REG32_34XX(0x180)
#define CONTROL_PADCONF_UART2_RTS       CONTROL_REG32_34XX(0x174)
#define CONTROL_PADCONF_UART2_CTS       CONTROL_REG32_34XX(0x174)
#define CONTROL_PADCONF_OFF		CONTROL_REG32_34XX(0x270)
#define CONTROL_GENERAL_PURPOSE_STATUS	CONTROL_REG32_34XX(0x2F4)
#define CONTROL_MEM_DFTRW0		CONTROL_REG32_34XX(0x278)
#define CONTROL_MEM_DFTRW1		CONTROL_REG32_34XX(0x27C)
#define CONTROL_MSUSPENDMUX_0		CONTROL_REG32_34XX(0x290)
#define CONTROL_MSUSPENDMUX_1		CONTROL_REG32_34XX(0x294)
#define CONTROL_MSUSPENDMUX_2		CONTROL_REG32_34XX(0x298)
#define CONTROL_MSUSPENDMUX_3		CONTROL_REG32_34XX(0x29C)
#define CONTROL_MSUSPENDMUX_4		CONTROL_REG32_34XX(0x2A0)
#define CONTROL_MSUSPENDMUX_5		CONTROL_REG32_34XX(0x2A4)
#define CONTROL_SEC_CTRL		CONTROL_REG32_34XX(0x2B0)
#define CONTROL_CSIRXFE			CONTROL_REG32_34XX(0x2DC)
#define CONTROL_DEBOBS_0		CONTROL_REG32_34XX(0x420)
#define CONTROL_DEBOBS_1		CONTROL_REG32_34XX(0x424)
#define CONTROL_DEBOBS_2		CONTROL_REG32_34XX(0x428)
#define CONTROL_DEBOBS_3		CONTROL_REG32_34XX(0x42C)
#define CONTROL_DEBOBS_4		CONTROL_REG32_34XX(0x430)
#define CONTROL_DEBOBS_5		CONTROL_REG32_34XX(0x434)
#define CONTROL_DEBOBS_6		CONTROL_REG32_34XX(0x438)
#define CONTROL_DEBOBS_7		CONTROL_REG32_34XX(0x43C)
#define CONTROL_DEBOBS_8		CONTROL_REG32_34XX(0x440)
#define CONTROL_PROG_IO0		CONTROL_REG32_34XX(0x444)
#define CONTROL_PROG_IO1		CONTROL_REG32_34XX(0x448)
#define CONTROL_DSS_DPLL_SPREADING	CONTROL_REG32_34XX(0x450)
#define CONTROL_CORE_DPLL_SPREADING	CONTROL_REG32_34XX(0x454)
#define CONTROL_PER_DPLL_SPREADING	CONTROL_REG32_34XX(0x458)
#define CONTROL_USBHOST_DPLL_SPREADING	CONTROL_REG32_34XX(0x45C)
#define CONTROL_TEMP_SENSOR		CONTROL_REG32_34XX(0x524)
#define CONTROL_SRAMLDO4		CONTROL_REG32_34XX(0x528)
#define CONTROL_SRAMLDO5		CONTROL_REG32_34XX(0x52C)
#define CONTROL_CSI			CONTROL_REG32_34XX(0x530)
#define CONTROL_SCALABLE_OMAP_OCP	CONTROL_REG32_34XX(0x534)
#define CONTROL_SCALABLE_OMAP_STATUS	CONTROL_REG32_34XX(0x44C)


#define CONTROL_PADCONF_GPMC_A2		CONTROL_REG32_34XX(0x07c)
#define CONTROL_PADCONF_GPMC_A4		CONTROL_REG32_34XX(0x080)
#define CONTROL_PADCONF_GPMC_A6		CONTROL_REG32_34XX(0x084)
#define CONTROL_PADCONF_GPMC_A8		CONTROL_REG32_34XX(0x088)
#define CONTROL_PADCONF_GPMC_A10	CONTROL_REG32_34XX(0x08c)
#define CONTROL_PADCONF_GPMC_D1		CONTROL_REG32_34XX(0x090)
#define CONTROL_PADCONF_GPMC_D3		CONTROL_REG32_34XX(0x094)
#define CONTROL_PADCONF_GPMC_D5		CONTROL_REG32_34XX(0x098)
#define CONTROL_PADCONF_GPMC_D7		CONTROL_REG32_34XX(0x09c)
#define CONTROL_PADCONF_GPMC_D9		CONTROL_REG32_34XX(0x0a0)
#define CONTROL_PADCONF_GPMC_D11	CONTROL_REG32_34XX(0x0a4)
#define CONTROL_PADCONF_GPMC_D13	CONTROL_REG32_34XX(0x0a8)
#define CONTROL_PADCONF_GPMC_D15	CONTROL_REG32_34XX(0x0ac)
#define CONTROL_PADCONF_GPMC_NCS1	CONTROL_REG32_34XX(0x0b0)
#define CONTROL_PADCONF_GPMC_NCS3	CONTROL_REG32_34XX(0x0b4)
#define CONTROL_PADCONF_GPMC_NCS5	CONTROL_REG32_34XX(0x0b8)
#define CONTROL_PADCONF_GPMC_NCS7	CONTROL_REG32_34XX(0x0bc)
#define CONTROL_PADCONF_GPMC_NADV_ALE	CONTROL_REG32_34XX(0x0c0)
#define CONTROL_PADCONF_GPMC_NWE	CONTROL_REG32_34XX(0x0c4)
#define CONTROL_PADCONF_GPMC_NBE1	CONTROL_REG32_34XX(0x0c8)
#define CONTROL_PADCONF_GPMC_WAIT0	CONTROL_REG32_34XX(0x0cc)
#define CONTROL_PADCONF_GPMC_WAIT2	CONTROL_REG32_34XX(0x0d0)
#define CONTROL_PADCONF_DSS_PCLK	CONTROL_REG32_34XX(0x0d4)
#define CONTROL_PADCONF_DSS_VSYNC	CONTROL_REG32_34XX(0x0d8)
#define CONTROL_PADCONF_DSS_DATA0	CONTROL_REG32_34XX(0x0dc)
#define CONTROL_PADCONF_DSS_DATA2	CONTROL_REG32_34XX(0x0e0)
#define CONTROL_PADCONF_DSS_DATA4	CONTROL_REG32_34XX(0x0e4)
#define CONTROL_PADCONF_DSS_DATA6	CONTROL_REG32_34XX(0x0e8)
#define CONTROL_PADCONF_DSS_DATA8	CONTROL_REG32_34XX(0x0ec)
#define CONTROL_PADCONF_DSS_DATA10	CONTROL_REG32_34XX(0x0f0)
#define CONTROL_PADCONF_DSS_DATA12	CONTROL_REG32_34XX(0x0f4)
#define CONTROL_PADCONF_DSS_DATA14	CONTROL_REG32_34XX(0x0f8)
#define CONTROL_PADCONF_DSS_DATA16	CONTROL_REG32_34XX(0x0fc)
#define CONTROL_PADCONF_DSS_DATA18	CONTROL_REG32_34XX(0x100)
#define CONTROL_PADCONF_DSS_DATA20	CONTROL_REG32_34XX(0x104)
#define CONTROL_PADCONF_DSS_DATA22	CONTROL_REG32_34XX(0x108)
#define CONTROL_PADCONF_CAM_HS		CONTROL_REG32_34XX(0x10c)
#define CONTROL_PADCONF_CAM_XCLKA	CONTROL_REG32_34XX(0x110)
#define CONTROL_PADCONF_CAM_FLD		CONTROL_REG32_34XX(0x114)
#define CONTROL_PADCONF_CAM_D1          CONTROL_REG32_34XX(0x118)
#define CONTROL_PADCONF_CAM_D3          CONTROL_REG32_34XX(0x11c)
#define CONTROL_PADCONF_CAM_D5          CONTROL_REG32_34XX(0x120)
#define CONTROL_PADCONF_CAM_D7          CONTROL_REG32_34XX(0x124)
#define CONTROL_PADCONF_CAM_D9          CONTROL_REG32_34XX(0x128)
#define CONTROL_PADCONF_CAM_D11         CONTROL_REG32_34XX(0x12c)
#define CONTROL_PADCONF_CAM_WEN		CONTROL_REG32_34XX(0x130)
#define CONTROL_PADCONF_CSI2_DX0	CONTROL_REG32_34XX(0x134)
#define CONTROL_PADCONF_CSI2_DX1	CONTROL_REG32_34XX(0x138)
#define CONTROL_PADCONF_MCBSP2_FSX	CONTROL_REG32_34XX(0x13c)
#define CONTROL_PADCONF_MCBSP2_DR	CONTROL_REG32_34XX(0x140)
#define CONTROL_PADCONF_MMC1_CLK	CONTROL_REG32_34XX(0x144)
#define CONTROL_PADCONF_MMC1_DAT0	CONTROL_REG32_34XX(0x148)
#define CONTROL_PADCONF_MMC1_DAT2	CONTROL_REG32_34XX(0x14c)
#define CONTROL_PADCONF_MMC1_DAT4	CONTROL_REG32_34XX(0x150)
#define CONTROL_PADCONF_MMC1_DAT6	CONTROL_REG32_34XX(0x154)
#define CONTROL_PADCONF_MMC2_CLK	CONTROL_REG32_34XX(0x158)
#define CONTROL_PADCONF_MMC2_DAT0	CONTROL_REG32_34XX(0x15c)
#define CONTROL_PADCONF_MMC2_DAT2	CONTROL_REG32_34XX(0x160)
#define CONTROL_PADCONF_MMC2_DAT4	CONTROL_REG32_34XX(0x164)
#define CONTROL_PADCONF_MMC2_DAT6	CONTROL_REG32_34XX(0x168)
#define CONTROL_PADCONF_MCBSP3_DX	CONTROL_REG32_34XX(0x16c)
#define CONTROL_PADCONF_MCBSP3_CLKX	CONTROL_REG32_34XX(0x170)
#define CONTROL_PADCONF_UART2_CTS	CONTROL_REG32_34XX(0x174)
#define CONTROL_PADCONF_UART2_TX	CONTROL_REG32_34XX(0x178)
#define CONTROL_PADCONF_UART1_TX	CONTROL_REG32_34XX(0x17c)
#define CONTROL_PADCONF_UART1_CTS	CONTROL_REG32_34XX(0x180)
#define CONTROL_PADCONF_MCBSP4_CLKX	CONTROL_REG32_34XX(0x184)
#define CONTROL_PADCONF_MCBSP4_DX	CONTROL_REG32_34XX(0x188)
#define CONTROL_PADCONF_MCBSP1_CLKR	CONTROL_REG32_34XX(0x18c)
#define CONTROL_PADCONF_MCBSP1_DX	CONTROL_REG32_34XX(0x190)
#define CONTROL_PADCONF_MCBSP_CLKS	CONTROL_REG32_34XX(0x194)
#define CONTROL_PADCONF_MCBSP1_CLKX	CONTROL_REG32_34XX(0x198)
#define CONTROL_PADCONF_UART3_RTS_SD	CONTROL_REG32_34XX(0x19c)
#define CONTROL_PADCONF_UART3_TX_IRTX	CONTROL_REG32_34XX(0x1a0)
#define CONTROL_PADCONF_HSUSB0_STP	CONTROL_REG32_34XX(0x1a4)
#define CONTROL_PADCONF_HSUSB0_NXT	CONTROL_REG32_34XX(0x1a8)
#define CONTROL_PADCONF_HSUSB0_DATA1	CONTROL_REG32_34XX(0x1ac)
#define CONTROL_PADCONF_HSUSB0_DATA3	CONTROL_REG32_34XX(0x1b0)
#define CONTROL_PADCONF_HSUSB0_DATA5	CONTROL_REG32_34XX(0x1b4)
#define CONTROL_PADCONF_HSUSB0_DATA7	CONTROL_REG32_34XX(0x1b8)
#define CONTROL_PADCONF_I2C1_SDA	CONTROL_REG32_34XX(0x1bc)
#define CONTROL_PADCONF_I2C2_SDA	CONTROL_REG32_34XX(0x1c0)
#define CONTROL_PADCONF_I2C3_SDA	CONTROL_REG32_34XX(0x1c4)
#define CONTROL_PADCONF_MCSPI1_CLK	CONTROL_REG32_34XX(0x1c8)
#define CONTROL_PADCONF_MCSPI1_SOMI	CONTROL_REG32_34XX(0x1cc)
#define CONTROL_PADCONF_MCSPI1_CS1	CONTROL_REG32_34XX(0x1d0)
#define CONTROL_PADCONF_MCSPI1_CS3	CONTROL_REG32_34XX(0x1d4)
#define CONTROL_PADCONF_MCSPI2_SIMO	CONTROL_REG32_34XX(0x1d8)
#define CONTROL_PADCONF_MCSPI2_CS0  	CONTROL_REG32_34XX(0x1dc)
#define CONTROL_PADCONF_SYS_NIRQ    	CONTROL_REG32_34XX(0x1e0)
#define CONTROL_PADCONF_SAD2D_MCAD0 	CONTROL_REG32_34XX(0x1e4)
#define CONTROL_PADCONF_SAD2D_MCAD2 	CONTROL_REG32_34XX(0x1e8)
#define CONTROL_PADCONF_SAD2D_MCAD4 	CONTROL_REG32_34XX(0x1ec)
#define CONTROL_PADCONF_SAD2D_MCAD6 	CONTROL_REG32_34XX(0x1f0)
#define CONTROL_PADCONF_SAD2D_MCAD8 	CONTROL_REG32_34XX(0x1f4)
#define CONTROL_PADCONF_SAD2D_MCAD10	CONTROL_REG32_34XX(0x1f8)
#define CONTROL_PADCONF_SAD2D_MCAD12	CONTROL_REG32_34XX(0x1fc)
#define CONTROL_PADCONF_SAD2D_MCAD14	CONTROL_REG32_34XX(0x200)
#define CONTROL_PADCONF_SAD2D_MCAD16	CONTROL_REG32_34XX(0x204)
#define CONTROL_PADCONF_SAD2D_MCAD18	CONTROL_REG32_34XX(0x208)
#define CONTROL_PADCONF_SAD2D_MCAD20	CONTROL_REG32_34XX(0x20c)
#define CONTROL_PADCONF_SAD2D_MCAD22	CONTROL_REG32_34XX(0x210)
#define CONTROL_PADCONF_SAD2D_MCAD24	CONTROL_REG32_34XX(0x214)
#define CONTROL_PADCONF_SAD2D_MCAD26	CONTROL_REG32_34XX(0x218)
#define CONTROL_PADCONF_SAD2D_MCAD28	CONTROL_REG32_34XX(0x21c)
#define CONTROL_PADCONF_SAD2D_MCAD30	CONTROL_REG32_34XX(0x220)
#define CONTROL_PADCONF_SAD2D_MCAD32	CONTROL_REG32_34XX(0x224)
#define CONTROL_PADCONF_SAD2D_MCAD34	CONTROL_REG32_34XX(0x228)
#define CONTROL_PADCONF_SAD2D_MCAD36	CONTROL_REG32_34XX(0x22c)
#define CONTROL_PADCONF_SAD2D_NRESPWRON CONTROL_REG32_34XX(0x230)
#define CONTROL_PADCONF_SAD2D_ARMNIRQ	CONTROL_REG32_34XX(0x234)
#define CONTROL_PADCONF_SAD2D_SPINT	CONTROL_REG32_34XX(0x238)
#define CONTROL_PADCONF_SAD2D_DMAREQ0	CONTROL_REG32_34XX(0x23c)
#define CONTROL_PADCONF_SAD2D_DMAREQ2	CONTROL_REG32_34XX(0x240)
#define CONTROL_PADCONF_SAD2D_NTRST	CONTROL_REG32_34XX(0x244)
#define CONTROL_PADCONF_SAD2D_TDO	CONTROL_REG32_34XX(0x248)
#define CONTROL_PADCONF_SAD2D_TCK	CONTROL_REG32_34XX(0x24c)
#define CONTROL_PADCONF_SAD2D_MSTDBY	CONTROL_REG32_34XX(0x250)
#define CONTROL_PADCONF_SAD2D_IDLEACK	CONTROL_REG32_34XX(0x154)
#define CONTROL_PADCONF_SAD2D_SWRITE    CONTROL_REG32_34XX(0x158)
#define CONTROL_PADCONF_SAD2D_SREAD     CONTROL_REG32_34XX(0x15c)
#define CONTROL_PADCONF_SAD2D_SBUSFLAG  CONTROL_REG32_34XX(0x160)
#define CONTROL_PADCONF_SDRC_CKE1       CONTROL_REG32_34XX(0x164)
#define CONTROL_PADCONF_ETK_CLK         CONTROL_REG32_34XX(0x5d8)
#define CONTROL_PADCONF_ETK_D0          CONTROL_REG32_34XX(0x5dc)
#define CONTROL_PADCONF_ETK_D2          CONTROL_REG32_34XX(0x5e0)
#define CONTROL_PADCONF_ETK_D4          CONTROL_REG32_34XX(0x5e4)
#define CONTROL_PADCONF_ETK_D6          CONTROL_REG32_34XX(0x5e8)
#define CONTROL_PADCONF_ETK_D8          CONTROL_REG32_34XX(0x5ec)
#define CONTROL_PADCONF_ETK_D10         CONTROL_REG32_34XX(0x5f0)
#define CONTROL_PADCONF_ETK_D12         CONTROL_REG32_34XX(0x5f4)
#define CONTROL_PADCONF_ETK_D14         CONTROL_REG32_34XX(0x5f8)


#define CONTROL_PADCONF_I2C4_SCL	CONTROL_REG32_34XX(0xA00)
#define CONTROL_PADCONF_SYS_32K		CONTROL_REG32_34XX(0xA04)
#define CONTROL_PADCONF_SYS_NRESWARM    CONTROL_REG32_34XX(0xA08)
#define CONTROL_PADCONF_SYS_BOOT1	CONTROL_REG32_34XX(0xA0C)
#define CONTROL_PADCONF_SYS_BOOT3	CONTROL_REG32_34XX(0xA10)
#define CONTROL_PADCONF_SYS_BOOT5	CONTROL_REG32_34XX(0xA14)
#define CONTROL_PADCONF_SYS_OFF_MODE	CONTROL_REG32_34XX(0xA18)
#define CONTROL_PADCONF_JTAG_NTRST	CONTROL_REG32_34XX(0xA1c)
#define CONTROL_PADCONF_JTAG_TMS_TMSC	CONTROL_REG32_34XX(0xA20)
#define CONTROL_PADCONF_JTAG_EMU0	CONTROL_REG32_34XX(0xA24)
#define CONTROL_PADCONF_SAD2D_SWAKEUP	CONTROL_REG32_34XX(0xA4C)
#define CONTROL_PADCONF_JTAG_TDO	CONTROL_REG32_34XX(0xA50)

/* IO_PAD bit masks */
#define IO_PAD_MUXMODE0			0x0
#define IO_PAD_MUXMODE1			0x1
#define IO_PAD_MUXMODE2			0x2
#define IO_PAD_MUXMODE3			0x3
#define IO_PAD_MUXMODE4			0x4
#define IO_PAD_MUXMODE5			0x5
#define IO_PAD_MUXMODE6			0x6
#define IO_PAD_MUXMODE7			0x7
#define IO_PAD_PULLUDENABLE		0x8
#define IO_PAD_PULLTYPESELECT		0x10
#define IO_PAD_INPUTENABLE		0x100
#define IO_PAD_OFFENABLE		0x200
#define IO_PAD_OFFOUTENABLE		0x400
#define IO_PAD_OFFOUTVALUE		0x800
#define IO_PAD_OFFPULLUDENABLE		0x1000
#define IO_PAD_OFFPULLTYPESELECT	0x2000
#define IO_PAD_WAKEUPENABLE		0x4000
#define IO_PAD_WAKEUPEVENT		0x8000
#define IO_PAD_HIGH_SHIFT		0x10

/* GPMC registers */
#define GPMC_BASE		OMAP34XX_GPMC_BASE
#define GPMC_REG32_34XX(offset) __REG32(GPMC_BASE + (offset))
#define GPMC_SYS_CONFIG		GPMC_REG32_34XX(0x10)
#define GPMC_IRQ_ENABLE		GPMC_REG32_34XX(0x1C)
#define GPMC_TIMEOUT_CONTROL	GPMC_REG32_34XX(0x40)
#define GPMC_CFG		GPMC_REG32_34XX(0x50)
#define GPMC_PREFETCH_CONFIG_1	GPMC_REG32_34XX(0x1E0)
#define GPMC_PREFETCH_CONFIG_2	GPMC_REG32_34XX(0x1E4)
#define GPMC_PREFETCH_CTRL	GPMC_REG32_34XX(0x1EC)
#define GPMC_CONFIG1_0		GPMC_REG32_34XX(0x60)
#define GPMC_CONFIG1_1		GPMC_REG32_34XX(0x90)
#define GPMC_CONFIG1_2		GPMC_REG32_34XX(0xC0)
#define GPMC_CONFIG1_3		GPMC_REG32_34XX(0xF0)
#define GPMC_CONFIG1_4		GPMC_REG32_34XX(0x120)
#define GPMC_CONFIG1_5		GPMC_REG32_34XX(0x150)
#define GPMC_CONFIG1_6		GPMC_REG32_34XX(0x180)
#define GPMC_CONFIG1_7		GPMC_REG32_34XX(0x1B0)
#define GPMC_CONFIG2_0		GPMC_REG32_34XX(0x64)
#define GPMC_CONFIG2_1		GPMC_REG32_34XX(0x94)
#define GPMC_CONFIG2_2		GPMC_REG32_34XX(0xC4)
#define GPMC_CONFIG2_3		GPMC_REG32_34XX(0xF4)
#define GPMC_CONFIG2_4		GPMC_REG32_34XX(0x124)
#define GPMC_CONFIG2_5		GPMC_REG32_34XX(0x154)
#define GPMC_CONFIG2_6		GPMC_REG32_34XX(0x184)
#define GPMC_CONFIG2_7		GPMC_REG32_34XX(0x1B4)
#define GPMC_CONFIG3_0		GPMC_REG32_34XX(0x68)
#define GPMC_CONFIG3_1		GPMC_REG32_34XX(0x98)
#define GPMC_CONFIG3_2		GPMC_REG32_34XX(0xC8)
#define GPMC_CONFIG3_3		GPMC_REG32_34XX(0xF8)
#define GPMC_CONFIG3_4		GPMC_REG32_34XX(0x128)
#define GPMC_CONFIG3_5		GPMC_REG32_34XX(0x158)
#define GPMC_CONFIG3_6		GPMC_REG32_34XX(0x188)
#define GPMC_CONFIG3_7		GPMC_REG32_34XX(0x1B8)
#define GPMC_CONFIG4_0		GPMC_REG32_34XX(0x6C)
#define GPMC_CONFIG4_1		GPMC_REG32_34XX(0x9C)
#define GPMC_CONFIG4_2		GPMC_REG32_34XX(0xCC)
#define GPMC_CONFIG4_3		GPMC_REG32_34XX(0xFC)
#define GPMC_CONFIG4_4		GPMC_REG32_34XX(0x12C)
#define GPMC_CONFIG4_5		GPMC_REG32_34XX(0x15C)
#define GPMC_CONFIG4_6		GPMC_REG32_34XX(0x18C)
#define GPMC_CONFIG4_7		GPMC_REG32_34XX(0x1BC)
#define GPMC_CONFIG5_0		GPMC_REG32_34XX(0x70)
#define GPMC_CONFIG5_1		GPMC_REG32_34XX(0xA0)
#define GPMC_CONFIG5_2		GPMC_REG32_34XX(0xD0)
#define GPMC_CONFIG5_3		GPMC_REG32_34XX(0x100)
#define GPMC_CONFIG5_4		GPMC_REG32_34XX(0x130)
#define GPMC_CONFIG5_5		GPMC_REG32_34XX(0x160)
#define GPMC_CONFIG5_6		GPMC_REG32_34XX(0x190)
#define GPMC_CONFIG5_7		GPMC_REG32_34XX(0x1C0)
#define GPMC_CONFIG6_0		GPMC_REG32_34XX(0x74)
#define GPMC_CONFIG6_1		GPMC_REG32_34XX(0xA4)
#define GPMC_CONFIG6_2		GPMC_REG32_34XX(0xD4)
#define GPMC_CONFIG6_3		GPMC_REG32_34XX(0x104)
#define GPMC_CONFIG6_4		GPMC_REG32_34XX(0x134)
#define GPMC_CONFIG6_5		GPMC_REG32_34XX(0x164)
#define GPMC_CONFIG6_6		GPMC_REG32_34XX(0x194)
#define GPMC_CONFIG6_7		GPMC_REG32_34XX(0x1C4)
#define GPMC_CONFIG7_0		GPMC_REG32_34XX(0x78)
#define GPMC_CONFIG7_1		GPMC_REG32_34XX(0xA8)
#define GPMC_CONFIG7_2		GPMC_REG32_34XX(0xD8)
#define GPMC_CONFIG7_3		GPMC_REG32_34XX(0x108)
#define GPMC_CONFIG7_4		GPMC_REG32_34XX(0x138)
#define GPMC_CONFIG7_5		GPMC_REG32_34XX(0x168)
#define GPMC_CONFIG7_6		GPMC_REG32_34XX(0x198)
#define GPMC_CONFIG7_7		GPMC_REG32_34XX(0x1C8)

#define SCRATHPAD_SDRCPWR_OFFSET    0x1D

#endif

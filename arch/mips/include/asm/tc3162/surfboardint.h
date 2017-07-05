/*
 * Copyright (C) 2001 Palmchip Corporation.  All rights reserved.
 *
 * ########################################################################
 *
 *  This program is free software; you can distribute it and/or modify it
 *  under the terms of the GNU General Public License (Version 2) as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston MA 02111-1307, USA.
 *
 * ########################################################################
 *
 * Defines for the Surfboard interrupt controller.
 *
 */
#ifndef __ASM_MACH_MIPS_TC3262_SURFBOARDINT_H
#define __ASM_MACH_MIPS_TC3262_SURFBOARDINT_H

#if defined(CONFIG_ECONET_EN75XX_MP)

#define SURFBOARDINT_GPIO		11	/* GPIO */
#define SURFBOARDINT_PCM		12	/* PCM */
#define SURFBOARDINT_DMA		15	/* DMA */
#define SURFBOARDINT_I2S 		35	/* I2S */
#define SURFBOARDINT_ESW		16	/* ESW */
#define SURFBOARDINT_USB		18	/* USB */
#define SURFBOARDINT_FE			22	/* Frame Engine */
#define SURFBOARDINT_QDMA		23	/* QDMA */
#define SURFBOARDINT_PCIE0		24	/* PCIe0 */
#define SURFBOARDINT_PCIE1		25	/* PCIe1 */
#define SURFBOARDINT_CRYPTO		29	/* CryptoEngine */

#else

#define SURFBOARDINT_GPIO		11	/* GPIO */
#define SURFBOARDINT_DMA		15	/* DMA */
#define SURFBOARDINT_I2S 		35	/* I2S */
#define SURFBOARDINT_ESW		16	/* ESW */
#define SURFBOARDINT_UHST		18	/* USB Host */
#define SURFBOARDINT_PCM		12	/* PCM */
#define SURFBOARDINT_FE			22	/* Frame Engine */
#define SURFBOARDINT_PCIE0		25	/* PCIe0 */
#define SURFBOARDINT_PCIE1		24	/* PCIe1 */
#define SURFBOARDINT_CRYPTO		29	/* CryptoEngine */

#endif

extern void tc_enable_irq(unsigned int irq);
extern void tc_disable_irq(unsigned int irq);

#endif

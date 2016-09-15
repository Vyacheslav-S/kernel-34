/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 5F., No.36, Taiyuan St., Jhubei City,
 * Hsinchu County 302,
 * Taiwan, R.O.C.
 *
 * (c) Copyright, Ralink Technology, Inc.
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 *  THIS  SOFTWARE  IS PROVIDED   ``AS  IS'' AND   ANY  EXPRESS OR IMPLIED
 *  WARRANTIES,   INCLUDING, BUT NOT  LIMITED  TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 *  NO  EVENT  SHALL   THE AUTHOR  BE    LIABLE FOR ANY   DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *  NOT LIMITED   TO, PROCUREMENT OF  SUBSTITUTE GOODS  OR SERVICES; LOSS OF
 *  USE, DATA,  OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN  CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  You should have received a copy of the  GNU General Public License along
 *  with this program; if not, write  to the Free Software Foundation, Inc.,
 *  675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *
 ***************************************************************************
 */

#ifndef _GDMA_H
#define _GDMA_H

#include <asm/rt2880/rt_mmap.h>

/*
 * DEFINITIONS AND MACROS
 */
#define MOD_VERSION 			"0.4"

#if defined (CONFIG_RALINK_RT3052)
#define MAX_GDMA_CHANNEL		8
#elif defined (CONFIG_RALINK_RT3883) || defined (CONFIG_RALINK_RT3352) || \
      defined (CONFIG_RALINK_RT5350) || defined (CONFIG_RALINK_RT6XXX_MP) || \
      defined (CONFIG_RALINK_MT7620) || defined (CONFIG_RALINK_MT7621) || \
      defined (CONFIG_RALINK_MT7628)
#define MAX_GDMA_CHANNEL		16
#else
#error Please Choose System Type
#endif

#define RALINK_GDMA_CTRL_BASE		RALINK_GDMA_BASE
#if defined (CONFIG_RALINK_RT3052)
#define RALINK_GDMAISTS			(RALINK_GDMA_BASE + 0x80)
#define RALINK_GDMAGCT			(RALINK_GDMA_BASE + 0x88)
#elif defined (CONFIG_RALINK_RT3883) || defined (CONFIG_RALINK_RT3352) || \
      defined (CONFIG_RALINK_RT5350) || defined (CONFIG_RALINK_RT6XXX_MP) || \
      defined (CONFIG_RALINK_MT7620) || defined (CONFIG_RALINK_MT7621) || \
      defined (CONFIG_RALINK_MT7628)
#define RALINK_GDMA_UNMASKINT		(RALINK_GDMA_BASE + 0x200)
#define RALINK_GDMA_DONEINT		(RALINK_GDMA_BASE + 0x204)
#define RALINK_GDMA_GCT			(RALINK_GDMA_BASE + 0x220)
#endif

#define GDMA_READ_REG(addr)		(*(volatile u32 *)(addr))
#define GDMA_WRITE_REG(addr, val)	*((volatile u32 *)(addr)) = (u32)(val)
#define GET_GDMA_IP_VER			(GDMA_READ_REG(RALINK_GDMA_GCT) & 0x6) >> 1 //GDMA_GCT[2:1]

/* 
 * 12bytes=GDMA Channel n Source Address(4) +
 *         GDMA Channel n Destination Address(4) +
 *         GDMA Channel n Control Register(4)
 *
 */
#define GDMA_SRC_REG(ch)		(RALINK_GDMA_BASE + ch*16)
#define GDMA_DST_REG(ch)		(GDMA_SRC_REG(ch) + 4)
#define GDMA_CTRL_REG(ch)		(GDMA_DST_REG(ch) + 4)
#define GDMA_CTRL_REG1(ch)		(GDMA_CTRL_REG(ch) + 4)

//GDMA Interrupt Status Register
#if defined (CONFIG_RALINK_RT3052)
#define UNMASK_INT_STATUS(ch)		(ch+16)
#elif defined (CONFIG_RALINK_RT3883) || defined (CONFIG_RALINK_RT3352) || \
      defined (CONFIG_RALINK_RT5350) || defined (CONFIG_RALINK_RT6XXX_MP) || \
      defined (CONFIG_RALINK_MT7620) || defined (CONFIG_RALINK_MT7621) || \
      defined (CONFIG_RALINK_MT7628)
#define UNMASK_INT_STATUS(ch)		(ch)
#endif
#define TXDONE_INT_STATUS(ch)		(ch)

//Control Reg0
#define MODE_SEL_OFFSET			0
#define CH_EBL_OFFSET			1
#define CH_DONEINT_EBL_OFFSET		2
#define BRST_SIZE_OFFSET		3
#define DST_BRST_MODE_OFFSET		6
#define SRC_BRST_MODE_OFFSET		7
#define TRANS_CNT_OFFSET		16

//Control Reg1
#if defined (CONFIG_RALINK_RT3052)
#define CH_UNMASKINT_EBL_OFFSET		4
#define NEXT_UNMASK_CH_OFFSET		1
#elif defined (CONFIG_RALINK_RT3883) || defined (CONFIG_RALINK_RT3352) || \
      defined (CONFIG_RALINK_RT5350) || defined (CONFIG_RALINK_RT6XXX_MP) || \
      defined (CONFIG_RALINK_MT7620) || defined (CONFIG_RALINK_MT7621) || \
      defined (CONFIG_RALINK_MT7628)
#define CH_UNMASKINT_EBL_OFFSET		1
#define NEXT_UNMASK_CH_OFFSET		3
#endif
#define COHERENT_INT_EBL_OFFSET		2
#define CH_MASK_OFFSET			0

#if defined (CONFIG_RALINK_RT3052)
//Control Reg0
#define DST_DMA_REQ_OFFSET		8
#define SRC_DMA_REQ_OFFSET		12
#elif defined (CONFIG_RALINK_RT3883) || defined (CONFIG_RALINK_RT3352) || \
      defined (CONFIG_RALINK_RT5350) || defined (CONFIG_RALINK_RT6XXX_MP) || \
      defined (CONFIG_RALINK_MT7620) || defined (CONFIG_RALINK_MT7621) || \
      defined (CONFIG_RALINK_MT7628)
//Control Reg1
#define DST_DMA_REQ_OFFSET		8
#define SRC_DMA_REQ_OFFSET		16
#endif

//#define GDMA_DEBUG
#ifdef GDMA_DEBUG
#define GDMA_PRINT(fmt, args...) printk(KERN_INFO "GDMA: " fmt, ## args)
#else
#define GDMA_PRINT(fmt, args...) { }
#endif

/*
 * TYPEDEFS AND STRUCTURES
 */

enum GdmaDmaReqNum {
#if defined (CONFIG_RALINK_RT6XXX_MP)
	DMA_NAND_REQ=0,
#else
	DMA_NAND_REQ=1,
#endif
#if defined (CONFIG_RALINK_RT3052)
	DMA_MEM_REQ=8
#elif defined (CONFIG_RALINK_RT3883)
	DMA_MEM_REQ=16
#else
	DMA_MEM_REQ=32
#endif
};

#define BURST_SIZE_4B	0	/* 1 transfer */
#define BURST_SIZE_8B	1	/* 2 transfer */
#define	BURST_SIZE_16B	2	/* 4 transfer */
#define	BURST_SIZE_32B	3	/* 8 transfer */
#define BURST_SIZE_64B	4	/* 16 transfer */

#define SW_MODE 1
#define HW_MODE 0
#define TRN_FIX 1
#define TRN_INC 0

int _ra_nand_prepare_dma_pull(unsigned long dst, int len);
int _ra_nand_dma_pull(unsigned long dst, int len);
int _ra_nand_dma_push(unsigned long src, int len);

#endif

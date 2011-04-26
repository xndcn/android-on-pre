/* linux/include/asm-arm/arch-s3c2410/irqs.h
 *
 * Copyright (c) 2003-2005 Simtec Electronics
 *   Ben Dooks <ben@simtec.co.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/


#ifndef __ASM_ARCH_IRQS_H
#define __ASM_ARCH_IRQS_H __FILE__

#ifndef __ASM_ARM_IRQ_H
#error "Do not include this directly, instead #include <asm/irq.h>"
#endif

#if !defined(CONFIG_CPU_S3C6400) && !defined(CONFIG_CPU_S3C6410) 

/* we keep the first set of CPU IRQs out of the range of
 * the ISA space, so that the PC104 has them to itself
 * and we don't end up having to do horrible things to the
 * standard ISA drivers....
 */

#define S3C2410_CPUIRQ_OFFSET	 (16)

#define S3C2410_IRQ(x) ((x) + S3C2410_CPUIRQ_OFFSET)

/* main cpu interrupts */
#define IRQ_EINT0      S3C2410_IRQ(0)	    /* 16 */
#define IRQ_EINT1      S3C2410_IRQ(1)
#define IRQ_EINT2      S3C2410_IRQ(2)
#define IRQ_EINT3      S3C2410_IRQ(3)
#define IRQ_EINT4t7    S3C2410_IRQ(4)	    /* 20 */
#define IRQ_EINT8t23   S3C2410_IRQ(5)
#define IRQ_RESERVED6  S3C2410_IRQ(6)	    /* for s3c2410 */
#define IRQ_CAM        S3C2410_IRQ(6)	    /* for s3c2440,s3c2443 */
#define IRQ_BATT_FLT   S3C2410_IRQ(7)
#define IRQ_TICK       S3C2410_IRQ(8)	    /* 24 */
#define IRQ_WDT	       S3C2410_IRQ(9)	    /* WDT/AC97 for s3c2443 */
#define IRQ_TIMER0     S3C2410_IRQ(10)
#define IRQ_TIMER1     S3C2410_IRQ(11)
#define IRQ_TIMER2     S3C2410_IRQ(12)
#define IRQ_TIMER3     S3C2410_IRQ(13)
#define IRQ_TIMER4     S3C2410_IRQ(14)
#define IRQ_UART2      S3C2410_IRQ(15)
#define IRQ_LCD	       S3C2410_IRQ(16)	    /* 32 */
#define IRQ_DMA0       S3C2410_IRQ(17)	    /* IRQ_DMA for s3c2443 */
#define IRQ_DMA1       S3C2410_IRQ(18)
#define IRQ_DMA2       S3C2410_IRQ(19)
#define IRQ_DMA3       S3C2410_IRQ(20)
#define IRQ_SDI	       S3C2410_IRQ(21)
#define IRQ_SPI0       S3C2410_IRQ(22)
#define IRQ_UART1      S3C2410_IRQ(23)
#define IRQ_RESERVED24 S3C2410_IRQ(24)	    /* 40 */
#define IRQ_NFCON      S3C2410_IRQ(24)	    /* for s3c2440 */
#define IRQ_USBD       S3C2410_IRQ(25)
#define IRQ_USBH       S3C2410_IRQ(26)
#define IRQ_IIC	       S3C2410_IRQ(27)
#define IRQ_UART0      S3C2410_IRQ(28)	    /* 44 */
#define IRQ_SPI1       S3C2410_IRQ(29)
#define IRQ_RTC	       S3C2410_IRQ(30)
#define IRQ_ADCPARENT  S3C2410_IRQ(31)

/* interrupts generated from the external interrupts sources */
#define IRQ_EINT4      S3C2410_IRQ(32)	   /* 48 */
#define IRQ_EINT5      S3C2410_IRQ(33)
#define IRQ_EINT6      S3C2410_IRQ(34)
#define IRQ_EINT7      S3C2410_IRQ(35)
#define IRQ_EINT8      S3C2410_IRQ(36)
#define IRQ_EINT9      S3C2410_IRQ(37)
#define IRQ_EINT10     S3C2410_IRQ(38)
#define IRQ_EINT11     S3C2410_IRQ(39)
#define IRQ_EINT12     S3C2410_IRQ(40)
#define IRQ_EINT13     S3C2410_IRQ(41)
#define IRQ_EINT14     S3C2410_IRQ(42)
#define IRQ_EINT15     S3C2410_IRQ(43)
#define IRQ_EINT16     S3C2410_IRQ(44)
#define IRQ_EINT17     S3C2410_IRQ(45)
#define IRQ_EINT18     S3C2410_IRQ(46)
#define IRQ_EINT19     S3C2410_IRQ(47)
#define IRQ_EINT20     S3C2410_IRQ(48)	   /* 64 */
#define IRQ_EINT21     S3C2410_IRQ(49)
#define IRQ_EINT22     S3C2410_IRQ(50)
#define IRQ_EINT23     S3C2410_IRQ(51)


#define IRQ_EINT(x)    S3C2410_IRQ((x >= 4) ? (IRQ_EINT4 + (x) - 4) : (S3C2410_IRQ(0) + (x)))

#define IRQ_LCD_FIFO   S3C2410_IRQ(52)
#define IRQ_LCD_FRAME  S3C2410_IRQ(53)

/* IRQs for the interal UARTs, and ADC
 * these need to be ordered in number of appearance in the
 * SUBSRC mask register
*/

#define S3C2410_IRQSUB(x)	S3C2410_IRQ((x)+54)

#define IRQ_S3CUART_RX0		S3C2410_IRQSUB(0)	/* 70 */
#define IRQ_S3CUART_TX0		S3C2410_IRQSUB(1)
#define IRQ_S3CUART_ERR0	S3C2410_IRQSUB(2)

#define IRQ_S3CUART_RX1		S3C2410_IRQSUB(3)	/* 73 */
#define IRQ_S3CUART_TX1		S3C2410_IRQSUB(4)
#define IRQ_S3CUART_ERR1	S3C2410_IRQSUB(5)

#define IRQ_S3CUART_RX2		S3C2410_IRQSUB(6)	/* 76 */
#define IRQ_S3CUART_TX2		S3C2410_IRQSUB(7)
#define IRQ_S3CUART_ERR2	S3C2410_IRQSUB(8)

#define IRQ_TC			S3C2410_IRQSUB(9)
#define IRQ_ADC			S3C2410_IRQSUB(10)

/* extra irqs for s3c2412 */

#define IRQ_S3C2412_CFSDI	S3C2410_IRQ(21)

#define IRQ_S3C2412_SDI		S3C2410_IRQSUB(13)
#define IRQ_S3C2412_CF		S3C2410_IRQSUB(14)

/* extra irqs for s3c2440 */

#define IRQ_S3C2440_CAM_C	S3C2410_IRQSUB(11)	/* S3C2443 too */
#define IRQ_S3C2440_CAM_P	S3C2410_IRQSUB(12)	/* S3C2443 too */
#define IRQ_S3C2440_WDT		S3C2410_IRQSUB(13)
#define IRQ_S3C2440_AC97	S3C2410_IRQSUB(14)

/* irqs for s3c2443 */

#define IRQ_S3C2443_DMA		S3C2410_IRQ(17)		/* IRQ_DMA1 */
#define IRQ_S3C2443_UART3	S3C2410_IRQ(18)		/* IRQ_DMA2 */
#define IRQ_S3C2443_CFCON	S3C2410_IRQ(19)		/* IRQ_DMA3 */
#define IRQ_S3C2443_HSMMC	S3C2410_IRQ(20)		/* IRQ_SDI */
#define IRQ_S3C2443_SDI1	S3C2410_IRQ(20)		/* IRQ_SDI */
#define IRQ_S3C2443_NAND	S3C2410_IRQ(24)		/* reserved */

#define IRQ_S3C2443_LCD1	S3C2410_IRQSUB(14)
#define IRQ_S3C2443_LCD2	S3C2410_IRQSUB(15)
#define IRQ_S3C2443_LCD3	S3C2410_IRQSUB(16)
#define IRQ_S3C2443_LCD4	S3C2410_IRQSUB(17)

#define IRQ_S3C2443_DMA0	S3C2410_IRQSUB(18)
#define IRQ_S3C2443_DMA1	S3C2410_IRQSUB(19)
#define IRQ_S3C2443_DMA2	S3C2410_IRQSUB(20)
#define IRQ_S3C2443_DMA3	S3C2410_IRQSUB(21)
#define IRQ_S3C2443_DMA4	S3C2410_IRQSUB(22)
#define IRQ_S3C2443_DMA5	S3C2410_IRQSUB(23)

#if defined(CONFIG_CPU_S3C2450) || defined(CONFIG_CPU_S3C2416)
#define IRQ_S3C2443_DMA6	S3C2410_IRQSUB(29)
#define IRQ_S3C2443_DMA7	S3C2410_IRQSUB(30)
#endif

/* UART3 */
#define IRQ_S3C2443_RX3		S3C2410_IRQSUB(24)
#define IRQ_S3C2443_TX3		S3C2410_IRQSUB(25)
#define IRQ_S3C2443_ERR3	S3C2410_IRQSUB(26)

#define IRQ_S3C2443_WDT		S3C2410_IRQSUB(27)
#define IRQ_S3C2443_AC97	S3C2410_IRQSUB(28)

#if defined (CONFIG_CPU_S3C2443) || defined (CONFIG_CPU_S3C2450) || defined(CONFIG_CPU_S3C2416)
#define IRQ_CFCON	        S3C2410_IRQ(19)
#define IRQ_SDI_1	        S3C2410_IRQ(20)
#define IRQ_SDI_0	        S3C2410_IRQ(21)

#if defined(CONFIG_CPU_S3C2450) || defined (CONFIG_CPU_S3C2416)
#define IRQ_S3C2450_2D		S3C2410_IRQSUB(31)
#define IRQ_S3C2450_IIC1	S3C2410_IRQSUB(32)
#define IRQ_S3C2450_GIB		S3C2410_IRQSUB(33)
#define IRQ_S3C2450_Reserved	S3C2410_IRQSUB(34)
#define IRQ_S3C2450_PCM0	S3C2410_IRQSUB(35)
#define IRQ_S3C2450_PCM1	S3C2410_IRQSUB(36)
#define IRQ_S3C2450_I2S0	S3C2410_IRQSUB(37)
#define IRQ_S3C2450_I2S1	S3C2410_IRQSUB(38)

#define NR_IRQS (IRQ_S3C2450_I2S1+1)
#else
#define NR_IRQS (IRQ_S3C2443_AC97+1)
#endif

#else
#define NR_IRQS (IRQ_S3C2440_AC97+1)
#endif


#else /* CONFIG_CPU_S3C6400 || CONFIG_CPU_S3C6410 */ 

#define S3C6400_CPUIRQ_OFFSET	 (0)

#define S3C6400_IRQ(x) ((x) + S3C6400_CPUIRQ_OFFSET)

/******** TZIC0/VIC0 *****************/
/* main cpu interrupts */
#define IRQ_EINT0_3	S3C6400_IRQ(0)
#define IRQ_EINT4_11	S3C6400_IRQ(1)
#define IRQ_RTC_TIC	S3C6400_IRQ(2)
#define IRQ_CAMIF_C	S3C6400_IRQ(3)
#define IRQ_CAMIF_P	S3C6400_IRQ(4)
#define IRQ_IIC1	S3C6400_IRQ(5)

#ifdef CONFIG_CPU_S3C6410
#define IRQ_IIS		S3C6400_IRQ(6)
#else
#define IRQ_CAMIF_MP	S3C6400_IRQ(6)
#endif

#define IRQ_CAMIF_WE_C	S3C6400_IRQ(7)
#if defined(CONFIG_CPU_S3C6410)
#define IRQ_3D		S3C6400_IRQ(8)
#else
#define IRQ_CAMIF_WE_P	S3C6400_IRQ(8)
#endif

#define IRQ_POST0	S3C6400_IRQ(9)
#define IRQ_ROTATOR	S3C6400_IRQ(10)
#define IRQ_2D		S3C6400_IRQ(11)
#define IRQ_TVENC	S3C6400_IRQ(12)
#define IRQ_SCALER	S3C6400_IRQ(13)
#define IRQ_BATF	S3C6400_IRQ(14)
#define IRQ_JPEG	S3C6400_IRQ(15)
#define IRQ_MFC		S3C6400_IRQ(16)
#define IRQ_SDMA0	S3C6400_IRQ(17)
#define IRQ_SDMA1	S3C6400_IRQ(18)
#define IRQ_ARM_DMAERR	S3C6400_IRQ(19)
#define IRQ_ARM_DMA	S3C6400_IRQ(20)
#define IRQ_ARM_DMAS	S3C6400_IRQ(21)
#define IRQ_KEYPAD	S3C6400_IRQ(22)
#define IRQ_TIMER0	S3C6400_IRQ(23)
#define IRQ_TIMER1	S3C6400_IRQ(24)
#define IRQ_TIMER2	S3C6400_IRQ(25)
#define IRQ_WDT 	S3C6400_IRQ(26)
#define IRQ_TIMER3	S3C6400_IRQ(27)
#define IRQ_TIMER4	S3C6400_IRQ(28)
#define IRQ_LCD_FIFO	S3C6400_IRQ(29)
#define IRQ_LCD_VSYNC	S3C6400_IRQ(30)
#define IRQ_LCD_SYSTEM	S3C6400_IRQ(31)

/******** TZIC1/VIC1 *****************/
#define IRQ_EINT12_19	S3C6400_IRQ(32)
#define IRQ_EINT20_27	S3C6400_IRQ(33)
#define IRQ_PCM0	S3C6400_IRQ(34)
#define IRQ_PCM1	S3C6400_IRQ(35)
#define IRQ_AC97	S3C6400_IRQ(36)
#define IRQ_UART0	S3C6400_IRQ(37)
#define IRQ_UART1	S3C6400_IRQ(38)
#define IRQ_UART2	S3C6400_IRQ(39)
#define IRQ_UART3	S3C6400_IRQ(40)
#define IRQ_DMA0	S3C6400_IRQ(41)
#define IRQ_DMA1	S3C6400_IRQ(42)
#define IRQ_ONENAND0	S3C6400_IRQ(43)
#define IRQ_ONENAND1	S3C6400_IRQ(44)
#define IRQ_NFC 	S3C6400_IRQ(45)
#define IRQ_CFCON 	S3C6400_IRQ(46)
#define IRQ_UHOST	S3C6400_IRQ(47)
#define IRQ_SPI0	S3C6400_IRQ(48)
#define IRQ_SPI1	S3C6400_IRQ(49)
#define IRQ_IIC0 	S3C6400_IRQ(50)
#define IRQ_HSItx	S3C6400_IRQ(51)
#define IRQ_HSIrx	S3C6400_IRQ(52)
#define IRQ_RESERVED	S3C6400_IRQ(53)
#define IRQ_MSM 	S3C6400_IRQ(54)
#define IRQ_HOSTIF	S3C6400_IRQ(55)
#define IRQ_HSMMC0	S3C6400_IRQ(56)
#define IRQ_HSMMC1	S3C6400_IRQ(57)
#define IRQ_HSMMC2	IRQ_SPI1	/* shared with SPI1 */
#define IRQ_OTG 	S3C6400_IRQ(58)
#define IRQ_IRDA	S3C6400_IRQ(59)
#define IRQ_RTC_ALARM	S3C6400_IRQ(60)
#define IRQ_SEC 	S3C6400_IRQ(61)
#define IRQ_PENDN	S3C6400_IRQ(62)
#define IRQ_TC		IRQ_PENDN
#define IRQ_ADC 	S3C6400_IRQ(63)

/* EINT 0 ~27 */
#define IRQ_EINT0	S3C6400_IRQ(64)
#define IRQ_EINT1	S3C6400_IRQ(65)
#define IRQ_EINT2	S3C6400_IRQ(66)
#define IRQ_EINT3	S3C6400_IRQ(67)
#define IRQ_EINT4	S3C6400_IRQ(68)
#define IRQ_EINT5	S3C6400_IRQ(69)
#define IRQ_EINT6	S3C6400_IRQ(70)
#define IRQ_EINT7	S3C6400_IRQ(71)
#define IRQ_EINT8	S3C6400_IRQ(72)
#define IRQ_EINT9	S3C6400_IRQ(73)
#define IRQ_EINT10	S3C6400_IRQ(74)
#define IRQ_EINT11	S3C6400_IRQ(75)
#define IRQ_EINT12	S3C6400_IRQ(76)
#define IRQ_EINT13	S3C6400_IRQ(77)
#define IRQ_EINT14	S3C6400_IRQ(78)
#define IRQ_EINT15	S3C6400_IRQ(79)
#define IRQ_EINT16	S3C6400_IRQ(80)
#define IRQ_EINT17	S3C6400_IRQ(81)
#define IRQ_EINT18	S3C6400_IRQ(82)
#define IRQ_EINT19	S3C6400_IRQ(83)
#define IRQ_EINT20	S3C6400_IRQ(84)
#define IRQ_EINT21	S3C6400_IRQ(85)
#define IRQ_EINT22	S3C6400_IRQ(86)
#define IRQ_EINT23	S3C6400_IRQ(87)
#define IRQ_EINT24	S3C6400_IRQ(88)
#define IRQ_EINT25	S3C6400_IRQ(89)
#define IRQ_EINT26	S3C6400_IRQ(90)
#define IRQ_EINT27	S3C6400_IRQ(91)


#define NR_IRQS (IRQ_EINT27+1)
#endif


#endif /* __ASM_ARCH_IRQ_H */

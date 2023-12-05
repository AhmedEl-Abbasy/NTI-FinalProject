/******************************************************************************
 * Module:
 *
 * File Name: .h
 *
 * Description: Header File for the  Driver
 *
 * Author:
 *
 *******************************************************************************/

#ifndef TIM6_REG_H_
#define TIM6_REG_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
#define CR1_REG_OFFSET			  (0x00u)
#define CEN_BIT_0				  (0u)
#define ARPE_BIT_7				  (7u)
#define OPM_BIT_3				  (3u)

#define CR2_REG_OFFSET			  (0x04u)
#define TI1S_BIT_7				  (7u)

#define DIER_REG_OFFSET           (0x0Cu)
#define CC1IE_BIT_1				  (1u)
#define CC2IE_BIT_2				  (2u)

#define SR_REG_OFFSET			  (0x10u)
#define UIF_BIT_0				  (0u)

#define CCMR1_REG_OFFSET          (0x18u)
#define CC1S_BIT_0_1			  (0u)
#define IC1PSC_BIT_2_3			  (2u)
#define IC1F_BIT_4_5_6_7		  (4u)
#define CC2S_BIT_8_9			  (8u)
#define IC2PSC_BIT_10_11		  (10u)
#define IC2F_BIT_12_13_14_15	  (12u)

#define CCER_REG_OFFSET           (0x20u)
#define CC1E_BIT_0				  (0u)
#define CC1P_BIT_1				  (1u)
#define CC1NP_BIT_3				  (3u)
#define CC2E_BIT_4				  (4u)
#define CC2P_BIT_5				  (5u)
#define CC2NP_BIT_7				  (7u)

#define PSC_REG_OFFSET			  (0x28u)

#define ARR_REG_OFFSET			  (0x2Cu)

#define CCR1_REG_OFFSET           (0x34u)

#define CCR2_REG_OFFSET           (0x38u)


/*************          TIMER 6                *************/

#define TIMER6_BASE_ADDR                (0x40001000ul)      /*Timer 15 Base Address*/

#define TIM6_CR1_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + CR1_REG_OFFSET)) 		/*Timer 6 Control Register 1*/
#define TIM6_CR2_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + CR2_REG_OFFSET)) 		/*Timer 6 Control Register 2*/
#define TIM6_DIER_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + DIER_REG_OFFSET)) 	/*Timer 6 DMA/Interrupt Enable Register*/
#define TIM6_SR_REG						(*(volatile u16*) (TIMER6_BASE_ADDR + SR_REG_OFFSET)) 		/*Timer 6 Status Register*/
#define TIM6_CCMR1_REG					(*(volatile u32*) (TIMER6_BASE_ADDR + CCMR1_REG_OFFSET))	/*Timer 6 Capture/Compare Mode Register 1*/
#define TIM6_CCER_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + CCER_REG_OFFSET))		/*Timer 6 Capture/Compare Enable Register*/
#define TIM6_PSC_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + PSC_REG_OFFSET))		/*Timer 6 Pre-scaler Register*/
#define TIM6_ARR_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + ARR_REG_OFFSET))		/*Timer 6 Auto-reload Register*/
#define TIM6_CCR1_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + CCR1_REG_OFFSET))		/*Timer 6 Capture/Compare Register 1*/
#define TIM6_CCR2_REG					(*(volatile u16*) (TIMER6_BASE_ADDR + CCR2_REG_OFFSET))		/*Timer 6 Capture/Compare Register 2*/

/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Function Prototypes                             *
 *******************************************************************************/


#endif

/*******************************************************************************
 *                      End of File: .h                                        *
 *******************************************************************************/

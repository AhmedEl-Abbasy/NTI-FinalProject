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

#ifndef ICU_REG_H_
#define ICU_REG_H_

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
#define CC1S_BIT_0				  (0u)
#define CC1S_BIT_1				  (1u)
#define IC1PSC_BIT_2_3			  (2u)
#define IC1F_BIT_4_5_6_7		  (4u)

#define CC1E_BIT_0				  (0u)
#define CC1P_BIT_1				  (1u)
#define CC1NE_BIT_2				  (2u)
#define CC1NP_BIT_3				  (3u)

#define CC1IE_BIT_1				  (1u)
#define CC2IE_BIT_2				  (2u)
#define CC3IE_BIT_3				  (3u)
#define CC4IE_BIT_4				  (4u)
#define TIE_BIT_6                 (6u)











/*************          TIMER 20                *************/

#define TIMER8_BASE_ADDR                (0x40013400ul )      // Base Address for TIMER8 in memory map



#define CR1_REG_OFFSET  		  (0x00u)	//16b
#define CR2_REG_OFFSET  		  (0x04u)	//16b
#define DIER_REG_OFFSET           (0x0Cu)   //16b
#define SR_REG_OFFSET  			  (0x10u)   //32b
#define CCMR1_REG_OFFSET          (0x18u)   //32b
#define CCMR2_REG_OFFSET          (0x1cu)   //32b
#define CCER_REG_OFFSET           (0x20u)   //32b
#define PSC_REG_OFFSET            (0x28u)   //16b
#define CCR1_REG_OFFSET           (0x34u)	//16b
#define CCR2_REG_OFFSET           (0x38u)	//16b
#define CCR3_REG_OFFSET           (0x3cu)	//16b
#define CCR4_REG_OFFSET           (0x40u)	//16b
#define EGR_REG_OFFSET			  (0x14)

/**********************************/


#define TIM8_CR1_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CR1_REG_OFFSET   ))    //control register 1

#define CEN_BIT_0		(0u)			//Bit 0 CEN: Counter enable

/**********************************/
#define TIM8_CR2_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CR2_REG_OFFSET   ))	  //control register 2
/**********************************/

#define TIM8_DIER_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + DIER_REG_OFFSET  ))	  //DMA/interrupt enable register

#define  CC4IE_BIT_4	(4u)	//Bit 4 CC4IE: Capture/Compare 4 interrupt enable
#define  CC3IE_BIT_3	(3u)	//Bit 3 CC3IE: Capture/Compare 3 interrupt enable
#define  CC2IE_BIT_2	(2u)	//Bit 2 CC2IE: Capture/Compare 2 interrupt enable
#define  CC1IE_BIT_1	(1u)	//Bit 1 CC1IE: Capture/Compare 1 interrupt enable
/**********************************/

#define TIM8_SR_REG					( *( volatile u32* ) ( TIMER8_BASE_ADDR + SR_REG_OFFSET    ))	  //status register

#define  CC4IF_BIT_4	(4u)	//Bit 4 CC4IE: Capture/Compare 4 interrupt flag
#define  CC3IF_BIT_3	(3u)	//Bit 3 CC3IE: Capture/Compare 3 interrupt flag
#define  CC2IF_BIT_2	(2u)	//Bit 2 CC2IE: Capture/Compare 2 interrupt flag
#define  CC1IF_BIT_1	(1u)	//Bit 1 CC1IE: Capture/Compare 1 interrupt flag

/**********************************/

#define TIM8_CCMR1_REG					( *( volatile u32* ) ( TIMER8_BASE_ADDR + CCMR1_REG_OFFSET ))    //capture/compare mode register 1
#define CC2S_BIT_8_9      (8u)		//Bits 9:8 CC2S: Capture/Compare 2 selection
#define CC1S_BIT_0_1      (0u)		//Bits 1:0 CC1S: Capture/Compare 1 selection

/**********************************/

#define TIM8_CCMR2_REG					( *( volatile u32* ) ( TIMER8_BASE_ADDR + CCMR2_REG_OFFSET ))    //capture/compare mode register 2
#define CC4S_BIT_8_9      (8u)		//Bits 9:8 CC4S: Capture/Compare 4 selection
#define CC3S_BIT_0_1      (0u)		//Bits 1:0 CC3S: Capture/Compare 3 selection


/**********************************/

#define TIM8_CCER_REG					( *( volatile u32* ) ( TIMER8_BASE_ADDR + CCER_REG_OFFSET  ))    //capture/compare enable register

#define CC1E_BIT_0   (0u)     //Bit 0 CC1E: Capture/Compare 1 output enable
#define CC1P_BIT_1	 (1u)	  //Bit 1 CC1P: Capture/Compare 1 output polarity
#define CC1NP_BIT_3  (3u)	  //Bit 3 CC1NP: Capture/Compare 1 complementary output polarity

#define CC2E_BIT_4   (4u)     //Bit 4 CC1E: Capture/Compare 2 output enable
#define CC2P_BIT_5	 (5u)	  //Bit 5 CC1P: Capture/Compare 2 output polarity
#define CC2NP_BIT_7  (7u)	  //Bit 7 CC1NP: Capture/Compare 2 complementary output polarity

#define CC3E_BIT_8   (8u)     //Bit 8 CC1E: Capture/Compare 3 output enable
#define CC3P_BIT_9	 (9u)	  //Bit 9 CC1P: Capture/Compare 3 output polarity
#define CC3NP_BIT_11  (11u)	  //Bit 11 CC1NP: Capture/Compare 3 complementary output polarity

#define CC4E_BIT_12   (12u)     //Bit 12 CC1E: Capture/Compare 4 output enable
#define CC4P_BIT_13	 (13u)	  //Bit 13 CC1P: Capture/Compare 4 output polarity
#define CC4NP_BIT_15  (315u)	  //Bit 15 CC1NP: Capture/Compare 4 complementary output polarity

/**********************************/

#define TIM8_PSC_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + PSC_REG_OFFSET   ))    //prescaler

/**********************************/

#define TIM8_CCR1_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CCR1_REG_OFFSET  ))    //capture/compare register 1

/**********************************/

#define TIM8_CCR2_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CCR2_REG_OFFSET  ))    //capture/compare register 2

/**********************************/

#define TIM8_CCR3_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CCR3_REG_OFFSET  ))    //capture/compare register 3

/**********************************/

#define TIM8_CCR4_REG					( *( volatile u16* ) ( TIMER8_BASE_ADDR + CCR4_REG_OFFSET  ))    //capture/compare register 4

/**********************************/



#define ARR_REG_OFFSET  (0x2Cu)
#define  TIM8_ARR_REG   ( *( volatile u16* ) ( TIMER8_BASE_ADDR + ARR_REG_OFFSET  ))

#define  TIM8_EGR_REG 	( *( volatile u16* ) ( TIMER8_BASE_ADDR + EGR_REG_OFFSET  ))


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

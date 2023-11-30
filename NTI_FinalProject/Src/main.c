/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module:
 *
 * File Name: main.c
 *
 * Description:
 *
 * Created on: Nov 15, 2023
 *
 * Author: 
 *******************************************************************************/

 /*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include <SCB.h>
#include <NVIC.h>
#include <EXTI.h>
#include <rcc.h>
#include <motor.h>
#include <BUTTON.h>
#include <adc.h>
#include <dio.h>
//#include <PWM_INTERFACE.h>

/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/
void Exti_Fun(void);
u16 Glopal_Var = 0;
/*******************************************************************************
 *                      Main Function                          *
 *******************************************************************************/

int main(void)
{
//	u8 k=0;
	rcc_setSystemClk(HSI);
	rcc_enablePeriClk(AHB,IOPB_EN);

	rcc_enablePeriClk(AHB,IOPC_EN);

	rcc_enablePeriClk(AHB,IOPA_EN);
//	rcc_enablePeriClk(AHB,ADC12_EN);
//
//	rcc_enablePeriClk(APB2,TIM1_EN);
//	rcc_enablePeriClk(APB1,TIM2_EN);
//	rcc_enablePeriClk(APB1,TIM3_EN);
//	rcc_enablePeriClk(APB1,TIM4_EN);

	rcc_enablePeriClk(APB2,SYSCFG_EN);


	DcMotor_Init();
	BUTTON_init();

	Config_Motor MyCong;
	MyCong.state=on;
//	MyCong.direction=clockwise;
	MyCong.direction=anticlockwise;

//	BUTTON_Status Button1= RELEASED;

//	DIO_setupPinMode(PORTA_ID, PIN0_ID, PIN_ANALOG);
//	ADC1_Init(Channel_1 );
//
//	ADC_Enable(ADC_1);
	EXTI_Type Button_EXT;
	Button_EXT.Trig_Stat =RISING_TRIGGER;
	Button_EXT.EXTIxSelect = EXTI_13;
	Button_EXT.EXTI_CallBackFunc = (&Exti_Fun);
	SYSCFG_EXTICR4 = 0x0020;

//	PWM_voidSetPinDirection(1,1);
//	PWM_voidWrite(1,1,100);
	DcMotor_Rotate(&MyCong);
	/* Loop forever */
//	SCB_SetPriorityGroup(GROUPS_4_SUBS_4);
	NVIC_EnableIRQ(IRQn_EXTI15_10);
//	NVIC_SetPriority(IRQn_EXTI15_10 , 0);
	EXTI_LineEnable(&Button_EXT);


//	DIO_setupPinMode(PORTC_ID, PIN13_ID,PIN_INPUT);

	DIO_setupPinMode(PORTA_ID, PIN5_ID,PIN_OUTPUT);
	DIO_writePin(PORTA_ID, PIN5_ID,STD_HIGH);

//	NVIC_SetPendingIRQ(IRQn_EXTI15_10);
//
//	NVIC_SetPendingIRQ(IRQn_EXTI15_10);
//
//	NVIC_SetPendingIRQ(IRQn_EXTI15_10);

	Glopal_Var =0;
	for(;;)
	{
//		ADC_Start(ADC_1);
//		ADC_Read(ADC_1 ,&Glopal_Var);
//
//		BUTTON_getStatus(&Button1);
//		if(Button1 == PRESSED)
//		{
//			Glopal_Var++;
//
//
//		}


	}
}

void Exti_Fun(void)
{

}
void EXTI15_10_IRQHandler()
{
//	if((Glopal_Var % 2) == 0)
//	{
//		DIO_writePin(PORTA_ID, PIN5_ID,STD_LOW);
//	}
//	else
//	{
//		DIO_writePin(PORTA_ID, PIN5_ID,STD_HIGH);
//	}
	DIO_writePin(PORTA_ID, PIN5_ID,STD_LOW);
//	NVIC_SetPendingIRQ(IRQn_EXTI15_10);
//	DIO_togglePin(PORTA_ID, PIN5_ID);
//	for(u16 i=0;i<10000;i++){
//
//	}
//	NVIC_ClearPendingIRQ(IRQn_EXTI15_10);
}

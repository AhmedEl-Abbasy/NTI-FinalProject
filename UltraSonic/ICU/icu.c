

#include "icu.h"




static void (* Channel_1_CLB_Ptr)(void) = NULLPTR;
static void (* Channel_2_CLB_Ptr)(void) = NULLPTR;
static void (* Channel_3_CLB_Ptr)(void) = NULLPTR;
static void (* Channel_4_CLB_Ptr)(void) = NULLPTR;




void TIM8_ICU_Enable(ICU_Channel channel)
{


	TIM8_PSC_REG = 7;

	switch(channel)
	{
	  case channel_1:
		  TIM8_CCMR1_REG |= WriteValue(1,CC1S_BIT_0_1);
		  SET_BIT(TIM8_CCER_REG , CC1E_BIT_0 );
	  break;
	  case channel_2:
		  TIM8_CCMR1_REG |= WriteValue(1,CC2S_BIT_8_9);
		  SET_BIT(TIM8_CCER_REG , CC2E_BIT_4 );
	  break;
	  case channel_3:
		  TIM8_CCMR1_REG |= WriteValue(1,CC3S_BIT_0_1);  //01: CC3 channel is configured as input, IC3 is mapped on TI3
		  SET_BIT(TIM8_CCER_REG , CC3E_BIT_8 );
	  break;
	  case channel_4:
		  TIM8_CCMR1_REG |= WriteValue(1,CC4S_BIT_8_9);
		  SET_BIT(TIM8_CCER_REG , CC4E_BIT_12 );
	  break;
	}

	//TIM8_DIER_REG = 0;


	//TIM8_ARR_REG = 0xFFFF;
	SET_BIT(TIM8_CR1_REG,CEN_BIT_0);
}



void TIM8_ICU_SelectEdge(ICU_Channel channel,ICU_Edge edge)
{
	switch(channel)
	{
	  case channel_1:
		  	   if( edge == RISING )
		  	  	{
		  		      CLEAR_BIT(TIM8_CCER_REG,CC1P_BIT_1);
		  		      CLEAR_BIT(TIM8_CCER_REG,CC1NP_BIT_3);
		  	  	 }
		  	  	else if (edge == FALLING )
		  	  	  {
		  	  	  	  SET_BIT(TIM8_CCER_REG,CC1P_BIT_1);
		  	  	  	  CLEAR_BIT(TIM8_CCER_REG,CC1NP_BIT_3);
		  	  	  }
		  	  	else
		  	  	{
		  	  		 SET_BIT(TIM8_CCER_REG,CC1P_BIT_1);
		  	  		 SET_BIT(TIM8_CCER_REG,CC1NP_BIT_3);
		  	  	}
	  break;
	  case channel_2:
	  	  	  if( edge == RISING )
	  	  	  {
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC2P_BIT_5);
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC2NP_BIT_7);
	  	  	  }
	  	     else if (edge == FALLING )
	  	  	  {
	  	  		  SET_BIT(TIM8_CCER_REG,CC2P_BIT_5);
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC2NP_BIT_7);
	  	  	  }
	  	     else
	  	     {
	  	  		  SET_BIT(TIM8_CCER_REG,CC2P_BIT_5);
	  	  		  SET_BIT(TIM8_CCER_REG,CC2NP_BIT_7);
	  	     }
	  break;
	  case channel_3:
	  	  	  if( edge == RISING )
	  	  	  {
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC3P_BIT_9);
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC3NP_BIT_11);
	  	  	  }
		  	  else if (edge == FALLING )
	  	  	  {
	  	  		  SET_BIT(TIM8_CCER_REG,CC3P_BIT_9);
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC3NP_BIT_11);
	  	  	  }
		  	  else
		  	  {
		  		 SET_BIT(TIM8_CCER_REG,CC3P_BIT_9);
		  		SET_BIT(TIM8_CCER_REG,CC3NP_BIT_11);
		  	  }
	  break;
	  case channel_4:
	  	  	  if( edge == RISING )
	  	  	  {
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC4P_BIT_13);
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC4NP_BIT_15);
	  	  	  }
		  	  else if (edge == FALLING )
	  	  	  {
	  	  		  SET_BIT(TIM8_CCER_REG,CC4P_BIT_13);
	  	  		  CLEAR_BIT(TIM8_CCER_REG,CC4NP_BIT_15);
	  	  	  }
		  	  else
		  	  {
	  	  		  SET_BIT(TIM8_CCER_REG,CC4P_BIT_13);
	  	  		  SET_BIT(TIM8_CCER_REG,CC4NP_BIT_15);
		  	  }
	  break;
	}



}



STD_ReturnState TIM8_ICU_INT_CheckStatus(ICU_Channel channel)
{
	STD_ReturnState state;

	switch(channel)
	{
	   case channel_1:
		   state = CHECK_BIT( TIM8_SR_REG , CC1IF_BIT_1 );
		   if( state == 0 )
		   	{
		   	   state = E_NOT_OK;
		   	}
		   	else
		   	{
			   state = E_OK;
			}
	   break;
	   case channel_2:
	   	   state = CHECK_BIT( TIM8_SR_REG , CC2IF_BIT_2 );
	   	   if( state == 0 )
	   	   {
	   		   state = E_NOT_OK;
	   	   }
	   	   else
	   	   {
			  state = E_OK;
	   	   }

	   break;
	   case channel_3:
	   	   state = CHECK_BIT( TIM8_SR_REG , CC3IF_BIT_3 );
	   	   if( state == 0 )
	   	   {
	   		   state = E_NOT_OK;
	   	   }
	   	   else
	   	   {
			  state = E_OK;
	   	   }

	   break;
	   case channel_4:
	   	   state = CHECK_BIT( TIM8_SR_REG , CC4IF_BIT_4 );
	   	   if( state == 0 )
	   	   {
	   		   state = E_NOT_OK;
	   	   }
	   	   else
	   	   {
			  state = E_OK;
	   	   }

	   break;


	}

	return state;

}


void TIM8_ICU_Read(ICU_Channel channel,u16 * read_ptr )
{

	switch(channel)
	{
	  case channel_1:
		  * read_ptr = TIM8_CCR1_REG;
	  break;
	  case channel_2:
		  * read_ptr = TIM8_CCR2_REG;
	  break;
	  case channel_3:
		  * read_ptr = TIM8_CCR3_REG;
	  break;
	  case channel_4:
		  * read_ptr = TIM8_CCR4_REG;
	  break;
	}

}




void TIM8_ICU_INT_Enable(ICU_Channel channel,void(*ptr)(void))
{
	switch(channel)
	{
	  case channel_1:
	    	SET_BIT(TIM8_DIER_REG,CC1IE_BIT_1);
	    	if(ptr != NULLPTR)
	    	{
	    		Channel_1_CLB_Ptr = ptr;
	    	}
	  break;
	  case channel_2:
		   SET_BIT(TIM8_DIER_REG,CC2IE_BIT_2);
	    	if(ptr != NULLPTR)
	    	{
	    		Channel_2_CLB_Ptr = ptr;
	    	}
	  break;
	  case channel_3:
		   SET_BIT(TIM8_DIER_REG,CC3IE_BIT_3);
	    	if( ptr != NULLPTR)
	    	{
	    		Channel_3_CLB_Ptr = ptr;
	    	}
	  break;
	  case channel_4:
		   SET_BIT(TIM8_DIER_REG,CC4IE_BIT_4);
	    	if( ptr != NULLPTR)
	    	{
	    		Channel_4_CLB_Ptr = ptr;
	    	}
	  break;
	}



}

void TIM8_ICU_INT_Disable(ICU_Channel channel)
{

	switch(channel)
	{
	  case channel_1:
	  	CLEAR_BIT(TIM8_DIER_REG,CC1IE_BIT_1);
	  break;
	  case channel_2:
	  	CLEAR_BIT(TIM8_DIER_REG,CC2IE_BIT_2);
	  break;
	  case channel_3:
	  	CLEAR_BIT(TIM8_DIER_REG,CC3IE_BIT_3);
	  break;
	  case channel_4:
	  	CLEAR_BIT(TIM8_DIER_REG,CC4IE_BIT_4);
	  break;
	}

}

//TIM8_CC_IRQHandler
void TIM8_CC_IRQHandler(void)
{

	if ( TIM8_ICU_INT_CheckStatus(channel_1 ) == E_OK  )
	{

		CLEAR_BIT( TIM8_SR_REG , CC1IF_BIT_1 );
		if( Channel_1_CLB_Ptr != NULLPTR )
		{
			Channel_1_CLB_Ptr();
		}


	}

	if ( TIM8_ICU_INT_CheckStatus(channel_2 ) == E_OK  )
	{
		CLEAR_BIT( TIM8_SR_REG , CC2IF_BIT_2 );
		if( Channel_2_CLB_Ptr != NULLPTR )
		{
			Channel_2_CLB_Ptr();
		}

	}

	if ( TIM8_ICU_INT_CheckStatus(channel_3 ) == E_OK  )
	{
		CLEAR_BIT( TIM8_SR_REG ,CC3IF_BIT_3 );

		if( Channel_3_CLB_Ptr != NULLPTR )
		{
			Channel_3_CLB_Ptr();
		}

	}

	if ( TIM8_ICU_INT_CheckStatus(channel_4 ) == E_OK  )
	{
		CLEAR_BIT( TIM8_SR_REG , CC4IF_BIT_4 );
		if( Channel_4_CLB_Ptr != NULLPTR )
		{
			Channel_4_CLB_Ptr();
		}

	}
}


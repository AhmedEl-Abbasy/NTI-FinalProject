
#ifndef  _ICU_H_
#define  _ICU_H_

#include "bit_math.h"
#include "std_types.h"
#include "icu_reg.h"
#include "icu_types.h"


void TIM8_ICU_Enable(ICU_Channel channel);				          // done
void TIM8_ICU_Read(ICU_Channel channel,u16 * read_ptr );         // done
void TIM8_ICU_SelectEdge(ICU_Channel channel,ICU_Edge edge);     // done
void TIM8_ICU_INT_Enable(ICU_Channel channel,void(*ptr)(void));  // done
void TIM8_ICU_INT_Disable(ICU_Channel channel);                  // done
STD_ReturnState TIM8_ICU_INT_CheckStatus(ICU_Channel channel);   // done
















#endif   //_ICU_H_

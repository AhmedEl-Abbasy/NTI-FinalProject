#include "ultrasonic.h"




typedef struct
{

	ICU_Channel channel;
	DIO_PortID Echo_Port;
	DIO_PortID Trigger_Port;
	DIO_PinID  Echo_Pin;
	DIO_PinID  Trigger_Pin;
	DIO_AltFuncID AF;

}UltraSonic_Channel;



#define BR_Channel







UltraSonic_Channel Channel_arr[6];

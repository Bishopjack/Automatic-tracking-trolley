#include"speedtest.h"
#include"stm32f10x_it.h"
#include"motor.h"

inline void Athletic::movement::TIM1_IRQ()
{
	Athletic::movement::Speed::TIM1_UP();
	static char count=0;
	if(count!=5)
		++count;
	else
	{
		Athletic::movement::motor::TIM1_PID();
		count=0;
	}
}

extern "C" void TIM1_UP_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM1,TIM_IT_Update)!=RESET)
	{
		TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
		Athletic::movement::TIM1_IRQ();
	}
}
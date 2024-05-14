#include"NVIC_Conf.h"
#include"stm32f10x_it.h"


NVIC_Conf::NVIC_INIT::NVIC_INIT()
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_Conf::NVIC_INIT::Rad_INIT();
	NVIC_Conf::NVIC_INIT::Speed_INIT();
	NVIC_Conf::NVIC_INIT::TIM1_UP_INIT();
}
void NVIC_Conf::NVIC_INIT::Rad_INIT()
{
	NVIC_InitTypeDef NVIC_InitStr;
	
	NVIC_InitStr.NVIC_IRQChannelCmd=ENABLE;
	
	NVIC_InitStr.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStr.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStr);
	
	NVIC_InitStr.NVIC_IRQChannel=EXTI1_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStr.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStr);
	
	NVIC_InitStr.NVIC_IRQChannel=EXTI2_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStr.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStr);
	
	NVIC_InitStr.NVIC_IRQChannel=EXTI3_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStr.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStr);
}

void NVIC_Conf::NVIC_INIT::Speed_INIT()
{
	NVIC_InitTypeDef NVIC_InitStr;
	
	NVIC_InitStr.NVIC_IRQChannelCmd=ENABLE;
	
	NVIC_InitStr.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStr.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStr);
	
	NVIC_InitStr.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStr.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStr);
	
	NVIC_InitStr.NVIC_IRQChannel=EXTI4_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStr.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStr);

}



void NVIC_Conf::NVIC_INIT::TIM1_UP_INIT()
{
	NVIC_InitTypeDef NVIC_InitStr;
	
	NVIC_InitStr.NVIC_IRQChannelCmd=ENABLE;
	
	NVIC_InitStr.NVIC_IRQChannel=TIM1_UP_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStr.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStr);
}
#include"NVIC_Conf.h"
#include"stm32f10x_it.h"

#define Init_NVIC(Channel,ChannelPreemptionPriority,ChannelSubPriority)\


void NVIC_Init()
{
	NVIC_InitTypeDef NVIC_InitStr;
	
	NVIC_InitStr.NVIC_IRQChannelCmd=ENABLE;
	
	NVIC_InitStr.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStr.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStr);
	
	
}
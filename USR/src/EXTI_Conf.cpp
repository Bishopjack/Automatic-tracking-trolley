#include"EXTI_Conf.h"
#include"stm32f10x_it.h"

void Athletic::movement::GPIO_EXIT_conf(uint32_t rcc_peripth,GPIO_TypeDef* gpio,uint16_t Pin,uint32_t exti_line)
{
	RCC_APB2PeriphClockCmd(rcc_peripth,ENABLE);
	GPIO_InitTypeDef GPIO_Init_Str;
	
	GPIO_Init_Str.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init_Str.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init_Str.GPIO_Pin=Pin;
	
	GPIO_Init(gpio,&GPIO_Init_Str);
	
	EXTI_InitTypeDef EXTI_InitStr;
	
	EXTI_InitStr.EXTI_Line=exti_line;
	EXTI_InitStr.EXTI_LineCmd=ENABLE;
	EXTI_InitStr.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStr.EXTI_Trigger=EXTI_Trigger_Rising;
	
	EXTI_Init(&EXTI_InitStr);
}
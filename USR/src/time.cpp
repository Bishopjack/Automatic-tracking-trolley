#include"time.h"
#include"stm32f10x_flash.h"
#include"stm32f10x_rcc.h"


/*
* @brief set clock
*	         PLLCLK=72MHz;
*	         HCLK=36MHz;
*	         PCLK1=36MHz;
*	         PCLK2=36MHz;
*
* @param none
* @return nuno
*/
void time_conf::CLK_Config()
{
	/*resets the RCC configuration to its default state. */
	RCC_DeInit();
	/*Enable HSE */
	RCC_HSEConfig(RCC_HSE_ON);
	/*wait start up HSE*/
	while(!RCC_WaitForHSEStartUp());
	/*Waite till HSE is ready*/
	while(RCC_GetFlagStatus(RCC_FLAG_HSERDY)==RESET);
	
	/*Enable the Flash prefetch buffer to improve memory access performance*/
	FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
	/*Set the Flash latency to 0 wait states for optimal access speed*/
	FLASH_SetLatency(FLASH_Latency_2);
	
	//HCLK=SYSCLK/2
	RCC_HCLKConfig(RCC_SYSCLK_Div2);
	//PCLK1=HCLK/4
	RCC_PCLK1Config(RCC_HCLK_Div1);
	//PCLK2=HCLK/2
	RCC_PCLK2Config(RCC_HCLK_Div1);
	///PLLCLK=9*HSE(8MHz) PLLCLK=72MHz
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);
	//Enable PLL
	RCC_PLLCmd(ENABLE);
	//Wait till PLL is ready
	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);
	//Select PLL as system clock source
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	//Wait till PLL is used as system clock source
	while(RCC_GetSYSCLKSource()!=0x08);
	
}

void time_conf::TIM::TIM_INIT::InitTIM2()
{
	#ifndef INITTIM2
	#define INITTIM2
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStr;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TIM_TimeBaseStr.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseStr.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStr.TIM_Period=10000-1;
	TIM_TimeBaseStr.TIM_Prescaler=3600-1;
	TIM_TimeBaseStr.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStr);
	#endif
}

void time_conf::TIM::TIM_INIT::InitTIM4()
{
	//TIM time init
	//0.1ms TIM
	#ifndef INIT_TIM4
	#define INIT_TIM4
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStr;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	TIM_TimeBaseStr.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseStr.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStr.TIM_Period=10000-1;
	TIM_TimeBaseStr.TIM_Prescaler=3600-1;
	TIM_TimeBaseStr.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStr);

	#endif
}

void time_conf::TIM::TIM_INIT::InitTIM1()
{
	//TIM time init
	//0.1ms TIM
	#ifndef INIT_TIM1
	#define INIT_TIM1
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStr;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	TIM_TimeBaseStr.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseStr.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStr.TIM_Period=10000-1;
	TIM_TimeBaseStr.TIM_Prescaler=3600-1;
	TIM_TimeBaseStr.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStr);

	#endif
}
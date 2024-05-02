#include"time.h"
#include"stm32f10x_flash.h"
#include"stm32f10x_rcc.h"


/*
* @brief set clock
*	         PLLCLK=72MHz;
*	         HCLK=36MHz;
*	         PCLK1=9MHz;
*	         PCLK2=18MHz;
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
	RCC_PCLK1Config(RCC_HCLK_Div4);
	//PCLK2=HCLK/2
	RCC_PCLK2Config(RCC_HCLK_Div2);
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
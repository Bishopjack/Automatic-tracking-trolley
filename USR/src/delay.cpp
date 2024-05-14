#include"delay.h"
#include"stm32f10x.h"
#include"time.h"

time::uint8_t time::delay::fac_us=0;
time::uint16_t time::delay::fac_ms=0;

time::delay::delay()
{
	time::delay::delay::InitDelay();
}

void time::delay::InitDelay()
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us = SystemCoreClock / 8000000; 
	fac_ms = ( uint16_t ) fac_us * 1000;    
}




void time::delay::delayus(unsigned int us)
{
	time::uint32_t temp;
	SysTick->LOAD=us*fac_us;
	SysTick->VAL=0x00;
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;
	
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&!(temp&(1<<16)));
	
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL=0x00;
}


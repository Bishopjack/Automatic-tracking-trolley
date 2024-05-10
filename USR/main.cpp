#include"stm32f10x_it.h"
#include"travel.h"
#include"time.h"
#include"NVIC_Conf.h"
#include"myus.h"
#include"pwm.h"
#include"delay.h"
void Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_0;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&gpio);
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
}
void blink()
{
	static int i=0;
	if(i%2!=0)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_0);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	}
	++i;
}


int main(int argc,char** argv)
{
	time_conf::CLK_Config();
	NVIC_Init();
	Athletic::movement::travel test;
	My_US_Init();
	My_TIM3_Init(19999,71);
	time::delay::delay::InitDelay();
	while(true)
	{
		time::delay::delays(1);
		test.run(100,0);
		time::delay::delays(1);
		test.run(100,200);
	}
	return 0;
}
#include"motor.h"
#include"stm32f10x_it.h"

void Athletic::motor::InitTIM()
{
}
void Athletic::motor::InitTIM_OC()
{
}

Athletic::motor::motor(PORT gpio_port,uint16_t gpio_pin)
{

}

Athletic::motor::~motor()
{

}

void Athletic::motor::init(PORT gpio_port,uint16_t gpio_pin)
{
	//GPIO init 
	GPIO_InitTypeDef gpio;//define GPIO Init structure definition 
	
	gpio.GPIO_Mode=GPIO_Mode_AF_PP;//set gpio mode is 
	gpio.GPIO_Pin=gpio_pin;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	switch(gpio_port)
	{
		case GPIO_A:
		{
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//use APB2 GPIOA out put
			GPIO_Init(GPIOA,&gpio);//Init GPIO
			break;
		}
		case GPIO_B:
		{
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
			GPIO_Init(GPIOB,&gpio);
			break;
		}
		case GPIO_C:
		{
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
			GPIO_Init(GPIOC,&gpio);
			break;
		}
		case GPIO_D:
		{
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
			GPIO_Init(GPIOD,&gpio);
			break;
		}
		default:
		{
			break;
		}
	}
	
	//TIM time init
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStr;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_OCInitTypeDef TIM_OCInitStr;
}

Athletic::motor& Athletic::motor::operator=(const motor& machinery)
{

}

Athletic::motor::motor(const motor&)
{

}

extern "C" void TIM1_UP_IRQHandler()
{
	
}
#include"Infrared.h"
#include"stm32f10x_it.h"
#include"EXTI_Conf.h"
#include"travel.h"
#include<stddef.h>

#define FIRST_EXTI 	RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_0,EXTI_Line0
#define SECOND_EXTI	RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_1,EXTI_Line1
#define THIRD_EXTI 	RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_2,EXTI_Line2
#define FOURTH_EXTI RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_3,EXTI_Line3
	
#define FIRST 			RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_0,this
#define SECOND			RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_1,this
#define THIRD 			RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_2,this
#define FOURTH 			RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_3,this

Athletic::movement::travel*	Athletic::movement::Infrared::device=NULL;


namespace Athletic
{
	namespace movement
	{
		void GPIO_conf(uint32_t rcc_peripth,GPIO_TypeDef* gpio,uint16_t Pin,void* class_print)
		{
			RCC_APB2PeriphClockCmd(rcc_peripth,ENABLE);
			GPIO_InitTypeDef GPIO_Init_Str;
	
			GPIO_Init_Str.GPIO_Mode=GPIO_Mode_IN_FLOATING;
			GPIO_Init_Str.GPIO_Speed=GPIO_Speed_50MHz;
			GPIO_Init_Str.GPIO_Pin=Pin;
	
			GPIO_Init(static_cast<GPIO_TypeDef*>(gpio),&GPIO_Init_Str);
			
			Athletic::movement::Infrared* trail=static_cast<Athletic::movement::Infrared*>(class_print);
			trail->Port=gpio;
			trail->Pin=Pin;
		}
	}
}
	

void Athletic::movement::Infrared::init(Athletic::movement::Infrared::SITE& site,STATUS& status)
{
	switch(site)
	{
		case first:
		{
			Athletic::movement::GPIO_EXIT_conf(FIRST_EXTI);
			break;
		}
		case second:
		{
			Athletic::movement::GPIO_EXIT_conf(SECOND_EXTI);
			break;
		}
		case third:
		{
			Athletic::movement::GPIO_EXIT_conf(THIRD_EXTI);
			break;
		}
		case fourth:
		{
			Athletic::movement::GPIO_EXIT_conf(FOURTH_EXTI);
			break;
		}
	}
}

Athletic::movement::Infrared::Infrared(SITE site,STATUS status)
{
	switch(status)
	{
		case enable:
		{
			this->init(site,status);
			break;
		}
		case disable:
		{
			this->init(site);
			break;
		}
	}
}
	

void Athletic::movement::Infrared::EXTI0()
{
	if(EXTI_GetFlagStatus(EXTI_Line0)!=RESET)
		EXTI_ClearFlag(EXTI_Line0);
	if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
	{
		if(Athletic::movement::Infrared::Infrared::device!=NULL)
		{
			Athletic::movement::Infrared::Infrared::device->run(100,90);
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}

void Athletic::movement::Infrared::EXTI1()
{
	if(EXTI_GetFlagStatus(EXTI_Line1)!=RESET)
		EXTI_ClearFlag(EXTI_Line1);
	if(EXTI_GetITStatus(EXTI_Line1)!=RESET)
	{
		if(Athletic::movement::Infrared::Infrared::device!=NULL)
		{
			Athletic::movement::Infrared::Infrared::device->run(100,270);
		}
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}

void Athletic::movement::Infrared::EXTI2()
{
	if(EXTI_GetFlagStatus(EXTI_Line2)!=RESET)
		EXTI_ClearFlag(EXTI_Line2);
	if(EXTI_GetITStatus(EXTI_Line2)!=RESET)
	{
		if(Athletic::movement::Infrared::Infrared::device!=NULL)
		{
			Athletic::movement::Infrared::Infrared::device->run(100,90);
		}
		EXTI_ClearITPendingBit(EXTI_Line2);
	}
}

void Athletic::movement::Infrared::EXTI3()
{
	if(EXTI_GetFlagStatus(EXTI_Line3)!=RESET)
		EXTI_ClearFlag(EXTI_Line3);
	if(EXTI_GetITStatus(EXTI_Line3)!=RESET)
	{
		if(Athletic::movement::Infrared::Infrared::device!=NULL)
		{
			Athletic::movement::Infrared::Infrared::device->run(100,270);
		}
		EXTI_ClearITPendingBit(EXTI_Line3);
	}
}

void Athletic::movement::Infrared::init(Athletic::movement::Infrared::SITE& site)
{
	switch(site)
	{
		case first:
		{
			Athletic::movement::GPIO_conf(FIRST);
			break;
		}
		case second:
		{
			Athletic::movement::GPIO_conf(SECOND);
			break;
		}
		case third:
		{
			Athletic::movement::GPIO_conf(THIRD);
			break;
		}
		case fourth:
		{
			Athletic::movement::GPIO_conf(FOURTH);
			break;
		}
	}
}

bool Athletic::movement::Infrared::getData()
{
	return GPIO_ReadInputDataBit(static_cast<GPIO_TypeDef*>(this->Port),this->Pin);
}
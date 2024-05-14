#include"speedtest.h"
#include"stm32f10x_it.h"
#include"time.h"
#include"EXTI_Conf.h"
#include"stdint.h"


#define RIGHT_FRONT RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_4,EXTI_Line4
#define LEFT_FRONT 	RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_5,EXTI_Line5
#define RIGHT_BACK 	RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_8,EXTI_Line8
#define LEFT_BACK 	RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_11,EXTI_Line11

namespace Athletic
{
	namespace movement{
		class Speed_rate
		{
			typedef unsigned int COUNT;
		public:
			static COUNT right_front_count,left_front_count,right_back_count,left_back_count;
		};
		Speed_rate::COUNT Speed_rate::right_front_count=0;
		Speed_rate::COUNT Speed_rate::left_front_count=0;
		Speed_rate::COUNT Speed_rate::right_back_count=0;
		Speed_rate::COUNT Speed_rate::left_back_count=0;

	}
}
Athletic::movement::speed_rate Athletic::movement::Speed::get_rate()
{
	switch(site)
	{
		case right_front:
		{
			return (double)Speed_rate::right_front_count/20;
			break;
		}
		case left_front:
		{
			return (double)Speed_rate::left_front_count/20;
			break;
		}
		case right_back:
		{
			return (double)Speed_rate::right_back_count/20;
			break;
		}
		case left_back:
		{
			return (double)Speed_rate::right_back_count/20;
			break;
		}
	}
	return -1;
}

Athletic::movement::Speed::Speed(SITE site):site(site)
{
	switch(site)
	{
		case right_front:
		{
			GPIO_EXIT_conf(RIGHT_FRONT);
			break;
		}
		case left_front:
		{
			GPIO_EXIT_conf(LEFT_FRONT);
			break;
		}
		case right_back:
		{
			GPIO_EXIT_conf(RIGHT_BACK);
			break;
		}
		case left_back:
		{
			GPIO_EXIT_conf(LEFT_BACK);
			break;
		}
	}
	this->init_TIM();
}

void Athletic::movement::Speed::init_TIM()
{
	time_conf::TIM::TIM_INIT::InitTIM1();
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM1, ENABLE);
	
}

void Athletic::movement::Speed::EXTI4()
{
	if(EXTI_GetFlagStatus(EXTI_Line4)!=RESET)
		EXTI_ClearFlag(EXTI_Line4);
	if(EXTI_GetITStatus(EXTI_Line4)!=RESET)
	{
		++Athletic::movement::Speed_rate::right_front_count;
		EXTI_ClearITPendingBit(EXTI_Line4);
	}
}
void Athletic::movement::Speed::EXTI5()
{
	if(EXTI_GetFlagStatus(EXTI_Line5)!=RESET)
		EXTI_ClearFlag(EXTI_Line5);
	if(EXTI_GetITStatus(EXTI_Line5)!=RESET)
	{
		++Athletic::movement::Speed_rate::left_front_count;
		EXTI_ClearITPendingBit(EXTI_Line5);
	}
}
void Athletic::movement::Speed::EXTI8()
{
	if(EXTI_GetFlagStatus(EXTI_Line8)!=RESET)
		EXTI_ClearFlag(EXTI_Line8);
	if(EXTI_GetITStatus(EXTI_Line8)!=RESET)
	{
		++Athletic::movement::Speed_rate::right_back_count;
		EXTI_ClearITPendingBit(EXTI_Line8);
	}
}
void Athletic::movement::Speed::EXTI11()
{
	if(EXTI_GetFlagStatus(EXTI_Line11)!=RESET)
		EXTI_ClearFlag(EXTI_Line11);
	if(EXTI_GetITStatus(EXTI_Line11)!=RESET)
	{
		++Athletic::movement::Speed_rate::left_back_count;
		EXTI_ClearITPendingBit(EXTI_Line11);
	}
}


void Athletic::movement::Speed::TIM1_UP()
{
	static short int count=0;
	if(count!=1000)
	{
		Athletic::movement::Speed_rate::Speed_rate::right_front_count=0;
		Athletic::movement::Speed_rate::Speed_rate::left_front_count=0;
		Athletic::movement::Speed_rate::Speed_rate::right_back_count=0;
		Athletic::movement::Speed_rate::Speed_rate::left_back_count=0;
		count=0;
	}
}
#include"speedtest.h"
#include"stm32f10x_it.h"

#define RIGHT_FRONT RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_0,EXTI_Line0
#define LEFT_FRONT RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_0,EXTI_Line0
#define RIGHT_BACK RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_0,EXTI_Line0
#define LEFT_BACK RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_0,EXTI_Line0

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

		void GPIO_EXIT_conf(uint32_t rcc_peripth,GPIO_TypeDef* gpio,uint16_t Pin,uint32_t exti_line)
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
	#ifndef TIM_INIT
	#define TIM_INIT
	this->init_TIM();
	#endif
}

void Athletic::movement::Speed::init_TIM()
{
	TIM_TimeBaseInitTypeDef TIM_BaseStructure;
	
	TIM_BaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_BaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_BaseStructure.TIM_Period = 10000 - 1;
	TIM_BaseStructure.TIM_Prescaler = 1800 - 1;
	TIM_BaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM5, &TIM_BaseStructure);
	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM5, ENABLE);

	TIM_TimeBaseInit(TIM5, &TIM_BaseStructure);
	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
	
}

extern "C" void EXTI0_IRQHandler(void)
{
	if(EXTI_GetFlagStatus(EXTI_Line0)==1)
		EXTI_ClearFlag(EXTI_Line0);
	if(EXTI_GetITStatus(EXTI_Line0)==1)
	{
		++Athletic::movement::Speed_rate::right_front_count;
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}
extern "C" void EXTI1_IRQHandler(void)
{
	if(EXTI_GetFlagStatus(EXTI_Line1)==1)
		EXTI_ClearFlag(EXTI_Line1);
	if(EXTI_GetITStatus(EXTI_Line1)==1)
	{
		++Athletic::movement::Speed_rate::left_front_count;
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}
extern "C" void EXTI2_IRQHandler(void)
{
	if(EXTI_GetFlagStatus(EXTI_Line2)==1)
		EXTI_ClearFlag(EXTI_Line2);
	if(EXTI_GetITStatus(EXTI_Line2)==1)
	{
		++Athletic::movement::Speed_rate::right_back_count;
		EXTI_ClearITPendingBit(EXTI_Line2);
	}
}
extern "C" void EXTI3_IRQHandler(void)
{
	if(EXTI_GetFlagStatus(EXTI_Line3)==1)
		EXTI_ClearFlag(EXTI_Line3);
	if(EXTI_GetITStatus(EXTI_Line3)==1)
	{
		++Athletic::movement::Speed_rate::left_back_count;
		EXTI_ClearITPendingBit(EXTI_Line3);
	}
}

extern "C" void TIM5_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)!=RESET)
	{
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
		static unsigned int count=0;
		
		Athletic::movement::Speed_rate::Speed_rate::right_front_count=0;
		Athletic::movement::Speed_rate::Speed_rate::left_front_count=0;
		Athletic::movement::Speed_rate::Speed_rate::right_back_count=0;
		Athletic::movement::Speed_rate::Speed_rate::left_back_count=0;
	}
}
#include"motor.h"
#include"stm32f10x_it.h"

void Athletic::movement::motor::front(unsigned int speed)
{
	switch(this->sign)
	{
		case 1:
		{
			TIM_SetCompare1(TIM2,0);
			TIM_SetCompare1(TIM4,0);
			break;
		}
		case 2:
		{
			TIM_SetCompare2(TIM2,0);
			TIM_SetCompare2(TIM4,0);
			break;
		}
		case 3:
		{
			TIM_SetCompare3(TIM2,0);
			TIM_SetCompare3(TIM4,0);
			break;
		}
		case 4:
		{
			TIM_SetCompare4(TIM2,0);
			TIM_SetCompare4(TIM4,0);
			break;
		}
	}
}
void Athletic::movement::motor::back(unsigned int speed)
{
	switch(this->sign)
	{
		case 1:
		{
			TIM_SetCompare1(TIM2,0);
			TIM_SetCompare1(TIM4,0);
			break;
		}
		case 2:
		{
			TIM_SetCompare2(TIM2,0);
			TIM_SetCompare2(TIM4,0);
			break;
		}
		case 3:
		{
			TIM_SetCompare3(TIM2,0);
			TIM_SetCompare3(TIM4,0);
			break;
		}
		case 4:
		{
			TIM_SetCompare4(TIM2,0);
			TIM_SetCompare4(TIM4,0);
			break;
		}
	}
}

int Athletic::movement::motor::initCount=0;

inline void Init_TIMOC1(void*& TIMx1,TIM_OCInitTypeDef& TIM_OCInitStr)
{
		//Init TIMx
		TIM_OC1Init(static_cast<TIM_TypeDef*>(TIMx1),&TIM_OCInitStr);
	
		//WOE output
		TIM_CtrlPWMOutputs(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
	
		//CH1 Polarity config
		TIM_OC1PolarityConfig(static_cast<TIM_TypeDef*>(TIMx1),TIM_OCPreload_Enable);
	
		//enable TIMx use ARR
		TIM_ARRPreloadConfig(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
	
		//enable use TIMx
		TIM_Cmd(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
}

inline void Init_TIMOC2(void*& TIMx1,TIM_OCInitTypeDef& TIM_OCInitStr)
{
		//Init TIMx
		TIM_OC2Init(static_cast<TIM_TypeDef*>(TIMx1),&TIM_OCInitStr);
	
		//WOE output
		TIM_CtrlPWMOutputs(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
	
		//CH1 Polarity config
		TIM_OC2PolarityConfig(static_cast<TIM_TypeDef*>(TIMx1),TIM_OCPreload_Enable);
	
		//enable TIMx use ARR
		TIM_ARRPreloadConfig(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
	
		//enable use TIMx
		TIM_Cmd(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
}

inline void Init_TIMOC3(void*& TIMx1,TIM_OCInitTypeDef& TIM_OCInitStr)
{
		//Init TIMx
		TIM_OC3Init(static_cast<TIM_TypeDef*>(TIMx1),&TIM_OCInitStr);
	
		//WOE output
		TIM_CtrlPWMOutputs(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
	
		//CH1 Polarity config
		TIM_OC3PolarityConfig(static_cast<TIM_TypeDef*>(TIMx1),TIM_OCPreload_Enable);
	
		//enable TIMx use ARR
		TIM_ARRPreloadConfig(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
	
		//enable use TIMx
		TIM_Cmd(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
}

inline void Init_TIMOC4(void*& TIMx1,TIM_OCInitTypeDef& TIM_OCInitStr)
{
		//Init TIMx
		TIM_OC4Init(static_cast<TIM_TypeDef*>(TIMx1),&TIM_OCInitStr);
	
		//WOE output
		TIM_CtrlPWMOutputs(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
	
		//CH1 Polarity config
		TIM_OC4PolarityConfig(static_cast<TIM_TypeDef*>(TIMx1),TIM_OCPreload_Enable);
	
		//enable TIMx use ARR
		TIM_ARRPreloadConfig(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
	
		//enable use TIMx
		TIM_Cmd(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
}


void Athletic::movement::motor::InitTIM(void* TIMx)
{
	//TIM time init
	//1ms TIM
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStr;
	
	if(TIMx==TIM2)
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	else if(TIMx==TIM4)
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	TIM_TimeBaseStr.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseStr.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStr.TIM_Period=20000-1;
	TIM_TimeBaseStr.TIM_Prescaler=2000-1;
	TIM_TimeBaseInit(static_cast<TIM_TypeDef*>(TIMx),&TIM_TimeBaseStr);

}
void Athletic::movement::motor::InitTIM_OC(void* TIMx1=TIM2,void* TIMx2=TIM4)
{
	TIM_OCInitTypeDef TIM_OCInitStr;
	TIM_OCInitStr.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStr.TIM_OutputState=TIM_OutputState_Enable;

	TIM_OCInitStr.TIM_Pulse=0;
	TIM_OCInitStr.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_Cmd(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
	TIM_CtrlPWMOutputs(static_cast<TIM_TypeDef*>(TIMx1),ENABLE);
	
	switch(initCount)
	{
		case 1:
		{
			Init_TIMOC1(TIMx1,TIM_OCInitStr);
			Init_TIMOC1(TIMx2,TIM_OCInitStr);
		break;
		}
		case 2:
		{
			Init_TIMOC2(TIMx1,TIM_OCInitStr);
			Init_TIMOC2(TIMx2,TIM_OCInitStr);
			break;
		}
		case 3:
		{
			Init_TIMOC3(TIMx1,TIM_OCInitStr);
			Init_TIMOC3(TIMx2,TIM_OCInitStr);
			break;
		}
		case 4:
		{
			Init_TIMOC4(TIMx1,TIM_OCInitStr);
			Init_TIMOC4(TIMx2,TIM_OCInitStr);
			break;
		}
		default:
		{
			break;
		}
	}
}

Athletic::movement::motor::motor(PWM CH):_run(true)
{
	if(this->init(CH))
	{
		++initCount;
		this->sign=initCount;
	}
	else
		this->_run=false;
}


bool Athletic::movement::motor::init(PWM& CH)
{
	//GPIO init 
	GPIO_InitTypeDef gpio;//define GPIO Init structure definition 
	
	gpio.GPIO_Mode=GPIO_Mode_AF_PP;//set gpio mode is 
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	switch(CH)
	{
		case CH1:
		{			
			gpio.GPIO_Pin=GPIO_Pin_6;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
			GPIO_Init(GPIOA,&gpio);
			gpio.GPIO_Pin=GPIO_Pin_6;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
			GPIO_Init(GPIOB,&gpio);
			break;
		}
		case CH2:
		{			
			gpio.GPIO_Pin=GPIO_Pin_7;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
			GPIO_Init(GPIOA,&gpio);
			gpio.GPIO_Pin=GPIO_Pin_7;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
			GPIO_Init(GPIOB,&gpio);
			break;
		}
		case CH3:
		{			
			gpio.GPIO_Pin=GPIO_Pin_0;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
			GPIO_Init(GPIOA,&gpio);
			gpio.GPIO_Pin=GPIO_Pin_8;			
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
			GPIO_Init(GPIOB,&gpio);
			break;
		}
		case CH4:
		{			
			gpio.GPIO_Pin=GPIO_Pin_3;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
			GPIO_Init(GPIOA,&gpio);
			gpio.GPIO_Pin=GPIO_Pin_9;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
			GPIO_Init(GPIOB,&gpio);
			break;
		}
		default:
		{
			return false;
			break;
		}
	}
	
	static bool Init=false;
	#ifndef TIM2_INIT
	#define TIM2_INIT
	this->resetTIM2();
	#else
		Athletic::motor::motor_pwm::InitTIM_OC();
		Init=true;
	#endif
	
	#ifndef TIM4_INIT
	#define TIM4_INIT
	this->resetTIM2();
	#else
		if(!Init)
			Athletic::motor::motor_pwm::InitTIM_OC();
	#endif
	
	return true;
}

Athletic::movement::motor::~motor()
{
	if(this->_run)
		--this->initCount;
}

inline void Athletic::movement::motor::resetTIM2()
{
	Athletic::movement::motor::InitTIM(TIM2);
	Athletic::movement::motor::InitTIM_OC();
}

inline void Athletic::movement::motor::resetTIM4()
{
	Athletic::movement::motor::InitTIM(TIM4);
	Athletic::movement::motor::InitTIM_OC();
}


extern "C" void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET)
	{
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}

extern "C" void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)!=RESET)
	{
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
	}
}
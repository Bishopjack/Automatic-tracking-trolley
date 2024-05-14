#include"motor.h"
#include"stm32f10x_it.h"
#include"time.h"
#include"speedtest.h"
#include"stddef.h"
#include"vector.h"

vector::motor_vector motor_List;

static double Err=0,LastErr=0,LastLastErr=0;
static double pwm_CCR=0,Add_CCR=0;

void Athletic::movement::motor::TIM1_PID()
{
	motor_List.run();
}

void Athletic::movement::motor::set_rate(unsigned int speed)
{
	this->speed=speed;
}

void Athletic::movement::motor::go_rate(unsigned int speed)
{
	if(speed>1000)
		speed=1000;
	switch(this->dir)
	{
		case front_go:
		{
				switch(this->sign)
				{
					case 1:
					{
						TIM_SetCompare1(TIM2,0);
						TIM_SetCompare1(TIM4,speed);
						break;
					}
					case 2:
					{
						TIM_SetCompare2(TIM2,0);
						TIM_SetCompare2(TIM4,speed);
						break;
					}
					case 3:
					{
						TIM_SetCompare3(TIM2,0);
						TIM_SetCompare3(TIM4,speed);
						break;
					}
					case 4:
					{
						TIM_SetCompare4(TIM2,0);
						TIM_SetCompare4(TIM4,speed);
						break;
					}
				}
			break;
		}
		case back_go:
		{
			switch(this->sign)
			{
				case 1:
				{
					TIM_SetCompare1(TIM2,speed);
					TIM_SetCompare1(TIM4,0);
					break;
				}
				case 2:
				{
					TIM_SetCompare2(TIM2,speed);
					TIM_SetCompare2(TIM4,0);
					break;
				}
				case 3:
				{
					TIM_SetCompare3(TIM2,speed);
					TIM_SetCompare3(TIM4,0);
					break;
				}
				case 4:
				{
					TIM_SetCompare4(TIM2,speed);
					TIM_SetCompare4(TIM4,0);
					break;
				}
			}
			break;
		}
	}
	this->speed=speed;
}

void Athletic::movement::motor::front()
{
	this->dir=front_go;
	Err=0;LastErr=0;LastLastErr=0;
	pwm_CCR=0;Add_CCR=0;
}
void Athletic::movement::motor::back()
{
	this->dir=back_go;
	Err=0;LastErr=0;LastLastErr=0;
	pwm_CCR=0;Add_CCR=0;
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
		case 0:
		{
			Init_TIMOC1(TIMx1,TIM_OCInitStr);
			Init_TIMOC1(TIMx2,TIM_OCInitStr);
		break;
		}
		case 1:
		{
			Init_TIMOC2(TIMx1,TIM_OCInitStr);
			Init_TIMOC2(TIMx2,TIM_OCInitStr);
			break;
		}
		case 2:
		{
			Init_TIMOC3(TIMx1,TIM_OCInitStr);
			Init_TIMOC3(TIMx2,TIM_OCInitStr);
			break;
		}
		case 3:
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

Athletic::movement::motor::motor(PWM CH):_run(true),rate(NULL)
{
	if(this->init(CH))
	{
		++initCount;
		this->sign=initCount;
		motor_List.push_back(this);
		this->front();
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
			gpio.GPIO_Pin=GPIO_Pin_0;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
			GPIO_Init(GPIOA,&gpio);
			gpio.GPIO_Pin=GPIO_Pin_6;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
			GPIO_Init(GPIOB,&gpio);
			this->rate=new Athletic::movement::Speed(Athletic::movement::Speed::right_front);
			break;
		}
		case CH2:
		{			
			gpio.GPIO_Pin=GPIO_Pin_1;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
			GPIO_Init(GPIOA,&gpio);
			gpio.GPIO_Pin=GPIO_Pin_7;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
			GPIO_Init(GPIOB,&gpio);
			this->rate=new Athletic::movement::Speed(Athletic::movement::Speed::left_front);
			break;
		}
		case CH3:
		{			
			gpio.GPIO_Pin=GPIO_Pin_2;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
			GPIO_Init(GPIOA,&gpio);
			gpio.GPIO_Pin=GPIO_Pin_8;			
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
			GPIO_Init(GPIOB,&gpio);
			this->rate=new Athletic::movement::Speed(Athletic::movement::Speed::right_back);
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
			this->rate=new Athletic::movement::Speed(Athletic::movement::Speed::left_back);
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
	this->resetTIM4();
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
	if(this->rate!=NULL)
	{
		delete this->rate;
		this->rate=NULL;
	}
	
	for(int i=0;i<motor_List.size();++i)
	{
		if(motor_List.at(i)==this)
		{
			motor_List.earse(i);
		}
	}
}

inline void Athletic::movement::motor::resetTIM2()
{
	time_conf::TIM::TIM_INIT::InitTIM2();
	Athletic::movement::motor::InitTIM_OC();
}

inline void Athletic::movement::motor::resetTIM4()
{
	time_conf::TIM::TIM_INIT::InitTIM4();
	Athletic::movement::motor::InitTIM_OC();
}

double Athletic::movement::motor::PID()
{
	const static double p=0.1,i=0.05,d=0.0;
	
	Err=this->speed-this->rate->get_rate();
	
	Add_CCR=p*(Err-LastErr)+i*(Err)+d*(Err+LastLastErr-2*LastErr);
	if(Add_CCR<-1||Add_CCR>1)
	{
		pwm_CCR+=Add_CCR;
	}
	
	if(pwm_CCR>999)
		pwm_CCR=999;
	if(pwm_CCR<0)
		pwm_CCR=0;
	LastLastErr=LastErr;
	LastErr=Err;
	
	return pwm_CCR;
}


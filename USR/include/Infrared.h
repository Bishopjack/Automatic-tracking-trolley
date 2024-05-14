#ifndef _INFRARED_H
#define _INFRARED_H
#include"standint.h"
#include"stm32f10x_gpio.h"
namespace Athletic
{
	namespace movement
	{

		class travel;
		class Infrared
		{
			friend void EXTI0(void);
			friend void EXTI1(void);
			friend void EXTI2(void);
			friend void EXTI3(void);
			
			friend void GPIO_conf(uint32_t,GPIO_TypeDef*,uint16_t Pin,void*);
		public:
			enum SITE{first,second,third,fourth};
			enum STATUS{enable,disable};
			Infrared(SITE site,STATUS status);
			bool getData();
		private:
			static void EXTI0();
			static void EXTI1();
			static void EXTI2();
			static void EXTI3();
		private:
			static travel* device;
			void init(Athletic::movement::Infrared::SITE& site,STATUS& status);
			void init(SITE& site);
			void* Port;
			uint32_t Pin;
		};
	}
}
#endif
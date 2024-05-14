#ifndef _SPEEDTEST_H
#define _SPEEDTEST_H

namespace Athletic
{
	namespace movement
	{
		typedef double speed_rate;
		//PA4,PA5,PA8,PA9
		class Speed
		{
			friend void EXTI4(void);
			friend void EXTI9_5(void);
			friend void EXTI15_10(void);
			friend void TIM1_IRQ(void);
		public:
			enum SITE{right_front,left_front,right_back,left_back};
			Speed(SITE site);
			speed_rate get_rate();
			void init_TIM();
		private:
			static void EXTI4();
			static void EXTI5();
			static void EXTI8();
			static void EXTI11();
			static void TIM1_UP();
		private:
			SITE site;
		};
	}
}

#endif
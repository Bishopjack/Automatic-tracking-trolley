#ifndef _MOTOR_H
#define _MOTOR_H

namespace Athletic
{
	namespace movement
	{
		class motor{
		public:
			
			motor();
			~motor();
			
			void front(unsigned int speed);
			void back(unsigned int speed);
			enum PWM{CH1,CH2,CH3,CH4};
		
			motor(PWM CH);
			inline void resetTIM2();
			inline void resetTIM4();
		private:
			static void InitTIM(void* TIMx);
			static void InitTIM_OC(void* TIMx1,void* TIMx2);
			bool init(PWM& CH);
			static int initCount;
			bool _run;
			char sign;
		};
	}
}

#endif
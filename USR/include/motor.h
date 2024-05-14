#ifndef _MOTOR_H
#define _MOTOR_H



namespace Athletic
{
	namespace movement
	{
		class Speed;
		class motor{
			private:
				friend void Go_rate(void*);
				friend void TIM1_IRQ(void);
		public:
			
			motor();
			~motor();
			
			void front();
			void back();
			void set_rate(unsigned int speed);
			enum PWM{CH1,CH2,CH3,CH4};
			motor(PWM CH);
			inline void resetTIM2();
			inline void resetTIM4();
		private:
			static void TIM1_PID();

		private:
			double PID();
		
			void go_rate(unsigned int speed);
			static void InitTIM_OC(void* TIMx1,void* TIMx2);
			bool init(PWM& CH);
			static int initCount;
			bool _run;
			char sign;
			Speed* rate;
			unsigned int speed;
			enum direction{front_go,back_go};
			direction dir;
		};
	}
}

#endif
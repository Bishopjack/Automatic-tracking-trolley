#ifndef _TIME_H
#define _TIME_H
namespace time_conf
{
  extern void CLK_Config();
	namespace TIM
	{
		class TIM_INIT{
			public:
				//1s
				static void InitTIM4();
				static void InitTIM2();
				static void InitTIM1();
		};
	}
}

#endif //!_TIME_H
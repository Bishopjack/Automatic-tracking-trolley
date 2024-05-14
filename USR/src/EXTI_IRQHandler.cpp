#include"speedtest.h"
#include"Infrared.h"

inline void Athletic::movement::EXTI4(void)
{
	Athletic::movement::Speed::EXTI4();
}
inline void Athletic::movement::EXTI9_5(void)
{
	Athletic::movement::Speed::EXTI5();
	Athletic::movement::Speed::EXTI8();
}
inline void Athletic::movement::EXTI15_10(void)
{
	Athletic::movement::Speed::EXTI11();
}

inline void Athletic::movement::EXTI0(void)
{
	Athletic::movement::Infrared::EXTI0();
}

inline void Athletic::movement::EXTI1(void)
{
	Athletic::movement::Infrared::EXTI1();
}
inline void Athletic::movement::EXTI2(void)
{
	Athletic::movement::Infrared::EXTI2();
}
inline void Athletic::movement::EXTI3(void)
{
	Athletic::movement::Infrared::EXTI3();
}

extern "C" void EXTI0_IRQHandler(void)
{
	Athletic::movement::EXTI0();
}
extern "C" void EXTI1_IRQHandler(void)
{
	Athletic::movement::EXTI1();
}
extern "C" void EXTI2_IRQHandler(void)
{
	Athletic::movement::EXTI2();
}
extern "C" void EXTI3_IRQHandler(void)
{
	Athletic::movement::EXTI3();
}

extern "C" void EXTI4_IRQHandler(void)
{
	Athletic::movement::EXTI4();
}
extern "C" void EXTI9_5_IRQHandler(void)
{
	Athletic::movement::EXTI9_5();
}

extern "C" void EXTI15_10_IRQHandler(void)
{
	Athletic::movement::EXTI15_10();
}

#ifndef _EXTI_CONF_H
#define _EXTI_CONF_H
#include"standint.h"
#include"stm32f10x_gpio.h"
namespace Athletic
{
	namespace movement
	{
		extern void GPIO_EXIT_conf(uint32_t rcc_peripth,GPIO_TypeDef* gpio,uint16_t Pin,uint32_t exti_line);
	}
}
#endif
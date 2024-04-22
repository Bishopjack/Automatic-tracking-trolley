#ifndef _MOTOR_H
#define _MOTOR_H
#include"stdint.h"

namespace Athletic
{
	class motor
	{
	public:
		enum PORT{GPIO_A,GPIO_B,GPIO_C,GPIO_D};
		motor(PORT gpio_port,uint16_t gpio_pin);
		~motor();
		motor(const motor&);
		motor& operator=(const motor&);
	private:
		static void InitTIM();
		static void InitTIM_OC();
		void init(PORT gpio_port,uint16_t gpio_pin);

	};
}
#endif
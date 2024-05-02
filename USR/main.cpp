#include"stm32f10x_it.h"
#include"motor.h"
#include"time.h"
int main(int argc,char** argv)
{
	time_conf::CLK_Config();
	Athletic::motor test(Athletic::motor::GPIO_A,GPIO_Pin_0);
	return 0;
}
#include"stm32f10x_it.h"
#include"motor.h"
int main(int argc,char** argv)
{
	Athletic::motor test(Athletic::motor::GPIO_A,GPIO_Pin_0);
	return 0;
}
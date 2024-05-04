#include"stm32f10x_it.h"
#include"travel.h"
#include"time.h"
#include"NVIC_Conf.h"
int main(int argc,char** argv)
{
	time_conf::CLK_Config();
	NVIC_Init();
	Athletic::movement::travel test;
	return 0;
}
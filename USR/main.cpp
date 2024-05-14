#include"time.h"
#include"myus.h"
#include"pwm.h"
#include"delay.h"
#include"movement.h"



int main(int argc,char** argv)
{
	time_conf::CLK_Config();
	My_US_Init();
	My_TIM3_Init(19999,71);
	time::delay::delay::InitDelay();
	Athletic::movement::trailing test;
	while(true)
	{
		test.run();
	}
	return 0;
}
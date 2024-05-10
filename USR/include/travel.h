#ifndef _TRAVEL_H
#define _TRAVEL_H
#include"stdint.h"

namespace Athletic
{
	namespace movement
	{
		class motor;
		class travel
		{
		public:
			travel();
			travel(const travel& m);
			travel& operator=(const travel& m);
			~travel();
			void run(unsigned int speed,short angle=0);
		private:;
			motor* motor1;
			motor* motor2;
			motor* motor3;
			motor* motor4;
		};
	}
}
#endif
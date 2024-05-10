#ifndef _SPEEDTEST_H
#define _SPEEDTEST_H

namespace Athletic
{
	namespace movement
	{
		typedef double speed_rate;
		class Speed
		{
		public:
			enum SITE{right_front,left_front,right_back,left_back};
			Speed(SITE site);
			speed_rate get_rate();
			void init_TIM();
			private:
			SITE site;
		};
	}
}

#endif
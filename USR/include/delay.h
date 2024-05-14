#ifndef _DELAY_H
#define _DELAY_H
#include"standint.h"

namespace time
{
	class delay
	{
	public:
		delay();
			
		static void InitDelay();

		inline static void delayms(unsigned int ms)
		{
			for(int i=0;i<ms;++i)
				time::delay::delayus(1000);
		}
			
		static void NVIC_Conf();
		
		inline static void delays(unsigned int s)
		{
			for(int i=0;i<s;++i)
				time::delay::delayms(1000);
		}
	
		static void delayus(unsigned int us);
	private:
		static time::uint8_t fac_us;
		static time::uint16_t fac_ms;
	};
	
}
#endif
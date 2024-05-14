#ifndef _MOVEMENT_H
#define _MOVEMENT_H

namespace Athletic
{
	namespace movement
	{
		class travel;
		class Infrared;
		class trailing
		{
			public:
				trailing();
				~trailing();
				void run();
			private:
				travel* device;
				Infrared* first;
				Infrared* second;
				Infrared* third;
				Infrared* fourth;
		};
	}
}

#endif
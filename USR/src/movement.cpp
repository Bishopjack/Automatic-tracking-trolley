#include"movement.h"
#include"NVIC_Conf.h"
#include"travel.h"
#include"Infrared.h"
#include<stddef.h>

Athletic::movement::trailing::trailing()
{
	this->device=new travel();
	this->first=new Athletic::movement::Infrared(Athletic::movement::Infrared::first,Athletic::movement::Infrared::enable);
	this->second=new Athletic::movement::Infrared(Athletic::movement::Infrared::second,Athletic::movement::Infrared::enable);
	this->third=new Athletic::movement::Infrared(Athletic::movement::Infrared::third,Athletic::movement::Infrared::disable);
	this->fourth=new Athletic::movement::Infrared(Athletic::movement::Infrared::fourth,Athletic::movement::Infrared::disable);
	NVIC_Conf::NVIC_INIT con;
}

Athletic::movement::trailing::~trailing()
{
	if(this->device!=NULL)
	{
		delete this->device;
		this->device=NULL;
	}
}

void Athletic::movement::trailing::run()
{
	while(true)
	{
		if(this->third->getData()||this->fourth->getData())
		{
			this->device->run(100,90);
		}
	}
}
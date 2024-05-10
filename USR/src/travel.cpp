#include"travel.h"
#include"stm32f10x_it.h"
#include"motor.h"
#include<new>

Athletic::movement::travel::travel()
{
	this->motor1=new Athletic::movement::motor(Athletic::movement::motor::CH1);
	this->motor2=new Athletic::movement::motor(Athletic::movement::motor::CH2);;
	this->motor3=new Athletic::movement::motor(Athletic::movement::motor::CH3);;
	this->motor4=new Athletic::movement::motor(Athletic::movement::motor::CH4);;
}

void Athletic::movement::travel::run(unsigned int speed,short angle)
{
	if(angle>=0 and angle<90)
	{
		this->motor1->front(speed);
		this->motor2->front(speed);
		this->motor3->front(speed);
		this->motor4->front(speed);
	}
	else if(angle>=90 and angle <180)
	{
		this->motor1->front(speed);
		this->motor2->front(speed);
		this->motor3->front(speed);
		this->motor4->front(speed);
	}
	else if(angle>=180 and angle <270)
	{
		this->motor1->back(speed);
		this->motor2->back(speed);
		this->motor3->back(speed);
		this->motor4->back(speed);
	}
	else if(angle>=270 and angle <360)
	{
		this->motor1->back(speed);
		this->motor2->back(speed);
		this->motor3->back(speed);
		this->motor4->back(speed);
	}		
}

Athletic::movement::travel::~travel()
{
	if(this->motor1!=NULL)
	{
		delete this->motor1;
		this->motor1=NULL;
	}
	if(this->motor2!=NULL)
	{
		delete this->motor2;
		this->motor2=NULL;
	}
	if(this->motor3!=NULL)
	{
		delete this->motor3;
		this->motor3=NULL;
	}
	if(this->motor4!=NULL)
	{
		delete this->motor4;
		this->motor4=NULL;
	}
}

Athletic::movement::travel::travel(const travel& m)
{
	this->motor1=m.motor1;
	this->motor2=m.motor2;	
	this->motor3=m.motor3;	
	this->motor4=m.motor4;
}

Athletic::movement::travel& Athletic::movement::travel::operator=(const travel& m)
{
	this->motor1=m.motor1;
	this->motor2=m.motor2;	
	this->motor3=m.motor3;	
	this->motor4=m.motor4;
	return *this;
}



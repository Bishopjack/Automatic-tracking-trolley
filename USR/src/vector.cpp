#include"vector.h"
#include"motor.h"
#include"stddef.h"


inline void Athletic::movement::Go_rate(void* element)
{
	Athletic::movement::motor* motor;
	motor=static_cast<Athletic::movement::motor*>(element);
	motor->go_rate(motor->PID());
}

vector::motor_vector::motor_vector()
{
	this->max=4;
	this->m_size=0;
	this->data=new void*[4];
}
vector::motor_vector::motor_vector(const motor_vector& ve)
{
	this->max=ve.max;
	this->m_size=ve.m_size;
	this->data=new void*[m_size];
	
	for(int i=0;i<m_size;++i)
	{
		this->data[i]=ve.data[i];
	}
	
}
void vector::motor_vector::push_back(void* ve)
{
	unsigned int after_size=this->m_size;
	
	if(after_size>this->max)
	{
		void** temp=new void*[this->max+4];
		for(int i=0;i<max;++i)
		{
			temp[i]=this->data[i];
		}
		this->max+=2;
		temp[after_size]=ve;
		delete[] this->data;
		this->data=temp;
	}
	else
	{
		this->data[after_size]=ve;
	}
	++this->m_size;
}
void vector::motor_vector::run()
{
	for(int i=0;i<this->m_size;++i)
	{
		Athletic::movement::Go_rate(this->data[i]);
	}
}
void vector::motor_vector::earse(unsigned int address)
{
	for(int i=address+1;i<this->m_size;++i)
	{
		this->data[i-1]=this->data[i];
	}
	--this->m_size;
	if(this->m_size<this->max-2)
	{
		this->max-=2;
	}
}

void* vector::motor_vector::at(unsigned int address)
{
	return data[address];
}

vector::motor_vector::~motor_vector()
{
	if(this->data!=NULL)
	{
		delete[] this->data;
		this->data=NULL;
	}
}

unsigned int vector::motor_vector::size()
{
	return this->m_size;
}

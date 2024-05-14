#ifndef _VECTOR_H

namespace vector
{
class motor_vector
{
	public:
		motor_vector();
		motor_vector(const motor_vector&);
		~motor_vector();
		void push_back(void*);
		void* at(unsigned int address);
		unsigned int size();
		void run();
		void earse(unsigned int address);
	protected:
		unsigned int max;
		unsigned int m_size;
		void** data;
		
};
}

#endif
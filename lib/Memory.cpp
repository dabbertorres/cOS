#include "Memory.hpp"

namespace cos
{
	namespace mem
	{
		uint8 inport(uint16 port)
		{
			unsigned char rv;
			asm volatile("inb %1, %0" : "=a"(rv) : "dN"(port));
			return rv;
		}

		void outport(uint16 port, uint8 data)
		{
			asm volatile("outb %1, %0" : : "dN"(port), "a"(data));
		}
	}
}

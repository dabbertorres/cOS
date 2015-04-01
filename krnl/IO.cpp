#include "IO.hpp"

namespace cos
{
	namespace io
	{
		uint8 inport(uint16 port)
		{
			uint8 ret;
			asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));
			return ret;
		}

		void outport(uint16 port, uint8 data)
		{
			asm volatile("outb %1, %0" : : "dN"(port), "a"(data));
		}

		void wait()
		{
			asm volatile("outb %%al, $0x80" : : "a"(0));
		}
	}
}

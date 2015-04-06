#include "IO.hpp"

namespace cos
{
	namespace io
	{
		uint8 in8(uint16 port)
		{
			uint8 ret;
			asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));
			return ret;
		}
		
		uint16 in16(uint16 port)
		{
			uint16 ret;
			asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));
			return ret;
		}
		
		uint32 in32(uint16 port)
		{
			uint32 ret;
			asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));
			return ret;
		}

		void out8(uint16 port, uint8 data)
		{
			asm volatile("outb %1, %0" : : "dN"(port), "a"(data));
		}

		void out16(uint16 port, uint16 data)
		{
			asm volatile("outb %1, %0" : : "dN"(port), "a"(data));
		}

		void out32(uint16 port, uint32 data)
		{
			asm volatile("outb %1, %0" : : "dN"(port), "a"(data));
		}

		void wait()
		{
			asm volatile("outb %%al, $0x80" : : "a"(0));
		}
	}
}

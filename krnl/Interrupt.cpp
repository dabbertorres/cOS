#include "Interrupt.hpp"

#include "../lib/Types.hpp"

namespace cos
{
	Interrupt::Interrupt()
	{
	}

	Interrupt::~Interrupt()
	{
	}

	bool Interrupt::areEnabled()
	{
		uint64 flags;

		asm volatile("pushf\n\t"
		             "pop %0"
		             : "=g"(flags));
		
		return flags & (1 << 9);
	}
}

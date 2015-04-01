#include "Memory.hpp"

namespace cos
{
	namespace mem
	{
		uint32 farPeek(uint16 sel, void* off)
		{
			uint32 ret;
			asm volatile("push %%fs\n\t"
			             "mov  %1, %%fs\n\t"
			             "mov  %%fs:(%2), %0\n\t"
			             "pop  %%fs"
			             : "=r"(ret) : "g"(sel), "r"(off));
			return ret;
		}

		void farPoke(uint16 sel, void* off, uint8 v)
		{
			asm volatile("push %%fs\n\t"
			             "mov  %0, %%fs\n\t"
			             "movb %2, %%fs:(%1)\n\t"
			             "pop %%fs"
			             : : "g"(sel), "r"(off), "r"(v));
		}
	}
}

#ifndef COS_MEMORY_HPP
#define COS_MEMORY_HPP

#include "Types.hpp"

namespace cos
{
	namespace mem
	{
		uint32 farPeek(uint16 sel, void* off);
		void farPoke(uint16 sel, void* off, uint8 v);
	}
}

#endif // COS_MEMORY_HPP

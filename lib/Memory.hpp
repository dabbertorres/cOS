#ifndef COS_MEMORY_HPP
#define COS_MEMORY_HPP

#include "Types.hpp"

namespace cos
{
	namespace mem
	{
		uint8 inport(uint16 port);
		void outport(uint16 port, uint8 data);
	}
}

#endif // COS_MEMORY_HPP

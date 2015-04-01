#ifndef COS_IO_HPP
#define COS_IO_HPP

#include "../lib/Types.hpp"

namespace cos
{
	namespace io
	{
		uint8 inport(uint16 port);
		void outport(uint16 port, uint8 data);
		
		void wait();
	}
}

#endif // COS_IO_HPP

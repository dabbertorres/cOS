#ifndef COS_IO_HPP
#define COS_IO_HPP

#include "../lib/Types.hpp"

namespace cos
{
	namespace io
	{
		uint8 in8(uint16 port);
		uint16 in16(uint16 port);
		uint32 in32(uint16 port);
		
		void out8(uint16 port, uint8 data);
		void out16(uint16 port, uint16 data);
		void out32(uint16 port, uint32 data);
		
		void wait();
	}
}

#endif // COS_IO_HPP

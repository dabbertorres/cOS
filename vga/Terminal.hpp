#ifndef COS_TERMINAL_HPP
#define COS_TERMINAL_HPP

#include "../lib/Types.hpp"
#include "Color.hpp"

namespace cos
{
	namespace vga
	{
		class Terminal
		{
			public:
				// w = width of terminal
				// h = height of terminal
				Terminal(uint16 w, uint16 h);

				void putCharAt(char c, uint16 x, uint16 y);
				void putChar(char c);
				void writeString(const char* s);

				void setColor(const Color& fg, const Color& bg);

				void clear();
				void scroll();

				void setPosition(uint16 x, uint16 y);

			private:
				void moveCursor();

				const uint16 WIDTH;
				const uint16 HEIGHT;

				uint16* buffer;

				uint16 row;
				uint16 column;

				uint8 color;
				const uint8 clearColor;
		};
	}
}

#endif // COS_TERMINAL_HPP

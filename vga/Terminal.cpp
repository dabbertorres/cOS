#include "Terminal.hpp"

#include "../lib/String.hpp"

#include "../lib/Memory.hpp"

namespace cos
{
	namespace vga
	{
		Terminal::Terminal(uint16 w, uint16 h)
			:	WIDTH(w),
			    HEIGHT(h),
			    buffer(reinterpret_cast<uint16*>(0xb8000)),
			    row(0),
			    column(0),
			    color(Color::Black << 4 | Color::LightGrey),
			    clearColor(Color::Black << 4 | Color::LightGrey)
		{
			clear();
		}

		void Terminal::putCharAt(char c, uint16 x, uint16 y)
		{
			if(x >= WIDTH || y >= HEIGHT)
			{
				return;
			}

			const uint16 c16 = c;
			const uint16 col16 = color;

			buffer[y * WIDTH + x] = col16 << 8 | c16;
		}

		void Terminal::putChar(char c)
		{
			// backspace
			if(c == 0x08)
			{
				if(column != 0)
				{
					column--;
				}
			}
			// tab
			else if(c == 0x08)
			{
				column = (column + 8) & ~(8 - 1);
			}
			// carriage return
			else if(c == '\r')
			{
				column = 0;
			}
			// newline
			else if(c == '\n')
			{
				column = 0;
				row++;
			}
			// anything space or greater is printable
			else if(c >= ' ')
			{
				putCharAt(c, column, row);
				column++;
			}

			if(column == WIDTH)
			{
				column = 0;
				row++;

				if(row == HEIGHT)
				{
					row = 0;
				}
			}

			moveCursor();
		}

		void Terminal::writeString(const char* s)
		{
			uint32 len = String::getLength(s);

			for(uint32 i = 0; i < len; i++)
			{
				putChar(s[i]);
			}
		}

		void Terminal::setColor(const Color& fg, const Color& bg)
		{
			color = bg << 4 | fg;
		}

		void Terminal::clear()
		{
			uint8 currentColor = color;
			color = clearColor;

			for(uint16 y = 0; y < HEIGHT; y++)
			{
				for(uint16 x = 0; x < WIDTH; x++)
				{
					putCharAt(' ', x, y);
				}
			}

			color = currentColor;

			setPosition(0, 0);
		}

		void Terminal::scroll()
		{
			if(row != HEIGHT)
			{
				return;
			}

			uint16 lastLine[WIDTH];

			for(int i = 0; i < WIDTH; i++)
			{
				lastLine[i] = buffer[(HEIGHT - 1) * WIDTH + i];
			}

			clear();

			for(int i = 0; i < WIDTH; i++)
			{
				buffer[i] = lastLine[i];
			}

			row = 1;
			column = 0;
		}

		void Terminal::setPosition(uint16 x, uint16 y)
		{
			column = x;
			row = y;

			moveCursor();
		}

		void Terminal::moveCursor()
		{
			uint16 idx = row * WIDTH + column;

			mem::outport(0x3d4, 14);
			mem::outport(0x3d5, idx >> 8);
			mem::outport(0x3d4, 15);
			mem::outport(0x3d5, idx);
		}
	}
}

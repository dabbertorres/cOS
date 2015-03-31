#include "Color.hpp"

namespace cos
{
	namespace vga
	{
		const Color Color::Black(0);
		const Color Color::Blue(1);
		const Color Color::Green(2);
		const Color Color::Cyan(3);
		const Color Color::Red(4);
		const Color Color::Magenta(5);
		const Color Color::Brown(6);
		const Color Color::LightGrey(7);
		const Color Color::DarkGrey(8);
		const Color Color::LightBlue(9);
		const Color Color::LightGreen(10);
		const Color Color::LightCyan(11);
		const Color Color::LightRed(12);
		const Color Color::LightMagenta(13);
		const Color Color::LightBrown(14);
		const Color Color::White(15);

		Color::Color()
			:	value(Color::Black)
		{}

		Color::Color(const Color& other)
			:	value(other)
		{}

		Color& Color::operator=(const Color& other)
		{
			value = other.value;
			return *this;
		}

		Color::operator uint8() const
		{
			return value;
		}

		Color::Color(uint8 c)
			:	value(c)
		{}

		bool operator==(const Color& l, const Color& r)
		{
			return l.value == r.value;
		}

		bool operator!=(const Color& l, const Color& r)
		{
			return !(l == r);
		}
	}
}

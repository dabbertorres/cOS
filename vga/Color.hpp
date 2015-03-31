#ifndef COS_COLOR_HPP
#define COS_COLOR_HPP

#include "../lib/Types.hpp"

namespace cos
{
	namespace vga
	{
		class Color
		{
			public:
				// basic values
				static const Color Black;
				static const Color Blue;
				static const Color Green;
				static const Color Cyan;
				static const Color Red;
				static const Color Magenta;
				static const Color Brown;
				static const Color LightGrey;
				static const Color DarkGrey;
				static const Color LightBlue;
				static const Color LightGreen;
				static const Color LightCyan;
				static const Color LightRed;
				static const Color LightMagenta;
				static const Color LightBrown;
				static const Color White;

				// constructors
				Color();
				Color(const Color&);

				Color& operator=(const Color&);

				// cast operators
				operator uint8() const;

				// operators
				friend bool operator==(const Color&, const Color&);
				friend bool operator!=(const Color&, const Color&);

			private:
				// private to prevent people from making Colors with nums.
				// but we need it to make the Color types. So it exists.
				Color(uint8);
				uint8 value;
		};
	}
}

#endif // COS_COLOR_HPP

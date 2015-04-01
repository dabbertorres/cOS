#ifndef INTERRUPT_HPP
#define INTERRUPT_HPP

namespace cos
{
	class Interrupt
	{
		public:
			Interrupt();
			~Interrupt();
			
			static bool areEnabled();

	};
}

#endif // INTERRUPT_HPP

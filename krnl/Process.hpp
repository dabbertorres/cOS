#ifndef COS_PROCESS_HPP
#define COS_PROCESS_HPP

#include "../lib/Types.hpp"

namespace cos
{
	class Process
	{
		public:
			Process(uint32 memNeed);
			~Process();
			
			static uint32 total();

			void sleep(uint32 ms);
			void wake();

		private:
			static uint32 numberOf;
			
			bool isSleeping;
	};
}

#endif // COS_PROCESS_HPP

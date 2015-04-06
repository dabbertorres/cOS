#ifndef COS_PROCESS_HPP
#define COS_PROCESS_HPP

#include "../lib/Types.hpp"

namespace cos
{
	class Process
	{
		public:
			Process(uint32 memNeed = 0, int p = 5);
			~Process();
			
			static uint32 total();
			
			bool isSleeping() const;

			void sleep(uint32 ms);
			void wake();

		private:
			static uint32 numberOf;
			//static <some sort of array storage> allProcesses
			
			uint32 memoryUsage;	// KB?
			
			uint8 priority;	// 0 - 10?
			
			bool sleeping;
			uint32 timeLeftToSleep;
	};
}

#endif // COS_PROCESS_HPP

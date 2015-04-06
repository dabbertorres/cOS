#include "Process.hpp"

namespace cos
{
	Process::Process(uint32 memNeed, int p)
	:	memoryUsage(memNeed),
		priority(p),
		sleeping(false),
		timeLeftToSleep(0)
	{
		numberOf++;
	}
	
	Process::~Process()
	{
		numberOf--;
	}
	
	uint32 Process::total()
	{
		return numberOf;
	}
	
	bool Process::isSleeping() const
	{
		return sleeping;
	}
	
	void Process::sleep(uint32 ms)
	{
		sleeping = true;
		timeLeftToSleep = ms;
	}
	
	void Process::wake()
	{
		sleeping = false;
		timeLeftToSleep = 0;
	}
	
	uint32 Process::numberOf = 0;
}

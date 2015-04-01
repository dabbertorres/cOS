#ifndef CPUID_HPP
#define CPUID_HPP

#include "../lib/Types.hpp"

namespace cos
{
	class CpuID
	{
		public:
			enum class Vendor : uint8
			{
			    Intel = 0,
			    AMD = 1,
			    Unknown = 2,
				NotSet = 3,
			};
			
			enum class Feature : uint32
			{
				
			};

			static Vendor getVendor();
			static const char* getVendorString();

		private:
			static void findVendor();
			
			static bool cpuid(uint8 in, uint32 out[4]);
			
			static const char* VENDOR_STRINGS[3];
			
			static const uint32 VENDOR_CODES[3][3];

			static Vendor vendor;
			
			static uint8 maxValueEAX;
	};
}

#endif // CPUID_HPP

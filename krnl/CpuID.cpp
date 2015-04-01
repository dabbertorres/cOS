#include "CpuID.hpp"

namespace cos
{
	CpuID::Vendor CpuID::getVendor()
	{
		if(vendor == Vendor::NotSet)
		{
			findVendor();
		}

		return vendor;
	}

	const char* CpuID::getVendorString()
	{
		if(vendor == Vendor::NotSet)
		{
			findVendor();
		}

		return VENDOR_STRINGS[static_cast<uint8>(vendor)];
	}

	void CpuID::findVendor()
	{
		uint32 registers[4];

		bool valid = cpuid(0, registers);

		if(!valid)	// we made an invalid call
		{
			return;
		}

		// update maxValue for eax
		maxValueEAX = registers[0];

		if(	registers[1] == VENDOR_CODES[0][0] &&
			registers[2] == VENDOR_CODES[0][1] &&
			registers[3] == VENDOR_CODES[0][2])
		{
			vendor = Vendor::Intel;
		}
		else if(registers[1] == VENDOR_CODES[1][0] &&
		        registers[2] == VENDOR_CODES[1][1] &&
		        registers[3] == VENDOR_CODES[1][2])
		{
			vendor = Vendor::AMD;
		}
		else
		{
			vendor = Vendor::Unknown;
		}
	}

	bool CpuID::cpuid(uint8 in, uint32 out[4])
	{
		if(in > maxValueEAX)	// invalid value for eax
		{
			return false;
		}

		asm volatile("cpuid": "=a"(out[0]), "=b"(out[1]), "=c"(out[2]), "=d"(out[3]) : "a"(in));

		return true;
	}

	const char* CpuID::VENDOR_STRINGS[3] =
	{
		"GenuineIntel",
		"AuthenticAMD",
		"Unknown",
	};

	const uint32 CpuID::VENDOR_CODES[3][3] =
	{
		// Intel
		{0x756e6547, 0x6c65746e, 0x49656e69},	// "uneG", "letn", "Ieni"
		// AMD
		{0x68747541, 0x444d4163, 0x69746e65},	// "htuA", "DMAc", "itne"
		// Unknown
		{0, 0, 0},
	};

	CpuID::Vendor CpuID::vendor = CpuID::Vendor::NotSet;

	uint8 CpuID::maxValueEAX = 0;
}

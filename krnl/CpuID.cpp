#include "CpuID.hpp"

namespace cos
{
	CpuID::Vendor CpuID::getVendor()
	{
		if(vendor == Vendor::NotSet)
			findVendor();

		return vendor;
	}

	const char* CpuID::getVendorString()
	{
		if(vendor == Vendor::NotSet)
			findVendor();

		return VENDOR_STRINGS[static_cast<uint8>(vendor)];
	}
	
	const char* CpuID::getModelString()
	{
		if(modelString[0] == 0)
			calcBrandString();
		
		return modelString;
	}
	
	uint8 CpuID::getStepID()
	{
		if(displayStepID == 0)
			getVersion();
		
		return displayStepID;
	}
	
	uint8 CpuID::getModelID()
	{
		if(displayModelID == 0)
			getVersion();
		
		return displayModelID;
	}
	
	uint8 CpuID::getFamilyID()
	{
		if(displayFamilyID == 0)
			getVersion();
		
		return displayFamilyID;
	}
	
	uint8 CpuID::getTypeID()
	{
		if(displayTypeID == 0)
			getVersion();
		
		return displayTypeID;
	}
	
	uint16 CpuID::getClflushLineSize()
	{
		if(clflushLineSize == 0)
			getVersion();
		
		return clflushLineSize;
	}
	
	uint8 CpuID::getNumLogicalProcessors()
	{
		if(numLogicalProcessors == 0)
			getVersion();
		
		return numLogicalProcessors;
	}
	
	uint8 CpuID::getInitialAPICID()
	{
		if(initialAPICID == 0)
			getVersion();
		
		return initialAPICID;
	}
	
	bool CpuID::hasFeature(FeatureECX f)
	{
		if(featuresECX == 0)
			getVersion();
		
		return featuresECX & static_cast<uint32>(f);
	}
	
	bool CpuID::hasFeature(FeatureEDX f)
	{
		if(featuresEDX == 0)
			getVersion();
		
		return featuresEDX & static_cast<uint32>(f);
	}

	bool CpuID::cpuid(uint32 in, uint32 out[4])
	{
		if(in > maxValueEAX && (in < 0x80000000 || in > maxExtValueEAX))	// invalid value for eax
		{
			return false;
		}

		asm volatile("cpuid": "=a"(out[0]), "=b"(out[1]), "=c"(out[2]), "=d"(out[3]) : "a"(in));

		return true;
	}

	void CpuID::findVendor()
	{
		uint32 registers[4] = {0, 0, 0, 0};

		cpuid(0x0, registers);

		// update maxValue for eax
		maxValueEAX = registers[0];
		
		// Intel check
		if(	registers[1] == VENDOR_CODES[0][0] &&
			registers[2] == VENDOR_CODES[0][1] &&
			registers[3] == VENDOR_CODES[0][2])
		{
			vendor = Vendor::Intel;
		}
		// AMD check
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
		
		getMaxExtValueEax();
	}
	
	void CpuID::getVersion()
	{
		if(vendor == Vendor::NotSet)
			findVendor();
		
		uint32 registers[4] = {0, 0, 0, 0};
		
		cpuid(0x1, registers);
		
		// parse eax
		displayStepID = registers[0] & 0xf;				// bits 0-3
		uint8 modelID = registers[0] >> 4 & 0xf;		// bits 4-7
		uint8 familyID = registers[0] >> 8 & 0xf;		// bits 8-11
		displayTypeID = registers[0] >> 12 & 0x3;		// bits 12-13
		uint8 extModelID = registers[0] >> 16 & 0xf;	// bits 16-19 *only needed when familyID is 0x6 or 0xf
		uint8 extFamilyID = registers[0] >> 20 & 0xff;	// bits 20-27 *only needed when familyID is 0xf
		
		// handle final familyID
		if(familyID == 0xf)
			displayFamilyID = familyID + extFamilyID;
		else
			displayFamilyID = familyID;
		
		// handle final modelID
		if(familyID == 0x6 || familyID == 0xf)
		 	displayModelID = extModelID << 4 | modelID;
		else
			displayModelID = modelID;
		
		// parse ebx
		//uint8 brandIdx = registers[1] & 0xff;	// brand string index is no longer used
		clflushLineSize = (registers[1] >> 8 & 0xff) * 8;
		numLogicalProcessors = registers[1] >> 16 & 0xff;
		initialAPICID = registers[1] >> 24 & 0xff;
		 
		// parse ecx
		featuresECX = registers[2];
		
		// parse edx
		featuresEDX = registers[3];
	}
	
	void CpuID::getMaxExtValueEax()
	{
		uint32 registers[4] = {0, 0, 0, 0};
		
		cpuid(0x80000000, registers);
		
		maxExtValueEAX = registers[0];
	}
	
	// assuming brand string is supported
	void CpuID::calcBrandString()
	{
		if(maxExtValueEAX == 0)
			getMaxExtValueEax();
		
		uint32 registers[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		uint32* registersSet0 = &registers[0];	// bytes 0 - 15
		uint32* registersSet1 = &registers[4];	// bytes 16 - 31
		uint32* registersSet2 = &registers[8];	// bytes 32 - 47
		
		cpuid(0x80000002, registersSet0);
		cpuid(0x80000003, registersSet1);
		cpuid(0x80000004, registersSet2);
		
		for(int i = 0; i < 48; i += 4)
		{
			for(int j = 0; j < 4; j++)
			{
				modelString[i + j] = registers[i / 4] >> 8 * j & 0xff;
			}
		}
		
		modelString[46] = 'H';
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
		{0x0, 0x0, 0x0},
	};

	CpuID::Vendor CpuID::vendor = CpuID::Vendor::NotSet;
	
	uint8 CpuID::displayStepID = 0;
	uint8 CpuID::displayModelID = 0;
	uint8 CpuID::displayFamilyID = 0;
	uint8 CpuID::displayTypeID = 0;
	
	char CpuID::modelString[48] = {0};
	uint16 CpuID::clflushLineSize = 0;
	uint8 CpuID::numLogicalProcessors = 0;
	uint8 CpuID::initialAPICID = 0;
	
	uint32 CpuID::featuresECX = 0;
	uint32 CpuID::featuresEDX = 0;

	uint16 CpuID::maxValueEAX = 0;
	uint32 CpuID::maxExtValueEAX = 0x80000000;
	
	uint32 CpuID::maxValueECX = 0;
}

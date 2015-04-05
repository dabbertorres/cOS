#ifndef CPUID_HPP
#define CPUID_HPP

#include "../lib/Types.hpp"

// Assuming we have CpuID support, since pretty much all modern x86 cpus support it

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
			
			enum class FeatureECX : uint32
			{
				// ECX features
				SSE3 = 1 << 0,			// Streaming SIMD Extensions 3
				PCLMULQDQ = 1 << 1,		// carryless multiplication
				DTES64 = 1 << 2,		// 64-bit DS Area
				MONITOR = 1 << 3,		// MONITOR / MWAIT
				DSCPL = 1 << 4,			// CPL Qualified Debug Store
				VMX = 1 << 5,			// Virtual Machine Extensions
				SMX = 1 << 6,			// Safer Mode Extensions
				EIST = 1 << 7,			// Enhanced Intel SpeedStep
				TM2 = 1 << 8,			// Thermal Monitor 2
				SSSE3 = 1 << 9,			// Supplemental Streaming SIMD Extensions 3
				CNXTID = 1 << 10,		// L1 Cache Context ID (adaptive or shared mode)
				SDBG = 1 << 11,			// IA32_DEBUG_INTERFACE MSR
				FMA = 1 << 12,			// FMA extensions with YMM state
				CMPXCHG16B = 1 << 13,	// 16 byte compare and exchange
				xTPRUC = 1 << 14,		// xTPR Update Control, IA32_MISC_ENABLE[bit 23]
				PDCM = 1 << 15,			// Perfmon and Debug Capability (MSR IA32_PERF_CAPABILITIES)
										// bit 16 is reserved
				PCID = 1 << 17,			// Process Context Identifiers (CRF4.PCIDE may be set to 1)
				DCA = 1 << 18,			// Processor may prefetch data from memory mapped devices
				SSE41 = 1 << 19,		// SSE4.1 is supported
				SSE42 = 1 << 20,		// SSE4.2 is supported
				x2APIC = 1 << 21,		// x2APIC is supported
				MOVBE = 1 << 22,		// MOVBE instruction is supported
				POPCNT = 1 << 23,		// POPCNT instruction is supported
				TSCDV = 1 << 24,			// local APIC timer supports one-shot operation using a TSC deadline value
				AESNI = 1 << 25,		// ASENI instruction extensions supported
				XSAVE = 1 << 26,		// XSAVE / XRSTOR extended states, XSETBV / XGETBV instructions, and XCR0 are supported
				OSXSAVE = 1 << 27,		// OS has enabled CR4.OSXSAVE[bit 18] to enable above features
				AVX = 1 << 28,			// AVX instruction extensions supported
				F16C = 1 << 29,			// 16-bit floating point conversion instructions are supported
				RDRAND = 1 << 30,		// RDRAND instruction is supported
										// bit 31 is not used
			};
			
			enum class FeatureEDX : uint32
			{
				// EDX features
				FPU = 1 << 0,			// Floating Point Unit - processor contains an x87 FPU
				VME = 1 << 1,			// Virtual 8086 Mode Enhancements - (CR4.VME (for controlling feature), CR4.PVI (protected mode virtual interrupts),
										// software interrupt indirection, expansion of the TSS, and EFLAGS.VIF and EFLAGS.VIP flags
				DE = 1 << 2,			// Debugging Extensions - I/O breakpoints, CR4.DE (for controlling feature), and optional trapping of accesses to DR4 and DR5
				PSE = 1 << 3,			// Page Size Extension - Large pages of 4 MB supported, CR4.PSE (for controlling feature), 
										// defined dirty bit in PDE (Page Directory Extensions), optional reserved bit trapping in CR3, PDEs, and PTEs
				TSC = 1 << 4,			// Time Stamp Counter - RDTSC instruction is supported, including CR4.TSD (for controlling privilege)
				MSR = 1 << 5,			// Model Specific Registers - RDMSR and WRMSR instructions are supported
				PAE = 1 << 6,			// Physical Address Extension - Physical Addresses >32 bits are supported, 2 MB pages are supported instead of 4 MB pages
				MCE = 1 << 7,			// Machine Check Exception - Exception 18 is defined for Machine Checks, CR4.MCE (for controlling feature)
				CX8 = 1 << 8,			// CMPXCHG8B instruction is supported (64 bits compare and exchange, implicitly locked and atomic)
				APIC = 1 << 9,			// APIC - processor contains an Advanced Programmable Interrupt Controller - responds to address range: 0xfffe0000 - 0xfffe0fff
										// bit 10 is reserved
				SEP = 1 << 11,			// SYSENTER and SYSEXIT instructions are supported (and associated MSRs)
				MTRR = 1 << 12,			// Memory Type Range Registers are supported - MTRRcap MSR shows supported memory types, # of MTRRs, and fixed MTRRs
				PGE = 1 << 13,			// Page Global Bit - indicates TLB entries that need not be flushed. CR4.PGE controls feature
				MCA = 1 << 14,			// Machince Check Architecture - error reporting is supported. MCG_CAP MSR shows supported # of error reporting MSRs
				CMOV = 1 << 15,			// Conditional Move Instructions - supported. if x87 FPU is present, FCOMI and FCMOV instructions are supported
				PAT = 1 << 16,			// Page Attribute Table - supported. OS may specify memory attributes of linear addresses on 4KB granularity
				PSE36 = 1 << 17,		// 36 bit Page Size Extension - 4MB pages addressing physical memory beyond 4GB are supported with 32 bit paging
										// upper bits of a 4MB page are encoded in bits 20-13 of the page-directory entry. Limited by MAXPHYADDR and 40 bits in size
				PSN = 1 << 18,			// Processor Serial Number - 96 bit processor ID# is supported and enabled
				CLFSH = 1 << 19,		// CLFLUSH Instruction is supported
										// bit 20 is reserved
				DS = 1 << 21,			// Debug Store - Writing debug info to a memory resident buffer is supported. Used by Branch Trace Store and Precise Event-Based Sampling
				ACPI = 1 << 22,			// Thermal Monitor and Software Controlled Clock Facilities - internal MSRs allow temps to be monitored and performance to be modulated
				MMX = 1 << 23,			// Intel MMX is supported
				FXSR = 1 << 24,			// FXSAVE and FXSTOR Instructions are supported. Indicates CR4.OSFXSR is available
				SSE = 1 << 25,			// SSE extensions are supported
				SSE2 = 1 << 26,			// SSE2 extensions are supported
				SS = 1 << 27,			// Self Snoop - management of conflicting memory types for transactions issued to the bus is supported
				HTT = 1 << 28,			// (HyperThreading Technology) Max APIC IDs reserved field is valid. (CPUID.1.EBX[23-16] is valid)
				TM = 1 << 29,			// Thermal Monitor - automatic thermal control circuitry (TCC) is implemented
										// bit 30 is reserved
				PBE = 1u << 31,			// Pending Break Enable - use of FERR# / PBE# pin when stop-clock state (STPCLK#) is active to signal that an interrupt is pending and
										// return to normal operation to handle the interrupt is supported. bit 10 in IA32_MISC_ENABLE MSR enables this
			};

			static Vendor getVendor();
			static const char* getVendorString();
			
			static const char* getModelString();
			
			static uint8 getStepID();
			static uint8 getModelID();
			static uint8 getFamilyID();
			
			// 0 = Original OEM Processor
			// 1 = Intel OverDrive Processor
			// 2 = Dual Processor
			// 3 = Intel Reserved
			static uint8 getTypeID();
			
			static uint16 getClflushLineSize();
			static uint8 getNumLogicalProcessors();
			static uint8 getInitialAPICID();
			
			static bool hasFeature(FeatureECX f);
			static bool hasFeature(FeatureEDX f);

		private:
			static bool cpuid(uint32 in, uint32 out[4]);
			
			// calls cpuid with an eax value of 0x0
			static void findVendor();
			
			// calls cpuid with an eax value of 0x1
			static void getVersion();
			
			// calls cpuid with an eax value of 0x2
			// cache and tlb info
			
			// calls cpuid with an eax value of 0x4
			// cache parameters
			
			// calls cpuid with an eax value of 0x5
			// MONITOR / MWAIT
			
			// calls cpuid with an eax value of 0x6
			// Thermal and Power Management
			
			// calls cpuid with an eax value of 0x7
			// extended featuer flags
			// output depends on input value for ecx
			
			// calls cpuid with an eax value of 0x9
			// IA32_PLATFORM_DCA_CAP MSR: 0x1f8
			
			// calls cpuid with an eax value of 0xa
			// architectural performance monitoring
			
			// calls cpuid with an eax value of 0xb
			// extended topology
			// output depends on input value for ecx
			
			// calls cpuid with an eax value of 0xd
			// processor extended state
			// should have a second input for ecx
			
			// calls cpuid with an eax value of 0xf
			// platform QoS monitoring
			// should have a second input for ecx
			
			// calls cpuid with an eax value of 0x10
			// platform QoS Enforcement monitoring
			// should have a second input for ecx
			
			// calls cpuid with an eax value of 0x14
			// intel processor trace
			
			// calls cpuid with an eax value of 0x15
			// time stamp counter / core crystal clock
			
			/* Extended CpuID Information */
			// calls cpuid with an eax value of 0x80000000
			static void getMaxExtValueEax();
			
			// calls cpuid with an eax value of 0x80000001
			
			
			// calls cpuid with an eax value of 0x80000002 - 0x80000004
			static void calcBrandString();
			
			// calls cpuid with an eax value of 0x80000006
			
			
			// calls cpuid with an eax value of 0x80000007
			
			
			// calls cpuid with an eax value of 0x80000008
			
			// vendor codes/strings
			static const char* VENDOR_STRINGS[3];
			static const uint32 VENDOR_CODES[3][3];

			static Vendor vendor;
			
			// CPU identification
			static uint8 displayStepID;
			static uint8 displayModelID;
			static uint8 displayFamilyID;
			static uint8 displayTypeID;
			
			// processor info
			static char modelString[48];
			static uint16 clflushLineSize;
			static uint8 numLogicalProcessors;
			static uint8 initialAPICID;
			
			// feature codes
			static uint32 featuresECX;
			static uint32 featuresEDX;
			
			static uint16 maxValueEAX;
			static uint32 maxExtValueEAX;
			
			static uint32 maxValueECX;
	};
}

#endif // CPUID_HPP

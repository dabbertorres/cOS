// main file for our kernel

#define NO_NAME_MANGLE extern "C"

#if defined(__linux__) || defined(_WIN32) || defined(__APPLE__) && defined(__MACH__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This OS needs to be compiled with a ix86-elf compiler"
#endif

#include "lib/String.hpp"

#include "vga/Color.hpp"
#include "vga/Terminal.hpp"

#include "krnl/Interrupt.hpp"
#include "krnl/CpuID.hpp"

NO_NAME_MANGLE
void kernelMain()
{
	cos::vga::Terminal terminal(80, 25);

	terminal.writeString("hi!");

	terminal.writeString(" Hello world! ");

	terminal.setColor(cos::vga::Color::LightGreen, cos::vga::Color::DarkGrey);

	terminal.writeString("so?");

	terminal.setColor(cos::vga::Color::LightRed, cos::vga::Color::Cyan);

	for(int i = 0; i < 100; i++)
	{
		terminal.putChar('.');
	}

	terminal.setColor(cos::vga::Color::Red, cos::vga::Color::Black);

	terminal.setPosition(10, 4);
	terminal.writeString("Interrupts enabled: ");
	terminal.writeString((cos::Interrupt::areEnabled() ? "true" : "false"));

	terminal.setColor(cos::vga::Color::Magenta, cos::vga::Color::Black);

	terminal.setPosition(10, 6);
	terminal.writeString("cpu vendor: ");
	terminal.writeString(cos::CpuID::getVendorString());
	
	terminal.setColor(cos::vga::Color::LightGrey, cos::vga::Color::Black);
	
	terminal.setPosition(10, 8);
	terminal.writeString("cpu model: ");
	terminal.writeString(cos::CpuID::getModelString());
	
	terminal.setPosition(0, 10);
	
	// ecx features
	for(cos::uint32 i = 1; ; i <<= 1)
	{
		if(cos::CpuID::hasFeature(static_cast<cos::CpuID::FeatureECX>(i)))
			terminal.putChar('y');
		else
			terminal.putChar('n');
		
		if(i == 1 << 30)
			break;
	}
	
	terminal.setPosition(0, 12);
	
	// edx features
	for(cos::uint32 i = 1; ; i <<= 1)
	{
		if(cos::CpuID::hasFeature(static_cast<cos::CpuID::FeatureECX>(i)))
			terminal.putChar('y');
		else
			terminal.putChar('n');
		 
		 if(i == 1u << 31)
			 break;
	}
}

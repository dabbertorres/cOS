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

NO_NAME_MANGLE
void kernelMain()
{
	cos::vga::Terminal terminal(80, 25);

	terminal.putChar('h');
	terminal.putChar('i');
	terminal.putChar('!');

	terminal.writeString(" Hello world! ");
	
	terminal.setColor(cos::vga::Color::LightGreen, cos::vga::Color::DarkGrey);

	terminal.putChar('s');
	terminal.putChar('o');
	terminal.putChar('?');

	for(int i = 0; i < 100; i++)
	{
		terminal.putChar('.');
	}
}

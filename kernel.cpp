// main file for our kernel

#define NO_NAME_MANGLE extern "C"

/* Check if the compiler thinks if we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
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

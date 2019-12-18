#pragma once
#include <string>
#include <sstream>
#ifdef _WIN32
#include "Windows.h"
#endif

//Debug variables
bool enable_grammar_debug = false;
bool enable_testing = false;
std::stringstream last_calls_stream;
std::stringstream parents_stream;

//Test variables
std::string test_description;

//Text ontrol variables
int scan_lines = 0;
int entry_line = 1;
int scan_position = 0;

void set_console_color(int color)
{
#ifdef _WIN32
	WORD wColor;
	//This handle is needed to get the current background attribute

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//csbi is used for wAttributes word

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//To mask out all but the background attribute, and to add the color
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
#endif
}
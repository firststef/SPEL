#pragma once
#include <string>
#ifdef _WIN32
#include "Windows.h"
#endif

std::string test_description;
int test_state = 0;
int NO_TEST = 0;
int TEST_STARTED = 1;
int TEST_ENDED = 2;

std::string syy_text;
int scan_lines = 1;
int scan_position = 0;
int yycolumn = 0;
bool ended_input = false;

#ifdef _WIN32
void set_console_color(int color)
{
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
}
#endif

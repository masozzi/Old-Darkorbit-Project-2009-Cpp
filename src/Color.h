#ifndef __COLOR_H__
#define __COLOR_H__

#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#endif

enum class EColor
{
#ifdef _WIN32
	BLACK,
	DARKER_BLUE,
	DARK_GREEN,
	DARK_TURQUOISE,
	DARK_RED,
	DARK_PURPLE,
	DARK_YELLOW,
	DEFAULT,
	WHITE = 7,
	GREY,
	DARK_BLUE,
	GREEN,
	LIGHT_BLUE,
	RED,
	PURPLE,
	YELLOW,
	OTHER_WHITE
#endif
#ifdef __linux__
	BLACK = 30,
	DARKER_BLUE = 94,
	DARK_GREEN = 92,
	DARK_TURQUOISE = 96,
	DARK_RED = 91,
	DARK_PURPLE = 95,
	DARK_YELLOW = 93,
	DEFAULT = 39,
	WHITE = 97,
	GREY = 90,
	DARK_BLUE = 34,
	GREEN = 32,
	LIGHT_BLUE = 36,
	RED = 31,
	PURPLE = 35,
	YELLOW = 33,
	OTHER_WHITE = 37
#endif
};

struct _ColorChange
{
	explicit _ColorChange(int color)
	{
#ifdef _WIN32
		SetConsoleTextAttribute(hConsole, color);
#endif
#ifdef __linux__
		std::cout << "\033[" << color << "m";
#endif
	}

#ifdef _WIN32
private:
	static HANDLE hConsole;
#endif
};

#endif

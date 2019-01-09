#include "coutcolor.h"

#ifdef _WIN32
HANDLE _ColorChange::hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
#endif
EColor _lastColor = EColor::DEFAULT;

std::ostream& operator<<(std::ostream& os, const EColor& c)
{
	_ColorChange(static_cast<int>(c));
	_lastColor = c;
	return os;
}

#ifndef __COUTCOLOR_H__
#define __COUTCOLOR_H__
#include <iostream>
#include "Color.h"

std::ostream& operator<<(std::ostream& os, const EColor& c);
template<class El, class Tr>
std::basic_ostream<El, Tr> cendl(std::basic_ostream<El, Tr>&);

#include "coutcolor.tpp"

#endif //__COLOR_H__

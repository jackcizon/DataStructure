#ifndef FTOA_H
#define FTOA_H

#include"heapstring.h"

#define ToStr(s) #s
//if s is char, works well, and if s is digit,
//only works when s is using #define

#define PRECISION 6


HeapStr* _ftoa(double val);

string ToString(char c);

#endif
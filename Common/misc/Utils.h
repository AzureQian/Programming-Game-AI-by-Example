#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cassert>
#include <iomanip>

inline int RandInt(int x, int y)
{
	assert(y >= x && "<RandInt>: y is less than x");
	return rand() % (y - x + 1) + x;
}

inline double RandFloat() { return rand() / (RAND_MAX + 1.0); }

#endif
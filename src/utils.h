#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <string>
#include <cstring>
#include <limits>
#include <ctime>
#include <stddef.h>
#include <sstream>

using namespace std;

void printHeading(string header);

string generatePNR(int n);

string getCurrentDate();


size_t strlcpy(char *dst, const char *src, size_t dstsize = numeric_limits<size_t>::max());

#endif // UTILS_H

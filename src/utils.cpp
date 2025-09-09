#include "utils.h"
#include <iostream>

using namespace std;

void printHeading(string header)
{
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\t\t==========================================================\n";
    cout << "\t\t\t\t\t\t\t\t\t\t                       " << header << "                     \n";
    cout << "\t\t\t\t\t\t\t\t\t\t==========================================================\n\n";
}

string generatePNR(int n)
{
    srand(time(0));
    string pnr;
    int randomNo = rand() % n;
    pnr = "PNR" + to_string(randomNo);
    return pnr;
}

string getCurrentDate()
{
    time_t t = time(NULL);
    struct tm tStruct;
#if defined(_MSC_VER)
    errno_t err = localtime_s(&tStruct, &t);
    if (err != 0) {
        memset(&tStruct, 0, sizeof(tStruct));
    }
#elif defined(__MINGW32__) || defined(__MINGW64__)
    struct tm* tmptr = localtime(&t);
    if (tmptr)
        tStruct = *tmptr;
    else
        memset(&tStruct, 0, sizeof(tStruct));
#else
    localtime_r(&t, &tStruct);
#endif
    ostringstream oss;
    oss << tStruct.tm_mday << "-"
        << (tStruct.tm_mon + 1) << "-"
        << (tStruct.tm_year + 1900);
    return oss.str();
}

size_t strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t srclen = strlen(src);
    size_t copylen = (srclen >= dstsize) ? dstsize - 1 : srclen;
    if (dstsize != 0)
    {
        memcpy(dst, src, copylen);
        dst[copylen] = '\0';
    }
    return srclen;
}

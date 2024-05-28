/*
 * 2012|lloyd|http://wtfpl.org
 */

#include "platformcompat.hh"
#include "util.hh"

#include <sstream>

#include <stdlib.h> // abs()

std::string
mw_util::niceSize(int bytes) 
{
    std::stringstream ss;
    
    if (abs(bytes) > 1024 * 1024) {
        ss << ROUND(bytes / (((double) 1024 * 1024 ) / 100)) / (double) 100 << " mb";
    } else if (abs(bytes) > 1024) {
        ss << ROUND(bytes / (((double) 1024 ) / 100)) / (double) 100 << " kb";
    } else {
        ss << bytes << " bytes";
    }
    
    return ss.str();
}

std::string
mw_util::niceDelta(int seconds) 
{
    std::stringstream ss;

    if (seconds > (60*60)) {
        ss << (seconds / (60*60)) << "h ";
        seconds %= (60*60);
    }

    if (seconds > (60)) {
        ss << (seconds / (60)) << "m ";
        seconds %= (60);
    }
    
    ss << seconds << "s";

    return ss.str();
}

#ifdef _WIN32
void 
mw_util::gettimeofday(timeval* tv, LPVOID ununsed)
{
    if (!tv)
    {
        return;
    }
	
    FILETIME ft;
	unsigned __int64 tmpres = 0;
	static int tzflag;

	GetSystemTimeAsFileTime(&ft);

	tmpres |= ft.dwHighDateTime;
	tmpres <<= 32;
	tmpres |= ft.dwLowDateTime;

	// Convert file time to UNIX epoch
	tmpres -= 116444736000000000ULL;
	// Converting file time to microseconds
	tmpres /= 10;

	// Filling the timeval structure
	tv->tv_sec = (long)(tmpres / 1000000UL);
	tv->tv_usec = (long)(tmpres % 1000000UL);
}
#endif
/*
 * 2012|lloyd|http://wtfpl.org
 */

#include <string>

#ifdef _WIN32
#include <WinSock2.h>
#include <windows.h>
#endif

namespace mw_util {
    // given a size in bytes, return a human readable representation of the
    // string
    std::string niceSize(int bytes);

    // given a delta in seconds, return a human redable representation
    std::string niceDelta(int seconds);

#ifdef _WIN32
    // gettimeofday is not available on windows, so we provide a simple
    // implementation here
    void gettimeofday(timeval* tv, void* unused);
#endif
};



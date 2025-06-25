#ifndef ADL_COMMON_PLATFORM_H
#define ADL_COMMON_PLATFORM_H


#if defined(_WIN32) || defined(_WIN64)
#define ADL_OS_WINDOWS

#elif defined(__APPLE__) && defined(__MACH__)
#define ADL_OS_MACOSX

#elif defined(__linux__)
#define ADL_OS_LINUX

#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
#define ADL_OS_BSD

#elif defined(__unix__)
#define ADL_OS_UNIX_OTHER

#else
#define ADL_OS_UNKNOWN

#endif


#if defined(ADL_OS_MACOSX) || defined(ADL_OS_LINUX) || defined(ADL_OS_BSD) || defined(ADL_OS_UNIX_OTHER)
#define ADL_OS_UNIX
#endif




#endif

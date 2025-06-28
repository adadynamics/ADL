#include "os.h"

#if defined(ADL_OS_UNIX)
ADL_UNIX adl_os;

#elif defined(ADL_OS_WINDOWS)
ADL_WINDOWS adl_os;

#endif


void ADL_SOCKET_WINDOWS_library_init();

void ADL_SOCKET_LINUX_library_init();


/*
void ADL_FILE_LINUX_library_init();

void ADL_FILE_Library_init();
void ADL_PTHREAD_LINUX_library_init();
void ADL_FILE_WINDOWS_library_init();
*/

void ADL_OS_library_init(void)
{
    puts("lib init");
    #if defined(ADL_OS_UNIX)
    ADL_UNIX_Init(&adl_os);
    ADL_SOCKET_LINUX_library_init();
    #elif defined(ADL_OS_WINDOWS)
    ADL_WINDOWS_Init(&adl_os);
    //ADL_FILE_WINDOWS_library_init();
    ADL_SOCKET_WINDOWS_library_init();
    puts("here");
    #endif
/**
    ADL_FILE_LINUX_library_init();
    ADL_FILE_Library_init();
    ADL_PTHREAD_LINUX_library_init();*/
    return;
}

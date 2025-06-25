#include "os.h"

#if defined(ADL_OS_UNIX)
ADL_UNIX adl_os;

#elif defined(ADL_OS_WINDOWS)
ADL_WINDOWS adl_os;

#endif

void ADL_FILE_LINUX_library_init();
void ADL_FILE_Library_init();
void ADL_PTHREAD_LINUX_library_init();

void ADL_OS_library_init(void)
{
    #if defined(ADL_OS_UNIX)
    ADL_UNIX_Init(&adl_os);

    #elif defined(ADL_OS_WINDOWS)
    ADL_WINDOWS_Init(&adl_os);
    #endif

    ADL_FILE_LINUX_library_init();
    ADL_FILE_Library_init();
    ADL_PTHREAD_LINUX_library_init();
    return;
}

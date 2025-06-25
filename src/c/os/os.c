#include "os.h"
ADL_UNIX adl_os;


void ADL_FILE_LINUX_library_init();
void ADL_FILE_Library_init();
void ADL_PTHREAD_LINUX_library_init();

void ADL_OS_library_init(void)
{
    ADL_UNIX_Init(&adl_os);
    ADL_FILE_LINUX_library_init();
    ADL_FILE_Library_init();
    ADL_PTHREAD_LINUX_library_init();
    return;
}

#include "os.h"
ADL_UNIX adl_os;


void ADL_OS_library_init(void)
{
    ADL_UNIX_init(&adl_os);
    return;
}

#include "os.h"
ADL_Unix adl_os;


void ADL_Os_library_init(void)
{
    ADL_Unix_init(&adl_os);
    return;
}

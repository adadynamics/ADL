#ifndef ADL_OS_H
#define ADL_OS_H

#define ADL_OS_UNIX
#if defined(ADL_OS_UNIX)

#include "../include/unix/unix.h"
#include <linux/if.h>


typedef struct iovec ADL_IOVEC;

#ifndef ADL_UNIX_BEGIN
#define ADL_UNIX_BEGIN #ifdef ADL_OS_UNIX
#endif

#ifndef ADL_UNIX_END
#define ADL_UNIX_END #endif
#endif

#else
#if defined(ADL_OS_WINDOWS)

#include "../include/windows/windows.h"

typedef struct ADL_IOVEC
{
	void_ptr base;
	u64 len;
}ADL_IOVEC;

#endif

#endif


typedef struct ADL_Stat
{

}ADL_Stat;



void ADL_Os_library_init();

#endif

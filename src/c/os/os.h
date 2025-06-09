#ifndef ADL_OS_H
#define ADL_OS_H

#define ADL_OS_UNIX
#if defined(ADL_OS_UNIX)

#include "../include/unix/unix.h"


typedef struct iovec ADL_IoVector;

#else
#if defined(ADL_OS_WINDOWS)

#include "../include/windows/windows.h"

typedef struct ADL_IoVector
{
	void_ptr base;
	u64 len;
}ADL_IoVector;

#endif

#endif


typedef struct ADL_Stat
{

}ADL_Stat;



void ADL_Os_library_init();

#endif

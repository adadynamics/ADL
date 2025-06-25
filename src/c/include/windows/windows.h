#ifndef ADL_WINDOWS_WINDOWS_H
#define ADL_WINDOWS_WINDOWS_H

#include "../../include/common/utils.h"
#include "../../include/ds/string.h"



#ifdef ADL_OS_WINDOWS



#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>




typedef struct ADL_WINDOWS
{

}ADL_WINDOWS;


void ADL_WINDOWS_Init(ADL_WINDOWS *class);

void ADL_WINDOWS_Fini(ADL_WINDOWS *class);


#endif


#endif

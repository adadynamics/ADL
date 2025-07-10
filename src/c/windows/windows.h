#ifndef ADL_SRC_WINDOWS_WINDOWS_H
#define ADL_SRC_WINDOWS_WINDOWS_H

#include "../include/windows/windows.h"

#ifdef ADL_OS_WINDOWS


#ifndef ADL_WINDOWS_INIT
#define ADL_WINDOWS_INIT(val,valptr)    ADL_S64_INIT(val);  \
                                        ADL_VOID_PTR_INIT(valptr); \
                                        ADL_ERRNO_INIT();   \
                                        ADL_RESULT_RETURN_DEFER_INIT();
#endif




#ifndef ADL_WINDOWS_FINI
#define ADL_WINDOWS_FINI(val,valptr)    if(ADL_CHECK_EQUAL(val,-1))                                                                                 \
                                        {                                                                                                           \
                                            ADL_STRING str;                                                                                         \
                                            ADL_STRING_Init(&str,ADL_STRERROR(errno));                                                              \
                                            ADL_RESULT_RETURN_DEFER(failed_syscall, ADL_RESULT_WRITE(errno,val,str,valptr));                        \
                                        }                                                                                                           \
                                                                                                                                                    \
                                        ADL_RESULT_RETURN_DEFER(success_syscall,ADL_RESULT_WRITE(errno,val,(ADL_STRING){},valptr));                 \
                                                                                                                                                    \
                                        failed_syscall:                                                                                             \
                                        success_syscall:                                                                                            \
                                            ADL_RESULT_RETURN_DEFER_FINI()                                

#endif



#ifndef ADL_WINDOWS_SOCKET_INIT
#define ADL_WINDOWS_SOCKET_INIT(val,valptr) ADL_SOCKET_DESC  val = (ADL_SOCKET_DESC)0;  \
                                   ADL_VOID_PTR_INIT(valptr); \
                                   ADL_ERRNO_INIT();   \
                                   ADL_RESULT_RETURN_DEFER_INIT();
#endif



#ifndef ADL_WINDOWS_SOCKET_FINI
#define ADL_WINDOWS_SOCKET_FINI(val,valptr)  if(ADL_CHECK_EQUAL(val,ADL_INVALID_SOCKET))                                                  \
                            {                                                                                   \
                                ADL_STRING str;                                                                 \
                                ADL_STRING_Init(&str,ADL_STRERROR(ADL_SOCKET_ERRNO));                                      \
                                ADL_RESULT_RETURN_DEFER(failed_syscall, ADL_RESULT_WRITE(ADL_SOCKET_ERRNO,val,str,valptr));      \
                            }                                                                                   \
                                                                                                                \
                            ADL_RESULT_RETURN_DEFER(success_syscall,ADL_RESULT_WRITE(ADL_SOCKET_ERRNO,val,(ADL_STRING){},valptr));  \
                                               \
                            failed_syscall:    \
                            success_syscall:   \
                                ADL_RESULT_RETURN_DEFER_FINI()                                

#endif





#define __BOOL__
#define __HANDLE__
#define __DWORD__
#define __LPVOID__
#define __UINT__
#define __VOID__
#define __HRESULT__





#endif

#endif


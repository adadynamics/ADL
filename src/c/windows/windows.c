#include "../include/windows/windows.h"

#define ADL_OS_WINDOWS
#ifdef ADL_OS_WINDOWS

#include <windows.h>
#include <winuser.h>
#include <winsock2.h>






ADL_Result adl_sys_ReadFile(HANDLE handle,void_ptr buf,u32 size,u32_ptr numread,void_ptr junk)
{
    BOOL status = ReadFile(handle,buf,size,numread,junk);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        ADL_RESULT_RETURN_DEFER(failed_syscall,ADL_RESULT_WRITE(-1,(ADL_String){},NULL));
    }

    ADL_RESULT_RETURN_DEFER(success_syscall,ADL_RESULT_WRITE(0,(ADL_String){},NULL));

failed_syscall:
success_syscall:
    ADL_RESULT_RETURN_DEFER_FINI();
}




















#endif

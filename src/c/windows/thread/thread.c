#include "thread.h"


#ifdef ADL_OS_WINDOWS



ADL_RESULT adl_lib_CreateThread(LPSECURITY_ATTRIBUTES sa,SIZE_T stack_size,LPTHREAD_START_ROUTINE subroutine,LPVOID args,DWORD flags,LPDWORD thread_id) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HANDLE handle = ADL_CREATETHREAD(sa,stack_size,subroutine,args,flags,thread_id);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_OpenThread(DWORD access,BOOL inherit,DWORD thread_id) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HANDLE handle = ADL_OPENTHREAD(access,inherit,thread_id);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_ExitThread(DWORD code) __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_EXITTHREAD(code);
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_TerminateThread(HANDLE handle,DWORD code) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_TERMINATETHREAD(handle,code);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_GetExitCodeThread(HANDLE handle,LPDWORD code) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_GETEXITCODETHREAD(handle,code);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_ResumeThread(HANDLE handle) __DWORD__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    DWORD status = ADL_RESUMETHREAD(handle);
    rdr_ret = status;

    /*
    if(ADL_CHECK_EQUAL(status,-1))
    {
        rdr_ret = -1;
    }*/

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_SuspendThread(HANDLE handle) __DWORD__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    DWORD status = ADL_SUSPENDTHREAD(handle);
    rdr_ret = status;

    /*
    if(ADL_CHECK_EQUAL(status,-1))
    {
        rdr_ret = -1;
    }*/

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}

/*
    CALL LocalFree TO FREE THE MEMORYALLOCATED TO description
*/
/*
ADL_RESULT adl_lib_GetThreadDescription(HANDLE handle,PCSTR *description) __HRESULT__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HRESULT hresult = ADL_GETTHREADDESCRIPTION(handle,description);

    if(ADL_CHECK_NOT_EQUAL(hresult,S_OK(0)))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_SetThreadDescription(HANDLE handle,PCSTR description) __HRESULT__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HRESULT hresult = ADL_SETTHREADDESCRIPTION(handle,description);

    if(ADL_CHECK_NOT_EQUAL(hresult,S_OK(0)))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}

*/

ADL_RESULT adl_lib_GetThreadTimes(HANDLE handle,LPFILETIME creation,LPFILETIME exit,LPFILETIME kernel,LPFILETIME user) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_GETTHREADTIMES(handle,creation,exit,kernel,user);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_GetPriorityClass(HANDLE handle) __DWORD__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    DWORD status = ADL_GETPRIORITYCLASS(handle);
    rdr_ret = status;

    if(ADL_CHECK_EQUAL(status,0))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_SetPriorityClass(HANDLE handle,DWORD class) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_SETPRIORITYCLASS(handle,class);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_SetThreadPriority(HANDLE handle,int priority) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_SETTHREADPRIORITY(handle,priority);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_InitializeCriticalSection(LPCRITICAL_SECTION cs) __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_INITIALIZECRITICALSECTION(cs);
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_InitializeCriticalSectionEx(LPCRITICAL_SECTION cs,DWORD spin_count,DWORD flags) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_INITIALIZECRITICALSECTIONEX(cs,spin_count,flags);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION cs,DWORD spin_count) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_INITIALIZECRITICALSECTIONANDSPINCOUNT(cs,spin_count);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_DeleteCriticalSection(LPCRITICAL_SECTION cs) __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_DELETECRITICALSECTION(cs);
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_EnterCriticalSection(LPCRITICAL_SECTION cs) __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_ENTERCRITICALSECTION(cs);
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_TryEnterCriticalSection(LPCRITICAL_SECTION cs) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_TRYENTERCRITICALSECTION(cs);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_LeaveCriticalSection(LPCRITICAL_SECTION cs) __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_LEAVECRITICALSECTION(cs);
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_CreateMutex(LPSECURITY_ATTRIBUTES sa,BOOL owner,LPCTSTR name) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HANDLE handle = ADL_CREATEMUTEX(sa,owner,name);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_CreateMutexEx(LPSECURITY_ATTRIBUTES sa,LPCTSTR name,DWORD flags,DWORD access) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HANDLE handle = ADL_CREATEMUTEXEX(sa,name,flags,access);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_OpenMutex(DWORD access,BOOL inherit,LPCTSTR name) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HANDLE handle = ADL_OPENMUTEX(access,inherit,name);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_WaitForSingleObject(HANDLE handle,DWORD milli) __DWORD__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    DWORD status = ADL_WAITFORSINGLEOBJECT(handle,milli);
    rdr_ret = status;

    if(ADL_CHECK_EQUAL(status,WAIT_FAILED))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_ReleaseMutex(HANDLE handle) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_RELEASEMUTEX(handle);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_CreateSemaphore(LPSECURITY_ATTRIBUTES sa,LONG count,LONG max_count,LPCTSTR name) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HANDLE handle = ADL_CREATESEMAPHORE(sa,count,max_count,name);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_CreateSemaphoreEx(LPSECURITY_ATTRIBUTES sa,LONG count,LONG max_count,LPCTSTR name,DWORD flags,DWORD access) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HANDLE handle = ADL_CREATESEMAPHOREEX(sa,count,max_count,name,flags,access);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_OpenSemaphore(DWORD access,DWORD inherit,LPCTSTR name) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HANDLE handle = ADL_OPENSEMAPHORE(access,inherit,name);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_ReleaseSemaphore(HANDLE handle,LONG count,LPLONG prev_count) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_RELEASESEMAPHORE(handle,count,prev_count);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_CreateEvent(LPSECURITY_ATTRIBUTES sa,BOOL manual_reset,BOOL initial_state,LPCTSTR name) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HANDLE handle = ADL_CREATEEVENT(sa,manual_reset,initial_state,name);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_CreateEventEx(LPSECURITY_ATTRIBUTES sa,LPCTSTR name,DWORD flags,DWORD access) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);HANDLE handle = ADL_CREATEEVENTEX(sa,name,flags,access);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }
    
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_OpenEvent(DWORD access,DWORD inherit,LPCTSTR name) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    HANDLE handle = ADL_OPENEVENT(access,inherit,name);
    rdr_retptr = (void_ptr)handle;

    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_SetEvent(HANDLE handle) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_SETEVENT(handle);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_ResetEvent(HANDLE handle) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_RESETEVENT(handle);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_PulseEvent(HANDLE handle) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_PULSEEVENT(handle);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_InitializeConditionVariable(PCONDITION_VARIABLE cv) __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_INITIALIZECONDITIONVARIABLE(cv);
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_SleepConditionVariableCS(PCONDITION_VARIABLE cv, PCRITICAL_SECTION cs, DWORD milli) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    BOOL status = ADL_SLEEPCONDITIONVARIABLECS(cv,cs,milli);

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_WakeConditionVariable(PCONDITION_VARIABLE cv) __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_WAKECONDITIONVARIABLE(cv);
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_WakeAllConditionVariable(PCONDITION_VARIABLE cv) __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_WAKEALLCONDITIONVARIABLE(cv);
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}

#endif
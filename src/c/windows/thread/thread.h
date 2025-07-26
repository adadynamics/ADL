#ifndef ADL_SRC_WINDOWS_THREAD_THREAD_H
#define ADL_SRC_WINDOWS_THREAD_THREAD_H


#include "../windows.h"


#ifdef ADL_OS_WINDOWS




#ifndef ADL_CREATETHREAD
#define ADL_CREATETHREAD CreateThread
#endif

#ifndef ADL_OPENTHREAD
#define ADL_OPENTHREAD OpenThread
#endif

#ifndef ADL_EXITTHREAD
#define ADL_EXITTHREAD ExitThread
#endif

#ifndef ADL_TERMINATETHREAD
#define ADL_TERMINATETHREAD TerminateThread
#endif

#ifndef ADL_GETEXITCODETHREAD
#define ADL_GETEXITCODETHREAD GetExitCodeThread
#endif

#ifndef ADL_RESUMETHREAD
#define ADL_RESUMETHREAD ResumeThread
#endif

#ifndef ADL_SUSPENDTHREAD
#define ADL_SUSPENDTHREAD SuspendThread
#endif






#ifndef ADL_GETTHREADDESCRIPTION
#define ADL_GETTHREADDESCRIPTION GetThreadDescription
#endif

#ifndef ADL_SETTHREADDESCRIPTION
#define ADL_SETTHREADDESCRIPTION SetThreadDescription
#endif

#ifndef ADL_GETTHREADTIMES
#define ADL_GETTHREADTIMES GetThreadTimes
#endif

#ifndef ADL_GETPRIORITYCLASS
#define ADL_GETPRIORITYCLASS GetPriorityClass
#endif

#ifndef ADL_SETPRIORITYCLASS
#define ADL_SETPRIORITYCLASS SetPriorityClass
#endif

#ifndef ADL_SETTHREADPRIORITY
#define ADL_SETTHREADPRIORITY SetThreadPriority
#endif






/*

    SYNCHRONIZATION OBJECTS

*/




#ifndef ADL_INITIALIZECRITICALSECTION
#define ADL_INITIALIZECRITICALSECTION InitializeCriticalSection
#endif

#ifndef ADL_INITIALIZECRITICALSECTIONEX
#define ADL_INITIALIZECRITICALSECTIONEX InitializeCriticalSectionEx
#endif

#ifndef ADL_INITIALIZECRITICALSECTIONANDSPINCOUNT
#define ADL_INITIALIZECRITICALSECTIONANDSPINCOUNT InitializeCriticalSectionAndSpinCount
#endif

#ifndef ADL_DELETECRITICALSECTION
#define ADL_DELETECRITICALSECTION DeleteCriticalSection
#endif

#ifndef ADL_ENTERCRITICALSECTION
#define ADL_ENTERCRITICALSECTION EnterCriticalSection
#endif

#ifndef ADL_TRYENTERCRITICALSECTION
#define ADL_TRYENTERCRITICALSECTION TryEnterCriticalSection
#endif


#ifndef ADL_LEAVECRITICALSECTION
#define ADL_LEAVECRITICALSECTION LeaveCriticalSection
#endif




#ifndef ADL_CREATEMUTEX
#define ADL_CREATEMUTEX CreateMutex
#endif

#ifndef ADL_CREATEMUTEXEX
#define ADL_CREATEMUTEXEX CreateMutexEx
#endif

#ifndef ADL_OPENMUTEX
#define ADL_OPENMUTEX OpenMutex
#endif

#ifndef ADL_WAITFORSINGLEOBJECT
#define ADL_WAITFORSINGLEOBJECT WaitForSingleObject
#endif


#ifndef ADL_RELEASEMUTEX
#define ADL_RELEASEMUTEX ReleaseMutex
#endif



#ifndef ADL_CREATESEMAPHORE
#define ADL_CREATESEMAPHORE CreateSemaphore
#endif


#ifndef ADL_CREATESEMAPHOREEX
#define ADL_CREATESEMAPHOREEX CreateSemaphoreEx
#endif

#ifndef ADL_OPENSEMAPHORE
#define ADL_OPENSEMAPHORE OpenSemaphore
#endif


#ifndef ADL_RELEASESEMAPHORE
#define ADL_RELEASESEMAPHORE ReleaseSemaphore
#endif




#ifndef ADL_CREATEEVENT
#define ADL_CREATEEVENT CreateEvent
#endif

#ifndef ADL_CREATEEVENTEX
#define ADL_CREATEEVENTEX CreateEventEx
#endif

#ifndef ADL_OPENEVENT
#define ADL_OPENEVENT OpenEvent
#endif

#ifndef ADL_SETEVENT
#define ADL_SETEVENT SetEvent
#endif


#ifndef ADL_RESETEVENT
#define ADL_RESETEVENT ResetEvent
#endif

#ifndef ADL_PULSEEVENT
#define ADL_PULSEEVENT PulseEvent
#endif



#ifndef ADL_INITIALIZECONDITIONVARIABLE
#define ADL_INITIALIZECONDITIONVARIABLE InitializeConditionVariable
#endif

#ifndef ADL_SLEEPCONDITIONVARIABLECS
#define ADL_SLEEPCONDITIONVARIABLECS SleepConditionVariableCS
#endif

#ifndef ADL_WAKECONDITIONVARIABLE
#define ADL_WAKECONDITIONVARIABLE WakeConditionVariable
#endif

#ifndef ADL_WAKEALLCONDITIONVARIABLE
#define ADL_WAKEALLCONDITIONVARIABLE WakeAllConditionVariable
#endif








ADL_RESULT adl_lib_CreateThread(LPSECURITY_ATTRIBUTES sa,SIZE_T stack_size,LPTHREAD_START_ROUTINE subroutine,LPVOID args,DWORD flags,LPDWORD thread_id);
ADL_RESULT adl_lib_OpenThread(DWORD access,BOOL inherit,DWORD thread_id);
ADL_RESULT adl_lib_ExitThread(DWORD code);
ADL_RESULT adl_lib_TerminateThread(HANDLE handle,DWORD code);
ADL_RESULT adl_lib_GetExitCodeThread(HANDLE handle,LPDWORD code);
ADL_RESULT adl_lib_ResumeThread(HANDLE handle);
ADL_RESULT adl_lib_SuspendThread(HANDLE handle);
ADL_RESULT adl_lib_GetThreadDescription(HANDLE handle,PCSTR *description);
ADL_RESULT adl_lib_SetThreadDescription(HANDLE handle,PCSTR description);
ADL_RESULT adl_lib_GetThreadTimes(HANDLE handle,LPFILETIME creation,LPFILETIME exit,LPFILETIME kernel,LPFILETIME user);
ADL_RESULT adl_lib_GetPriorityClass(HANDLE handle);
ADL_RESULT adl_lib_SetPriorityClass(HANDLE handle,DWORD class);
ADL_RESULT adl_lib_SetThreadPriority(HANDLE handle,int priority);
ADL_RESULT adl_lib_InitializeCriticalSection(LPCRITICAL_SECTION cs);
ADL_RESULT adl_lib_InitializeCriticalSectionEx(LPCRITICAL_SECTION cs,DWORD spin_count,DWORD flags);
ADL_RESULT adl_lib_InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION cs,DWORD spin_count);
ADL_RESULT adl_lib_DeleteCriticalSection(LPCRITICAL_SECTION cs);
ADL_RESULT adl_lib_EnterCriticalSection(LPCRITICAL_SECTION cs);
ADL_RESULT adl_lib_TryEnterCriticalSection(LPCRITICAL_SECTION cs);
ADL_RESULT adl_lib_LeaveCriticalSection(LPCRITICAL_SECTION cs);
ADL_RESULT adl_lib_CreateMutex(LPSECURITY_ATTRIBUTES sa,BOOL owner,LPCTSTR name);
ADL_RESULT adl_lib_CreateMutexEx(LPSECURITY_ATTRIBUTES sa,LPCTSTR name,DWORD flags,DWORD access);
ADL_RESULT adl_lib_OpenMutex(DWORD access,BOOL inherit,LPCTSTR name);
ADL_RESULT adl_lib_WaitForSingleObject(HANDLE handle,DWORD milli);
ADL_RESULT adl_lib_ReleaseMutex(HANDLE handle);
ADL_RESULT adl_lib_CreateSemaphore(LPSECURITY_ATTRIBUTES sa,LONG count,LONG max_count,LPCTSTR name);
ADL_RESULT adl_lib_CreateSemaphoreEx(LPSECURITY_ATTRIBUTES sa,LONG count,LONG max_count,LPCTSTR name,DWORD flags,DWORD access);
ADL_RESULT adl_lib_OpenSemaphore(DWORD access,DWORD inherit,LPCTSTR name);
ADL_RESULT adl_lib_ReleaseSemaphore(HANDLE handle,LONG count,LPLONG prev_count);
ADL_RESULT adl_lib_CreateEvent(LPSECURITY_ATTRIBUTES sa,BOOL manual_reset,BOOL initial_state,LPCTSTR name);
ADL_RESULT adl_lib_CreateEventEx(LPSECURITY_ATTRIBUTES sa,LPCTSTR name,DWORD flags,DWORD access);
ADL_RESULT adl_lib_OpenEvent(DWORD access,DWORD inherit,LPCTSTR name);
ADL_RESULT adl_lib_SetEvent(HANDLE handle);
ADL_RESULT adl_lib_ResetEvent(HANDLE handle);
ADL_RESULT adl_lib_PulseEvent(HANDLE handle);
ADL_RESULT adl_lib_InitializeConditionVariable(PCONDITION_VARIABLE cv);
ADL_RESULT adl_lib_SleepConditionVariableCS(PCONDITION_VARIABLE cv, PCRITICAL_SECTION cs, DWORD milli);
ADL_RESULT adl_lib_WakeConditionVariable(PCONDITION_VARIABLE cv);
ADL_RESULT adl_lib_WakeAllConditionVariable(PCONDITION_VARIABLE cv);

#endif


#endif
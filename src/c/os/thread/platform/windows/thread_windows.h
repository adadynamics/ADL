#ifndef ADL_SRC_OS_THREAD_PLATFORM_WINDOWS_THREAD_WINDOWS_H
#define ADL_SRC_OS_THREAD_PLATFORM_WINDOWS_THREAD_WINDOWS_H

#include "../../../os.h"


#ifdef ADL_OS_WINDOWS


typedef struct ADL_THREAD_WINDOWS
{
    ADL_RESULT (*CreateThread)(LPSECURITY_ATTRIBUTES sa,SIZE_T stack_size,LPTHREAD_START_ROUTINE subroutine,LPVOID args,DWORD flags,LPDWORD thread_id);
    ADL_RESULT (*OpenThread)(DWORD access,BOOL inherit,DWORD thread_id);
    ADL_RESULT (*ExitThread)(DWORD code);
    ADL_RESULT (*TerminateThread)(HANDLE handle,DWORD code);
    ADL_RESULT (*GetExitCodeThread)(HANDLE handle,LPDWORD code);
    ADL_RESULT (*ResumeThread)(HANDLE handle);
    ADL_RESULT (*SuspendThread)(HANDLE handle);
    ADL_RESULT (*GetThreadDescription)(HANDLE handle,PCSTR *description);
    ADL_RESULT (*SetThreadDescription)(HANDLE handle,PCSTR description);
    ADL_RESULT (*GetThreadTimes)(HANDLE handle,LPFILETIME creation,LPFILETIME exit,LPFILETIME kernel,LPFILETIME user);
    ADL_RESULT (*GetPriorityClass)(HANDLE handle);
    ADL_RESULT (*SetPriorityClass)(HANDLE handle,DWORD class);
    ADL_RESULT (*SetThreadPriority)(HANDLE handle,int priority);
    ADL_RESULT (*InitializeCriticalSection)(LPCRITICAL_SECTION cs);
    ADL_RESULT (*InitializeCriticalSectionEx)(LPCRITICAL_SECTION cs,DWORD spin_count,DWORD flags);
    ADL_RESULT (*InitializeCriticalSectionAndSpinCount)(LPCRITICAL_SECTION cs,DWORD spin_count);
    ADL_RESULT (*DeleteCriticalSection)(LPCRITICAL_SECTION cs);
    ADL_RESULT (*EnterCriticalSection)(LPCRITICAL_SECTION cs);
    ADL_RESULT (*TryEnterCriticalSection)(LPCRITICAL_SECTION cs);
    ADL_RESULT (*LeaveCriticalSection)(LPCRITICAL_SECTION cs);
    ADL_RESULT (*CreateMutex)(LPSECURITY_ATTRIBUTES sa,BOOL owner,LPCTSTR name);
    ADL_RESULT (*CreateMutexEx)(LPSECURITY_ATTRIBUTES sa,LPCTSTR name,DWORD flags,DWORD access);
    ADL_RESULT (*OpenMutex)(DWORD access,BOOL inherit,LPCTSTR name);
    ADL_RESULT (*WaitForSingleObject)(HANDLE handle,DWORD milli);
    ADL_RESULT (*ReleaseMutex)(HANDLE handle);
    ADL_RESULT (*CreateSemaphore)(LPSECURITY_ATTRIBUTES sa,LONG count,LONG max_count,LPCTSTR name);
    ADL_RESULT (*CreateSemaphoreEx)(LPSECURITY_ATTRIBUTES sa,LONG count,LONG max_count,LPCTSTR name,DWORD flags,DWORD access);
    ADL_RESULT (*OpenSemaphore)(DWORD access,DWORD inherit,LPCTSTR name);
    ADL_RESULT (*ReleaseSemaphore)(HANDLE handle,LONG count,LPLONG prev_count);
    ADL_RESULT (*CreateEvent)(LPSECURITY_ATTRIBUTES sa,BOOL manual_reset,BOOL initial_state,LPCTSTR name);
    ADL_RESULT (*CreateEventEx)(LPSECURITY_ATTRIBUTES sa,LPCTSTR name,DWORD flags,DWORD access);
    ADL_RESULT (*OpenEvent)(DWORD access,DWORD inherit,LPCTSTR name);
    ADL_RESULT (*SetEvent)(HANDLE handle);
    ADL_RESULT (*ResetEvent)(HANDLE handle);
    ADL_RESULT (*PulseEvent)(HANDLE handle);
}ADL_THREAD_WINDOWS;


void ADL_THREAD_WINDOWS_Init(ADL_THREAD_WINDOWS *class);

void ADL_THREAD_WINDOWS_Fini(ADL_THREAD_WINDOWS *class);

#endif

#endif
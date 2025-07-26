#include "thread_windows.h"


#ifdef ADL_OS_WINDOWS


extern ADL_WINDOWS adl_os;

void ADL_THREAD_WINDOWS_Init(ADL_THREAD_WINDOWS *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class->CreateThread                                              = adl_os.CreateThread;
    class->OpenThread                                                = adl_os.OpenThread;
    class->ExitThread                                                = adl_os.ExitThread;
    class->TerminateThread                                           = adl_os.TerminateThread;
    class->GetExitCodeThread                                         = adl_os.GetExitCodeThread;
    class->ResumeThread                                              = adl_os.ResumeThread;
    class->SuspendThread                                             = adl_os.SuspendThread;
    
    /*
    class->GetThreadDescription                                      = adl_os.GetThreadDescription;
    class->SetThreadDescription                                      = adl_os.SetThreadDescription;
    */
    
    class->GetThreadTimes                                            = adl_os.GetThreadTimes;
    class->GetPriorityClass                                          = adl_os.GetPriorityClass;
    class->SetPriorityClass                                          = adl_os.SetPriorityClass;
    class->SetThreadPriority                                         = adl_os.SetThreadPriority;
    class->InitializeCriticalSection                                 = adl_os.InitializeCriticalSection;
    class->InitializeCriticalSectionEx                               = adl_os.InitializeCriticalSectionEx;
    class->InitializeCriticalSectionAndSpinCount                     = adl_os.InitializeCriticalSectionAndSpinCount;
    class->DeleteCriticalSection                                     = adl_os.DeleteCriticalSection;
    class->EnterCriticalSection                                      = adl_os.EnterCriticalSection;
    class->TryEnterCriticalSection                                   = adl_os.TryEnterCriticalSection;
    class->LeaveCriticalSection                                      = adl_os.LeaveCriticalSection;
    class->CreateMutex                                               = adl_os.CreateMutex;
    class->CreateMutexEx                                             = adl_os.CreateMutexEx;
    class->OpenMutex                                                 = adl_os.OpenMutex;
    class->WaitForSingleObject                                       = adl_os.WaitForSingleObject;
    class->ReleaseMutex                                              = adl_os.ReleaseMutex;
    class->CreateSemaphore                                           = adl_os.CreateSemaphore;
    class->CreateSemaphoreEx                                         = adl_os.CreateSemaphoreEx;
    class->OpenSemaphore                                             = adl_os.OpenSemaphore;
    class->ReleaseSemaphore                                          = adl_os.ReleaseSemaphore;
    class->CreateEvent                                               = adl_os.CreateEvent;
    class->CreateEventEx                                             = adl_os.CreateEventEx;
    class->OpenEvent                                                 = adl_os.OpenEvent;
    class->SetEvent                                                  = adl_os.SetEvent;
    class->ResetEvent                                                = adl_os.ResetEvent;
    class->PulseEvent                                                = adl_os.PulseEvent;
    class->InitializeConditionVariable                               = adl_os.InitializeConditionVariable;
    class->SleepConditionVariableCS                                  = adl_os.SleepConditionVariableCS;
    class->WakeConditionVariable                                     = adl_os.WakeConditionVariable;
    class->WakeAllConditionVariable                                  = adl_os.WakeAllConditionVariable;

null_class:
    return;
}

void ADL_THREAD_WINDOWS_Fini(ADL_THREAD_WINDOWS *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_THREAD_WINDOWS));

null_class:
    return;
}

ADL_THREAD_WINDOWS thread_windows;

void ADL_THREAD_WINDOWS_library_init()
{
    ADL_THREAD_WINDOWS_Init(&thread_windows);
}

#endif
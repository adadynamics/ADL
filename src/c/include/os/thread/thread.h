#ifndef ADL_OS_THREAD_THREAD_H
#define ADL_OS_THREAD_THREAD_H


#include "../os.h"



typedef struct ADL_THREAD_ID
{
#if defined(ADL_OS_UNIX)
    pthread_t tid;
#elif defined(ADL_OS_WINDOWS)
    DWORD tid;
    HANDLE handle;
#endif
}ADL_THREAD_ID;


#if defined(ADL_OS_UNIX)
typedef void *(*ADL_THREAD_ROUTINE)(void *);
#elif defined(ADL_OS_WINDOWS)
typedef LPTHREAD_START_ROUTINE ADL_THREAD_ROUTINE;
#endif


#ifdef ADL_OS_UNIX
#define ADL_THREAD_RETURN_PARAM void *
#elif defined(ADL_OS_WINDOWS)
#define ADL_THREAD_RETURN_PARAM DWORD __attribute__((stdcall))
#endif

#ifdef ADL_OS_UNIX
#define ADL_THREAD_RETURN(arg) return arg
#elif defined(ADL_OS_WINDOWS)
#define ADL_THREAD_RETURN(arg) return (DWORD)arg
#endif

typedef struct ADL_THREAD
{
    ADL_THREAD_ID id;
    s64 exit_code;
    ADL_RESULT (*Start)(struct ADL_THREAD *self,ADL_THREAD_ROUTINE,void *arg);
    ADL_RESULT (*Detach)(struct ADL_THREAD *self);
    ADL_RESULT (*Join)(struct ADL_THREAD *self,void **retval);
    ADL_RESULT (*Exit)(struct ADL_THREAD *self,void *status);
    ADL_RESULT (*GetName)(struct ADL_THREAD *self);
    ADL_RESULT (*SetName)(struct ADL_THREAD *self,ADL_STRING name);
    ADL_RESULT (*GetId)(struct ADL_THREAD *self);
    ADL_RESULT (*IsAlive)(struct ADL_THREAD *self);
}ADL_THREAD;



void ADL_THREAD_Init(ADL_THREAD *thread);

void ADL_THREAD_Fini(ADL_THREAD *thread);



#endif
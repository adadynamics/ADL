#include "spinlock.h"

#if defined(ADL_OS_UNIX)
extern ADL_PTHREAD_LINUX pthread_linux;
#elif defined(ADL_OS_WINDOWS)
extern ADL_THREAD_WINDOWS thread_windows;
#endif


ADL_RESULT Acquire(struct ADL_SPINLOCK *self,bool blocking)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    switch(blocking)
    {
        case true:
        {
            rdr_res = pthread_linux.pthread_spin_lock(&self->lock);
            break;
        }
        case false:
        {
            rdr_res = pthread_linux.pthread_spin_trylock(&self->lock);
            break;
        }
    }

#elif defined(ADL_OS_WINDOWS)
    switch(blocking)
    {
        case true:
        {
            rdr_res = thread_windows.EnterCriticalSection(&self->lock);
            break;
        }
        case false:
        {
            rdr_res = thread_windows.TryEnterCriticalSection(&self->lock);
            break;
        }
    }
#endif

null_self:
    return rdr_res;
}


ADL_RESULT Release(struct ADL_SPINLOCK *self)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_spin_unlock(&self->lock);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.LeaveCriticalSection(&self->lock);
#endif

null_self:
    return rdr_res;
}



ADL_RESULT ADL_SPINLOCK_Init(ADL_SPINLOCK *class)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_spin_init(&class->lock,PTHREAD_PROCESS_PRIVATE);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.InitializeCriticalSection(&class->lock);
#endif
    class->Acquire         = Acquire;
    class->Release         = Release;

null_class:
    return rdr_res;
}

ADL_RESULT ADL_SPINLOCK_Fini(ADL_SPINLOCK *class)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_spin_destroy(&class->lock);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.DeleteCriticalSection(&class->lock);
#endif

    ADL_MEMSET(class,0,sizeof(ADL_SPINLOCK));

null_class:
    return rdr_res;
}
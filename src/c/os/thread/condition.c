#include "condition.h"

#if defined(ADL_OS_UNIX)
extern ADL_PTHREAD_LINUX pthread_linux;
#elif defined(ADL_OS_WINDOWS)
extern ADL_THREAD_WINDOWS thread_windows;
#endif


ADL_RESULT Acquire(struct ADL_CONDITION *self)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)

    rdr_res = pthread_linux.pthread_mutex_lock(&self->lock);

    if(ADL_CHECK_EQUAL(ADL_RESULT_READ_ERRNO(rdr_res),EOWNERDEAD))
    {
        pthread_linux.pthread_mutex_consistent(&self->lock);
    }

#elif defined(ADL_OS_WINDOWS)

    rdr_res = thread_windows.EnterCriticalSection(&self->lock);

#endif

null_self:
    return rdr_res;
}


ADL_RESULT Release(struct ADL_CONDITION *self)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_mutex_unlock(&self->lock);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.LeaveCriticalSection(&self->lock);
#endif

null_self:
    return rdr_res;
}




ADL_RESULT Wait(struct ADL_CONDITION *self)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_cond_wait(&self->condition,&self->lock);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.SleepConditionVariableCS(&self->condition,&self->lock,INFINITE);
#endif

null_self:
    return rdr_res;
}


ADL_RESULT TimedWait(struct ADL_CONDITION *self,u32 milliseconds)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += milliseconds / 1000;
    ts.tv_nsec += (milliseconds % 1000) * 1000000;
    if (ts.tv_nsec >= 1000000000) {
        ts.tv_sec += 1;
        ts.tv_nsec -= 1000000000;
    }

    rdr_res = pthread_linux.pthread_cond_timedwait(&self->condition,&self->lock,&ts);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.SleepConditionVariableCS(&self->condition,&self->lock,milliseconds);
#endif

null_self:
    return rdr_res;
}


ADL_RESULT Notify(struct ADL_CONDITION *self)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_cond_signal(&self->condition);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.WakeConditionVariable(&self->condition);
#endif

null_self:
    return rdr_res;
}



ADL_RESULT NotifyAll(struct ADL_CONDITION *self)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_cond_broadcast(&self->condition);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.WakeAllConditionVariable(&self->condition);
#endif

null_self:
    return rdr_res;
}



ADL_RESULT ADL_CONDITION_Init(ADL_CONDITION *class)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_cond_init(&class->condition,NULL);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(null_class);
    }

    rdr_res = pthread_linux.pthread_mutex_init(&class->lock,NULL);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        pthread_linux.pthread_cond_destroy(&class->condition);
        ADL_RETURN_DEFER(null_class);
    }

#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.InitializeConditionVariable(&class->condition);

    rdr_res = thread_windows.InitializeCriticalSection(&class->lock);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(null_class);
    }


#endif
    class->Acquire         = Acquire;
    class->Release         = Release;

null_class:
    return rdr_res;
}

ADL_RESULT ADL_CONDITION_Fini(ADL_CONDITION *class)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

#if defined(ADL_OS_UNIX)
    pthread_linux.pthread_cond_destroy(&class->condition);
    rdr_res = pthread_linux.pthread_mutex_destroy(&class->lock);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.DeleteCriticalSection(&class->lock);
#endif

    ADL_MEMSET(class,0,sizeof(ADL_CONDITION));

null_class:
    return rdr_res;
}
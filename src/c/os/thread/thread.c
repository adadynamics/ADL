#include "thread.h"


#if defined(ADL_OS_UNIX)
extern ADL_PTHREAD_LINUX pthread_linux;
#elif defined(ADL_OS_WINDOWS)
extern ADL_THREAD_WINDOWS thread_windows;
#endif

ADL_RESULT Start(ADL_THREAD *self,ADL_THREAD_ROUTINE start_routine,void *arg)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_create(&self->id.tid,NULL,(ADL_THREAD_ROUTINE)start_routine,arg);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.CreateThread(NULL,0,(ADL_THREAD_ROUTINE)start_routine,arg,0,&self->id.tid);
    self->id.handle = rdr_res.ptr;
#endif

null_self:
    return rdr_res;
}


ADL_RESULT Detach(ADL_THREAD *self)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_detach(self->id.tid);
#elif defined(ADL_OS_WINDOWS)

#endif

null_self:
    return rdr_res;
}


ADL_RESULT Join(ADL_THREAD *self,void **retval)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_join(self->id.tid,retval);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.WaitForSingleObject(self->id.handle,INFINITE);
#endif

null_self:
    return rdr_res;
}


ADL_RESULT Exit(ADL_THREAD *self,void *status)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = pthread_linux.pthread_exit(status);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = thread_windows.ExitThread((s32)ADL_READ_S32_PTR((s32_ptr)status));
#endif

null_self:
    return rdr_res;
}

/**
ADL_RESULT get_name(ADL_THREAD *self)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

null_self:
    return rdr_res;
}


ADL_RESULT set_name(ADL_THREAD *self,ADL_STRING name)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

null_self:
    return rdr_res;
}
*/

ADL_RESULT GetId(ADL_THREAD *self)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

#if defined(ADL_OS_UNIX)
    rdr_res.code = self->id.tid;
#elif defined(ADL_OS_WINDOWS)
    rdr_res.code = self->id.tid;
    rdr_res.ptr = self->id.handle;
#endif

null_self:
    return rdr_res;
}

/*
ADL_RESULT is_alive(ADL_THREAD *self)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

null_self:
    return rdr_res;
}

*/




void ADL_THREAD_Init(ADL_THREAD *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class->id          = (ADL_THREAD_ID){0};
    class->exit_code   = 0;

    class->Start       = Start;
    class->Detach      = Detach;
    class->Join        = Join;
    class->Exit        = Exit;
    class->GetId       = GetId;

null_class:
    return;
}

void ADL_THREAD_Fini(ADL_THREAD *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_THREAD));

null_class:
    return;
}

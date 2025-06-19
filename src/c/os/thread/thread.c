#include "thread.h"


ADL_RESULT adl_thread_start(ADL_THREAD *self,void *(*start_routine)(void *arg),void *arg)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    return pthread_linux.pthread_create(&self->id.tid,NULL,start_routine,arg);


null_self:
    return rdr_res;
}


ADL_RESULT adl_thread_detach(ADL_THREAD *self)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    return pthread_linux.pthread_detach(self->id.tid);

null_self:
    return rdr_res;
}


ADL_RESULT adl_thread_join(ADL_THREAD *self,void **retval)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    return pthread_linux.pthread_join(self->id.tid,retval);

null_self:
    return rdr_res;
}


ADL_RESULT adl_thread_exit(ADL_THREAD *self,void *status)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    return pthread_linux.pthread_exit(status);

null_self:
    return rdr_res;
}

/**
ADL_RESULT adl_thread_get_name(ADL_THREAD *self)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

null_self:
    return rdr_res;
}


ADL_RESULT adl_thread_set_name(ADL_THREAD *self,ADL_STRING name)
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

ADL_RESULT adl_thread_get_tid(ADL_THREAD *self)
{
    ADL_RESULT_INIT(rdr_res);
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    return pthread_linux.pthread_self();

null_self:
    return rdr_res;
}

/*
ADL_RESULT adl_thread_is_alive(ADL_THREAD *self)
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




void ADL_THREAD_init(ADL_THREAD *thread)
{
    if(ADL_CHECK_NULL(thread))
    {
        ADL_RETURN_DEFER(null_class);
    }

    thread->start       = adl_thread_start;
    thread->detach      = adl_thread_detach;
    thread->join        = adl_thread_join;
    thread->exit        = adl_thread_exit;
    thread->get_tid     = adl_thread_get_tid;

null_class:
    return;
}

void ADL_THREAD_fini(ADL_THREAD *thread)
{
    if(ADL_CHECK_NULL(thread))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(thread,0,sizeof(ADL_THREAD));

null_class:
    return;
}

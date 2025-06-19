#ifndef ADL_OS_THREAD_THREAD_H
#define ADL_OS_THREAD_THREAD_H




#include "pthread_linux.h"




typedef struct ADL_THREAD_ID
{
    pthread_t tid;
}ADL_THREAD_ID;

typedef struct ADL_THREAD
{
    ADL_THREAD_ID id;
    ADL_RESULT (*start)(struct ADL_THREAD *self,void *(*start_routine)(void *arg),void *arg);
    ADL_RESULT (*detach)(struct ADL_THREAD *self);
    ADL_RESULT (*join)(struct ADL_THREAD *self,void **retval);
    ADL_RESULT (*exit)(struct ADL_THREAD *self,void *status);
    ADL_RESULT (*get_name)(struct ADL_THREAD *self);
    ADL_RESULT (*set_name)(struct ADL_THREAD *self,ADL_STRING name);
    ADL_RESULT (*get_tid)(struct ADL_THREAD *self);
    ADL_RESULT (*is_alive)(struct ADL_THREAD *self);
}ADL_THREAD;


extern ADL_PTHREAD_LINUX pthread_linux;



void ADL_THREAD_init(ADL_THREAD *thread);

void ADL_THREAD_fini(ADL_THREAD *thread);

#endif
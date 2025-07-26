#ifndef ADL_OS_THREAD_CONDITION_H
#define ADL_OS_THREAD_CONDITION_H

#include "../os.h"



typedef struct ADL_CONDITION
{
#if defined(ADL_OS_UNIX)
    pthread_mutex_t lock;
    pthread_cond_t condition;
#elif defined(ADL_OS_WINDOWS)
    CRITICAL_SECTION lock;
    CONDITION_VARIABLE condition;
#endif

    ADL_RESULT (*Acquire)(struct ADL_CONDITION *self);
    ADL_RESULT (*Release)(struct ADL_CONDITION *self);
    ADL_RESULT (*Wait)(struct ADL_CONDITION *self);
    ADL_RESULT (*TimedWait)(struct ADL_CONDITION *self,u32 milliseconds);
    ADL_RESULT (*Notify)(struct ADL_CONDITION *self);
    ADL_RESULT (*NotifyAll)(struct ADL_CONDITION *self);
}ADL_CONDITION;



ADL_RESULT ADL_CONDITION_Init(ADL_CONDITION *class);

ADL_RESULT ADL_CONDITION_Fini(ADL_CONDITION *class);

#endif
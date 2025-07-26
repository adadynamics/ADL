#ifndef ADL_OS_THREAD_MUTEX_H
#define ADL_OS_THREAD_MUTEX_H

#include "../os.h"



typedef struct ADL_MUTEX
{
#if defined(ADL_OS_UNIX)
    pthread_mutex_t lock;
#elif defined(ADL_OS_WINDOWS)
    CRITICAL_SECTION lock;
#endif

    ADL_RESULT (*Acquire)(struct ADL_MUTEX *self,bool blocking);
    ADL_RESULT (*Release)(struct ADL_MUTEX *self);
}ADL_MUTEX;



ADL_RESULT ADL_MUTEX_Init(ADL_MUTEX *class);

ADL_RESULT ADL_MUTEX_Fini(ADL_MUTEX *class);

#endif
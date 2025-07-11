#ifndef ADL_OS_THREAD_SPINLOCK_H
#define ADL_OS_THREAD_SPINLOCK_H

#include "../os.h"



typedef struct ADL_SPINLOCK
{
#if defined(ADL_OS_UNIX)
    pthread_spinlock_t lock;
#elif defined(ADL_OS_WINDOWS)
    CRITICAL_SECTION lock;
#endif

    ADL_RESULT (*Acquire)(struct ADL_SPINLOCK *self,bool blocking);
    ADL_RESULT (*Release)(struct ADL_SPINLOCK *self);
}ADL_SPINLOCK;



ADL_RESULT ADL_SPINLOCK_Init(ADL_SPINLOCK *class);

ADL_RESULT ADL_SPINLOCK_Fini(ADL_SPINLOCK *class);

#endif
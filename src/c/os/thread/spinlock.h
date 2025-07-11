#ifndef ADL_SRC_OS_THREAD_SPINLOCK_H
#define ADL_SRC_OS_THREAD_SPINLOCK_H


#include "../../include/os/thread/spinlock.h"
#include "platform/unix/pthread_linux.h"
#include "platform/windows/thread_windows.h"



ADL_RESULT Acquire(struct ADL_SPINLOCK *self,bool blocking);
ADL_RESULT Release(struct ADL_SPINLOCK *self);



ADL_RESULT ADL_SPINLOCK_Init(ADL_SPINLOCK *class);

ADL_RESULT ADL_SPINLOCK_Fini(ADL_SPINLOCK *class);


#endif
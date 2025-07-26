#ifndef ADL_SRC_OS_THREAD_MUTEX_H
#define ADL_SRC_OS_THREAD_MUTEX_H


#include "../../include/os/thread/condition.h"
#include "platform/unix/pthread_linux.h"
#include "platform/windows/thread_windows.h"




ADL_RESULT Acquire(struct ADL_CONDITION *self);
ADL_RESULT Release(struct ADL_CONDITION *self);
ADL_RESULT Wait(struct ADL_CONDITION *self);
ADL_RESULT TimedWait(struct ADL_CONDITION *self,u32 milliseconds);
ADL_RESULT Notify(struct ADL_CONDITION *self);
ADL_RESULT NotifyAll(struct ADL_CONDITION *self);


ADL_RESULT ADL_CONDITION_Init(ADL_CONDITION *class);

ADL_RESULT ADL_CONDITION_Fini(ADL_CONDITION *class);


#endif
#ifndef ADL_SRC_OS_THREAD_MUTEX_H
#define ADL_SRC_OS_THREAD_MUTEX_H


#include "../../include/os/thread/mutex.h"
#include "platform/unix/pthread_linux.h"
#include "platform/windows/thread_windows.h"



ADL_RESULT Acquire(struct ADL_MUTEX *self,bool blocking);
ADL_RESULT Release(struct ADL_MUTEX *self);



ADL_RESULT ADL_MUTEX_Init(ADL_MUTEX *class);

ADL_RESULT ADL_MUTEX_Fini(ADL_MUTEX *class);


#endif
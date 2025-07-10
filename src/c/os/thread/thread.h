#ifndef ADL_SRC_OS_THREAD_THREAD_H
#define ADL_SRC_OS_THREAD_THREAD_H

#include "../../include/os/thread/thread.h"
#include "platform/unix/pthread_linux.h"
#include "platform/windows/thread_windows.h"



ADL_RESULT Start(ADL_THREAD *self,u64 (*start_routine)(void *arg),void *arg);
ADL_RESULT Detach(ADL_THREAD *self);
ADL_RESULT Join(ADL_THREAD *self,void **retval);
ADL_RESULT Exit(ADL_THREAD *self,void *status);
ADL_RESULT GetName(ADL_THREAD *self);
ADL_RESULT SetName(ADL_THREAD *self,ADL_STRING name);
ADL_RESULT GetId(ADL_THREAD *self);
ADL_RESULT IsAlive(ADL_THREAD *self);



#endif
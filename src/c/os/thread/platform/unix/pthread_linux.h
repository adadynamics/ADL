#ifndef ADL_SRC_OS_THREAD_PLATFORM_UNIX_PTHREAD_LINUX
#define ADL_SRC_OS_THREAD_PLATFORM_UNIX_PTHREAD_LINUX

#include "../../../os.h"



#ifdef ADL_OS_UNIX



typedef struct ADL_PTHREAD_LINUX
{
    ADL_RESULT (*pthread_attr_destroy)(pthread_attr_t *attr);
    ADL_RESULT (*pthread_getcpuclockid)(pthread_t thread, clockid_t *clockid);
    ADL_RESULT (*pthread_attr_getaffinity_np)(const pthread_attr_t *attr,size_t cpusetsize,cpu_set_t *cpuset);
    ADL_RESULT (*pthread_getname_np)(pthread_t thread, char *name,size_t size);
    ADL_RESULT (*pthread_attr_getdetachstate)(const pthread_attr_t *attr,int *detachstate);
    ADL_RESULT (*pthread_getschedparam)(pthread_t thread,int *restrict policy,struct sched_param *restrict param);
    ADL_RESULT (*pthread_attr_getguardsize)(const pthread_attr_t *restrict attr,size_t *restrict guardsize);
    ADL_RESULT (*pthread_join)(pthread_t thread,void **retval);
    ADL_RESULT (*pthread_attr_getinheritsched)(const pthread_attr_t *restrict attr,int *restrict inheritsched);
    ADL_RESULT (*pthread_kill)(pthread_t thread,int sig);
    ADL_RESULT (*pthread_attr_getschedparam)(const pthread_attr_t *restrict attr,struct sched_param *restrict param);
    ADL_RESULT (*pthread_attr_getschedpolicy)(const pthread_attr_t *restrict attr,int *restrict policy);
    ADL_RESULT (*pthread_mutexattr_getpshared)(const pthread_mutexattr_t *restrict attr,int *restrict pshared);
    ADL_RESULT (*pthread_attr_getscope)(const pthread_attr_t *restrict attr,int *restrict scope);
    ADL_RESULT (*pthread_mutexattr_getrobust)(const pthread_mutexattr_t *attr,int *robustness);
    ADL_RESULT (*pthread_attr_getsigmask_np)(const pthread_attr_t *attr,sigset_t *sigmask);
    ADL_RESULT (*pthread_attr_getstack)(const pthread_attr_t *restrict attr,void **restrict stackaddr,size_t *restrict stacksize);
    ADL_RESULT (*pthread_mutexattr_setpshared)(pthread_mutexattr_t *attr,int pshared);
    ADL_RESULT (*pthread_mutexattr_setrobust)(pthread_mutexattr_t *attr,int robustness);
    ADL_RESULT (*pthread_attr_getstacksize)(const pthread_attr_t *restrict attr,size_t *restrict stacksize);
    ADL_RESULT (*pthread_attr_init)(pthread_attr_t *attr);
    ADL_RESULT (*pthread_mutex_consistent)(pthread_mutex_t *mutex);
    ADL_RESULT (*pthread_attr_setaffinity_np)(pthread_attr_t *attr,size_t cpusetsize,const cpu_set_t *cpuset);
    ADL_RESULT (*pthread_attr_setdetachstate)(pthread_attr_t *attr,int detachstate);
    ADL_RESULT (*pthread_rwlockattr_getkind_np)(const pthread_rwlockattr_t *restrict attr,int *restrict pref);
    ADL_RESULT (*pthread_attr_setguardsize)(pthread_attr_t *attr,size_t guardsize);
    ADL_RESULT (*pthread_rwlockattr_setkind_np)(pthread_rwlockattr_t *attr,int pref);
    ADL_RESULT (*pthread_attr_setinheritsched)(pthread_attr_t *attr,int inheritsched);
    ADL_RESULT (*pthread_self)(void);
    ADL_RESULT (*pthread_attr_setschedparam)(pthread_attr_t *restrict attr,const struct sched_param *restrict param);
    ADL_RESULT (*pthread_setaffinity_np)(pthread_t thread,size_t cpusetsize,const cpu_set_t *cpuset);
    ADL_RESULT (*pthread_attr_setschedpolicy)(pthread_attr_t *attr,int policy);
    ADL_RESULT (*pthread_setattr_default_np)(const pthread_attr_t *attr);
    ADL_RESULT (*pthread_attr_setscope)(pthread_attr_t *attr,int scope);
    ADL_RESULT (*pthread_setcancelstate)(int state,int *oldstate);
    ADL_RESULT (*pthread_attr_setsigmask_np)(pthread_attr_t *attr,const sigset_t *sigmask);
    ADL_RESULT (*pthread_setcanceltype)(int type,int *oldtype);
    ADL_RESULT (*pthread_attr_setstack)(pthread_attr_t *attr,void *stackaddr,size_t stacksize);
    ADL_RESULT (*pthread_setconcurrency)(int new_level);
    ADL_RESULT (*pthread_setname_np)(pthread_t thread,const char *name);
    ADL_RESULT (*pthread_attr_setstacksize)(pthread_attr_t *attr,size_t stacksize);
    ADL_RESULT (*pthread_setschedparam)(pthread_t thread,int policy,const struct sched_param *param);
    ADL_RESULT (*pthread_cancel)(pthread_t thread);
    ADL_RESULT (*pthread_setschedprio)(pthread_t thread,int prio);
    ADL_RESULT (*pthread_sigmask)(int how,const sigset_t *set,sigset_t *oldset);
    ADL_RESULT (*pthread_sigqueue)(pthread_t thread,int sig,const union sigval value);
    ADL_RESULT (*pthread_spin_destroy)(pthread_spinlock_t *lock);
    ADL_RESULT (*pthread_spin_init)(pthread_spinlock_t *lock,int pshared);
    ADL_RESULT (*pthread_create)(pthread_t *restrict thread,const pthread_attr_t *restrict attr,void *(*start_routine)(void *),void *restrict arg);
    ADL_RESULT (*pthread_spin_lock)(pthread_spinlock_t *lock);
    ADL_RESULT (*pthread_detach)(pthread_t thread);
    ADL_RESULT (*pthread_spin_trylock)(pthread_spinlock_t *lock);
    ADL_RESULT (*pthread_equal)(pthread_t t1,pthread_t t2);
    ADL_RESULT (*pthread_spin_unlock)(pthread_spinlock_t *lock);
    ADL_RESULT (*pthread_exit)(void *retval);
    ADL_RESULT (*pthread_testcancel)(void);
    ADL_RESULT (*pthread_getaffinity_np)(pthread_t thread,size_t cpusetsize,cpu_set_t *cpuset);
    ADL_RESULT (*pthread_timedjoin_np)(pthread_t thread,void **retval,const struct timespec *abstime);
    ADL_RESULT (*pthread_getattr_default_np)(pthread_attr_t *attr);
    ADL_RESULT (*pthread_tryjoin_np)(pthread_t thread,void **retval);
    ADL_RESULT (*pthread_getattr_np)(pthread_t thread,pthread_attr_t *attr);
    ADL_RESULT (*pthread_getconcurrency)(void);
	ADL_RESULT (*pthread_mutex_init)(pthread_mutex_t *mutex,const pthread_mutexattr_t *attr);
	ADL_RESULT (*pthread_mutex_destroy)(pthread_mutex_t *mutex);
	ADL_RESULT (*pthread_mutex_lock)(pthread_mutex_t *mutex);
	ADL_RESULT (*pthread_mutex_trylock)(pthread_mutex_t *mutex);
	ADL_RESULT (*pthread_mutex_timedlock)(pthread_mutex_t *mutex,const struct timespec *abstime);
	ADL_RESULT (*pthread_mutex_unlock)(pthread_mutex_t *mutex);
	ADL_RESULT (*pthread_cond_init)(pthread_cond_t *cond, const pthread_condattr_t *attr);
	ADL_RESULT (*pthread_cond_destroy)(pthread_cond_t *cond);
	ADL_RESULT (*pthread_cond_wait)(pthread_cond_t *cond, pthread_mutex_t *mutex);
	ADL_RESULT (*pthread_cond_timedwait)(pthread_cond_t *cond, pthread_mutex_t *mutex, const struct timespec *abstime);
	ADL_RESULT (*pthread_cond_signal)(pthread_cond_t *cond);
	ADL_RESULT (*pthread_cond_broadcast)(pthread_cond_t *cond);
}ADL_PTHREAD_LINUX;


void ADL_PTHREAD_LINUX_Init(ADL_PTHREAD_LINUX *pthread);

void ADL_PTHREAD_LINUX_Fini(ADL_PTHREAD_LINUX *pthread);


#endif

#endif

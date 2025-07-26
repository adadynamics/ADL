#ifndef ADL_SRC_UNIX_THREAD_THREAD_H
#define ADL_SRC_UNIX_THREAD_THREAD_H


#include "../unix.h"

#ifdef ADL_OS_UNIX




#ifndef ADL_PTHREAD_ATTR_DESTROY
#define ADL_PTHREAD_ATTR_DESTROY pthread_attr_destroy
#endif


#ifndef ADL_PTHREAD_GETCPUCLOCKID
#define ADL_PTHREAD_GETCPUCLOCKID pthread_getcpuclockid
#endif


#ifndef ADL_PTHREAD_ATTR_GETAFFINITY_NP
#define ADL_PTHREAD_ATTR_GETAFFINITY_NP pthread_attr_getaffinity_np   
#endif


#ifndef ADL_PTHREAD_GETNAME_NP
#define ADL_PTHREAD_GETNAME_NP pthread_getname_np
#endif


#ifndef ADL_PTHREAD_ATTR_GETDETACHSTATE
#define ADL_PTHREAD_ATTR_GETDETACHSTATE pthread_attr_getdetachstate   
#endif


#ifndef ADL_PTHREAD_GETSCHEDPARAM
#define ADL_PTHREAD_GETSCHEDPARAM pthread_getschedparam
#endif


#ifndef ADL_PTHREAD_ATTR_GETGUARDSIZE
#define ADL_PTHREAD_ATTR_GETGUARDSIZE pthread_attr_getguardsize     
#endif


#ifndef ADL_PTHREAD_JOIN
#define ADL_PTHREAD_JOIN pthread_join
#endif


#ifndef ADL_PTHREAD_ATTR_GETINHERITSCHED
#define ADL_PTHREAD_ATTR_GETINHERITSCHED pthread_attr_getinheritsched  
#endif


#ifndef ADL_PTHREAD_KILL
#define ADL_PTHREAD_KILL pthread_kill
#endif


#ifndef ADL_PTHREAD_ATTR_GETSCHEDPARAM
#define ADL_PTHREAD_ATTR_GETSCHEDPARAM pthread_attr_getschedparam    
#endif


#ifndef ADL_PTHREAD_ATTR_GETSCHEDPOLICY
#define ADL_PTHREAD_ATTR_GETSCHEDPOLICY pthread_attr_getschedpolicy   
#endif


#ifndef ADL_PTHREAD_MUTEXATTR_GETPSHARED
#define ADL_PTHREAD_MUTEXATTR_GETPSHARED pthread_mutexattr_getpshared
#endif


#ifndef ADL_PTHREAD_ATTR_GETSCOPE
#define ADL_PTHREAD_ATTR_GETSCOPE pthread_attr_getscope         
#endif


#ifndef ADL_PTHREAD_MUTEXATTR_GETROBUST
#define ADL_PTHREAD_MUTEXATTR_GETROBUST pthread_mutexattr_getrobust
#endif


#ifndef ADL_PTHREAD_ATTR_GETSIGMASK_NP
#define ADL_PTHREAD_ATTR_GETSIGMASK_NP pthread_attr_getsigmask_np    
#endif


#ifndef ADL_PTHREAD_ATTR_GETSTACK
#define ADL_PTHREAD_ATTR_GETSTACK pthread_attr_getstack         
#endif


#ifndef ADL_PTHREAD_MUTEXATTR_SETPSHARED
#define ADL_PTHREAD_MUTEXATTR_SETPSHARED pthread_mutexattr_setpshared
#endif


#ifndef ADL_PTHREAD_MUTEXATTR_SETROBUST
#define ADL_PTHREAD_MUTEXATTR_SETROBUST pthread_mutexattr_setrobust
#endif


#ifndef ADL_PTHREAD_ATTR_GETSTACKSIZE
#define ADL_PTHREAD_ATTR_GETSTACKSIZE pthread_attr_getstacksize     
#endif


#ifndef ADL_PTHREAD_ATTR_INIT
#define ADL_PTHREAD_ATTR_INIT pthread_attr_init             
#endif


#ifndef ADL_PTHREAD_MUTEX_CONSISTENT
#define ADL_PTHREAD_MUTEX_CONSISTENT pthread_mutex_consistent
#endif


#ifndef ADL_PTHREAD_ATTR_SETAFFINITY_NP
#define ADL_PTHREAD_ATTR_SETAFFINITY_NP pthread_attr_setaffinity_np   
#endif


#ifndef ADL_PTHREAD_ATTR_SETDETACHSTATE
#define ADL_PTHREAD_ATTR_SETDETACHSTATE pthread_attr_setdetachstate   
#endif


#ifndef ADL_PTHREAD_RWLOCKATTR_GETKIND_NP
#define ADL_PTHREAD_RWLOCKATTR_GETKIND_NP pthread_rwlockattr_getkind_np
#endif


#ifndef ADL_PTHREAD_ATTR_SETGUARDSIZE
#define ADL_PTHREAD_ATTR_SETGUARDSIZE pthread_attr_setguardsize     
#endif


#ifndef ADL_PTHREAD_RWLOCKATTR_SETKIND_NP
#define ADL_PTHREAD_RWLOCKATTR_SETKIND_NP pthread_rwlockattr_setkind_np
#endif


#ifndef ADL_PTHREAD_ATTR_SETINHERITSCHED
#define ADL_PTHREAD_ATTR_SETINHERITSCHED pthread_attr_setinheritsched  
#endif


#ifndef ADL_PTHREAD_SELF
#define ADL_PTHREAD_SELF pthread_self
#endif


#ifndef ADL_PTHREAD_ATTR_SETSCHEDPARAM
#define ADL_PTHREAD_ATTR_SETSCHEDPARAM pthread_attr_setschedparam    
#endif


#ifndef ADL_PTHREAD_SETAFFINITY_NP
#define ADL_PTHREAD_SETAFFINITY_NP pthread_setaffinity_np
#endif


#ifndef ADL_PTHREAD_ATTR_SETSCHEDPOLICY
#define ADL_PTHREAD_ATTR_SETSCHEDPOLICY pthread_attr_setschedpolicy   
#endif


#ifndef ADL_PTHREAD_SETATTR_DEFAULT_NP
#define ADL_PTHREAD_SETATTR_DEFAULT_NP pthread_setattr_default_np
#endif


#ifndef ADL_PTHREAD_ATTR_SETSCOPE
#define ADL_PTHREAD_ATTR_SETSCOPE pthread_attr_setscope         
#endif


#ifndef ADL_PTHREAD_SETCANCELSTATE
#define ADL_PTHREAD_SETCANCELSTATE pthread_setcancelstate
#endif


#ifndef ADL_PTHREAD_ATTR_SETSIGMASK_NP
#define ADL_PTHREAD_ATTR_SETSIGMASK_NP pthread_attr_setsigmask_np    
#endif


#ifndef ADL_PTHREAD_SETCANCELTYPE
#define ADL_PTHREAD_SETCANCELTYPE pthread_setcanceltype
#endif


#ifndef ADL_PTHREAD_ATTR_SETSTACK
#define ADL_PTHREAD_ATTR_SETSTACK pthread_attr_setstack         
#endif


#ifndef ADL_PTHREAD_SETCONCURRENCY
#define ADL_PTHREAD_SETCONCURRENCY pthread_setconcurrency
#endif


#ifndef ADL_PTHREAD_SETNAME_NP
#define ADL_PTHREAD_SETNAME_NP pthread_setname_np
#endif


#ifndef ADL_PTHREAD_ATTR_SETSTACKSIZE
#define ADL_PTHREAD_ATTR_SETSTACKSIZE pthread_attr_setstacksize     
#endif


#ifndef ADL_PTHREAD_SETSCHEDPARAM
#define ADL_PTHREAD_SETSCHEDPARAM pthread_setschedparam
#endif


#ifndef ADL_PTHREAD_CANCEL
#define ADL_PTHREAD_CANCEL pthread_cancel                
#endif


#ifndef ADL_PTHREAD_SETSCHEDPRIO
#define ADL_PTHREAD_SETSCHEDPRIO pthread_setschedprio
#endif


#ifndef ADL_PTHREAD_SIGMASK
#define ADL_PTHREAD_SIGMASK pthread_sigmask
#endif


#ifndef ADL_PTHREAD_CLEANUP_POP_RESTORE_NP
#define ADL_PTHREAD_CLEANUP_POP_RESTORE_NP pthread_cleanup_pop_restore_np
#endif


#ifndef ADL_PTHREAD_SIGQUEUE
#define ADL_PTHREAD_SIGQUEUE pthread_sigqueue
#endif


#ifndef ADL_PTHREAD_SPIN_DESTROY
#define ADL_PTHREAD_SPIN_DESTROY pthread_spin_destroy
#endif


#ifndef ADL_PTHREAD_SPIN_INIT
#define ADL_PTHREAD_SPIN_INIT pthread_spin_init
#endif


#ifndef ADL_PTHREAD_CREATE
#define ADL_PTHREAD_CREATE pthread_create                
#endif


#ifndef ADL_PTHREAD_SPIN_LOCK
#define ADL_PTHREAD_SPIN_LOCK pthread_spin_lock
#endif


#ifndef ADL_PTHREAD_DETACH
#define ADL_PTHREAD_DETACH pthread_detach                
#endif


#ifndef ADL_PTHREAD_SPIN_TRYLOCK
#define ADL_PTHREAD_SPIN_TRYLOCK pthread_spin_trylock
#endif


#ifndef ADL_PTHREAD_EQUAL
#define ADL_PTHREAD_EQUAL pthread_equal                 
#endif


#ifndef ADL_PTHREAD_SPIN_UNLOCK
#define ADL_PTHREAD_SPIN_UNLOCK pthread_spin_unlock
#endif


#ifndef ADL_PTHREAD_EXIT
#define ADL_PTHREAD_EXIT pthread_exit                  
#endif


#ifndef ADL_PTHREAD_TESTCANCEL
#define ADL_PTHREAD_TESTCANCEL pthread_testcancel
#endif


#ifndef ADL_PTHREAD_GETAFFINITY_NP
#define ADL_PTHREAD_GETAFFINITY_NP pthread_getaffinity_np        
#endif


#ifndef ADL_PTHREAD_TIMEDJOIN_NP
#define ADL_PTHREAD_TIMEDJOIN_NP pthread_timedjoin_np
#endif


#ifndef ADL_PTHREAD_GETATTR_DEFAULT_NP
#define ADL_PTHREAD_GETATTR_DEFAULT_NP pthread_getattr_default_np    
#endif


#ifndef ADL_PTHREAD_TRYJOIN_NP
#define ADL_PTHREAD_TRYJOIN_NP pthread_tryjoin_np
#endif


#ifndef ADL_PTHREAD_GETATTR_NP
#define ADL_PTHREAD_GETATTR_NP pthread_getattr_np            
#endif


#ifndef ADL_PTHREAD_GETCONCURRENCY
#define ADL_PTHREAD_GETCONCURRENCY pthread_getconcurrency
#endif


#ifndef ADL_PTHREAD_MUTEX_INIT
#define ADL_PTHREAD_MUTEX_INIT pthread_mutex_init
#endif

#ifndef ADL_PTHREAD_MUTEX_DESTROY
#define ADL_PTHREAD_MUTEX_DESTROY pthread_mutex_destroy
#endif

#ifndef ADL_PTHREAD_MUTEX_LOCK
#define ADL_PTHREAD_MUTEX_LOCK pthread_mutex_lock
#endif

#ifndef ADL_PTHREAD_MUTEX_TRYLOCK
#define ADL_PTHREAD_MUTEX_TRYLOCK pthread_mutex_trylock
#endif

#ifndef ADL_PTHREAD_MUTEX_TIMEDLOCK
#define ADL_PTHREAD_MUTEX_TIMEDLOCK pthread_mutex_timedlock
#endif

#ifndef ADL_PTHREAD_MUTEX_UNLOCK
#define ADL_PTHREAD_MUTEX_UNLOCK pthread_mutex_unlock
#endif



#ifndef ADL_PTHREAD_COND_INIT
#define ADL_PTHREAD_COND_INIT pthread_cond_init
#endif

#ifndef ADL_PTHREAD_COND_DESTROY
#define ADL_PTHREAD_COND_DESTROY pthread_cond_destroy
#endif

#ifndef ADL_PTHREAD_COND_WAIT
#define ADL_PTHREAD_COND_WAIT pthread_cond_wait
#endif

#ifndef ADL_PTHREAD_COND_TIMEDWAIT
#define ADL_PTHREAD_COND_TIMEDWAIT pthread_cond_timedwait
#endif

#ifndef ADL_PTHREAD_COND_SIGNAL
#define ADL_PTHREAD_COND_SIGNAL pthread_cond_signal
#endif

#ifndef ADL_PTHREAD_COND_BROADCAST
#define ADL_PTHREAD_COND_BROADCAST pthread_cond_broadcast
#endif



ADL_RESULT adl_lib_pthread_attr_destroy(pthread_attr_t *attr);
ADL_RESULT adl_lib_pthread_getcpuclockid(pthread_t thread, clockid_t *clockid);
ADL_RESULT adl_lib_pthread_attr_getaffinity_np(const pthread_attr_t *attr,size_t cpusetsize,cpu_set_t *cpuset);
ADL_RESULT adl_lib_pthread_getname_np(pthread_t thread, char *name,size_t size);
ADL_RESULT adl_lib_pthread_attr_getdetachstate(const pthread_attr_t *attr,int *detachstate);
ADL_RESULT adl_lib_pthread_getschedparam(pthread_t thread,int *restrict policy,struct sched_param *restrict param);
ADL_RESULT adl_lib_pthread_attr_getguardsize(const pthread_attr_t *restrict attr,size_t *restrict guardsize);
ADL_RESULT adl_lib_pthread_join(pthread_t thread,void **retval);
ADL_RESULT adl_lib_pthread_attr_getinheritsched(const pthread_attr_t *restrict attr,int *restrict inheritsched);
ADL_RESULT adl_lib_pthread_kill(pthread_t thread,int sig);
ADL_RESULT adl_lib_pthread_attr_getschedparam(const pthread_attr_t *restrict attr,struct sched_param *restrict param);
ADL_RESULT adl_lib_pthread_attr_getschedpolicy(const pthread_attr_t *restrict attr,int *restrict policy);
ADL_RESULT adl_lib_pthread_mutexattr_getpshared(const pthread_mutexattr_t *restrict attr,int *restrict pshared);
ADL_RESULT adl_lib_pthread_attr_getscope(const pthread_attr_t *restrict attr,int *restrict scope);
ADL_RESULT adl_lib_pthread_mutexattr_getrobust(const pthread_mutexattr_t *attr,int *robustness);
ADL_RESULT adl_lib_pthread_attr_getsigmask_np(const pthread_attr_t *attr,sigset_t *sigmask);
ADL_RESULT adl_lib_pthread_attr_getstack(const pthread_attr_t *restrict attr,void **restrict stackaddr,size_t *restrict stacksize);
ADL_RESULT adl_lib_pthread_mutexattr_setpshared(pthread_mutexattr_t *attr,int pshared);
ADL_RESULT adl_lib_pthread_mutexattr_setrobust(pthread_mutexattr_t *attr,int robustness);
ADL_RESULT adl_lib_pthread_attr_getstacksize(const pthread_attr_t *restrict attr,size_t *restrict stacksize);
ADL_RESULT adl_lib_pthread_attr_init(pthread_attr_t *attr);
ADL_RESULT adl_lib_pthread_mutex_consistent(pthread_mutex_t *mutex);
ADL_RESULT adl_lib_pthread_attr_setaffinity_np(pthread_attr_t *attr,size_t cpusetsize,const cpu_set_t *cpuset);
ADL_RESULT adl_lib_pthread_attr_setdetachstate(pthread_attr_t *attr,int detachstate);
ADL_RESULT adl_lib_pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t *restrict attr,int *restrict pref);
ADL_RESULT adl_lib_pthread_attr_setguardsize(pthread_attr_t *attr,size_t guardsize);
ADL_RESULT adl_lib_pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *attr,int pref);
ADL_RESULT adl_lib_pthread_attr_setinheritsched(pthread_attr_t *attr,int inheritsched);
ADL_RESULT adl_lib_pthread_self(void);
ADL_RESULT adl_lib_pthread_attr_setschedparam(pthread_attr_t *restrict attr,const struct sched_param *restrict param);
ADL_RESULT adl_lib_pthread_setaffinity_np(pthread_t thread,size_t cpusetsize,const cpu_set_t *cpuset);
ADL_RESULT adl_lib_pthread_attr_setschedpolicy(pthread_attr_t *attr,int policy);
ADL_RESULT adl_lib_pthread_setattr_default_np(const pthread_attr_t *attr);
ADL_RESULT adl_lib_pthread_attr_setscope(pthread_attr_t *attr,int scope);
ADL_RESULT adl_lib_pthread_setcancelstate(int state,int *oldstate);
ADL_RESULT adl_lib_pthread_attr_setsigmask_np(pthread_attr_t *attr,const sigset_t *sigmask);
ADL_RESULT adl_lib_pthread_setcanceltype(int type,int *oldtype);
ADL_RESULT adl_lib_pthread_attr_setstack(pthread_attr_t *attr,void *stackaddr,size_t stacksize);
ADL_RESULT adl_lib_pthread_setconcurrency(int new_level);
ADL_RESULT adl_lib_pthread_setname_np(pthread_t thread,const char *name);
ADL_RESULT adl_lib_pthread_attr_setstacksize(pthread_attr_t *attr,size_t stacksize);
ADL_RESULT adl_lib_pthread_setschedparam(pthread_t thread,int policy,const struct sched_param *param);
ADL_RESULT adl_lib_pthread_cancel(pthread_t thread);
ADL_RESULT adl_lib_pthread_setschedprio(pthread_t thread,int prio);
ADL_RESULT adl_lib_pthread_sigmask(int how,const sigset_t *set,sigset_t *oldset);
ADL_RESULT adl_lib_pthread_sigqueue(pthread_t thread,int sig,const union sigval value);
ADL_RESULT adl_lib_pthread_spin_destroy(pthread_spinlock_t *lock);
ADL_RESULT adl_lib_pthread_spin_init(pthread_spinlock_t *lock,int pshared);
ADL_RESULT adl_lib_pthread_create(pthread_t *restrict thread,const pthread_attr_t *restrict attr,void *(*start_routine)(void *),void *restrict arg);
ADL_RESULT adl_lib_pthread_spin_lock(pthread_spinlock_t *lock);
ADL_RESULT adl_lib_pthread_detach(pthread_t thread);
ADL_RESULT adl_lib_pthread_spin_trylock(pthread_spinlock_t *lock);
ADL_RESULT adl_lib_pthread_equal(pthread_t t1,pthread_t t2);
ADL_RESULT adl_lib_pthread_spin_unlock(pthread_spinlock_t *lock);
ADL_RESULT adl_lib_pthread_exit(void *retval);
ADL_RESULT adl_lib_pthread_testcancel(void);
ADL_RESULT adl_lib_pthread_getaffinity_np(pthread_t thread,size_t cpusetsize,cpu_set_t *cpuset);
ADL_RESULT adl_lib_pthread_timedjoin_np(pthread_t thread,void **retval,const struct timespec *abstime);
ADL_RESULT adl_lib_pthread_getattr_default_np(pthread_attr_t *attr);
ADL_RESULT adl_lib_pthread_tryjoin_np(pthread_t thread,void **retval);
ADL_RESULT adl_lib_pthread_getattr_np(pthread_t thread,pthread_attr_t *attr);
ADL_RESULT adl_lib_pthread_getconcurrency(void);
ADL_RESULT adl_lib_pthread_mutex_init(pthread_mutex_t *mutex,const pthread_mutexattr_t *attr);
ADL_RESULT adl_lib_pthread_mutex_destroy(pthread_mutex_t *mutex);
ADL_RESULT adl_lib_pthread_mutex_lock(pthread_mutex_t *mutex);
ADL_RESULT adl_lib_pthread_mutex_trylock(pthread_mutex_t *mutex);
ADL_RESULT adl_lib_pthread_mutex_timedlock(pthread_mutex_t *mutex,const struct timespec *abstime);
ADL_RESULT adl_lib_pthread_mutex_unlock(pthread_mutex_t *mutex);
ADL_RESULT adl_lib_pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);
ADL_RESULT adl_lib_pthread_cond_destroy(pthread_cond_t *cond);
ADL_RESULT adl_lib_pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
ADL_RESULT adl_lib_pthread_cond_timedwait(pthread_cond_t *cond, pthread_mutex_t *mutex, const struct timespec *abstime);
ADL_RESULT adl_lib_pthread_cond_signal(pthread_cond_t *cond);
ADL_RESULT adl_lib_pthread_cond_broadcast(pthread_cond_t *cond);


#endif

#endif

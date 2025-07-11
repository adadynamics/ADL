#include "pthread_linux.h"


#ifdef ADL_OS_UNIX

extern ADL_UNIX adl_os;

void ADL_PTHREAD_LINUX_Init(ADL_PTHREAD_LINUX *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }





    class->pthread_attr_destroy                            = adl_os.pthread_attr_destroy;
    class->pthread_getcpuclockid                           = adl_os.pthread_getcpuclockid;
    class->pthread_attr_getaffinity_np                     = adl_os.pthread_attr_getaffinity_np;
    class->pthread_getname_np                              = adl_os.pthread_getname_np;
    class->pthread_attr_getdetachstate                     = adl_os.pthread_attr_getdetachstate;
    class->pthread_getschedparam                           = adl_os.pthread_getschedparam;
    class->pthread_attr_getguardsize                       = adl_os.pthread_attr_getguardsize;
    class->pthread_join                                    = adl_os.pthread_join;
    class->pthread_attr_getinheritsched                    = adl_os.pthread_attr_getinheritsched;
    class->pthread_kill                                    = adl_os.pthread_kill;
    class->pthread_attr_getschedparam                      = adl_os.pthread_attr_getschedparam;
    class->pthread_attr_getschedpolicy                     = adl_os.pthread_attr_getschedpolicy;
    class->pthread_mutexattr_getpshared                    = adl_os.pthread_mutexattr_getpshared;
    class->pthread_attr_getscope                           = adl_os.pthread_attr_getscope;
    class->pthread_mutexattr_getrobust                     = adl_os.pthread_mutexattr_getrobust;
    class->pthread_attr_getsigmask_np                      = adl_os.pthread_attr_getsigmask_np;
    class->pthread_attr_getstack                           = adl_os.pthread_attr_getstack;
    class->pthread_mutexattr_setpshared                    = adl_os.pthread_mutexattr_setpshared;
    class->pthread_mutexattr_setrobust                     = adl_os.pthread_mutexattr_setrobust;
    class->pthread_attr_getstacksize                       = adl_os.pthread_attr_getstacksize;
    class->pthread_attr_init                               = adl_os.pthread_attr_init;
    class->pthread_mutex_consistent                        = adl_os.pthread_mutex_consistent;
    class->pthread_attr_setaffinity_np                     = adl_os.pthread_attr_setaffinity_np;
    class->pthread_attr_setdetachstate                     = adl_os.pthread_attr_setdetachstate;
    class->pthread_rwlockattr_getkind_np                   = adl_os.pthread_rwlockattr_getkind_np;
    class->pthread_attr_setguardsize                       = adl_os.pthread_attr_setguardsize;
    class->pthread_rwlockattr_setkind_np                   = adl_os.pthread_rwlockattr_setkind_np;
    class->pthread_attr_setinheritsched                    = adl_os.pthread_attr_setinheritsched;
    class->pthread_self                                    = adl_os.pthread_self;
    class->pthread_attr_setschedparam                      = adl_os.pthread_attr_setschedparam;
    class->pthread_setaffinity_np                          = adl_os.pthread_setaffinity_np;
    class->pthread_attr_setschedpolicy                     = adl_os.pthread_attr_setschedpolicy;
    class->pthread_setattr_default_np                      = adl_os.pthread_setattr_default_np;
    class->pthread_attr_setscope                           = adl_os.pthread_attr_setscope;
    class->pthread_setcancelstate                          = adl_os.pthread_setcancelstate;
    class->pthread_attr_setsigmask_np                      = adl_os.pthread_attr_setsigmask_np;
    class->pthread_setcanceltype                           = adl_os.pthread_setcanceltype;
    class->pthread_attr_setstack                           = adl_os.pthread_attr_setstack;
    class->pthread_setconcurrency                          = adl_os.pthread_setconcurrency; 
    class->pthread_setname_np                              = adl_os.pthread_setname_np;
    class->pthread_attr_setstacksize                       = adl_os.pthread_attr_setstacksize;
    class->pthread_setschedparam                           = adl_os.pthread_setschedparam;
    class->pthread_cancel                                  = adl_os.pthread_cancel;
    class->pthread_setschedprio                            = adl_os.pthread_setschedprio;
    class->pthread_sigmask                                 = adl_os.pthread_sigmask;
    class->pthread_sigqueue                                = adl_os.pthread_sigqueue; 
    class->pthread_spin_destroy                            = adl_os.pthread_spin_destroy;
    class->pthread_spin_init                               = adl_os.pthread_spin_init;
    class->pthread_create                                  = adl_os.pthread_create;
    class->pthread_spin_lock                               = adl_os.pthread_spin_lock;
    class->pthread_detach                                  = adl_os.pthread_detach;
    class->pthread_spin_trylock                            = adl_os.pthread_spin_trylock;
    class->pthread_equal                                   = adl_os.pthread_equal;
    class->pthread_spin_unlock                             = adl_os.pthread_spin_unlock;
    class->pthread_exit                                    = adl_os.pthread_exit;
    class->pthread_testcancel                              = adl_os.pthread_testcancel;
    class->pthread_getaffinity_np                          = adl_os.pthread_getaffinity_np;
    class->pthread_timedjoin_np                            = adl_os.pthread_timedjoin_np;
    class->pthread_getattr_default_np                      = adl_os.pthread_getattr_default_np;
    class->pthread_tryjoin_np                              = adl_os.pthread_tryjoin_np;
    class->pthread_getattr_np                              = adl_os.pthread_getattr_np;
    class->pthread_getconcurrency                          = adl_os.pthread_getconcurrency;

null_class:
    return;
}



void ADL_PTHREAD_LINUX_Fini(ADL_PTHREAD_LINUX *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_PTHREAD_LINUX));

null_class:
    return;
}


ADL_PTHREAD_LINUX pthread_linux;

void ADL_PTHREAD_LINUX_library_init()
{
    ADL_PTHREAD_LINUX_Init(&pthread_linux);
}

#endif
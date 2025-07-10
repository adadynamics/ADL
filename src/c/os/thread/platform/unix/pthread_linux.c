#include "pthread_linux.h"


void ADL_PTHREAD_LINUX_init(ADL_PTHREAD_LINUX *pthread_linux)
{
    if(ADL_CHECK_NULL(pthread_linux))
    {
        ADL_RETURN_DEFER(null_class);
    }





    pthread_linux->pthread_attr_destroy                            = adl_os.pthread_attr_destroy;
    pthread_linux->pthread_getcpuclockid                           = adl_os.pthread_getcpuclockid;
    pthread_linux->pthread_attr_getaffinity_np                     = adl_os.pthread_attr_getaffinity_np;
    pthread_linux->pthread_getname_np                              = adl_os.pthread_getname_np;
    pthread_linux->pthread_attr_getdetachstate                     = adl_os.pthread_attr_getdetachstate;
    pthread_linux->pthread_getschedparam                           = adl_os.pthread_getschedparam;
    pthread_linux->pthread_attr_getguardsize                       = adl_os.pthread_attr_getguardsize;
    pthread_linux->pthread_join                                    = adl_os.pthread_join;
    pthread_linux->pthread_attr_getinheritsched                    = adl_os.pthread_attr_getinheritsched;
    pthread_linux->pthread_kill                                    = adl_os.pthread_kill;
    pthread_linux->pthread_attr_getschedparam                      = adl_os.pthread_attr_getschedparam;
    pthread_linux->pthread_attr_getschedpolicy                     = adl_os.pthread_attr_getschedpolicy;
    pthread_linux->pthread_mutexattr_getpshared                    = adl_os.pthread_mutexattr_getpshared;
    pthread_linux->pthread_attr_getscope                           = adl_os.pthread_attr_getscope;
    pthread_linux->pthread_mutexattr_getrobust                     = adl_os.pthread_mutexattr_getrobust;
    pthread_linux->pthread_attr_getsigmask_np                      = adl_os.pthread_attr_getsigmask_np;
    pthread_linux->pthread_attr_getstack                           = adl_os.pthread_attr_getstack;
    pthread_linux->pthread_mutexattr_setpshared                    = adl_os.pthread_mutexattr_setpshared;
    pthread_linux->pthread_mutexattr_setrobust                     = adl_os.pthread_mutexattr_setrobust;
    pthread_linux->pthread_attr_getstacksize                       = adl_os.pthread_attr_getstacksize;
    pthread_linux->pthread_attr_init                               = adl_os.pthread_attr_init;
    pthread_linux->pthread_mutex_consistent                        = adl_os.pthread_mutex_consistent;
    pthread_linux->pthread_attr_setaffinity_np                     = adl_os.pthread_attr_setaffinity_np;
    pthread_linux->pthread_attr_setdetachstate                     = adl_os.pthread_attr_setdetachstate;
    pthread_linux->pthread_rwlockattr_getkind_np                   = adl_os.pthread_rwlockattr_getkind_np;
    pthread_linux->pthread_attr_setguardsize                       = adl_os.pthread_attr_setguardsize;
    pthread_linux->pthread_rwlockattr_setkind_np                   = adl_os.pthread_rwlockattr_setkind_np;
    pthread_linux->pthread_attr_setinheritsched                    = adl_os.pthread_attr_setinheritsched;
    pthread_linux->pthread_self                                    = adl_os.pthread_self;
    pthread_linux->pthread_attr_setschedparam                      = adl_os.pthread_attr_setschedparam;
    pthread_linux->pthread_setaffinity_np                          = adl_os.pthread_setaffinity_np;
    pthread_linux->pthread_attr_setschedpolicy                     = adl_os.pthread_attr_setschedpolicy;
    pthread_linux->pthread_setattr_default_np                      = adl_os.pthread_setattr_default_np;
    pthread_linux->pthread_attr_setscope                           = adl_os.pthread_attr_setscope;
    pthread_linux->pthread_setcancelstate                          = adl_os.pthread_setcancelstate;
    pthread_linux->pthread_attr_setsigmask_np                      = adl_os.pthread_attr_setsigmask_np;
    pthread_linux->pthread_setcanceltype                           = adl_os.pthread_setcanceltype;
    pthread_linux->pthread_attr_setstack                           = adl_os.pthread_attr_setstack;
    pthread_linux->pthread_setconcurrency                          = adl_os.pthread_setconcurrency; 
    pthread_linux->pthread_setname_np                              = adl_os.pthread_setname_np;
    pthread_linux->pthread_attr_setstacksize                       = adl_os.pthread_attr_setstacksize;
    pthread_linux->pthread_setschedparam                           = adl_os.pthread_setschedparam;
    pthread_linux->pthread_cancel                                  = adl_os.pthread_cancel;
    pthread_linux->pthread_setschedprio                            = adl_os.pthread_setschedprio;
    pthread_linux->pthread_sigmask                                 = adl_os.pthread_sigmask;
    pthread_linux->pthread_sigqueue                                = adl_os.pthread_sigqueue; 
    pthread_linux->pthread_spin_destroy                            = adl_os.pthread_spin_destroy;
    pthread_linux->pthread_spin_init                               = adl_os.pthread_spin_init;
    pthread_linux->pthread_create                                  = adl_os.pthread_create;
    pthread_linux->pthread_spin_lock                               = adl_os.pthread_spin_lock;
    pthread_linux->pthread_detach                                  = adl_os.pthread_detach;
    pthread_linux->pthread_spin_trylock                            = adl_os.pthread_spin_trylock;
    pthread_linux->pthread_equal                                   = adl_os.pthread_equal;
    pthread_linux->pthread_spin_unlock                             = adl_os.pthread_spin_unlock;
    pthread_linux->pthread_exit                                    = adl_os.pthread_exit;
    pthread_linux->pthread_testcancel                              = adl_os.pthread_testcancel;
    pthread_linux->pthread_getaffinity_np                          = adl_os.pthread_getaffinity_np;
    pthread_linux->pthread_timedjoin_np                            = adl_os.pthread_timedjoin_np;
    pthread_linux->pthread_getattr_default_np                      = adl_os.pthread_getattr_default_np;
    pthread_linux->pthread_tryjoin_np                              = adl_os.pthread_tryjoin_np;
    pthread_linux->pthread_getattr_np                              = adl_os.pthread_getattr_np;
    pthread_linux->pthread_getconcurrency                          = adl_os.pthread_getconcurrency;

null_class:
    return;
}



void ADL_PTHREAD_LINUX_fini(ADL_PTHREAD_LINUX *pthread_linux)
{
    if(ADL_CHECK_NULL(pthread_linux))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(pthread_linux,0,sizeof(ADL_PTHREAD_LINUX));

null_class:
    return;
}


ADL_PTHREAD_LINUX pthread_linux;

void ADL_PTHREAD_LINUX_library_init()
{
    ADL_PTHREAD_LINUX_init(&pthread_linux);
}
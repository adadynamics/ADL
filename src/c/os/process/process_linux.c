#include "process_linux.h"





void ADL_PROCESS_LINUX_init(ADL_PROCESS_LINUX *process_linux)
{
    if(ADL_CHECK_NULL(process_linux))
    {
        ADL_RETURN_DEFER(null_class);
    }


    process_linux->capget                                          = adl_os.capget;
    process_linux->capset                                          = adl_os.capset;
    process_linux->clone3                                          = adl_os.clone3;
    process_linux->clone                                           = adl_os.clone;
    process_linux->execve                                          = adl_os.execve;
    process_linux->execveat                                        = adl_os.execveat;
    process_linux->exit                                            = adl_os.exit;
    process_linux->exit_group                                      = adl_os.exit_group;
    process_linux->fork                                            = adl_os.fork;
    process_linux->vfork                                           = adl_os.vfork;
    process_linux->getcpu                                          = adl_os.getcpu;
    process_linux->getegid                                         = adl_os.getegid;
    process_linux->geteuid                                         = adl_os.geteuid;
    process_linux->getgid                                          = adl_os.getgid;
    process_linux->getgroups                                       = adl_os.getgroups;
    process_linux->getpgid                                         = adl_os.getpgid;
    process_linux->getpgrp                                         = adl_os.getpgrp;
    process_linux->getpid                                          = adl_os.getpid;
    process_linux->getppid                                         = adl_os.getppid;
    process_linux->getpriority                                     = adl_os.getpriority;
    process_linux->getresgid                                       = adl_os.getresgid;
    process_linux->getresuid                                       = adl_os.getresuid;
    process_linux->getrlimit                                       = adl_os.getrlimit;
    process_linux->getrusage                                       = adl_os.getrusage;
    process_linux->getsid                                          = adl_os.getsid;
    process_linux->get_thread_area                                 = adl_os.get_thread_area;
    process_linux->gettid                                          = adl_os.gettid;
    process_linux->getuid                                          = adl_os.getuid;
    process_linux->kill                                            = adl_os.kill;
    process_linux->pidfd_getfd                                     = adl_os.pidfd_getfd;
    process_linux->pidfd_open                                      = adl_os.pidfd_open;
    process_linux->prctl                                           = adl_os.prctl;
    process_linux->prlimit                                         = adl_os.prlimit;
    process_linux->process_madvise                                 = adl_os.process_madvise;
    process_linux->process_vm_readv                                = adl_os.process_vm_readv;
    process_linux->process_vm_writev                               = adl_os.process_vm_writev;
    process_linux->sched_getaffinity                               = adl_os.sched_getaffinity;
    process_linux->sched_getattr                                   = adl_os.sched_getattr;
    process_linux->sched_getparam                                  = adl_os.sched_getparam;
    process_linux->sched_get_priority_max                          = adl_os.sched_get_priority_max;
    process_linux->sched_get_priority_min                          = adl_os.sched_get_priority_min;
    process_linux->sched_getscheduler                              = adl_os.sched_getscheduler;
    process_linux->sched_rr_get_interval                           = adl_os.sched_rr_get_interval;
    process_linux->sched_setaffinity                               = adl_os.sched_setaffinity;
    process_linux->sched_setattr                                   = adl_os.sched_setattr;
    process_linux->sched_setparam                                  = adl_os.sched_setparam;
    process_linux->sched_setscheduler                              = adl_os.sched_setscheduler;
    process_linux->sched_yield                                     = adl_os.sched_yield;
    process_linux->setgid                                          = adl_os.setgid;
    process_linux->setgroups                                       = adl_os.setgroups;
    process_linux->initgroups                                      = adl_os.initgroups;
    process_linux->setns                                           = adl_os.setns;
    process_linux->setpgid                                         = adl_os.setpgid;
    process_linux->setpriority                                     = adl_os.setpriority;
    process_linux->setregid                                        = adl_os.setregid;
    process_linux->setresgid                                       = adl_os.setresgid;
    process_linux->setresuid                                       = adl_os.setresuid;
    process_linux->setreuid                                        = adl_os.setreuid;
    process_linux->setrlimit                                       = adl_os.setrlimit;
    process_linux->setsid                                          = adl_os.setsid;
    process_linux->set_thread_area                                 = adl_os.set_thread_area;
    process_linux->set_tid_address                                 = adl_os.set_tid_address;
    process_linux->setuid                                          = adl_os.setuid;
    process_linux->seteuid                                         = adl_os.seteuid;
    process_linux->setegid                                         = adl_os.setegid;
    process_linux->tgkill                                          = adl_os.tgkill;
    process_linux->unshare                                         = adl_os.unshare;
    process_linux->wait                                            = adl_os.wait;
    process_linux->waitpid                                         = adl_os.waitpid;
    process_linux->waitid                                          = adl_os.waitid;
    process_linux->wait4                                           = adl_os.wait4;
    process_linux->wait3                                           = adl_os.wait3;
    process_linux->bpf                                             = adl_os.bpf;
    process_linux->modify_ldt                                      = adl_os.modify_ldt;
    process_linux->seccomp                                         = adl_os.seccomp;
    process_linux->kcmp                                            = adl_os.kcmp;
    process_linux->getenv                                          = adl_os.getenv;
    process_linux->setenv                                          = adl_os.setenv;
    process_linux->unsetenv                                        = adl_os.unsetenv;
    process_linux->clearenv                                        = adl_os.clearenv;
    process_linux->times                                           = adl_os.times;
    process_linux->acct                                            = adl_os.acct;



null_class:
    return;
}


void ADL_PROCESS_LINUX_fini(ADL_PROCESS_LINUX *process_linux)
{
    if(ADL_CHECK_NULL(process_linux))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(process_linux,0,sizeof(ADL_PROCESS_LINUX));

null_class:
    return;
}


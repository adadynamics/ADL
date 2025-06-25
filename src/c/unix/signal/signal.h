#ifndef ADL_SRC_UNIX_SIGNAL_SIGNAL_H
#define ADL_SRC_UNIX_SIGNAL_SIGNAL_H


#include "../unix.h"


#ifdef ADL_OS_UNIX




#ifndef ADL_SIGACTION
#define ADL_SIGACTION sigaction
#endif

#ifndef ADL_SIGPENDING
#define ADL_SIGPENDING sigpending
#endif

#ifndef ADL_SIGPROCMASK
#define ADL_SIGPROCMASK sigprocmask
#endif



#ifndef ADL_SIGSUSPEND
#define ADL_SIGSUSPEND sigsuspend
#endif

#ifndef ADL_SIGTIMEDWAIT
#define ADL_SIGTIMEDWAIT sigtimedwait
#endif

#ifndef ADL_SIGWAITINFO
#define ADL_SIGWAITINFO sigwaitinfo
#endif


#ifndef ADL_SIGNAL
#define ADL_SIGNAL signal
#endif


___adl_linux_std___
___adl_syscall___

#ifndef ADL_PIDFD_SEND_SIGNAL
#define ADL_PIDFD_SEND_SIGNAL pidfd_send_signal
#endif

___adl_end_syscall___

#ifndef ADL_EVENTFD
#define ADL_EVENTFD eventfd
#endif


#ifndef ADL_SIGNALFD
#define ADL_SIGNALFD signalfd
#endif


___adl_end_linux___

#ifndef ADL_SIGALTSTACK
#define ADL_SIGALTSTACK sigaltstack
#endif




ADL_RESULT adl_sys_sigaction(int signum,const struct sigaction *newact,struct sigaction *oldact);
ADL_RESULT adl_sys_sigpending(sigset_t *set);
ADL_RESULT adl_sys_sigprocmask(int how,const sigset_t *newset,sigset_t *oldset);
ADL_RESULT adl_sys_sigsuspend(const sigset_t *mask);
ADL_RESULT adl_sys_sigtimedwait(const sigset_t *set,siginfo_t *info,const struct timespec *timeout);
ADL_RESULT adl_sys_sigwaitinfo(const sigset_t *set,siginfo_t *info);
ADL_RESULT adl_sys_signal(int signum,void (*handler)(int));
ADL_RESULT adl_sys_pidfd_send_signal(int pidfd,int sig,siginfo_t *info,unsigned int flags);
ADL_RESULT adl_sys_eventfd(unsigned int initval,int flags);
ADL_RESULT adl_sys_signalfd(int fd,const sigset_t *mask,int flags);
ADL_RESULT adl_sys_sigaltstack(const stack_t *newstack,stack_t *oldstack);




#endif


#endif

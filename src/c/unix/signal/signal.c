#include "signal.h"



#ifdef ADL_OS_UNIX





/*

                SIGNALS

*/



/*

ADL_RESULT adl_sys_sigaction(int signum,const struct sigaction *newact,struct sigaction *oldact)

            a wrapper for sigaction system call on unix systems

            INPUT  :(int signum,const struct sigaction *newact,struct sigaction *oldact)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sigaction(int signum,const struct sigaction *newact,struct sigaction *oldact)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGACTION(signum,newact,oldact);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sigpending(sigset_t *set)

            a wrapper for sigpending system call on unix systems

            INPUT  :(sigset_t *set)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sigpending(sigset_t *set)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGPENDING(set);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_sigprocmask(int how,const sigset_t *newset,sigset_t *oldset)

            a wrapper for sigprocmask system call on unix systems

            INPUT  :(int how,const sigset_t *newset,sigset_t *oldset)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sigprocmask(int how,const sigset_t *newset,sigset_t *oldset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGPROCMASK(how,newset,oldset);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sigsuspend(const sigset_t *mask)

            a wrapper for sigsuspend system call on unix systems

            INPUT  :(const sigset_t *mask)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sigsuspend(const sigset_t *mask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGSUSPEND(mask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sigtimedwait(const sigset_t *set,siginfo_t *info,const struct timespec *timeout)

            a wrapper for sigtimedwait system call on unix systems

            INPUT  :(const sigset_t *set,siginfo_t *info,const struct timespec *timeout)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sigtimedwait(const sigset_t *set,siginfo_t *info,const struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGTIMEDWAIT(set,info,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_sigwaitinfo(const sigset_t *set,siginfo_t *info)

            a wrapper for sigwaitinfo system call on unix systems

            INPUT  :(const sigset_t *set,siginfo_t *info)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sigwaitinfo(const sigset_t *set,siginfo_t *info)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGWAITINFO(set,info);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_signal(int signum,void (*handler)(int))

            a wrapper for signal system call on unix systems

            INPUT  :(int signum,void (*handler)(int))
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_signal(int signum,void (*handler)(int))
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_SIGNAL(signum,handler);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_pidfd_send_signal(int pidfd,int sig,siginfo_t *info,unsigned int flags)

            a wrapper for pidfd_send_signal  system call on unix systems

            INPUT  :(int pidfd,int sig,siginfo_t *info,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___
___adl_syscall___

ADL_RESULT adl_sys_pidfd_send_signal(int pidfd,int sig,siginfo_t *info,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIDFD_SEND_SIGNAL(pidfd,sig,info,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___





/*

ADL_RESULT adl_sys_eventfd(unsigned int initval,int flags)

            a wrapper for eventfd system call on unix systems

            INPUT  :(unsigned int initval,int flags
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_eventfd(unsigned int initval,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EVENTFD(initval,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_signalfd(int fd,const sigset_t *mask,int flags)

            a wrapper for signalfd system call on unix systems

            INPUT  :(int fd,const sigset_t *mask,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_signalfd(int fd,const sigset_t *mask,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGNALFD(fd,mask,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

ADL_RESULT adl_sys_sigaltstack(const stack_t *newstack,stack_t *oldstack)

            a wrapper for sigaltstack system call on unix systems

            INPUT  :(const stack_t *newstack,stack_t *oldstack)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sigaltstack(const stack_t *newstack,stack_t *oldstack)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGALTSTACK(newstack,oldstack);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





#endif

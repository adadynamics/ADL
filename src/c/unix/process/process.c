#include "process.h"


#ifdef ADL_OS_UNIX




/*

                PROCESS MANAGEMENT

*/




/*

ADL_RESULT adl_sys_capget(cap_user_header_t hdrp,cap_user_data_t datap)

            a wrapper for capget system call on unix systems

            INPUT  :(cap_user_header_t hdrp,cap_user_data_t datap)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

___adl_syscall___

ADL_RESULT adl_sys_capget(cap_user_header_t hdrp,cap_user_data_t datap)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CAPGET(hdrp,datap);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

ADL_RESULT adl_sys_capset(cap_user_header_t hdrp,const cap_user_data_t datap)

            a wrapper for capset system call on unix systems

            INPUT  :(cap_user_header_t hdrp,const cap_user_data_t datap)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_capset(cap_user_header_t hdrp,const cap_user_data_t datap)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CAPSET(hdrp,datap);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_clone3(struct clone_args *cl_args,size_t size)

            a wrapper for clone3 system call on unix systems

            INPUT  :(struct clone_args *cl_args,size_t size)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_clone3(struct clone_args *cl_args,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLONE3(cl_args,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___





/*

ADL_RESULT adl_sys_clone(int (*fn)(void *),void *stack,int flags,void *arg,pid_t *parent_tid,void *tls,pid_t *child_tid)

            a wrapper for clone system call on unix systems

            INPUT  :(int (*fn)(void *),void *stack,int flags,void *arg,pid_t *parent_tid,void *tls,pid_t *child_tid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_clone(int (*fn)(void *),void *stack,int flags,void *arg,pid_t *parent_tid,void *tls,pid_t *child_tid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLONE(fn,stack,flags,arg,parent_tid,tls,child_tid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/*

ADL_RESULT adl_sys_execve(const char *pathname, char *const argv[],char *const envp[])

            a wrapper for execve system call on unix systems

            INPUT  :(const char *pathname, char *const argv[],char *const envp[])
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_execve(const char *pathname, char *const argv[],char *const envp[])
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EXECVE(pathname,argv,envp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_execveat(int dirfd,const char *pathname, char *const argv[],char *const envp[],int flags)

            a wrapper for execveat system call on unix systems

            INPUT  :(int dirfd,const char *pathname, char *const argv[],char *const envp[],int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_execveat(int dirfd,const char *pathname, char *const argv[],char *const envp[],int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EXECVEAT(dirfd,pathname,argv,envp,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/*

ADL_RESULT adl_sys_exit(int status)

            a wrapper for exit system call on unix systems

            INPUT  :(int status)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_exit(int status)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_EXIT(status);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_exit_group(int status)

            a wrapper for exit_group system call on unix systems

            INPUT  :(int status)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

___adl_syscall___

ADL_RESULT adl_sys_exit_group(int status)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_EXIT_GROUP(status);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___

___adl_end_linux___





/*

ADL_RESULT adl_sys_fork()

            a wrapper for fork system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fork()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FORK();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_vfork()

            a wrapper for vfork system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_vfork()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_VFORK();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getcpu(unsigned int *cpu,unsigned int *node)

            a wrapper for getcpu system call on unix systems

            INPUT  :(unsigned int *cpu,unsigned int *node)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_getcpu(unsigned int *cpu,unsigned int *node)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETCPU(cpu,node);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

ADL_RESULT adl_sys_getegid()

            a wrapper for getegid system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getegid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETEGID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_geteuid()

            a wrapper for geteuid system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_geteuid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETEUID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getgid()

            a wrapper for getgid system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getgid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETGID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getgroups(int size,gid_t list[])

            a wrapper for getgrfoups system call on unix systems

            INPUT  :(int size,gid_t list[]
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getgroups(int size,gid_t list[])
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETGROUPS(size,list);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getpgid(pid_t pid)

            a wrapper for getpgid system call on unix systems

            INPUT  :(pid_t pid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getpgid(pid_t pid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPGID(pid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getpgrp()

            a wrapper for getpgrp system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getpgrp()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPGRP();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getpid()

            a wrapper for getpid system call on unix systems

            INPUT  :(
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getpid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getppid()

            a wrapper for getppid system call on unix systems

            INPUT  :(
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getppid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPPID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getpriority(int which,id_t who)

            a wrapper for getpriority system call on unix systems

            INPUT  :(int which,id_t who
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getpriority(int which,id_t who)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPRIORITY(which,who);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getresgid(gid_t *rgid,gid_t *egid,gid_t *sgid)

            a wrapper for getresgid system call on unix systems

            INPUT  :(gid_t *rgid,gid_t *egid,gid_t *sgid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getresgid(gid_t *rgid,gid_t *egid,gid_t *sgid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETRESGID(rgid,egid,sgid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getresuid(uid_t *ruid,uid_t *euid,uid_t *suid)

            a wrapper for getresuid system call on unix systems

            INPUT  :(uid_t *ruid,uid_t *euid,uid_t *suid
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getresuid(uid_t *ruid,uid_t *euid,uid_t *suid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETRESUID(ruid,euid,suid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_getrlimit(int resource,struct rlimit *rlim)

            a wrapper for getrlimit system call on unix systems

            INPUT  :(int resource,struct rlimit *rlim)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getrlimit(int resource,struct rlimit *rlim)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETRLIMIT(resource,rlim);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_getrusage(int who,struct rusage *usage)

            a wrapper for getrusage system call on unix systems

            INPUT  :(int who,struct rusage *usage
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getrusage(int who,struct rusage *usage)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETRUSAGE(who,usage);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getsid(pid_t pid)

            a wrapper for getsid system call on unix systems

            INPUT  :(pid_t pid
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getsid(pid_t pid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETSID(pid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_get_thread_area(struct user_desc *u_info)

            a wrapper for get_thread_area system call on unix systems

            INPUT  :(struct user_desc *u_info)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

___adl_syscall___

ADL_RESULT adl_sys_get_thread_area(struct user_desc *u_info)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GET_THREAD_AREA(u_info);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___




/*

ADL_RESULT adl_sys_gettid()

            a wrapper for gettid system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_gettid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETTID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/*

ADL_RESULT adl_sys_getuid()

            a wrapper for getuid system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getuid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETUID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_kill(pid_t pid,int sig)

            a wrapper for kill system call on unix systems

            INPUT  :(pid_t pid,int sig)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_kill(pid_t pid,int sig)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_KILL(pid,sig);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_pidfd_getfd(int pidfd,int targetfd,unsigned int flags)

            a wrapper for pidfd_getfd system call on unix systems

            INPUT  :(int pidfd,int targetfd,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

___adl_syscall___

ADL_RESULT adl_sys_pidfd_getfd(int pidfd,int targetfd,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIDFD_GETFD(pidfd,targetfd,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_pidfd_open(pid_t pid,unsigned int flags)

            a wrapper for pidfd_open system call on unix systems

            INPUT  :(pid_t pid,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pidfd_open(pid_t pid,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIDFD_OPEN(pid,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___




/*

ADL_RESULT adl_sys_prctl(int op,unsigned long arg2,unsigned long arg3,unsigned long arg4, unsigned long arg5)

            a wrapper for prctl system call on unix systems

            INPUT  :(int op,unsigned long arg2,unsigned long arg3,unsigned long arg4, unsigned long arg5)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_prctl(int op,unsigned long arg2,unsigned long arg3,unsigned long arg4, unsigned long arg5)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PRCTL(op,arg2,arg3,arg4,arg5);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_prlimit(pid_t pid, int resource,const struct rlimit *new_limit,struct rlimit *old_limit)

            a wrapper for prlimit system call on unix systems

            INPUT  :(pid_t pid, int resource,const struct rlimit *new_limit,struct rlimit *old_limit)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_prlimit(pid_t pid, int resource,const struct rlimit *new_limit,struct rlimit *old_limit)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PRLIMIT(pid,resource,new_limit,old_limit);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_process_madvise(int pidfd,const struct iovec *iovec,size_t n,int advice,unsigned int flags)

            a wrapper for process system call on unix systems

            INPUT  :(int pidfd,const struct iovec *iovec,size_t n,int advice,unsigned int flags)

            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_process_madvise(int pidfd,const struct iovec *iovec,size_t n,int advice,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PROCESS_MADVISE(pidfd,iovec,n,advice,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_process_vm_readv(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)

            a wrapper for process_vm_readv system call on unix systems

            INPUT  :(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)

            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_process_vm_readv(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PROCESS_VM_READV(pid,local_iov,liovcnt,remote_iov,riovcnt,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_process_vm_writev(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)

            a wrapper for process_vm_writev system call on unix systems

            INPUT  :(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_process_vm_writev(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PROCESS_VM_WRITEV(pid,local_iov,liovcnt,remote_iov,riovcnt,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sched_getaffinity(pid_t pid,size_t cpusetsize,cpu_set_t *mask)

            a wrapper for sched_getaffinity system call on unix systems

            INPUT  :(pid_t pid,size_t cpusetsize,cpu_set_t *mask)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sched_getaffinity(pid_t pid,size_t cpusetsize,cpu_set_t *mask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GETAFFINITY(pid,cpusetsize,mask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sched_getattr(pid_t pid,struct sched_attr *attr,unsigned int size, unsigned int flags)

            a wrapper for sched_getattr system call on unix systems

            INPUT  :(pid_t pid,struct sched_attr *attr,unsigned int size, unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_syscall___

ADL_RESULT adl_sys_sched_getattr(pid_t pid,struct sched_attr *attr,unsigned int size, unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GETATTR(pid,attr,size,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___

___adl_end_linux___





/*

ADL_RESULT adl_sys_sched_getparam(pid_t pid,struct sched_param *param)

            a wrapper for sched_getparam system call on unix systems

            INPUT  :(pid_t pid,struct sched_param *param)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sched_getparam(pid_t pid,struct sched_param *param)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GETPARAM(pid,param);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sched_get_priority_max(int policy)

            a wrapper for sched_get_priority_max system call on unix systems

            INPUT  :(int policy)

            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sched_get_priority_max(int policy)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GET_PRIORITY_MAX(policy);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sched_get_priority_min(int policy)

            a wrapper for sched_get_priority_min system call on unix systems

            INPUT  :(int policy)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sched_get_priority_min(int policy)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GET_PRIORITY_MIN(policy);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sched_getscheduler(pid_t pid)

            a wrapper for sched_getscheduler system call on unix systems

            INPUT  :(pid_t pid
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sched_getscheduler(pid_t pid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GETSCHEDULER(pid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sched_rr_get_interval(pid_t pid, struct timespec *tp)

            a wrapper for sched_rr_get_interval system call on unix systems

            INPUT  :(pid_t pid, struct timespec *tp)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sched_rr_get_interval(pid_t pid, struct timespec *tp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_RR_GET_INTERVAL(pid,tp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sched_setaffinity(pid_t pid,size_t cpusetsize,const cpu_set_t *mask)

            a wrapper for sched_setaffinity system call on unix systems

            INPUT  :(pid_t pid,size_t cpusetsize,const cpu_set_t *mask)


        
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_sched_setaffinity(pid_t pid,size_t cpusetsize,const cpu_set_t *mask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_SETAFFINITY(pid,cpusetsize,mask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sched_setattr(pid_t pid, struct sched_attr *attr,unsigned int flags)

            a wrapper for sched_setattr system call on unix systems

            INPUT  :(pid_t pid, struct sched_attr *attr,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_syscall___

ADL_RESULT adl_sys_sched_setattr(pid_t pid, struct sched_attr *attr,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_SETATTR(pid,attr,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___

___adl_end_linux___




/*

ADL_RESULT adl_sys_sched_setparam(pid_t pid,const struct sched_param *param)

            a wrapper for sched_setparam system call on unix systems

            INPUT  :(pid_t pid,const struct sched_param *param)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sched_setparam(pid_t pid,const struct sched_param *param)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_SETPARAM(pid,param);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sched_setscheduler(pid_t pid, int policy,const struct sched_param *param)

            a wrapper for sched_setscheduler system call on unix systems

            INPUT  :(pid_t pid, int policy,const struct sched_param *param)

            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sched_setscheduler(pid_t pid, int policy,const struct sched_param *param)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_SETSCHEDULER(pid,policy,param);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sched_yield()

            a wrapper for sched_yield system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sched_yield()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_YIELD();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setgid(gid_t gid)

            a wrapper for setgid system call on unix systems

            INPUT  :(gid_t gid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setgid(gid_t gid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETGID(gid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setgroups(size_t size,const gid_t *list)

            a wrapper for setgroups system call on unix systems

            INPUT  :(size_t size,const gid_t *list)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setgroups(size_t size,const gid_t *list)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETGROUPS(size,list);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






ADL_RESULT adl_lib_initgroups(const char *user,gid_t group)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INITGROUPS(user,group);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setns(int fd,int nstype)

            a wrapper for setns system call on unix systems

            INPUT  :(int fd,int nstype)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_setns(int fd,int nstype)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETNS(fd,nstype);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

ADL_RESULT adl_sys_setpgid(pid_t pid, pid_t pgid)

            a wrapper for  setpgid system call on unix systems

            INPUT  :(pid_t pid, pid_t pgid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setpgid(pid_t pid, pid_t pgid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETPGID(pid,pgid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setpriority(int which, id_t who, int prio)

            a wrapper for setpriority system call on unix systems

            INPUT  :(int which, id_t who, int prio)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setpriority(int which, id_t who, int prio)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETPRIORITY(which,who,prio);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setregid(gid_t rgid, gid_t egid)

            a wrapper for setregid system call on unix systems

            INPUT  :(gid_t rgid, gid_t egid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setregid(gid_t rgid, gid_t egid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETREGID(rgid,egid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setresgid(gid_t rgid,gid_t egid,gid_t sgid)

            a wrapper for setresgid system call on unix systems

            INPUT  :(gid_t rgid,gid_t egid,gid_t sgid
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setresgid(gid_t rgid,gid_t egid,gid_t sgid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETRESGID(rgid,egid,sgid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setresuid(uid_t ruid,uid_t euid,uid_t suid)

            a wrapper for setresuid system call on unix systems

            INPUT  :(uid_t ruid,uid_t euid,uid_t suid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setresuid(uid_t ruid,uid_t euid,uid_t suid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETRESUID(ruid,euid,suid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setreuid(uid_t ruid,uid_t euid)

            a wrapper for setreuid system call on unix systems

            INPUT  :(uid_t ruid,uid_t euid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setreuid(uid_t ruid,uid_t euid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETREUID(ruid,euid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setrlimit(int resource,const struct rlimit *rlim)

            a wrapper for  setrlimit system call on unix systems

            INPUT  :(int resource,const struct rlimit *rlim)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setrlimit(int resource,const struct rlimit *rlim)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETRLIMIT(resource,rlim);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setsid(void)

            a wrapper for setsid system call on unix systems

            INPUT  :(void)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setsid(void)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETSID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_set_thread_area(struct user_desc *u_info)

            a wrapper for set_thread_area system call on unix systems

            INPUT  :(struct user_desc *u_info)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

___adl_syscall___

ADL_RESULT adl_sys_set_thread_area(struct user_desc *u_info)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SET_THREAD_AREA(u_info);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_set_tid_address(int *tidptr)

            a wrapper for set_tid_address system call on unix systems

            INPUT  :(int *tidptr)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_set_tid_address(int *tidptr)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SET_TID_ADDRESS(tidptr);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

ADL_RESULT adl_sys_setuid(uid_t uid)

            a wrapper for setuid system call on unix systems

            INPUT  :(uid_t uid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_syscall___

ADL_RESULT adl_sys_setuid(uid_t uid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETUID(uid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_sys_seteuid(uid_t uid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETEUID(uid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_sys_setegid(gid_t gid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETEGID(gid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

ADL_RESULT adl_sys_tgkill(pid_t tgid,pid_t tid,int sig)

            a wrapper for tgkill system call on unix systems

            INPUT  :(pid_t tgid,pid_t tid,int sig)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_tgkill(pid_t tgid,pid_t tid,int sig)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_TGKILL(tgid,tid,sig);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_unshare(int flags)

            a wrapper for unshare system call on unix systems

            INPUT  :(int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_unshare(int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UNSHARE(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





ADL_RESULT adl_sys_wait(int *status)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WAIT(status);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





ADL_RESULT adl_sys_waitpid(pid_t pid,int *status,int options)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WAITPID(pid,status,options);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





ADL_RESULT adl_sys_waitid(idtype_t idtype,id_t id,siginfo_t *info,int options)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WAITID(idtype,id,info,options);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_wait4(pid_t pid,int *wstatus,int options,struct rusage *rusage)

            a wrapper for wait4 system call on unix systems

            INPUT  :(pid_t pid,int *wstatus,int options,struct rusage *rusage)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_wait4(pid_t pid,int *wstatus,int options,struct rusage *rusage)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WAIT4(pid,wstatus,options,rusage);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_wait3(int *wstatus,int options,struct rusage *rusage)

            a wrapper for wait3 system call on unix systems

            INPUT  :(int *wstatus,int options,struct rusage *rusage)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_wait3(int *wstatus,int options,struct rusage *rusage)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WAIT3(wstatus,options,rusage);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_bpf(int cmd,union bpf_attr *attr,unsigned int size)

            a wrapper for bpf  system call on unix systems

            INPUT  :(int cmd,union bpf_attr *attr,unsigned int size)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_bpf(int cmd,union bpf_attr *attr,unsigned int size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_BPF(cmd,attr,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_modify_ldt(int func,void *ptr,unsigned long bytecount)

            a wrapper for modify_ldt system call on unix systems

            INPUT  :(int func,void *ptr,unsigned long bytecount)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_syscall___

ADL_RESULT adl_sys_modify_ldt(int func,void *ptr,unsigned long bytecount)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MODIFY_LDT(func,ptr,bytecount);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_seccomp(unsigned int operation,unsigned int flags,void *args)

            a wrapper for seccomp system call on unix systems

            INPUT  :(unsigned int operation,unsigned int flags,void *args)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_seccomp(unsigned int operation,unsigned int flags,void *args)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SECCOMP(operation,flags,args);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_kcmp(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)

            a wrapper for kcmp system call on unix systems

            INPUT  :(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_kcmp(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_KCMP(pid1,pid2,type,idx1,idx2);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___

___adl_end_linux___




/*

ADL_RESULT adl_sys_kcmp(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)

            a wrapper for kcmp system call on unix systems

            INPUT  :(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_getenv(const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETENV(name);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_kcmp(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)

            a wrapper for kcmp system call on unix systems

            INPUT  :(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_setenv(const char *name,const char *value,int overwrite)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETENV(name,value,overwrite);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_kcmp(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)

            a wrapper for kcmp system call on unix systems

            INPUT  :(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_unsetenv(const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UNSETENV(name);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_kcmp(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)

            a wrapper for kcmp system call on unix systems

            INPUT  :(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_clearenv(void)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLEARENV();
    if(ADL_CHECK_NOT_EQUAL(rdr_ret,0))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






ADL_RESULT adl_sys_times(struct tms *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_TIMES(buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






ADL_RESULT adl_sys_acct(const char *acctfile)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_ACCT(acctfile);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






#endif



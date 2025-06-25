#ifndef ADL_SRC_UNIX_PROCESS_PROCESS_H
#define ADL_SRC_UNIX_PROCESS_PROCESS_H



#include "../unix.h"

#ifdef ADL_OS_UNIX





#ifndef ADL_CAPGET
#define ADL_CAPGET capget
#endif

#ifndef ADL_CAPSET
#define ADL_CAPSET capset
#endif

#ifndef ADL_CLONE3
#define ADL_CLONE3 clone3
#endif

___adl_end_syscall___

#ifndef ADL_CLONE
#define ADL_CLONE clone
#endif

___adl_end_linux___

#ifndef ADL_EXECVE
#define ADL_EXECVE execve
#endif

___adl_linux_std___

#ifndef ADL_EXECVEAT
#define ADL_EXECVEAT execveat
#endif

___adl_end_linux___

#ifndef ADL_EXIT
#define ADL_EXIT exit
#endif

___adl_linux_std___
___adl_syscall___

#ifndef ADL_EXIT_GROUP
#define ADL_EXIT_GROUP exit_group
#endif

___adl_end_syscall___
___adl_end_linux___

#ifndef ADL_FORK
#define ADL_FORK fork
#endif

#ifndef ADL_VFORK
#define ADL_VFORK vfork
#endif

___adl_linux_std___

#ifndef ADL_GETCPU
#define ADL_GETCPU getcpu
#endif

___adl_end_linux___

#ifndef ADL_GETEGID
#define ADL_GETEGID getegid
#endif

#ifndef ADL_GETEUID
#define ADL_GETEUID geteuid
#endif

#ifndef ADL_GETGID
#define ADL_GETGID getgid
#endif

#ifndef ADL_GETGROUPS
#define ADL_GETGROUPS getgroups
#endif

#ifndef ADL_GETPGID
#define ADL_GETPGID getpgid
#endif

#ifndef ADL_GETPGRP
#define ADL_GETPGRP getpgrp
#endif

#ifndef ADL_GETPID
#define ADL_GETPID getpid
#endif

#ifndef ADL_GETPPID
#define ADL_GETPPID getppid
#endif

#ifndef ADL_GETPRIORITY
#define ADL_GETPRIORITY getpriority
#endif

#ifndef ADL_GETRESGID
#define ADL_GETRESGID getresgid
#endif

#ifndef ADL_GETRESUID
#define ADL_GETRESUID getresuid
#endif

#ifndef ADL_GETRLIMIT
#define ADL_GETRLIMIT getrlimit
#endif

#ifndef ADL_GETRUSAGE
#define ADL_GETRUSAGE getrusage
#endif

#ifndef ADL_GETSID
#define ADL_GETSID getsid
#endif

___adl_linux_std___
___adl_syscall___

#ifndef ADL_GET_THREAD_AREA
#define ADL_GET_THREAD_AREA get_thread_area
#endif

___adl_end_syscall___

#ifndef ADL_GETTID
#define ADL_GETTID gettid
#endif

___adl_end_linux___

#ifndef ADL_GETUID
#define ADL_GETUID getuid
#endif

#ifndef ADL_KILL
#define ADL_KILL kill
#endif



___adl_linux_std___
___adl_syscall___

#ifndef ADL_PIDFD_GETFD
#define ADL_PIDFD_GETFD pidfd_getfd
#endif

#ifndef ADL_PIDFD_OPEN
#define ADL_PIDFD_OPEN pidfd_open
#endif

___adl_end_syscall___

#ifndef ADL_PRCTL
#define ADL_PRCTL prctl
#endif


#ifndef ADL_PRLIMIT
#define ADL_PRLIMIT prlimit
#endif

#ifndef ADL_PROCESS_MADVISE
#define ADL_PROCESS_MADVISE process_madvise
#endif


#ifndef ADL_PROCESS_VM_READV
#define ADL_PROCESS_VM_READV process_vm_readv
#endif

#ifndef ADL_PROCESS_VM_WRITEV
#define ADL_PROCESS_VM_WRITEV process_vm_writev
#endif

#ifndef ADL_SCHED_GETAFFINITY
#define ADL_SCHED_GETAFFINITY sched_getaffinity
#endif

___adl_syscall___

#ifndef ADL_SCHED_GETATTR
#define ADL_SCHED_GETATTR sched_getattr
#endif

___adl_end_syscall___
___adl_end_linux___


#ifndef ADL_SCHED_GETPARAM
#define ADL_SCHED_GETPARAM sched_getparam
#endif

#ifndef ADL_SCHED_GET_PRIORITY_MAX
#define ADL_SCHED_GET_PRIORITY_MAX sched_get_priority_max
#endif

#ifndef ADL_SCHED_GET_PRIORITY_MIN
#define ADL_SCHED_GET_PRIORITY_MIN sched_get_priority_min
#endif

#ifndef ADL_SCHED_GETSCHEDULER
#define ADL_SCHED_GETSCHEDULER sched_getscheduler
#endif

#ifndef ADL_SCHED_RR_GET_INTERVAL
#define ADL_SCHED_RR_GET_INTERVAL sched_rr_get_interval
#endif

___adl_linux_std___

#ifndef ADL_SCHED_SETAFFINITY
#define ADL_SCHED_SETAFFINITY sched_setaffinity
#endif


___adl_syscall___

#ifndef ADL_SCHED_SETATTR
#define ADL_SCHED_SETATTR sched_setattr
#endif

___adl_end_syscall___
___adl_end_linux___

#ifndef ADL_SCHED_SETPARAM
#define ADL_SCHED_SETPARAM sched_setparam
#endif

#ifndef ADL_SCHED_SETSCHEDULER
#define ADL_SCHED_SETSCHEDULER sched_setscheduler
#endif

#ifndef ADL_SCHED_YIELD
#define ADL_SCHED_YIELD sched_yield
#endif

#ifndef ADL_SETGID
#define ADL_SETGID setgid
#endif

#ifndef ADL_SETGROUPS
#define ADL_SETGROUPS setgroups
#endif


#ifndef ADL_INITGROUPS
#define ADL_INITGROUPS initgroups
#endif


___adl_linux_std___

#ifndef ADL_SETNS
#define ADL_SETNS setns
#endif

___adl_end_linux___

#ifndef ADL_SETPGID
#define ADL_SETPGID setpgid
#endif

#ifndef ADL_SETPRIORITY
#define ADL_SETPRIORITY setpriority
#endif

#ifndef ADL_SETREGID
#define ADL_SETREGID setregid
#endif

#ifndef ADL_SETRESGID
#define ADL_SETRESGID setresgid
#endif

#ifndef ADL_SETRESUID
#define ADL_SETRESUID setresuid
#endif

#ifndef ADL_SETREUID
#define ADL_SETREUID setreuid
#endif

#ifndef ADL_SETRLIMIT
#define ADL_SETRLIMIT setrlimit
#endif

#ifndef ADL_SETSID
#define ADL_SETSID setsid
#endif

___adl_linux_std___
___adl_syscall___

#ifndef ADL_SET_THREAD_AREA
#define ADL_SET_THREAD_AREA set_thread_area
#endif

#ifndef ADL_SET_TID_ADDRESS
#define ADL_SET_TID_ADDRESS set_tid_address
#endif

___adl_syscall___
___adl_end_linux___


#ifndef ADL_SETUID
#define ADL_SETUID setuid
#endif



#ifndef ADL_SETEUID
#define ADL_SETEUID seteuid
#endif



#ifndef ADL_SETEGID
#define ADL_SETEGID setegid
#endif



___adl_linux_std___

#ifndef ADL_TGKILL
#define ADL_TGKILL tgkill
#endif


#ifndef ADL_UNSHARE
#define ADL_UNSHARE unshare
#endif

___adl_end_linux___

#ifndef ADL_WAIT
#define ADL_WAIT wait
#endif


#ifndef ADL_WAITPID
#define ADL_WAITPID waitpid
#endif

#ifndef ADL_WAITID
#define ADL_WAITID waitid
#endif


#ifndef ADL_WAIT4
#define ADL_WAIT4 wait4
#endif

#ifndef ADL_WAIT3
#define ADL_WAIT3 wait3
#endif


___adl_linux_std___

#ifndef ADL_BPF
#define ADL_BPF bpf
#endif

___adl_syscall___

#ifndef ADL_MODIFY_LDT
#define ADL_MODIFY_LDT modify_ldt
#endif

#ifndef ADL_SECCOMP
#define ADL_SECCOMP seccomp
#endif

#ifndef ADL_KCMP
#define ADL_KCMP kcmp
#endif

___adl_end_syscall___
___adl_end_linux___


#ifndef ADL_GETENV
#define ADL_GETENV getenv
#endif



#ifndef ADL_SETENV
#define ADL_SETENV setenv
#endif


#ifndef ADL_UNSETENV
#define ADL_UNSETENV unsetenv
#endif


#ifndef ADL_CLEARENV
#define ADL_CLEARENV clearenv
#endif



#ifndef ADL_TIMES 
#define ADL_TIMES times
#endif


#ifndef ADL_ACCT
#define ADL_ACCT acct
#endif







ADL_RESULT adl_sys_capget(cap_user_header_t hdrp,cap_user_data_t datap);
ADL_RESULT adl_sys_capset(cap_user_header_t hdrp,const cap_user_data_t datap);
ADL_RESULT adl_sys_clone3(struct clone_args *cl_args,size_t size);
ADL_RESULT adl_sys_clone(int (*fn)(void *),void *stack,int flags,void *arg,pid_t *parent_tid,void *tls,pid_t *child_tid);
ADL_RESULT adl_sys_execve(const char *pathname, char *const argv[],char *const envp[]);
ADL_RESULT adl_sys_execveat(int dirfd,const char *pathname, char *const argv[],char *const envp[],int flags);
ADL_RESULT adl_sys_exit(int status);
ADL_RESULT adl_sys_exit_group(int status);
ADL_RESULT adl_sys_fork();
ADL_RESULT adl_sys_vfork();
ADL_RESULT adl_sys_getcpu(unsigned int *cpu,unsigned int *node);
ADL_RESULT adl_sys_getegid();
ADL_RESULT adl_sys_geteuid();
ADL_RESULT adl_sys_getgid();
ADL_RESULT adl_sys_getgroups(int size,gid_t list[]);
ADL_RESULT adl_sys_getpgid(pid_t pid);
ADL_RESULT adl_sys_getpgrp();
ADL_RESULT adl_sys_getpid();
ADL_RESULT adl_sys_getppid();
ADL_RESULT adl_sys_getpriority(int which,id_t who);
ADL_RESULT adl_sys_getresgid(gid_t *rgid,gid_t *egid,gid_t *sgid);
ADL_RESULT adl_sys_getresuid(uid_t *ruid,uid_t *euid,uid_t *suid);
ADL_RESULT adl_sys_getrlimit(int resource,struct rlimit *rlim);
ADL_RESULT adl_sys_getrusage(int who,struct rusage *usage);
ADL_RESULT adl_sys_getsid(pid_t pid);
ADL_RESULT adl_sys_get_thread_area(struct user_desc *u_info);
ADL_RESULT adl_sys_gettid();
ADL_RESULT adl_sys_getuid();
ADL_RESULT adl_sys_kill(pid_t pid,int sig);
ADL_RESULT adl_sys_pidfd_getfd(int pidfd,int targetfd,unsigned int flags);
ADL_RESULT adl_sys_pidfd_open(pid_t pid,unsigned int flags);
ADL_RESULT adl_sys_prctl(int op,unsigned long arg2,unsigned long arg3,unsigned long arg4, unsigned long arg5);
ADL_RESULT adl_sys_prlimit(pid_t pid, int resource,const struct rlimit *new_limit,struct rlimit *old_limit);
ADL_RESULT adl_sys_process_madvise(int pidfd,const struct iovec *iovec,size_t n,int advice,unsigned int flags);
ADL_RESULT adl_sys_process_vm_readv(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags);
ADL_RESULT adl_sys_process_vm_writev(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags);
ADL_RESULT adl_sys_sched_getaffinity(pid_t pid,size_t cpusetsize,cpu_set_t *mask);
ADL_RESULT adl_sys_sched_getattr(pid_t pid,struct sched_attr *attr,unsigned int size, unsigned int flags);
ADL_RESULT adl_sys_sched_getparam(pid_t pid,struct sched_param *param);
ADL_RESULT adl_sys_sched_get_priority_max(int policy);
ADL_RESULT adl_sys_sched_get_priority_min(int policy);
ADL_RESULT adl_sys_sched_getscheduler(pid_t pid);
ADL_RESULT adl_sys_sched_rr_get_interval(pid_t pid, struct timespec *tp);
ADL_RESULT adl_sys_sched_setaffinity(pid_t pid,size_t cpusetsize,const cpu_set_t *mask);
ADL_RESULT adl_sys_sched_setattr(pid_t pid, struct sched_attr *attr,unsigned int flags);
ADL_RESULT adl_sys_sched_setparam(pid_t pid,const struct sched_param *param);
ADL_RESULT adl_sys_sched_setscheduler(pid_t pid, int policy,const struct sched_param *param);
ADL_RESULT adl_sys_sched_yield();
ADL_RESULT adl_sys_setgid(gid_t gid);
ADL_RESULT adl_sys_setgroups(size_t size,const gid_t *list);
ADL_RESULT adl_lib_initgroups(const char *user,gid_t group);
ADL_RESULT adl_sys_setns(int fd,int nstype);
ADL_RESULT adl_sys_setpgid(pid_t pid, pid_t pgid);
ADL_RESULT adl_sys_setpriority(int which, id_t who, int prio);
ADL_RESULT adl_sys_setregid(gid_t rgid, gid_t egid);
ADL_RESULT adl_sys_setresgid(gid_t rgid,gid_t egid,gid_t sgid);
ADL_RESULT adl_sys_setresuid(uid_t ruid,uid_t euid,uid_t suid);
ADL_RESULT adl_sys_setreuid(uid_t ruid,uid_t euid);
ADL_RESULT adl_sys_setrlimit(int resource,const struct rlimit *rlim);
ADL_RESULT adl_sys_setsid(void);
ADL_RESULT adl_sys_set_thread_area(struct user_desc *u_info);
ADL_RESULT adl_sys_set_tid_address(int *tidptr);
ADL_RESULT adl_sys_setuid(uid_t uid);
ADL_RESULT adl_sys_seteuid(uid_t uid);
ADL_RESULT adl_sys_setegid(gid_t gid);
ADL_RESULT adl_sys_tgkill(pid_t tgid,pid_t tid,int sig);
ADL_RESULT adl_sys_unshare(int flags);
ADL_RESULT adl_sys_wait(int *status);
ADL_RESULT adl_sys_waitpid(pid_t pid,int *status,int options);
ADL_RESULT adl_sys_waitid(idtype_t idtype,id_t id,siginfo_t *info,int options);
ADL_RESULT adl_sys_wait4(pid_t pid,int *wstatus,int options,struct rusage *rusage);
ADL_RESULT adl_sys_wait3(int *wstatus,int options,struct rusage *rusage);
ADL_RESULT adl_sys_bpf(int cmd,union bpf_attr *attr,unsigned int size);
ADL_RESULT adl_sys_modify_ldt(int func,void *ptr,unsigned long bytecount);
ADL_RESULT adl_sys_seccomp(unsigned int operation,unsigned int flags,void *args);
ADL_RESULT adl_sys_kcmp(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2);
ADL_RESULT adl_lib_getenv(const char *name);
ADL_RESULT adl_lib_setenv(const char *name,const char *value,int overwrite);
ADL_RESULT adl_lib_unsetenv(const char *name);
ADL_RESULT adl_lib_clearenv(void);
ADL_RESULT adl_sys_times(struct tms *buf);
ADL_RESULT adl_sys_acct(const char *acctfile);





#endif



#endif

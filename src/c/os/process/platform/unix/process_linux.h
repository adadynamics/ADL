#ifndef ADL_SRC_OS_PROCESS_PROCESS_LINUX_H
#define ADL_SRC_OS_PROCESS_PROCESS_LINUX_H




#include "../os.h"


typedef struct ADL_PROCESS_LINUX
{

    ADL_RESULT (*capget)(cap_user_header_t hdrp,cap_user_data_t datap);
    ADL_RESULT (*capset)(cap_user_header_t hdrp,const cap_user_data_t datap);
    ADL_RESULT (*clone3)(struct clone_args *cl_args,size_t size);
    ADL_RESULT (*clone)(int (*fn)(void *),void *stack,int flags,void *arg,pid_t *parent_tid,void *tls,pid_t *child_tid);
    ADL_RESULT (*execve)(const char *pathname, char *const argv[],char *const envp[]);
    ADL_RESULT (*execveat)(int dirfd,const char *pathname, char *const argv[],char *const envp[],int flags);
    ADL_RESULT (*exit)(int status);
    ADL_RESULT (*exit_group)(int status);
    ADL_RESULT (*fork)();
    ADL_RESULT (*vfork)();
    ADL_RESULT (*getcpu)(unsigned int *cpu,unsigned int *node);
    ADL_RESULT (*getegid)();
    ADL_RESULT (*geteuid)();
    ADL_RESULT (*getgid)();
    ADL_RESULT (*getgroups)(int size,gid_t list[]);
    ADL_RESULT (*getpgid)(pid_t pid);
    ADL_RESULT (*getpgrp)();
    ADL_RESULT (*getpid)();
    ADL_RESULT (*getppid)();
    ADL_RESULT (*getpriority)(int which,id_t who);
    ADL_RESULT (*getresgid)(gid_t *rgid,gid_t *egid,gid_t *sgid);
    ADL_RESULT (*getresuid)(uid_t *ruid,uid_t *euid,uid_t *suid);
    ADL_RESULT (*getrlimit)(int resource,struct rlimit *rlim);
    ADL_RESULT (*getrusage)(int who,struct rusage *usage);
    ADL_RESULT (*getsid)(pid_t pid);
    ADL_RESULT (*get_thread_area)(struct user_desc *u_info);
    ADL_RESULT (*gettid)();
    ADL_RESULT (*getuid)();
    ADL_RESULT (*kill)(pid_t pid,int sig);
    ADL_RESULT (*pidfd_getfd)(int pidfd,int targetfd,unsigned int flags);
    ADL_RESULT (*pidfd_open)(pid_t pid,unsigned int flags);
    ADL_RESULT (*prctl)(int op,unsigned long arg2,unsigned long arg3,unsigned long arg4, unsigned long arg5);
    ADL_RESULT (*prlimit)(pid_t pid, int resource,const struct rlimit *new_limit,struct rlimit *old_limit);
    ADL_RESULT (*process_madvise)(int pidfd,const struct iovec *iovec,size_t n,int advice,unsigned int flags);
    ADL_RESULT (*process_vm_readv)(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags);
    ADL_RESULT (*process_vm_writev)(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags);
    ADL_RESULT (*sched_getaffinity)(pid_t pid,size_t cpusetsize,cpu_set_t *mask);
    ADL_RESULT (*sched_getattr)(pid_t pid,struct sched_attr *attr,unsigned int size, unsigned int flags);
    ADL_RESULT (*sched_getparam)(pid_t pid,struct sched_param *param);
    ADL_RESULT (*sched_get_priority_max)(int policy);
    ADL_RESULT (*sched_get_priority_min)(int policy);
    ADL_RESULT (*sched_getscheduler)(pid_t pid);
    ADL_RESULT (*sched_rr_get_interval)(pid_t pid, struct timespec *tp);
    ADL_RESULT (*sched_setaffinity)(pid_t pid,size_t cpusetsize,const cpu_set_t *mask);
    ADL_RESULT (*sched_setattr)(pid_t pid, struct sched_attr *attr,unsigned int flags);
    ADL_RESULT (*sched_setparam)(pid_t pid,const struct sched_param *param);
    ADL_RESULT (*sched_setscheduler)(pid_t pid, int policy,const struct sched_param *param);
    ADL_RESULT (*sched_yield)();
    ADL_RESULT (*setgid)(gid_t gid);
    ADL_RESULT (*setgroups)(size_t size,const gid_t *list);
    ADL_RESULT (*initgroups)(const char *user,gid_t group);
    ADL_RESULT (*setns)(int fd,int nstype);
    ADL_RESULT (*setpgid)(pid_t pid, pid_t pgid);
    ADL_RESULT (*setpriority)(int which, id_t who, int prio);
    ADL_RESULT (*setregid)(gid_t rgid, gid_t egid);
    ADL_RESULT (*setresgid)(gid_t rgid,gid_t egid,gid_t sgid);
    ADL_RESULT (*setresuid)(uid_t ruid,uid_t euid,uid_t suid);
    ADL_RESULT (*setreuid)(uid_t ruid,uid_t euid);
    ADL_RESULT (*setrlimit)(int resource,const struct rlimit *rlim);
    ADL_RESULT (*setsid)(void);
    ADL_RESULT (*set_thread_area)(struct user_desc *u_info);
    ADL_RESULT (*set_tid_address)(int *tidptr);
    ADL_RESULT (*setuid)(uid_t uid);
    ADL_RESULT (*seteuid)(uid_t uid);
    ADL_RESULT (*setegid)(gid_t gid);
    ADL_RESULT (*tgkill)(pid_t tgid,pid_t tid,int sig);
    ADL_RESULT (*unshare)(int flags);
    ADL_RESULT (*wait)(int *status);
    ADL_RESULT (*waitpid)(pid_t pid,int *status,int options);
    ADL_RESULT (*waitid)(idtype_t idtype,id_t id,siginfo_t *info,int options);
    ADL_RESULT (*wait4)(pid_t pid,int *wstatus,int options,struct rusage *rusage);
    ADL_RESULT (*wait3)(int *wstatus,int options,struct rusage *rusage);
    ADL_RESULT (*bpf)(int cmd,union bpf_attr *attr,unsigned int size);
    ADL_RESULT (*modify_ldt)(int func,void *ptr,unsigned long bytecount);
    ADL_RESULT (*seccomp)(unsigned int operation,unsigned int flags,void *args);
    ADL_RESULT (*kcmp)(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2);
    ADL_RESULT (*getenv)(const char *name);
    ADL_RESULT (*setenv)(const char *name,const char *value,int overwrite);
    ADL_RESULT (*unsetenv)(const char *name);
    ADL_RESULT (*clearenv)(void);
    ADL_RESULT (*times)(struct tms *buf);
    ADL_RESULT (*acct)(const char *acctfile);
}ADL_PROCESS_LINUX;



void ADL_PROCESS_LINUX_init(ADL_PROCESS_LINUX *process_linux);


void ADL_PROCESS_LINUX_fini(ADL_PROCESS_LINUX *process_linux);


#endif
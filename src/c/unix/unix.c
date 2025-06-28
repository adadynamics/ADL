

#include "file/file.h"
#include "ipc/ipc.h"
#include "memory/memory.h"
#include "net/net.h"
#include "process/process.h"
#include "signal/signal.h"
#include "sys/sys.h"
#include "thread/thread.h"
#include "time/time.h"
#include "user/user.h"



#ifdef ADL_OS_UNIX



int openat2(int dirfd,const char *pathname,struct open_how *how,size_t size)
{
    return syscall(SYS_openat2,dirfd,pathname,how,size);  
}


int faccessat2(int dirfd,const char *path,int mode,int flags)
{
    return syscall(SYS_faccessat2,dirfd,path,mode,flags);
}


int pivot_root(const char *new_root, const char *put_old)
{
    return syscall(SYS_pivot_root,new_root,put_old);
}


int io_setup(unsigned int nr_events,aio_context_t *ctx_id)
{
    return syscall(SYS_io_setup,nr_events,ctx_id);
}


int io_destroy(aio_context_t ctx_id)
{
    return syscall(SYS_io_destroy,ctx_id);
}


int io_getevents(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout)
{
    return syscall(SYS_io_getevents,ctx_id,min_nr,nr,events,timeout);
}


int io_submit(aio_context_t ctx_id, long nr, struct iocb **iocb)
{
    return syscall(SYS_io_submit,ctx_id,nr,iocb);
}


int io_cancel(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result)
{
    return syscall(SYS_io_cancel,ctx_id,iocb,result);
}


int lookup_dcookie(uint64_t cookie, char *buffer,size_t len)
{
    return syscall(SYS_lookup_dcookie,cookie,buffer,len);
}


int ioprio_set(int which,int who,int ioprio)
{
    return syscall(SYS_ioprio_set,which,who,ioprio);
}


int ioprio_get(int which,int who)
{
    return syscall(SYS_ioprio_get,which,who);
}


int mq_getsetattr(mqd_t mqdes,const struct mq_attr *newattr, struct mq_attr *oldattr)
{
    return syscall(SYS_mq_getsetattr, mqdes,newattr,oldattr);
}


int futex(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3)
{
    return syscall(SYS_futex,uaddr,futex_op,val,timeout,uaddr2,val3);
}


int get_robust_list(int pid,struct robust_list_head **head_ptr, size_t *len_ptr)
{
    return syscall(SYS_get_robust_list,pid,head_ptr,len_ptr);
}


int set_robust_list(struct robust_list_head *head,size_t len)
{
    return syscall(SYS_set_robust_list,head,len);
}


int capget(cap_user_header_t hdrp,cap_user_data_t datap)
{
    return syscall(SYS_capget,hdrp,datap);
}


int capset(cap_user_header_t hdrp,const cap_user_data_t datap)
{
    return syscall(SYS_capset,hdrp,datap);
}


long clone3(struct clone_args *cl_args, size_t size)
{
    return syscall(SYS_clone3,cl_args,size);
}


void exit_group(int status)
{
    syscall(SYS_exit_group,status);
}


int get_thread_area(struct user_desc *u_info)
{
    return syscall(SYS_get_thread_area,u_info);
}


int pidfd_getfd(int pidfd, int targetfd,unsigned int flags)
{
    return syscall(SYS_pidfd_getfd,pidfd,targetfd,flags);
}


int pidfd_open(pid_t pid,unsigned int flags)
{
    return syscall(SYS_pidfd_open,pid,flags);
}


int sched_getattr(pid_t pid,struct sched_attr *attr,unsigned int size,unsigned int flags)
{
    return syscall(SYS_sched_getattr,pid,attr,size,flags);
}


int sched_setattr(pid_t pid, struct sched_attr *attr,unsigned int flags)
{
    return syscall(SYS_sched_setattr,pid,attr,flags);
}

int set_thread_area(struct user_desc *u_info)
{
    return syscall(SYS_set_thread_area,u_info);
}


int set_tid_address(int *tidptr)
{
    return syscall(SYS_set_tid_address,tidptr);
}


int modify_ldt(int func, void *ptr,unsigned long bytecount)
{
    return syscall(SYS_modify_ldt,func,ptr,bytecount);
}


int seccomp(unsigned int operation,unsigned int flags,void *args)
{
    return syscall(SYS_seccomp,operation,flags,args);
}


int kcmp(pid_t pid1, pid_t pid2, int type,unsigned long idx1, unsigned long idx2)
{
    return syscall(SYS_kcmp,pid1,pid2,type,idx1,idx2);
}


int bpf(int cmd, union bpf_attr *attr, unsigned int size)
{
    return syscall(SYS_bpf,cmd,attr,size);
}


int pidfd_send_signal(int pidfd, int sig,siginfo_t *info, unsigned int flags)
{
    return syscall(SYS_pidfd_send_signal,pidfd,sig,info,flags);
}


int reboot(int magic,int magic2,int op,void *arg)
{
    return syscall(SYS_reboot,magic,magic2,op,arg);
}


int delete_module(const char *name,unsigned int flags)
{
    return syscall(SYS_delete_module,name,flags);
}


int init_module(void * module_image,unsigned long len,const char *param_values)
{
    return syscall(SYS_init_module,module_image,len,param_values);
}


int finit_module(int fd,const char *param_values,int flags)
{
    return syscall(SYS_finit_module,fd,param_values,flags);
}


int kexec_file_load(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags)
{
    return syscall(SYS_kexec_file_load,kernel_fd,initrd_fd,cmdline_len,cmdline,flags);
}


int kexec_load(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags)
{
    return syscall(SYS_kexec_load,entry,nr_segments,segments,flags);
}


int syslog(int type,char *bufp,int len)
{
    return syscall(SYS_syslog,type,bufp,len);
}


/*
int keyctl(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5)
{
    return syscall(SYS_keyctl,operation,arg2,arg3,arg4,arg5);
}
*/



int membarrier(int cmd,unsigned int flags,int cpu_id)
{
    return syscall(SYS_membarrier,cmd,flags,cpu_id);
}


int memfd_secret(unsigned int flags)
{
    return syscall(SYS_memfd_secret,flags);
}


int userfaultfd(int flags)
{
    return syscall(SYS_userfaultfd,flags);
}



void ADL_UNIX_Init(ADL_UNIX *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class->SocketInit                                      = adl_lib_SocketInit;
    class->SocketFini                                      = adl_lib_SocketFini;
    class->socket                                          = adl_sys_socket;
    class->socketpair                                      = adl_sys_socketpair;
    class->bind                                            = adl_sys_bind;
    class->connect                                         = adl_sys_connect;
    class->listen                                          = adl_sys_listen;
    class->accept                                          = adl_sys_accept;
    class->accept4                                         = adl_sys_accept4;
    class->recv                                            = adl_sys_recv;
    class->recvfrom                                        = adl_sys_recvfrom;
    class->recvmsg                                         = adl_sys_recvmsg;
    class->recvmmsg                                        = adl_sys_recvmmsg;
    class->send                                            = adl_sys_send;
    class->sendto                                          = adl_sys_sendto;
    class->sendmsg                                         = adl_sys_sendmsg;
    class->sendmmsg                                        = adl_sys_sendmmsg;
    class->shutdown                                        = adl_sys_shutdown;
    class->close                                           = adl_sys_close;
    class->getsockopt                                      = adl_sys_getsockopt;
    class->setsockopt                                      = adl_sys_setsockopt;
    class->getsockname                                     = adl_sys_getsockname;
    class->getpeername                                     = adl_sys_getpeername;
    class->getaddrinfo                                     = adl_lib_getaddrinfo;
    class->freeaddrinfo                                    = adl_lib_freeaddrinfo;
    class->getnameinfo                                     = adl_lib_getnameinfo;
    class->htons                                           = adl_lib_htons;
    class->htonl                                           = adl_lib_htonl;
    class->ntohs                                           = adl_lib_ntohs;
    class->ntohl                                           = adl_lib_ntohl;
    class->open                                            = adl_sys_open;
    class->creat                                           = adl_sys_creat;
    class->openat                                          = adl_sys_openat;
    class->openat2                                         = adl_sys_openat2;
    class->read                                            = adl_sys_read;
    class->write                                           = adl_sys_write;
    class->sendfile                                        = adl_sys_sendfile;
    class->close                                           = adl_sys_close;
    class->stat                                            = adl_sys_stat;
    class->fstat                                           = adl_sys_fstat;
    class->lstat                                           = adl_sys_lstat;
    class->fstatat                                         = adl_sys_fstatat;
    class->poll                                            = adl_sys_poll;
    class->ppoll                                           = adl_sys_ppoll;
    class->lseek                                           = adl_sys_lseek;
    class->ioctl                                           = adl_sys_ioctl;
    class->pread                                           = adl_sys_pread;
    class->pwrite                                          = adl_sys_pwrite;
    class->readv                                           = adl_sys_readv;
    class->writev                                          = adl_sys_writev;
    class->preadv                                          = adl_sys_preadv;
    class->pwritev                                         = adl_sys_pwritev;
    class->preadv2                                         = adl_sys_preadv2;
    class->pwritev2                                        = adl_sys_pwritev2;
    class->pipe                                            = adl_sys_pipe;
    class->pipe2                                           = adl_sys_pipe2;
    class->select                                          = adl_sys_select;
    class->pselect                                         = adl_sys_pselect;
    class->dup                                             = adl_sys_dup;
    class->dup2                                            = adl_sys_dup2;
    class->dup3                                            = adl_sys_dup3;
    class->flock                                           = adl_sys_flock;
    class->fsync                                           = adl_sys_fsync;
    class->fdatasync                                       = adl_sys_fdatasync;
    class->truncate                                        = adl_sys_truncate;
    class->ftruncate                                       = adl_sys_ftruncate;
    class->getcwd                                          = adl_sys_getcwd;
    class->chdir                                           = adl_sys_chdir;
    class->fchdir                                          = adl_sys_fchdir;
    class->rename                                          = adl_sys_rename;
    class->renameat                                        = adl_sys_renameat;
    class->renameat2                                       = adl_sys_renameat2;
    class->mkdir                                           = adl_sys_mkdir;
    class->mkdirat                                         = adl_sys_mkdirat;
    class->rmdir                                           = adl_sys_rmdir;
    class->link                                            = adl_sys_link;
    class->linkat                                          = adl_sys_linkat;
    class->unlink                                          = adl_sys_unlink;
    class->unlinkat                                        = adl_sys_unlinkat;
    class->symlink                                         = adl_sys_symlink;
    class->symlinkat                                       = adl_sys_symlinkat;
    class->readlink                                        = adl_sys_readlink;
    class->readlinkat                                      = adl_sys_readlinkat;
    class->chmod                                           = adl_sys_chmod;
    class->fchmod                                          = adl_sys_fchmod;
    class->fchmodat                                        = adl_sys_fchmodat;
    class->chown                                           = adl_sys_chown;
    class->lchown                                          = adl_sys_lchown;
    class->fchown                                          = adl_sys_fchown;
    class->fchownat                                        = adl_sys_fchownat;
    class->umask                                           = adl_sys_umask;
    class->mknod                                           = adl_sys_mknod;
    class->mknodat                                         = adl_sys_mknodat;
    class->statfs                                          = adl_sys_statfs;
    class->fstatfs                                         = adl_sys_fstatfs;
    class->vhangup                                         = adl_sys_vhangup;
    class->pivot_root                                      = adl_sys_pivot_root;
    class->chroot                                          = adl_sys_chroot;
    class->sync                                            = adl_sys_sync;
    class->syncfs                                          = adl_sys_syncfs;
    class->mount                                           = adl_sys_mount;
    class->umount                                          = adl_sys_umount;
    class->umount2                                         = adl_sys_umount2;
    class->ioperm                                          = adl_sys_ioperm;
    class->readahead                                       = adl_sys_readahead;
    class->setxattr                                        = adl_sys_setxattr;
    class->lsetxattr                                       = adl_sys_lsetxattr;
    class->fsetxattr                                       = adl_sys_fsetxattr;
    class->getxattr                                        = adl_sys_getxattr;
    class->lgetxattr                                       = adl_sys_lgetxattr;
    class->fgetxattr                                       = adl_sys_fgetxattr;
    class->listxattr                                       = adl_sys_listxattr;
    class->llistxattr                                      = adl_sys_llistxattr;
    class->flistxattr                                      = adl_sys_flistxattr;
    class->removexattr                                     = adl_sys_removexattr;
    class->lremovexattr                                    = adl_sys_lremovexattr;
    class->fremovexattr                                    = adl_sys_fremovexattr;
    class->ioprio_set                                      = adl_sys_ioprio_set;
    class->ioprio_get                                      = adl_sys_ioprio_get;
    class->inotify_init                                    = adl_sys_inotify_init;
    class->inotify_init1                                   = adl_sys_inotify_init1;
    class->inotify_add_watch                               = adl_sys_inotify_add_watch;
    class->inotify_rm_watch                                = adl_sys_inotify_rm_watch;
    class->access                                          = adl_sys_access;
    class->faccessat                                       = adl_sys_faccessat;
    class->faccessat2                                      = adl_sys_faccessat2;
    class->quotactl                                        = adl_sys_quotactl;
    class->io_setup                                        = adl_sys_io_setup;
    class->io_destroy                                      = adl_sys_io_destroy;
    class->io_getevents                                    = adl_sys_io_getevents;
    class->io_submit                                       = adl_sys_io_submit;
    class->io_cancel                                       = adl_sys_io_cancel;
    class->lookup_dcookie                                  = adl_sys_lookup_dcookie;
    class->epoll_create                                    = adl_sys_epoll_create;
    class->epoll_create1                                   = adl_sys_epoll_create1;
    class->epoll_wait                                      = adl_sys_epoll_wait;
    class->epoll_pwait                                     = adl_sys_epoll_pwait;
    class->epoll_pwait2                                    = adl_sys_epoll_pwait2;
    class->epoll_ctl                                       = adl_sys_epoll_ctl;
    class->splice                                          = adl_sys_splice;
    class->tee                                             = adl_sys_tee;
    class->posix_fadvise64                                 = adl_sys_posix_fadvise64;
    class->utime                                           = adl_sys_utime;
    class->utimes                                          = adl_sys_utimes;
    class->utimensat                                       = adl_sys_utimensat;
    class->futimens                                        = adl_sys_futimens;
    class->sync_file_range                                 = adl_sys_sync_file_range;
    class->fallocate                                       = adl_sys_fallocate;
    class->fanotify_init                                   = adl_sys_fanotify_init;
    class->fanotify_mark                                   = adl_sys_fanotify_mark;
    class->name_to_handle_at                               = adl_sys_name_to_handle_at;
    class->open_by_handle_at                               = adl_sys_open_by_handle_at;
    class->copy_file_range                                 = adl_sys_copy_file_range;
    class->statx                                           = adl_sys_statx;
    class->close_range                                     = adl_sys_close_range;
    class->mount_setattr                                   = adl_sys_mount_setattr;
    class->mkfifo                                          = adl_lib_mkfifo;
    class->mkfifoat                                        = adl_lib_mkfifoat;
    class->opendir                                         = adl_lib_opendir;
    class->fdopendir                                       = adl_lib_fdopendir;
    class->readdir                                         = adl_lib_readdir;
    class->rewinddir                                       = adl_lib_rewinddir;
    class->closedir                                        = adl_lib_closedir;
    class->dirfd                                           = adl_lib_dirfd;





    class->pause                                           = adl_sys_pause;
    class->nanosleep                                       = adl_sys_nanosleep;
    class->getitimer                                       = adl_sys_getitimer;
    class->setitimer                                       = adl_sys_setitimer;
    class->alarm                                           = adl_sys_alarm;
    class->gettimeofday                                    = adl_sys_gettimeofday;
    class->settimeofday                                    = adl_sys_settimeofday;
    class->timer_create                                    = adl_sys_timer_create;
    class->timer_settime                                   = adl_sys_timer_settime;
    class->timer_gettime                                   = adl_sys_timer_gettime;
    class->timer_getoverrun                                = adl_sys_timer_getoverrun;
    class->timer_delete                                    = adl_sys_timer_delete;
    class->clock_settime                                   = adl_sys_clock_settime;
    class->clock_gettime                                   = adl_sys_clock_gettime;
    class->clock_getres                                    = adl_sys_clock_getres;
    class->clock_nanosleep                                 = adl_sys_clock_nanosleep;
    class->clock_adjtime                                   = adl_sys_clock_adjtime;
    class->adjtimex                                        = adl_sys_adjtimex;
    class->time                                            = adl_sys_time;
    class->timerfd_settime                                 = adl_sys_timerfd_settime;
    class->timerfd_gettime                                 = adl_sys_timerfd_gettime;
    class->timerfd_create                                  = adl_sys_timerfd_create;
    class->shmget                                          = adl_sys_shmget;
    class->shmat                                           = adl_sys_shmat;
    class->shmctl                                          = adl_sys_shmctl;
    class->shmdt                                           = adl_sys_shmdt;
    class->msgget                                          = adl_sys_msgget;
    class->msgsnd                                          = adl_sys_msgsnd;
    class->msgrcv                                          = adl_sys_msgrcv;
    class->msgctl                                          = adl_sys_msgctl;
    class->mq_open_v1                                      = adl_sys_mq_open_v1;
    class->mq_open_v2                                      = adl_sys_mq_open_v2;
    class->mq_unlink                                       = adl_sys_mq_unlink;
    class->mq_timedsend                                    = adl_sys_mq_timedsend;
    class->mq_timedreceive                                 = adl_sys_mq_timedreceive;
    class->mq_notify                                       = adl_sys_mq_notify;
    class->mq_getsetattr                                   = adl_sys_mq_getsetattr;
    class->semget                                          = adl_sys_semget;
    class->semop                                           = adl_sys_semop;
    class->semtimedop                                      = adl_sys_semtimedop;
    class->semctl                                          = adl_sys_semctl;
    class->futex                                           = adl_sys_futex;
    class->set_robust_list                                 = adl_sys_set_robust_list;
    class->get_robust_list                                 = adl_sys_get_robust_list;



    class->capget                                          = adl_sys_capget;
    class->capset                                          = adl_sys_capset;
    class->clone3                                          = adl_sys_clone3;
    class->clone                                           = adl_sys_clone;
    class->execve                                          = adl_sys_execve;
    class->execveat                                        = adl_sys_execveat;
    class->exit                                            = adl_sys_exit;
    class->exit_group                                      = adl_sys_exit_group;
    class->fork                                            = adl_sys_fork;
    class->vfork                                           = adl_sys_vfork;
    class->getcpu                                          = adl_sys_getcpu;
    class->getegid                                         = adl_sys_getegid;
    class->geteuid                                         = adl_sys_geteuid;
    class->getgid                                          = adl_sys_getgid;
    class->getgroups                                       = adl_sys_getgroups;
    class->getpgid                                         = adl_sys_getpgid;
    class->getpgrp                                         = adl_sys_getpgrp;
    class->getpid                                          = adl_sys_getpid;
    class->getppid                                         = adl_sys_getppid;
    class->getpriority                                     = adl_sys_getpriority;
    class->getresgid                                       = adl_sys_getresgid;
    class->getresuid                                       = adl_sys_getresuid;
    class->getrlimit                                       = adl_sys_getrlimit;
    class->getrusage                                       = adl_sys_getrusage;
    class->getsid                                          = adl_sys_getsid;
    class->get_thread_area                                 = adl_sys_get_thread_area;
    class->gettid                                          = adl_sys_gettid;
    class->getuid                                          = adl_sys_getuid;
    class->kill                                            = adl_sys_kill;
    class->pidfd_getfd                                     = adl_sys_pidfd_getfd;
    class->pidfd_open                                      = adl_sys_pidfd_open;
    class->prctl                                           = adl_sys_prctl;
    class->prlimit                                         = adl_sys_prlimit;
    class->process_madvise                                 = adl_sys_process_madvise;
    class->process_vm_readv                                = adl_sys_process_vm_readv;
    class->process_vm_writev                               = adl_sys_process_vm_writev;
    class->sched_getaffinity                               = adl_sys_sched_getaffinity;
    class->sched_getattr                                   = adl_sys_sched_getattr;
    class->sched_getparam                                  = adl_sys_sched_getparam;
    class->sched_get_priority_max                          = adl_sys_sched_get_priority_max;
    class->sched_get_priority_min                          = adl_sys_sched_get_priority_min;
    class->sched_getscheduler                              = adl_sys_sched_getscheduler;
    class->sched_rr_get_interval                           = adl_sys_sched_rr_get_interval;
    class->sched_setaffinity                               = adl_sys_sched_setaffinity;
    class->sched_setattr                                   = adl_sys_sched_setattr;
    class->sched_setparam                                  = adl_sys_sched_setparam;
    class->sched_setscheduler                              = adl_sys_sched_setscheduler;
    class->sched_yield                                     = adl_sys_sched_yield;
    class->setgid                                          = adl_sys_setgid;
    class->setgroups                                       = adl_sys_setgroups;
    class->initgroups                                      = adl_lib_initgroups;
    class->setns                                           = adl_sys_setns;
    class->setpgid                                         = adl_sys_setpgid;
    class->setpriority                                     = adl_sys_setpriority;
    class->setregid                                        = adl_sys_setregid;
    class->setresgid                                       = adl_sys_setresgid;
    class->setresuid                                       = adl_sys_setresuid;
    class->setreuid                                        = adl_sys_setreuid;
    class->setrlimit                                       = adl_sys_setrlimit;
    class->setsid                                          = adl_sys_setsid;
    class->set_thread_area                                 = adl_sys_set_thread_area;
    class->set_tid_address                                 = adl_sys_set_tid_address;
    class->setuid                                          = adl_sys_setuid;
    class->seteuid                                         = adl_sys_seteuid;
    class->setegid                                         = adl_sys_setegid;
    class->tgkill                                          = adl_sys_tgkill;
    class->unshare                                         = adl_sys_unshare;
    class->wait                                            = adl_sys_wait;
    class->waitpid                                         = adl_sys_waitpid;
    class->waitid                                          = adl_sys_waitid;
    class->wait4                                           = adl_sys_wait4;
    class->wait3                                           = adl_sys_wait3;
    class->bpf                                             = adl_sys_bpf;
    class->modify_ldt                                      = adl_sys_modify_ldt;
    class->seccomp                                         = adl_sys_seccomp;
    class->kcmp                                            = adl_sys_kcmp;
    class->getenv                                          = adl_lib_getenv;
    class->setenv                                          = adl_lib_setenv;
    class->unsetenv                                        = adl_lib_unsetenv;
    class->clearenv                                        = adl_lib_clearenv;
    class->times                                           = adl_sys_times;
    class->acct                                            = adl_sys_acct;


    class->sigaction                                       = adl_sys_sigaction;
    class->sigpending                                      = adl_sys_sigpending;
    class->sigprocmask                                     = adl_sys_sigprocmask;
    class->sigsuspend                                      = adl_sys_sigsuspend;
    class->sigtimedwait                                    = adl_sys_sigtimedwait;
    class->sigwaitinfo                                     = adl_sys_sigwaitinfo;
    class->signal                                          = adl_sys_signal;
    class->pidfd_send_signal                               = adl_sys_pidfd_send_signal;
    class->eventfd                                         = adl_sys_eventfd;
    class->signalfd                                        = adl_sys_signalfd;
    class->sigaltstack                                     = adl_sys_sigaltstack;
    class->reboot                                          = adl_sys_reboot;
    class->delete_module                                   = adl_sys_delete_module;
    class->finit_module                                    = adl_sys_finit_module;
    class->init_module                                     = adl_sys_init_module;
    class->kexec_file_load                                 = adl_sys_kexec_file_load;
    class->kexec_load                                      = adl_sys_kexec_load;
    class->syslog                                          = adl_sys_syslog;
    class->sysinfo                                         = adl_sys_sysinfo;
    class->getrandom                                       = adl_sys_getrandom;
    class->setdomainname                                   = adl_sys_setdomainname;
    class->getdomainname                                   = adl_sys_getdomainname;
    class->sethostname                                     = adl_sys_sethostname;
    class->gethostname                                     = adl_sys_gethostname;
    class->brk                                             = adl_sys_brk;
    class->sbrk                                            = adl_sys_sbrk;
    class->madvise                                         = adl_sys_madvise;
    class->mincore                                         = adl_sys_mincore;
    class->get_mempolicy                                   = adl_sys_get_mempolicy;
    class->keyctl                                          = adl_sys_keyctl;
    class->membarrier                                      = adl_sys_membarrier;
    class->memfd_secret                                    = adl_sys_memfd_secret;
    class->userfaultfd                                     = adl_sys_userfaultfd;
    class->mbind                                           = adl_sys_mbind;
    class->memfd_create                                    = adl_sys_memfd_create;
    class->migrate_pages                                   = adl_sys_migrate_pages;
    class->mlock2                                          = adl_sys_mlock2;
    class->mremap                                          = adl_sys_mremap;
    class->move_pages                                      = adl_sys_move_pages;
    class->request_key                                     = adl_sys_request_key;
    class->pkey_alloc                                      = adl_sys_pkey_alloc;
    class->pkey_free                                       = adl_sys_pkey_free;
    class->pkey_mprotect                                   = adl_sys_pkey_mprotect;
    class->set_mempolicy                                   = adl_sys_set_mempolicy;
    class->swapoff                                         = adl_sys_swapoff;
    class->swapon                                          = adl_sys_swapon;
    class->vmsplice                                        = adl_sys_vmsplice;
    class->mlock                                           = adl_sys_mlock;
    class->mlockall                                        = adl_sys_mlockall;
    class->mmap                                            = adl_sys_mmap;
    class->mprotect                                        = adl_sys_mprotect;
    class->msync                                           = adl_sys_msync;
    class->munlock                                         = adl_sys_munlock;
    class->munlockall                                      = adl_sys_munlockall;
    class->munmap                                          = adl_sys_munmap;




    class->pthread_attr_destroy                            = adl_lib_pthread_attr_destroy;
    class->pthread_getcpuclockid                           = adl_lib_pthread_getcpuclockid;
    class->pthread_attr_getaffinity_np                     = adl_lib_pthread_attr_getaffinity_np;
    class->pthread_getname_np                              = adl_lib_pthread_getname_np;
    class->pthread_attr_getdetachstate                     = adl_lib_pthread_attr_getdetachstate;
    class->pthread_getschedparam                           = adl_lib_pthread_getschedparam;
    class->pthread_attr_getguardsize                       = adl_lib_pthread_attr_getguardsize;
    class->pthread_join                                    = adl_lib_pthread_join;
    class->pthread_attr_getinheritsched                    = adl_lib_pthread_attr_getinheritsched;
    class->pthread_kill                                    = adl_lib_pthread_kill;
    class->pthread_attr_getschedparam                      = adl_lib_pthread_attr_getschedparam;
    class->pthread_attr_getschedpolicy                     = adl_lib_pthread_attr_getschedpolicy;
    class->pthread_mutexattr_getpshared                    = adl_lib_pthread_mutexattr_getpshared;
    class->pthread_attr_getscope                           = adl_lib_pthread_attr_getscope;
    class->pthread_mutexattr_getrobust                     = adl_lib_pthread_mutexattr_getrobust;
    class->pthread_attr_getsigmask_np                      = adl_lib_pthread_attr_getsigmask_np;
    class->pthread_attr_getstack                           = adl_lib_pthread_attr_getstack;
    class->pthread_mutexattr_setpshared                    = adl_lib_pthread_mutexattr_setpshared;
    class->pthread_mutexattr_setrobust                     = adl_lib_pthread_mutexattr_setrobust;
    class->pthread_attr_getstacksize                       = adl_lib_pthread_attr_getstacksize;
    class->pthread_attr_init                               = adl_lib_pthread_attr_init;
    class->pthread_mutex_consistent                        = adl_lib_pthread_mutex_consistent;
    class->pthread_attr_setaffinity_np                     = adl_lib_pthread_attr_setaffinity_np;
    class->pthread_attr_setdetachstate                     = adl_lib_pthread_attr_setdetachstate;
    class->pthread_rwlockattr_getkind_np                   = adl_lib_pthread_rwlockattr_getkind_np;
    class->pthread_attr_setguardsize                       = adl_lib_pthread_attr_setguardsize;
    class->pthread_rwlockattr_setkind_np                   = adl_lib_pthread_rwlockattr_setkind_np;
    class->pthread_attr_setinheritsched                    = adl_lib_pthread_attr_setinheritsched;
    class->pthread_self                                    = adl_lib_pthread_self;
    class->pthread_attr_setschedparam                      = adl_lib_pthread_attr_setschedparam;
    class->pthread_setaffinity_np                          = adl_lib_pthread_setaffinity_np;
    class->pthread_attr_setschedpolicy                     = adl_lib_pthread_attr_setschedpolicy;
    class->pthread_setattr_default_np                      = adl_lib_pthread_setattr_default_np;
    class->pthread_attr_setscope                           = adl_lib_pthread_attr_setscope;
    class->pthread_setcancelstate                          = adl_lib_pthread_setcancelstate;
    class->pthread_attr_setsigmask_np                      = adl_lib_pthread_attr_setsigmask_np;
    class->pthread_setcanceltype                           = adl_lib_pthread_setcanceltype;
    class->pthread_attr_setstack                           = adl_lib_pthread_attr_setstack;
    class->pthread_setconcurrency                          = adl_lib_pthread_setconcurrency; 
    class->pthread_setname_np                              = adl_lib_pthread_setname_np;
    class->pthread_attr_setstacksize                       = adl_lib_pthread_attr_setstacksize;
    class->pthread_setschedparam                           = adl_lib_pthread_setschedparam;
    class->pthread_cancel                                  = adl_lib_pthread_cancel;
    class->pthread_setschedprio                            = adl_lib_pthread_setschedprio;
    class->pthread_sigmask                                 = adl_lib_pthread_sigmask;
    class->pthread_sigqueue                                = adl_lib_pthread_sigqueue; 
    class->pthread_spin_destroy                            = adl_lib_pthread_spin_destroy;
    class->pthread_spin_init                               = adl_lib_pthread_spin_init;
    class->pthread_create                                  = adl_lib_pthread_create;
    class->pthread_spin_lock                               = adl_lib_pthread_spin_lock;
    class->pthread_detach                                  = adl_lib_pthread_detach;
    class->pthread_spin_trylock                            = adl_lib_pthread_spin_trylock;
    class->pthread_equal                                   = adl_lib_pthread_equal;
    class->pthread_spin_unlock                             = adl_lib_pthread_spin_unlock;
    class->pthread_exit                                    = adl_lib_pthread_exit;
    class->pthread_testcancel                              = adl_lib_pthread_testcancel;
    class->pthread_getaffinity_np                          = adl_lib_pthread_getaffinity_np;
    class->pthread_timedjoin_np                            = adl_lib_pthread_timedjoin_np;
    class->pthread_getattr_default_np                      = adl_lib_pthread_getattr_default_np;
    class->pthread_tryjoin_np                              = adl_lib_pthread_tryjoin_np;
    class->pthread_getattr_np                              = adl_lib_pthread_getattr_np;
    class->pthread_getconcurrency                          = adl_lib_pthread_getconcurrency;




    class->getpwnam                                        = adl_lib_getpwnam;
    class->getpwuid                                        = adl_lib_getpwuid;
    class->getpwent                                        = adl_lib_getpwent;
    class->setpwent                                        = adl_lib_setpwent;
    class->endpwent                                        = adl_lib_endpwent;
    class->getgrnam                                        = adl_lib_getgrnam;
    class->getgrgid                                        = adl_lib_getgrgid;
    class->getgrent                                        = adl_lib_getgrent;
    class->setgrent                                        = adl_lib_setgrent;
    class->endgrent                                        = adl_lib_endgrent;
    class->getspnam                                        = adl_lib_getspnam;
    class->getspent                                        = adl_lib_getspent;
    class->setspent                                        = adl_lib_setspent;
    class->endspent                                        = adl_lib_endspent;
    class->crypt                                           = adl_lib_crypt;

null_class:
    return;
}

void ADL_UNIX_Fini(ADL_UNIX *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_UNIX));

null_class:
    return;
}




#endif




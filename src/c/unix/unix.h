
#include "../include/unix/unix.h"

#ifdef  ADL_OS_LINUX


#define ___adl_bsd_std___
#define ___adl_end_bsd___
#define ___adl_linux_std___
#define ___adl_end_linux___
#define ___adl_nostd___
#define ___adl_end_nostd___
#define ___adl_not_sys___
#define ___adl_end_not_sys___
#define ___adl_ret_charptr___

#define ___adl_syscall___
#define ___adl_end_syscall___

#define ___adl_obsolete___
#define ___adl_end_obsolete___

#define ___adl_not_for_apps_for_glibc___


static int openat2(int dirfd,const char *pathname,struct open_how *how,size_t size);
static int faccessat2(int dirfd,const char *path,int mode,int flags);
static int pivot_root(const char *new_root, const char *put_old);
static int io_setup(unsigned int nr_events,aio_context_t *ctx_id);
static int io_destroy(aio_context_t ctx_id);
static int io_getevents(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout);
static int io_submit(aio_context_t ctx_id, long nr, struct iocb **iocb);
static int io_cancel(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result);
static int lookup_dcookie(uint64_t cookie, char *buffer,size_t len);
static int ioprio_set(int which,int who,int ioprio);
static int ioprio_get(int which,int who);
static int mq_getsetattr(mqd_t mqdes,const struct mq_attr *newattr, struct mq_attr *oldattr);
static int futex(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3);
static int get_robust_list(int pid,struct robust_list_head **head_ptr, size_t *len_ptr);
static int set_robust_list(struct robust_list_head *head,size_t len);
int bpf(int cmd,union bpf_attr *attr,unsigned int size);
int pidfd_send_signal(int pidfd, int sig,siginfo_t *info, unsigned int flags);
int reboot(int magic,int magic2,int op,void *arg);
int delete_module(const char *name,unsigned int flags);
int init_module(void * module_image,unsigned long len,const char *param_values);
int finit_module(int fd,const char *param_values, int flags);
int kexec_file_load(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags);
int kexec_load(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags);
int syslog(int type,char *bufp,int len);
//int keyctl(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5);
int membarrier(int cmd,unsigned int flags,int cpu_id);
int memfd_secret(unsigned int flags);
int userfaultfd(int flags);







static int openat2(int dirfd,const char *pathname,struct open_how *how,size_t size)
{
    return syscall(SYS_openat2,dirfd,pathname,how,size);  
}


static int faccessat2(int dirfd,const char *path,int mode,int flags)
{
    return syscall(SYS_faccessat2,dirfd,path,mode,flags);
}


static int pivot_root(const char *new_root, const char *put_old)
{
    return syscall(SYS_pivot_root,new_root,put_old);
}


static int io_setup(unsigned int nr_events,aio_context_t *ctx_id)
{
    return syscall(SYS_io_setup,nr_events,ctx_id);
}


static int io_destroy(aio_context_t ctx_id)
{
    return syscall(SYS_io_destroy,ctx_id);
}


static int io_getevents(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout)
{
    return syscall(SYS_io_getevents,ctx_id,min_nr,nr,events,timeout);
}


static int io_submit(aio_context_t ctx_id, long nr, struct iocb **iocb)
{
    return syscall(SYS_io_submit,ctx_id,nr,iocb);
}


static int io_cancel(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result)
{
    return syscall(SYS_io_cancel,ctx_id,iocb,result);
}


static int lookup_dcookie(uint64_t cookie, char *buffer,size_t len)
{
    return syscall(SYS_lookup_dcookie,cookie,buffer,len);
}


static int ioprio_set(int which,int who,int ioprio)
{
    return syscall(SYS_ioprio_set,which,who,ioprio);
}


static int ioprio_get(int which,int who)
{
    return syscall(SYS_ioprio_get,which,who);
}


static int mq_getsetattr(mqd_t mqdes,const struct mq_attr *newattr, struct mq_attr *oldattr)
{
    return syscall(SYS_mq_getsetattr, mqdes,newattr,oldattr);
}


static int futex(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3)
{
    return syscall(SYS_futex,uaddr,futex_op,val,timeout,uaddr2,val3);
}


static int get_robust_list(int pid,struct robust_list_head **head_ptr, size_t *len_ptr)
{
    return syscall(SYS_get_robust_list,pid,head_ptr,len_ptr);
}


static int set_robust_list(struct robust_list_head *head,size_t len)
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








#ifndef ADL_SOCKET
#define ADL_SOCKET socket
#endif


#ifndef ADL_SOCKETPAIR
#define ADL_SOCKETPAIR socketpair
#endif


#ifndef ADL_CONNECT
#define ADL_CONNECT connect
#endif

#ifndef ADL_BIND
#define ADL_BIND bind
#endif


#ifndef ADL_LISTEN
#define ADL_LISTEN listen
#endif


#ifndef ADL_ACCEPT 
#define ADL_ACCEPT accept
#endif

#ifndef ADL_ACCEPT4
#define ADL_ACCEPT4 accept4
#endif

#ifndef ADL_RECV
#define ADL_RECV recv
#endif


#ifndef ADL_RECVFROM
#define ADL_RECVFROM recvfrom
#endif


#ifndef ADL_RECVMSG
#define ADL_RECVMSG recvmsg
#endif

#ifndef ADL_RECVMMSG
#define ADL_RECVMMSG recvmmsg
#endif

#ifndef ADL_SEND
#define ADL_SEND send
#endif

#ifndef ADL_SENDTO
#define ADL_SENDTO sendto
#endif


#ifndef ADL_SENDMSG
#define ADL_SENDMSG sendmsg
#endif

#ifndef ADL_SENDMMSG
#define ADL_SENDMMSG sendmmsg
#endif


#ifndef ADL_SHUTDOWN
#define ADL_SHUTDOWN shutdown
#endif

#ifndef ADL_CLOSE
#define ADL_CLOSE close
#endif


#ifndef ADL_GETSOCKOPT
#define ADL_GETSOCKOPT getsockopt
#endif


#ifndef ADL_SETSOCKOPT
#define ADL_SETSOCKOPT setsockopt
#endif


#ifndef ADL_GETSOCKNAME
#define ADL_GETSOCKNAME getsockname
#endif


#ifndef ADL_GETPEERNAME 
#define ADL_GETPEERNAME getpeername
#endif

#ifndef ADL_GETADDRINFO
#define ADL_GETADDRINFO getaddrinfo
#endif

#ifndef ADL_FREEADDRINFO
#define ADL_FREEADDRINFO freeaddrinfo
#endif

#ifndef ADL_GAI_STRERROR
#define ADL_GAI_STRERROR gai_strerror
#endif

#ifndef ADL_GETNAMEINFO
#define ADL_GETNAMEINFO getnameinfo
#endif


#ifndef ADL_HTONS
#define ADL_HTONS htons
#endif

#ifndef ADL_HTONL
#define ADL_HTONL htonl
#endif

#ifndef ADL_NTOHS
#define ADL_NTOHS ntohs
#endif

#ifndef ADL_NTOHL
#define ADL_NTOHL ntohl
#endif

#ifndef ADL_OPEN
#define ADL_OPEN open
#endif

#ifndef ADL_CREAT
#define ADL_CREAT creat
#endif

#ifndef ADL_OPENAT
#define ADL_OPENAT openat
#endif

#ifndef ADL_OPENAT2
#define ADL_OPENAT2 openat2
#endif


#ifndef ADL_READ
#define ADL_READ read
#endif


#ifndef ADL_WRITE
#define ADL_WRITE write
#endif


#ifndef ADL_CLOSE
#define ADL_CLOSE close
#endif



#ifndef ADL_STAT
#define ADL_STAT stat
#endif

#ifndef ADL_FSTAT
#define ADL_FSTAT fstat
#endif

#ifndef ADL_LSTAT
#define ADL_LSTAT lstat
#endif



#ifndef ADL_FSTATAT
#define ADL_FSTATAT fstatat
#endif



#ifndef ADL_SENDFILE
#define ADL_SENDFILE sendfile
#endif


#ifndef ADL_PPOLL
#define ADL_PPOLL ppoll
#endif


#ifndef ADL_GETDENTS64
#define ADL_GETDENTS64 getdents64
#endif



#ifndef ADL_POLL 
#define ADL_POLL poll
#endif




#ifndef ADL_LSEEK
#define ADL_LSEEK lseek
#endif



#ifndef ADL_IOCTL
#define ADL_IOCTL ioctl
#endif


#ifndef ADL_PREAD
#define ADL_PREAD pread
#endif

#ifndef ADL_PWRITE
#define ADL_PWRITE pwrite
#endif



#ifndef ADL_READV
#define ADL_READV readv
#endif

#ifndef ADL_WRITEV
#define ADL_WRITEV writev
#endif


#ifndef ADL_PREADV
#define ADL_PREADV preadv
#endif

#ifndef ADL_PWRITEV
#define ADL_PWRITEV pwritev
#endif


#ifndef ADL_PREADV2
#define ADL_PREADV2 preadv2
#endif

#ifndef ADL_PWRITEV2
#define ADL_PWRITEV2 pwritev2
#endif



#ifndef ADL_PIPE
#define ADL_PIPE pipe
#endif


#ifndef ADL_PIPE2
#define ADL_PIPE2 pipe2
#endif




#ifndef ADL_SELECT
#define ADL_SELECT select
#endif


#ifndef ADL_PSELECT
#define ADL_PSELECT pselect
#endif



#ifndef ADL_DUP
#define ADL_DUP dup
#endif


#ifndef ADL_DUP2
#define ADL_DUP2 dup2
#endif

#ifndef ADL_DUP3
#define ADL_DUP3 dup3
#endif








#ifndef ADL_FLOCK
#define ADL_FLOCK flock
#endif

#ifndef ADL_FSYNC
#define ADL_FSYNC fsync
#endif

#ifndef ADL_FDATASYNC
#define ADL_FDATASYNC fdatasync
#endif

#ifndef ADL_TRUNCATE
#define ADL_TRUNCATE truncate
#endif

#ifndef ADL_FTRUNCATE
#define ADL_FTRUNCATE ftruncate
#endif

#ifndef ADL_GETCWD
#define ADL_GETCWD getcwd
#endif

#ifndef ADL_CHDIR
#define ADL_CHDIR chdir
#endif

#ifndef ADL_FCHDIR
#define ADL_FCHDIR fchdir
#endif


#ifndef ADL_RENAME
#define ADL_RENAME rename
#endif

#ifndef ADL_RENAMEAT
#define ADL_RENAMEAT renameat
#endif

#ifndef ADL_RENAMEAT2
#define ADL_RENAMEAT2 renameat2
#endif


#ifndef ADL_MKDIR
#define ADL_MKDIR mkdir
#endif

#ifndef ADL_MKDIRAT
#define ADL_MKDIRAT mkdirat
#endif

#ifndef ADL_RMDIR
#define ADL_RMDIR rmdir
#endif

#ifndef ADL_LINK
#define ADL_LINK link
#endif

#ifndef ADL_LINKAT
#define ADL_LINKAT linkat
#endif

#ifndef ADL_UNLINK
#define ADL_UNLINK unlink
#endif

#ifndef ADL_UNLINKAT
#define ADL_UNLINKAT unlinkat
#endif

#ifndef ADL_SYMLINK
#define ADL_SYMLINK symlink
#endif

#ifndef ADL_SYMLINKAT
#define ADL_SYMLINKAT symlinkat
#endif

#ifndef ADL_READLINK
#define ADL_READLINK readlink
#endif

#ifndef ADL_READLINKAT
#define ADL_READLINKAT readlinkat
#endif

#ifndef ADL_CHMOD
#define ADL_CHMOD chmod
#endif

#ifndef ADL_FCHMODAT
#define ADL_FCHMODAT fchmodat
#endif

#ifndef ADL_FCHMOD
#define ADL_FCHMOD fchmod
#endif

#ifndef ADL_CHOWN
#define ADL_CHOWN chown
#endif


#ifndef ADL_FCHOWN
#define ADL_FCHOWN fchown
#endif

#ifndef ADL_LCHOWN
#define ADL_LCHOWN lchown
#endif

#ifndef ADL_FCHOWNAT
#define ADL_FCHOWNAT fchownat
#endif

#ifndef ADL_UMASK
#define ADL_UMASK umask
#endif

#ifndef ADL_sys_MKNOD
#define ADL_sys_MKNOD mknod
#endif

#ifndef ADL_sys_MKNODAT
#define ADL_sys_MKNODAT mknodat
#endif


___adl_linux_std___

#ifndef ADL_STATFS
#define ADL_STATFS statfs
#endif

#ifndef ADL_FSTATFS
#define ADL_FSTATFS fstatfs
#endif


#ifndef ADL_VHANGUP
#define ADL_VHANGUP vhangup
#endif


___adl_syscall___

#ifndef ADL_PIVOT_ROOT
#define ADL_PIVOT_ROOT pivot_root
#endif

___adl_end_syscall___

___adl_end_linux___

#ifndef ADL_CHROOT
#define ADL_CHROOT chroot
#endif

#ifndef ADL_SYNC
#define ADL_SYNC sync
#endif

___adl_linux_std___

#ifndef ADL_SYNCFS
#define ADL_SYNCFS syncfs
#endif

#ifndef ADL_MOUNT
#define ADL_MOUNT mount
#endif

#ifndef ADL_UMOUNT
#define ADL_UMOUNT umount
#endif

#ifndef ADL_UMOUNT2
#define ADL_UMOUNT2 umount2
#endif

#ifndef ADL_IOPERM
#define ADL_IOPERM ioperm
#endif

#define _FILE_OFFSET_BITS 64
#ifndef ADL_READAHEAD
#define ADL_READAHEAD readahead
#endif

#ifndef ADL_SETXATTR
#define ADL_SETXATTR setxattr
#endif

#ifndef ADL_LSETXATTR
#define ADL_LSETXATTR lsetxattr
#endif

#ifndef ADL_FSETXATTR
#define ADL_FSETXATTR fsetxattr
#endif

#ifndef ADL_GETXATTR
#define ADL_GETXATTR getxattr
#endif

#ifndef ADL_LGETXATTR
#define ADL_LGETXATTR lgetxattr
#endif

#ifndef ADL_FGETXATTR
#define ADL_FGETXATTR fgetxattr
#endif

#ifndef ADL_LISTXATTR
#define ADL_LISTXATTR listxattr
#endif

#ifndef ADL_LLISTXATTR
#define ADL_LLISTXATTR llistxattr
#endif

#ifndef ADL_FLISTXATTR
#define ADL_FLISTXATTR flistxattr
#endif

#ifndef ADL_REMOVEXATTR
#define ADL_REMOVEXATTR removexattr
#endif

#ifndef ADL_LREMOVEXATTR
#define ADL_LREMOVEXATTR lremovexattr
#endif

#ifndef ADL_FREMOVEXATTR
#define ADL_FREMOVEXATTR fremovexattr
#endif


___adl_syscall___

#ifndef ADL_IOPRIO_SET
#define ADL_IOPRIO_SET ioprio_set
#endif

#ifndef ADL_IOPRIO_GET
#define ADL_IOPRIO_GET ioprio_get
#endif

___adl_end_syscall___


#ifndef ADL_INOTIFY_INIT
#define ADL_INOTIFY_INIT inotify_init
#endif

#ifndef ADL_INOTIFY_INIT1
#define ADL_INOTIFY_INIT1 inotify_init1
#endif

#ifndef ADL_INOTIFY_ADD_WATCH
#define ADL_INOTIFY_ADD_WATCH inotify_add_watch
#endif

#ifndef ADL_INOTIFY_RM_WATCH
#define ADL_INOTIFY_RM_WATCH inotify_rm_watch
#endif

___adl_end_linux___



#ifndef ADL_ACCESS
#define ADL_ACCESS access
#endif

#ifndef ADL_FACCESSAT
#define ADL_FACCESSAT faccessat
#endif


___adl_linux_std___

#ifndef ADL_FACCESSAT2
#define ADL_FACCESSAT2 faccessat2
#endif


#ifndef ADL_QUOTACTL
#define ADL_QUOTACTL quotactl
#endif

___adl_syscall___


#ifndef ADL_IO_SETUP
#define ADL_IO_SETUP io_setup
#endif

#ifndef ADL_IO_DESTROY
#define ADL_IO_DESTROY io_destroy
#endif

#ifndef ADL_IO_GETEVENTS
#define ADL_IO_GETEVENTS io_getevents
#endif

#ifndef ADL_IO_SUBMIT
#define ADL_IO_SUBMIT io_submit
#endif

#ifndef ADL_IO_CANCEL
#define ADL_IO_CANCEL io_cancel
#endif

#ifndef ADL_LOOKUP_DCOOKIE
#define ADL_LOOKUP_DCOOKIE lookup_dcookie 
#endif

___adl_end_syscall___


#ifndef ADL_EPOLL_CREATE
#define ADL_EPOLL_CREATE epoll_create
#endif


#ifndef ADL_EPOLL_CREATE1
#define ADL_EPOLL_CREATE1 epoll_create1
#endif

#ifndef ADL_EPOLL_WAIT
#define ADL_EPOLL_WAIT epoll_wait
#endif

#ifndef ADL_EPOLL_PWAIT
#define ADL_EPOLL_PWAIT epoll_pwait
#endif

#ifndef ADL_EPOLL_PWAIT2
#define ADL_EPOLL_PWAIT2 epoll_pwait2
#endif

#ifndef ADL_EPOLL_CTL
#define ADL_EPOLL_CTL epoll_ctl
#endif


#ifndef ADL_SPLICE
#define ADL_SPLICE splice
#endif

#ifndef ADL_TEE
#define ADL_TEE tee
#endif

___adl_end_linux___


#ifndef ADL_POSIX_FADVICE64
#define ADL_POSIX_FADVICE64 posix_fadvise64
#endif

#ifndef ADL_UTIMES
#define ADL_UTIMES utimes 
#endif


#ifndef ADL_UTIME
#define ADL_UTIME utime
#endif

#ifndef ADL_UTIMENSAT
#define ADL_UTIMENSAT utimensat
#endif

#ifndef ADL_FUTIMENS
#define ADL_FUTIMENS futimens
#endif




___adl_linux_std___

#ifndef ADL_SYNC_FILE_RANGE
#define ADL_SYNC_FILE_RANGE sync_file_range 
#endif

#ifndef ADL_FALLOCATE
#define ADL_FALLOCATE fallocate
#endif

#ifndef ADL_FANOTIFY_INIT
#define ADL_FANOTIFY_INIT fanotify_init
#endif

#ifndef ADL_FANOTIFY_MARK
#define ADL_FANOTIFY_MARK fanotify_mark
#endif

#ifndef ADL_NAME_TO_HANDLE_AT
#define ADL_NAME_TO_HANDLE_AT name_to_handle_at
#endif

#ifndef ADL_OPEN_BY_HANDLE_AT
#define ADL_OPEN_BY_HANDLE_AT open_by_handle_at
#endif

#ifndef ADL_COPY_FILE_RANGE
#define ADL_COPY_FILE_RANGE copy_file_range
#endif

#ifndef ADL_STATX
#define ADL_STATX statx
#endif

#ifndef ADL_CLOSE_RANGE
#define ADL_CLOSE_RANGE close_range
#endif

#ifndef ADL_MOUNT_SETATTR
#define ADL_MOUNT_SETATTR mount_setattr
#endif

___adl_end_linux___



#ifndef ADL_FCNTL
#define ADL_FCNTL fcntl
#endif



#ifndef ADL_MKFIFO
#define ADL_MKFIFO mkfifo
#endif

#ifndef ADL_MKFIFOAT
#define ADL_MKFIFOAT mkfifoat
#endif

#ifndef ADL_OPENDIR
#define ADL_OPENDIR opendir
#endif

#ifndef ADL_FDOPENDIR
#define ADL_FDOPENDIR fdopendir
#endif

#ifndef ADL_READDIR
#define ADL_READDIR readdir
#endif

#ifndef ADL_REWINDDIR
#define ADL_REWINDDIR rewinddir
#endif

#ifndef ADL_CLOSEDIR
#define ADL_CLOSEDIR closedir
#endif

#ifndef ADL_DIRFD
#define ADL_DIRFD dirfd
#endif

#ifndef ADL_PAUSE
#define ADL_PAUSE pause
#endif

#ifndef ADL_NANOSLEEP
#define ADL_NANOSLEEP nanosleep
#endif

#ifndef ADL_GETITIMER
#define ADL_GETITIMER getitimer
#endif

#ifndef ADL_ALARM
#define ADL_ALARM alarm
#endif

#ifndef ADL_SETITIMER
#define ADL_SETITIMER setitimer
#endif

#ifndef ADL_GETTIMEOFDAY
#define ADL_GETTIMEOFDAY gettimeofday
#endif

#ifndef ADL_SETTIMEOFDAY
#define ADL_SETTIMEOFDAY settimeofday 
#endif

#ifndef ADL_TIMER_CREATE
#define ADL_TIMER_CREATE timer_create 
#endif

#ifndef ADL_TIMER_SETTIME
#define ADL_TIMER_SETTIME timer_settime 
#endif

#ifndef ADL_TIMER_GETTIME
#define ADL_TIMER_GETTIME timer_gettime 
#endif

#ifndef ADL_TIMER_GETOVERRUN
#define ADL_TIMER_GETOVERRUN timer_getoverrun 
#endif

#ifndef ADL_TIMER_DELETE
#define ADL_TIMER_DELETE timer_delete 
#endif

#ifndef ADL_CLOCK_SETTIME
#define ADL_CLOCK_SETTIME clock_settime 
#endif

#ifndef ADL_CLOCK_GETTIME
#define ADL_CLOCK_GETTIME clock_gettime 
#endif

#ifndef ADL_CLOCK_GETRES
#define ADL_CLOCK_GETRES clock_getres 
#endif

#ifndef ADL_CLOCK_NANOSLEEP
#define ADL_CLOCK_NANOSLEEP clock_nanosleep 
#endif

#ifndef ADL_ADJTIMEX
#define ADL_ADJTIMEX adjtimex 
#endif

#ifndef ADL_CLOCK_ADJTIME
#define ADL_CLOCK_ADJTIME clock_adjtime 
#endif

#ifndef ADL_TIME
#define ADL_TIME time 
#endif



___adl_linux_std___

#ifndef ADL_TIMERFD_SETTIME
#define ADL_TIMERFD_SETTIME timerfd_settime 
#endif

#ifndef ADL_TIMERFD_GETTIME
#define ADL_TIMERFD_GETTIME timerfd_gettime 
#endif

#ifndef ADL_TIMERFD_CREATE
#define ADL_TIMERFD_CREATE timerfd_create 
#endif

___adl_end_linux___




#ifndef ADL_SHMGET
#define ADL_SHMGET shmget
#endif

#ifndef ADL_SHMAT
#define ADL_SHMAT shmat
#endif

#ifndef ADL_SHMCTL
#define ADL_SHMCTL shmctl
#endif

#ifndef ADL_SHMDT
#define ADL_SHMDT shmdt
#endif

#ifndef ADL_MSGGET
#define ADL_MSGGET msgget
#endif

#ifndef ADL_MSGSND
#define ADL_MSGSND msgsnd
#endif

#ifndef ADL_MSGRCV
#define ADL_MSGRCV msgrcv
#endif

#ifndef ADL_MSGCTL
#define ADL_MSGCTL msgctl
#endif

#ifndef ADL_MQ_OPEN
#define ADL_MQ_OPEN mq_open 
#endif

#ifndef ADL_MQ_UNLINK
#define ADL_MQ_UNLINK mq_unlink 
#endif

#ifndef ADL_MQ_TIMEDSEND
#define ADL_MQ_TIMEDSEND mq_timedsend 
#endif

#ifndef ADL_MQ_TIMEDRECEIVE
#define ADL_MQ_TIMEDRECEIVE mq_timedreceive 
#endif

#ifndef ADL_MQ_NOTIFY
#define ADL_MQ_NOTIFY mq_notify 
#endif

___adl_not_for_apps_for_glibc___

#ifndef ADL_MQ_GETSETATTR
#define ADL_MQ_GETSETATTR mq_getsetattr 
#endif

#ifndef ADL_SEMGET
#define ADL_SEMGET semget
#endif

#ifndef ADL_SEMOP
#define ADL_SEMOP semop
#endif

#ifndef ADL_SEMTIMEDOP
#define ADL_SEMTIMEDOP semtimedop
#endif

#ifndef ADL_SEMCTL
#define ADL_SEMCTL semctl
#endif


___adl_linux_std___
___adl_syscall___


#ifndef ADL_FUTEX
#define ADL_FUTEX futex
#endif

#ifndef ADL_SET_ROBUST_LIST
#define ADL_SET_ROBUST_LIST set_robust_list
#endif

#ifndef ADL_GET_ROBUST_LIST
#define ADL_GET_ROBUST_LIST get_robust_list
#endif




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

___adl_linux_std___

#ifndef ADL_TGKILL
#define ADL_TGKILL tgkill
#endif


#ifndef ADL_UNSHARE
#define ADL_UNSHARE unshare
#endif

___adl_end_linux___

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


___adl_linux_std___
___adl_syscall___

#ifndef ADL_REBOOT
#define ADL_REBOOT reboot
#endif

#ifndef ADL_DELETE_MODULE
#define ADL_DELETE_MODULE delete_module
#endif

#ifndef ADL_FINIT_MODULE
#define ADL_FINIT_MODULE finit_module
#endif


#ifndef ADL_INIT_MODULE
#define ADL_INIT_MODULE init_module
#endif

#ifndef ADL_KEXEC_FILE_LOAD
#define ADL_KEXEC_FILE_LOAD kexec_file_load
#endif

#ifndef ADL_KEXEC_LOAD
#define ADL_KEXEC_LOAD kexec_load
#endif

#ifndef ADL_SYSLOG
#define ADL_SYSLOG syslog
#endif

___adl_end_syscall___

#ifndef ADL_SYSINFO
#define ADL_SYSINFO sysinfo
#endif

#ifndef ADL_GETRANDOM
#define ADL_GETRANDOM getrandom
#endif

___adl_end_linux___

___adl_nostd___

#ifndef ADL_SETDOMAINNAME
#define ADL_SETDOMAINNAME setdomainname
#endif

#ifndef ADL_GETDOMAINNAME
#define ADL_GETDOMAINNAME getdomainname
#endif

#ifndef ADL_SETHOSTNAME
#define ADL_SETHOSTNAME sethostname
#endif

___adl_end_nostd___

#ifndef ADL_GETHOSTNAME
#define ADL_GETHOSTNAME gethostname
#endif

___adl_nostd___

#ifndef ADL_BRK
#define ADL_BRK brk
#endif

#ifndef ADL_SBRK
#define ADL_SBRK sbrk
#endif

#ifndef ADL_MADVISE
#define ADL_MADVISE madvise
#endif

#ifndef ADL_MINCORE
#define ADL_MINCORE mincore
#endif

___adl_end_nostd___



___adl_linux_std___

#ifndef ADL_GET_MEMPOLICY
#define ADL_GET_MEMPOLICY get_mempolicy
#endif

___adl_syscall___

#ifndef ADL_KEYCTL
#define ADL_KEYCTL keyctl
#endif

#ifndef ADL_MEMBARRIER
#define ADL_MEMBARRIER membarrier
#endif

#ifndef ADL_MEMFD_SECRET
#define ADL_MEMFD_SECRET memfd_secret
#endif

#ifndef ADL_USERFAULTFD
#define ADL_USERFAULTFD userfaultfd
#endif

___adl_end_syscall___

#ifndef ADL_MBIND
#define ADL_MBIND mbind
#endif

#ifndef ADL_MEMFD_CREATE
#define ADL_MEMFD_CREATE memfd_create
#endif

#ifndef ADL_MIGRATE_PAGES
#define ADL_MIGRATE_PAGES migrate_pages
#endif

#ifndef ADL_MLOCK2
#define ADL_MLOCK2 mlock2
#endif

#ifndef ADL_MREMAP
#define ADL_MREMAP mremap
#endif

#ifndef ADL_MOVE_PAGES
#define ADL_MOVE_PAGES move_pages
#endif

#ifndef ADL_REQUEST_KEY
#define ADL_REQUEST_KEY request_key
#endif

#ifndef ADL_PKEY_ALLOC
#define ADL_PKEY_ALLOC pkey_alloc
#endif

#ifndef ADL_PKEY_FREE
#define ADL_PKEY_FREE pkey_free
#endif

#ifndef ADL_PKEY_MPROTECT
#define ADL_PKEY_MPROTECT pkey_mprotect
#endif

#ifndef ADL_SET_MEMPOLICY
#define ADL_SET_MEMPOLICY set_mempolicy
#endif

#ifndef ADL_SWAPOFF
#define ADL_SWAPOFF swapoff
#endif

#ifndef ADL_SWAPON
#define ADL_SWAPON swapon
#endif

#ifndef ADL_VMSPLICE
#define ADL_VMSPLICE vmsplice
#endif

___adl_end_linux___

#ifndef ADL_MLOCK
#define ADL_MLOCK mlock
#endif

#ifndef ADL_MLOCKALL
#define ADL_MLOCKALL mlockall
#endif

#ifndef ADL_MMAP
#define ADL_MMAP mmap
#endif

#ifndef ADL_MPROTECT
#define ADL_MPROTECT mprotect
#endif

#ifndef ADL_MSYNC
#define ADL_MSYNC msync
#endif

#ifndef ADL_MUNLOCK
#define ADL_MUNLOCK munlock
#endif

#ifndef ADL_MUNLOCKALL
#define ADL_MUNLOCKALL munlockall
#endif

#ifndef ADL_MUNMAP
#define ADL_MUNMAP munmap
#endif


#ifndef ADL_GETPWNAM
#define ADL_GETPWNAM getpwnam
#endif

#ifndef ADL_GETPWUID
#define ADL_GETPWUID getpwuid
#endif

#ifndef ADL_GETPWENT
#define ADL_GETPWENT getpwent
#endif

#ifndef ADL_SETPWENT
#define ADL_SETPWENT setpwent
#endif

#ifndef ADL_ENDPWENT
#define ADL_ENDPWENT endpwent
#endif


#ifndef ADL_GETGRNAM
#define ADL_GETGRNAM getgrnam
#endif

#ifndef ADL_GETGRGID
#define ADL_GETGRGID getgrgid
#endif

#ifndef ADL_GETGRENT
#define ADL_GETGRENT getgrent
#endif

#ifndef ADL_SETGRENT
#define ADL_SETGRENT setgrent
#endif

#ifndef ADL_ENDGRENT
#define ADL_ENDGRENT endgrent
#endif


#ifndef ADL_GETSPNAM
#define ADL_GETSPNAM getspnam
#endif

#ifndef ADL_GETSPENT
#define ADL_GETSPENT getspent
#endif

#ifndef ADL_SETSPENT
#define ADL_SETSPENT setspent
#endif

#ifndef ADL_ENDSPENT
#define ADL_ENDSPENT endspent
#endif

#ifndef ADL_CRYPT
#define ADL_CRYPT crypt
#endif





static ADL_RESULT adl_sys_socket(int domain,int type,int protocol);
static ADL_RESULT adl_sys_socketpair(int domain,int type,int protocol,int sockfds[2]);
static ADL_RESULT adl_sys_bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
static ADL_RESULT adl_sys_connect(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
static ADL_RESULT adl_sys_listen(int sockfd,int backlog);
static ADL_RESULT adl_sys_accept(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
static ADL_RESULT adl_sys_accept4(int sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags);
static ADL_RESULT adl_sys_recv(int sockfd,void *buf,size_t buflen,int flags);
static ADL_RESULT adl_sys_recvfrom(int sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen);
static ADL_RESULT adl_sys_recvmsg(int sockfd,struct msghdr *msg,int flags);
static ADL_RESULT adl_sys_recvmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout);
static ADL_RESULT adl_sys_send(int sockfd,const void *buf,size_t buflen,int flags);
static ADL_RESULT adl_sys_sendto(int sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen);
static ADL_RESULT adl_sys_sendmsg(int sockfd,const struct msghdr *msg,int flags);
static ADL_RESULT adl_sys_sendmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags);
static ADL_RESULT adl_sys_shutdown(int sockfd,int how);
static ADL_RESULT adl_sys_close(int fd);
static ADL_RESULT adl_sys_getsockopt(int sockfd,int level,int optname,void *optval,socklen_t *optlen);
static ADL_RESULT adl_sys_setsockopt(int sockfd,int level,int optname,void *optval,socklen_t optlen);
static ADL_RESULT adl_sys_getsockname(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
static ADL_RESULT adl_sys_getpeername(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
static ADL_RESULT adl_lib_getaddrinfo(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);
static ADL_RESULT adl_lib_freeaddrinfo(struct addrinfo *res);
static ADL_RESULT adl_lib_getnameinfo(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,int flags);
static ADL_RESULT adl_lib_htons(u16 hostshort);
static ADL_RESULT adl_lib_htonl(u32 hostlong);
static ADL_RESULT adl_lib_ntohs(u16 netshort);
static ADL_RESULT adl_lib_ntohl(u32 netlong);
static ADL_RESULT adl_sys_open(const char *pathname,int flags,mode_t mode);
static ADL_RESULT adl_sys_creat(const char *pathname,mode_t mode);
static ADL_RESULT adl_sys_openat(int dirfd,const char *pathname,int flags,mode_t mode);
static ADL_RESULT adl_sys_openat2(int dirfd,const char *pathname,struct open_how *how,size_t size);
static ADL_RESULT adl_sys_read(int fd,void *buf,size_t buflen);
static ADL_RESULT adl_sys_write(int fd,const void *buf,size_t buflen);
static ADL_RESULT adl_sys_sendfile(int outfd,int infd,off_t *offset,size_t count);
static ADL_RESULT adl_sys_close(int fd);
static ADL_RESULT adl_sys_stat(const char *pathname,struct stat *statbuf);
static ADL_RESULT adl_sys_fstat(int fd,struct stat *statbuf);
static ADL_RESULT adl_sys_lstat(const char *pathname,struct stat *statbuf);
static ADL_RESULT adl_sys_fstatat(int dirfd,const char *pathname,struct stat *statbuf,int flags);
static ADL_RESULT adl_sys_poll(struct pollfd *fds,nfds_t nfds,int timeout);
static ADL_RESULT adl_sys_ppoll(struct pollfd *fds,nfds_t nfds,const struct timespec *timeout,const sigset_t *sigmask);
static ADL_RESULT adl_sys_lseek(int fd,off_t offset,int whence);
static ADL_RESULT adl_sys_ioctl(int fd,u64 operation,char *argp);
static ADL_RESULT adl_sys_pread(int fd,void *buf,size_t buflen,off_t offset);
static ADL_RESULT adl_sys_pwrite(int fd,const void *buf,size_t buflen,off_t offset);
static ADL_RESULT adl_sys_readv(int fd,const struct iovec *iov,int iovcnt);
static ADL_RESULT adl_sys_writev(int fd,const struct iovec *iov,int iovcnt);
static ADL_RESULT adl_sys_preadv(int fd,const struct iovec *iov,int iovcnt,off_t offset);
static ADL_RESULT adl_sys_pwritev(int fd,const struct iovec *iov,int iovcnt,off_t offset);
static ADL_RESULT adl_sys_preadv2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags);
static ADL_RESULT adl_sys_pwritev2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags);
static ADL_RESULT adl_sys_pipe(int pipefd[]);
static ADL_RESULT adl_sys_pipe2(int pipefd[],int flags);
static ADL_RESULT adl_sys_select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout);
static ADL_RESULT adl_sys_pselect(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,const struct timespec *timeout,const sigset_t *sigmask);
static ADL_RESULT adl_sys_dup(int fd);
static ADL_RESULT adl_sys_dup2(int oldfd,int newfd);
static ADL_RESULT adl_sys_dup3(int oldfd,int newfd,int flags);
static ADL_RESULT adl_sys_flock(int fd,int op);
static ADL_RESULT adl_sys_fsync(int fd);
static ADL_RESULT adl_sys_fdatasync(int fd);
static ADL_RESULT adl_sys_truncate(const char *path,off_t length);
static ADL_RESULT adl_sys_ftruncate(int fd,off_t length);
static ADL_RESULT adl_sys_getcwd(char *buf,size_t bufsize);
static ADL_RESULT adl_sys_chdir(const char *path);
static ADL_RESULT adl_sys_fchdir(int fd);
static ADL_RESULT adl_sys_rename(const char *oldpath,const char *newpath);
static ADL_RESULT adl_sys_renameat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath);
static ADL_RESULT adl_sys_renameat2(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags);
static ADL_RESULT adl_sys_mkdir(const char *path,mode_t mode);
static ADL_RESULT adl_sys_mkdirat(int dirfd,const char *path,mode_t mode);
static ADL_RESULT adl_sys_rmdir(const char *path);
static ADL_RESULT adl_sys_link(const char *oldpath,const char *newpath);
static ADL_RESULT adl_sys_linkat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags);
static ADL_RESULT adl_sys_unlink(const char *path);
static ADL_RESULT adl_sys_unlinkat(int dirfd,const char *path,int flags);
static ADL_RESULT adl_sys_symlink(const char *target,const char *linkpath);
static ADL_RESULT adl_sys_symlinkat(const char *target,int newdirfd,const char *linkpath);
static ADL_RESULT adl_sys_readlink(const char *path,char *buf,size_t bufsize);
static ADL_RESULT adl_sys_readlinkat(int dirfd,const char *path,char *buf,size_t bufsize);
static ADL_RESULT adl_sys_chmod(const char *path,mode_t mode);
static ADL_RESULT adl_sys_fchmod(int fd,mode_t mode);
static ADL_RESULT adl_sys_fchmodat(int dirfd,const char *path,mode_t mode,int flags);
static ADL_RESULT adl_sys_chown(const char *path,uid_t owner,gid_t group);
static ADL_RESULT adl_sys_lchown(const char *path,uid_t owner,gid_t group);
static ADL_RESULT adl_sys_fchown(int fd,uid_t owner,gid_t group);
static ADL_RESULT adl_sys_fchownat(int dirfd,const char *path,uid_t owner,gid_t group,int flags);
static ADL_RESULT adl_sys_umask(mode_t mask);
static ADL_RESULT adl_sys_mknod(const char *path,mode_t mode,dev_t dev);
static ADL_RESULT adl_sys_mknodat(int dirfd,const char *path,mode_t mode,dev_t dev);
static ADL_RESULT adl_sys_statfs(const char *path,struct statfs *buf);
static ADL_RESULT adl_sys_fstatfs(int fd,struct statfs *buf);
static ADL_RESULT adl_sys_vhangup(void);
static ADL_RESULT adl_sys_pivot_root(const char *newroot,const char *putold);
static ADL_RESULT adl_sys_chroot(const char *path);
static ADL_RESULT adl_sys_sync(void);
static ADL_RESULT adl_sys_syncfs(int fd);
static ADL_RESULT adl_sys_mount(const char *source,const char *target,const char *fstype,unsigned long mountflags,const void *data);
static ADL_RESULT adl_sys_umount(const char *target);
static ADL_RESULT adl_sys_umount2(const char *target,int flags);
static ADL_RESULT adl_sys_ioperm(unsigned long from,unsigned long num,int turnon);
static ADL_RESULT adl_sys_readahead(int fd,off_t offset,size_t count);
static ADL_RESULT adl_sys_setxattr(const char *path,const char *name,const void *value,size_t size,int flags);
static ADL_RESULT adl_sys_lsetxattr(const char *path,const char *name,const void *value,size_t size,int flags);
static ADL_RESULT adl_sys_fsetxattr(int fd,const char *name,const void *value,size_t size,int flags);
static ADL_RESULT adl_sys_getxattr(const char *path,const char *name,void *value,size_t size);
static ADL_RESULT adl_sys_lgetxattr(const char *path,const char *name,void *value,size_t size);
static ADL_RESULT adl_sys_fgetxattr(int fd,const char *name,void *value,size_t size);
static ADL_RESULT adl_sys_listxattr(const char *path,char *list,size_t size);
static ADL_RESULT adl_sys_llistxattr(const char *path,char *list,size_t size);
static ADL_RESULT adl_sys_flistxattr(int fd,char *list,size_t size);
static ADL_RESULT adl_sys_removexattr(const char *path,const char *name);
static ADL_RESULT adl_sys_lremovexattr(const char *path,const char *name);
static ADL_RESULT adl_sys_fremovexattr(int fd,const char *name);
static ADL_RESULT adl_sys_ioprio_set(int which,int who,int ioprio);
static ADL_RESULT adl_sys_ioprio_get(int which,int who);
static ADL_RESULT adl_sys_inotify_init();
static ADL_RESULT adl_sys_inotify_init1(int flags);
static ADL_RESULT adl_sys_inotify_add_watch(int fd,const char *path,uint32_t mask);
static ADL_RESULT adl_sys_inotify_rm_watch(int fd,int wd);
static ADL_RESULT adl_sys_access(const char *path,int mode);
static ADL_RESULT adl_sys_faccessat(int dirfd,const char *path,int mode,int flags);
static ADL_RESULT adl_sys_faccessat2(int dirfd,const char *path,int mode,int flags);
static ADL_RESULT adl_sys_quotactl(int op,const char *special,int id, caddr_t addr);
static ADL_RESULT adl_sys_io_setup(unsigned int nr_events,aio_context_t *ctx_id);
static ADL_RESULT adl_sys_io_destroy(aio_context_t ctx_id);
static ADL_RESULT adl_sys_io_getevents(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout);
static ADL_RESULT adl_sys_io_submit(aio_context_t ctx_id, long nr, struct iocb **iocb);
static ADL_RESULT adl_sys_io_cancel(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result);
static ADL_RESULT adl_sys_lookup_dcookie(uint64_t cookie, char *buffer,size_t len);
static ADL_RESULT adl_sys_epoll_create(int size);
static ADL_RESULT adl_sys_epoll_create1(int flags);
static ADL_RESULT adl_sys_epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout);
static ADL_RESULT adl_sys_epoll_pwait(int epfd, struct epoll_event *events,int maxevents, int timeout,const sigset_t *sigmask);
static ADL_RESULT adl_sys_epoll_pwait2(int epfd, struct epoll_event *events,int maxevents,const struct timespec * timeout,const sigset_t *sigmask);
static ADL_RESULT adl_sys_epoll_ctl(int epfd, int op, int fd,struct epoll_event *event);
static ADL_RESULT adl_sys_splice(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags);
static ADL_RESULT adl_sys_tee(int fd_in, int fd_out, size_t len, unsigned int flags);
static ADL_RESULT adl_sys_posix_fadvise64(int fd,off_t offset,off_t len,int advice);
static ADL_RESULT adl_sys_utime(const char *path,const struct utimbuf *times);
static ADL_RESULT adl_sys_utimes(const char *path,const struct timeval *times);
static ADL_RESULT adl_sys_utimensat(int dirfd, const char *path,const struct timespec *times, int flags);
static ADL_RESULT adl_sys_futimens(int fd,const struct timespec *times);
static ADL_RESULT adl_sys_sync_file_range(int fd, off_t offset, off_t count,unsigned int flags);
static ADL_RESULT adl_sys_fallocate(int fd, int mode, off_t offset, off_t len);
static ADL_RESULT adl_sys_fanotify_init(unsigned int flags, unsigned int event_f_flags);
static ADL_RESULT adl_sys_fanotify_mark(int fd, unsigned int flags,uint64_t mask, int dirfd, const char *path);
static ADL_RESULT adl_sys_name_to_handle_at(int dirfd, const char *path,struct file_handle *handle,int *mount_id, int flags);
static ADL_RESULT adl_sys_open_by_handle_at(int mount_fd, struct file_handle *handle,int flags);
static ADL_RESULT adl_sys_copy_file_range(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags);
static ADL_RESULT adl_sys_statx(int dirfd, const char *path, int flags,unsigned int mask, struct statx *statxbuf);
static ADL_RESULT adl_sys_close_range(unsigned int first, unsigned int last, int flags);
static ADL_RESULT adl_sys_mount_setattr(int dirfd, const char *path,unsigned int flags, struct mount_attr *attr, size_t size);
static ADL_RESULT adl_lib_mkfifo(const char *name,mode_t mode);
static ADL_RESULT adl_lib_mkfifoat(int dirfd,const char *name,mode_t mode);
static ADL_RESULT adl_lib_opendir(const char *str);
static ADL_RESULT adl_lib_fdopendir(int fd);
static ADL_RESULT adl_lib_readdir(DIR *dirp);
static ADL_RESULT adl_lib_rewinddir(DIR *dirp);
static ADL_RESULT adl_lib_closedir(DIR *dirp);
static ADL_RESULT adl_lib_dirfd(DIR *dirp);
static ADL_RESULT adl_sys_pause(void);
static ADL_RESULT adl_sys_nanosleep(const struct timespec *duration,struct timespec *remaining);
static ADL_RESULT adl_sys_getitimer(int which,struct itimerval *current);
static ADL_RESULT adl_sys_setitimer(int which,const struct itimerval *new,struct itimerval *old);
static ADL_RESULT adl_sys_alarm(unsigned int seconds);
static ADL_RESULT adl_sys_gettimeofday(struct timeval *tv,struct timezone *tz);
static ADL_RESULT adl_sys_settimeofday(const struct timeval *tv,const struct timezone *tz);
static ADL_RESULT adl_sys_timer_create(clockid_t clockid,struct sigevent *sigevent,timer_t *timerid);
static ADL_RESULT adl_sys_timer_settime(timer_t timerid, int flags,const struct itimerspec *new,struct itimerspec *old);
static ADL_RESULT adl_sys_timer_gettime(timer_t timerid, struct itimerspec *current);
static ADL_RESULT adl_sys_timer_getoverrun(timer_t timerid);
static ADL_RESULT adl_sys_timer_delete(timer_t timerid);
static ADL_RESULT adl_sys_clock_settime(clockid_t clockid,const struct timespec *tp);
static ADL_RESULT adl_sys_clock_gettime(clockid_t clockid,struct timespec *tp);
static ADL_RESULT adl_sys_clock_getres(clockid_t clockid,struct timespec *res);
static ADL_RESULT adl_sys_clock_nanosleep(clockid_t clockid, int flags,const struct timespec *duration,struct timespec *remaining);
static ADL_RESULT adl_sys_clock_adjtime(clockid_t clockid,struct timex *buf);
static ADL_RESULT adl_sys_adjtimex(struct timex *buf);
static ADL_RESULT adl_sys_time(time_t *timep);
static ADL_RESULT adl_sys_timerfd_settime(int fd,int flags,const struct itimerspec *new,struct itimerspec *old);
static ADL_RESULT adl_sys_timerfd_gettime(int fd,struct itimerspec *current);
static ADL_RESULT adl_sys_timerfd_create(int clockid, int flags);
static ADL_RESULT adl_sys_shmget(key_t key,size_t size,int flags);
static ADL_RESULT adl_sys_shmat(int id, const void *addr, int flags);
static ADL_RESULT adl_sys_shmctl(int id, int op, struct shmid_ds *buf);
static ADL_RESULT adl_sys_shmdt(const void *addr);
static ADL_RESULT adl_sys_msgget(key_t key, int flags);
static ADL_RESULT adl_sys_msgsnd(int id, const void *buf,size_t buflen,int flags);
static ADL_RESULT adl_sys_msgrcv(int id,void *buf,size_t buflen,long type,int flags);
static ADL_RESULT adl_sys_msgctl(int id, int op, struct msqid_ds *buf);
static ADL_RESULT adl_sys_mq_open_v1(const char *name,int flags);
static ADL_RESULT adl_sys_mq_open_v2(const char *name,int flags,mode_t mode,struct mq_attr *attr);
static ADL_RESULT adl_sys_mq_unlink(const char *name);
static ADL_RESULT adl_sys_mq_timedsend(mqd_t fd, const char *buf,size_t buflen, unsigned int priority,const struct timespec *timeout);
static ADL_RESULT adl_sys_mq_timedreceive(mqd_t fd,char *buf,size_t buflen, unsigned int *priority,const struct timespec *timeout);
static ADL_RESULT adl_sys_mq_notify(mqd_t fd, const struct sigevent *sigevent);
static ADL_RESULT adl_sys_mq_getsetattr(mqd_t fd,const struct mq_attr *new,struct mq_attr *old);
static ADL_RESULT adl_sys_semget(key_t key, int num, int flags);
static ADL_RESULT adl_sys_semop(int id, struct sembuf *sops, size_t num);
static ADL_RESULT adl_sys_semtimedop(int id, struct sembuf *sops, size_t num,const struct timespec *timeout);
static ADL_RESULT adl_sys_semctl(int id, int num,int op,...);
static ADL_RESULT adl_sys_futex(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3);
static ADL_RESULT adl_sys_set_robust_list(struct robust_list_head *head,size_t len);
static ADL_RESULT adl_sys_get_robust_list(int pid,struct robust_list_head **head, size_t *len);
static ADL_RESULT adl_sys_capget(cap_user_header_t hdrp,cap_user_data_t datap);
static ADL_RESULT adl_sys_capset(cap_user_header_t hdrp,const cap_user_data_t datap);
static ADL_RESULT adl_sys_clone3(struct clone_args *cl_args,size_t size);
static ADL_RESULT adl_sys_clone(int (*fn)(void *),void *stack,int flags,void *arg,pid_t *parent_tid,void *tls,pid_t *child_tid);
static ADL_RESULT adl_sys_execve(const char *pathname, char *const argv[],char *const envp[]);
static ADL_RESULT adl_sys_execveat(int dirfd,const char *pathname, char *const argv[],char *const envp[],int flags);
static void adl_sys_exit(int status);
static void adl_sys_exit_group(int status);
static ADL_RESULT adl_sys_fork();
static ADL_RESULT adl_sys_vfork();
static ADL_RESULT adl_sys_getcpu(unsigned int *cpu,unsigned int *node);
static ADL_RESULT adl_sys_getegid();
static ADL_RESULT adl_sys_geteuid();
static ADL_RESULT adl_sys_getgid();
static ADL_RESULT adl_sys_getgroups(int size,gid_t list[]);
static ADL_RESULT adl_sys_getpgid(pid_t pid);
static ADL_RESULT adl_sys_getpgrp();
static ADL_RESULT adl_sys_getpid();
static ADL_RESULT adl_sys_getppid();
static ADL_RESULT adl_sys_getpriority(int which,id_t who);
static ADL_RESULT adl_sys_getresgid(gid_t *rgid,gid_t *egid,gid_t *sgid);
static ADL_RESULT adl_sys_getresuid(uid_t *ruid,uid_t *euid,uid_t *suid);
static ADL_RESULT adl_sys_getrlimit(int resource,struct rlimit *rlim);
static ADL_RESULT adl_sys_getrusage(int who,struct rusage *usage);
static ADL_RESULT adl_sys_getsid(pid_t pid);
static ADL_RESULT adl_sys_get_thread_area(struct user_desc *u_info);
static ADL_RESULT adl_sys_gettid();
static ADL_RESULT adl_sys_getuid();
static ADL_RESULT adl_sys_kill(pid_t pid,int sig);
static ADL_RESULT adl_sys_pidfd_getfd(int pidfd,int targetfd,unsigned int flags);
static ADL_RESULT adl_sys_pidfd_open(pid_t pid,unsigned int flags);
static ADL_RESULT adl_sys_prctl(int op,unsigned long arg2,unsigned long arg3,unsigned long arg4, unsigned long arg5);
static ADL_RESULT adl_sys_prlimit(pid_t pid, int resource,const struct rlimit *new_limit,struct rlimit *old_limit);
static ADL_RESULT adl_sys_process_madvise(int pidfd,const struct iovec *iovec,size_t n,int advice,unsigned int flags);
static ADL_RESULT adl_sys_process_vm_readv(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags);
static ADL_RESULT adl_sys_process_vm_writev(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags);
static ADL_RESULT adl_sys_sched_getaffinity(pid_t pid,size_t cpusetsize,cpu_set_t *mask);
static ADL_RESULT adl_sys_sched_getattr(pid_t pid,struct sched_attr *attr,unsigned int size, unsigned int flags);
static ADL_RESULT adl_sys_sched_getparam(pid_t pid,struct sched_param *param);
static ADL_RESULT adl_sys_sched_get_priority_max(int policy);
static ADL_RESULT adl_sys_sched_get_priority_min(int policy);
static ADL_RESULT adl_sys_sched_getscheduler(pid_t pid);
static ADL_RESULT adl_sys_sched_rr_get_interval(pid_t pid, struct timespec *tp);
static ADL_RESULT adl_sys_sched_setaffinity(pid_t pid,size_t cpusetsize,const cpu_set_t *mask);
static ADL_RESULT adl_sys_sched_setattr(pid_t pid, struct sched_attr *attr,unsigned int flags);
static ADL_RESULT adl_sys_sched_setparam(pid_t pid,const struct sched_param *param);
static ADL_RESULT adl_sys_sched_setscheduler(pid_t pid, int policy,const struct sched_param *param);
static ADL_RESULT adl_sys_sched_yield();
static ADL_RESULT adl_sys_setgid(gid_t gid);
static ADL_RESULT adl_sys_setgroups(size_t size,const gid_t *list);
static ADL_RESULT adl_sys_setns(int fd,int nstype);
static ADL_RESULT adl_sys_setpgid(pid_t pid, pid_t pgid);
static ADL_RESULT adl_sys_setpriority(int which, id_t who, int prio);
static ADL_RESULT adl_sys_setregid(gid_t rgid, gid_t egid);
static ADL_RESULT adl_sys_setresgid(gid_t rgid,gid_t egid,gid_t sgid);
static ADL_RESULT adl_sys_setresuid(uid_t ruid,uid_t euid,uid_t suid);
static ADL_RESULT adl_sys_setreuid(uid_t ruid,uid_t euid);
static ADL_RESULT adl_sys_setrlimit(int resource,const struct rlimit *rlim);
static ADL_RESULT adl_sys_setsid(void);
static ADL_RESULT adl_sys_set_thread_area(struct user_desc *u_info);
static ADL_RESULT adl_sys_set_tid_address(int *tidptr);
static ADL_RESULT adl_sys_setuid(uid_t uid);
static ADL_RESULT adl_sys_tgkill(pid_t tgid,pid_t tid,int sig);
static ADL_RESULT adl_sys_unshare(int flags);
static ADL_RESULT adl_sys_wait4(pid_t pid,int *wstatus,int options,struct rusage *rusage);
static ADL_RESULT adl_sys_wait3(int *wstatus,int options,struct rusage *rusage);
static ADL_RESULT adl_sys_bpf(int cmd,union bpf_attr *attr,unsigned int size);
static ADL_RESULT adl_sys_modify_ldt(int func,void *ptr,unsigned long bytecount);
static ADL_RESULT adl_sys_seccomp(unsigned int operation,unsigned int flags,void *args);
static ADL_RESULT adl_sys_kcmp(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2);
static ADL_RESULT adl_sys_sigaction(int signum,const struct sigaction *newact,struct sigaction *oldact);
static ADL_RESULT adl_sys_sigpending(sigset_t *set);
static ADL_RESULT adl_sys_sigprocmask(int how,const sigset_t *newset,sigset_t *oldset);
static ADL_RESULT adl_sys_sigsuspend(const sigset_t *mask);
static ADL_RESULT adl_sys_sigtimedwait(const sigset_t *set,siginfo_t *info,const struct timespec *timeout);
static ADL_RESULT adl_sys_sigwaitinfo(const sigset_t *set,siginfo_t *info);
static ADL_RESULT adl_sys_signal(int signum,void (*handler)(int));
static ADL_RESULT adl_sys_pidfd_send_signal(int pidfd,int sig,siginfo_t *info,unsigned int flags);
static ADL_RESULT adl_sys_eventfd(unsigned int initval,int flags);
static ADL_RESULT adl_sys_signalfd(int fd,const sigset_t *mask,int flags);
static ADL_RESULT adl_sys_sigaltstack(const stack_t *newstack,stack_t *oldstack);
static ADL_RESULT adl_sys_reboot(int magic,int magic2,int op,void *arg);
static ADL_RESULT adl_sys_delete_module(const char *name,unsigned int flags);
static ADL_RESULT adl_sys_finit_module(int fd,const char *param_values,int flags);
static ADL_RESULT adl_sys_init_module(void *module_image,unsigned long len,const char *param_value);
static ADL_RESULT adl_sys_kexec_file_load(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags);
static ADL_RESULT adl_sys_kexec_load(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags);
static ADL_RESULT adl_sys_syslog(int type,char *bufp,int len);
static ADL_RESULT adl_sys_sysinfo(struct sysinfo *info);
static ADL_RESULT adl_sys_getrandom(void *buf,size_t buflen,unsigned int flags);
static ADL_RESULT adl_sys_setdomainname(const char *name,size_t len);
static ADL_RESULT adl_sys_getdomainname(char *name,size_t len);
static ADL_RESULT adl_sys_sethostname(const char *name,size_t len);
static ADL_RESULT adl_sys_gethostname(char *name,size_t len);
static ADL_RESULT adl_sys_brk(void *addr);
static ADL_RESULT adl_sys_sbrk(intptr_t increment);
static ADL_RESULT adl_sys_madvise(void *addr,size_t length,int advice);
static ADL_RESULT adl_sys_mincore(void *addr,size_t length,unsigned char *vec);
static ADL_RESULT adl_sys_get_mempolicy(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags);
static ADL_RESULT adl_sys_keyctl(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5);
static ADL_RESULT adl_sys_membarrier(int cmd,unsigned int flags,int cpu_id);
static ADL_RESULT adl_sys_memfd_secret(unsigned int flags);
static ADL_RESULT adl_sys_userfaultfd(int flags);
static ADL_RESULT adl_sys_mbind(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags);
static ADL_RESULT adl_sys_memfd_create(const char *name,unsigned int flags);
static ADL_RESULT adl_sys_migrate_pages(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes);
static ADL_RESULT adl_sys_mlock2(const void *addr,size_t len,unsigned int flags);
static ADL_RESULT adl_sys_mremap(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address);
static ADL_RESULT adl_sys_move_pages(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags);
static ADL_RESULT adl_sys_request_key(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring);
static ADL_RESULT adl_sys_pkey_alloc(unsigned int flags,unsigned int access_rights);
static ADL_RESULT adl_sys_pkey_free(int pkey);
static ADL_RESULT adl_sys_pkey_mprotect(void *addr,size_t len,int prot,int pkey);
static ADL_RESULT adl_sys_set_mempolicy(int mode,const unsigned long *nodemask,unsigned long maxnode);
static ADL_RESULT adl_sys_swapoff(const char *path);
static ADL_RESULT adl_sys_swapon(const char *path,int swapflags);
static ADL_RESULT adl_sys_vmsplice(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags);
static ADL_RESULT adl_sys_mlock(void *addr,size_t len);
static ADL_RESULT adl_sys_mlockall(int flags);
static ADL_RESULT adl_sys_mmap(void *addr,size_t len,int prot,int flags,int fd,off_t offset);
static ADL_RESULT adl_sys_mprotect(void *addr,size_t len,int prot);
static ADL_RESULT adl_sys_msync(void *addr,size_t len,int flags);
static ADL_RESULT adl_sys_munlock(const void *addr,size_t len);
static ADL_RESULT adl_sys_munlockall();
static ADL_RESULT adl_sys_munmap(void *addr,size_t len);
static ADL_RESULT adl_lib_getpwnam(const char *name);
static ADL_RESULT adl_lib_getpwuid(uid_t uid);
static ADL_RESULT adl_lib_getpwent();
static ADL_RESULT adl_lib_setpwent();
static ADL_RESULT adl_lib_endpwent();
static ADL_RESULT adl_lib_getgrnam(const char *name);
static ADL_RESULT adl_lib_getgrgid(gid_t gid);
static ADL_RESULT adl_lib_getgrent();
static ADL_RESULT adl_lib_setgrent();
static ADL_RESULT adl_lib_endgrent();
static ADL_RESULT adl_lib_getspnam(const char *name);
static ADL_RESULT adl_lib_getspent();
static ADL_RESULT adl_lib_setspent();
static ADL_RESULT adl_lib_endspent();
static ADL_RESULT adl_lib_crypt(const char *key,const char *salt);



#ifndef ADL_UNIX_INIT
#define ADL_UNIX_INIT(val,valptr)  ADL_S64_INIT(val);  \
                                   ADL_VOID_PTR_INIT(valptr); \
                                   ADL_ERRNO_INIT();   \
                                   ADL_RESULT_RETURN_DEFER_INIT();
#endif


#ifndef ADL_UNIX_FINI
#define ADL_UNIX_FINI(val,valptr)  if(ADL_CHECK_EQUAL(val,-1))                                                  \
                            {                                                                                   \
                                ADL_STRING str;                                                                 \
                                ADL_STRING_init(&str,ADL_STRERROR(errno));                                      \
                                ADL_RESULT_RETURN_DEFER(failed_syscall, ADL_RESULT_WRITE(val,str,valptr));      \
                            }                                                                                   \
                                                                                                                \
                            ADL_RESULT_RETURN_DEFER(success_syscall,ADL_RESULT_WRITE(val,(ADL_STRING){},valptr));  \
                                               \
                            failed_syscall:    \
                            success_syscall:   \
                                ADL_RESULT_RETURN_DEFER_FINI()                                

#endif



#endif

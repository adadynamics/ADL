#ifndef ADL_UNIX_UNIX_H
#define ADL_UNIX_UNIX_H


#include "../common/utils.h"
#include "../ds/string.h"


#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <poll.h>
#include <sys/syscall.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/statfs.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/uio.h>
#include <sys/select.h>
#include <sys/file.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <sys/io.h>
#include <sys/xattr.h>
#include <linux/ioprio.h>
#include <sys/inotify.h>
#include <sys/quota.h>

#ifdef ADL_XFS_XQM_H
#include <xfs/xqm.h>
#endif
#include  <linux/dqblk_xfs.h>
#include <linux/aio_abi.h>
#include <sys/epoll.h>

#include <sys/time.h>
#include <utime.h>
#include <sys/fanotify.h>
#include <linux/close_range.h>
#include <linux/mount.h>
#include <time.h>
#include <sys/timerfd.h>
#include <sys/wait.h>
#include <sys/timex.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <mqueue.h>
#include <signal.h>
#include <linux/futex.h>
#include <sys/sendfile.h>
#include <linux/openat2.h>
#include <sys/syscall.h>
#include <dirent.h>
#include <sys/sem.h>
#include <linux/capability.h>
#include <linux/sched.h>
#include <linux/sched/types.h>
#include <sched.h>
#include <sys/prctl.h>
#include <sys/resource.h>
#include <asm/ldt.h>
#include <linux/seccomp.h>
#include <linux/filter.h>
#include <linux/audit.h>
#include <linux/version.h>
#include <sys/ptrace.h>
#include <linux/bpf.h> 
#include <grp.h>
#include <crypt.h>
#include <pwd.h>
#include <sys/uio.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/eventfd.h>
#include <sys/signalfd.h>
#include <linux/reboot.h>
#include <linux/module.h>
#include <linux/kexec.h>
#include <sys/klog.h>
#include <sys/sysinfo.h>
#include <sys/random.h>
#include <numaif.h>
//#include <linux/keyctl.h>
#include <linux/membarrier.h>
#include <keyutils.h>
#include <linux/userfaultfd.h>
#include <sys/swap.h>
#include <sys/mman.h>
#include <shadow.h>





typedef struct ADL_Unix
{
    ADL_Result (*socket)(int domain,int type,int protocol);
    ADL_Result (*socketpair)(int domain,int type,int protocol,int sockfds[2]);
    ADL_Result (*bind)(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
    ADL_Result (*connect)(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
    ADL_Result (*listen)(int sockfd,int backlog);
    ADL_Result (*accept)(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
    ADL_Result (*accept4)(int sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags);
    ADL_Result (*recv)(int sockfd,void *buf,size_t buflen,int flags);
    ADL_Result (*recvfrom)(int sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen);
    ADL_Result (*recvmsg)(int sockfd,struct msghdr *msg,int flags);
    ADL_Result (*recvmmsg)(int sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout);
    ADL_Result (*send)(int sockfd,const void *buf,size_t buflen,int flags);
    ADL_Result (*sendto)(int sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen);
    ADL_Result (*sendmsg)(int sockfd,const struct msghdr *msg,int flags);
    ADL_Result (*sendmmsg)(int sockfd,struct mmsghdr *msgvec,int vlen,int flags);
    ADL_Result (*shutdown)(int sockfd,int how);
    ADL_Result (*close)(int fd);
    ADL_Result (*getsockopt)(int sockfd,int level,int optname,void *optval,socklen_t *optlen);
    ADL_Result (*setsockopt)(int sockfd,int level,int optname,void *optval,socklen_t optlen);
    ADL_Result (*getsockname)(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
    ADL_Result (*getpeername)(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
    ADL_Result (*getaddrinfo)(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);
    ADL_Result (*freeaddrinfo)(struct addrinfo *res);
    ADL_Result (*getnameinfo)(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,int flags);
    u16 (*htons)(u16 hostshort);
    u32 (*htonl)(u32 hostlong);
    u16 (*ntohs)(u16 netshort);
    u32 (*ntohl)(u32 netlong);
    ADL_Result (*open)(const char *pathname,int flags,mode_t mode);
    ADL_Result (*creat)(const char *pathname,mode_t mode);
    ADL_Result (*openat)(int dirfd,const char *pathname,int flags,mode_t mode);
    ADL_Result (*openat2)(int dirfd,const char *pathname,struct open_how *how,size_t size);
    ADL_Result (*read)(int fd,void *buf,size_t buflen);
    ADL_Result (*write)(int fd,const void *buf,size_t buflen);
    ADL_Result (*sendfile)(int outfd,int infd,off_t *offset,size_t count);
    //ADL_Result (*close)(int fd);
    ADL_Result (*stat)(const char *pathname,struct stat *statbuf);
    ADL_Result (*fstat)(int fd,struct stat *statbuf);
    ADL_Result (*lstat)(const char *pathname,struct stat *statbuf);
    ADL_Result (*fstatat)(int dirfd,const char *pathname,struct stat *statbuf,int flags);
    ADL_Result (*poll)(struct pollfd *fds,nfds_t nfds,int timeout);
    ADL_Result (*ppoll)(struct pollfd *fds,nfds_t nfds,const struct timespec *timeout,const sigset_t *sigmask);
    ADL_Result (*lseek)(int fd,off_t offset,int whence);
    ADL_Result (*ioctl)(int fd,u64 operation,char *argp);
    ADL_Result (*pread)(int fd,void *buf,size_t buflen,off_t offset);
    ADL_Result (*pwrite)(int fd,const void *buf,size_t buflen,off_t offset);
    ADL_Result (*readv)(int fd,const struct iovec *iov,int iovcnt);
    ADL_Result (*writev)(int fd,const struct iovec *iov,int iovcnt);
    ADL_Result (*preadv)(int fd,const struct iovec *iov,int iovcnt,off_t offset);
    ADL_Result (*pwritev)(int fd,const struct iovec *iov,int iovcnt,off_t offset);
    ADL_Result (*preadv2)(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags);
    ADL_Result (*pwritev2)(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags);
    ADL_Result (*pipe)(int pipefd[]);
    ADL_Result (*pipe2)(int pipefd[],int flags);
    ADL_Result (*select)(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout);
    ADL_Result (*pselect)(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,const struct timespec *timeout,const sigset_t *sigmask);
    ADL_Result (*dup)(int fd);
    ADL_Result (*dup2)(int oldfd,int newfd);
    ADL_Result (*dup3)(int oldfd,int newfd,int flags);
    ADL_Result (*flock)(int fd,int op);
    ADL_Result (*fsync)(int fd);
    ADL_Result (*fdatasync)(int fd);
    ADL_Result (*truncate)(const char *path,off_t length);
    ADL_Result (*ftruncate)(int fd,off_t length);
    ADL_Result (*getcwd)(char *buf,size_t bufsize);
    ADL_Result (*chdir)(const char *path);
    ADL_Result (*fchdir)(int fd);
    ADL_Result (*rename)(const char *oldpath,const char *newpath);
    ADL_Result (*renameat)(int olddirfd,const char *oldpath,int newdirfd,const char *newpath);
    ADL_Result (*renameat2)(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags);
    ADL_Result (*mkdir)(const char *path,mode_t mode);
    ADL_Result (*mkdirat)(int dirfd,const char *path,mode_t mode);
    ADL_Result (*rmdir)(const char *path);
    ADL_Result (*link)(const char *oldpath,const char *newpath);
    ADL_Result (*linkat)(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags);
    ADL_Result (*unlink)(const char *path);
    ADL_Result (*unlinkat)(int dirfd,const char *path,int flags);
    ADL_Result (*symlink)(const char *target,const char *linkpath);
    ADL_Result (*symlinkat)(const char *target,int newdirfd,const char *linkpath);
    ADL_Result (*readlink)(const char *path,char *buf,size_t bufsize);
    ADL_Result (*readlinkat)(int dirfd,const char *path,char *buf,size_t bufsize);
    ADL_Result (*chmod)(const char *path,mode_t mode);
    ADL_Result (*fchmod)(int fd,mode_t mode);
    ADL_Result (*fchmodat)(int dirfd,const char *path,mode_t mode,int flags);
    ADL_Result (*chown)(const char *path,uid_t owner,gid_t group);
    ADL_Result (*lchown)(const char *path,uid_t owner,gid_t group);
    ADL_Result (*fchown)(int fd,uid_t owner,gid_t group);
    ADL_Result (*fchownat)(int dirfd,const char *path,uid_t owner,gid_t group,int flags);
    ADL_Result (*umask)(mode_t mask);
    ADL_Result (*mknod)(const char *path,mode_t mode,dev_t dev);
    ADL_Result (*mknodat)(int dirfd,const char *path,mode_t mode,dev_t dev);
    ADL_Result (*statfs)(const char *path,struct statfs *buf);
    ADL_Result (*fstatfs)(int fd,struct statfs *buf);
    ADL_Result (*vhangup)(void);
    ADL_Result (*pivot_root)(const char *newroot,const char *putold);
    ADL_Result (*chroot)(const char *path);
    ADL_Result (*sync)(void);
    ADL_Result (*syncfs)(int fd);
    ADL_Result (*mount)(const char *source,const char *target,const char *fstype,unsigned long mountflags,const void *data);
    ADL_Result (*umount)(const char *target);
    ADL_Result (*umount2)(const char *target,int flags);
    ADL_Result (*ioperm)(unsigned long from,unsigned long num,int turnon);
    ADL_Result (*readahead)(int fd,off_t offset,size_t count);
    ADL_Result (*setxattr)(const char *path,const char *name,const void *value,size_t size,int flags);
    ADL_Result (*lsetxattr)(const char *path,const char *name,const void *value,size_t size,int flags);
    ADL_Result (*fsetxattr)(int fd,const char *name,const void *value,size_t size,int flags);
    ADL_Result (*getxattr)(const char *path,const char *name,void *value,size_t size);
    ADL_Result (*lgetxattr)(const char *path,const char *name,void *value,size_t size);
    ADL_Result (*fgetxattr)(int fd,const char *name,void *value,size_t size);
    ADL_Result (*listxattr)(const char *path,char *list,size_t size);
    ADL_Result (*llistxattr)(const char *path,char *list,size_t size);
    ADL_Result (*flistxattr)(int fd,char *list,size_t size);
    ADL_Result (*removexattr)(const char *path,const char *name);
    ADL_Result (*lremovexattr)(const char *path,const char *name);
    ADL_Result (*fremovexattr)(int fd,const char *name);
    ADL_Result (*ioprio_set)(int which,int who,int ioprio);
    ADL_Result (*ioprio_get)(int which,int who);
    ADL_Result (*inotify_init)();
    ADL_Result (*inotify_init1)(int flags);
    ADL_Result (*inotify_add_watch)(int fd,const char *path,uint32_t mask);
    ADL_Result (*inotify_rm_watch)(int fd,int wd);
    ADL_Result (*access)(const char *path,int mode);
    ADL_Result (*faccessat)(int dirfd,const char *path,int mode,int flags);
    ADL_Result (*faccessat2)(int dirfd,const char *path,int mode,int flags);
    ADL_Result (*quotactl)(int op,const char *special,int id, caddr_t addr);
    ADL_Result (*io_setup)(unsigned int nr_events,aio_context_t *ctx_id);
    ADL_Result (*io_destroy)(aio_context_t ctx_id);
    ADL_Result (*io_getevents)(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout);
    ADL_Result (*io_submit)(aio_context_t ctx_id, long nr, struct iocb **iocb);
    ADL_Result (*io_cancel)(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result);
    ADL_Result (*lookup_dcookie)(uint64_t cookie, char *buffer,size_t len);
    ADL_Result (*epoll_create)(int size);
    ADL_Result (*epoll_create1)(int flags);
    ADL_Result (*epoll_wait)(int epfd, struct epoll_event *events,int maxevents, int timeout);
    ADL_Result (*epoll_pwait)(int epfd, struct epoll_event *events,int maxevents, int timeout,const sigset_t *sigmask);
    ADL_Result (*epoll_pwait2)(int epfd, struct epoll_event *events,int maxevents,const struct timespec * timeout,const sigset_t *sigmask);
    ADL_Result (*epoll_ctl)(int epfd, int op, int fd,struct epoll_event *event);
    ADL_Result (*splice)(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags);
    ADL_Result (*tee)(int fd_in, int fd_out, size_t len, unsigned int flags);
    ADL_Result (*posix_fadvise64)(int fd,off_t offset,off_t len,int advice);
    ADL_Result (*utime)(const char *path,const struct utimbuf *times);
    ADL_Result (*utimes)(const char *path,const struct timeval *times);
    ADL_Result (*utimensat)(int dirfd, const char *path,const struct timespec *times, int flags);
    ADL_Result (*futimens)(int fd,const struct timespec *times);
    ADL_Result (*sync_file_range)(int fd, off_t offset, off_t count,unsigned int flags);
    ADL_Result (*fallocate)(int fd, int mode, off_t offset, off_t len);
    ADL_Result (*fanotify_init)(unsigned int flags, unsigned int event_f_flags);
    ADL_Result (*fanotify_mark)(int fd, unsigned int flags,uint64_t mask, int dirfd, const char *path);
    ADL_Result (*name_to_handle_at)(int dirfd, const char *path,struct file_handle *handle,int *mount_id, int flags);
    ADL_Result (*open_by_handle_at)(int mount_fd, struct file_handle *handle,int flags);
    ADL_Result (*copy_file_range)(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags);
    ADL_Result (*statx)(int dirfd, const char *path, int flags,unsigned int mask, struct statx *statxbuf);
    ADL_Result (*close_range)(unsigned int first, unsigned int last, int flags);
    ADL_Result (*mount_setattr)(int dirfd, const char *path,unsigned int flags, struct mount_attr *attr, size_t size);
    ADL_Result (*mkfifo)(const char *name,mode_t mode);
    ADL_Result (*mkfifoat)(int dirfd,const char *name,mode_t mode);
    ADL_Result (*opendir)(const char *str);
    ADL_Result (*fdopendir)(int fd);
    ADL_Result (*readdir)(DIR *dirp);
    ADL_Result (*rewinddir)(DIR *dirp);
    ADL_Result (*closedir)(DIR *dirp);
    ADL_Result (*dirfd)(DIR *dirp);
    ADL_Result (*pause)(void);
    ADL_Result (*nanosleep)(const struct timespec *duration,struct timespec *remaining);
    ADL_Result (*getitimer)(int which,struct itimerval *current);
    ADL_Result (*setitimer)(int which,const struct itimerval *new,struct itimerval *old);
    ADL_Result (*alarm)(unsigned int seconds);
    ADL_Result (*gettimeofday)(struct timeval *tv,struct timezone *tz);
    ADL_Result (*settimeofday)(const struct timeval *tv,const struct timezone *tz);
    ADL_Result (*timer_create)(clockid_t clockid,struct sigevent *sigevent,timer_t *timerid);
    ADL_Result (*timer_settime)(timer_t timerid, int flags,const struct itimerspec *new,struct itimerspec *old);
    ADL_Result (*timer_gettime)(timer_t timerid, struct itimerspec *current);
    ADL_Result (*timer_getoverrun)(timer_t timerid);
    ADL_Result (*timer_delete)(timer_t timerid);
    ADL_Result (*clock_settime)(clockid_t clockid,const struct timespec *tp);
    ADL_Result (*clock_gettime)(clockid_t clockid,struct timespec *tp);
    ADL_Result (*clock_getres)(clockid_t clockid,struct timespec *res);
    ADL_Result (*clock_nanosleep)(clockid_t clockid, int flags,const struct timespec *duration,struct timespec *remaining);
    ADL_Result (*clock_adjtime)(clockid_t clockid,struct timex *buf);
    ADL_Result (*adjtimex)(struct timex *buf);
    ADL_Result (*time)(time_t *timep);
    ADL_Result (*timerfd_settime)(int fd,int flags,const struct itimerspec *new,struct itimerspec *old);
    ADL_Result (*timerfd_gettime)(int fd,struct itimerspec *current);
    ADL_Result (*timerfd_create)(int clockid, int flags);
    ADL_Result (*shmget)(key_t key,size_t size,int flags);
    ADL_Result (*shmat)(int id, const void *addr, int flags);
    ADL_Result (*shmctl)(int id, int op, struct shmid_ds *buf);
    ADL_Result (*shmdt)(const void *addr);
    ADL_Result (*msgget)(key_t key, int flags);
    ADL_Result (*msgsnd)(int id, const void *buf,size_t buflen,int flags);
    ADL_Result (*msgrcv)(int id,void *buf,size_t buflen,long type,int flags);
    ADL_Result (*msgctl)(int id, int op, struct msqid_ds *buf);
    ADL_Result (*mq_open_v1)(const char *name,int flags);
    ADL_Result (*mq_open_v2)(const char *name,int flags,mode_t mode,struct mq_attr *attr);
    ADL_Result (*mq_unlink)(const char *name);
    ADL_Result (*mq_timedsend)(mqd_t fd, const char *buf,size_t buflen, unsigned int priority,const struct timespec *timeout);
    ADL_Result (*mq_timedreceive)(mqd_t fd,char *buf,size_t buflen, unsigned int *priority,const struct timespec *timeout);
    ADL_Result (*mq_notify)(mqd_t fd, const struct sigevent *sigevent);
    ADL_Result (*mq_getsetattr)(mqd_t fd,const struct mq_attr *new,struct mq_attr *old);
    ADL_Result (*semget)(key_t key, int num, int flags);
    ADL_Result (*semop)(int id, struct sembuf *sops, size_t num);
    ADL_Result (*semtimedop)(int id, struct sembuf *sops, size_t num,const struct timespec *timeout);
    ADL_Result (*semctl)(int id, int num,int op,...);
    ADL_Result (*futex)(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3);
    ADL_Result (*set_robust_list)(struct robust_list_head *head,size_t len);
    ADL_Result (*get_robust_list)(int pid,struct robust_list_head **head, size_t *len);
    ADL_Result (*capget)(cap_user_header_t hdrp,cap_user_data_t datap);
    ADL_Result (*capset)(cap_user_header_t hdrp,const cap_user_data_t datap);
    ADL_Result (*clone3)(struct clone_args *cl_args,size_t size);
    ADL_Result (*clone)(int (*fn)(void *),void *stack,int flags,void *arg,pid_t *parent_tid,void *tls,pid_t *child_tid);
    ADL_Result (*execve)(const char *pathname, char *const argv[],char *const envp[]);
    ADL_Result (*execveat)(int dirfd,const char *pathname, char *const argv[],char *const envp[],int flags);
    void (*exit)(int status);
    void (*exit_group)(int status);
    ADL_Result (*fork)();
    ADL_Result (*vfork)();
    ADL_Result (*getcpu)(unsigned int *cpu,unsigned int *node);
    ADL_Result (*getegid)();
    ADL_Result (*geteuid)();
    ADL_Result (*getgid)();
    ADL_Result (*getgroups)(int size,gid_t list[]);
    ADL_Result (*getpgid)(pid_t pid);
    ADL_Result (*getpgrp)();
    ADL_Result (*getpid)();
    ADL_Result (*getppid)();
    ADL_Result (*getpriority)(int which,id_t who);
    ADL_Result (*getresgid)(gid_t *rgid,gid_t *egid,gid_t *sgid);
    ADL_Result (*getresuid)(uid_t *ruid,uid_t *euid,uid_t *suid);
    ADL_Result (*getrlimit)(int resource,struct rlimit *rlim);
    ADL_Result (*getrusage)(int who,struct rusage *usage);
    ADL_Result (*getsid)(pid_t pid);
    ADL_Result (*get_thread_area)(struct user_desc *u_info);
    ADL_Result (*gettid)();
    ADL_Result (*getuid)();
    ADL_Result (*kill)(pid_t pid,int sig);
    ADL_Result (*pidfd_getfd)(int pidfd,int targetfd,unsigned int flags);
    ADL_Result (*pidfd_open)(pid_t pid,unsigned int flags);
    ADL_Result (*prctl)(int op,unsigned long arg2,unsigned long arg3,unsigned long arg4, unsigned long arg5);
    ADL_Result (*prlimit)(pid_t pid, int resource,const struct rlimit *new_limit,struct rlimit *old_limit);
    ADL_Result (*process_madvise)(int pidfd,const struct iovec *iovec,size_t n,int advice,unsigned int flags);
    ADL_Result (*process_vm_readv)(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags);
    ADL_Result (*process_vm_writev)(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags);
    ADL_Result (*sched_getaffinity)(pid_t pid,size_t cpusetsize,cpu_set_t *mask);
    ADL_Result (*sched_getattr)(pid_t pid,struct sched_attr *attr,unsigned int size, unsigned int flags);
    ADL_Result (*sched_getparam)(pid_t pid,struct sched_param *param);
    ADL_Result (*sched_get_priority_max)(int policy);
    ADL_Result (*sched_get_priority_min)(int policy);
    ADL_Result (*sched_getscheduler)(pid_t pid);
    ADL_Result (*sched_rr_get_interval)(pid_t pid, struct timespec *tp);
    ADL_Result (*sched_setaffinity)(pid_t pid,size_t cpusetsize,const cpu_set_t *mask);
    ADL_Result (*sched_setattr)(pid_t pid, struct sched_attr *attr,unsigned int flags);
    ADL_Result (*sched_setparam)(pid_t pid,const struct sched_param *param);
    ADL_Result (*sched_setscheduler)(pid_t pid, int policy,const struct sched_param *param);
    ADL_Result (*sched_yield)();
    ADL_Result (*setgid)(gid_t gid);
    ADL_Result (*setgroups)(size_t size,const gid_t *list);
    ADL_Result (*setns)(int fd,int nstype);
    ADL_Result (*setpgid)(pid_t pid, pid_t pgid);
    ADL_Result (*setpriority)(int which, id_t who, int prio);
    ADL_Result (*setregid)(gid_t rgid, gid_t egid);
    ADL_Result (*setresgid)(gid_t rgid,gid_t egid,gid_t sgid);
    ADL_Result (*setresuid)(uid_t ruid,uid_t euid,uid_t suid);
    ADL_Result (*setreuid)(uid_t ruid,uid_t euid);
    ADL_Result (*setrlimit)(int resource,const struct rlimit *rlim);
    ADL_Result (*setsid)(void);
    ADL_Result (*set_thread_area)(struct user_desc *u_info);
    ADL_Result (*set_tid_address)(int *tidptr);
    ADL_Result (*setuid)(uid_t uid);
    ADL_Result (*tgkill)(pid_t tgid,pid_t tid,int sig);
    ADL_Result (*unshare)(int flags);
    ADL_Result (*wait4)(pid_t pid,int *wstatus,int options,struct rusage *rusage);
    ADL_Result (*wait3)(int *wstatus,int options,struct rusage *rusage);
    ADL_Result (*bpf)(int cmd,union bpf_attr *attr,unsigned int size);
    ADL_Result (*modify_ldt)(int func,void *ptr,unsigned long bytecount);
    ADL_Result (*seccomp)(unsigned int operation,unsigned int flags,void *args);
    ADL_Result (*kcmp)(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2);
    ADL_Result (*sigaction)(int signum,const struct sigaction *newact,struct sigaction *oldact);
    ADL_Result (*sigpending)(sigset_t *set);
    ADL_Result (*sigprocmask)(int how,const sigset_t *newset,sigset_t *oldset);
    ADL_Result (*sigsuspend)(const sigset_t *mask);
    ADL_Result (*sigtimedwait)(const sigset_t *set,siginfo_t *info,const struct timespec *timeout);
    ADL_Result (*sigwaitinfo)(const sigset_t *set,siginfo_t *info);
    ADL_Result (*signal)(int signum,void (*handler)(int));
    ADL_Result (*pidfd_send_signal)(int pidfd,int sig,siginfo_t *info,unsigned int flags);
    ADL_Result (*eventfd)(unsigned int initval,int flags);
    ADL_Result (*signalfd)(int fd,const sigset_t *mask,int flags);
    ADL_Result (*sigaltstack)(const stack_t *newstack,stack_t *oldstack);
    ADL_Result (*reboot)(int magic,int magic2,int op,void *arg);
    ADL_Result (*delete_module)(const char *name,unsigned int flags);
    ADL_Result (*finit_module)(int fd,const char *param_values,int flags);
    ADL_Result (*init_module)(void *module_image,unsigned long len,const char *param_value);
    ADL_Result (*kexec_file_load)(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags);
    ADL_Result (*kexec_load)(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags);
    ADL_Result (*syslog)(int type,char *bufp,int len);
    ADL_Result (*sysinfo)(struct sysinfo *info);
    ADL_Result (*getrandom)(void *buf,size_t buflen,unsigned int flags);
    ADL_Result (*setdomainname)(const char *name,size_t len);
    ADL_Result (*getdomainname)(char *name,size_t len);
    ADL_Result (*sethostname)(const char *name,size_t len);
    ADL_Result (*gethostname)(char *name,size_t len);
    ADL_Result (*brk)(void *addr);
    ADL_Result (*sbrk)(intptr_t increment);
    ADL_Result (*madvise)(void *addr,size_t length,int advice);
    ADL_Result (*mincore)(void *addr,size_t length,unsigned char *vec);
    ADL_Result (*get_mempolicy)(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags);
    ADL_Result (*keyctl)(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5);
    ADL_Result (*membarrier)(int cmd,unsigned int flags,int cpu_id);
    ADL_Result (*memfd_secret)(unsigned int flags);
    ADL_Result (*userfaultfd)(int flags);
    ADL_Result (*mbind)(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags);
    ADL_Result (*memfd_create)(const char *name,unsigned int flags);
    ADL_Result (*migrate_pages)(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes);
    ADL_Result (*mlock2)(const void *addr,size_t len,unsigned int flags);
    ADL_Result (*mremap)(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address);
    ADL_Result (*move_pages)(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags);
    ADL_Result (*request_key)(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring);
    ADL_Result (*pkey_alloc)(unsigned int flags,unsigned int access_rights);
    ADL_Result (*pkey_free)(int pkey);
    ADL_Result (*pkey_mprotect)(void *addr,size_t len,int prot,int pkey);
    ADL_Result (*set_mempolicy)(int mode,const unsigned long *nodemask,unsigned long maxnode);
    ADL_Result (*swapoff)(const char *path);
    ADL_Result (*swapon)(const char *path,int swapflags);
    ADL_Result (*vmsplice)(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags);
    ADL_Result (*mlock)(void *addr,size_t len);
    ADL_Result (*mlockall)(int flags);
    ADL_Result (*mmap)(void *addr,size_t len,int prot,int flags,int fd,off_t offset);
    ADL_Result (*mprotect)(void *addr,size_t len,int prot);
    ADL_Result (*msync)(void *addr,size_t len,int flags);
    ADL_Result (*munlock)(const void *addr,size_t len);
    ADL_Result (*munlockall)();
    ADL_Result (*munmap)(void *addr,size_t len);
    ADL_Result (*getpwnam)(const char *name);
    ADL_Result (*getpwuid)(uid_t uid);
    ADL_Result (*getpwent)();
    ADL_Result (*setpwent)();
    ADL_Result (*endpwent)();
    ADL_Result (*getgrnam)(const char *name);
    ADL_Result (*getgrgid)(gid_t gid);
    ADL_Result (*getgrent)();
    ADL_Result (*setgrent)();
    ADL_Result (*endgrent)();
    ADL_Result (*getspnam)(const char *name);
    ADL_Result (*getspent)();
    ADL_Result (*setspent)();
    ADL_Result (*endspent)();
    ADL_Result (*crypt)(const char *key,const char *salt);
}ADL_Unix;


void ADL_Unix_init(ADL_Unix *adl_unix);

void ADL_Unix_fini(ADL_Unix *adl_unix);



#endif

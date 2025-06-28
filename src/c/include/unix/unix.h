#ifndef ADL_UNIX_UNIX_H
#define ADL_UNIX_UNIX_H


#include "../common/utils.h"
#include "../ds/string.h"


#ifdef ADL_OS_UNIX

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
#include <sys/times.h>
#include <pthread.h>

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


#ifndef ADL_SOCKET_DESC
#define ADL_SOCKET_DESC int
#endif

#ifndef ADL_INVALID_SOCKET
#define ADL_INVALID_SOCKET -1
#endif


#ifndef ADL_SOCKET_ERRNO
#define ADL_SOCKET_ERRNO errno
#endif





typedef struct ADL_UNIX
{
    bool (*SocketInit)(void);
    bool (*SocketFini)(void);
    ADL_RESULT (*socket)(int domain,int type,int protocol);
    ADL_RESULT (*socketpair)(int domain,int type,int protocol,int sockfds[2]);
    ADL_RESULT (*bind)(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
    ADL_RESULT (*connect)(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
    ADL_RESULT (*listen)(int sockfd,int backlog);
    ADL_RESULT (*accept)(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
    ADL_RESULT (*accept4)(int sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags);
    ADL_RESULT (*recv)(int sockfd,void *buf,size_t buflen,int flags);
    ADL_RESULT (*recvfrom)(int sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen);
    ADL_RESULT (*recvmsg)(int sockfd,struct msghdr *msg,int flags);
    ADL_RESULT (*recvmmsg)(int sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout);
    ADL_RESULT (*send)(int sockfd,const void *buf,size_t buflen,int flags);
    ADL_RESULT (*sendto)(int sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen);
    ADL_RESULT (*sendmsg)(int sockfd,const struct msghdr *msg,int flags);
    ADL_RESULT (*sendmmsg)(int sockfd,struct mmsghdr *msgvec,int vlen,int flags);
    ADL_RESULT (*shutdown)(int sockfd,int how);
    ADL_RESULT (*close)(int fd);
    ADL_RESULT (*getsockopt)(int sockfd,int level,int optname,void *optval,socklen_t *optlen);
    ADL_RESULT (*setsockopt)(int sockfd,int level,int optname,void *optval,socklen_t optlen);
    ADL_RESULT (*getsockname)(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
    ADL_RESULT (*getpeername)(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
    ADL_RESULT (*getaddrinfo)(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);
    ADL_RESULT (*freeaddrinfo)(struct addrinfo *res);
    ADL_RESULT (*getnameinfo)(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,int flags);
    ADL_RESULT (*htons)(u16 hostshort);
    ADL_RESULT (*htonl)(u32 hostlong);
    ADL_RESULT (*ntohs)(u16 netshort);
    ADL_RESULT (*ntohl)(u32 netlong);
    ADL_RESULT (*open)(const char *pathname,int flags,mode_t mode);
    ADL_RESULT (*creat)(const char *pathname,mode_t mode);
    ADL_RESULT (*openat)(int dirfd,const char *pathname,int flags,mode_t mode);
    ADL_RESULT (*openat2)(int dirfd,const char *pathname,struct open_how *how,size_t size);
    ADL_RESULT (*read)(int fd,void *buf,size_t buflen);
    ADL_RESULT (*write)(int fd,const void *buf,size_t buflen);
    ADL_RESULT (*sendfile)(int outfd,int infd,off_t *offset,size_t count);
    //ADL_RESULT (*close)(int fd);
    ADL_RESULT (*stat)(const char *pathname,struct stat *statbuf);
    ADL_RESULT (*fstat)(int fd,struct stat *statbuf);
    ADL_RESULT (*lstat)(const char *pathname,struct stat *statbuf);
    ADL_RESULT (*fstatat)(int dirfd,const char *pathname,struct stat *statbuf,int flags);
    ADL_RESULT (*poll)(struct pollfd *fds,nfds_t nfds,int timeout);
    ADL_RESULT (*ppoll)(struct pollfd *fds,nfds_t nfds,const struct timespec *timeout,const sigset_t *sigmask);
    ADL_RESULT (*lseek)(int fd,off_t offset,int whence);
    ADL_RESULT (*ioctl)(int fd,u64 operation,char *argp);
    ADL_RESULT (*pread)(int fd,void *buf,size_t buflen,off_t offset);
    ADL_RESULT (*pwrite)(int fd,const void *buf,size_t buflen,off_t offset);
    ADL_RESULT (*readv)(int fd,const struct iovec *iov,int iovcnt);
    ADL_RESULT (*writev)(int fd,const struct iovec *iov,int iovcnt);
    ADL_RESULT (*preadv)(int fd,const struct iovec *iov,int iovcnt,off_t offset);
    ADL_RESULT (*pwritev)(int fd,const struct iovec *iov,int iovcnt,off_t offset);
    ADL_RESULT (*preadv2)(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags);
    ADL_RESULT (*pwritev2)(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags);
    ADL_RESULT (*pipe)(int pipefd[]);
    ADL_RESULT (*pipe2)(int pipefd[],int flags);
    ADL_RESULT (*select)(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout);
    ADL_RESULT (*pselect)(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,const struct timespec *timeout,const sigset_t *sigmask);
    ADL_RESULT (*dup)(int fd);
    ADL_RESULT (*dup2)(int oldfd,int newfd);
    ADL_RESULT (*dup3)(int oldfd,int newfd,int flags);
    ADL_RESULT (*flock)(int fd,int op);
    ADL_RESULT (*fsync)(int fd);
    ADL_RESULT (*fdatasync)(int fd);
    ADL_RESULT (*truncate)(const char *path,off_t length);
    ADL_RESULT (*ftruncate)(int fd,off_t length);
    ADL_RESULT (*getcwd)(char *buf,size_t buf_size);
    ADL_RESULT (*chdir)(const char *path);
    ADL_RESULT (*fchdir)(int fd);
    ADL_RESULT (*rename)(const char *oldpath,const char *newpath);
    ADL_RESULT (*renameat)(int olddirfd,const char *oldpath,int newdirfd,const char *newpath);
    ADL_RESULT (*renameat2)(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags);
    ADL_RESULT (*mkdir)(const char *path,mode_t mode);
    ADL_RESULT (*mkdirat)(int dirfd,const char *path,mode_t mode);
    ADL_RESULT (*rmdir)(const char *path);
    ADL_RESULT (*link)(const char *oldpath,const char *newpath);
    ADL_RESULT (*linkat)(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags);
    ADL_RESULT (*unlink)(const char *path);
    ADL_RESULT (*unlinkat)(int dirfd,const char *path,int flags);
    ADL_RESULT (*symlink)(const char *target,const char *linkpath);
    ADL_RESULT (*symlinkat)(const char *target,int newdirfd,const char *linkpath);
    ADL_RESULT (*readlink)(const char *path,char *buf,size_t buf_size);
    ADL_RESULT (*readlinkat)(int dirfd,const char *path,char *buf,size_t buf_size);
    ADL_RESULT (*chmod)(const char *path,mode_t mode);
    ADL_RESULT (*fchmod)(int fd,mode_t mode);
    ADL_RESULT (*fchmodat)(int dirfd,const char *path,mode_t mode,int flags);
    ADL_RESULT (*chown)(const char *path,uid_t owner,gid_t group);
    ADL_RESULT (*lchown)(const char *path,uid_t owner,gid_t group);
    ADL_RESULT (*fchown)(int fd,uid_t owner,gid_t group);
    ADL_RESULT (*fchownat)(int dirfd,const char *path,uid_t owner,gid_t group,int flags);
    ADL_RESULT (*umask)(mode_t mask);
    ADL_RESULT (*mknod)(const char *path,mode_t mode,dev_t dev);
    ADL_RESULT (*mknodat)(int dirfd,const char *path,mode_t mode,dev_t dev);
    ADL_RESULT (*statfs)(const char *path,struct statfs *buf);
    ADL_RESULT (*fstatfs)(int fd,struct statfs *buf);
    ADL_RESULT (*vhangup)(void);
    ADL_RESULT (*pivot_root)(const char *newroot,const char *putold);
    ADL_RESULT (*chroot)(const char *path);
    ADL_RESULT (*sync)(void);
    ADL_RESULT (*syncfs)(int fd);
    ADL_RESULT (*mount)(const char *source,const char *target,const char *fstype,unsigned long mountflags,const void *data);
    ADL_RESULT (*umount)(const char *target);
    ADL_RESULT (*umount2)(const char *target,int flags);
    ADL_RESULT (*ioperm)(unsigned long from,unsigned long num,int turnon);
    ADL_RESULT (*readahead)(int fd,off_t offset,size_t count);
    ADL_RESULT (*setxattr)(const char *path,const char *name,const void *value,size_t size,int flags);
    ADL_RESULT (*lsetxattr)(const char *path,const char *name,const void *value,size_t size,int flags);
    ADL_RESULT (*fsetxattr)(int fd,const char *name,const void *value,size_t size,int flags);
    ADL_RESULT (*getxattr)(const char *path,const char *name,void *value,size_t size);
    ADL_RESULT (*lgetxattr)(const char *path,const char *name,void *value,size_t size);
    ADL_RESULT (*fgetxattr)(int fd,const char *name,void *value,size_t size);
    ADL_RESULT (*listxattr)(const char *path,char *list,size_t size);
    ADL_RESULT (*llistxattr)(const char *path,char *list,size_t size);
    ADL_RESULT (*flistxattr)(int fd,char *list,size_t size);
    ADL_RESULT (*removexattr)(const char *path,const char *name);
    ADL_RESULT (*lremovexattr)(const char *path,const char *name);
    ADL_RESULT (*fremovexattr)(int fd,const char *name);
    ADL_RESULT (*ioprio_set)(int which,int who,int ioprio);
    ADL_RESULT (*ioprio_get)(int which,int who);
    ADL_RESULT (*inotify_init)();
    ADL_RESULT (*inotify_init1)(int flags);
    ADL_RESULT (*inotify_add_watch)(int fd,const char *path,uint32_t mask);
    ADL_RESULT (*inotify_rm_watch)(int fd,int wd);
    ADL_RESULT (*access)(const char *path,int mode);
    ADL_RESULT (*faccessat)(int dirfd,const char *path,int mode,int flags);
    ADL_RESULT (*faccessat2)(int dirfd,const char *path,int mode,int flags);
    ADL_RESULT (*quotactl)(int op,const char *special,int id, caddr_t addr);
    ADL_RESULT (*io_setup)(unsigned int nr_events,aio_context_t *ctx_id);
    ADL_RESULT (*io_destroy)(aio_context_t ctx_id);
    ADL_RESULT (*io_getevents)(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout);
    ADL_RESULT (*io_submit)(aio_context_t ctx_id, long nr, struct iocb **iocb);
    ADL_RESULT (*io_cancel)(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result);
    ADL_RESULT (*lookup_dcookie)(uint64_t cookie, char *buffer,size_t len);
    ADL_RESULT (*epoll_create)(int size);
    ADL_RESULT (*epoll_create1)(int flags);
    ADL_RESULT (*epoll_wait)(int epfd, struct epoll_event *events,int maxevents, int timeout);
    ADL_RESULT (*epoll_pwait)(int epfd, struct epoll_event *events,int maxevents, int timeout,const sigset_t *sigmask);
    ADL_RESULT (*epoll_pwait2)(int epfd, struct epoll_event *events,int maxevents,const struct timespec * timeout,const sigset_t *sigmask);
    ADL_RESULT (*epoll_ctl)(int epfd, int op, int fd,struct epoll_event *event);
    ADL_RESULT (*splice)(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags);
    ADL_RESULT (*tee)(int fd_in, int fd_out, size_t len, unsigned int flags);
    ADL_RESULT (*posix_fadvise64)(int fd,off_t offset,off_t len,int advice);
    ADL_RESULT (*utime)(const char *path,const struct utimbuf *times);
    ADL_RESULT (*utimes)(const char *path,const struct timeval *times);
    ADL_RESULT (*utimensat)(int dirfd, const char *path,const struct timespec *times, int flags);
    ADL_RESULT (*futimens)(int fd,const struct timespec *times);
    ADL_RESULT (*sync_file_range)(int fd, off_t offset, off_t count,unsigned int flags);
    ADL_RESULT (*fallocate)(int fd, int mode, off_t offset, off_t len);
    ADL_RESULT (*fanotify_init)(unsigned int flags, unsigned int event_f_flags);
    ADL_RESULT (*fanotify_mark)(int fd, unsigned int flags,uint64_t mask, int dirfd, const char *path);
    ADL_RESULT (*name_to_handle_at)(int dirfd, const char *path,struct file_handle *handle,int *mount_id, int flags);
    ADL_RESULT (*open_by_handle_at)(int mount_fd, struct file_handle *handle,int flags);
    ADL_RESULT (*copy_file_range)(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags);
    ADL_RESULT (*statx)(int dirfd, const char *path, int flags,unsigned int mask, struct statx *statxbuf);
    ADL_RESULT (*close_range)(unsigned int first, unsigned int last, int flags);
    ADL_RESULT (*mount_setattr)(int dirfd, const char *path,unsigned int flags, struct mount_attr *attr, size_t size);
    ADL_RESULT (*mkfifo)(const char *name,mode_t mode);
    ADL_RESULT (*mkfifoat)(int dirfd,const char *name,mode_t mode);
    ADL_RESULT (*opendir)(const char *str);
    ADL_RESULT (*fdopendir)(int fd);
    ADL_RESULT (*readdir)(DIR *dirp);
    ADL_RESULT (*rewinddir)(DIR *dirp);
    ADL_RESULT (*closedir)(DIR *dirp);
    ADL_RESULT (*dirfd)(DIR *dirp);


    ADL_RESULT (*pause)(void);
    ADL_RESULT (*nanosleep)(const struct timespec *duration,struct timespec *remaining);
    ADL_RESULT (*getitimer)(int which,struct itimerval *current);
    ADL_RESULT (*setitimer)(int which,const struct itimerval *new,struct itimerval *old);
    ADL_RESULT (*alarm)(unsigned int seconds);
    ADL_RESULT (*gettimeofday)(struct timeval *tv,struct timezone *tz);
    ADL_RESULT (*settimeofday)(const struct timeval *tv,const struct timezone *tz);
    ADL_RESULT (*timer_create)(clockid_t clockid,struct sigevent *sigevent,timer_t *timerid);
    ADL_RESULT (*timer_settime)(timer_t timerid, int flags,const struct itimerspec *new,struct itimerspec *old);
    ADL_RESULT (*timer_gettime)(timer_t timerid, struct itimerspec *current);
    ADL_RESULT (*timer_getoverrun)(timer_t timerid);
    ADL_RESULT (*timer_delete)(timer_t timerid);
    ADL_RESULT (*clock_settime)(clockid_t clockid,const struct timespec *tp);
    ADL_RESULT (*clock_gettime)(clockid_t clockid,struct timespec *tp);
    ADL_RESULT (*clock_getres)(clockid_t clockid,struct timespec *res);
    ADL_RESULT (*clock_nanosleep)(clockid_t clockid, int flags,const struct timespec *duration,struct timespec *remaining);
    ADL_RESULT (*clock_adjtime)(clockid_t clockid,struct timex *buf);
    ADL_RESULT (*adjtimex)(struct timex *buf);
    ADL_RESULT (*time)(time_t *timep);
    ADL_RESULT (*timerfd_settime)(int fd,int flags,const struct itimerspec *new,struct itimerspec *old);
    ADL_RESULT (*timerfd_gettime)(int fd,struct itimerspec *current);
    ADL_RESULT (*timerfd_create)(int clockid, int flags);
    ADL_RESULT (*shmget)(key_t key,size_t size,int flags);
    ADL_RESULT (*shmat)(int id, const void *addr, int flags);
    ADL_RESULT (*shmctl)(int id, int op, struct shmid_ds *buf);
    ADL_RESULT (*shmdt)(const void *addr);
    ADL_RESULT (*msgget)(key_t key, int flags);
    ADL_RESULT (*msgsnd)(int id, const void *buf,size_t buflen,int flags);
    ADL_RESULT (*msgrcv)(int id,void *buf,size_t buflen,long type,int flags);
    ADL_RESULT (*msgctl)(int id, int op, struct msqid_ds *buf);
    ADL_RESULT (*mq_open_v1)(const char *name,int flags);
    ADL_RESULT (*mq_open_v2)(const char *name,int flags,mode_t mode,struct mq_attr *attr);
    ADL_RESULT (*mq_unlink)(const char *name);
    ADL_RESULT (*mq_timedsend)(mqd_t fd, const char *buf,size_t buflen, unsigned int priority,const struct timespec *timeout);
    ADL_RESULT (*mq_timedreceive)(mqd_t fd,char *buf,size_t buflen, unsigned int *priority,const struct timespec *timeout);
    ADL_RESULT (*mq_notify)(mqd_t fd, const struct sigevent *sigevent);
    ADL_RESULT (*mq_getsetattr)(mqd_t fd,const struct mq_attr *new,struct mq_attr *old);
    ADL_RESULT (*semget)(key_t key, int num, int flags);
    ADL_RESULT (*semop)(int id, struct sembuf *sops, size_t num);
    ADL_RESULT (*semtimedop)(int id, struct sembuf *sops, size_t num,const struct timespec *timeout);
    ADL_RESULT (*semctl)(int id, int num,int op,...);
    ADL_RESULT (*futex)(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3);
    ADL_RESULT (*set_robust_list)(struct robust_list_head *head,size_t len);
    ADL_RESULT (*get_robust_list)(int pid,struct robust_list_head **head, size_t *len);



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




    ADL_RESULT (*sigaction)(int signum,const struct sigaction *newact,struct sigaction *oldact);
    ADL_RESULT (*sigpending)(sigset_t *set);
    ADL_RESULT (*sigprocmask)(int how,const sigset_t *newset,sigset_t *oldset);
    ADL_RESULT (*sigsuspend)(const sigset_t *mask);
    ADL_RESULT (*sigtimedwait)(const sigset_t *set,siginfo_t *info,const struct timespec *timeout);
    ADL_RESULT (*sigwaitinfo)(const sigset_t *set,siginfo_t *info);
    ADL_RESULT (*signal)(int signum,void (*handler)(int));
    ADL_RESULT (*pidfd_send_signal)(int pidfd,int sig,siginfo_t *info,unsigned int flags);
    ADL_RESULT (*eventfd)(unsigned int initval,int flags);
    ADL_RESULT (*signalfd)(int fd,const sigset_t *mask,int flags);
    ADL_RESULT (*sigaltstack)(const stack_t *newstack,stack_t *oldstack);
    ADL_RESULT (*reboot)(int magic,int magic2,int op,void *arg);
    ADL_RESULT (*delete_module)(const char *name,unsigned int flags);
    ADL_RESULT (*finit_module)(int fd,const char *param_values,int flags);
    ADL_RESULT (*init_module)(void *module_image,unsigned long len,const char *param_value);
    ADL_RESULT (*kexec_file_load)(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags);
    ADL_RESULT (*kexec_load)(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags);
    ADL_RESULT (*syslog)(int type,char *bufp,int len);
    ADL_RESULT (*sysinfo)(struct sysinfo *info);
    ADL_RESULT (*getrandom)(void *buf,size_t buflen,unsigned int flags);
    ADL_RESULT (*setdomainname)(const char *name,size_t len);
    ADL_RESULT (*getdomainname)(char *name,size_t len);
    ADL_RESULT (*sethostname)(const char *name,size_t len);
    ADL_RESULT (*gethostname)(char *name,size_t len);
    ADL_RESULT (*brk)(void *addr);
    ADL_RESULT (*sbrk)(intptr_t increment);
    ADL_RESULT (*madvise)(void *addr,size_t length,int advice);
    ADL_RESULT (*mincore)(void *addr,size_t length,unsigned char *vec);
    ADL_RESULT (*get_mempolicy)(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags);
    ADL_RESULT (*keyctl)(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5);
    ADL_RESULT (*membarrier)(int cmd,unsigned int flags,int cpu_id);
    ADL_RESULT (*memfd_secret)(unsigned int flags);
    ADL_RESULT (*userfaultfd)(int flags);
    ADL_RESULT (*mbind)(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags);
    ADL_RESULT (*memfd_create)(const char *name,unsigned int flags);
    ADL_RESULT (*migrate_pages)(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes);
    ADL_RESULT (*mlock2)(const void *addr,size_t len,unsigned int flags);
    ADL_RESULT (*mremap)(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address);
    ADL_RESULT (*move_pages)(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags);
    ADL_RESULT (*request_key)(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring);
    ADL_RESULT (*pkey_alloc)(unsigned int flags,unsigned int access_rights);
    ADL_RESULT (*pkey_free)(int pkey);
    ADL_RESULT (*pkey_mprotect)(void *addr,size_t len,int prot,int pkey);
    ADL_RESULT (*set_mempolicy)(int mode,const unsigned long *nodemask,unsigned long maxnode);
    ADL_RESULT (*swapoff)(const char *path);
    ADL_RESULT (*swapon)(const char *path,int swapflags);
    ADL_RESULT (*vmsplice)(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags);
    ADL_RESULT (*mlock)(void *addr,size_t len);
    ADL_RESULT (*mlockall)(int flags);
    ADL_RESULT (*mmap)(void *addr,size_t len,int prot,int flags,int fd,off_t offset);
    ADL_RESULT (*mprotect)(void *addr,size_t len,int prot);
    ADL_RESULT (*msync)(void *addr,size_t len,int flags);
    ADL_RESULT (*munlock)(const void *addr,size_t len);
    ADL_RESULT (*munlockall)();
    ADL_RESULT (*munmap)(void *addr,size_t len);



    ADL_RESULT (*pthread_attr_destroy)(pthread_attr_t *attr);
    ADL_RESULT (*pthread_getcpuclockid)(pthread_t thread, clockid_t *clockid);
    ADL_RESULT (*pthread_attr_getaffinity_np)(const pthread_attr_t *attr,size_t cpusetsize,cpu_set_t *cpuset);
    ADL_RESULT (*pthread_getname_np)(pthread_t thread, char *name,size_t size);
    ADL_RESULT (*pthread_attr_getdetachstate)(const pthread_attr_t *attr,int *detachstate);
    ADL_RESULT (*pthread_getschedparam)(pthread_t thread,int *restrict policy,struct sched_param *restrict param);
    ADL_RESULT (*pthread_attr_getguardsize)(const pthread_attr_t *restrict attr,size_t *restrict guardsize);
    ADL_RESULT (*pthread_join)(pthread_t thread,void **retval);
    ADL_RESULT (*pthread_attr_getinheritsched)(const pthread_attr_t *restrict attr,int *restrict inheritsched);
    ADL_RESULT (*pthread_kill)(pthread_t thread,int sig);
    ADL_RESULT (*pthread_attr_getschedparam)(const pthread_attr_t *restrict attr,struct sched_param *restrict param);
    ADL_RESULT (*pthread_attr_getschedpolicy)(const pthread_attr_t *restrict attr,int *restrict policy);
    ADL_RESULT (*pthread_mutexattr_getpshared)(const pthread_mutexattr_t *restrict attr,int *restrict pshared);
    ADL_RESULT (*pthread_attr_getscope)(const pthread_attr_t *restrict attr,int *restrict scope);
    ADL_RESULT (*pthread_mutexattr_getrobust)(const pthread_mutexattr_t *attr,int *robustness);
    ADL_RESULT (*pthread_attr_getsigmask_np)(const pthread_attr_t *attr,sigset_t *sigmask);
    ADL_RESULT (*pthread_attr_getstack)(const pthread_attr_t *restrict attr,void **restrict stackaddr,size_t *restrict stacksize);
    ADL_RESULT (*pthread_mutexattr_setpshared)(pthread_mutexattr_t *attr,int pshared);
    ADL_RESULT (*pthread_mutexattr_setrobust)(pthread_mutexattr_t *attr,int robustness);
    ADL_RESULT (*pthread_attr_getstacksize)(const pthread_attr_t *restrict attr,size_t *restrict stacksize);
    ADL_RESULT (*pthread_attr_init)(pthread_attr_t *attr);
    ADL_RESULT (*pthread_mutex_consistent)(pthread_mutex_t *mutex);
    ADL_RESULT (*pthread_attr_setaffinity_np)(pthread_attr_t *attr,size_t cpusetsize,const cpu_set_t *cpuset);
    ADL_RESULT (*pthread_attr_setdetachstate)(pthread_attr_t *attr,int detachstate);
    ADL_RESULT (*pthread_rwlockattr_getkind_np)(const pthread_rwlockattr_t *restrict attr,int *restrict pref);
    ADL_RESULT (*pthread_attr_setguardsize)(pthread_attr_t *attr,size_t guardsize);
    ADL_RESULT (*pthread_rwlockattr_setkind_np)(pthread_rwlockattr_t *attr,int pref);
    ADL_RESULT (*pthread_attr_setinheritsched)(pthread_attr_t *attr,int inheritsched);
    ADL_RESULT (*pthread_self)(void);
    ADL_RESULT (*pthread_attr_setschedparam)(pthread_attr_t *restrict attr,const struct sched_param *restrict param);
    ADL_RESULT (*pthread_setaffinity_np)(pthread_t thread,size_t cpusetsize,const cpu_set_t *cpuset);
    ADL_RESULT (*pthread_attr_setschedpolicy)(pthread_attr_t *attr,int policy);
    ADL_RESULT (*pthread_setattr_default_np)(const pthread_attr_t *attr);
    ADL_RESULT (*pthread_attr_setscope)(pthread_attr_t *attr,int scope);
    ADL_RESULT (*pthread_setcancelstate)(int state,int *oldstate);
    ADL_RESULT (*pthread_attr_setsigmask_np)(pthread_attr_t *attr,const sigset_t *sigmask);
    ADL_RESULT (*pthread_setcanceltype)(int type,int *oldtype);
    ADL_RESULT (*pthread_attr_setstack)(pthread_attr_t *attr,void *stackaddr,size_t stacksize);
    ADL_RESULT (*pthread_setconcurrency)(int new_level);
    ADL_RESULT (*pthread_setname_np)(pthread_t thread,const char *name);
    ADL_RESULT (*pthread_attr_setstacksize)(pthread_attr_t *attr,size_t stacksize);
    ADL_RESULT (*pthread_setschedparam)(pthread_t thread,int policy,const struct sched_param *param);
    ADL_RESULT (*pthread_cancel)(pthread_t thread);
    ADL_RESULT (*pthread_setschedprio)(pthread_t thread,int prio);
    ADL_RESULT (*pthread_sigmask)(int how,const sigset_t *set,sigset_t *oldset);
    ADL_RESULT (*pthread_sigqueue)(pthread_t thread,int sig,const union sigval value);
    ADL_RESULT (*pthread_spin_destroy)(pthread_spinlock_t *lock);
    ADL_RESULT (*pthread_spin_init)(pthread_spinlock_t *lock,int pshared);
    ADL_RESULT (*pthread_create)(pthread_t *restrict thread,const pthread_attr_t *restrict attr,void *(*start_routine)(void *),void *restrict arg);
    ADL_RESULT (*pthread_spin_lock)(pthread_spinlock_t *lock);
    ADL_RESULT (*pthread_detach)(pthread_t thread);
    ADL_RESULT (*pthread_spin_trylock)(pthread_spinlock_t *lock);
    ADL_RESULT (*pthread_equal)(pthread_t t1,pthread_t t2);
    ADL_RESULT (*pthread_spin_unlock)(pthread_spinlock_t *lock);
    ADL_RESULT (*pthread_exit)(void *retval);
    ADL_RESULT (*pthread_testcancel)(void);
    ADL_RESULT (*pthread_getaffinity_np)(pthread_t thread,size_t cpusetsize,cpu_set_t *cpuset);
    ADL_RESULT (*pthread_timedjoin_np)(pthread_t thread,void **retval,const struct timespec *abstime);
    ADL_RESULT (*pthread_getattr_default_np)(pthread_attr_t *attr);
    ADL_RESULT (*pthread_tryjoin_np)(pthread_t thread,void **retval);
    ADL_RESULT (*pthread_getattr_np)(pthread_t thread,pthread_attr_t *attr);
    ADL_RESULT (*pthread_getconcurrency)(void);



    ADL_RESULT (*getpwnam)(const char *name);
    ADL_RESULT (*getpwuid)(uid_t uid);
    ADL_RESULT (*getpwent)();
    ADL_RESULT (*setpwent)();
    ADL_RESULT (*endpwent)();
    ADL_RESULT (*getgrnam)(const char *name);
    ADL_RESULT (*getgrgid)(gid_t gid);
    ADL_RESULT (*getgrent)();
    ADL_RESULT (*setgrent)();
    ADL_RESULT (*endgrent)();
    ADL_RESULT (*getspnam)(const char *name);
    ADL_RESULT (*getspent)();
    ADL_RESULT (*setspent)();
    ADL_RESULT (*endspent)();
    ADL_RESULT (*crypt)(const char *key,const char *salt);
}ADL_UNIX;


void ADL_UNIX_Init(ADL_UNIX *adl_unix);

void ADL_UNIX_Fini(ADL_UNIX *adl_unix);


#endif

#endif

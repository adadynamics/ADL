#ifndef ADL_OS_FILES_FILE_LINUX_H
#define ADL_OS_FILES_FILE_LINUX_H

#include "../os.h"


typedef struct ADL_FILE_LINUX
{
	ADL_RESULT (*open)(const char *pathname,int flags,mode_t mode);
    ADL_RESULT (*creat)(const char *pathname,mode_t mode);
    ADL_RESULT (*openat)(int dirfd,const char *pathname,int flags,mode_t mode);
    ADL_RESULT (*openat2)(int dirfd,const char *pathname,struct open_how *how,size_t size);
    ADL_RESULT (*read)(int fd,void *buf,size_t buflen);
    ADL_RESULT (*write)(int fd,const void *buf,size_t buflen);
    ADL_RESULT (*sendfile)(int outfd,int infd,off_t *offset,size_t count);
    ADL_RESULT (*close)(int fd);
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

}ADL_FILE_LINUX;



void ADL_FILE_LINUX_init(ADL_FILE_LINUX *file);

void ADL_FILE_LINUX_fini(ADL_FILE_LINUX *file);


#endif

#ifndef ADL_SRC_UNIX_FILE_FILE_H
#define ADL_SRC_UNIX_FILE_FILE_H

#include "../unix.h"

#ifdef ADL_OS_UNIX



/*

    FILE I/O

*/




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








ADL_RESULT adl_sys_open(const char *pathname,int flags,mode_t mode);
ADL_RESULT adl_sys_creat(const char *pathname,mode_t mode);
ADL_RESULT adl_sys_openat(int dirfd,const char *pathname,int flags,mode_t mode);
ADL_RESULT adl_sys_openat2(int dirfd,const char *pathname,struct open_how *how,size_t size);
ADL_RESULT adl_sys_read(int fd,void *buf,size_t buflen);
ADL_RESULT adl_sys_write(int fd,const void *buf,size_t buflen);
ADL_RESULT adl_sys_sendfile(int outfd,int infd,off_t *offset,size_t count);
ADL_RESULT adl_sys_close(int fd);
ADL_RESULT adl_sys_stat(const char *pathname,struct stat *statbuf);
ADL_RESULT adl_sys_fstat(int fd,struct stat *statbuf);
ADL_RESULT adl_sys_lstat(const char *pathname,struct stat *statbuf);
ADL_RESULT adl_sys_fstatat(int dirfd,const char *pathname,struct stat *statbuf,int flags);
ADL_RESULT adl_sys_poll(struct pollfd *fds,nfds_t nfds,int timeout);
ADL_RESULT adl_sys_ppoll(struct pollfd *fds,nfds_t nfds,const struct timespec *timeout,const sigset_t *sigmask);
ADL_RESULT adl_sys_lseek(int fd,off_t offset,int whence);
ADL_RESULT adl_sys_ioctl(int fd,u64 operation,char *argp);
ADL_RESULT adl_sys_pread(int fd,void *buf,size_t buflen,off_t offset);
ADL_RESULT adl_sys_pwrite(int fd,const void *buf,size_t buflen,off_t offset);
ADL_RESULT adl_sys_readv(int fd,const struct iovec *iov,int iovcnt);
ADL_RESULT adl_sys_writev(int fd,const struct iovec *iov,int iovcnt);
ADL_RESULT adl_sys_preadv(int fd,const struct iovec *iov,int iovcnt,off_t offset);
ADL_RESULT adl_sys_pwritev(int fd,const struct iovec *iov,int iovcnt,off_t offset);
ADL_RESULT adl_sys_preadv2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags);
ADL_RESULT adl_sys_pwritev2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags);
ADL_RESULT adl_sys_pipe(int pipefd[]);
ADL_RESULT adl_sys_pipe2(int pipefd[],int flags);
ADL_RESULT adl_sys_select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout);
ADL_RESULT adl_sys_pselect(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,const struct timespec *timeout,const sigset_t *sigmask);
ADL_RESULT adl_sys_dup(int fd);
ADL_RESULT adl_sys_dup2(int oldfd,int newfd);
ADL_RESULT adl_sys_dup3(int oldfd,int newfd,int flags);
ADL_RESULT adl_sys_flock(int fd,int op);
ADL_RESULT adl_sys_fsync(int fd);
ADL_RESULT adl_sys_fdatasync(int fd);
ADL_RESULT adl_sys_truncate(const char *path,off_t length);
ADL_RESULT adl_sys_ftruncate(int fd,off_t length);
ADL_RESULT adl_sys_getcwd(char *buf,size_t buf_size);
ADL_RESULT adl_sys_chdir(const char *path);
ADL_RESULT adl_sys_fchdir(int fd);
ADL_RESULT adl_sys_rename(const char *oldpath,const char *newpath);
ADL_RESULT adl_sys_renameat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath);
ADL_RESULT adl_sys_renameat2(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags);
ADL_RESULT adl_sys_mkdir(const char *path,mode_t mode);
ADL_RESULT adl_sys_mkdirat(int dirfd,const char *path,mode_t mode);
ADL_RESULT adl_sys_rmdir(const char *path);
ADL_RESULT adl_sys_link(const char *oldpath,const char *newpath);
ADL_RESULT adl_sys_linkat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags);
ADL_RESULT adl_sys_unlink(const char *path);
ADL_RESULT adl_sys_unlinkat(int dirfd,const char *path,int flags);
ADL_RESULT adl_sys_symlink(const char *target,const char *linkpath);
ADL_RESULT adl_sys_symlinkat(const char *target,int newdirfd,const char *linkpath);
ADL_RESULT adl_sys_readlink(const char *path,char *buf,size_t buf_size);
ADL_RESULT adl_sys_readlinkat(int dirfd,const char *path,char *buf,size_t buf_size);
ADL_RESULT adl_sys_chmod(const char *path,mode_t mode);
ADL_RESULT adl_sys_fchmod(int fd,mode_t mode);
ADL_RESULT adl_sys_fchmodat(int dirfd,const char *path,mode_t mode,int flags);
ADL_RESULT adl_sys_chown(const char *path,uid_t owner,gid_t group);
ADL_RESULT adl_sys_lchown(const char *path,uid_t owner,gid_t group);
ADL_RESULT adl_sys_fchown(int fd,uid_t owner,gid_t group);
ADL_RESULT adl_sys_fchownat(int dirfd,const char *path,uid_t owner,gid_t group,int flags);
ADL_RESULT adl_sys_umask(mode_t mask);
ADL_RESULT adl_sys_mknod(const char *path,mode_t mode,dev_t dev);
ADL_RESULT adl_sys_mknodat(int dirfd,const char *path,mode_t mode,dev_t dev);
ADL_RESULT adl_sys_statfs(const char *path,struct statfs *buf);
ADL_RESULT adl_sys_fstatfs(int fd,struct statfs *buf);
ADL_RESULT adl_sys_vhangup(void);
ADL_RESULT adl_sys_pivot_root(const char *newroot,const char *putold);
ADL_RESULT adl_sys_chroot(const char *path);
ADL_RESULT adl_sys_sync(void);
ADL_RESULT adl_sys_syncfs(int fd);
ADL_RESULT adl_sys_mount(const char *source,const char *target,const char *fstype,unsigned long mountflags,const void *data);
ADL_RESULT adl_sys_umount(const char *target);
ADL_RESULT adl_sys_umount2(const char *target,int flags);
ADL_RESULT adl_sys_ioperm(unsigned long from,unsigned long num,int turnon);
ADL_RESULT adl_sys_readahead(int fd,off_t offset,size_t count);
ADL_RESULT adl_sys_setxattr(const char *path,const char *name,const void *value,size_t size,int flags);
ADL_RESULT adl_sys_lsetxattr(const char *path,const char *name,const void *value,size_t size,int flags);
ADL_RESULT adl_sys_fsetxattr(int fd,const char *name,const void *value,size_t size,int flags);
ADL_RESULT adl_sys_getxattr(const char *path,const char *name,void *value,size_t size);
ADL_RESULT adl_sys_lgetxattr(const char *path,const char *name,void *value,size_t size);
ADL_RESULT adl_sys_fgetxattr(int fd,const char *name,void *value,size_t size);
ADL_RESULT adl_sys_listxattr(const char *path,char *list,size_t size);
ADL_RESULT adl_sys_llistxattr(const char *path,char *list,size_t size);
ADL_RESULT adl_sys_flistxattr(int fd,char *list,size_t size);
ADL_RESULT adl_sys_removexattr(const char *path,const char *name);
ADL_RESULT adl_sys_lremovexattr(const char *path,const char *name);
ADL_RESULT adl_sys_fremovexattr(int fd,const char *name);
ADL_RESULT adl_sys_ioprio_set(int which,int who,int ioprio);
ADL_RESULT adl_sys_ioprio_get(int which,int who);
ADL_RESULT adl_sys_inotify_init();
ADL_RESULT adl_sys_inotify_init1(int flags);
ADL_RESULT adl_sys_inotify_add_watch(int fd,const char *path,uint32_t mask);
ADL_RESULT adl_sys_inotify_rm_watch(int fd,int wd);
ADL_RESULT adl_sys_access(const char *path,int mode);
ADL_RESULT adl_sys_faccessat(int dirfd,const char *path,int mode,int flags);
ADL_RESULT adl_sys_faccessat2(int dirfd,const char *path,int mode,int flags);
ADL_RESULT adl_sys_quotactl(int op,const char *special,int id, caddr_t addr);
ADL_RESULT adl_sys_io_setup(unsigned int nr_events,aio_context_t *ctx_id);
ADL_RESULT adl_sys_io_destroy(aio_context_t ctx_id);
ADL_RESULT adl_sys_io_getevents(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout);
ADL_RESULT adl_sys_io_submit(aio_context_t ctx_id, long nr, struct iocb **iocb);
ADL_RESULT adl_sys_io_cancel(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result);
ADL_RESULT adl_sys_lookup_dcookie(uint64_t cookie, char *buffer,size_t len);
ADL_RESULT adl_sys_epoll_create(int size);
ADL_RESULT adl_sys_epoll_create1(int flags);
ADL_RESULT adl_sys_epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout);
ADL_RESULT adl_sys_epoll_pwait(int epfd, struct epoll_event *events,int maxevents, int timeout,const sigset_t *sigmask);
ADL_RESULT adl_sys_epoll_pwait2(int epfd, struct epoll_event *events,int maxevents,const struct timespec * timeout,const sigset_t *sigmask);
ADL_RESULT adl_sys_epoll_ctl(int epfd, int op, int fd,struct epoll_event *event);
ADL_RESULT adl_sys_splice(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags);
ADL_RESULT adl_sys_tee(int fd_in, int fd_out, size_t len, unsigned int flags);
ADL_RESULT adl_sys_posix_fadvise64(int fd,off_t offset,off_t len,int advice);
ADL_RESULT adl_sys_utime(const char *path,const struct utimbuf *times);
ADL_RESULT adl_sys_utimes(const char *path,const struct timeval *times);
ADL_RESULT adl_sys_utimensat(int dirfd, const char *path,const struct timespec *times, int flags);
ADL_RESULT adl_sys_futimens(int fd,const struct timespec *times);
ADL_RESULT adl_sys_sync_file_range(int fd, off_t offset, off_t count,unsigned int flags);
ADL_RESULT adl_sys_fallocate(int fd, int mode, off_t offset, off_t len);
ADL_RESULT adl_sys_fanotify_init(unsigned int flags, unsigned int event_f_flags);
ADL_RESULT adl_sys_fanotify_mark(int fd, unsigned int flags,uint64_t mask, int dirfd, const char *path);
ADL_RESULT adl_sys_name_to_handle_at(int dirfd, const char *path,struct file_handle *handle,int *mount_id, int flags);
ADL_RESULT adl_sys_open_by_handle_at(int mount_fd, struct file_handle *handle,int flags);
ADL_RESULT adl_sys_copy_file_range(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags);
ADL_RESULT adl_sys_statx(int dirfd, const char *path, int flags,unsigned int mask, struct statx *statxbuf);
ADL_RESULT adl_sys_close_range(unsigned int first, unsigned int last, int flags);
ADL_RESULT adl_sys_mount_setattr(int dirfd, const char *path,unsigned int flags, struct mount_attr *attr, size_t size);
ADL_RESULT adl_lib_mkfifo(const char *name,mode_t mode);
ADL_RESULT adl_lib_mkfifoat(int dirfd,const char *name,mode_t mode);
ADL_RESULT adl_lib_opendir(const char *str);
ADL_RESULT adl_lib_fdopendir(int fd);
ADL_RESULT adl_lib_readdir(DIR *dirp);
ADL_RESULT adl_lib_rewinddir(DIR *dirp);
ADL_RESULT adl_lib_closedir(DIR *dirp);
ADL_RESULT adl_lib_dirfd(DIR *dirp);




#endif


#endif

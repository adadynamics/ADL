#include "file.h"

#ifdef ADL_OS_UNIX





/*
        FILES,DIRECTORIES AND FILESYSTEM OPERATIONS
*/



/*

ADL_RESULT adl_sys_open(const char *pathname,int flags,mode_t mode)

            a wrapper for the open system call on unix systems

            INPUT  : (const char *pathname,int flags,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_open(const char *pathname,int flags,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_OPEN(pathname,flags,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_creat(const char *pathname,mode_t mode)

            a wrapper for the creat system call on unix systems

            INPUT  : (const char *pathname,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_creat(const char *pathname,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CREAT(pathname,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}


/*

ADL_RESULT adl_sys_openat(int dirfd,const char *pathname,int flags,mode_t mode)

            a wrapper for the openat system call on unix systems

            INPUT  : (int dirfd,const char *pathname,int flags,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_openat(int dirfd,const char *pathname,int flags,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_OPENAT(dirfd,pathname,flags,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_openat2(int dirfd,const char *pathname,struct open_how *how,size_t size)


            a wrapper for the openat2 system call on unix systems

            INPUT  : (int dirfd,const char *pathname,struct open_how *how,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_openat2(int dirfd,const char *pathname,struct open_how *how,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_OPENAT2(dirfd,pathname,how,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);   
}





/*

ADL_RESULT adl_sys_read(int fd,void *buf,size_t buflen)

            a wrapper for the read system call on unix systems

            INPUT  : (int fd,void *buf,size_t buflen)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_read(int fd,void *buf,size_t buflen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_READ(fd,buf,buflen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_write(int fd,const void *buf,size_t buflen)

            a wrapper for the write system call on unix systems

            INPUT  : (int fd,const void *buf,size_t buflen)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_write(int fd,const void *buf,size_t buflen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WRITE(fd,buf,buflen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sendfile(int outfd,int infd,off_t *offset,size_t count)

            a wrapper for the sendfile system call on unix systems

            INPUT  : (int outfd,int infd,off_t *offset,size_t count)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___


ADL_RESULT adl_sys_sendfile(int outfd,int infd,off_t *offset,size_t count)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDFILE(outfd,infd,offset,count);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/**
ADL_RESULT adl_sys_close(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLOSE(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
*/


/*

ADL_RESULT adl_sys_stat(const char *pathname,struct stat *statbuf)

            a wrapper for the stat system call on unix systems

            INPUT  : (const char *pathname,struct stat *statbuf)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_stat(const char *pathname,struct stat *statbuf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_STAT(pathname,statbuf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_fstat(int fd,struct stat *statbuf)

            a wrapper for the fstat system call on unix systems

            INPUT  :(int fd,struct stat *statbuf)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fstat(int fd,struct stat *statbuf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FSTAT(fd,statbuf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_lstat(const char *pathname,struct stat *statbuf)

            a wrapper for the lstat system call on unix systems

            INPUT  :(const char *pathname,struct stat *statbuf)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_lstat(const char *pathname,struct stat *statbuf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LSTAT(pathname,statbuf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_fstatat(int dirfd,const char *pathname,struct stat *statbuf,int flags)

            a wrapper for the fstatat system call on unix systems

            INPUT  :(int dirfd,const char *pathname,struct stat *statbuf,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fstatat(int dirfd,const char *pathname,struct stat *statbuf,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FSTATAT(dirfd,pathname,statbuf,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_poll(struct pollfd *fds,nfds_t nfds,int timeout)

            a wrapper for the poll system call on unix systems

            INPUT  :(struct pollfd *fds,nfds_t nfds,int timeout)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_poll(struct pollfd *fds,nfds_t nfds,int timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_POLL(fds,nfds,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_ppoll(struct pollfd *fds,nfds_t nfds,const struct timespec *timeout,const sigset_t *sigmask)

            a wrapper for the ppoll system call on unix systems

            INPUT  :(struct pollfd *fds,nfds_t nfds,const struct timespec *timeout,const sigset_t *sigmask)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_ppoll(struct pollfd *fds,nfds_t nfds,const struct timespec *timeout,const sigset_t *sigmask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PPOLL(fds,nfds,timeout,sigmask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_lseek(int fd,off_t offset,int whence)

            a wrapper for the lseek system call on unix systems

            INPUT  :(int fd,off_t offset,int whence)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_lseek(int fd,off_t offset,int whence)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LSEEK(fd,offset,whence);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_ioctl(int fd,u64 operation,char *argp)

            a wrapper for the ioctl system call on unix systems

            INPUT  :(int fd,u64 operation,char *argp)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_not_sys___

ADL_RESULT adl_sys_ioctl(int fd,u64 operation,char *argp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IOCTL(fd,operation,argp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_not_sys___





/*

ADL_RESULT adl_sys_pread(int fd,void *buf,size_t buflen,off_t offset)

            a wrapper for the pread system call on unix systems

            INPUT  :(int fd,void *buf,size_t buflen,off_t offset)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pread(int fd,void *buf,size_t buflen,off_t offset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PREAD(fd,buf,buflen,offset);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_pwrite(int fd,const void *buf,size_t buflen,off_t offset)

            a wrapper for the pwrite system call on unix systems

            INPUT  :(int fd,const void *buf,size_t buflen,off_t offset)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pwrite(int fd,const void *buf,size_t buflen,off_t offset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PWRITE(fd,buf,buflen,offset);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_readv(int fd,const struct iovec *iov,int iovcnt)

            a wrapper for the readv system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_readv(int fd,const struct iovec *iov,int iovcnt)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_READV(fd,iov,iovcnt);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_writev(int fd,const struct iovec *iov,int iovcnt)

            a wrapper for the writev system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_writev(int fd,const struct iovec *iov,int iovcnt)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WRITEV(fd,iov,iovcnt);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_preadv(int fd,const struct iovec *iov,int iovcnt,off_t offset)

            a wrapper for the preadv system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt,off_t offset)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_preadv(int fd,const struct iovec *iov,int iovcnt,off_t offset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PREADV(fd,iov,iovcnt,offset);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_pwritev(int fd,const struct iovec *iov,int iovcnt,off_t offset)

            a wrapper for the pwritev system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt,off_t offset)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pwritev(int fd,const struct iovec *iov,int iovcnt,off_t offset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PWRITEV(fd,iov,iovcnt,offset);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_preadv2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)

            a wrapper for the preadv2 system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_preadv2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PREADV2(fd,iov,iovcnt,offset,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_pwritev2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)

            a wrapper for the pwritev2 system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pwritev2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PWRITEV2(fd,iov,iovcnt,offset,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_pipe(int pipefd[])

            a wrapper for the pipe system call on unix systems

            INPUT  :(int pipefd[])

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pipe(int pipefd[])
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIPE(pipefd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*
ADL_RESULT adl_sys_pipe2(int pipefd[],int flags)

            a wrapper for the pipe2 system call on unix systems

            INPUT  :(int pipefd[],int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pipe2(int pipefd[],int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIPE2(pipefd,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
ADL_RESULT adl_sys_select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout)

            a wrapper for the select system call on unix systems

            INPUT  :(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SELECT(nfds,readfds,writefds,exceptfds,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
ADL_RESULT adl_sys_pselect(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,const struct timespec *timeout,const sigset_t *sigmask)

            a wrapper for the pselect system call on unix systems

            INPUT  :(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,const struct timespec *timeout,const sigset_t *sigmask)


            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pselect(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,const struct timespec *timeout,const sigset_t *sigmask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PSELECT(nfds,readfds,writefds,exceptfds,timeout,sigmask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_dup(int fd)

            a wrapper for the dup system call on unix systems

            INPUT  :(int fd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_dup(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_DUP(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_dup2(int oldfd,int newfd)

            a wrapper for the dup2 system call on unix systems

            INPUT  :(int oldfd,int newfd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_dup2(int oldfd,int newfd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_DUP2(oldfd,newfd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
ADL_RESULT adl_sys_dup3(int oldfd,int newfd,int flags)

            a wrapper for the dup3 system call on unix systems

            INPUT  :(int oldfd,int newfd,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_dup3(int oldfd,int newfd,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_DUP3(oldfd,newfd,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
ADL_RESULT adl_sys_flock(int fd,int op)

            a wrapper for the flock system call on unix systems

            INPUT  :(int fd,int op)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_flock(int fd,int op)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FLOCK(fd,op);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
ADL_RESULT adl_sys_fsync(int fd)

            a wrapper for the fsync system call on unix systems

            INPUT  :(int fd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

ADL_RESULT adl_sys_fsync(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FSYNC(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_fdatasync(int fd)

            a wrapper for the fdatasync system call on unix systems

            INPUT  :(int fd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fdatasync(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FDATASYNC(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_truncate(const char *path,off_t length)

            a wrapper for the truncate system call on unix systems

            INPUT  :(const char *path,off_t length)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_truncate(const char *path,off_t length)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_TRUNCATE(path,length);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_ftruncate(int fd,off_t length)

            a wrapper for the ftruncate system call on unix systems

            INPUT  :(int fd,off_t length)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_ftruncate(int fd,off_t length)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FTRUNCATE(fd,length);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_getcwd(char *buf,size_t buf_size)

            a wrapper for the getcwd system call on unix systems

            INPUT  :(char *buf,size_t buf_size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_ret_charptr___

ADL_RESULT adl_sys_getcwd(char *buf,size_t buf_size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETCWD(buf,buf_size);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_chdir(const char *path)

            a wrapper for the chdir system call on unix systems

            INPUT  :(const char *path)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_chdir(const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CHDIR(path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_fchdir(int fd)

            a wrapper for the fchdir system call on unix systems

            INPUT  :(int fd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fchdir(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FCHDIR(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_rename(const char *oldpath,const char *newpath)

            a wrapper for the rename system call on unix systems

            INPUT  :(const char *oldpath,const char *newpath)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_rename(const char *oldpath,const char *newpath)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RENAME(oldpath,newpath);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_renameat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath)

            a wrapper for the renameat system call on unix systems

            INPUT  :(int olddirfd,const char *oldpath,int newdirfd,const char *newpath)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_renameat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RENAMEAT(olddirfd,oldpath,newdirfd,newpath);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_renameat2(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)

            a wrapper for the renameat2 system call on unix systems

            INPUT  :(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_renameat2(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RENAMEAT2(olddirfd,oldpath,newdirfd,newpath,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_mkdir(const char *path,mode_t mode)

            a wrapper for the mkdir system call on unix systems

            INPUT  :(const char *path,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mkdir(const char *path,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MKDIR(path,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_mkdirat(int dirfd,const char *path,mode_t mode)

            a wrapper for the mkdirat system call on unix systems

            INPUT  :(int dirfd,const char *path,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mkdirat(int dirfd,const char *path,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MKDIRAT(dirfd,path,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_rmdir(const char *path)

            a wrapper for the rmdir system call on unix systems

            INPUT  :(const char *path)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_rmdir(const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RMDIR(path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_link(const char *oldpath,const char *newpath)

            a wrapper for the link system call on unix systems

            INPUT  :(const char *oldpath,const char *newpath)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_link(const char *oldpath,const char *newpath)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LINK(oldpath,newpath);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_linkat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)

            a wrapper for the linkat system call on unix systems

            INPUT  :(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_linkat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LINKAT(olddirfd,oldpath,newdirfd,newpath,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_unlink(const char *path)

            a wrapper for the unlink system call on unix systems

            INPUT  :(const char *path)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_unlink(const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UNLINK(path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_unlinkat(int dirfd,const char *path,int flags)

            a wrapper for the unlinkat system call on unix systems

            INPUT  :(int dirfd,const char *path,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_unlinkat(int dirfd,const char *path,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UNLINKAT(dirfd,path,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_symlink(const char *target,const char *linkpath)

            a wrapper for the symlink system call on unix systems

            INPUT  :(const char *target,const char *linkpath)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_symlink(const char *target,const char *linkpath)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYMLINK(target,linkpath);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_symlinkat(const char *target,int newdirfd,const char *linkpath)

            a wrapper for the symlinkat system call on unix systems

            INPUT  :(const char *target,int newdirfd,const char *linkpath)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_symlinkat(const char *target,int newdirfd,const char *linkpath)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYMLINKAT(target,newdirfd,linkpath);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_readlink(const char *path,char *buf,size_t buf_size)

            a wrapper for the readlink system call on unix systems

            INPUT  :(const char *path,char *buf,size_t buf_size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_readlink(const char *path,char *buf,size_t buf_size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_READLINK(path,buf,buf_size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_readlinkat(int dirfd,const char *path,char *buf,size_t buf_size)

            a wrapper for the readlinkat system call on unix systems

            INPUT  :(int dirfd,const char *path,char *buf,size_t buf_size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_readlinkat(int dirfd,const char *path,char *buf,size_t buf_size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_READLINKAT(dirfd,path,buf,buf_size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_chmod(const char *path,mode_t mode)

            a wrapper for the chmod system call on unix systems

            INPUT  :(const char *path,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_chmod(const char *path,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CHMOD(path,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_fchmod(int fd,mode_t mode)

            a wrapper for the fchmod system call on unix systems

            INPUT  :(int fd,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fchmod(int fd,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FCHMOD(fd,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_fchmodat(int dirfd,const char *path,mode_t mode,int flags)

            a wrapper for the fchomodat system call on unix systems

            INPUT  :(int dirfd,const char *path,mode_t mode,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fchmodat(int dirfd,const char *path,mode_t mode,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FCHMODAT(dirfd,path,mode,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_chown(const char *path,uid_t owner,gid_t group)

            a wrapper for the chown system call on unix systems

            INPUT  :(const char *path,uid_t owner,gid_t group)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_chown(const char *path,uid_t owner,gid_t group)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CHOWN(path,owner,group);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_lchown(const char *path,uid_t owner,gid_t group)

            a wrapper for the lchown system call on unix systems

            INPUT  :(const char *path,uid_t owner,gid_t group)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_lchown(const char *path,uid_t owner,gid_t group)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LCHOWN(path,owner,group);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_fchown(int fd,uid_t owner,gid_t group)

            a wrapper for the fchown system call on unix systems

            INPUT  :(int fd,uid_t owner,gid_t group)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fchown(int fd,uid_t owner,gid_t group)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FCHOWN(fd,owner,group);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_sys_fchownat(int dirfd,const char *path,uid_t owner,gid_t group,int flags)

            a wrapper for the fchownat system call on unix systems

            INPUT  :(int dirfd,const char *path,uid_t owner,gid_t group,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fchownat(int dirfd,const char *path,uid_t owner,gid_t group,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FCHOWNAT(dirfd,path,owner,group,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_umask(mode_t mask)

            a wrapper for the umask system call on unix systems

            INPUT  :(mode_t mask)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_umask(mode_t mask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UMASK(mask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_mknod(const char *path,mode_t mode,dev_t dev)

            a wrapper for the mknod system call on unix systems

            INPUT  :(const char *path,mode_t mode,dev_t dev)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mknod(const char *path,mode_t mode,dev_t dev)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret                                              = ADL_sys_MKNOD(path,mode,dev);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_mknodat(int dirfd,const char *path,mode_t mode,dev_t dev)

            a wrapper for the mknodat system call on unix systems

            INPUT  :(int dirfd,const char *path,mode_t mode,dev_t dev)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mknodat(int dirfd,const char *path,mode_t mode,dev_t dev)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret                                              = ADL_sys_MKNODAT(dirfd,path,mode,dev);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_sys_statfs(const char *path,struct statfs *buf)

            a wrapper for the statfs system call on unix systems

            INPUT  :(const char *path,struct statfs *buf)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_statfs(const char *path,struct statfs *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_STATFS(path,buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_fstatfs(int fd,struct statfs *buf)

            a wrapper for the fstatfs system call on unix systems

            INPUT  :(int fd,struct statfs *buf)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fstatfs(int fd,struct statfs *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FSTATFS(fd,buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_vhangup(void)

            a wrapper for the vhangup system call on unix systems

            INPUT  :(void)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_vhangup(void)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_VHANGUP();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_pivot_root(const char *newroot,const char *putold)

            a wrapper for the pivot_root system call on unix systems

            INPUT  :(const char *newroot,const char *putold)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pivot_root(const char *newroot,const char *putold)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIVOT_ROOT(newroot,putold);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___






/*

ADL_RESULT adl_sys_chroot(const char *path)

            a wrapper for the chroot system call on unix systems

            INPUT  :(const char *path)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_chroot(const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CHROOT(path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_sync(void)

            a wrapper for the sync system call on unix systems

            INPUT  :(void)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sync(void)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_SYNC();
    rdr_ret = 0;
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_syncfs(int fd)

            a wrapper for the syncfs system call on unix systems

            INPUT  :(int fd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_syncfs(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYNCFS(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_mount(const char *source,const char *target,const char *fstype,unsigned long mountflags,const void *data)

            a wrapper for the mount system call on unix systems

            INPUT  :(const char *source,const char *target,const char *fstype,unsigned long mountflags,const void *data)


            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mount(const char *source,const char *target,const char *fstype,unsigned long mountflags,const void *data)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MOUNT(source,target,fstype,mountflags,data);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_umount(const char *target)

            a wrapper for the umount system call on unix systems

            INPUT  :(const char *target)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_umount(const char *target)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UMOUNT(target);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_umount2(const char *target,int flags)

            a wrapper for the umount2 system call on unix systems

            INPUT  :(const char *target,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_umount2(const char *target,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UMOUNT2(target,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_ioperm(unsigned long from,unsigned long num,int turnon)

            a wrapper for the ioperm system call on unix systems

            INPUT  :(unsigned long from,unsigned long num,int turnon)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_ioperm(unsigned long from,unsigned long num,int turnon)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IOPERM(from,num,turnon);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_readahead(int fd,off_t offset,size_t count)

            a wrapper for the readahead system call on unix systems

            INPUT  :(int fd,off_t offset,size_t count)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_readahead(int fd,off_t offset,size_t count)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_READAHEAD(fd,offset,count);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_setxattr(const char *path,const char *name,const void *value,size_t size,int flags)

            a wrapper for the setxattr system call on unix systems

            INPUT  :(const char *path,const char *name,const void *value,size_t size,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setxattr(const char *path,const char *name,const void *value,size_t size,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETXATTR(path,name,value,size,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_lsetxattr(const char *path,const char *name,const void *value,size_t size,int flags)             

            a wrapper for the lsetxattr system call on unix systems

            INPUT  :(const char *path,const char *name,const void *value,size_t size,int flags) 

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_lsetxattr(const char *path,const char *name,const void *value,size_t size,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LSETXATTR(path,name,value,size,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_fsetxattr(int fd,const char *name,const void *value,size_t size,int flags)

            a wrapper for the fsetxattr system call on unix systems

            INPUT  :(int fd,const char *name,const void *value,size_t size,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fsetxattr(int fd,const char *name,const void *value,size_t size,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FSETXATTR(fd,name,value,size,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_getxattr(const char *path,const char *name,void *value,size_t size)

            a wrapper for the getxattr system call on unix systems

            INPUT  :(const char *path,const char *name,void *value,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getxattr(const char *path,const char *name,void *value,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETXATTR(path,name,value,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_lgetxattr(const char *path,const char *name,void *value,size_t size)

            a wrapper for the lgetxattr system call on unix systems

            INPUT  :(const char *path,const char *name,void *value,size_t size)


            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_lgetxattr(const char *path,const char *name,void *value,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LGETXATTR(path,name,value,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_fgetxattr(int fd,const char *name,void *value,size_t size)

            a wrapper for the fgetxattr system call on unix systems

            INPUT  :(int fd,const char *name,void *value,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fgetxattr(int fd,const char *name,void *value,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FGETXATTR(fd,name,value,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_listxattr(const char *path,char *list,size_t size)

            a wrapper for the listxattr system call on unix systems

            INPUT  :(const char *path,char *list,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_listxattr(const char *path,char *list,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LISTXATTR(path,list,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_llistxattr(const char *path,char *list,size_t size)

            a wrapper for the llistxattr system call on unix systems

            INPUT  :(const char *path,char *list,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_llistxattr(const char *path,char *list,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LLISTXATTR(path,list,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_flistxattr(int fd,char *list,size_t size)

            a wrapper for the flistxattr system call on unix systems

            INPUT  :(int fd,char *list,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_flistxattr(int fd,char *list,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FLISTXATTR(fd,list,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_removexattr(const char *path,const char *name)

            a wrapper for the removexattr system call on unix systems

            INPUT  :(const char *path,const char *name)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_removexattr(const char *path,const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_REMOVEXATTR(path,name);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_lremovexattr(const char *path,const char *name)

            a wrapper for the lremovexattr system call on unix systems

            INPUT  :(const char *path,const char *name)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_lremovexattr(const char *path,const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LREMOVEXATTR(path,name);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_fremovexattr(int fd,const char *name)

            a wrapper for the fremovexattr system call on unix systems

            INPUT  :(int fd,const char *name)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fremovexattr(int fd,const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FREMOVEXATTR(fd,name);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_ioprio_set(int which,int who,int ioprio)

            a wrapper for the ioprio_set system call on unix systems

            INPUT  :(int which,int who,int ioprio)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_ioprio_set(int which,int who,int ioprio)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IOPRIO_SET(which,who,ioprio);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_ioprio_get(int which,int who)

            a wrapper for the ioprio_get system call on unix systems

            INPUT  :(int which,int who)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_ioprio_get(int which,int who)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IOPRIO_GET(which,who);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_inotify_init()

            a wrapper for the inotify_init system call on unix systems

            INPUT  :()

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_inotify_init()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INOTIFY_INIT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_inotify_init1(int flags)

            a wrapper for the inotify_init1 system call on unix systems

            INPUT  :(int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_inotify_init1(int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INOTIFY_INIT1(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_inotify_add_watch(int fd,const char *path,uint32_t mask)

            a wrapper for the inotify_add_watch system call on unix systems

            INPUT  :(int fd,const char *path,uint32_t mask)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_inotify_add_watch(int fd,const char *path,uint32_t mask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INOTIFY_ADD_WATCH(fd,path,mask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_inotify_rm_watch(int fd,int wd)

            a wrapper for the inotify_rm_watch system call on unix systems

            INPUT  :(int fd,int wd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_inotify_rm_watch(int fd,int wd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INOTIFY_RM_WATCH(fd,wd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

ADL_RESULT adl_sys_access(const char *path,int mode)

            a wrapper for the access system call on unix systems

            INPUT  :(const char *path,int mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_access(const char *path,int mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_ACCESS(path,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_faccessat(int dirfd,const char *path,int mode,int flags)

            a wrapper for the faccessat system call on unix systems

            INPUT  :(int dirfd,const char *path,int mode,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_faccessat(int dirfd,const char *path,int mode,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FACCESSAT(dirfd,path,mode,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
___adl_linux_std___
___adl_syscall___




/*

ADL_RESULT adl_sys_faccessat2(int dirfd,const char *path,int mode,int flags)

            a wrapper for the faccessat2 system call on unix systems

            INPUT  :(int dirfd,const char *path,int mode,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_faccessat2(int dirfd,const char *path,int mode,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FACCESSAT2(dirfd,path,mode,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_quotactl(int op,const char *special,int id, caddr_t addr)

            a wrapper for the quotactl system call on unix systems

            INPUT  :(int op,const char *special,int id, caddr_t addr)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_quotactl(int op,const char *special,int id, caddr_t addr)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_QUOTACTL(op,special,id,addr);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_io_setup(unsigned int nr_events,aio_context_t *ctx_id)

            a wrapper for the io_setup system call on unix systems

            INPUT  :(unsigned int nr_events,aio_context_t *ctx_id)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_io_setup(unsigned int nr_events,aio_context_t *ctx_id)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IO_SETUP(nr_events,ctx_id);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_io_destroy(aio_context_t ctx_id)

            a wrapper for the io_destroy system call on unix systems

            INPUT  :(aio_context_t ctx_id)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_io_destroy(aio_context_t ctx_id)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IO_DESTROY(ctx_id);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_io_getevents(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout)

            a wrapper for the io_getevents system call on unix systems

            INPUT  :(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout)


            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_io_getevents(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IO_GETEVENTS(ctx_id,min_nr,nr,events,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_io_submit(aio_context_t ctx_id, long nr, struct iocb **iocb)

            a wrapper for the io_submit system call on unix systems

            INPUT  :(aio_context_t ctx_id, long nr, struct iocb **iocb)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_io_submit(aio_context_t ctx_id, long nr, struct iocb **iocb)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IO_SUBMIT(ctx_id,nr,iocb);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_io_cancel(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result)

            a wrapper for the io_cancel system call on unix systems

            INPUT  :(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_io_cancel(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IO_CANCEL(ctx_id,iocb,result);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_lookup_dcookie(uint64_t cookie, char *buffer,size_t len)

            a wrapper for the lookup_dcookie system call on unix systems

            INPUT  :(uint64_t cookie, char *buffer,size_t len)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_lookup_dcookie(uint64_t cookie, char *buffer,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LOOKUP_DCOOKIE(cookie,buffer,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_epoll_create(int size)

            a wrapper for the epoll system call on unix systems

            INPUT  :(int size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_epoll_create(int size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_CREATE(size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_epoll_create1(int flags)

            a wrapper for the epoll_create1 system call on unix systems

            INPUT  :(int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_epoll_create1(int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_CREATE1(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout)

            a wrapper for the epoll_wait system call on unix systems

            INPUT  :(int epfd, struct epoll_event *events,int maxevents, int timeout)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_WAIT(epfd,events,maxevents,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_epoll_pwait(int epfd, struct epoll_event *events,int maxevents, int timeout,const sigset_t *sigmask)

            a wrapper for epoll_pwait system call on unix systems

            INPUT  :(int epfd, struct epoll_event *events,int maxevents, int timeout,const sigset_t *sigmask)


            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_epoll_pwait(int epfd, struct epoll_event *events,int maxevents, int timeout,const sigset_t *sigmask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_PWAIT(epfd,events,maxevents,timeout,sigmask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_epoll_pwait2(int epfd, struct epoll_event *events,int maxevents,const struct timespec * timeout,const sigset_t *sigmask)

            a wrapper for epoll_pwait2 system call on unix systems

            INPUT  :(int epfd, struct epoll_event *events,int maxevents,const struct timespec * timeout,const sigset_t *sigmask)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_epoll_pwait2(int epfd, struct epoll_event *events,int maxevents,const struct timespec * timeout,const sigset_t *sigmask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_PWAIT2(epfd,events,maxevents,timeout,sigmask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_epoll_ctl(int epfd, int op, int fd,struct epoll_event *event)

            a wrapper for epoll_ctl system call on unix systems

            INPUT  :(int epfd, int op, int fd,struct epoll_event *event)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_epoll_ctl(int epfd, int op, int fd,struct epoll_event *event)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_CTL(epfd,op,fd,event);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_splice(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)

            a wrapper for splice system call on unix systems

            INPUT  :(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_splice(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SPLICE(fd_in,off_in,fd_out,off_out,len,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_tee(int fd_in, int fd_out, size_t len, unsigned int flags)

            a wrapper for tee system call on unix systems

            INPUT  :(int fd_in, int fd_out, size_t len, unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_tee(int fd_in, int fd_out, size_t len, unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_TEE(fd_in,fd_out,len,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
___adl_end_linux___






/*

ADL_RESULT adl_sys_posix_fadvise64(int fd,off_t offset,off_t len,int advice)

            a wrapper for posix_fadvise64 system call on unix systems

            INPUT  :(int fd,off_t offset,off_t len,int advice)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_posix_fadvise64(int fd,off_t offset,off_t len,int advice)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_POSIX_FADVICE64(fd,offset,len,advice);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_utime(const char *path,const struct utimbuf *times)

            a wrapper for utime system call on unix systems

            INPUT  :(const char *path,const struct utimbuf *times)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_utime(const char *path,const struct utimbuf *times)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UTIME(path,times);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_utimes(const char *path,const struct timeval *times)

            a wrapper for utimes system call on unix systems

            INPUT  :(const char *path,const struct timeval *times)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_utimes(const char *path,const struct timeval *times)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UTIMES(path,times);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_utimensat(int dirfd, const char *path,const struct timespec *times, int flags)

            a wrapper for utimensat system call on unix systems

            INPUT  :(int dirfd, const char *path,const struct timespec *times, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_utimensat(int dirfd, const char *path,const struct timespec *times, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UTIMENSAT(dirfd,path,times,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_futimens(int fd,const struct timespec *times)

            a wrapper for futimens system call on unix systems

            INPUT  :(int fd,const struct timespec *times)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_futimens(int fd,const struct timespec *times)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FUTIMENS(fd,times);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sync_file_range(int fd, off_t offset, off_t count,unsigned int flags)

            a wrapper for file_range system call on unix systems

            INPUT  :(int fd, off_t offset, off_t count,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sync_file_range(int fd, off_t offset, off_t count,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYNC_FILE_RANGE(fd,offset,count,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_fallocate(int fd, int mode, off_t offset, off_t len)

            a wrapper for fallocate system call on unix systems

            INPUT  :(int fd, int mode, off_t offset, off_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fallocate(int fd, int mode, off_t offset, off_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FALLOCATE(fd,mode,offset,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_fanotify_init(unsigned int flags, unsigned int event_f_flags)

            a wrapper for fanotify_init system call on unix systems

            INPUT  :(unsigned int flags, unsigned int event_f_flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fanotify_init(unsigned int flags, unsigned int event_f_flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FANOTIFY_INIT(flags,event_f_flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_fanotify_mark(int fd, unsigned int flags,uint64_t mask, int dirfd, const char *path)

            a wrapper for fanotify_mark system call on unix systems

            INPUT  :(int fd, unsigned int flags,uint64_t mask, int dirfd, const char *path)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_fanotify_mark(int fd, unsigned int flags,uint64_t mask, int dirfd, const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FANOTIFY_MARK(fd,flags,mask,dirfd,path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_name_to_handle_at(int dirfd, const char *path,struct file_handle *handle,int *mount_id, int flags)

            a wrapper for name_to_handle_at system call on unix systems

            INPUT  :(int dirfd, const char *path,struct file_handle *handle,int *mount_id, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_name_to_handle_at(int dirfd, const char *path,struct file_handle *handle,int *mount_id, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_NAME_TO_HANDLE_AT(dirfd,path,handle,mount_id,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_open_by_handle_at(int mount_fd, struct file_handle *handle,int flags)

            a wrapper for open_by_handle_at system call on unix systems

            INPUT  :(int mount_fd, struct file_handle *handle,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_open_by_handle_at(int mount_fd, struct file_handle *handle,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_OPEN_BY_HANDLE_AT(mount_fd,handle,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_copy_file_range(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)

            a wrapper for copy_file_range system call on unix systems

            INPUT  :(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_copy_file_range(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_COPY_FILE_RANGE(fd_in,off_in,fd_out,off_out,len,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_statx(int dirfd, const char *path, int flags,unsigned int mask, struct statx *statxbuf)

            a wrapper for statx system call on unix systems

            INPUT  :(int dirfd, const char *path, int flags,unsigned int mask, struct statx *statxbuf)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_statx(int dirfd, const char *path, int flags,unsigned int mask, struct statx *statxbuf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_STATX(dirfd,path,flags,mask,statxbuf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_close_range(unsigned int first, unsigned int last, int flags)

            a wrapper for close_range system call on unix systems

            INPUT  :(unsigned int first, unsigned int last, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_close_range(unsigned int first, unsigned int last, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLOSE_RANGE(first,last,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_mount_setattr(int dirfd, const char *path,unsigned int flags, struct mount_attr *attr, size_t size)

            a wrapper for mount_setattr system call on unix systems

            INPUT  :(int dirfd, const char *path,unsigned int flags, struct mount_attr *attr, size_t size)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_syscall___

ADL_RESULT adl_sys_mount_setattr(int dirfd, const char *path,unsigned int flags, struct mount_attr *attr, size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MOUNT_SETATTR(dirfd,path,flags,attr,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_mkfifo(const char *name,mode_t mode)

            a wrapper for mkfifo library call on unix systems

            INPUT  :(const char *name,mode_t mode)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_mkfifo(const char *name,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MKFIFO(name,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_mkfifoat(int dirfd,const char *name,mode_t mode)

            a wrapper for mkfifoat library call on unix systems

            INPUT  :(int dirfd,const char *name,mode_t mode)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_mkfifoat(int dirfd,const char *name,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MKFIFOAT(dirfd,name,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_opendir(const char *str)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_OPENDIR(str);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

ADL_RESULT adl_lib_fdopendir(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_FDOPENDIR(fd);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

ADL_RESULT adl_lib_readdir(DIR *dirp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_READDIR(dirp);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

ADL_RESULT adl_lib_rewinddir(DIR *dirp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_REWINDDIR(dirp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

ADL_RESULT adl_lib_closedir(DIR *dirp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLOSEDIR(dirp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}


ADL_RESULT adl_lib_dirfd(DIR *dirp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_DIRFD(dirp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




#endif

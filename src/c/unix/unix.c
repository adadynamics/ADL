
#include "unix.h"

#ifdef ADL_OS_UNIX



/*
        NETWORK SOCKETS
*/




/*

static ADL_RESULT adl_sys_socket(int domain,int type,int protocol);
    
            a wrapper for the socket system call on unix systems
            
            INPUT  : domain(eg. AF_INET,AF_INET6),type(eg. SOCK_STREAM,SOCK_RAW),protocol(eg. IPPROTO_TCP)
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains a valid socket descriptor which is a positive integral value

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/




static ADL_RESULT adl_sys_socket(int domain,int type,int protocol)
{

    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SOCKET(domain,type,protocol);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}









/*

static ADL_RESULT adl_sys_socketpair(int domain,int type,int protocol,int sockfds[2]);
    
            a wrapper for the socketpair system call on unix systems
            
            INPUT  : domain(eg. AF_INET,AF_INET6),type(eg. SOCK_STREAM,SOCK_RAW),protocol(eg. IPPROTO_TCP),array of two integers
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains two valid socket descriptors in the sockfds array which are positive integral value

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_socketpair(int domain,int type,int protocol,int sockfds[2])
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SOCKETPAIR(domain,type,protocol,sockfds);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen);

            a wrapper for the bind system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to sockaddr structure,length of the sockaddr structure
                     the pointer must point to an allocated memory
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen)
{
    
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_BIND(sockfd,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_connect(int sockfd,const struct sockaddr *addr,socklen_t addrlen);

            a wrapper for the connect system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to sockaddr structure,length of the sockaddr structure
                     the pointer must point to an allocated memory
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_connect(int sockfd,const struct sockaddr *addr,socklen_t addrlen)
{
    
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CONNECT(sockfd,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_listen(int sockfd,int backlog);

            a wrapper for the listen system call on unix systems

            INPUT  : a valid socket descriptor,a positive integral value for the backlog
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_listen(int sockfd,int backlog)
{
    
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LISTEN(sockfd,backlog);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_accept(int sockfd,struct sockaddr *addr,socklen_t *addrlen);

            a wrapper for the accept system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to sockaddr structure,pointer to a socklen_t variable
                     which contains the length of the sockaddr structure
                     
                     both pointers must point to an allocated memory
                    
                     both pointers are value-result arguments
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure contains a valid socket descriptor which is a positive integral value

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_accept(int sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_ACCEPT(sockfd,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_accept4(int sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags);

            a wrapper for the accept system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to sockaddr structure,pointer to a socklen_t variable
                     which contains the length of the sockaddr structure,flags
                     
                     both pointers must point to an allocated memory
                    
                     both pointers are value-result arguments

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure contains a valid socket descriptor which is a positive integral value

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_accept4(int sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_ACCEPT4(sockfd,addr,addrlen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_recv(int sockfd,void *buf,size_t buflen,int flags);

            a wrapper for the recv system call on unix systems

            INPUT  : a valid socket descriptor,an allocated buffer,size of the buffer,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_recv(int sockfd,void *buf,size_t buflen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECV(sockfd,buf,buflen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_recvfrom(int sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen);

            a wrapper for the recvfrom system call on unix systems

            INPUT  : a valid socket descriptor,an allocated buffer,size of the buffer,flags,sockaddr pointer,
                     socklen_t pointer

                     all pointers point to an allocated memory region

                     addr and addrlen are value-result arguments
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received...addr contains the address details of the connection and addrlen contains the size of addr

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_recvfrom(int sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen)
{

    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECVFROM(sockfd,buf,buflen,flags,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_recvmsg(int sockfd,struct msghdr *msg,int flags);

            a wrapper for the recvmsg system call on unix systems

            INPUT  : a valid socket descriptor,pointer to an allocated struct msghdr memory region,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_recvmsg(int sockfd,struct msghdr *msg,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECVMSG(sockfd,msg,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_recvmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout);

            a wrapper for the recvmmsg system call on unix systems

            INPUT  : a valid socket descriptor,pointer to an allocated struct msghdr memory region,vlen,flags,timeout
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_recvmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECVMMSG(sockfd,msgvec,vlen,flags,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_send(int sockfd,const void *buf,size_t buflen,int flags);

            a wrapper for the send system call on unix systems

            INPUT  : a valid socket descriptor,an allocated buffer,size of the buffer,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes sent,zero is not an error,it just implies that zero bytes were sent

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_send(int sockfd,const void *buf,size_t buflen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEND(sockfd,buf,buflen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sendto(int sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen);

            a wrapper for the sendto system call on unix systems

            INPUT  : a valid socket descriptor,an allocated buffer,size of the buffer,flags,sockaddr pointer,
                     socklen_t pointer...addr contains the address details of the connection and addrlen contains the size of addr

                     all pointers point to an allocated memory region
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sendto(int sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDTO(sockfd,buf,buflen,flags,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sendmsg(int sockfd,const struct msghdr *msg,int flags);

            a wrapper for the sendmsg system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to an allocated struct msghdr memory region,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes sent,zero is not an error,it just implies that zero bytes were sent

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sendmsg(int sockfd,const struct msghdr *msg,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDMSG(sockfd,msg,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sendmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags);

            a wrapper for the sendmmsg system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to an allocated struct mmsghdr memory region,vlen,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes sent,zero is not an error,it just implies that zero bytes were sent

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sendmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDMMSG(sockfd,msgvec,vlen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_shutdown(int sockfd,int how);

            a wrapper for the shutdown system call on unix systems

            INPUT  : a valid socket descriptor,how(describes how/what to shutdown)
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_shutdown(int sockfd,int how)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SHUTDOWN(sockfd,how);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_close(int sockfd);

            a wrapper for the close system call on unix systems 

            INPUT  : a valid file/socket descriptor
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_close(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLOSE(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_getsockopt(int sockfd,int level,int optname,void *optval,socklen_t *optlen);

            a wrapper for the getsockopt system call on unix systems

            INPUT  : a valid socket descriptor,level,option name,buffer to store option value,pointer to 
                     to variable to store the size of optval returned

                     all pointers point to an allocated memory region

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero,optval is set to the value of the option,optlen contains size of optval

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getsockopt(int sockfd,int level,int optname,void *optval,socklen_t *optlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETSOCKOPT(sockfd,level,optname,optval,optlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setsockopt(int sockfd,int level,int optname,void *optval,socklen_t optlen);

            a wrapper for the setsockopt system call on unix systems

            INPUT  : a valid socket descriptor,level,option name,buffer containing the option value,size of
                     optval

                     all pointers point to an allocated memory region

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setsockopt(int sockfd,int level,int optname,void *optval,socklen_t optlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETSOCKOPT(sockfd,level,optname,optval,optlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_getsockname(int sockfd,struct sockaddr *addr,socklen_t *addrlen);

            a wrapper for the getsockname system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to sockaddr structure,pointer to a socklen_t variable
                     which contains the length of the sockaddr structure
                     
                     both pointers must point to an allocated memory
                    
                     both pointers are value-result arguments
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getsockname(int sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETSOCKNAME(sockfd,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_getpeername(int sockfd,struct sockaddr *addr,socklen_t *addrlen);

            a wrapper for the getpeername system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to sockaddr structure,pointer to a socklen_t variable
                     which contains the length of the sockaddr structure
                     
                     both pointers must point to an allocated memory
                    
                     both pointers are value-result arguments
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getpeername(int sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPEERNAME(sockfd,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_lib_getaddrinfo(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);

            a wrapper for the getaddrinfo library call

            INPUT  : host/ip,port/service,hints,res
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero,and res has memory allocated to it that should be freed using adl_freeaddrinfo_l eventually

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_getaddrinfo(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETADDRINFO(host,service,hints,res);

    if(ADL_CHECK_NOT_EQUAL(rdr_ret,0))
    {
        rdr_ret = -1;
    }
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_lib_freeaddrinfo(struct addrinfo *res);

            a wrapper for the freeaddrinfo library call

            INPUT  : res
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero,and res' memory is deallocated

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  DYNAMIC MEMORY IS NOT USED
*/


static ADL_RESULT adl_lib_freeaddrinfo(struct addrinfo *res)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    if(ADL_CHECK_NULL(res))
    {
        rdr_ret = -1;
    }

    ADL_FREEADDRINFO(res);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_lib_getnameinfo(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,int flags);

            a wrapper for getnameinfo library call

            INPUT  : addr,addrlen,host,hostlen,service,servicelen,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero,host and service are filled

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  DYNAMIC MEMORY IS NOT USED
*/


static ADL_RESULT adl_lib_getnameinfo(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETNAMEINFO(addr,addrlen,host,hostlen,service,servicelen,flags);

    if(ADL_CHECK_NOT_EQUAL(rdr_ret,0))
    {
        rdr_ret = -1;
    }
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_lib_htons(u16 hostshort);

            a wrapper htons library call

            INPUT  : a 16 bit integer in host byte-order
            OUTPUT : returns the 16 bit integer in network byte order

            ****
                always succeeds
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_htons(u16 hostshort)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_HTONS(hostshort);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_htonl(u32 hostlong);

            a wrapper htonl library call

            INPUT  : a 32 bit integer in host byte-order
            OUTPUT : returns the 32 bit integer in network byte order

            ****
                always succeeds
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_htonl(u32 hostlong)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_HTONL(hostlong);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_ntohs(u16 netshort);

            a wrapper ntohs library call

            INPUT  : a 16 bit integer in network byte-order
            OUTPUT : returns the 16 bit integer in host byte order

            ****
                always succeeds
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_ntohs(u16 netshort)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_NTOHS(netshort);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_ntohl(u32 netlong);

            a wrapper ntohl library call

            INPUT  : a 32 bit integer in network byte-order
            OUTPUT : returns the 32 bit integer in host byte order

            ****
                always succeeds
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_ntohl(u32 netlong)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_NTOHL(netlong);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
        FILES,DIRECTORIES AND FILESYSTEM OPERATIONS
*/



/*

static ADL_RESULT adl_sys_open(const char *pathname,int flags,mode_t mode)

            a wrapper for the open system call on unix systems

            INPUT  : (const char *pathname,int flags,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_open(const char *pathname,int flags,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_OPEN(pathname,flags,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_creat(const char *pathname,mode_t mode)

            a wrapper for the creat system call on unix systems

            INPUT  : (const char *pathname,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_creat(const char *pathname,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CREAT(pathname,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}


/*

static ADL_RESULT adl_sys_openat(int dirfd,const char *pathname,int flags,mode_t mode)

            a wrapper for the openat system call on unix systems

            INPUT  : (int dirfd,const char *pathname,int flags,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_openat(int dirfd,const char *pathname,int flags,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_OPENAT(dirfd,pathname,flags,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_openat2(int dirfd,const char *pathname,struct open_how *how,size_t size)


            a wrapper for the openat2 system call on unix systems

            INPUT  : (int dirfd,const char *pathname,struct open_how *how,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_openat2(int dirfd,const char *pathname,struct open_how *how,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_OPENAT2(dirfd,pathname,how,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);   
}





/*

static ADL_RESULT adl_sys_read(int fd,void *buf,size_t buflen)

            a wrapper for the read system call on unix systems

            INPUT  : (int fd,void *buf,size_t buflen)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_read(int fd,void *buf,size_t buflen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_READ(fd,buf,buflen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_write(int fd,const void *buf,size_t buflen)

            a wrapper for the write system call on unix systems

            INPUT  : (int fd,const void *buf,size_t buflen)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_write(int fd,const void *buf,size_t buflen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WRITE(fd,buf,buflen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sendfile(int outfd,int infd,off_t *offset,size_t count)

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


static ADL_RESULT adl_sys_sendfile(int outfd,int infd,off_t *offset,size_t count)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDFILE(outfd,infd,offset,count);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/**
static ADL_RESULT adl_sys_close(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLOSE(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
*/


/*

static ADL_RESULT adl_sys_stat(const char *pathname,struct stat *statbuf)

            a wrapper for the stat system call on unix systems

            INPUT  : (const char *pathname,struct stat *statbuf)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_stat(const char *pathname,struct stat *statbuf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_STAT(pathname,statbuf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_fstat(int fd,struct stat *statbuf)

            a wrapper for the fstat system call on unix systems

            INPUT  :(int fd,struct stat *statbuf)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fstat(int fd,struct stat *statbuf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FSTAT(fd,statbuf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_lstat(const char *pathname,struct stat *statbuf)

            a wrapper for the lstat system call on unix systems

            INPUT  :(const char *pathname,struct stat *statbuf)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_lstat(const char *pathname,struct stat *statbuf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LSTAT(pathname,statbuf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_fstatat(int dirfd,const char *pathname,struct stat *statbuf,int flags)

            a wrapper for the fstatat system call on unix systems

            INPUT  :(int dirfd,const char *pathname,struct stat *statbuf,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fstatat(int dirfd,const char *pathname,struct stat *statbuf,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FSTATAT(dirfd,pathname,statbuf,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_poll(struct pollfd *fds,nfds_t nfds,int timeout)

            a wrapper for the poll system call on unix systems

            INPUT  :(struct pollfd *fds,nfds_t nfds,int timeout)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_poll(struct pollfd *fds,nfds_t nfds,int timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_POLL(fds,nfds,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_ppoll(struct pollfd *fds,nfds_t nfds,const struct timespec *timeout,const sigset_t *sigmask)

            a wrapper for the ppoll system call on unix systems

            INPUT  :(struct pollfd *fds,nfds_t nfds,const struct timespec *timeout,const sigset_t *sigmask)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_ppoll(struct pollfd *fds,nfds_t nfds,const struct timespec *timeout,const sigset_t *sigmask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PPOLL(fds,nfds,timeout,sigmask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_lseek(int fd,off_t offset,int whence)

            a wrapper for the lseek system call on unix systems

            INPUT  :(int fd,off_t offset,int whence)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_lseek(int fd,off_t offset,int whence)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LSEEK(fd,offset,whence);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_ioctl(int fd,u64 operation,char *argp)

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

static ADL_RESULT adl_sys_ioctl(int fd,u64 operation,char *argp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IOCTL(fd,operation,argp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_not_sys___





/*

static ADL_RESULT adl_sys_pread(int fd,void *buf,size_t buflen,off_t offset)

            a wrapper for the pread system call on unix systems

            INPUT  :(int fd,void *buf,size_t buflen,off_t offset)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pread(int fd,void *buf,size_t buflen,off_t offset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PREAD(fd,buf,buflen,offset);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_pwrite(int fd,const void *buf,size_t buflen,off_t offset)

            a wrapper for the pwrite system call on unix systems

            INPUT  :(int fd,const void *buf,size_t buflen,off_t offset)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pwrite(int fd,const void *buf,size_t buflen,off_t offset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PWRITE(fd,buf,buflen,offset);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_readv(int fd,const struct iovec *iov,int iovcnt)

            a wrapper for the readv system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_readv(int fd,const struct iovec *iov,int iovcnt)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_READV(fd,iov,iovcnt);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_writev(int fd,const struct iovec *iov,int iovcnt)

            a wrapper for the writev system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_writev(int fd,const struct iovec *iov,int iovcnt)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WRITEV(fd,iov,iovcnt);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_preadv(int fd,const struct iovec *iov,int iovcnt,off_t offset)

            a wrapper for the preadv system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt,off_t offset)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_preadv(int fd,const struct iovec *iov,int iovcnt,off_t offset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PREADV(fd,iov,iovcnt,offset);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_pwritev(int fd,const struct iovec *iov,int iovcnt,off_t offset)

            a wrapper for the pwritev system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt,off_t offset)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pwritev(int fd,const struct iovec *iov,int iovcnt,off_t offset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PWRITEV(fd,iov,iovcnt,offset);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_preadv2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)

            a wrapper for the preadv2 system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_preadv2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PREADV2(fd,iov,iovcnt,offset,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_pwritev2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)

            a wrapper for the pwritev2 system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pwritev2(int fd,const struct iovec *iov,int iovcnt,off_t offset,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PWRITEV2(fd,iov,iovcnt,offset,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_pipe(int pipefd[])

            a wrapper for the pipe system call on unix systems

            INPUT  :(int pipefd[])

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pipe(int pipefd[])
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIPE(pipefd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*
static ADL_RESULT adl_sys_pipe2(int pipefd[],int flags)

            a wrapper for the pipe2 system call on unix systems

            INPUT  :(int pipefd[],int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pipe2(int pipefd[],int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIPE2(pipefd,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
static ADL_RESULT adl_sys_select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout)

            a wrapper for the select system call on unix systems

            INPUT  :(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SELECT(nfds,readfds,writefds,exceptfds,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
static ADL_RESULT adl_sys_pselect(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,const struct timespec *timeout,const sigset_t *sigmask)

            a wrapper for the pselect system call on unix systems

            INPUT  :(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,const struct timespec *timeout,const sigset_t *sigmask)


            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pselect(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,const struct timespec *timeout,const sigset_t *sigmask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PSELECT(nfds,readfds,writefds,exceptfds,timeout,sigmask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_dup(int fd)

            a wrapper for the dup system call on unix systems

            INPUT  :(int fd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_dup(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_DUP(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_dup2(int oldfd,int newfd)

            a wrapper for the dup2 system call on unix systems

            INPUT  :(int oldfd,int newfd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_dup2(int oldfd,int newfd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_DUP2(oldfd,newfd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
static ADL_RESULT adl_sys_dup3(int oldfd,int newfd,int flags)

            a wrapper for the dup3 system call on unix systems

            INPUT  :(int oldfd,int newfd,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_dup3(int oldfd,int newfd,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_DUP3(oldfd,newfd,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
static ADL_RESULT adl_sys_flock(int fd,int op)

            a wrapper for the flock system call on unix systems

            INPUT  :(int fd,int op)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_flock(int fd,int op)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FLOCK(fd,op);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
static ADL_RESULT adl_sys_fsync(int fd)

            a wrapper for the fsync system call on unix systems

            INPUT  :(int fd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

static ADL_RESULT adl_sys_fsync(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FSYNC(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_fdatasync(int fd)

            a wrapper for the fdatasync system call on unix systems

            INPUT  :(int fd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fdatasync(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FDATASYNC(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_truncate(const char *path,off_t length)

            a wrapper for the truncate system call on unix systems

            INPUT  :(const char *path,off_t length)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_truncate(const char *path,off_t length)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_TRUNCATE(path,length);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_ftruncate(int fd,off_t length)

            a wrapper for the ftruncate system call on unix systems

            INPUT  :(int fd,off_t length)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_ftruncate(int fd,off_t length)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FTRUNCATE(fd,length);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_getcwd(char *buf,size_t buf_size)

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

static ADL_RESULT adl_sys_getcwd(char *buf,size_t buf_size)
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

static ADL_RESULT adl_sys_chdir(const char *path)

            a wrapper for the chdir system call on unix systems

            INPUT  :(const char *path)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_chdir(const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CHDIR(path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_fchdir(int fd)

            a wrapper for the fchdir system call on unix systems

            INPUT  :(int fd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fchdir(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FCHDIR(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_rename(const char *oldpath,const char *newpath)

            a wrapper for the rename system call on unix systems

            INPUT  :(const char *oldpath,const char *newpath)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_rename(const char *oldpath,const char *newpath)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RENAME(oldpath,newpath);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_renameat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath)

            a wrapper for the renameat system call on unix systems

            INPUT  :(int olddirfd,const char *oldpath,int newdirfd,const char *newpath)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_renameat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RENAMEAT(olddirfd,oldpath,newdirfd,newpath);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_renameat2(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)

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

static ADL_RESULT adl_sys_renameat2(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RENAMEAT2(olddirfd,oldpath,newdirfd,newpath,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_mkdir(const char *path,mode_t mode)

            a wrapper for the mkdir system call on unix systems

            INPUT  :(const char *path,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mkdir(const char *path,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MKDIR(path,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_mkdirat(int dirfd,const char *path,mode_t mode)

            a wrapper for the mkdirat system call on unix systems

            INPUT  :(int dirfd,const char *path,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mkdirat(int dirfd,const char *path,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MKDIRAT(dirfd,path,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_rmdir(const char *path)

            a wrapper for the rmdir system call on unix systems

            INPUT  :(const char *path)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_rmdir(const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RMDIR(path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_link(const char *oldpath,const char *newpath)

            a wrapper for the link system call on unix systems

            INPUT  :(const char *oldpath,const char *newpath)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_link(const char *oldpath,const char *newpath)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LINK(oldpath,newpath);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_linkat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)

            a wrapper for the linkat system call on unix systems

            INPUT  :(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_linkat(int olddirfd,const char *oldpath,int newdirfd,const char *newpath,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LINKAT(olddirfd,oldpath,newdirfd,newpath,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_unlink(const char *path)

            a wrapper for the unlink system call on unix systems

            INPUT  :(const char *path)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_unlink(const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UNLINK(path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_unlinkat(int dirfd,const char *path,int flags)

            a wrapper for the unlinkat system call on unix systems

            INPUT  :(int dirfd,const char *path,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_unlinkat(int dirfd,const char *path,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UNLINKAT(dirfd,path,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_symlink(const char *target,const char *linkpath)

            a wrapper for the symlink system call on unix systems

            INPUT  :(const char *target,const char *linkpath)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_symlink(const char *target,const char *linkpath)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYMLINK(target,linkpath);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_symlinkat(const char *target,int newdirfd,const char *linkpath)

            a wrapper for the symlinkat system call on unix systems

            INPUT  :(const char *target,int newdirfd,const char *linkpath)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_symlinkat(const char *target,int newdirfd,const char *linkpath)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYMLINKAT(target,newdirfd,linkpath);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_readlink(const char *path,char *buf,size_t buf_size)

            a wrapper for the readlink system call on unix systems

            INPUT  :(const char *path,char *buf,size_t buf_size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_readlink(const char *path,char *buf,size_t buf_size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_READLINK(path,buf,buf_size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_readlinkat(int dirfd,const char *path,char *buf,size_t buf_size)

            a wrapper for the readlinkat system call on unix systems

            INPUT  :(int dirfd,const char *path,char *buf,size_t buf_size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_readlinkat(int dirfd,const char *path,char *buf,size_t buf_size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_READLINKAT(dirfd,path,buf,buf_size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_chmod(const char *path,mode_t mode)

            a wrapper for the chmod system call on unix systems

            INPUT  :(const char *path,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_chmod(const char *path,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CHMOD(path,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_fchmod(int fd,mode_t mode)

            a wrapper for the fchmod system call on unix systems

            INPUT  :(int fd,mode_t mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fchmod(int fd,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FCHMOD(fd,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_fchmodat(int dirfd,const char *path,mode_t mode,int flags)

            a wrapper for the fchomodat system call on unix systems

            INPUT  :(int dirfd,const char *path,mode_t mode,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fchmodat(int dirfd,const char *path,mode_t mode,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FCHMODAT(dirfd,path,mode,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_chown(const char *path,uid_t owner,gid_t group)

            a wrapper for the chown system call on unix systems

            INPUT  :(const char *path,uid_t owner,gid_t group)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_chown(const char *path,uid_t owner,gid_t group)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CHOWN(path,owner,group);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_lchown(const char *path,uid_t owner,gid_t group)

            a wrapper for the lchown system call on unix systems

            INPUT  :(const char *path,uid_t owner,gid_t group)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_lchown(const char *path,uid_t owner,gid_t group)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LCHOWN(path,owner,group);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_fchown(int fd,uid_t owner,gid_t group)

            a wrapper for the fchown system call on unix systems

            INPUT  :(int fd,uid_t owner,gid_t group)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fchown(int fd,uid_t owner,gid_t group)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FCHOWN(fd,owner,group);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}







/*

static ADL_RESULT adl_sys_fchownat(int dirfd,const char *path,uid_t owner,gid_t group,int flags)

            a wrapper for the fchownat system call on unix systems

            INPUT  :(int dirfd,const char *path,uid_t owner,gid_t group,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fchownat(int dirfd,const char *path,uid_t owner,gid_t group,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FCHOWNAT(dirfd,path,owner,group,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_umask(mode_t mask)

            a wrapper for the umask system call on unix systems

            INPUT  :(mode_t mask)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_umask(mode_t mask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UMASK(mask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_mknod(const char *path,mode_t mode,dev_t dev)

            a wrapper for the mknod system call on unix systems

            INPUT  :(const char *path,mode_t mode,dev_t dev)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mknod(const char *path,mode_t mode,dev_t dev)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_sys_MKNOD(path,mode,dev);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_mknodat(int dirfd,const char *path,mode_t mode,dev_t dev)

            a wrapper for the mknodat system call on unix systems

            INPUT  :(int dirfd,const char *path,mode_t mode,dev_t dev)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mknodat(int dirfd,const char *path,mode_t mode,dev_t dev)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_sys_MKNODAT(dirfd,path,mode,dev);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}







/*

static ADL_RESULT adl_sys_statfs(const char *path,struct statfs *buf)

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

static ADL_RESULT adl_sys_statfs(const char *path,struct statfs *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_STATFS(path,buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_fstatfs(int fd,struct statfs *buf)

            a wrapper for the fstatfs system call on unix systems

            INPUT  :(int fd,struct statfs *buf)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fstatfs(int fd,struct statfs *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FSTATFS(fd,buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_vhangup(void)

            a wrapper for the vhangup system call on unix systems

            INPUT  :(void)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_vhangup(void)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_VHANGUP();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_pivot_root(const char *newroot,const char *putold)

            a wrapper for the pivot_root system call on unix systems

            INPUT  :(const char *newroot,const char *putold)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pivot_root(const char *newroot,const char *putold)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIVOT_ROOT(newroot,putold);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___






/*

static ADL_RESULT adl_sys_chroot(const char *path)

            a wrapper for the chroot system call on unix systems

            INPUT  :(const char *path)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_chroot(const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CHROOT(path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_sync(void)

            a wrapper for the sync system call on unix systems

            INPUT  :(void)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sync(void)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_SYNC();
    rdr_ret = 0;
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_syncfs(int fd)

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

static ADL_RESULT adl_sys_syncfs(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYNCFS(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_mount(const char *source,const char *target,const char *fstype,unsigned long mountflags,const void *data)

            a wrapper for the mount system call on unix systems

            INPUT  :(const char *source,const char *target,const char *fstype,unsigned long mountflags,const void *data)


            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mount(const char *source,const char *target,const char *fstype,unsigned long mountflags,const void *data)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MOUNT(source,target,fstype,mountflags,data);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_umount(const char *target)

            a wrapper for the umount system call on unix systems

            INPUT  :(const char *target)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_umount(const char *target)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UMOUNT(target);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_umount2(const char *target,int flags)

            a wrapper for the umount2 system call on unix systems

            INPUT  :(const char *target,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_umount2(const char *target,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UMOUNT2(target,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_ioperm(unsigned long from,unsigned long num,int turnon)

            a wrapper for the ioperm system call on unix systems

            INPUT  :(unsigned long from,unsigned long num,int turnon)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_ioperm(unsigned long from,unsigned long num,int turnon)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IOPERM(from,num,turnon);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_readahead(int fd,off_t offset,size_t count)

            a wrapper for the readahead system call on unix systems

            INPUT  :(int fd,off_t offset,size_t count)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_readahead(int fd,off_t offset,size_t count)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_READAHEAD(fd,offset,count);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_setxattr(const char *path,const char *name,const void *value,size_t size,int flags)

            a wrapper for the setxattr system call on unix systems

            INPUT  :(const char *path,const char *name,const void *value,size_t size,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setxattr(const char *path,const char *name,const void *value,size_t size,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETXATTR(path,name,value,size,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_lsetxattr(const char *path,const char *name,const void *value,size_t size,int flags)             

            a wrapper for the lsetxattr system call on unix systems

            INPUT  :(const char *path,const char *name,const void *value,size_t size,int flags) 

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_lsetxattr(const char *path,const char *name,const void *value,size_t size,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LSETXATTR(path,name,value,size,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_fsetxattr(int fd,const char *name,const void *value,size_t size,int flags)

            a wrapper for the fsetxattr system call on unix systems

            INPUT  :(int fd,const char *name,const void *value,size_t size,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fsetxattr(int fd,const char *name,const void *value,size_t size,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FSETXATTR(fd,name,value,size,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_getxattr(const char *path,const char *name,void *value,size_t size)

            a wrapper for the getxattr system call on unix systems

            INPUT  :(const char *path,const char *name,void *value,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getxattr(const char *path,const char *name,void *value,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETXATTR(path,name,value,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_lgetxattr(const char *path,const char *name,void *value,size_t size)

            a wrapper for the lgetxattr system call on unix systems

            INPUT  :(const char *path,const char *name,void *value,size_t size)


            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_lgetxattr(const char *path,const char *name,void *value,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LGETXATTR(path,name,value,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_fgetxattr(int fd,const char *name,void *value,size_t size)

            a wrapper for the fgetxattr system call on unix systems

            INPUT  :(int fd,const char *name,void *value,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fgetxattr(int fd,const char *name,void *value,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FGETXATTR(fd,name,value,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_listxattr(const char *path,char *list,size_t size)

            a wrapper for the listxattr system call on unix systems

            INPUT  :(const char *path,char *list,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_listxattr(const char *path,char *list,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LISTXATTR(path,list,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_llistxattr(const char *path,char *list,size_t size)

            a wrapper for the llistxattr system call on unix systems

            INPUT  :(const char *path,char *list,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_llistxattr(const char *path,char *list,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LLISTXATTR(path,list,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_flistxattr(int fd,char *list,size_t size)

            a wrapper for the flistxattr system call on unix systems

            INPUT  :(int fd,char *list,size_t size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_flistxattr(int fd,char *list,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FLISTXATTR(fd,list,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_removexattr(const char *path,const char *name)

            a wrapper for the removexattr system call on unix systems

            INPUT  :(const char *path,const char *name)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_removexattr(const char *path,const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_REMOVEXATTR(path,name);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_lremovexattr(const char *path,const char *name)

            a wrapper for the lremovexattr system call on unix systems

            INPUT  :(const char *path,const char *name)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_lremovexattr(const char *path,const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LREMOVEXATTR(path,name);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_fremovexattr(int fd,const char *name)

            a wrapper for the fremovexattr system call on unix systems

            INPUT  :(int fd,const char *name)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fremovexattr(int fd,const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FREMOVEXATTR(fd,name);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_ioprio_set(int which,int who,int ioprio)

            a wrapper for the ioprio_set system call on unix systems

            INPUT  :(int which,int who,int ioprio)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_ioprio_set(int which,int who,int ioprio)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IOPRIO_SET(which,who,ioprio);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_ioprio_get(int which,int who)

            a wrapper for the ioprio_get system call on unix systems

            INPUT  :(int which,int who)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_ioprio_get(int which,int who)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IOPRIO_GET(which,who);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_inotify_init()

            a wrapper for the inotify_init system call on unix systems

            INPUT  :()

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_inotify_init()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INOTIFY_INIT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_inotify_init1(int flags)

            a wrapper for the inotify_init1 system call on unix systems

            INPUT  :(int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_inotify_init1(int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INOTIFY_INIT1(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_inotify_add_watch(int fd,const char *path,uint32_t mask)

            a wrapper for the inotify_add_watch system call on unix systems

            INPUT  :(int fd,const char *path,uint32_t mask)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_inotify_add_watch(int fd,const char *path,uint32_t mask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INOTIFY_ADD_WATCH(fd,path,mask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_inotify_rm_watch(int fd,int wd)

            a wrapper for the inotify_rm_watch system call on unix systems

            INPUT  :(int fd,int wd)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_inotify_rm_watch(int fd,int wd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INOTIFY_RM_WATCH(fd,wd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

static ADL_RESULT adl_sys_access(const char *path,int mode)

            a wrapper for the access system call on unix systems

            INPUT  :(const char *path,int mode)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_access(const char *path,int mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_ACCESS(path,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_faccessat(int dirfd,const char *path,int mode,int flags)

            a wrapper for the faccessat system call on unix systems

            INPUT  :(int dirfd,const char *path,int mode,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_faccessat(int dirfd,const char *path,int mode,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FACCESSAT(dirfd,path,mode,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
___adl_linux_std___
___adl_syscall___




/*

static ADL_RESULT adl_sys_faccessat2(int dirfd,const char *path,int mode,int flags)

            a wrapper for the faccessat2 system call on unix systems

            INPUT  :(int dirfd,const char *path,int mode,int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_faccessat2(int dirfd,const char *path,int mode,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FACCESSAT2(dirfd,path,mode,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_quotactl(int op,const char *special,int id, caddr_t addr)

            a wrapper for the quotactl system call on unix systems

            INPUT  :(int op,const char *special,int id, caddr_t addr)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_quotactl(int op,const char *special,int id, caddr_t addr)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_QUOTACTL(op,special,id,addr);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_io_setup(unsigned int nr_events,aio_context_t *ctx_id)

            a wrapper for the io_setup system call on unix systems

            INPUT  :(unsigned int nr_events,aio_context_t *ctx_id)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_io_setup(unsigned int nr_events,aio_context_t *ctx_id)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IO_SETUP(nr_events,ctx_id);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_io_destroy(aio_context_t ctx_id)

            a wrapper for the io_destroy system call on unix systems

            INPUT  :(aio_context_t ctx_id)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_io_destroy(aio_context_t ctx_id)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IO_DESTROY(ctx_id);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_io_getevents(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout)

            a wrapper for the io_getevents system call on unix systems

            INPUT  :(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout)


            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_io_getevents(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IO_GETEVENTS(ctx_id,min_nr,nr,events,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_io_submit(aio_context_t ctx_id, long nr, struct iocb **iocb)

            a wrapper for the io_submit system call on unix systems

            INPUT  :(aio_context_t ctx_id, long nr, struct iocb **iocb)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_io_submit(aio_context_t ctx_id, long nr, struct iocb **iocb)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IO_SUBMIT(ctx_id,nr,iocb);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_io_cancel(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result)

            a wrapper for the io_cancel system call on unix systems

            INPUT  :(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_io_cancel(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_IO_CANCEL(ctx_id,iocb,result);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_lookup_dcookie(uint64_t cookie, char *buffer,size_t len)

            a wrapper for the lookup_dcookie system call on unix systems

            INPUT  :(uint64_t cookie, char *buffer,size_t len)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_lookup_dcookie(uint64_t cookie, char *buffer,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LOOKUP_DCOOKIE(cookie,buffer,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_epoll_create(int size)

            a wrapper for the epoll system call on unix systems

            INPUT  :(int size)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_epoll_create(int size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_CREATE(size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_epoll_create1(int flags)

            a wrapper for the epoll_create1 system call on unix systems

            INPUT  :(int flags)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_epoll_create1(int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_CREATE1(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout)

            a wrapper for the epoll_wait system call on unix systems

            INPUT  :(int epfd, struct epoll_event *events,int maxevents, int timeout)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_WAIT(epfd,events,maxevents,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_epoll_pwait(int epfd, struct epoll_event *events,int maxevents, int timeout,const sigset_t *sigmask)

            a wrapper for epoll_pwait system call on unix systems

            INPUT  :(int epfd, struct epoll_event *events,int maxevents, int timeout,const sigset_t *sigmask)


            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_epoll_pwait(int epfd, struct epoll_event *events,int maxevents, int timeout,const sigset_t *sigmask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_PWAIT(epfd,events,maxevents,timeout,sigmask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_epoll_pwait2(int epfd, struct epoll_event *events,int maxevents,const struct timespec * timeout,const sigset_t *sigmask)

            a wrapper for epoll_pwait2 system call on unix systems

            INPUT  :(int epfd, struct epoll_event *events,int maxevents,const struct timespec * timeout,const sigset_t *sigmask)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_epoll_pwait2(int epfd, struct epoll_event *events,int maxevents,const struct timespec * timeout,const sigset_t *sigmask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_PWAIT2(epfd,events,maxevents,timeout,sigmask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_epoll_ctl(int epfd, int op, int fd,struct epoll_event *event)

            a wrapper for epoll_ctl system call on unix systems

            INPUT  :(int epfd, int op, int fd,struct epoll_event *event)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_epoll_ctl(int epfd, int op, int fd,struct epoll_event *event)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EPOLL_CTL(epfd,op,fd,event);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_splice(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)

            a wrapper for splice system call on unix systems

            INPUT  :(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_splice(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SPLICE(fd_in,off_in,fd_out,off_out,len,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_tee(int fd_in, int fd_out, size_t len, unsigned int flags)

            a wrapper for tee system call on unix systems

            INPUT  :(int fd_in, int fd_out, size_t len, unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_tee(int fd_in, int fd_out, size_t len, unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_TEE(fd_in,fd_out,len,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
___adl_end_linux___






/*

static ADL_RESULT adl_sys_posix_fadvise64(int fd,off_t offset,off_t len,int advice)

            a wrapper for posix_fadvise64 system call on unix systems

            INPUT  :(int fd,off_t offset,off_t len,int advice)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_posix_fadvise64(int fd,off_t offset,off_t len,int advice)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_POSIX_FADVICE64(fd,offset,len,advice);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_utime(const char *path,const struct utimbuf *times)

            a wrapper for utime system call on unix systems

            INPUT  :(const char *path,const struct utimbuf *times)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_utime(const char *path,const struct utimbuf *times)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UTIME(path,times);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_utimes(const char *path,const struct timeval *times)

            a wrapper for utimes system call on unix systems

            INPUT  :(const char *path,const struct timeval *times)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_utimes(const char *path,const struct timeval *times)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UTIMES(path,times);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_utimensat(int dirfd, const char *path,const struct timespec *times, int flags)

            a wrapper for utimensat system call on unix systems

            INPUT  :(int dirfd, const char *path,const struct timespec *times, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_utimensat(int dirfd, const char *path,const struct timespec *times, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UTIMENSAT(dirfd,path,times,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_futimens(int fd,const struct timespec *times)

            a wrapper for futimens system call on unix systems

            INPUT  :(int fd,const struct timespec *times)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_futimens(int fd,const struct timespec *times)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FUTIMENS(fd,times);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sync_file_range(int fd, off_t offset, off_t count,unsigned int flags)

            a wrapper for file_range system call on unix systems

            INPUT  :(int fd, off_t offset, off_t count,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sync_file_range(int fd, off_t offset, off_t count,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYNC_FILE_RANGE(fd,offset,count,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_fallocate(int fd, int mode, off_t offset, off_t len)

            a wrapper for fallocate system call on unix systems

            INPUT  :(int fd, int mode, off_t offset, off_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fallocate(int fd, int mode, off_t offset, off_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FALLOCATE(fd,mode,offset,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_fanotify_init(unsigned int flags, unsigned int event_f_flags)

            a wrapper for fanotify_init system call on unix systems

            INPUT  :(unsigned int flags, unsigned int event_f_flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fanotify_init(unsigned int flags, unsigned int event_f_flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FANOTIFY_INIT(flags,event_f_flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_fanotify_mark(int fd, unsigned int flags,uint64_t mask, int dirfd, const char *path)

            a wrapper for fanotify_mark system call on unix systems

            INPUT  :(int fd, unsigned int flags,uint64_t mask, int dirfd, const char *path)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fanotify_mark(int fd, unsigned int flags,uint64_t mask, int dirfd, const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FANOTIFY_MARK(fd,flags,mask,dirfd,path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_name_to_handle_at(int dirfd, const char *path,struct file_handle *handle,int *mount_id, int flags)

            a wrapper for name_to_handle_at system call on unix systems

            INPUT  :(int dirfd, const char *path,struct file_handle *handle,int *mount_id, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_name_to_handle_at(int dirfd, const char *path,struct file_handle *handle,int *mount_id, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_NAME_TO_HANDLE_AT(dirfd,path,handle,mount_id,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_open_by_handle_at(int mount_fd, struct file_handle *handle,int flags)

            a wrapper for open_by_handle_at system call on unix systems

            INPUT  :(int mount_fd, struct file_handle *handle,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_open_by_handle_at(int mount_fd, struct file_handle *handle,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_OPEN_BY_HANDLE_AT(mount_fd,handle,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_copy_file_range(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)

            a wrapper for copy_file_range system call on unix systems

            INPUT  :(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_copy_file_range(int fd_in, off_t *off_in,int fd_out, off_t *off_out,size_t len, unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_COPY_FILE_RANGE(fd_in,off_in,fd_out,off_out,len,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_statx(int dirfd, const char *path, int flags,unsigned int mask, struct statx *statxbuf)

            a wrapper for statx system call on unix systems

            INPUT  :(int dirfd, const char *path, int flags,unsigned int mask, struct statx *statxbuf)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_statx(int dirfd, const char *path, int flags,unsigned int mask, struct statx *statxbuf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_STATX(dirfd,path,flags,mask,statxbuf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_close_range(unsigned int first, unsigned int last, int flags)

            a wrapper for close_range system call on unix systems

            INPUT  :(unsigned int first, unsigned int last, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_close_range(unsigned int first, unsigned int last, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLOSE_RANGE(first,last,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_mount_setattr(int dirfd, const char *path,unsigned int flags, struct mount_attr *attr, size_t size)

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

static ADL_RESULT adl_sys_mount_setattr(int dirfd, const char *path,unsigned int flags, struct mount_attr *attr, size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MOUNT_SETATTR(dirfd,path,flags,attr,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_mkfifo(const char *name,mode_t mode)

            a wrapper for mkfifo library call on unix systems

            INPUT  :(const char *name,mode_t mode)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



static ADL_RESULT adl_lib_mkfifo(const char *name,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MKFIFO(name,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_mkfifoat(int dirfd,const char *name,mode_t mode)

            a wrapper for mkfifoat library call on unix systems

            INPUT  :(int dirfd,const char *name,mode_t mode)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_mkfifoat(int dirfd,const char *name,mode_t mode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MKFIFOAT(dirfd,name,mode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




static ADL_RESULT adl_lib_opendir(const char *str)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_OPENDIR(str);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

static ADL_RESULT adl_lib_fdopendir(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_FDOPENDIR(fd);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

static ADL_RESULT adl_lib_readdir(DIR *dirp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_READDIR(dirp);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

static ADL_RESULT adl_lib_rewinddir(DIR *dirp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_REWINDDIR(dirp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

static ADL_RESULT adl_lib_closedir(DIR *dirp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLOSEDIR(dirp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}


static ADL_RESULT adl_lib_dirfd(DIR *dirp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_DIRFD(dirp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

                TIME

*/



/*

static ADL_RESULT adl_sys_pause(void)

            a wrapper for pause system call on unix systems

            INPUT  :(void)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pause(void)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_PAUSE();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_nanosleep(const struct timespec *duration,struct timespec *remaining)

            a wrapper for nanosleep system call on unix systems

            INPUT  :(const struct timespec *duration,struct timespec *remaining)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_nanosleep(const struct timespec *duration,struct timespec *remaining)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_NANOSLEEP(duration,remaining);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getitimer(int which,struct itimerval *current)

            a wrapper for getitimer system call on unix systems

            INPUT  :(int which,struct itimerval *current)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_obsolete___

static ADL_RESULT adl_sys_getitimer(int which,struct itimerval *current)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_GETITIMER(which,current);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_setitimer(int which,const struct itimerval *new,struct itimerval *old)

            a wrapper for setitimer system call on unix systems

            INPUT  :(int which,const struct itimerval *new,struct itimerval *old)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setitimer(int which,const struct itimerval *new,struct itimerval *old)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_SETITIMER(which,new,old);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
___adl_end_obsolete___




/*

static ADL_RESULT adl_sys_alarm(unsigned int seconds)

            a wrapper for alarm system call on unix systems

            INPUT  :(unsigned int seconds)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_alarm(unsigned int seconds)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_ALARM(seconds);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_gettimeofday(struct timeval *tv,struct timezone *tz)

            a wrapper for gettimeofday system call on unix systems

            INPUT  :(struct timeval *tv,struct timezone *tz)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_obsolete___

static ADL_RESULT adl_sys_gettimeofday(struct timeval *tv,struct timezone *tz)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_GETTIMEOFDAY(tv,tz);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
static ADL_RESULT adl_sys_settimeofday(const struct timeval *tv,const struct timezone *tz)

            a wrapper for settimeofday system call on unix systems

            INPUT  :(const struct timeval *tv,const struct timezone *tz)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_settimeofday(const struct timeval *tv,const struct timezone *tz)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_SETTIMEOFDAY(tv,tz);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
___adl_end_obsolete___





/*

static ADL_RESULT adl_sys_timer_create(clockid_t clockid,struct sigevent *sigevent,timer_t *timerid)

            a wrapper for timer_create system call on unix systems

            INPUT  :(clockid_t clockid,struct sigevent *sigevent,timer_t *timerid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_timer_create(clockid_t clockid,struct sigevent *sigevent,timer_t *timerid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMER_CREATE(clockid,sigevent,timerid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_timer_settime(timer_t timerid, int flags,const struct itimerspec *new,struct itimerspec *old)

            a wrapper timer_settime system call on unix systems

            INPUT  :(timer_t timerid, int flags,const struct itimerspec *new,struct itimerspec *old)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_timer_settime(timer_t timerid, int flags,const struct itimerspec *new,struct itimerspec *old)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMER_SETTIME(timerid,flags,new,old);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_timer_gettime(timer_t timerid, struct itimerspec *current)

            a wrapper for timer_gettime system call on unix systems

            INPUT  :(timer_t timerid, struct itimerspec *current)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_timer_gettime(timer_t timerid, struct itimerspec *current)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMER_GETTIME(timerid,current);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_timer_getoverrun(timer_t timerid)

            a wrapper for timer_getoverrun system call on unix systems

            INPUT  :(timer_t timerid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_timer_getoverrun(timer_t timerid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMER_GETOVERRUN(timerid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_timer_delete(timer_t timerid)

            a wrapper for timer-delete system call on unix systems

            INPUT  :(timer_t timeri
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_timer_delete(timer_t timerid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMER_DELETE(timerid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_clock_settime(clockid_t clockid,const struct timespec *tp)

            a wrapper for clock_settime system call on unix systems

            INPUT  :(clockid_t clockid,const struct timespec *tp)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_clock_settime(clockid_t clockid,const struct timespec *tp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_CLOCK_SETTIME(clockid,tp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_clock_gettime(clockid_t clockid,struct timespec *tp)

            a wrapper for clock_gettime system call on unix systems

            INPUT  :(clockid_t clockid,struct timespec *tp)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_clock_gettime(clockid_t clockid,struct timespec *tp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_CLOCK_GETTIME(clockid,tp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_clock_getres(clockid_t clockid,struct timespec *res)

            a wrapper for clock_getres system call on unix systems

            INPUT  :(clockid_t clockid,struct timespec *res)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_clock_getres(clockid_t clockid,struct timespec *res)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_CLOCK_GETRES(clockid,res);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}


/*

static ADL_RESULT adl_sys_clock_nanosleep(clockid_t clockid, int flags,const struct timespec *duration,struct timespec *remaining)

            a wrapper for clock_nanosleep system call on unix systems

            INPUT  :(clockid_t clockid, int flags,const struct timespec *duration,struct timespec *remaining)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_clock_nanosleep(clockid_t clockid, int flags,const struct timespec *duration,struct timespec *remaining)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_CLOCK_NANOSLEEP(clockid,flags,duration,remaining);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_clock_adjtime(clockid_t clockid,struct timex *buf)

            a wrapper for clock_adjtime system call on unix systems

            INPUT  :(clockid_t clockid,struct timex *buf)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_clock_adjtime(clockid_t clockid,struct timex *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_CLOCK_ADJTIME(clockid,buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_adjtimex(struct timex *buf)

            a wrapper for adjtimex system call on unix systems

            INPUT  :(struct timex *buf)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_adjtimex(struct timex *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_ADJTIMEX(buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_time(time_t *timep)

            a wrapper for time system call on unix systems

            INPUT  :(time_t *timep)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_time(time_t *timep)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIME(timep);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_timerfd_settime(int fd,int flags,const struct itimerspec *new,struct itimerspec *old)

            a wrapper timerfd_settime system call on unix systems

            INPUT  :(int fd,int flags,const struct itimerspec *new,struct itimerspec *old)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

static ADL_RESULT adl_sys_timerfd_settime(int fd,int flags,const struct itimerspec *new,struct itimerspec *old)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMERFD_SETTIME(fd,flags,new,old);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_timerfd_gettime(int fd,struct itimerspec *current)

            a wrapper for timerfd_gettime system call on unix systems

            INPUT  :(const struct timespec *duration,struct timespec *remaining)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_timerfd_gettime(int fd,struct itimerspec *current)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMERFD_GETTIME(fd,current);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_timerfd_create(int clockid, int flags)

            a wrapper for timerfd_create system call on unix systems

            INPUT  :(int clockid, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_timerfd_create(int clockid, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMERFD_CREATE(clockid,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
___adl_end_linux___











/*
    INTER-PROCESS COMMUNICATION
*/



/*

static ADL_RESULT adl_sys_shmget(key_t key,size_t size,int flags)

            a wrapper for shmget system call on unix systems

            INPUT  :(key_t key,size_t size,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_shmget(key_t key,size_t size,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SHMGET(key,size,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_shmat(int id, const void *addr, int flags)

            a wrapper for shmat system call on unix systems

            INPUT  :(int id, const void *addr, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_shmat(int id, const void *addr, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_SHMAT(id,addr,flags);
    
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_shmctl(int id, int op, struct shmid_ds *buf)

            a wrapper for shmctl system call on unix systems

            INPUT  :(int id, int op, struct shmid_ds *buf)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_shmctl(int id, int op, struct shmid_ds *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SHMCTL(id,op,buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_shmdt(const void *addr)

            a wrapper for shmdt system call on unix systems

            INPUT  :(const void *addr)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_shmdt(const void *addr)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SHMDT(addr);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_msgget(key_t key, int flags)

            a wrapper for msgget system call on unix systems

            INPUT  :(key_t key, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_msgget(key_t key, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MSGGET(key,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}


/*

static ADL_RESULT adl_sys_msgsnd(int id, const void *buf,size_t buflen,int flags)

            a wrapper for msgsnd system call on unix systems

            INPUT  :(int id, const void *buf,size_t buflen,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_msgsnd(int id, const void *buf,size_t buflen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MSGSND(id,buf,buflen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_msgrcv(int id,void *buf,size_t buflen,long type,int flags)

            a wrapper for msgrcv system call on unix systems

            INPUT  :(int id,void *buf,size_t buflen,long type,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_msgrcv(int id,void *buf,size_t buflen,long type,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MSGRCV(id,buf,buflen,type,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_msgctl(int id, int op, struct msqid_ds *buf)

            a wrapper for msgctl system call on unix systems

            INPUT  :(int id, int op, struct msqid_ds *buf)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_msgctl(int id, int op, struct msqid_ds *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MSGCTL(id,op,buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_mq_open_v1(const char *name,int flags)

            a wrapper for mq_open_v1 system call on unix systems

            INPUT  :(const char *name,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mq_open_v1(const char *name,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_OPEN(name,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_mq_open_v2(const char *name,int flags,mode_t mode,struct mq_attr *attr)

            a wrapper for mq_open_v2 system call on unix systems

            INPUT  :(const char *name,int flags,mode_t mode,struct mq_attr *attr)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mq_open_v2(const char *name,int flags,mode_t mode,struct mq_attr *attr)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_OPEN(name,flags,mode,attr);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_mq_unlink(const char *name)

            a wrapper for mq_unlink system call on unix systems

            INPUT  :(const char *name)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mq_unlink(const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_UNLINK(name);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_mq_timedsend(mqd_t fd, const char *buf,size_t buflen, unsigned int priority,const struct timespec *timeout)

            a wrapper for mq_timedsend system call on unix systems

            INPUT  :(mqd_t fd, const char *buf,size_t buflen, unsigned int priority,const struct timespec *timeout
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mq_timedsend(mqd_t fd, const char *buf,size_t buflen, unsigned int priority,const struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_TIMEDSEND(fd,buf,buflen,priority,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_mq_timedreceive(mqd_t fd,char *buf,size_t buflen, unsigned int *priority,const struct timespec *timeout)

            a wrapper for mq_timedreceive system call on unix systems

            INPUT  :(mqd_t fd,char *buf,size_t buflen, unsigned int *priority,const struct timespec *timeout)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mq_timedreceive(mqd_t fd,char *buf,size_t buflen, unsigned int *priority,const struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_TIMEDRECEIVE(fd,buf,buflen,priority,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_mq_notify(mqd_t fd, const struct sigevent *sigevent)

            a wrapper for mq_notify system call on unix systems

            INPUT  :(mqd_t fd, const struct sigevent *sigevent)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mq_notify(mqd_t fd, const struct sigevent *sigevent)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_NOTIFY(fd,sigevent);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_mq_getsetattr(mqd_t fd,const struct mq_attr *new,struct mq_attr *old)

            a wrapper for mq_getsetattr system call on unix systems

            INPUT  :(mqd_t fd,const struct mq_attr *new,struct mq_attr *old)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_not_for_apps_for_glibc___

static ADL_RESULT adl_sys_mq_getsetattr(mqd_t fd,const struct mq_attr *new,struct mq_attr *old)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_GETSETATTR(fd,new,old);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}








/*
    SYNCHRONIZATION
*/



/*

static ADL_RESULT adl_sys_semget(key_t key, int num, int flags)

            a wrapper for semget system call on unix systems

            INPUT  :(key_t key, int num, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_semget(key_t key, int num, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEMGET(key,num,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_semop(int id, struct sembuf *sops, size_t num)

            a wrapper for semop system call on unix systems

            INPUT  :(int id, struct sembuf *sops, size_t num)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_semop(int id, struct sembuf *sops, size_t num)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEMOP(id,sops,num);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_semtimedop(int id, struct sembuf *sops, size_t num,const struct timespec *timeout)

            a wrapper for semptimedop system call on unix systems

            INPUT  :(int id, struct sembuf *sops, size_t num,const struct timespec *timeout)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_semtimedop(int id, struct sembuf *sops, size_t num,const struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEMTIMEDOP(id,sops,num,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_semctl(int id, int num,int op,...)

            a wrapper for semctl system call on unix systems

            INPUT  :(int id, int num,int op,...
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_semctl(int id, int num,int op,...)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEMCTL(id,num,op);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_futex(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3)

            a wrapper for futex system call on unix systems

            INPUT  :(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___
___adl_syscall___

static ADL_RESULT adl_sys_futex(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FUTEX(uaddr,futex_op,val,timeout,uaddr2,val3);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_set_robust_list(struct robust_list_head *head,size_t len)

            a wrapper for set_robust_list system call on unix systems

            INPUT  :(struct robust_list_head *head,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_set_robust_list(struct robust_list_head *head,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SET_ROBUST_LIST(head,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_get_robust_list(int pid,struct robust_list_head **head, size_t *len)

            a wrapper for get-robust_list system call on unix systems

            INPUT  :(int pid,struct robust_list_head **head, size_t *len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_get_robust_list(int pid,struct robust_list_head **head, size_t *len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GET_ROBUST_LIST(pid,head,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___
___adl_end_linux___











/*

                PROCESS MANAGEMENT

*/




/*

static ADL_RESULT adl_sys_capget(cap_user_header_t hdrp,cap_user_data_t datap)

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

static ADL_RESULT adl_sys_capget(cap_user_header_t hdrp,cap_user_data_t datap)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CAPGET(hdrp,datap);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

static ADL_RESULT adl_sys_capset(cap_user_header_t hdrp,const cap_user_data_t datap)

            a wrapper for capset system call on unix systems

            INPUT  :(cap_user_header_t hdrp,const cap_user_data_t datap)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_capset(cap_user_header_t hdrp,const cap_user_data_t datap)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CAPSET(hdrp,datap);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_clone3(struct clone_args *cl_args,size_t size)

            a wrapper for clone3 system call on unix systems

            INPUT  :(struct clone_args *cl_args,size_t size)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_clone3(struct clone_args *cl_args,size_t size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLONE3(cl_args,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___





/*

static ADL_RESULT adl_sys_clone(int (*fn)(void *),void *stack,int flags,void *arg,pid_t *parent_tid,void *tls,pid_t *child_tid)

            a wrapper for clone system call on unix systems

            INPUT  :(int (*fn)(void *),void *stack,int flags,void *arg,pid_t *parent_tid,void *tls,pid_t *child_tid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_clone(int (*fn)(void *),void *stack,int flags,void *arg,pid_t *parent_tid,void *tls,pid_t *child_tid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLONE(fn,stack,flags,arg,parent_tid,tls,child_tid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/*

static ADL_RESULT adl_sys_execve(const char *pathname, char *const argv[],char *const envp[])

            a wrapper for execve system call on unix systems

            INPUT  :(const char *pathname, char *const argv[],char *const envp[])
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_execve(const char *pathname, char *const argv[],char *const envp[])
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EXECVE(pathname,argv,envp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_execveat(int dirfd,const char *pathname, char *const argv[],char *const envp[],int flags)

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

static ADL_RESULT adl_sys_execveat(int dirfd,const char *pathname, char *const argv[],char *const envp[],int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EXECVEAT(dirfd,pathname,argv,envp,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/*

void adl_sys_exit(int status)

            a wrapper for exit system call on unix systems

            INPUT  :(int status)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


void adl_sys_exit(int status)
{
    ADL_EXIT(status);
}




/*

void adl_sys_exit_group(int status)

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

void adl_sys_exit_group(int status)
{
    ADL_EXIT_GROUP(status);
}

___adl_end_syscall___

___adl_end_linux___





/*

static ADL_RESULT adl_sys_fork()

            a wrapper for fork system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_fork()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FORK();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_vfork()

            a wrapper for vfork system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_vfork()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_VFORK();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getcpu(unsigned int *cpu,unsigned int *node)

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

static ADL_RESULT adl_sys_getcpu(unsigned int *cpu,unsigned int *node)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETCPU(cpu,node);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

static ADL_RESULT adl_sys_getegid()

            a wrapper for getegid system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getegid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETEGID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_geteuid()

            a wrapper for geteuid system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_geteuid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETEUID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getgid()

            a wrapper for getgid system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getgid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETGID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getgroups(int size,gid_t list[])

            a wrapper for getgrfoups system call on unix systems

            INPUT  :(int size,gid_t list[]
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getgroups(int size,gid_t list[])
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETGROUPS(size,list);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getpgid(pid_t pid)

            a wrapper for getpgid system call on unix systems

            INPUT  :(pid_t pid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getpgid(pid_t pid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPGID(pid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getpgrp()

            a wrapper for getpgrp system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getpgrp()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPGRP();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getpid()

            a wrapper for getpid system call on unix systems

            INPUT  :(
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getpid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getppid()

            a wrapper for getppid system call on unix systems

            INPUT  :(
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getppid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPPID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getpriority(int which,id_t who)

            a wrapper for getpriority system call on unix systems

            INPUT  :(int which,id_t who
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getpriority(int which,id_t who)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPRIORITY(which,who);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getresgid(gid_t *rgid,gid_t *egid,gid_t *sgid)

            a wrapper for getresgid system call on unix systems

            INPUT  :(gid_t *rgid,gid_t *egid,gid_t *sgid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getresgid(gid_t *rgid,gid_t *egid,gid_t *sgid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETRESGID(rgid,egid,sgid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getresuid(uid_t *ruid,uid_t *euid,uid_t *suid)

            a wrapper for getresuid system call on unix systems

            INPUT  :(uid_t *ruid,uid_t *euid,uid_t *suid
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getresuid(uid_t *ruid,uid_t *euid,uid_t *suid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETRESUID(ruid,euid,suid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_getrlimit(int resource,struct rlimit *rlim)

            a wrapper for getrlimit system call on unix systems

            INPUT  :(int resource,struct rlimit *rlim)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getrlimit(int resource,struct rlimit *rlim)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETRLIMIT(resource,rlim);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_getrusage(int who,struct rusage *usage)

            a wrapper for getrusage system call on unix systems

            INPUT  :(int who,struct rusage *usage
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getrusage(int who,struct rusage *usage)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETRUSAGE(who,usage);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_getsid(pid_t pid)

            a wrapper for getsid system call on unix systems

            INPUT  :(pid_t pid
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getsid(pid_t pid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETSID(pid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_get_thread_area(struct user_desc *u_info)

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

static ADL_RESULT adl_sys_get_thread_area(struct user_desc *u_info)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GET_THREAD_AREA(u_info);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___




/*

static ADL_RESULT adl_sys_gettid()

            a wrapper for gettid system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_gettid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETTID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/*

static ADL_RESULT adl_sys_getuid()

            a wrapper for getuid system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getuid()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETUID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_kill(pid_t pid,int sig)

            a wrapper for kill system call on unix systems

            INPUT  :(pid_t pid,int sig)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_kill(pid_t pid,int sig)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_KILL(pid,sig);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_pidfd_getfd(int pidfd,int targetfd,unsigned int flags)

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

static ADL_RESULT adl_sys_pidfd_getfd(int pidfd,int targetfd,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIDFD_GETFD(pidfd,targetfd,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_pidfd_open(pid_t pid,unsigned int flags)

            a wrapper for pidfd_open system call on unix systems

            INPUT  :(pid_t pid,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pidfd_open(pid_t pid,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIDFD_OPEN(pid,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___




/*

static ADL_RESULT adl_sys_prctl(int op,unsigned long arg2,unsigned long arg3,unsigned long arg4, unsigned long arg5)

            a wrapper for prctl system call on unix systems

            INPUT  :(int op,unsigned long arg2,unsigned long arg3,unsigned long arg4, unsigned long arg5)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_prctl(int op,unsigned long arg2,unsigned long arg3,unsigned long arg4, unsigned long arg5)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PRCTL(op,arg2,arg3,arg4,arg5);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_prlimit(pid_t pid, int resource,const struct rlimit *new_limit,struct rlimit *old_limit)

            a wrapper for prlimit system call on unix systems

            INPUT  :(pid_t pid, int resource,const struct rlimit *new_limit,struct rlimit *old_limit)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_prlimit(pid_t pid, int resource,const struct rlimit *new_limit,struct rlimit *old_limit)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PRLIMIT(pid,resource,new_limit,old_limit);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_process_madvise(int pidfd,const struct iovec *iovec,size_t n,int advice,unsigned int flags)

            a wrapper for process system call on unix systems

            INPUT  :(int pidfd,const struct iovec *iovec,size_t n,int advice,unsigned int flags)

            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_process_madvise(int pidfd,const struct iovec *iovec,size_t n,int advice,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PROCESS_MADVISE(pidfd,iovec,n,advice,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_process_vm_readv(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)

            a wrapper for process_vm_readv system call on unix systems

            INPUT  :(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)

            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_process_vm_readv(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PROCESS_VM_READV(pid,local_iov,liovcnt,remote_iov,riovcnt,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_process_vm_writev(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)

            a wrapper for process_vm_writev system call on unix systems

            INPUT  :(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_process_vm_writev(pid_t pid,const struct iovec *local_iov,unsigned long liovcnt,const struct iovec *remote_iov,unsigned long riovcnt,unsigned long flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PROCESS_VM_WRITEV(pid,local_iov,liovcnt,remote_iov,riovcnt,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sched_getaffinity(pid_t pid,size_t cpusetsize,cpu_set_t *mask)

            a wrapper for sched_getaffinity system call on unix systems

            INPUT  :(pid_t pid,size_t cpusetsize,cpu_set_t *mask)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sched_getaffinity(pid_t pid,size_t cpusetsize,cpu_set_t *mask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GETAFFINITY(pid,cpusetsize,mask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sched_getattr(pid_t pid,struct sched_attr *attr,unsigned int size, unsigned int flags)

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

static ADL_RESULT adl_sys_sched_getattr(pid_t pid,struct sched_attr *attr,unsigned int size, unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GETATTR(pid,attr,size,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___

___adl_end_linux___





/*

static ADL_RESULT adl_sys_sched_getparam(pid_t pid,struct sched_param *param)

            a wrapper for sched_getparam system call on unix systems

            INPUT  :(pid_t pid,struct sched_param *param)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sched_getparam(pid_t pid,struct sched_param *param)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GETPARAM(pid,param);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sched_get_priority_max(int policy)

            a wrapper for sched_get_priority_max system call on unix systems

            INPUT  :(int policy)

            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sched_get_priority_max(int policy)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GET_PRIORITY_MAX(policy);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sched_get_priority_min(int policy)

            a wrapper for sched_get_priority_min system call on unix systems

            INPUT  :(int policy)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sched_get_priority_min(int policy)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GET_PRIORITY_MIN(policy);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sched_getscheduler(pid_t pid)

            a wrapper for sched_getscheduler system call on unix systems

            INPUT  :(pid_t pid
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sched_getscheduler(pid_t pid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_GETSCHEDULER(pid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sched_rr_get_interval(pid_t pid, struct timespec *tp)

            a wrapper for sched_rr_get_interval system call on unix systems

            INPUT  :(pid_t pid, struct timespec *tp)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sched_rr_get_interval(pid_t pid, struct timespec *tp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_RR_GET_INTERVAL(pid,tp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sched_setaffinity(pid_t pid,size_t cpusetsize,const cpu_set_t *mask)

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

static ADL_RESULT adl_sys_sched_setaffinity(pid_t pid,size_t cpusetsize,const cpu_set_t *mask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_SETAFFINITY(pid,cpusetsize,mask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sched_setattr(pid_t pid, struct sched_attr *attr,unsigned int flags)

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

static ADL_RESULT adl_sys_sched_setattr(pid_t pid, struct sched_attr *attr,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_SETATTR(pid,attr,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___

___adl_end_linux___




/*

static ADL_RESULT adl_sys_sched_setparam(pid_t pid,const struct sched_param *param)

            a wrapper for sched_setparam system call on unix systems

            INPUT  :(pid_t pid,const struct sched_param *param)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sched_setparam(pid_t pid,const struct sched_param *param)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_SETPARAM(pid,param);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sched_setscheduler(pid_t pid, int policy,const struct sched_param *param)

            a wrapper for sched_setscheduler system call on unix systems

            INPUT  :(pid_t pid, int policy,const struct sched_param *param)

            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sched_setscheduler(pid_t pid, int policy,const struct sched_param *param)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_SETSCHEDULER(pid,policy,param);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sched_yield()

            a wrapper for sched_yield system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sched_yield()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SCHED_YIELD();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setgid(gid_t gid)

            a wrapper for setgid system call on unix systems

            INPUT  :(gid_t gid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setgid(gid_t gid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETGID(gid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setgroups(size_t size,const gid_t *list)

            a wrapper for setgroups system call on unix systems

            INPUT  :(size_t size,const gid_t *list)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setgroups(size_t size,const gid_t *list)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETGROUPS(size,list);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setns(int fd,int nstype)

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

static ADL_RESULT adl_sys_setns(int fd,int nstype)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETNS(fd,nstype);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

static ADL_RESULT adl_sys_setpgid(pid_t pid, pid_t pgid)

            a wrapper for  setpgid system call on unix systems

            INPUT  :(pid_t pid, pid_t pgid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setpgid(pid_t pid, pid_t pgid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETPGID(pid,pgid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setpriority(int which, id_t who, int prio)

            a wrapper for setpriority system call on unix systems

            INPUT  :(int which, id_t who, int prio)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setpriority(int which, id_t who, int prio)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETPRIORITY(which,who,prio);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setregid(gid_t rgid, gid_t egid)

            a wrapper for setregid system call on unix systems

            INPUT  :(gid_t rgid, gid_t egid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setregid(gid_t rgid, gid_t egid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETREGID(rgid,egid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setresgid(gid_t rgid,gid_t egid,gid_t sgid)

            a wrapper for setresgid system call on unix systems

            INPUT  :(gid_t rgid,gid_t egid,gid_t sgid
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setresgid(gid_t rgid,gid_t egid,gid_t sgid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETRESGID(rgid,egid,sgid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setresuid(uid_t ruid,uid_t euid,uid_t suid)

            a wrapper for setresuid system call on unix systems

            INPUT  :(uid_t ruid,uid_t euid,uid_t suid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setresuid(uid_t ruid,uid_t euid,uid_t suid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETRESUID(ruid,euid,suid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setreuid(uid_t ruid,uid_t euid)

            a wrapper for setreuid system call on unix systems

            INPUT  :(uid_t ruid,uid_t euid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setreuid(uid_t ruid,uid_t euid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETREUID(ruid,euid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setrlimit(int resource,const struct rlimit *rlim)

            a wrapper for  setrlimit system call on unix systems

            INPUT  :(int resource,const struct rlimit *rlim)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setrlimit(int resource,const struct rlimit *rlim)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETRLIMIT(resource,rlim);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_setsid(void)

            a wrapper for setsid system call on unix systems

            INPUT  :(void)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_setsid(void)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETSID();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_set_thread_area(struct user_desc *u_info)

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

static ADL_RESULT adl_sys_set_thread_area(struct user_desc *u_info)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SET_THREAD_AREA(u_info);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_set_tid_address(int *tidptr)

            a wrapper for set_tid_address system call on unix systems

            INPUT  :(int *tidptr)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_set_tid_address(int *tidptr)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SET_TID_ADDRESS(tidptr);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

static ADL_RESULT adl_sys_setuid(uid_t uid)

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

static ADL_RESULT adl_sys_setuid(uid_t uid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETUID(uid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_tgkill(pid_t tgid,pid_t tid,int sig)

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

static ADL_RESULT adl_sys_tgkill(pid_t tgid,pid_t tid,int sig)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_TGKILL(tgid,tid,sig);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_unshare(int flags)

            a wrapper for unshare system call on unix systems

            INPUT  :(int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_unshare(int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_UNSHARE(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/*

static ADL_RESULT adl_sys_wait4(pid_t pid,int *wstatus,int options,struct rusage *rusage)

            a wrapper for wait4 system call on unix systems

            INPUT  :(pid_t pid,int *wstatus,int options,struct rusage *rusage)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_wait4(pid_t pid,int *wstatus,int options,struct rusage *rusage)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WAIT4(pid,wstatus,options,rusage);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_wait3(int *wstatus,int options,struct rusage *rusage)

            a wrapper for wait3 system call on unix systems

            INPUT  :(int *wstatus,int options,struct rusage *rusage)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_wait3(int *wstatus,int options,struct rusage *rusage)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_WAIT3(wstatus,options,rusage);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_bpf(int cmd,union bpf_attr *attr,unsigned int size)

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

static ADL_RESULT adl_sys_bpf(int cmd,union bpf_attr *attr,unsigned int size)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_BPF(cmd,attr,size);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_modify_ldt(int func,void *ptr,unsigned long bytecount)

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

static ADL_RESULT adl_sys_modify_ldt(int func,void *ptr,unsigned long bytecount)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MODIFY_LDT(func,ptr,bytecount);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_seccomp(unsigned int operation,unsigned int flags,void *args)

            a wrapper for seccomp system call on unix systems

            INPUT  :(unsigned int operation,unsigned int flags,void *args)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_seccomp(unsigned int operation,unsigned int flags,void *args)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SECCOMP(operation,flags,args);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_kcmp(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)

            a wrapper for kcmp system call on unix systems

            INPUT  :(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_kcmp(pid_t pid1,pid_t pid2,int type,unsigned long idx1,unsigned long idx2)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_KCMP(pid1,pid2,type,idx1,idx2);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___

___adl_end_linux___










/*

                SIGNALS

*/



/*

static ADL_RESULT adl_sys_sigaction(int signum,const struct sigaction *newact,struct sigaction *oldact)

            a wrapper for sigaction system call on unix systems

            INPUT  :(int signum,const struct sigaction *newact,struct sigaction *oldact)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sigaction(int signum,const struct sigaction *newact,struct sigaction *oldact)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGACTION(signum,newact,oldact);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sigpending(sigset_t *set)

            a wrapper for sigpending system call on unix systems

            INPUT  :(sigset_t *set)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sigpending(sigset_t *set)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGPENDING(set);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_sigprocmask(int how,const sigset_t *newset,sigset_t *oldset)

            a wrapper for sigprocmask system call on unix systems

            INPUT  :(int how,const sigset_t *newset,sigset_t *oldset)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sigprocmask(int how,const sigset_t *newset,sigset_t *oldset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGPROCMASK(how,newset,oldset);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sigsuspend(const sigset_t *mask)

            a wrapper for sigsuspend system call on unix systems

            INPUT  :(const sigset_t *mask)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sigsuspend(const sigset_t *mask)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGSUSPEND(mask);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sigtimedwait(const sigset_t *set,siginfo_t *info,const struct timespec *timeout)

            a wrapper for sigtimedwait system call on unix systems

            INPUT  :(const sigset_t *set,siginfo_t *info,const struct timespec *timeout)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sigtimedwait(const sigset_t *set,siginfo_t *info,const struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGTIMEDWAIT(set,info,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_sigwaitinfo(const sigset_t *set,siginfo_t *info)

            a wrapper for sigwaitinfo system call on unix systems

            INPUT  :(const sigset_t *set,siginfo_t *info)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sigwaitinfo(const sigset_t *set,siginfo_t *info)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGWAITINFO(set,info);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_signal(int signum,void (*handler)(int))

            a wrapper for signal system call on unix systems

            INPUT  :(int signum,void (*handler)(int))
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_signal(int signum,void (*handler)(int))
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_SIGNAL(signum,handler);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_pidfd_send_signal(int pidfd,int sig,siginfo_t *info,unsigned int flags)

            a wrapper for pidfd_send_signal  system call on unix systems

            INPUT  :(int pidfd,int sig,siginfo_t *info,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___
___adl_syscall___

static ADL_RESULT adl_sys_pidfd_send_signal(int pidfd,int sig,siginfo_t *info,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PIDFD_SEND_SIGNAL(pidfd,sig,info,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___





/*

static ADL_RESULT adl_sys_eventfd(unsigned int initval,int flags)

            a wrapper for eventfd system call on unix systems

            INPUT  :(unsigned int initval,int flags
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_eventfd(unsigned int initval,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_EVENTFD(initval,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_signalfd(int fd,const sigset_t *mask,int flags)

            a wrapper for signalfd system call on unix systems

            INPUT  :(int fd,const sigset_t *mask,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_signalfd(int fd,const sigset_t *mask,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGNALFD(fd,mask,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

static ADL_RESULT adl_sys_sigaltstack(const stack_t *newstack,stack_t *oldstack)

            a wrapper for sigaltstack system call on unix systems

            INPUT  :(const stack_t *newstack,stack_t *oldstack)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sigaltstack(const stack_t *newstack,stack_t *oldstack)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SIGALTSTACK(newstack,oldstack);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}












/*

                OVERALL SYSTEM

*/


/*

static ADL_RESULT adl_sys_reboot(int magic,int magic2,int op,void *arg)

            a wrapper for reboot system call on unix systems

            INPUT  :(int magic,int magic2,int op,void *arg)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___
___adl_syscall___


static ADL_RESULT adl_sys_reboot(int magic,int magic2,int op,void *arg)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_REBOOT(magic,magic2,op,arg);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_delete_module(const char *name,unsigned int flags)

            a wrapper for delete_module system call on unix systems

            INPUT  :(const char *name,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_delete_module(const char *name,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_DELETE_MODULE(name,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_finit_module(int fd,const char *param_values,int flags)

            a wrapper for finit_module system call on unix systems

            INPUT  :(int fd,const char *param_values,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_finit_module(int fd,const char *param_values,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FINIT_MODULE(fd,param_values,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_init_module(void *module_image,unsigned long len,const char *param_value)

            a wrapper for init_module system call on unix systems

            INPUT  :(void *module_image,unsigned long len,const char *param_value)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_init_module(void *module_image,unsigned long len,const char *param_value)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INIT_MODULE(module_image,len,param_value);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_kexec_file_load(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags)

            a wrapper for kexec_file_load system call on unix systems

            INPUT  :(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags)

            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_kexec_file_load(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_KEXEC_FILE_LOAD(kernel_fd,initrd_fd,cmdline_len,cmdline,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_kexec_load(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags)

            a wrapper for kexec_load  system call on unix systems

            INPUT  :(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_kexec_load(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_KEXEC_LOAD(entry,nr_segments,segments,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_syslog(int type,char *bufp,int len)

            a wrapper for syslog system call on unix systems

            INPUT  :(int type,char *bufp,int len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_syslog(int type,char *bufp,int len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYSLOG(type,bufp,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___






/*

static ADL_RESULT adl_sys_sysinfo(struct sysinfo *info)

            a wrapper for sysinfo system call on unix systems

            INPUT  :(struct sysinfo *info)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sysinfo(struct sysinfo *info)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYSINFO(info);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_getrandom(void *buf,size_t buflen,unsigned int flags)

            a wrapper for getrandom system call on unix systems

            INPUT  :(void *buf,size_t buflen,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getrandom(void *buf,size_t buflen,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETRANDOM(buf,buflen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

static ADL_RESULT adl_sys_setdomainname(const char *name,size_t len)

            a wrapper for setdomainname system call on unix systems

            INPUT  :(const char *name,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_nostd___


static ADL_RESULT adl_sys_setdomainname(const char *name,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETDOMAINNAME(name,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_getdomainname(char *name,size_t len)

            a wrapper for getdomainname system call on unix systems

            INPUT  :(char *name,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_getdomainname(char *name,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETDOMAINNAME(name,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sethostname(const char *name,size_t len)

            a wrapper for sethostname system call on unix systems

            INPUT  :(const char *name,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sethostname(const char *name,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETHOSTNAME(name,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_nostd___





/*

static ADL_RESULT adl_sys_gethostname(char *name,size_t len)

            a wrapper for gethostname system call on unix systems

            INPUT  :(char *name,size_t len
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_gethostname(char *name,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETHOSTNAME(name,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}












/*

                MEMORY MANAGEMENT

*/




/*

static ADL_RESULT adl_sys_brk(void *addr)

            a wrapper for brk system call on unix systems

            INPUT  :(void *addr)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_nostd___

static ADL_RESULT adl_sys_brk(void *addr)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_BRK(addr);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_sbrk(intptr_t increment)

            a wrapper for sbrk system call on unix systems

            INPUT  :(intptr_t increment)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_sbrk(intptr_t increment)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_SBRK(increment);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_madvise(void *addr,size_t length,int advice)

            a wrapper for madvise system call on unix systems

            INPUT  :(void *addr,size_t length,int advice)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_madvise(void *addr,size_t length,int advice)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MADVISE(addr,length,advice);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_mincore(void *addr,size_t length,unsigned char *vec)

            a wrapper for mincore system call on unix systems

            INPUT  :(void *addr,size_t length,unsigned char *vec)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mincore(void *addr,size_t length,unsigned char *vec)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MINCORE(addr,length,vec);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_nostd___





/*

static ADL_RESULT adl_sys_get_mempolicy(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags)

            a wrapper for get_mempolicy system call on unix systems

            INPUT  :(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

static ADL_RESULT adl_sys_get_mempolicy(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GET_MEMPOLICY(mode,nodemask,maxnode,addr,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_keyctl(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5)

            a wrapper for keyctl system call on unix systems

            INPUT  :(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_syscall___

static ADL_RESULT adl_sys_keyctl(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_KEYCTL(operation,arg2,arg3,arg4,arg5);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_membarrier(int cmd,unsigned int flags,int cpu_id)

            a wrapper for membarrier system call on unix systems

            INPUT  :(int cmd,unsigned int flags,int cpu_id)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_membarrier(int cmd,unsigned int flags,int cpu_id)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MEMBARRIER(cmd,flags,cpu_id);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_memfd_secret(unsigned int flags)

            a wrapper for memfd_secret system call on unix systems

            INPUT  :(unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_memfd_secret(unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MEMFD_SECRET(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_userfaultfd(int flags)

            a wrapper for userfaultfd system call on unix systems

            INPUT  :(int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_userfaultfd(int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_USERFAULTFD(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___





/*

static ADL_RESULT adl_sys_mbind(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags)

            a wrapper for mbind system call on unix systems

            INPUT  :(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mbind(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MBIND(addr,len,mode,nodemask,maxnode,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_memfd_create(const char *name,unsigned int flags)

            a wrapper for memfd_create system call on unix systems

            INPUT  :(const char *name,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_memfd_create(const char *name,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MEMFD_CREATE(name,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_migrate_pages(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes)

            a wrapper for migrate_pages system call on unix systems

            INPUT  :(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_migrate_pages(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MIGRATE_PAGES(pid,maxnode,old_nodes,new_nodes);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

static ADL_RESULT adl_sys_mlock2(const void *addr,size_t len,unsigned int flags)

            a wrapper for mlock2 system call on unix systems

            INPUT  :(const void *addr,size_t len,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mlock2(const void *addr,size_t len,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MLOCK2(addr,len,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_mremap(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address)

            a wrapper for mremap system call on unix systems

            INPUT  :(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mremap(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_MREMAP(old_address,old_size,new_size,flags,new_address);
    if(ADL_CHECK_EQUAL(rdr_retptr,MAP_FAILED))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_move_pages(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags)

            a wrapper for move_pages system call on unix systems

            INPUT  :(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_move_pages(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MOVE_PAGES(pid,count,pages,nodes,status,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_request_key(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring)

            a wrapper for request_key system call on unix systems

            INPUT  :(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_request_key(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_REQUEST_KEY(type,description,callout_info,dest_keyring);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_pkey_alloc(unsigned int flags,unsigned int access_rights)

            a wrapper for pkey_alloc system call on unix systems

            INPUT  :(unsigned int flags,unsigned int access_rights)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pkey_alloc(unsigned int flags,unsigned int access_rights)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PKEY_ALLOC(flags,access_rights);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_pkey_free(int pkey)

            a wrapper for pkey_free system call on unix systems

            INPUT  :(int pkey)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pkey_free(int pkey)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PKEY_FREE(pkey);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_pkey_mprotect(void *addr,size_t len,int prot,int pkey)

            a wrapper for pkey_mprotect system call on unix systems

            INPUT  :(void *addr,size_t len,int prot,int pkey)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_pkey_mprotect(void *addr,size_t len,int prot,int pkey)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PKEY_MPROTECT(addr,len,prot,pkey);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_set_mempolicy(int mode,const unsigned long *nodemask,unsigned long maxnode)

            a wrapper for set_mempolicy system call on unix systems

            INPUT  :(int mode,const unsigned long *nodemask,unsigned long maxnode)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_set_mempolicy(int mode,const unsigned long *nodemask,unsigned long maxnode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SET_MEMPOLICY(mode,nodemask,maxnode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_sys_swapoff(const char *path)

            a wrapper for swapoff system call on unix systems

            INPUT  :(const char *path)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_swapoff(const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SWAPOFF(path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_swapon(const char *path,int swapflags)

            a wrapper for swapon system call on unix systems

            INPUT  :(const char *path,int swapflags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_swapon(const char *path,int swapflags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SWAPON(path,swapflags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_vmsplice(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags)

            a wrapper for vmsplice system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



static ADL_RESULT adl_sys_vmsplice(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_VMSPLICE(fd,iov,nr_segs,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/*

static ADL_RESULT adl_sys_mlock(void *addr,size_t len)

            a wrapper for mlock system call on unix systems

            INPUT  :(void *addr,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



static ADL_RESULT adl_sys_mlock(void *addr,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MLOCK(addr,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_mlockall(int flags)

            a wrapper for mlockall system call on unix systems

            INPUT  :(int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



static ADL_RESULT adl_sys_mlockall(int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MLOCKALL(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_sys_mmap(void *addr,size_t len,int prot,int flags,int fd,off_t offset)

            a wrapper for mmap system call on unix systems

            INPUT  :(void *addr,size_t len,int prot,int flags,int fd,off_t offset)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_mmap(void *addr,size_t len,int prot,int flags,int fd,off_t offset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_MMAP(addr,len,prot,flags,fd,offset);
    if(ADL_CHECK_EQUAL(rdr_retptr,MAP_FAILED))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

static ADL_RESULT adl_sys_mprotect(void *addr,size_t len,int prot)

            a wrapper for mprotect  system call on unix systems

            INPUT  :(void *addr,size_t len,int prot)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



static ADL_RESULT adl_sys_mprotect(void *addr,size_t len,int prot)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MPROTECT(addr,len,prot);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

static ADL_RESULT adl_sys_msync(void *addr,size_t len,int flags)

            a wrapper for msync system call on unix systems

            INPUT  :(void *addr,size_t len,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



static ADL_RESULT adl_sys_msync(void *addr,size_t len,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MSYNC(addr,len,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

static ADL_RESULT adl_sys_munlock(const void *addr,size_t len)

            a wrapper for munlock system call on unix systems

            INPUT  :(const void *addr,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_munlock(const void *addr,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MUNLOCK(addr,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

static ADL_RESULT adl_sys_munlockall()

            a wrapper for munlockall system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



static ADL_RESULT adl_sys_munlockall()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MUNLOCKALL();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

static ADL_RESULT adl_sys_munmap(void *addr,size_t len)

            a wrapper for munmap system call on unix systems

            INPUT  :(void *addr,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_sys_munmap(void *addr,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MUNMAP(addr,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}











/*
            USER ACCOUNT MANAGEMENT
*/




/*

static ADL_RESULT adl_lib_getpwnam(const char *name)

            a wrapper for getpwnam library call on unix systems

            INPUT  : (const char *name)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_getpwnam(const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETPWNAM(name);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_lib_getpwuid(uid_t uid)

            a wrapper for getpwuid library call on unix systems

            INPUT  : (uid_t uid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_getpwuid(uid_t uid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETPWUID(uid);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_lib_getpwent()

            a wrapper for getpwent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_getpwent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETPWENT();
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_lib_setpwent()

            a wrapper for setpwent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_setpwent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_SETPWENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_lib_endpwent()

            a wrapper for endpwent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_endpwent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_ENDPWENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_lib_getgrnam(const char *name)

            a wrapper for getgrnam library call on unix systems

            INPUT  : (const char *name)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_getgrnam(const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETGRNAM(name);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_lib_getgrgid(gid_t gid)

            a wrapper for getgrgid library call on unix systems

            INPUT  : (gid_t gid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_getgrgid(gid_t gid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETGRGID(gid);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_lib_getgrent()

            a wrapper for getgrent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_getgrent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETGRENT();
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_lib_setgrent()

            a wrapper for setgrent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_setgrent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_SETGRENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_lib_endgrent()

            a wrapper for endgrent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_endgrent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_ENDGRENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_lib_getspnam(const char *name)

            a wrapper for getpwuid library call on unix systems

            INPUT  : (const char *name)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_getspnam(const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETSPNAM(name);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_lib_getspent()

            a wrapper for getspent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_getspent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETSPENT();
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

static ADL_RESULT adl_lib_setspent()

            a wrapper for setspent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_setspent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_SETSPENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

static ADL_RESULT adl_lib_endspent()

            a wrapper for endspent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_endspent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_ENDSPENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

static ADL_RESULT adl_lib_crypt(const char *key,const char *salt)

            a wrapper for crypt library call on unix systems

            INPUT  : (const char *key,const char *salt)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


static ADL_RESULT adl_lib_crypt(const char *key,const char *salt)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_CRYPT(key,salt);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}








void ADL_UNIX_init(ADL_UNIX *adl_unix)
{
    if(ADL_CHECK_NULL(adl_unix))
    {
        ADL_RETURN_DEFER(null_adl_unix);
    }


    adl_unix->socket = adl_sys_socket;
    adl_unix->socketpair = adl_sys_socketpair;
    adl_unix->bind = adl_sys_bind;
    adl_unix->connect = adl_sys_connect;
    adl_unix->listen = adl_sys_listen;
    adl_unix->accept = adl_sys_accept;
    adl_unix->accept4 = adl_sys_accept4;
    adl_unix->recv = adl_sys_recv;
    adl_unix->recvfrom = adl_sys_recvfrom;
    adl_unix->recvmsg = adl_sys_recvmsg;
    adl_unix->recvmmsg = adl_sys_recvmmsg;
    adl_unix->send = adl_sys_send;
    adl_unix->sendto = adl_sys_sendto;
    adl_unix->sendmsg = adl_sys_sendmsg;
    adl_unix->sendmmsg = adl_sys_sendmmsg;
    adl_unix->shutdown = adl_sys_shutdown;
    adl_unix->close = adl_sys_close;
    adl_unix->getsockopt = adl_sys_getsockopt;
    adl_unix->setsockopt = adl_sys_setsockopt;
    adl_unix->getsockname = adl_sys_getsockname;
    adl_unix->getpeername = adl_sys_getpeername;
    adl_unix->getaddrinfo = adl_lib_getaddrinfo;
    adl_unix->freeaddrinfo = adl_lib_freeaddrinfo;
    adl_unix->getnameinfo = adl_lib_getnameinfo;
    adl_unix->htons = adl_lib_htons;
    adl_unix->htonl = adl_lib_htonl;
    adl_unix->ntohs = adl_lib_ntohs;
    adl_unix->ntohl = adl_lib_ntohl;
    adl_unix->open = adl_sys_open;
    adl_unix->creat = adl_sys_creat;
    adl_unix->openat = adl_sys_openat;
    adl_unix->openat2 = adl_sys_openat2;
    adl_unix->read = adl_sys_read;
    adl_unix->write = adl_sys_write;
    adl_unix->sendfile = adl_sys_sendfile;
    adl_unix->close = adl_sys_close;
    adl_unix->stat = adl_sys_stat;
    adl_unix->fstat = adl_sys_fstat;
    adl_unix->lstat = adl_sys_lstat;
    adl_unix->fstatat = adl_sys_fstatat;
    adl_unix->poll = adl_sys_poll;
    adl_unix->ppoll = adl_sys_ppoll;
    adl_unix->lseek = adl_sys_lseek;
    adl_unix->ioctl = adl_sys_ioctl;
    adl_unix->pread = adl_sys_pread;
    adl_unix->pwrite = adl_sys_pwrite;
    adl_unix->readv = adl_sys_readv;
    adl_unix->writev = adl_sys_writev;
    adl_unix->preadv = adl_sys_preadv;
    adl_unix->pwritev = adl_sys_pwritev;
    adl_unix->preadv2 = adl_sys_preadv2;
    adl_unix->pwritev2 = adl_sys_pwritev2;
    adl_unix->pipe = adl_sys_pipe;
    adl_unix->pipe2 = adl_sys_pipe2;
    adl_unix->select = adl_sys_select;
    adl_unix->pselect = adl_sys_pselect;
    adl_unix->dup = adl_sys_dup;
    adl_unix->dup2 = adl_sys_dup2;
    adl_unix->dup3 = adl_sys_dup3;
    adl_unix->flock = adl_sys_flock;
    adl_unix->fsync = adl_sys_fsync;
    adl_unix->fdatasync = adl_sys_fdatasync;
    adl_unix->truncate = adl_sys_truncate;
    adl_unix->ftruncate = adl_sys_ftruncate;
    adl_unix->getcwd = adl_sys_getcwd;
    adl_unix->chdir = adl_sys_chdir;
    adl_unix->fchdir = adl_sys_fchdir;
    adl_unix->rename = adl_sys_rename;
    adl_unix->renameat = adl_sys_renameat;
    adl_unix->renameat2 = adl_sys_renameat2;
    adl_unix->mkdir = adl_sys_mkdir;
    adl_unix->mkdirat = adl_sys_mkdirat;
    adl_unix->rmdir = adl_sys_rmdir;
    adl_unix->link = adl_sys_link;
    adl_unix->linkat = adl_sys_linkat;
    adl_unix->unlink = adl_sys_unlink;
    adl_unix->unlinkat = adl_sys_unlinkat;
    adl_unix->symlink = adl_sys_symlink;
    adl_unix->symlinkat = adl_sys_symlinkat;
    adl_unix->readlink = adl_sys_readlink;
    adl_unix->readlinkat = adl_sys_readlinkat;
    adl_unix->chmod = adl_sys_chmod;
    adl_unix->fchmod = adl_sys_fchmod;
    adl_unix->fchmodat = adl_sys_fchmodat;
    adl_unix->chown = adl_sys_chown;
    adl_unix->lchown = adl_sys_lchown;
    adl_unix->fchown = adl_sys_fchown;
    adl_unix->fchownat = adl_sys_fchownat;
    adl_unix->umask = adl_sys_umask;
    adl_unix->mknod = adl_sys_mknod;
    adl_unix->mknodat = adl_sys_mknodat;
    adl_unix->statfs = adl_sys_statfs;
    adl_unix->fstatfs = adl_sys_fstatfs;
    adl_unix->vhangup = adl_sys_vhangup;
    adl_unix->pivot_root = adl_sys_pivot_root;
    adl_unix->chroot = adl_sys_chroot;
    adl_unix->sync = adl_sys_sync;
    adl_unix->syncfs = adl_sys_syncfs;
    adl_unix->mount = adl_sys_mount;
    adl_unix->umount = adl_sys_umount;
    adl_unix->umount2 = adl_sys_umount2;
    adl_unix->ioperm = adl_sys_ioperm;
    adl_unix->readahead = adl_sys_readahead;
    adl_unix->setxattr = adl_sys_setxattr;
    adl_unix->lsetxattr = adl_sys_lsetxattr;
    adl_unix->fsetxattr = adl_sys_fsetxattr;
    adl_unix->getxattr = adl_sys_getxattr;
    adl_unix->lgetxattr = adl_sys_lgetxattr;
    adl_unix->fgetxattr = adl_sys_fgetxattr;
    adl_unix->listxattr = adl_sys_listxattr;
    adl_unix->llistxattr = adl_sys_llistxattr;
    adl_unix->flistxattr = adl_sys_flistxattr;
    adl_unix->removexattr = adl_sys_removexattr;
    adl_unix->lremovexattr = adl_sys_lremovexattr;
    adl_unix->fremovexattr = adl_sys_fremovexattr;
    adl_unix->ioprio_set = adl_sys_ioprio_set;
    adl_unix->ioprio_get = adl_sys_ioprio_get;
    adl_unix->inotify_init = adl_sys_inotify_init;
    adl_unix->inotify_init1 = adl_sys_inotify_init1;
    adl_unix->inotify_add_watch = adl_sys_inotify_add_watch;
    adl_unix->inotify_rm_watch = adl_sys_inotify_rm_watch;
    adl_unix->access = adl_sys_access;
    adl_unix->faccessat = adl_sys_faccessat;
    adl_unix->faccessat2 = adl_sys_faccessat2;
    adl_unix->quotactl = adl_sys_quotactl;
    adl_unix->io_setup = adl_sys_io_setup;
    adl_unix->io_destroy = adl_sys_io_destroy;
    adl_unix->io_getevents = adl_sys_io_getevents;
    adl_unix->io_submit = adl_sys_io_submit;
    adl_unix->io_cancel = adl_sys_io_cancel;
    adl_unix->lookup_dcookie = adl_sys_lookup_dcookie;
    adl_unix->epoll_create = adl_sys_epoll_create;
    adl_unix->epoll_create1 = adl_sys_epoll_create1;
    adl_unix->epoll_wait = adl_sys_epoll_wait;
    adl_unix->epoll_pwait = adl_sys_epoll_pwait;
    adl_unix->epoll_pwait2 = adl_sys_epoll_pwait2;
    adl_unix->epoll_ctl = adl_sys_epoll_ctl;
    adl_unix->splice = adl_sys_splice;
    adl_unix->tee = adl_sys_tee;
    adl_unix->posix_fadvise64 = adl_sys_posix_fadvise64;
    adl_unix->utime = adl_sys_utime;
    adl_unix->utimes = adl_sys_utimes;
    adl_unix->utimensat = adl_sys_utimensat;
    adl_unix->futimens = adl_sys_futimens;
    adl_unix->sync_file_range = adl_sys_sync_file_range;
    adl_unix->fallocate = adl_sys_fallocate;
    adl_unix->fanotify_init = adl_sys_fanotify_init;
    adl_unix->fanotify_mark = adl_sys_fanotify_mark;
    adl_unix->name_to_handle_at = adl_sys_name_to_handle_at;
    adl_unix->open_by_handle_at = adl_sys_open_by_handle_at;
    adl_unix->copy_file_range = adl_sys_copy_file_range;
    adl_unix->statx = adl_sys_statx;
    adl_unix->close_range = adl_sys_close_range;
    adl_unix->mount_setattr = adl_sys_mount_setattr;
    adl_unix->mkfifo = adl_lib_mkfifo;
    adl_unix->mkfifoat = adl_lib_mkfifoat;
    adl_unix->opendir = adl_lib_opendir;
    adl_unix->fdopendir = adl_lib_fdopendir;
    adl_unix->readdir = adl_lib_readdir;
    adl_unix->rewinddir = adl_lib_rewinddir;
    adl_unix->closedir = adl_lib_closedir;
    adl_unix->dirfd = adl_lib_dirfd;
    adl_unix->pause = adl_sys_pause;
    adl_unix->nanosleep = adl_sys_nanosleep;
    adl_unix->getitimer = adl_sys_getitimer;
    adl_unix->setitimer = adl_sys_setitimer;
    adl_unix->alarm = adl_sys_alarm;
    adl_unix->gettimeofday = adl_sys_gettimeofday;
    adl_unix->settimeofday = adl_sys_settimeofday;
    adl_unix->timer_create = adl_sys_timer_create;
    adl_unix->timer_settime = adl_sys_timer_settime;
    adl_unix->timer_gettime = adl_sys_timer_gettime;
    adl_unix->timer_getoverrun = adl_sys_timer_getoverrun;
    adl_unix->timer_delete = adl_sys_timer_delete;
    adl_unix->clock_settime = adl_sys_clock_settime;
    adl_unix->clock_gettime = adl_sys_clock_gettime;
    adl_unix->clock_getres = adl_sys_clock_getres;
    adl_unix->clock_nanosleep = adl_sys_clock_nanosleep;
    adl_unix->clock_adjtime = adl_sys_clock_adjtime;
    adl_unix->adjtimex = adl_sys_adjtimex;
    adl_unix->time = adl_sys_time;
    adl_unix->timerfd_settime = adl_sys_timerfd_settime;
    adl_unix->timerfd_gettime = adl_sys_timerfd_gettime;
    adl_unix->timerfd_create = adl_sys_timerfd_create;
    adl_unix->shmget = adl_sys_shmget;
    adl_unix->shmat = adl_sys_shmat;
    adl_unix->shmctl  = adl_sys_shmctl;
    adl_unix->shmdt = adl_sys_shmdt;
    adl_unix->msgget = adl_sys_msgget;
    adl_unix->msgsnd = adl_sys_msgsnd;
    adl_unix->msgrcv = adl_sys_msgrcv;
    adl_unix->msgctl = adl_sys_msgctl;
    adl_unix->mq_open_v1 = adl_sys_mq_open_v1;
    adl_unix->mq_open_v2 = adl_sys_mq_open_v2;
    adl_unix->mq_unlink = adl_sys_mq_unlink;
    adl_unix->mq_timedsend = adl_sys_mq_timedsend;
    adl_unix->mq_timedreceive = adl_sys_mq_timedreceive;
    adl_unix->mq_notify = adl_sys_mq_notify;
    adl_unix->mq_getsetattr = adl_sys_mq_getsetattr;
    adl_unix->semget = adl_sys_semget;
    adl_unix->semop = adl_sys_semop;
    adl_unix->semtimedop = adl_sys_semtimedop;
    adl_unix->semctl = adl_sys_semctl;
    adl_unix->futex = adl_sys_futex;
    adl_unix->set_robust_list = adl_sys_set_robust_list;
    adl_unix->get_robust_list = adl_sys_get_robust_list;
    adl_unix->capget = adl_sys_capget;
    adl_unix->capset = adl_sys_capset;
    adl_unix->clone3 = adl_sys_clone3;
    adl_unix->clone = adl_sys_clone;
    adl_unix->execve = adl_sys_execve;
    adl_unix->execveat = adl_sys_execveat;
    adl_unix->exit = adl_sys_exit;
    adl_unix->exit_group = adl_sys_exit_group;
    adl_unix->fork = adl_sys_fork;
    adl_unix->vfork = adl_sys_vfork;
    adl_unix->getcpu = adl_sys_getcpu;
    adl_unix->getegid = adl_sys_getegid;
    adl_unix->geteuid = adl_sys_geteuid;
    adl_unix->getgid = adl_sys_getgid;
    adl_unix->getgroups = adl_sys_getgroups;
    adl_unix->getpgid = adl_sys_getpgid;
    adl_unix->getpgrp = adl_sys_getpgrp;
    adl_unix->getpid = adl_sys_getpid;
    adl_unix->getppid = adl_sys_getppid;
    adl_unix->getpriority = adl_sys_getpriority;
    adl_unix->getresgid = adl_sys_getresgid;
    adl_unix->getresuid = adl_sys_getresuid;
    adl_unix->getrlimit = adl_sys_getrlimit;
    adl_unix->getrusage = adl_sys_getrusage;
    adl_unix->getsid = adl_sys_getsid;
    adl_unix->get_thread_area = adl_sys_get_thread_area;
    adl_unix->gettid = adl_sys_gettid;
    adl_unix->getuid = adl_sys_getuid;
    adl_unix->kill = adl_sys_kill;
    adl_unix->pidfd_getfd = adl_sys_pidfd_getfd;
    adl_unix->pidfd_open = adl_sys_pidfd_open;
    adl_unix->prctl = adl_sys_prctl;
    adl_unix->prlimit = adl_sys_prlimit;
    adl_unix->process_madvise = adl_sys_process_madvise;
    adl_unix->process_vm_readv = adl_sys_process_vm_readv;
    adl_unix->process_vm_writev = adl_sys_process_vm_writev;
    adl_unix->sched_getaffinity = adl_sys_sched_getaffinity;
    adl_unix->sched_getattr = adl_sys_sched_getattr;
    adl_unix->sched_getparam = adl_sys_sched_getparam;
    adl_unix->sched_get_priority_max = adl_sys_sched_get_priority_max;
    adl_unix->sched_get_priority_min = adl_sys_sched_get_priority_min;
    adl_unix->sched_getscheduler = adl_sys_sched_getscheduler;
    adl_unix->sched_rr_get_interval = adl_sys_sched_rr_get_interval;
    adl_unix->sched_setaffinity = adl_sys_sched_setaffinity;
    adl_unix->sched_setattr = adl_sys_sched_setattr;
    adl_unix->sched_setparam = adl_sys_sched_setparam;
    adl_unix->sched_setscheduler = adl_sys_sched_setscheduler;
    adl_unix->sched_yield = adl_sys_sched_yield;
    adl_unix->setgid = adl_sys_setgid;
    adl_unix->setgroups = adl_sys_setgroups;
    adl_unix->setns = adl_sys_setns;
    adl_unix->setpgid = adl_sys_setpgid;
    adl_unix->setpriority = adl_sys_setpriority;
    adl_unix->setregid = adl_sys_setregid;
    adl_unix->setresgid = adl_sys_setresgid;
    adl_unix->setresuid = adl_sys_setresuid;
    adl_unix->setreuid = adl_sys_setreuid;
    adl_unix->setrlimit = adl_sys_setrlimit;
    adl_unix->setsid = adl_sys_setsid;
    adl_unix->set_thread_area = adl_sys_set_thread_area;
    adl_unix->set_tid_address = adl_sys_set_tid_address;
    adl_unix->setuid = adl_sys_setuid;
    adl_unix->tgkill = adl_sys_tgkill;
    adl_unix->unshare = adl_sys_unshare;
    adl_unix->wait4 = adl_sys_wait4;
    adl_unix->wait3 = adl_sys_wait3;
    adl_unix->bpf = adl_sys_bpf;
    adl_unix->modify_ldt = adl_sys_modify_ldt;
    adl_unix->seccomp = adl_sys_seccomp;
    adl_unix->kcmp = adl_sys_kcmp;
    adl_unix->sigaction = adl_sys_sigaction;
    adl_unix->sigpending = adl_sys_sigpending;
    adl_unix->sigprocmask = adl_sys_sigprocmask;
    adl_unix->sigsuspend = adl_sys_sigsuspend;
    adl_unix->sigtimedwait = adl_sys_sigtimedwait;
    adl_unix->sigwaitinfo = adl_sys_sigwaitinfo;
    adl_unix->signal = adl_sys_signal;
    adl_unix->pidfd_send_signal = adl_sys_pidfd_send_signal;
    adl_unix->eventfd = adl_sys_eventfd;
    adl_unix->signalfd = adl_sys_signalfd;
    adl_unix->sigaltstack = adl_sys_sigaltstack;
    adl_unix->reboot = adl_sys_reboot;
    adl_unix->delete_module = adl_sys_delete_module;
    adl_unix->finit_module = adl_sys_finit_module;
    adl_unix->init_module = adl_sys_init_module;
    adl_unix->kexec_file_load = adl_sys_kexec_file_load;
    adl_unix->kexec_load = adl_sys_kexec_load;
    adl_unix->syslog = adl_sys_syslog;
    adl_unix->sysinfo = adl_sys_sysinfo;
    adl_unix->getrandom = adl_sys_getrandom;
    adl_unix->setdomainname = adl_sys_setdomainname;
    adl_unix->getdomainname = adl_sys_getdomainname;
    adl_unix->sethostname = adl_sys_sethostname;
    adl_unix->gethostname = adl_sys_gethostname;
    adl_unix->brk = adl_sys_brk;
    adl_unix->sbrk = adl_sys_sbrk;
    adl_unix->madvise = adl_sys_madvise;
    adl_unix->mincore = adl_sys_mincore;
    adl_unix->get_mempolicy = adl_sys_get_mempolicy;
    adl_unix->keyctl = adl_sys_keyctl;
    adl_unix->membarrier = adl_sys_membarrier;
    adl_unix->memfd_secret = adl_sys_memfd_secret;
    adl_unix->userfaultfd = adl_sys_userfaultfd;
    adl_unix->mbind = adl_sys_mbind;
    adl_unix->memfd_create = adl_sys_memfd_create;
    adl_unix->migrate_pages = adl_sys_migrate_pages;
    adl_unix->mlock2 = adl_sys_mlock2;
    adl_unix->mremap = adl_sys_mremap;
    adl_unix->move_pages = adl_sys_move_pages;
    adl_unix->request_key = adl_sys_request_key;
    adl_unix->pkey_alloc = adl_sys_pkey_alloc;
    adl_unix->pkey_free = adl_sys_pkey_free;
    adl_unix->pkey_mprotect = adl_sys_pkey_mprotect;
    adl_unix->set_mempolicy = adl_sys_set_mempolicy;
    adl_unix->swapoff = adl_sys_swapoff;
    adl_unix->swapon = adl_sys_swapon;
    adl_unix->vmsplice = adl_sys_vmsplice;
    adl_unix->mlock = adl_sys_mlock;
    adl_unix->mlockall = adl_sys_mlockall;
    adl_unix->mmap = adl_sys_mmap;
    adl_unix->mprotect = adl_sys_mprotect;
    adl_unix->msync = adl_sys_msync;
    adl_unix->munlock = adl_sys_munlock;
    adl_unix->munlockall = adl_sys_munlockall;
    adl_unix->munmap = adl_sys_munmap;
    adl_unix->getpwnam = adl_lib_getpwnam;
    adl_unix->getpwuid = adl_lib_getpwuid;
    adl_unix->getpwent = adl_lib_getpwent;
    adl_unix->setpwent = adl_lib_setpwent;
    adl_unix->endpwent = adl_lib_endpwent;
    adl_unix->getgrnam = adl_lib_getgrnam;
    adl_unix->getgrgid = adl_lib_getgrgid;
    adl_unix->getgrent = adl_lib_getgrent;
    adl_unix->setgrent = adl_lib_setgrent;
    adl_unix->endgrent = adl_lib_endgrent;
    adl_unix->getspnam = adl_lib_getspnam;
    adl_unix->getspent = adl_lib_getspent;
    adl_unix->setspent = adl_lib_setspent;
    adl_unix->endspent = adl_lib_endspent;
    adl_unix->crypt = adl_lib_crypt;

null_adl_unix:
    return;
}

void ADL_UNIX_fini(ADL_UNIX *adl_unix)
{
    if(ADL_CHECK_NULL(adl_unix))
    {
        ADL_RETURN_DEFER(null_adl_unix);
    }

    ADL_MEMSET(adl_unix,0,sizeof(ADL_UNIX));

null_adl_unix:
    return;
}




#endif




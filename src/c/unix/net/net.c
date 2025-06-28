#include "net.h"


#ifdef ADL_OS_UNIX





/*
        NETWORK SOCKETS
*/






/*

ADL_RESULT adl_lib_socket(int domain,int type,int protocol);
    
            a wrapper for the socket system call on unix systems
            
            INPUT  : domain(eg. AF_INET,AF_INET6),type(eg. SOCK_STREAM,SOCK_RAW),protocol(eg. IPPROTO_TCP)
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains a valid socket descriptor which is a positive integral value

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/




bool adl_lib_SocketInit(void)
{
    return true;
}








/*

ADL_RESULT adl_lib_socket(int domain,int type,int protocol);
    
            a wrapper for the socket system call on unix systems
            
            INPUT  : domain(eg. AF_INET,AF_INET6),type(eg. SOCK_STREAM,SOCK_RAW),protocol(eg. IPPROTO_TCP)
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains a valid socket descriptor which is a positive integral value

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/




bool adl_lib_SocketFini(void)
{
    return true;
}




/*

ADL_RESULT adl_sys_socket(int domain,int type,int protocol);
    
            a wrapper for the socket system call on unix systems
            
            INPUT  : domain(eg. AF_INET,AF_INET6),type(eg. SOCK_STREAM,SOCK_RAW),protocol(eg. IPPROTO_TCP)
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains a valid socket descriptor which is a positive integral value

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/




ADL_RESULT adl_sys_socket(int domain,int type,int protocol)
{

    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SOCKET(domain,type,protocol);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}









/*

ADL_RESULT adl_sys_socketpair(int domain,int type,int protocol,int sockfds[2]);
    
            a wrapper for the socketpair system call on unix systems
            
            INPUT  : domain(eg. AF_INET,AF_INET6),type(eg. SOCK_STREAM,SOCK_RAW),protocol(eg. IPPROTO_TCP),array of two integers
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains two valid socket descriptors in the sockfds array which are positive integral value

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_socketpair(int domain,int type,int protocol,int sockfds[2])
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SOCKETPAIR(domain,type,protocol,sockfds);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen);

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


ADL_RESULT adl_sys_bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen)
{
    
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_BIND(sockfd,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_connect(int sockfd,const struct sockaddr *addr,socklen_t addrlen);

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


ADL_RESULT adl_sys_connect(int sockfd,const struct sockaddr *addr,socklen_t addrlen)
{
    
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CONNECT(sockfd,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_listen(int sockfd,int backlog);

            a wrapper for the listen system call on unix systems

            INPUT  : a valid socket descriptor,a positive integral value for the backlog
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_listen(int sockfd,int backlog)
{
    
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LISTEN(sockfd,backlog);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_accept(int sockfd,struct sockaddr *addr,socklen_t *addrlen);

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


ADL_RESULT adl_sys_accept(int sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_ACCEPT(sockfd,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_accept4(int sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags);

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


ADL_RESULT adl_sys_accept4(int sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_ACCEPT4(sockfd,addr,addrlen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_recv(int sockfd,void *buf,size_t buflen,int flags);

            a wrapper for the recv system call on unix systems

            INPUT  : a valid socket descriptor,an allocated buffer,size of the buffer,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_recv(int sockfd,void *buf,size_t buflen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECV(sockfd,buf,buflen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_recvfrom(int sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen);

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


ADL_RESULT adl_sys_recvfrom(int sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen)
{

    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECVFROM(sockfd,buf,buflen,flags,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_recvmsg(int sockfd,struct msghdr *msg,int flags);

            a wrapper for the recvmsg system call on unix systems

            INPUT  : a valid socket descriptor,pointer to an allocated struct msghdr memory region,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_recvmsg(int sockfd,struct msghdr *msg,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECVMSG(sockfd,msg,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_recvmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout);

            a wrapper for the recvmmsg system call on unix systems

            INPUT  : a valid socket descriptor,pointer to an allocated struct msghdr memory region,vlen,flags,timeout
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_recvmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECVMMSG(sockfd,msgvec,vlen,flags,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_send(int sockfd,const void *buf,size_t buflen,int flags);

            a wrapper for the send system call on unix systems

            INPUT  : a valid socket descriptor,an allocated buffer,size of the buffer,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes sent,zero is not an error,it just implies that zero bytes were sent

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_send(int sockfd,const void *buf,size_t buflen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEND(sockfd,buf,buflen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sendto(int sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen);

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


ADL_RESULT adl_sys_sendto(int sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDTO(sockfd,buf,buflen,flags,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sendmsg(int sockfd,const struct msghdr *msg,int flags);

            a wrapper for the sendmsg system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to an allocated struct msghdr memory region,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes sent,zero is not an error,it just implies that zero bytes were sent

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sendmsg(int sockfd,const struct msghdr *msg,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDMSG(sockfd,msg,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sendmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags);

            a wrapper for the sendmmsg system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to an allocated struct mmsghdr memory region,vlen,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes sent,zero is not an error,it just implies that zero bytes were sent

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sendmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDMMSG(sockfd,msgvec,vlen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_shutdown(int sockfd,int how);

            a wrapper for the shutdown system call on unix systems

            INPUT  : a valid socket descriptor,how(describes how/what to shutdown)
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_shutdown(int sockfd,int how)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SHUTDOWN(sockfd,how);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_close(int sockfd);

            a wrapper for the close system call on unix systems 

            INPUT  : a valid file/socket descriptor
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_close(int fd)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLOSE(fd);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_getsockopt(int sockfd,int level,int optname,void *optval,socklen_t *optlen);

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


ADL_RESULT adl_sys_getsockopt(int sockfd,int level,int optname,void *optval,socklen_t *optlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETSOCKOPT(sockfd,level,optname,optval,optlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_setsockopt(int sockfd,int level,int optname,void *optval,socklen_t optlen);

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


ADL_RESULT adl_sys_setsockopt(int sockfd,int level,int optname,void *optval,socklen_t optlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETSOCKOPT(sockfd,level,optname,optval,optlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_getsockname(int sockfd,struct sockaddr *addr,socklen_t *addrlen);

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


ADL_RESULT adl_sys_getsockname(int sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETSOCKNAME(sockfd,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_getpeername(int sockfd,struct sockaddr *addr,socklen_t *addrlen);

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


ADL_RESULT adl_sys_getpeername(int sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPEERNAME(sockfd,addr,addrlen);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_lib_getaddrinfo(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);

            a wrapper for the getaddrinfo library call

            INPUT  : host/ip,port/service,hints,res
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero,and res has memory allocated to it that should be freed using adl_freeaddrinfo_l eventually

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_getaddrinfo(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res)
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

ADL_RESULT adl_lib_freeaddrinfo(struct addrinfo *res);

            a wrapper for the freeaddrinfo library call

            INPUT  : res
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero,and res' memory is deallocated

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  DYNAMIC MEMORY IS NOT USED
*/


ADL_RESULT adl_lib_freeaddrinfo(struct addrinfo *res)
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

ADL_RESULT adl_lib_getnameinfo(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,int flags);

            a wrapper for getnameinfo library call

            INPUT  : addr,addrlen,host,hostlen,service,servicelen,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero,host and service are filled

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  DYNAMIC MEMORY IS NOT USED
*/


ADL_RESULT adl_lib_getnameinfo(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,int flags)
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





#endif

#include "net.h"


#ifdef ADL_OS_WINDOWS





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
    ADL_S64_INIT(ret);
    WSADATA wsa;

    if(WSAStartup(MAKEWORD(2,2),&wsa))
    {
        return false;
    }

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
    WSACleanup();
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




ADL_RESULT adl_lib_socket(int domain,int type,int protocol)
{

    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SOCKET(domain,type,protocol);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}









/*

ADL_RESULT adl_lib_socketpair(int domain,int type,int protocol,int sockfds[2]);
    
            a wrapper for the socketpair system call on unix systems
            
            INPUT  : domain(eg. AF_INET,AF_INET6),type(eg. SOCK_STREAM,SOCK_RAW),protocol(eg. IPPROTO_TCP),array of two integers
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains two valid socket descriptors in the sockfds array which are positive integral value

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED



ADL_RESULT adl_lib_socketpair(int domain,int type,int protocol,int sockfds[2])
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SOCKETPAIR(domain,type,protocol,sockfds);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}

*/



/*

ADL_RESULT adl_lib_bind(ADL_SOCKET_DESC sockfd,const struct sockaddr *addr,socklen_t addrlen);

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


ADL_RESULT adl_lib_bind(ADL_SOCKET_DESC sockfd,const struct sockaddr *addr,socklen_t addrlen)
{
    
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_BIND(sockfd,addr,addrlen);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_connect(ADL_SOCKET_DESC sockfd,const struct sockaddr *addr,socklen_t addrlen);

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


ADL_RESULT adl_lib_connect(ADL_SOCKET_DESC sockfd,const struct sockaddr *addr,socklen_t addrlen)
{
    
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CONNECT(sockfd,addr,addrlen);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_listen(ADL_SOCKET_DESC sockfd,int backlog);

            a wrapper for the listen system call on unix systems

            INPUT  : a valid socket descriptor,a positive integral value for the backlog
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_listen(ADL_SOCKET_DESC sockfd,int backlog)
{
    
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_LISTEN(sockfd,backlog);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_accept(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen);

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


ADL_RESULT adl_lib_accept(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_ACCEPT(sockfd,addr,addrlen);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_accept4(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags);

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



ADL_RESULT adl_lib_accept4(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_ACCEPT4(sockfd,addr,addrlen,flags);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}

*/




/*

ADL_RESULT adl_lib_recv(ADL_SOCKET_DESC sockfd,void *buf,size_t buflen,int flags);

            a wrapper for the recv system call on unix systems

            INPUT  : a valid socket descriptor,an allocated buffer,size of the buffer,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_recv(ADL_SOCKET_DESC sockfd,void *buf,size_t buflen,int flags)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECV(sockfd,buf,buflen,flags);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_lib_recvfrom(ADL_SOCKET_DESC sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen);

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


ADL_RESULT adl_lib_recvfrom(ADL_SOCKET_DESC sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen)
{

    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECVFROM(sockfd,buf,buflen,flags,addr,addrlen);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_recvmsg(ADL_SOCKET_DESC sockfd,struct msghdr *msg,int flags);

            a wrapper for the recvmsg system call on unix systems

            INPUT  : a valid socket descriptor,pointer to an allocated struct msghdr memory region,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED



ADL_RESULT adl_lib_recvmsg(ADL_SOCKET_DESC sockfd,struct msghdr *msg,int flags)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECVMSG(sockfd,msg,flags);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}







ADL_RESULT adl_lib_recvmmsg(ADL_SOCKET_DESC sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout);

            a wrapper for the recvmmsg system call on unix systems

            INPUT  : a valid socket descriptor,pointer to an allocated struct msghdr memory region,vlen,flags,timeout
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes received,zero is not an error,it just implies that zero bytes were received

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED



ADL_RESULT adl_lib_recvmmsg(ADL_SOCKET_DESC sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_RECVMMSG(sockfd,msgvec,vlen,flags,timeout);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}



*/


/*

ADL_RESULT adl_lib_send(ADL_SOCKET_DESC sockfd,const void *buf,size_t buflen,int flags);

            a wrapper for the send system call on unix systems

            INPUT  : a valid socket descriptor,an allocated buffer,size of the buffer,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes sent,zero is not an error,it just implies that zero bytes were sent

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_send(ADL_SOCKET_DESC sockfd,const void *buf,size_t buflen,int flags)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEND(sockfd,buf,buflen,flags);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_sendto(ADL_SOCKET_DESC sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen);

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


ADL_RESULT adl_lib_sendto(ADL_SOCKET_DESC sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDTO(sockfd,buf,buflen,flags,addr,addrlen);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_sendmsg(ADL_SOCKET_DESC sockfd,const struct msghdr *msg,int flags);

            a wrapper for the sendmsg system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to an allocated struct msghdr memory region,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes sent,zero is not an error,it just implies that zero bytes were sent

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED



ADL_RESULT adl_lib_sendmsg(ADL_SOCKET_DESC sockfd,const struct msghdr *msg,int flags)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDMSG(sockfd,msg,flags);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}







ADL_RESULT adl_lib_sendmmsg(ADL_SOCKET_DESC sockfd,struct mmsghdr *msgvec,int vlen,int flags);

            a wrapper for the sendmmsg system call on unix systems

            INPUT  : a valid socket descriptor,a pointer to an allocated struct mmsghdr memory region,vlen,flags
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is to the number of bytes sent,zero is not an error,it just implies that zero bytes were sent

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED



ADL_RESULT adl_lib_sendmmsg(ADL_SOCKET_DESC sockfd,struct mmsghdr *msgvec,int vlen,int flags)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SENDMMSG(sockfd,msgvec,vlen,flags);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}

*/



/*

ADL_RESULT adl_lib_shutdown(ADL_SOCKET_DESC sockfd,int how);

            a wrapper for the shutdown system call on unix systems

            INPUT  : a valid socket descriptor,how(describes how/what to shutdown)
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_shutdown(ADL_SOCKET_DESC sockfd,int how)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SHUTDOWN(sockfd,how);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_closesocket(ADL_SOCKET_DESC sockfd);

            a wrapper for the close system call on unix systems 

            INPUT  : a valid file/socket descriptor
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_closesocket(ADL_SOCKET_DESC sockfd)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_CLOSESOCKET(sockfd);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_getsockopt(ADL_SOCKET_DESC sockfd,int level,int optname,void *optval,socklen_t *optlen);

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


ADL_RESULT adl_lib_getsockopt(ADL_SOCKET_DESC sockfd,int level,int optname,void *optval,socklen_t *optlen)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETSOCKOPT(sockfd,level,optname,optval,optlen);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_setsockopt(ADL_SOCKET_DESC sockfd,int level,int optname,void *optval,socklen_t optlen);

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


ADL_RESULT adl_lib_setsockopt(ADL_SOCKET_DESC sockfd,int level,int optname,void *optval,socklen_t optlen)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETSOCKOPT(sockfd,level,optname,optval,optlen);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_getsockname(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen);

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


ADL_RESULT adl_lib_getsockname(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETSOCKNAME(sockfd,addr,addrlen);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_getpeername(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen);

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


ADL_RESULT adl_lib_getpeername(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETPEERNAME(sockfd,addr,addrlen);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
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
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETADDRINFO(host,service,hints,res);

    if(ADL_CHECK_NOT_EQUAL(rdr_ret,0))
    {
        rdr_ret = -1;
    }
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
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
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    if(ADL_CHECK_NULL(res))
    {
        rdr_ret = -1;
    }

    ADL_FREEADDRINFO(res);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
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
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETNAMEINFO(addr,addrlen,host,hostlen,service,servicelen,flags);

    if(ADL_CHECK_NOT_EQUAL(rdr_ret,0))
    {
        rdr_ret = -1;
    }
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
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
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_HTONS(hostshort);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
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
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_HTONL(hostlong);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
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
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_NTOHS(netshort);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
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
    ADL_WINDOWS_SOCKET_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_NTOHL(netlong);
    ADL_WINDOWS_SOCKET_FINI(rdr_ret,rdr_retptr);
}





#endif

#include "../../os.h"
#include "../../../include/os/net/socket/socket.h"


typedef u64 ADL_SOCKFD;

extern ADL_Unix adl_os;


#ifndef ADL_SOCKET_INIT
#define ADL_SOCKET_INIT(val)    ADL_Result val = (ADL_Result){};                \
                                if(ADL_CHECK_NULL(self))                        \
                                {                                               \
                                    ADL_String str;                             \
                                    adl_string_init(&str,"null self");          \
                                    val = ADL_RESULT_WRITE(-1,str,NULL);        \
                                    ADL_RETURN_DEFER(null_self);                \
                                }                                  
#endif



#ifndef ADL_SOCKET_FINI_V1
#define ADL_SOCKET_FINI_V1(val)     if(ADL_RESULT_CHECK_ERROR(val))             \
                                    {                                           \
                                        ADL_RETURN_DEFER(failed_syscall);       \
                                    }                                           \
                                    self->sock.sockfd = (ADL_SOCKFD)result.code;\
                                null_self:                                      \
                                failed_syscall:                                 \
                                    return result
#endif



#ifndef ADL_SOCKET_FINI_V2
#define ADL_SOCKET_FINI_V2(val,sockfds)     if(ADL_RESULT_CHECK_ERROR(val))                         \
                                            {                                                       \
                                                ADL_RETURN_DEFER(failed_syscall);                   \
                                            }                                                       \
                                            self->sock.sockfds[0] = (ADL_SOCKFD)sockfds[0];         \
                                            self->sock.sockfds[1] = (ADL_SOCKFD)sockfds[1];         \
                                        null_self:                                                  \
                                        failed_syscall:                                             \
                                            return result
#endif


#ifndef ADL_SOCKET_FINI_V3
#define ADL_SOCKET_FINI_V3(val)     if(ADL_RESULT_CHECK_ERROR(val))             \
                                    {                                           \
                                        ADL_RETURN_DEFER(failed_syscall);       \
                                    }                                           \
                                null_self:                                      \
                                failed_syscall:                                 \
                                    return result
#endif





ADL_Result adl_socket_socket(struct ADL_Socket *self,s64 domain,s64 type,s64 protocol)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.socket(domain,type,protocol);
    ADL_SOCKET_FINI_V1(result);
}




ADL_Result adl_socket_socketpair(struct ADL_Socket *self,s64 domain,s64 type,s64 protocol)
{
    ADL_SOCKET_INIT(result);
    s32 sockfds[2] = {};
    result = adl_os.socketpair(domain,type,protocol,sockfds);
    ADL_SOCKET_FINI_V2(result,sockfds);
}




ADL_Result adl_socket_bind(struct ADL_Socket *self,const struct sockaddr *addr,socklen_t addrlen)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.bind(self->sock.sockfd,addr,addrlen);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_connect(struct ADL_Socket *self,const struct sockaddr *addr,socklen_t addrlen)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.connect(self->sock.sockfd,addr,addrlen);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_listen(struct ADL_Socket *self,s64 backlog)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.listen(self->sock.sockfd,backlog);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_accept(struct ADL_Socket *self,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.accept(self->sock.sockfd,addr,addrlen);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_accept4(struct ADL_Socket *self,struct sockaddr *addr,socklen_t *addrlen,s64 flags)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.accept4(self->sock.sockfd,addr,addrlen,flags);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_recv(struct ADL_Socket *self,ADL_SOCKFD sockfd,void *buf,u64 buflen,s64 flags)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.recv(sockfd,buf,buflen,flags);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_recvfrom(struct ADL_Socket *self,ADL_SOCKFD sockfd,void *buf,u64 buflen,s64 flags,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.recvfrom(sockfd,buf,buflen,flags,addr,addrlen);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_recvmsg(struct ADL_Socket *self,ADL_SOCKFD sockfd,struct msghdr *msg,s64 flags)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.recvmsg(sockfd,msg,flags);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_recvmmsg(struct ADL_Socket *self,ADL_SOCKFD sockfd,struct mmsghdr *msgvec,s64 vlen,s64 flags,struct timespec *timeout)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.recvmmsg(sockfd,msgvec,vlen,flags,timeout);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_send(struct ADL_Socket *self,ADL_SOCKFD sockfd,const void *buf,u64 buflen,s64 flags)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.send(sockfd,buf,buflen,flags);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_sendto(struct ADL_Socket *self,ADL_SOCKFD sockfd,const void *buf,u64 buflen,s64 flags,struct sockaddr *addr,socklen_t addrlen)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.sendto(sockfd,buf,buflen,flags,addr,addrlen);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_sendmsg(struct ADL_Socket *self,ADL_SOCKFD sockfd,const struct msghdr *msg,s64 flags)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.sendmsg(sockfd,msg,flags);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_sendmmsg(struct ADL_Socket *self,ADL_SOCKFD sockfd,struct mmsghdr *msgvec,s64 vlen,s64 flags)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.sendmmsg(sockfd,msgvec,vlen,flags);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_shutdown(struct ADL_Socket *self,ADL_SOCKFD sockfd,s64 how)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.shutdown(sockfd,how);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_close(struct ADL_Socket *self,ADL_SOCKFD sockfd)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.close(sockfd);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_getsockopt(struct ADL_Socket *self,s64 level,s64 optname,void *optval,socklen_t *optlen)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.getsockopt(self->sock.sockfd,level,optname,optval,optlen);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_setsockopt(struct ADL_Socket *self,s64 level,s64 optname,void *optval,socklen_t optlen)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.setsockopt(self->sock.sockfd,level,optname,optval,optlen);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_getsockname(struct ADL_Socket *self,ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.getsockname(sockfd,addr,addrlen);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_getpeername(struct ADL_Socket *self,ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.getpeername(sockfd,addr,addrlen);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_getaddrinfo(struct ADL_Socket *self,const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.getaddrinfo(host,service,hints,res);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_freeaddrinfo(struct ADL_Socket *self,struct addrinfo *res)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.freeaddrinfo(res);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_getnameinfo(struct ADL_Socket *self,const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,s64 flags)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.getnameinfo(addr,addrlen,host,hostlen,service,servicelen,flags);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_htons(struct ADL_Socket *self,u16 hostshort)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.htons(hostshort);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_htonl(struct ADL_Socket *self,u32 hostlong)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.htonl(hostlong);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_ntohs(struct ADL_Socket *self,u16 netshort)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.ntohs(netshort);
    ADL_SOCKET_FINI_V3(result);
}




ADL_Result adl_socket_ntohl(struct ADL_Socket *self,u32 netlong)
{
    ADL_SOCKET_INIT(result);
    result = adl_os.ntohl(netlong);
    ADL_SOCKET_FINI_V3(result);
}




void ADL_Socket_init(ADL_Socket *sock)
{
    if(ADL_CHECK_NULL(sock))
    {
        ADL_RETURN_DEFER(null_sock);
    }

    sock->sock.sockfd                 = 0;
    sock->sock.sockfds[0]             = 0;
    sock->sock.sockfds[1]             = 0;


    sock->socket                      = adl_socket_socket;
	sock->socketpair                  = adl_socket_socketpair;
	sock->bind                        = adl_socket_bind;
	sock->connect                     = adl_socket_connect;
	sock->listen                      = adl_socket_listen;
	sock->accept                      = adl_socket_accept;
	sock->accept4                     = adl_socket_accept4;
	sock->recv                        = adl_socket_recv;
	sock->recvfrom                    = adl_socket_recvfrom;
	sock->recvmsg                     = adl_socket_recvmsg;
	sock->recvmmsg                    = adl_socket_recvmmsg;
	sock->send                        = adl_socket_send;
	sock->sendto                      = adl_socket_sendto;
	sock->sendmsg                     = adl_socket_sendmsg;
	sock->sendmmsg                    = adl_socket_sendmmsg;
	sock->shutdown                    = adl_socket_shutdown;
	sock->close                       = adl_socket_close;
	sock->getsockopt                  = adl_socket_getsockopt;
	sock->setsockopt                  = adl_socket_setsockopt;
	sock->getsockname                 = adl_socket_getsockname;
	sock->getpeername                 = adl_socket_getpeername;
	sock->getaddrinfo                 = adl_socket_getaddrinfo;
	sock->freeaddrinfo                = adl_socket_freeaddrinfo;
	sock->getnameinfo                 = adl_socket_getnameinfo;
	sock->htons                       = adl_socket_htons;
	sock->htonl                       = adl_socket_htonl;
	sock->ntohs                       = adl_socket_ntohs;
	sock->ntohl                       = adl_socket_ntohl;


null_sock:
    return;
}

void ADL_Socket_fini(ADL_Socket *sock)
{
    if(ADL_CHECK_NULL(sock))
    {
        ADL_RETURN_DEFER(null_sock);
    }

    ADL_MEMSET(sock,0,sizeof(ADL_Socket));

null_sock:
    return;
}


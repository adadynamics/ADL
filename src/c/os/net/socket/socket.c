#include "../../os.h"
#include "../../../include/os/net/socket/socket.h"


typedef u64 ADL_SOCKFD;

extern ADL_Unix adl_os;


ADL_Result adl_socket_socket(s64 domain,s64 type,s64 protocol)
{
    return adl_os.socket(domain,type,protocol);
}



ADL_Result adl_socket_socketpair(s64 domain,s64 type,s64 protocol,ADL_SOCKFD sockfds[2])
{
    return adl_os.socketpair(domain,type,protocol,(s32_ptr)sockfds);
}



ADL_Result adl_socket_bind(ADL_SOCKFD sockfd,const struct sockaddr *addr,socklen_t addrlen)
{
    return adl_os.bind(sockfd,addr,addrlen);
}



ADL_Result adl_socket_connect(ADL_SOCKFD sockfd,const struct sockaddr *addr,socklen_t addrlen)
{
    return adl_os.connect(sockfd,addr,addrlen);
}



ADL_Result adl_socket_listen(ADL_SOCKFD sockfd,s64 backlog)
{
    return adl_os.listen(sockfd,backlog);
}



ADL_Result adl_socket_accept(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    return adl_os.accept(sockfd,addr,addrlen);
}



ADL_Result adl_socket_accept4(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen,s64 flags)
{
    return adl_os.accept4(sockfd,addr,addrlen,flags);
}



ADL_Result adl_socket_recv(ADL_SOCKFD sockfd,void *buf,u64 buflen,s64 flags)
{
    return adl_os.recv(sockfd,buf,buflen,flags);
}



ADL_Result adl_socket_recvfrom(ADL_SOCKFD sockfd,void *buf,u64 buflen,s64 flags,struct sockaddr *addr,socklen_t *addrlen)
{
    return adl_os.recvfrom(sockfd,buf,buflen,flags,addr,addrlen);
}



ADL_Result adl_socket_recvmsg(ADL_SOCKFD sockfd,struct msghdr *msg,s64 flags)
{
    return adl_os.recvmsg(sockfd,msg,flags);
}



ADL_Result adl_socket_recvmmsg(ADL_SOCKFD sockfd,struct mmsghdr *msgvec,s64 vlen,s64 flags,struct timespec *timeout)
{
    return adl_os.recvmmsg(sockfd,msgvec,vlen,flags,timeout);
}



ADL_Result adl_socket_send(ADL_SOCKFD sockfd,const void *buf,u64 buflen,s64 flags)
{
    return adl_os.send(sockfd,buf,buflen,flags);
}



ADL_Result adl_socket_sendto(ADL_SOCKFD sockfd,const void *buf,u64 buflen,s64 flags,struct sockaddr *addr,socklen_t addrlen)
{
    return adl_os.sendto(sockfd,buf,buflen,flags,addr,addrlen);
}



ADL_Result adl_socket_sendmsg(ADL_SOCKFD sockfd,const struct msghdr *msg,s64 flags)
{
    return adl_os.sendmsg(sockfd,msg,flags);
}



ADL_Result adl_socket_sendmmsg(ADL_SOCKFD sockfd,struct mmsghdr *msgvec,s64 vlen,s64 flags)
{
    return adl_os.sendmmsg(sockfd,msgvec,vlen,flags);
}



ADL_Result adl_socket_shutdown(ADL_SOCKFD sockfd,s64 how)
{
    return adl_os.shutdown(sockfd,how);
}



ADL_Result adl_socket_close(ADL_SOCKFD sockfd)
{
    return adl_os.close(sockfd);
}



ADL_Result adl_socket_getsockopt(ADL_SOCKFD sockfd,s64 level,s64 optname,void *optval,socklen_t *optlen)
{
    return adl_os.getsockopt(sockfd,level,optname,optval,optlen);
}



ADL_Result adl_socket_setsockopt(ADL_SOCKFD sockfd,s64 level,s64 optname,void *optval,socklen_t optlen)
{
    return adl_os.setsockopt(sockfd,level,optname,optval,optlen);
}



ADL_Result adl_socket_getsockname(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    return adl_os.getsockname(sockfd,addr,addrlen);
}



ADL_Result adl_socket_getpeername(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen)
{
    return adl_os.getpeername(sockfd,addr,addrlen);
}



ADL_Result adl_socket_getaddrinfo(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res)
{
    return adl_os.getaddrinfo(host,service,hints,res);
}



ADL_Result adl_socket_freeaddrinfo(struct addrinfo *res)
{
    return adl_os.freeaddrinfo(res);
}



ADL_Result adl_socket_getnameinfo(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,s64 flags)
{
    return adl_os.getnameinfo(addr,addrlen,host,hostlen,service,servicelen,flags);
}



ADL_Result adl_socket_htons(u16 hostshort)
{
    return adl_os.htons(hostshort);
}



ADL_Result adl_socket_htonl(u32 hostlong)
{
    return adl_os.htonl(hostlong);
}



ADL_Result adl_socket_ntohs(u16 netshort)
{
    return adl_os.ntohs(netshort);
}



ADL_Result adl_socket_ntohl(u32 netlong)
{
    return adl_os.ntohl(netlong);
}



void ADL_Socket_init(ADL_Socket *sock)
{
    if(ADL_CHECK_NULL(sock))
    {
        ADL_RETURN_DEFER(null_sock);
    }

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


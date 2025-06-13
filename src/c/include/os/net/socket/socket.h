#ifndef ADL_OS_NET_SOCKET_SOCKET_H
#define ADL_OS_NET_SOCKET_SOCKET_H

#include "../../../unix/unix.h"
#include "../../os.h"


typedef u64 ADL_SOCKFD;

typedef struct ADL_Socket
{
	ADL_Result (*socket)(s64 domain,s64 type,s64 protocol);
	ADL_Result (*socketpair)(s64 domain,s64 type,s64 protocol,ADL_SOCKFD sockfds[2]);
	ADL_Result (*bind)(ADL_SOCKFD sockfd,const struct sockaddr *addr,socklen_t addrlen);
	ADL_Result (*connect)(ADL_SOCKFD sockfd,const struct sockaddr *addr,socklen_t addrlen);
	ADL_Result (*listen)(ADL_SOCKFD sockfd,s64 backlog);
	ADL_Result (*accept)(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_Result (*accept4)(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen,s64 flags);
	ADL_Result (*recv)(ADL_SOCKFD sockfd,void *buf,u64 buflen,s64 flags);
	ADL_Result (*recvfrom)(ADL_SOCKFD sockfd,void *buf,u64 buflen,s64 flags,struct sockaddr *addr,socklen_t *addrlen);
	ADL_Result (*recvmsg)(ADL_SOCKFD sockfd,struct msghdr *msg,s64 flags);
	ADL_Result (*recvmmsg)(ADL_SOCKFD sockfd,struct mmsghdr *msgvec,s64 vlen,s64 flags,struct timespec *timeout);
	ADL_Result (*send)(ADL_SOCKFD sockfd,const void *buf,u64 buflen,s64 flags);
	ADL_Result (*sendto)(ADL_SOCKFD sockfd,const void *buf,u64 buflen,s64 flags,struct sockaddr *addr,socklen_t addrlen);
	ADL_Result (*sendmsg)(ADL_SOCKFD sockfd,const struct msghdr *msg,s64 flags);
	ADL_Result (*sendmmsg)(ADL_SOCKFD sockfd,struct mmsghdr *msgvec,s64 vlen,s64 flags);
	ADL_Result (*shutdown)(ADL_SOCKFD sockfd,s64 how);
	ADL_Result (*close)(ADL_SOCKFD sockfd);
	ADL_Result (*getsockopt)(ADL_SOCKFD sockfd,s64 level,s64 optname,void *optval,socklen_t *optlen);
	ADL_Result (*setsockopt)(ADL_SOCKFD sockfd,s64 level,s64 optname,void *optval,socklen_t optlen);
	ADL_Result (*getsockname)(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_Result (*getpeername)(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_Result (*getaddrinfo)(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);
	ADL_Result (*freeaddrinfo)(struct addrinfo *res);
	ADL_Result (*getnameinfo)(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,s64 flags);
	ADL_Result (*htons)(u16 hostshort);
	ADL_Result (*htonl)(u32 hostlong);
	ADL_Result (*ntohs)(u16 netshort);
	ADL_Result (*ntohl)(u32 netlong);
}ADL_Socket;




void ADL_Socket_init(ADL_Socket *sock);

void ADL_Socket_fini(ADL_Socket *sock);



#endif

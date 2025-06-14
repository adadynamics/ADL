#ifndef ADL_OS_NET_SOCKET_SOCKET_H
#define ADL_OS_NET_SOCKET_SOCKET_H

#include "../../../unix/unix.h"
#include "../../os.h"


typedef u64 ADL_SOCKFD;

typedef struct ADL_SOCKET
{
	ADL_RESULT (*socket)(s64 domain,s64 type,s64 protocol);
	ADL_RESULT (*socketpair)(s64 domain,s64 type,s64 protocol,ADL_SOCKFD sockfds[2]);
	ADL_RESULT (*bind)(ADL_SOCKFD sockfd,const struct sockaddr *addr,socklen_t addrlen);
	ADL_RESULT (*connect)(ADL_SOCKFD sockfd,const struct sockaddr *addr,socklen_t addrlen);
	ADL_RESULT (*listen)(ADL_SOCKFD sockfd,s64 backlog);
	ADL_RESULT (*accept)(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_RESULT (*accept4)(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen,s64 flags);
	ADL_RESULT (*recv)(ADL_SOCKFD sockfd,void *buf,u64 buflen,s64 flags);
	ADL_RESULT (*recvfrom)(ADL_SOCKFD sockfd,void *buf,u64 buflen,s64 flags,struct sockaddr *addr,socklen_t *addrlen);
	ADL_RESULT (*recvmsg)(ADL_SOCKFD sockfd,struct msghdr *msg,s64 flags);
	ADL_RESULT (*recvmmsg)(ADL_SOCKFD sockfd,struct mmsghdr *msgvec,s64 vlen,s64 flags,struct timespec *timeout);
	ADL_RESULT (*send)(ADL_SOCKFD sockfd,const void *buf,u64 buflen,s64 flags);
	ADL_RESULT (*sendto)(ADL_SOCKFD sockfd,const void *buf,u64 buflen,s64 flags,struct sockaddr *addr,socklen_t addrlen);
	ADL_RESULT (*sendmsg)(ADL_SOCKFD sockfd,const struct msghdr *msg,s64 flags);
	ADL_RESULT (*sendmmsg)(ADL_SOCKFD sockfd,struct mmsghdr *msgvec,s64 vlen,s64 flags);
	ADL_RESULT (*shutdown)(ADL_SOCKFD sockfd,s64 how);
	ADL_RESULT (*close)(ADL_SOCKFD sockfd);
	ADL_RESULT (*getsockopt)(ADL_SOCKFD sockfd,s64 level,s64 optname,void *optval,socklen_t *optlen);
	ADL_RESULT (*setsockopt)(ADL_SOCKFD sockfd,s64 level,s64 optname,void *optval,socklen_t optlen);
	ADL_RESULT (*getsockname)(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_RESULT (*getpeername)(ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_RESULT (*getaddrinfo)(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);
	ADL_RESULT (*freeaddrinfo)(struct addrinfo *res);
	ADL_RESULT (*getnameinfo)(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,s64 flags);
	ADL_RESULT (*htons)(u16 hostshort);
	ADL_RESULT (*htonl)(u32 hostlong);
	ADL_RESULT (*ntohs)(u16 netshort);
	ADL_RESULT (*ntohl)(u32 netlong);
}ADL_SOCKET;




void ADL_SOCKET_init(ADL_SOCKET *sock);

void ADL_SOCKET_fini(ADL_SOCKET *sock);



#endif

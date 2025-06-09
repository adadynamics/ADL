#ifndef ADL_OS_NET_SOCKET_SOCKET_H
#define ADL_OS_NET_SOCKET_SOCKET_H

#include "../../os.h"

typedef u64 ADL_SOCKFD;

typedef struct ADL_Socket
{
	union
	{
		ADL_SOCKFD sockfd;
		ADL_SOCKFD sockfds[2];
	}sock;

	ADL_Result (*socket)(struct ADL_Socket *self,s64 domain,s64 type,s64 protocol);
	ADL_Result (*socketpair)(struct ADL_Socket *self,s64 domain,s64 type,s64 protocol);
	ADL_Result (*bind)(struct ADL_Socket *self,const struct sockaddr *addr,socklen_t addrlen);
	ADL_Result (*connect)(struct ADL_Socket *self,const struct sockaddr *addr,socklen_t addrlen);
	ADL_Result (*listen)(struct ADL_Socket *self,s64 backlog);
	ADL_Result (*accept)(struct ADL_Socket *self,struct sockaddr *addr,socklen_t *addrlen);
	ADL_Result (*accept4)(struct ADL_Socket *self,struct sockaddr *addr,socklen_t *addrlen,s64 flags);
	ADL_Result (*recv)(struct ADL_Socket *self,ADL_SOCKFD sockfd,void *buf,u64 buflen,s64 flags);
	ADL_Result (*recvfrom)(struct ADL_Socket *self,ADL_SOCKFD sockfd,void *buf,u64 buflen,s64 flags,struct sockaddr *addr,socklen_t *addrlen);
	ADL_Result (*recvmsg)(struct ADL_Socket *self,ADL_SOCKFD sockfd,struct msghdr *msg,s64 flags);
	ADL_Result (*recvmmsg)(struct ADL_Socket *self,ADL_SOCKFD sockfd,struct mmsghdr *msgvec,s64 vlen,s64 flags,struct timespec *timeout);
	ADL_Result (*send)(struct ADL_Socket *self,ADL_SOCKFD sockfd,const void *buf,u64 buflen,s64 flags);
	ADL_Result (*sendto)(struct ADL_Socket *self,ADL_SOCKFD sockfd,const void *buf,u64 buflen,s64 flags,struct sockaddr *addr,socklen_t addrlen);
	ADL_Result (*sendmsg)(struct ADL_Socket *self,ADL_SOCKFD sockfd,const struct msghdr *msg,s64 flags);
	ADL_Result (*sendmmsg)(struct ADL_Socket *self,ADL_SOCKFD sockfd,struct mmsghdr *msgvec,s64 vlen,s64 flags);
	ADL_Result (*shutdown)(struct ADL_Socket *self,ADL_SOCKFD sockfd,s64 how);
	ADL_Result (*close)(struct ADL_Socket *self,ADL_SOCKFD sockfd);
	ADL_Result (*getsockopt)(struct ADL_Socket *self,s64 level,s64 optname,void *optval,socklen_t *optlen);
	ADL_Result (*setsockopt)(struct ADL_Socket *self,s64 level,s64 optname,void *optval,socklen_t optlen);
	ADL_Result (*getsockname)(struct ADL_Socket *self,ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_Result (*getpeername)(struct ADL_Socket *self,ADL_SOCKFD sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_Result (*getaddrinfo)(struct ADL_Socket *self,const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);
	ADL_Result (*freeaddrinfo)(struct ADL_Socket *self,struct addrinfo *res);
	ADL_Result (*getnameinfo)(struct ADL_Socket *self,const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,s64 flags);
	ADL_Result (*htons)(struct ADL_Socket *self,u16 hostshort);
	ADL_Result (*htonl)(struct ADL_Socket *self,u32 hostlong);
	ADL_Result (*ntohs)(struct ADL_Socket *self,u16 netshort);
	ADL_Result (*ntohl)(struct ADL_Socket *self,u32 netlong);
}ADL_Socket;




void ADL_Socket_init(ADL_Socket *sock);

void ADL_Socket_fini(ADL_Socket *sock);



#endif

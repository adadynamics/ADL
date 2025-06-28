#ifndef ADL_SRC_OS_NET_PLATFORM_WINDOWS_SOCKET_WINDOWS_H
#define ADL_SRC_OS_NET_PLATFORM_WINDOWS_SOCKET_WINDOWS_H


#include "../../../os.h"

#ifdef ADL_OS_WINDOWS


typedef struct ADL_SOCKET_WINDOWS
{
	ADL_RESULT (*socket)(s32 domain,s32 type,s32 protocol);
	ADL_RESULT (*socketpair)(s32 domain,s32 type,s32 protocol,ADL_SOCKET_DESC sockfds[2]);
	ADL_RESULT (*bind)(ADL_SOCKET_DESC sockfd,const struct sockaddr *addr,socklen_t addrlen);
	ADL_RESULT (*connect)(ADL_SOCKET_DESC sockfd,const struct sockaddr *addr,socklen_t addrlen);
	ADL_RESULT (*listen)(ADL_SOCKET_DESC sockfd,s32 backlog);
	ADL_RESULT (*accept)(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_RESULT (*accept4)(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen,s32 flags);
	ADL_RESULT (*recv)(ADL_SOCKET_DESC sockfd,void *buf,size_t buflen,s32 flags);
	ADL_RESULT (*recvfrom)(ADL_SOCKET_DESC sockfd,void *buf,size_t buflen,s32 flags,struct sockaddr *addr,socklen_t *addrlen);
	/*
	ADL_RESULT (*recvmsg)(ADL_SOCKET_DESC sockfd,struct msghdr *msg,s32 flags);
	ADL_RESULT (*recvmmsg)(ADL_SOCKET_DESC sockfd,struct mmsghdr *msgvec,s32 vlen,s32 flags,struct timespec *timeout);
	*/
	ADL_RESULT (*send)(ADL_SOCKET_DESC sockfd,const void *buf,size_t buflen,s32 flags);
	ADL_RESULT (*sendto)(ADL_SOCKET_DESC sockfd,const void *buf,size_t buflen,s32 flags,struct sockaddr *addr,socklen_t addrlen);
	/*
	ADL_RESULT (*sendmsg)(ADL_SOCKET_DESC sockfd,const struct msghdr *msg,s32 flags);
	ADL_RESULT (*sendmmsg)(ADL_SOCKET_DESC sockfd,struct mmsghdr *msgvec,s32 vlen,s32 flags);
	*/
	ADL_RESULT (*shutdown)(ADL_SOCKET_DESC sockfd,s32 how);
	ADL_RESULT (*close)(ADL_SOCKET_DESC sockfd);
	ADL_RESULT (*getsockopt)(ADL_SOCKET_DESC sockfd,s32 level,s32 optname,void *optval,socklen_t *optlen);
	ADL_RESULT (*setsockopt)(ADL_SOCKET_DESC sockfd,s32 level,s32 optname,void *optval,socklen_t optlen);
	ADL_RESULT (*getsockname)(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_RESULT (*getpeername)(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen);
	ADL_RESULT (*getaddrinfo)(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);
	ADL_RESULT (*freeaddrinfo)(struct addrinfo *res);
	ADL_RESULT (*getnameinfo)(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,s32 flags);
	ADL_RESULT (*htons)(u16 hostshort);
	ADL_RESULT (*htonl)(u32 hostlong);
	ADL_RESULT (*ntohs)(u16 netshort);
	ADL_RESULT (*ntohl)(u32 netlong);
}ADL_SOCKET_WINDOWS;



void ADL_SOCKET_WINDOWS_Init(ADL_SOCKET_WINDOWS *class);

void ADL_SOCKET_WINDOWS_Fini(ADL_SOCKET_WINDOWS *class);



#endif



#endif
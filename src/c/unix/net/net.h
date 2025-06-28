#ifndef ADL_SRC_UNIX_NET_NET_H
#define ADL_SRC_UNIX_NET_NET_H


#include "../unix.h"


#ifdef ADL_OS_UNIX




#ifndef ADL_SOCKET
#define ADL_SOCKET socket
#endif


#ifndef ADL_SOCKETPAIR
#define ADL_SOCKETPAIR socketpair
#endif


#ifndef ADL_CONNECT
#define ADL_CONNECT connect
#endif

#ifndef ADL_BIND
#define ADL_BIND bind
#endif


#ifndef ADL_LISTEN
#define ADL_LISTEN listen
#endif


#ifndef ADL_ACCEPT 
#define ADL_ACCEPT accept
#endif

#ifndef ADL_ACCEPT4
#define ADL_ACCEPT4 accept4
#endif

#ifndef ADL_RECV
#define ADL_RECV recv
#endif


#ifndef ADL_RECVFROM
#define ADL_RECVFROM recvfrom
#endif


#ifndef ADL_RECVMSG
#define ADL_RECVMSG recvmsg
#endif

#ifndef ADL_RECVMMSG
#define ADL_RECVMMSG recvmmsg
#endif

#ifndef ADL_SEND
#define ADL_SEND send
#endif

#ifndef ADL_SENDTO
#define ADL_SENDTO sendto
#endif


#ifndef ADL_SENDMSG
#define ADL_SENDMSG sendmsg
#endif

#ifndef ADL_SENDMMSG
#define ADL_SENDMMSG sendmmsg
#endif


#ifndef ADL_SHUTDOWN
#define ADL_SHUTDOWN shutdown
#endif

#ifndef ADL_CLOSE
#define ADL_CLOSE close
#endif


#ifndef ADL_GETSOCKOPT
#define ADL_GETSOCKOPT getsockopt
#endif


#ifndef ADL_SETSOCKOPT
#define ADL_SETSOCKOPT setsockopt
#endif


#ifndef ADL_GETSOCKNAME
#define ADL_GETSOCKNAME getsockname
#endif


#ifndef ADL_GETPEERNAME 
#define ADL_GETPEERNAME getpeername
#endif

#ifndef ADL_GETADDRINFO
#define ADL_GETADDRINFO getaddrinfo
#endif

#ifndef ADL_FREEADDRINFO
#define ADL_FREEADDRINFO freeaddrinfo
#endif

#ifndef ADL_GAI_STRERROR
#define ADL_GAI_STRERROR gai_strerror
#endif

#ifndef ADL_GETNAMEINFO
#define ADL_GETNAMEINFO getnameinfo
#endif


#ifndef ADL_HTONS
#define ADL_HTONS htons
#endif

#ifndef ADL_HTONL
#define ADL_HTONL htonl
#endif

#ifndef ADL_NTOHS
#define ADL_NTOHS ntohs
#endif

#ifndef ADL_NTOHL
#define ADL_NTOHL ntohl
#endif





bool adl_lib_SocketInit(void);
bool adl_lib_SocketFini(void);
ADL_RESULT adl_sys_socket(int domain,int type,int protocol);
ADL_RESULT adl_sys_socketpair(int domain,int type,int protocol,int sockfds[2]);
ADL_RESULT adl_sys_bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
ADL_RESULT adl_sys_connect(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
ADL_RESULT adl_sys_listen(int sockfd,int backlog);
ADL_RESULT adl_sys_accept(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
ADL_RESULT adl_sys_accept4(int sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags);
ADL_RESULT adl_sys_recv(int sockfd,void *buf,size_t buflen,int flags);
ADL_RESULT adl_sys_recvfrom(int sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen);
ADL_RESULT adl_sys_recvmsg(int sockfd,struct msghdr *msg,int flags);
ADL_RESULT adl_sys_recvmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout);
ADL_RESULT adl_sys_send(int sockfd,const void *buf,size_t buflen,int flags);
ADL_RESULT adl_sys_sendto(int sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen);
ADL_RESULT adl_sys_sendmsg(int sockfd,const struct msghdr *msg,int flags);
ADL_RESULT adl_sys_sendmmsg(int sockfd,struct mmsghdr *msgvec,int vlen,int flags);
ADL_RESULT adl_sys_shutdown(int sockfd,int how);
ADL_RESULT adl_sys_close(int fd);
ADL_RESULT adl_sys_getsockopt(int sockfd,int level,int optname,void *optval,socklen_t *optlen);
ADL_RESULT adl_sys_setsockopt(int sockfd,int level,int optname,void *optval,socklen_t optlen);
ADL_RESULT adl_sys_getsockname(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
ADL_RESULT adl_sys_getpeername(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
ADL_RESULT adl_lib_getaddrinfo(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);
ADL_RESULT adl_lib_freeaddrinfo(struct addrinfo *res);
ADL_RESULT adl_lib_getnameinfo(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,int flags);
ADL_RESULT adl_lib_htons(u16 hostshort);
ADL_RESULT adl_lib_htonl(u32 hostlong);
ADL_RESULT adl_lib_ntohs(u16 netshort);
ADL_RESULT adl_lib_ntohl(u32 netlong);


#endif



#endif

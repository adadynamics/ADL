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








#endif



#endif

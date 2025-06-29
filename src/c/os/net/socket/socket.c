
#include "socket.h"



#ifdef ADL_OS_UNIX

extern ADL_SOCKET_LINUX socket_os;

#elif defined(ADL_OS_WINDOWS)

extern ADL_SOCKET_WINDOWS socket_os;

#endif

void ADL_SOCKET_Init(ADL_SOCKET *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }


    class->socket                      = socket_os.socket;
	class->socketpair                  = socket_os.socketpair;
	class->bind                        = socket_os.bind;
	class->connect                     = socket_os.connect;
	class->listen                      = socket_os.listen;
	class->accept                      = socket_os.accept;
	class->accept4                     = socket_os.accept4;
	class->recv                        = socket_os.recv;
	class->recvfrom                    = socket_os.recvfrom;
	/**
	class->recvmsg                     = socket_os.recvmsg;
	class->recvmmsg                    = socket_os.recvmmsg;
	*/
	class->send                        = socket_os.send;
	class->sendto                      = socket_os.sendto;
	/**
	class->sendmsg                     = socket_os.sendmsg;
	class->sendmmsg                    = socket_os.sendmmsg;
	*/
	class->shutdown                    = socket_os.shutdown;
	class->close                       = socket_os.close;
	class->getsockopt                  = socket_os.getsockopt;
	class->setsockopt                  = socket_os.setsockopt;
	class->getsockname                 = socket_os.getsockname;
	class->getpeername                 = socket_os.getpeername;
	class->getaddrinfo                 = socket_os.getaddrinfo;
	class->freeaddrinfo                = socket_os.freeaddrinfo;
	class->getnameinfo                 = socket_os.getnameinfo;
	class->htons                       = socket_os.htons;
	class->htonl                       = socket_os.htonl;
	class->ntohs                       = socket_os.ntohs;
	class->ntohl                       = socket_os.ntohl;


null_class:
    return;
}

void ADL_SOCKET_Fini(ADL_SOCKET *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

null_class:
    return;
}


ADL_SOCKET adl_socket;

void ADL_SOCKET_library_init()
{
	ADL_SOCKET_Init(&adl_socket);
}
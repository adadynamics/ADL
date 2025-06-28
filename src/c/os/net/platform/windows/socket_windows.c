#include "socket_windows.h"



#ifdef ADL_OS_WINDOWS

extern ADL_WINDOWS adl_os;



void ADL_SOCKET_WINDOWS_Init(ADL_SOCKET_WINDOWS *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    if(ADL_CHECK_EQUAL(adl_os.SocketInit(),false))
    {
        ADL_RETURN_DEFER(failed_socket_init);
    }

    class->socket                      = adl_os.socket;
	class->socketpair                  = adl_os.socketpair;
	class->bind                        = adl_os.bind;
	class->connect                     = adl_os.connect;
	class->listen                      = adl_os.listen;
	class->accept                      = adl_os.accept;
	class->accept4                     = adl_os.accept4;
	class->recv                        = adl_os.recv;
	class->recvfrom                    = adl_os.recvfrom;
	/**
	class->recvmsg                     = adl_os.recvmsg;
	class->recvmmsg                    = adl_os.recvmmsg;
	*/
	class->send                        = adl_os.send;
	class->sendto                      = adl_os.sendto;
	/**
	class->sendmsg                     = adl_os.sendmsg;
	class->sendmmsg                    = adl_os.sendmmsg;
	*/
	class->shutdown                    = adl_os.shutdown;
	class->close                       = adl_os.close;
	class->getsockopt                  = adl_os.getsockopt;
	class->setsockopt                  = adl_os.setsockopt;
	class->getsockname                 = adl_os.getsockname;
	class->getpeername                 = adl_os.getpeername;
	class->getaddrinfo                 = adl_os.getaddrinfo;
	class->freeaddrinfo                = adl_os.freeaddrinfo;
	class->getnameinfo                 = adl_os.getnameinfo;
	class->htons                       = adl_os.htons;
	class->htonl                       = adl_os.htonl;
	class->ntohs                       = adl_os.ntohs;
	class->ntohl                       = adl_os.ntohl;


failed_socket_init:
null_class:
    return;
}

void ADL_SOCKET_WINDOWS_Fini(ADL_SOCKET_WINDOWS *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_SOCKET_WINDOWS));

    adl_os.SocketFini();

null_class:
    return;
}



ADL_SOCKET_WINDOWS socket_os;


void ADL_SOCKET_WINDOWS_library_init()
{
    ADL_SOCKET_WINDOWS_Init(&socket_os);
}



#endif
#ifndef ADL_OS_NET_TCP_TCP_SERVER_H
#define ADL_OS_NET_TCP_TCP_SERVER_H

#include "tcp.h"
#include "../../thread/thread.h"

struct ADL_TCP_SERVER;

typedef struct ADL_TCP_SERVER_HANDLE_CLIENT_ARG
{
    struct ADL_TCP_SERVER *self;
    ADL_SOCKET_DESC client_fd;
    void *(*handle_client)(struct ADL_TCP_SERVER *self,ADL_SOCKET_DESC client_fd);
}ADL_TCP_SERVER_HANDLE_CLIENT_ARG;

typedef ADL_THREAD_RETURN_PARAM (*ADL_TCP_SERVER_HANDLE_CLIENT)(/*ADL_TCP_SERVER_HANDLE_CLIENT_ARG*/ void *arg);

typedef struct ADL_TCP_SERVER
{
    ADL_SOCKET_DESC server_fd;
    ADL_IP_ADDRESS server_address;

    ADL_RESULT (*Listen)(struct ADL_TCP_SERVER *self,ADL_IP_ADDRESS addr,u64 backlog);
    ADL_RESULT (*Serve)(struct ADL_TCP_SERVER *self,void *(*handle_client)(struct ADL_TCP_SERVER *,ADL_SOCKET_DESC));
    ADL_RESULT (*Recv)(struct ADL_TCP_SERVER *self,ADL_SOCKET_DESC client_fd,ADL_NET_MESSAGE message);
    ADL_RESULT (*Send)(struct ADL_TCP_SERVER *self,ADL_SOCKET_DESC client_fd,ADL_NET_MESSAGE message);
    ADL_RESULT (*Close)(struct ADL_TCP_SERVER *self);
}ADL_TCP_SERVER;


void ADL_TCP_SERVER_Init(ADL_TCP_SERVER *class);

void ADL_TCP_SERVER_Fini(ADL_TCP_SERVER *class);


#endif
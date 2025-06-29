#ifndef ADL_OS_NET_TCP_TCP_H
#define ADL_OS_NET_TCP_TCP_H


#include "../socket/socket.h"

typedef struct ADL_IP_ADDRESS
{
    ADL_STRING ip;
    ADL_STRING port;
}ADL_IP_ADDRESS;


typedef struct ADL_NET_MESSAGE
{
    void *buffer;
    u64 buffer_size;
}ADL_NET_MESSAGE;

typedef struct ADL_TCP_CLIENT
{
    ADL_SOCKET_DESC client_fd;
    ADL_IP_ADDRESS server_address;

    ADL_RESULT (*Connect)(struct ADL_TCP_CLIENT *self,ADL_IP_ADDRESS addr);
    ADL_RESULT (*Recv)(struct ADL_TCP_CLIENT *self,ADL_NET_MESSAGE message);
    ADL_RESULT (*Send)(struct ADL_TCP_CLIENT *self,ADL_NET_MESSAGE message);
    ADL_RESULT (*Disconnect)(struct ADL_TCP_CLIENT *self);
}ADL_TCP_CLIENT;



void ADL_IP_ADDRESS_Init(ADL_IP_ADDRESS *class,const char *ip,const char *port);

void ADL_IP_ADDRESS_Fini(ADL_IP_ADDRESS *class);

void ADL_TCP_CLIENT_Init(ADL_TCP_CLIENT *class);

void ADL_TCP_CLIENT_Fini(ADL_TCP_CLIENT *class);





#endif
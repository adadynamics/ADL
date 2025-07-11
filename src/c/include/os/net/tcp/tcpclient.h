#ifndef ADL_OS_NET_TCP_TCP_CLIENT_H
#define ADL_OS_NET_TCP_TCP_CLIENT_H

#include "tcp.h"

typedef struct ADL_TCP_CLIENT
{
    ADL_SOCKET_DESC client_fd;
    ADL_IP_ADDRESS server_address;

    ADL_RESULT (*Connect)(struct ADL_TCP_CLIENT *self,ADL_IP_ADDRESS addr);
    ADL_RESULT (*Recv)(struct ADL_TCP_CLIENT *self,ADL_NET_MESSAGE message);
    ADL_RESULT (*Send)(struct ADL_TCP_CLIENT *self,ADL_NET_MESSAGE message);
    ADL_RESULT (*Disconnect)(struct ADL_TCP_CLIENT *self);
}ADL_TCP_CLIENT;




void ADL_TCP_CLIENT_Init(ADL_TCP_CLIENT *class);

void ADL_TCP_CLIENT_Fini(ADL_TCP_CLIENT *class);





#endif
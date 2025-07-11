#ifndef ADL_SRC_OS_NET_TCP_TCP_CLIENT_H
#define ADL_SRC_OS_NET_TCP_TCP_CLIENT_H


#include "../../../include/os/net/tcp/tcpclient.h"





ADL_RESULT Connect(struct ADL_TCP_CLIENT *self,ADL_IP_ADDRESS addr);
ADL_RESULT Recv(struct ADL_TCP_CLIENT *self,ADL_NET_MESSAGE message);
ADL_RESULT Send(struct ADL_TCP_CLIENT *self,ADL_NET_MESSAGE message);
ADL_RESULT Disconnect(struct ADL_TCP_CLIENT *self);

#endif

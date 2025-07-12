#ifndef ADL_SRC_OS_NET_TCP_TCP_SERVER_H
#define ADL_SRC_OS_NET_TCP_TCP_SERVER_H



#include "../../../include/os/net/tcp/tcpserver.h"


ADL_RESULT Listen(struct ADL_TCP_SERVER *self,ADL_IP_ADDRESS addr,u64 backlog);
ADL_RESULT Serve(struct ADL_TCP_SERVER *self,void *(*handle_client)(ADL_TCP_SERVER *,ADL_SOCKET_DESC));
ADL_RESULT Recv(struct ADL_TCP_SERVER *self,ADL_SOCKET_DESC client_fd,ADL_NET_MESSAGE message);
ADL_RESULT Send(struct ADL_TCP_SERVER *self,ADL_SOCKET_DESC client_fd,ADL_NET_MESSAGE message);
ADL_RESULT Close(struct ADL_TCP_SERVER *self);


#endif
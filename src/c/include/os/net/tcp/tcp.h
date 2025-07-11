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





void ADL_IP_ADDRESS_Init(ADL_IP_ADDRESS *class,const char *ip,const char *port);

void ADL_IP_ADDRESS_Fini(ADL_IP_ADDRESS *class);


#endif
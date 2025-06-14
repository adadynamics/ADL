#include "../socket/socket.h"
#include <linux/if.h>
#include <linux/if_packet.h>



ADL_SOCKET sock;

typedef struct ADL_RAWDEVICE
{
    ADL_SOCKFD sockfd;
    struct ifreq ifr;
    ADL_RESULT (*open)(struct ADL_RAWDEVICE *self,const char *device,u64 protocol);
    ADL_RESULT (*read)(struct ADL_RAWDEVICE *self,void *buf,u64 buflen);
    ADL_RESULT (*write)(struct ADL_RAWDEVICE *self,const void *buf,u64 buflen);
    ADL_RESULT (*close)(struct ADL_RAWDEVICE *self);
}ADL_RAWDEVICE;



void ADL_RAWDEVICE_init(ADL_RAWDEVICE *raw);

void ADL_RAWDEVICE_fini(ADL_RAWDEVICE *raw);

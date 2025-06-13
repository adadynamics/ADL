#include "../socket/socket.h"
#include <linux/if.h>
#include <linux/if_packet.h>



ADL_Socket sock;

typedef struct ADL_Raw
{
    ADL_SOCKFD sockfd;
    struct ifreq ifr;
    ADL_Result (*open)(struct ADL_Raw *self,const char *device,u64 protocol);
    ADL_Result (*read)(struct ADL_Raw *self,void *buf,u64 buflen);
    ADL_Result (*write)(struct ADL_Raw *self,const void *buf,u64 buflen);
    ADL_Result (*close)(struct ADL_Raw *self);
}ADL_Raw;



void ADL_Raw_init(ADL_Raw *raw);

void ADL_Raw_fini(ADL_Raw *raw);

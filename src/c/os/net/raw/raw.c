#include "../../../include/os/net/raw/raw.h"


ADL_Result adl_raw_create(ADL_Raw *self,u64 protocol)
{
    ADL_Result rdr_res = (ADL_Result){};
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    rdr_res = sock.socket(PF_PACKET,SOCK_RAW,ADL_RESULT_READ_CODE(sock.htons(protocol)));
    self->sockfd = ADL_RESULT_READ_CODE(rdr_res);

null_self:
    return rdr_res;
}



void adl_raw_get_interface_index(ADL_Raw *self,struct ifreq ifr)
{
    ioctl(self->sockfd,SIOCGIFINDEX,&ifr);
    return;
}




void adl_raw_set_promisc(ADL_Raw *self,struct ifreq ifr)
{
    ioctl(self->sockfd,SIOCGIFFLAGS,&ifr);
    ifr.ifr_flags |= IFF_PROMISC;
    ioctl(self->sockfd,SIOCSIFFLAGS,&ifr);
}


void adl_raw_unset_promisc(ADL_Raw *self,struct ifreq ifr)
{
    ioctl(self->sockfd,SIOCGIFFLAGS,&ifr);
    ifr.ifr_flags &= ~IFF_PROMISC;
    ioctl(self->sockfd,SIOCSIFFLAGS,&ifr);
}



ADL_Result adl_raw_bind(ADL_Raw *self,struct ifreq ifr,u32 protocol)
{
    struct sockaddr_ll sll;
    ADL_MEMSET(&sll,0,sizeof(sll));

    sll.sll_ifindex   = ifr.ifr_ifindex;
    sll.sll_family    = AF_PACKET;
    sll.sll_protocol  = ADL_RESULT_READ_CODE(sock.htons(protocol));

    return sock.bind(self->sockfd,(struct sockaddr *)&sll,sizeof(sll));
}


ADL_Result adl_raw_destroy(ADL_Raw *self)
{
    return sock.close(self->sockfd);
}






ADL_Result adl_raw_open(ADL_Raw *self,const char *device,u64 protocol)
{
    ADL_Result res = (ADL_Result){};
    res = adl_raw_create(self,protocol);
    if(ADL_RESULT_CHECK_ERROR(res))
    {
        ADL_RETURN_DEFER(failed_call);
    }

    ADL_RESULT_FINI(res);

    ADL_STRNCPY(self->ifr.ifr_name,device,IFNAMSIZ);
    adl_raw_get_interface_index(self,self->ifr);
    adl_raw_set_promisc(self,self->ifr);

    return adl_raw_bind(self,self->ifr,protocol);

failed_call:
    return res;
}



ADL_Result adl_raw_read(ADL_Raw *self,void *buf,u64 buflen)
{
    return sock.recvfrom(self->sockfd,buf,buflen,0,NULL,NULL);
}



ADL_Result adl_raw_write(ADL_Raw *self,const void *buf,u64 buflen)
{
    return sock.sendto(self->sockfd,buf,buflen,0,NULL,0);
}



ADL_Result adl_raw_close(ADL_Raw *self)
{
    adl_raw_unset_promisc(self,self->ifr);
    ADL_MEMSET(&self->ifr,0,sizeof(self->ifr));
    return adl_raw_destroy(self);
}





void ADL_Raw_init(ADL_Raw *raw)
{
    ADL_Socket_init(&sock);
    ADL_MEMSET(&raw->ifr,0,sizeof(raw->ifr));
    raw->open    = adl_raw_open;
    raw->read    = adl_raw_read;
    raw->write   = adl_raw_write;
    raw->close   = adl_raw_close;
}

void ADL_Raw_fini(ADL_Raw *raw)
{
    ADL_Socket_fini(&sock);
    ADL_MEMSET(raw,0,sizeof(ADL_Raw));
    return;
}

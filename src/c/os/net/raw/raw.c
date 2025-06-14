#include "../../../include/os/net/raw/raw.h"


ADL_RESULT adl_rawdevice_create(ADL_RAWDEVICE *self,u64 protocol)
{
    ADL_RESULT rdr_res = (ADL_RESULT){};
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    rdr_res = sock.socket(PF_PACKET,SOCK_RAW,ADL_RESULT_READ_CODE(sock.htons(protocol)));
    self->sockfd = ADL_RESULT_READ_CODE(rdr_res);

null_self:
    return rdr_res;
}



void adl_rawdevice_get_interface_index(ADL_RAWDEVICE *self,struct ifreq ifr)
{
    ioctl(self->sockfd,SIOCGIFINDEX,&ifr);
    return;
}




void adl_rawdevice_set_promisc(ADL_RAWDEVICE *self,struct ifreq ifr)
{
    ioctl(self->sockfd,SIOCGIFFLAGS,&ifr);
    ifr.ifr_flags |= IFF_PROMISC;
    ioctl(self->sockfd,SIOCSIFFLAGS,&ifr);
}


void adl_rawdevice_unset_promisc(ADL_RAWDEVICE *self,struct ifreq ifr)
{
    ioctl(self->sockfd,SIOCGIFFLAGS,&ifr);
    ifr.ifr_flags &= ~IFF_PROMISC;
    ioctl(self->sockfd,SIOCSIFFLAGS,&ifr);
}



ADL_RESULT adl_rawdevice_bind(ADL_RAWDEVICE *self,struct ifreq ifr,u32 protocol)
{
    struct sockaddr_ll sll;
    ADL_MEMSET(&sll,0,sizeof(sll));

    sll.sll_ifindex   = ifr.ifr_ifindex;
    sll.sll_family    = AF_PACKET;
    sll.sll_protocol  = ADL_RESULT_READ_CODE(sock.htons(protocol));

    return sock.bind(self->sockfd,(struct sockaddr *)&sll,sizeof(sll));
}


ADL_RESULT adl_rawdevice_destroy(ADL_RAWDEVICE *self)
{
    return sock.close(self->sockfd);
}






ADL_RESULT adl_rawdevice_open(ADL_RAWDEVICE *self,const char *device,u64 protocol)
{
    ADL_RESULT res = (ADL_RESULT){};
    res = adl_rawdevice_create(self,protocol);
    if(ADL_RESULT_CHECK_ERROR(res))
    {
        ADL_RETURN_DEFER(failed_call);
    }

    ADL_RESULT_FINI(res);

    ADL_STRNCPY(self->ifr.ifr_name,device,IFNAMSIZ);
    adl_rawdevice_get_interface_index(self,self->ifr);
    adl_rawdevice_set_promisc(self,self->ifr);

    return adl_rawdevice_bind(self,self->ifr,protocol);

failed_call:
    return res;
}



ADL_RESULT adl_rawdevice_read(ADL_RAWDEVICE *self,void *buf,u64 buflen)
{
    return sock.recvfrom(self->sockfd,buf,buflen,0,NULL,NULL);
}



ADL_RESULT adl_rawdevice_write(ADL_RAWDEVICE *self,const void *buf,u64 buflen)
{
    return sock.sendto(self->sockfd,buf,buflen,0,NULL,0);
}



ADL_RESULT adl_rawdevice_close(ADL_RAWDEVICE *self)
{
    adl_rawdevice_unset_promisc(self,self->ifr);
    ADL_MEMSET(&self->ifr,0,sizeof(self->ifr));
    return adl_rawdevice_destroy(self);
}





void ADL_RAWDEVICE_init(ADL_RAWDEVICE *raw)
{
    ADL_SOCKET_init(&sock);
    ADL_MEMSET(&raw->ifr,0,sizeof(raw->ifr));
    raw->open    = adl_rawdevice_open;
    raw->read    = adl_rawdevice_read;
    raw->write   = adl_rawdevice_write;
    raw->close   = adl_rawdevice_close;
}

void ADL_RAWDEVICE_fini(ADL_RAWDEVICE *raw)
{
    ADL_SOCKET_fini(&sock);
    ADL_MEMSET(raw,0,sizeof(ADL_RAWDEVICE));
    return;
}

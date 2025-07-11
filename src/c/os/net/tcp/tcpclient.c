

#include "tcpclient.h"

extern ADL_SOCKET adl_socket;




ADL_RESULT Connect(struct ADL_TCP_CLIENT *self,ADL_IP_ADDRESS address)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    struct addrinfo hints,*res;
    ADL_MEMSET(&hints,0,sizeof(hints));

    hints.ai_socktype = SOCK_STREAM;

    rdr_res = adl_socket.getaddrinfo(address.ip.str,address.port.str,&hints,&res);
    
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_getaddrinfo);
    }

    rdr_res = adl_socket.socket(res->ai_family,res->ai_socktype,res->ai_protocol);

    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_socket);
    }

    self->client_fd = ADL_RESULT_READ_CODE(rdr_res);

    rdr_res = adl_socket.connect(self->client_fd,res->ai_addr,res->ai_addrlen);

    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_connect);
    }

    self->server_address = address;

    rdr_res = adl_socket.freeaddrinfo(res);


failed_connect:
failed_socket:
failed_getaddrinfo:
null_self:
    return rdr_res;
}


ADL_RESULT Recv(struct ADL_TCP_CLIENT *self,ADL_NET_MESSAGE message)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self) || ADL_CHECK_NULL(message.buffer))
    {
        ADL_RETURN_DEFER(null_self);
    }

    ADL_U64_INIT(numread);
    ADL_U64_INIT(size_tmp);
    ADL_VOID_PTR_INIT(buffer_tmp);

    buffer_tmp = message.buffer;
    size_tmp   = message.buffer_size;

    while(1)
    {
        rdr_res = adl_socket.recv(self->client_fd,buffer_tmp,size_tmp,0);
        numread = ADL_RESULT_READ_CODE(rdr_res);

        if(ADL_RESULT_CHECK_ERROR(rdr_res))
        {
            ADL_RETURN_DEFER(failed_recv);
        }
        else if(ADL_CHECK_EQUAL(numread,0))
        {
            ADL_RETURN_DEFER(success_recv);
        }

        buffer_tmp += numread;
        size_tmp   -= numread;
    }

    rdr_res.code = (s64)(buffer_tmp - message.buffer);

success_recv:
failed_recv:
null_self:
    return rdr_res;
}


ADL_RESULT Send(struct ADL_TCP_CLIENT *self,ADL_NET_MESSAGE message)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self) || ADL_CHECK_NULL(message.buffer))
    {
        ADL_RETURN_DEFER(null_self);
    }

    puts(message.buffer);
    ADL_U64_INIT(numwrite);
    ADL_U64_INIT(size_tmp);
    ADL_VOID_PTR_INIT(buffer_tmp); 

    buffer_tmp = message.buffer;
    size_tmp   = message.buffer_size;

    while(1)
    {
        rdr_res = adl_socket.send(self->client_fd,buffer_tmp,size_tmp,0);
        numwrite = ADL_RESULT_READ_CODE(rdr_res);

        if(ADL_RESULT_CHECK_ERROR(rdr_res))
        {
            ADL_RETURN_DEFER(failed_send);
        }
        else if(ADL_CHECK_EQUAL(numwrite,0))
        {
            ADL_RETURN_DEFER(success_send);
        }

        buffer_tmp += numwrite;
        size_tmp   -= numwrite;
    }

    rdr_res.code = (s64)(buffer_tmp - message.buffer);

success_send:
failed_send:
null_self:
    return rdr_res;
}



ADL_RESULT Disconnect(struct ADL_TCP_CLIENT *self)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    ADL_IP_ADDRESS_Fini(&self->server_address);


    rdr_res = adl_socket.close(self->client_fd);

    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_close);
    }


failed_close:
null_self:
    return rdr_res;
}




void ADL_TCP_CLIENT_Init(ADL_TCP_CLIENT *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class->Connect     = Connect;
    class->Recv        = Recv;
    class->Send        = Send;
    class->Disconnect  = Disconnect;

null_class:
    return;
}

void ADL_TCP_CLIENT_Fini(ADL_TCP_CLIENT *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_TCP_CLIENT));

null_class:
    return;
}



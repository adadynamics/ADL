#include "tcpserver.h"


extern ADL_SOCKET adl_socket;



ADL_RESULT ADL_TCP_SERVER_Listen(struct ADL_TCP_SERVER *self,ADL_IP_ADDRESS addr,u64 backlog)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    struct addrinfo hints,*res;
    ADL_MEMSET(&hints,0,sizeof(hints));

    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE;

    rdr_res = adl_socket.getaddrinfo(addr.ip.str,addr.port.str,&hints,&res);
    
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_getaddrinfo);
    }

    rdr_res = adl_socket.socket(res->ai_family,res->ai_socktype,res->ai_protocol);

    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_socket);
    }

    self->server_fd = ADL_RESULT_READ_CODE(rdr_res);

    rdr_res = adl_socket.bind(self->server_fd,res->ai_addr,res->ai_addrlen);

    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_bind);
    }

    self->server_address = addr;

    rdr_res = adl_socket.freeaddrinfo(res);

    rdr_res = adl_socket.listen(self->server_fd,backlog);

failed_bind:
failed_socket:
failed_getaddrinfo:
null_self:
    return rdr_res;
}

ADL_THREAD_RETURN_PARAM ADL_TCP_SERVER_HandleClient(void *client_arg)
{
	ADL_TCP_SERVER_HANDLE_CLIENT_ARG *arg = (ADL_TCP_SERVER_HANDLE_CLIENT_ARG *)client_arg;
	if(ADL_CHECK_NULL(arg) || ADL_CHECK_NULL(arg->self))
	{
		ADL_RETURN_DEFER(null_client_arg);
	}

	arg->handle_client(arg->self,arg->client_fd);
null_client_arg:
	ADL_THREAD_RETURN(client_arg);
}

ADL_RESULT ADL_TCP_SERVER_Serve(struct ADL_TCP_SERVER *self,void *(*handle_client)(ADL_TCP_SERVER *,ADL_SOCKET_DESC))
{
    ADL_RESULT_INIT(rdr_res);
    puts("HERE");
    
    if(ADL_CHECK_NULL(self) || ADL_CHECK_NULL(handle_client))
    {
        ADL_RETURN_DEFER(null_self);
    }

    ADL_THREAD threads[10] = {0};

    for(int i = 0; i < 10; i++)
    {
        ADL_THREAD_Init(&threads[i]);
    }


    u32 count = 0;

    while(true)
    {
        rdr_res = adl_socket.accept(self->server_fd,NULL,NULL);
        if(ADL_RESULT_CHECK_ERROR(rdr_res))
        {
            ADL_RETURN_DEFER(failed_accept);
        }

        ADL_TCP_SERVER_HANDLE_CLIENT_ARG *client_arg = ADL_CALLOC(1,sizeof(ADL_TCP_SERVER_HANDLE_CLIENT_ARG));
        
        client_arg->self = self;
        client_arg->client_fd = ADL_RESULT_READ_CODE(rdr_res);
        client_arg->handle_client = handle_client;

        
        threads[count].Start(&threads[count],ADL_TCP_SERVER_HandleClient,client_arg);
        //thread.Detach(&thread);
        count = (count + 1) % 10;

    }

failed_accept:
null_self:
    return rdr_res;
}



ADL_RESULT ADL_TCP_SERVER_Recv(struct ADL_TCP_SERVER *self,ADL_SOCKET_DESC client_fd,ADL_NET_MESSAGE message)
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
        if(ADL_CHECK_EQUAL(size_tmp,0))
        {
            break;
        }

        rdr_res = adl_socket.recv(client_fd,buffer_tmp,size_tmp,0);
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


ADL_RESULT ADL_TCP_SERVER_Send(struct ADL_TCP_SERVER *self,ADL_SOCKET_DESC client_fd,ADL_NET_MESSAGE message)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self) || ADL_CHECK_NULL(message.buffer))
    {
        ADL_RETURN_DEFER(null_self);
    }

    ADL_U64_INIT(numwrite);
    ADL_U64_INIT(size_tmp);
    ADL_VOID_PTR_INIT(buffer_tmp); 

    buffer_tmp = message.buffer;
    size_tmp   = message.buffer_size;

    while(1)
    {
        if(ADL_CHECK_EQUAL(size_tmp,0))
        {
            break;
        }

        rdr_res = adl_socket.send(client_fd,buffer_tmp,size_tmp,0);
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



ADL_RESULT ADL_TCP_SERVER_Close(struct ADL_TCP_SERVER *self)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    ADL_IP_ADDRESS_Fini(&self->server_address);


    rdr_res = adl_socket.close(self->server_fd);

    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_close);
    }


failed_close:
null_self:
    return rdr_res;
}



void ADL_TCP_SERVER_Init(ADL_TCP_SERVER *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class->Listen      = ADL_TCP_SERVER_Listen;
    class->Serve       = ADL_TCP_SERVER_Serve;
    class->Recv        = ADL_TCP_SERVER_Recv;
    class->Send        = ADL_TCP_SERVER_Send;
    class->Close       = ADL_TCP_SERVER_Close;
    
null_class:
    return;
}

void ADL_TCP_SERVER_Fini(ADL_TCP_SERVER *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_TCP_SERVER));

null_class:
    return;
}

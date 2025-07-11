#include "tcp.h"



void ADL_IP_ADDRESS_Init(ADL_IP_ADDRESS *class,const char *ip,const char *port)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_STRING_Init(&class->ip,(char *)ip);
    ADL_STRING_Init(&class->port,(char *)port);

null_class:
    return;
}



void ADL_IP_ADDRESS_Fini(ADL_IP_ADDRESS *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_STRING_Fini(&class->ip);
    ADL_STRING_Fini(&class->port);

null_class:
    return;
}
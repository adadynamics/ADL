#include "../include/ds/string.h"


void adl_ds_string_append(void *self,const char *str);
u64 adl_ds_string_length(void *self);
void adl_ds_string_print(void *self);
void adl_ds_string_println(void *self);



void ADL_STRING_Init(ADL_STRING *adl_str,char *str)
{
	if(ADL_CHECK_NULL(adl_str))
	{
		ADL_RETURN_DEFER(null_adl_str);
	}

	ADL_U64_INIT(len);
	len = ADL_STRLEN(str);

	adl_str->size = len + 1;
	adl_str->len  = len;
	adl_str->str  = (char *)ADL_CALLOC(adl_str->size,sizeof(char));
	
	ADL_STRNCPY(adl_str->str,str,len);
	adl_str->str[adl_str->len] = '\0';


	adl_str->append  = adl_ds_string_append;
	adl_str->length	 = adl_ds_string_length;
	adl_str->print 	 = adl_ds_string_print;
	adl_str->println = adl_ds_string_println;

null_adl_str:
	return;
}





void ADL_STRING_Fini(ADL_STRING *adl_str)
{
	if(ADL_CHECK_NULL(adl_str))
	{
		ADL_RETURN_DEFER(null_adl_str);
	}
	
	adl_str->size = 0;
	adl_str->len  = 0;

	if(ADL_CHECK_NOT_NULL(adl_str->str))
	{
		ADL_FREE(adl_str->str);
	}

	adl_str->str  = NULL;

null_adl_str:
	return;
}



void adl_ds_string_append(void *self,const char *str)
{
	if(ADL_CHECK_NULL(self) || ADL_CHECK_NULL(str))
	{
		ADL_RETURN_DEFER(null_data);
	}

	ADL_STRING *self_new = (ADL_STRING *)self;

	ADL_U64_INIT(str_len);
	ADL_U64_INIT(size);
	ADL_U64_INIT(len);
	ADL_U64_INIT(avail_space);
	
	str_len     = ADL_STRLEN(str);
	size        = self_new->size;
	len 	    = self_new->len;
	avail_space = size - len;


	if(ADL_CHECK_LESS_THAN_EQUAL(avail_space,str_len))
	{
		ADL_U64_INIT(bigger);

		bigger = ADL_CHECK_GREATER_THAN(size * 2,size + str_len + 1) ? size * 2 : size + str_len + 1;

		char *ptr = (char *)ADL_REALLOC(self_new->str,bigger);
		
		if(ADL_CHECK_NULL(ptr))
		{
			ADL_RETURN_DEFER(failed_realloc);
		}
		
		self_new->str  = ptr;
		self_new->size = bigger;
	}


	ADL_STRNCPY(self_new->str + len,str,str_len);
	self_new->len += str_len;
	self_new->str[self_new->len] = '\0';

failed_realloc:
null_data:
	return;
}




u64 adl_ds_string_length(void *self)
{
	ADL_U64_INIT(len);

	if(ADL_CHECK_NULL(self))
	{
		ADL_RETURN_DEFER(null_self);
	}

	
	len = ((ADL_STRING *)self)->len;

null_self:
	return len;
}




void adl_ds_string_print(void *self)
{
	if(ADL_CHECK_NULL(self))
	{
		ADL_RETURN_DEFER(null_self);
	}

	ADL_PRINTF("%s",((ADL_STRING *)self)->str);

null_self:
	return;	
}




void adl_ds_string_println(void *self)
{
	if(ADL_CHECK_NULL(self))
	{
		ADL_RETURN_DEFER(null_self);
	}

	ADL_PRINTF("%s\n",((ADL_STRING *)self)->str);

null_self:
	return;
}


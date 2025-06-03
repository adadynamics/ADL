#ifndef ADL_DS_STRING_H
#define ADL_DS_STRING_H


#include "../common/types.h"


typedef struct ADL_String
{
	u64 size;
	u64 len;
	char *str;
	void (*append)(void *self,const char *str);
	u64 (*length)(void *self);
	void (*print)(void *self);
	void (*println)(void *self);
}ADL_String;


void adl_string_init(ADL_String *adl_str,char *str);

void adl_string_fini(ADL_String *adl_str);



#include "../common/utils.h"

#endif

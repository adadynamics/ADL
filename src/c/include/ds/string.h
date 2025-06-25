#ifndef ADL_DS_STRING_H
#define ADL_DS_STRING_H


#include "../common/types.h"


typedef struct ADL_STRING
{
	u64 size;
	u64 len;
	char *str;
	void (*append)(void *self,const char *str);
	u64 (*length)(void *self);
	void (*print)(void *self);
	void (*println)(void *self);
}ADL_STRING;


void ADL_STRING_Init(ADL_STRING *adl_str,char *str);

void ADL_STRING_Fini(ADL_STRING *adl_str);



#include "../common/utils.h"

#endif

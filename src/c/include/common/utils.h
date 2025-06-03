#ifndef ADL_COMMON_UTILS_H
#define ADL_COMMON_UTILS_H


#include <sys/types.h>
#include <stddef.h>
#include "platform.h"
#include "types.h"
#include "error_handling.h"
#include "debug.h"
#include "stdlib.h"
#include "term.h"


#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif




#ifndef ADL_CHECK_NULL
#define ADL_CHECK_NULL(val) (val) == NULL
#endif


#ifndef ADL_CHECK_NOT_NULL
#define ADL_CHECK_NOT_NULL(val) (val) != NULL
#endif




#ifndef ADL_CHECK_EQUAL
#define ADL_CHECK_EQUAL(val1,val2) (val1) == (val2)
#endif



#ifndef ADL_CHECK_NOT_EQUAL
#define ADL_CHECK_NOT_EQUAL(val1,val2) (val1) != (val2)
#endif



#ifndef ADL_CHECK_LESS_THAN
#define ADL_CHECK_LESS_THAN(val1,val2) (val1) < (val2)
#endif



#ifndef ADL_CHECK_LESS_THAN_EQUAL
#define ADL_CHECK_LESS_THAN_EQUAL(val1,val2) (val1) <= (val2)
#endif



#ifndef ADL_CHECK_GREATER_THAN
#define ADL_CHECK_GREATER_THAN(val1,val2) (val1) > (val2)
#endif



#ifndef ADL_CHECK_GREATER_THAN_EQUAL
#define ADL_CHECK_GREATER_THAN_EQUAL(val1,val2) (val1) >= (val2)
#endif




#ifndef ADL_ARRAY_LEN
#define ADL_ARRAY_LEN(arr)  sizeof((arr)) / sizeof((arr)[0])
#endif






#endif

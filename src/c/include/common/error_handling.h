#ifndef ADL_COMMON_ERROR_HANDLING_H
#define ADL_COMMON_ERROR_HANDLING_H



#include "types.h"
#include "../ds/string.h"


typedef struct ADL_Result
{
	u64 code;
	ADL_String str;
	void *ptr;
}ADL_Result;




#ifndef ADL_RESULT_INIT
#define ADL_RESULT_INIT(id)  ADL_Result id = (ADL_Result){}
#endif

#ifndef ADL_RESULT_READ_CODE
#define ADL_RESULT_READ_CODE(res) ((ADL_Result)(res)).code
#endif

#ifndef ADL_RESULT_READ_STRING
#define ADL_RESULT_READ_STRING(res) ((ADL_Result)(res)).str
#endif

#ifndef ADL_RESULT_READ_PTR
#define ADL_RESULT_READ_PTR(res) ((ADL_Result)(res)).ptr
#endif


#ifndef ADL_RESULT_WRITE
#define ADL_RESULT_WRITE(x,y,z) (ADL_Result){.code = (x),.str = (y),.ptr = (z)}  
#endif


#ifndef ADL_RESULT_CHECK_ERROR
#define ADL_RESULT_CHECK_ERROR(res) ADL_CHECK_NOT_EQUAL(((ADL_Result)res).code,0)
#endif


#ifndef ADL_RESULT_RETURN_DEFER_INIT
#define ADL_RESULT_RETURN_DEFER_INIT() ADL_RESULT_INIT(rdr_res)
#endif



#ifndef ADL_RESULT_RETURN_DEFER
#define ADL_RESULT_RETURN_DEFER(label,res) rdr_res = (res); goto label
#endif


#ifndef ADL_RESULT_RETURN_DEFER_FINI
#define ADL_RESULT_RETURN_DEFER_FINI() return rdr_res
#endif



#ifndef ADL_RETURN_DEFER
#define ADL_RETURN_DEFER(label) goto label
#endif



#ifndef ADL_NO_ERRNO
#include <errno.h>
#define ADL_ERRNO_INIT() errno = 0
#endif





#endif

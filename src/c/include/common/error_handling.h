#ifndef ADL_COMMON_ERROR_HANDLING_H
#define ADL_COMMON_ERROR_HANDLING_H



#include "types.h"
#include "../ds/string.h"


typedef struct ADL_RESULT
{
	u64 _errno;
	s64 code;
	ADL_STRING str;
	void *ptr;
}ADL_RESULT;




#ifndef ADL_RESULT_INIT
#define ADL_RESULT_INIT(id)  ADL_RESULT id = (ADL_RESULT){}
#endif


#ifndef ADL_RESULT_FINI
#define ADL_RESULT_FINI(id)  (id)._errno = 0; (id).code = 0; (id).ptr = NULL; ADL_STRING_fini(&(id).str)
#endif


#ifndef ADL_RESULT_READ_ERRNO
#define ADL_RESULT_READ_ERRNO(res) ((ADL_RESULT)(res))._errno
#endif


#ifndef ADL_RESULT_READ_CODE
#define ADL_RESULT_READ_CODE(res) ((ADL_RESULT)(res)).code
#endif

#ifndef ADL_RESULT_READ_STRING
#define ADL_RESULT_READ_STRING(res) ((ADL_RESULT)(res)).str
#endif

#ifndef ADL_RESULT_READ_PTR
#define ADL_RESULT_READ_PTR(res) ((ADL_RESULT)(res)).ptr
#endif


#ifndef ADL_RESULT_WRITE
#define ADL_RESULT_WRITE(w,x,y,z) (ADL_RESULT){._errno = (w),.code = (x),.str = (y),.ptr = (z)}  
#endif


#ifndef ADL_RESULT_CHECK_ERROR
#define ADL_RESULT_CHECK_ERROR(res) ADL_CHECK_EQUAL(((ADL_RESULT)res).code,-1)
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

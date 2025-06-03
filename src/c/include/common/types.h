#ifndef ADL_COMMON_TYPES_H
#define ADL_COMMON_TYPES_H


#ifndef ADL_SYS_TYPES_H


typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long      u64;


typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long        s64;


#else

#include <sys/types.h>
#include <stddef.h>



typedef u_int8_t 	   u8;
typedef u_int16_t 	   u16;
typedef u_int32_t 	   u32;
typedef u_int64_t 	   u64;


typedef int8_t		   s8;
typedef int16_t		   s16;
typedef int32_t 	   s32;
typedef int64_t 	   s64;



#endif


typedef float              f32;
typedef double             f64;

typedef u8 *   u8_ptr;
typedef u16 *  u16_ptr;
typedef u32 *  u32_ptr;
typedef u64 *  u64_ptr;


typedef s8 *   s8_ptr;
typedef s16 *  s16_ptr;
typedef s32 *  s32_ptr;
typedef s64 *  s64_ptr;


typedef f32 *  f32_ptr;
typedef f64 *  f64_ptr;

typedef void * void_ptr;



#ifndef ADL_COMMON_TYPE_INIT
#define ADL_COMMON_TYPE_INIT(type,ident,val) type ident = val 
#endif




#ifndef ADL_U8_INIT
#define ADL_U8_INIT(id) ADL_COMMON_TYPE_INIT(u8,id,0)
#endif


#ifndef ADL_U16_INIT
#define ADL_U16_INIT(id) ADL_COMMON_TYPE_INIT(u16,id,0)
#endif


#ifndef ADL_U32_INIT
#define ADL_U32_INIT(id) ADL_COMMON_TYPE_INIT(u32,id,0)
#endif


#ifndef ADL_U64_INIT
#define ADL_U64_INIT(id) ADL_COMMON_TYPE_INIT(u64,id,0)
#endif











#ifndef ADL_S8_INIT
#define ADL_S8_INIT(id) ADL_COMMON_TYPE_INIT(s8,id,0)
#endif


#ifndef ADL_S16_INIT
#define ADL_S16_INIT(id) ADL_COMMON_TYPE_INIT(s16,id,0)
#endif


#ifndef ADL_S32_INIT
#define ADL_S32_INIT(id) ADL_COMMON_TYPE_INIT(s32,id,0)
#endif


#ifndef ADL_S64_INIT
#define ADL_S64_INIT(id) ADL_COMMON_TYPE_INIT(s64,id,0)
#endif





#ifndef ADL_F32_INIT
#define ADL_F32_INIT(id) ADL_COMMON_TYPE_INIT(f32,id,0)
#endif


#ifndef ADL_F64_INIT
#define ADL_F64_INIT(id) ADL_COMMON_TYPE_INIT(f64,id,0)
#endif




#ifndef ADL_U8_PTR_INIT
#define ADL_U8_PTR_INIT(id) ADL_COMMON_TYPE_INIT(u8_ptr,id,NULL)
#endif


#ifndef ADL_U16_PTR_INIT
#define ADL_U16_PTR_INIT(id) ADL_COMMON_TYPE_INIT(u16_ptr,id,NULL)
#endif


#ifndef ADL_U32_PTR_INIT
#define ADL_U32_PTR_INIT(id) ADL_COMMON_TYPE_INIT(u32_ptr,id,NULL)
#endif


#ifndef ADL_U64_PTR_INIT
#define ADL_U64_PTR_INIT(id) ADL_COMMON_TYPE_INIT(u64_ptr,id,NULL)
#endif









#ifndef ADL_S8_PTR_INIT
#define ADL_S8_PTR_INIT(id) ADL_COMMON_TYPE_INIT(s8_ptr,id,NULL)
#endif


#ifndef ADL_S16_PTR_INIT
#define ADL_S16_PTR_INIT(id) ADL_COMMON_TYPE_INIT(s16_ptr,id,NULL)
#endif


#ifndef ADL_S32_PTR_INIT
#define ADL_S32_PTR_INIT(id) ADL_COMMON_TYPE_INIT(s32_ptr,id,NULL)
#endif


#ifndef ADL_S64_PTR_INIT
#define ADL_S64_PTR_INIT(id) ADL_COMMON_TYPE_INIT(s64_ptr,id,NULL)
#endif




#ifndef ADL_F32_PTR_INIT
#define ADL_F32_PTR_INIT(id) ADL_COMMON_TYPE_INIT(f32_ptr,id,NULL)
#endif


#ifndef ADL_F64_PTR_INIT
#define ADL_F64_PTR_INIT(id) ADL_COMMON_TYPE_INIT(f64_ptr,id,NULL)
#endif





#ifndef ADL_VOID_PTR_INIT
#define ADL_VOID_PTR_INIT(id) ADL_COMMON_TYPE_INIT(void_ptr,id,NULL)
#endif










#ifndef ADL_READ_PTR
#define ADL_READ_PTR(type,id) *((type)(id)) 
#endif





#ifndef ADL_READ_U8_PTR
#define ADL_READ_U8_PTR(var) ADL_READ_PTR(u8_ptr,var)
#endif

#ifndef ADL_READ_U16_PTR
#define ADL_READ_U16_PTR(var) ADL_READ_PTR(u16_ptr,var)
#endif

#ifndef ADL_READ_U32_PTR
#define ADL_READ_U32_PTR(var) ADL_READ_PTR(u32_ptr,var)
#endif

#ifndef ADL_READ_U64_PTR
#define ADL_READ_U64_PTR(var) ADL_READ_PTR(u64_ptr,var)
#endif









#ifndef ADL_READ_S8_PTR
#define ADL_READ_S8_PTR(var) ADL_READ_PTR(s8_ptr,var)
#endif

#ifndef ADL_READ_S16_PTR
#define ADL_READ_S16_PTR(var) ADL_READ_PTR(s16_ptr,var)
#endif

#ifndef ADL_READ_S32_PTR
#define ADL_READ_S32_PTR(var) ADL_READ_PTR(s32_ptr,var)
#endif

#ifndef ADL_READ_S64_PTR
#define ADL_READ_S64_PTR(var) ADL_READ_PTR(s64_ptr,var)
#endif





#ifndef ADL_WRITE_PTR
#define ADL_WRITE_PTR(type,id,val) *((type)(id)) = (type)(val) 
#endif


#ifndef ADL_WRITE_S8_PTR
#define ADL_WRITE_S8_PTR(id,val) ADL_WRITE_PTR(s8_ptr,id,(val))
#endif

#ifndef ADL_WRITE_S16_PTR
#define ADL_WRITE_S16_PTR(id,val) ADL_WRITE_PTR(s16_ptr,id,(val))
#endif

#ifndef ADL_WRITE_S32_PTR
#define ADL_WRITE_S32_PTR(id,val) ADL_WRITE_PTR(s32_ptr,id,(val))
#endif

#ifndef ADL_WRITE_S64_PTR
#define ADL_WRITE_S64_PTR(id,val) ADL_WRITE_PTR(s64_ptr,id,(val))
#endif








#ifndef ADL_WRITE_U8_PTR
#define ADL_WRITE_U8_PTR(id,val) ADL_WRITE_PTR(u8_ptr,id,(val))
#endif

#ifndef ADL_WRITE_U16_PTR
#define ADL_WRITE_U16_PTR(id,val) ADL_WRITE_PTR(u16_ptr,id,(val))
#endif

#ifndef ADL_WRITE_U32_PTR
#define ADL_WRITE_U32_PTR(id,val) ADL_WRITE_PTR(u32_ptr,id,(val))
#endif

#ifndef ADL_WRITE_U64_PTR
#define ADL_WRITE_U64_PTR(id,val) ADL_WRITE_PTR(u64_ptr,id,(val))
#endif




#endif

#ifndef ADL_OS_FILES_FILE_H
#define ADL_OS_FILES_FILE_H

#include "../os.h"



#if defined(ADL_OS_UNIX)

typedef s32 ADL_FILE_DESC;

#define ADL_FILE_INVALID_HANDLE_VALUE (-1)

#ifndef ADL_FILE_DESC_GET
#define ADL_FILE_DESC_GET(rdr_res) ADL_RESULT_READ_CODE(rdr_res)
#endif

#define ADL_FILE_READ         O_RDONLY
#define ADL_FILE_WRITE    	  O_WRONLY
#define ADL_FILE_RDWR         O_RDWR
#define ADL_FILE_APPEND   	  O_APPEND
#define ADL_FILE_CREATE  	  O_CREAT
#define ADL_FILE_TRUNCATE 	  O_TRUNC



#define ADL_FILE_SEEK_SET         SEEK_SET
#define ADL_FILE_SEEK_CUR         SEEK_CUR
#define ADL_FILE_SEEK_END         SEEK_END



#define ADL_FILE_ACCESS_READ       R_OK
#define ADL_FILE_ACCESS_WRITE      W_OK
#define ADL_FILE_ACCESS_EXECUTE    X_OK
#define ADL_FILE_ACCESS_EXISTS     F_OK




typedef struct iovec ADL_IOVEC;

#elif defined(ADL_OS_WINDOWS)

typedef HANDLE ADL_FILE_DESC;

#define ADL_FILE_INVALID_HANDLE_VALUE INVALID_HANDLE_VALUE

#ifndef ADL_FILE_DESC_GET
#define ADL_FILE_DESC_GET(rdr_res) ADL_RESULT_READ_PTR(rdr_res)
#endif

#define ADL_FILE_READ       _O_RDONLY
#define ADL_FILE_WRITE      _O_WRONLY
#define ADL_FILE_RDWR       _O_RDWR
#define ADL_FILE_APPEND     _O_APPEND
#define ADL_FILE_CREATE     _O_CREAT
#define ADL_FILE_TRUNCATE   _O_TRUNC


#define ADL_FILE_SEEK_SET   FILE_BEGIN
#define ADL_FILE_SEEK_CUR   FILE_CURRENT
#define ADL_FILE_SEEK_END   FILE_END

#define ADL_FILE_ACCESS_EXISTS 	   0 // Check existence
#define ADL_FILE_ACCESS_READ 	   4 // Check read permission
#define ADL_FILE_ACCESS_WRITE 	   2 // Check write permission
#define ADL_FILE_ACCESS_EXECUTE    1 // Check execute permission


typedef struct ADL_IOVEC
{
	void_ptr base;
	u64 len;
}ADL_IOVEC;


#define S_IFDIR 0x4000
#define S_IFREG 0x8000

#define S_ISDIR(x)  (x) & S_IFDIR
#define S_ISREG(x)  (x) & S_IFREG

#define S_IWUSR 0x0100




#endif


typedef enum ADL_FILE_TYPE
{
	ADL_FILE_TYPE_UNKNOWN,
	ADL_FILE_TYPE_REGULAR,
	ADL_FILE_TYPE_DIRECTORY,
#if defined(ADL_OS_UNIX)
	ADL_FILE_TYPE_PIPE,
#endif

}ADL_FILE_TYPE;

#ifdef ADL_OS_TIMESPEC_UNDEFINED
struct timespec 
{
    s64 tv_sec;
    s64 tv_nsec;
};
#endif

typedef struct ADL_STAT 
{
    u64 st_dev;
    u64 st_ino;
    u64 st_mode;
    u64 st_nlink;
    u64 st_uid;
    u64 st_gid;
    u64 st_rdev;
    s64 st_size;
    s64 st_blksize;
    s64 st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
} ADL_STAT;

#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec






typedef struct ADL_FILE_ARGS
{
	u64 flags;
	u64 mode;
	u32 uid;
	u32 gid;

	u32 access;
	void *sa;
	u32 share_mode;
	u32 create;
	u32 attrs_flags;
	ADL_FILE_DESC template;
}ADL_FILE_ARGS;





typedef struct ADL_FILE
{
	ADL_RESULT (*Open)(const char *path,ADL_FILE_ARGS args);
	ADL_RESULT (*Close)(ADL_FILE_DESC fd);
	ADL_RESULT (*Read)(ADL_FILE_DESC fd,void *buf,u64 buf_size);
	ADL_RESULT (*Write)(ADL_FILE_DESC fd,const void *buf,u64 buf_size);
	ADL_RESULT (*ReadAll)(ADL_FILE_DESC fd,void *buf,u64 buf_size);
	ADL_RESULT (*WriteAll)(ADL_FILE_DESC fd,const void *buf,u64 buf_size);


	
	ADL_RESULT (*Seek)(ADL_FILE_DESC fd,s64 offset,s32 origin);
	ADL_RESULT (*Truncate)(const char *path,u64 length);
	ADL_RESULT (*Ftruncate)(ADL_FILE_DESC fd,u64 length);


	
	ADL_RESULT (*Stat)(const char *path,ADL_STAT *info);
	ADL_RESULT (*Fstat)(ADL_FILE_DESC fd,ADL_STAT *info);
	ADL_RESULT (*Lstat)(const char *path,ADL_STAT *info);


	
	ADL_RESULT (*Access)(const char *path,ADL_FILE_ARGS args);
	ADL_RESULT (*Exists)(const char *path);
	ADL_RESULT (*FileType)(const char *path);

	
	ADL_RESULT (*Chmod)(const char *path,ADL_FILE_ARGS args);
	ADL_RESULT (*Fchmod)(ADL_FILE_DESC fd,ADL_FILE_ARGS args);
	ADL_RESULT (*Chown)(const char *path,ADL_FILE_ARGS args);
	ADL_RESULT (*Fchown)(ADL_FILE_DESC fd,ADL_FILE_ARGS args);
	ADL_RESULT (*Lchown)(const char *path,ADL_FILE_ARGS args);



	ADL_RESULT (*HardLink)(const char *linkpath,const char *targetpath,ADL_FILE_ARGS args);
	ADL_RESULT (*SymLink)(const char *linkpath,const char *targetpath,ADL_FILE_ARGS args);
	ADL_RESULT (*ReadLink)(const char *path,void *buf,u64 bufsize);

	ADL_RESULT (*Copy)(const char *dst,const char *src,ADL_FILE_ARGS args);
	ADL_RESULT (*Move)(const char *dst,const char *src,ADL_FILE_ARGS args);

	ADL_RESULT (*Dup)(ADL_FILE_DESC fd1,ADL_FILE_DESC fd2);
	ADL_RESULT (*Delete)(const char *path);


}ADL_FILE;



void ADL_FILE_Init(ADL_FILE *file);

void ADL_FILE_Fini(ADL_FILE *file);


#endif

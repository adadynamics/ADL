#ifndef ADL_OS_FILES_FILE_H
#define ADL_OS_FILES_FILE_H

#include "../os.h"



#if defined(ADL_OS_UNIX)

typedef s32 ADL_FILE_DESC;

#define ADL_FILE_INVALID_HANDLE_VALUE (-1)

#define ADL_FILE_READ         O_RDONLY
#define ADL_FILE_WRITE    	  O_WRONLY
#define ADL_FILE_RDWR         O_RDWR
#define ADL_FILE_APPEND   	  O_APPEND
#define ADL_FILE_CREATE  	  O_CREAT
#define ADL_FILE_TRUNCATE 	  O_TRUNC



#define ADL_FILE_SEEK_SET         SEEK_SET
#define ADL_FILE_SEEK_CUR         SEEK_CUR
#define ADL_FILE_SEEK_END         SEEK_END




typedef struct iovec ADL_IOVEC;

#elif defined(ADL_OS_WINDOWS)

typedef HANDLE ADL_FILE_DESC;

#define ADL_FILE_INVALID_HANDLE_VALUE INVALID_HANDLE_VALUE

#define ADL_FILE_READ       _O_RDONLY
#define ADL_FILE_WRITE      _O_WRONLY
#define ADL_FILE_RDWR       _O_RDWR
#define ADL_FILE_APPEND     _O_APPEND
#define ADL_FILE_CREATE     _O_CREAT
#define ADL_FILE_TRUNCATE   _O_TRUNC


#define ADL_FILE_SEEK_SET   FILE_BEGIN
#define ADL_FILE_SEEK_CUR   FILE_CURRENT
#define ADL_FILE_SEEK_END   FILE_END

typedef struct ADL_IOVEC
{
	void_ptr base;
	u64 len;
}ADL_IOVEC;

#endif



typedef struct ADL_STAT
{
	u64 st_dev;     // dev_t: ID of device containing file
    u64 st_ino;     // ino_t: inode number
    u32 st_mode;    // mode_t: file type and mode
    u32 st_nlink;   // nlink_t: number of hard links
    u32 st_uid;     // uid_t: user ID of owner
    u32 st_gid;     // gid_t: group ID of owner
    u64 st_rdev;    // dev_t: device ID (if special file)
    s64 st_size;    // off_t: total size, in bytes
    s64 st_blksize; // blksize_t: block size for filesystem I/O
    s64 st_blocks;  // blkcnt_t: number of 512B blocks allocated

#ifdef ADL_OS_TIMESPEC_UNDEFINED
    struct timespec {
        s64 tv_sec;   // time_t: seconds
        s64 tv_nsec;  // s64: nanoseconds
    };

#endif

	struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;

	#define st_atime st_atim.tv_sec
	#define st_mtime st_mtim.tv_sec
	#define st_ctime st_ctim.tv_sec

}ADL_STAT;





typedef struct ADL_FILE_ARGS
{
	u64 flags;
	u64 mode;
	u32 uid;
	u32 gid;
}ADL_FILE_ARGS;





typedef struct ADL_FILE
{
	ADL_RESULT (*Open)(const char *path,ADL_FILE_ARGS args);
	ADL_RESULT (*Close)(ADL_FILE_DESC fd);
	ADL_RESULT (*Read)(ADL_FILE_DESC fd,void *buf,u64 buf_size);
	ADL_RESULT (*Write)(ADL_FILE_DESC fd,const void *buf,u64 buf_size);


	ADL_RESULT (*Seek)(ADL_FILE_DESC fd,s64 offset,s32 origin);
	ADL_RESULT (*Truncate)(const char *path,u64 length);
	ADL_RESULT (*Ftruncate)(ADL_FILE_DESC fd,u64 length);


	ADL_RESULT (*Stat)(const char *path,ADL_STAT *info);
	ADL_RESULT (*Fstat)(ADL_FILE_DESC fd,ADL_STAT *info);
	ADL_RESULT (*Lstat)(const char *path,ADL_STAT *info);

	
}ADL_FILE;



void ADL_FILE_init(ADL_FILE *file);

void ADL_FILE_fini(ADL_FILE *file);


#endif

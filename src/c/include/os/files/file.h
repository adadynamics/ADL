#ifndef ADL_OS_FILES_FILE_H
#define ADL_OS_FILES_FILE_H

#include "../os.h"

typedef struct ADL_FILEARGS
{
	u64 flags;
	u64 mode;
}ADL_FILEARGS;


typedef struct ADL_FILE
{
	u64 fd;
	void_ptr handle;
	u64 bytes;
	u64 err_code;
	ADL_STRING err_str;

	void (*create)(struct ADL_FILE *self,const char *name,ADL_FILEARGS args);
	void (*open)(struct ADL_FILE *self,const char *name,ADL_FILEARGS args);
	void (*read)(struct ADL_FILE *self,void_ptr buf,u64 buf_size);
	void (*write)(struct ADL_FILE *self,const void_ptr buf,u64 buf_size);/**
	void (*readv)(struct ADL_FILE *self,const ADL_IOVEC *iov,u64 count);
	void (*writev)(struct ADL_FILE *self,const ADL_IOVEC *iov,u64 count);
	void (*seek)(struct ADL_FILE *self,s64 offset,u64 whence);
	void (*pread)(struct ADL_FILE *self,void_ptr buf,u64 bufsize,u64 offset);
	void (*pwrite)(struct ADL_FILE *self,const void_ptr buf,u64 bufsize,u64 offset);
	void (*preadv)(struct ADL_FILE *self,const ADL_IOVEC *iov,u64 count,u64 offset);
	void (*pwritev)(struct ADL_FILE *self,const ADL_IOVEC *iov,u64 count,u64 offset);
	void (*truncate)(struct ADL_FILE *self,u64 size);
	void (*rename)(struct ADL_FILE *self,const char *name);
	void (*move)(struct ADL_FILE *self,const char *path);
	void (*copy_from_name)(struct ADL_FILE *self,const char *src);
	void (*copy_from)(struct ADL_FILE *self,struct ADL_FILE *src);
	void (*copy_to_name)(struct ADL_FILE *self,const char *dst);
	void (*copy_to)(struct ADL_FILE *self,struct ADL_FILE *dst);
	void (*fdatasync)(struct ADL_FILE *self);
	void (*fsync)(struct ADL_FILE *self);
	void (*sync)(struct ADL_FILE *self);
	void (*stat)(struct ADL_FILE *self,ADL_Stat *buf);
	void (*chmod)(struct ADL_FILE *self,ADL_FILEARGS);
	void (*chown)(struct ADL_FILE *self,ADL_FILEARGS args);
	void (*lchown)(struct ADL_FILE *self,ADL_FILEARGS args);
	void (*get_size)(struct ADL_FILE *self);
	void (*set_size)(struct ADL_FILE *self,u64 size);*/
	void (*close)(struct ADL_FILE *self);
	bool (*check_error)(struct ADL_FILE *self);
	void (*clear_error)(struct ADL_FILE *self);
}ADL_FILE;



void ADL_FILE_init(ADL_FILE *file);

void ADL_FILE_fini(ADL_FILE *file);


#endif

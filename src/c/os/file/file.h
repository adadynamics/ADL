#ifndef ADL_OS_FILE_FILE_H
#define ADL_OS_FILE_FILE_H

#include "../os.h"


typedef struct ADL_FILE
{
	u64 fd;
	void_ptr handle;
	u64 bytes;
	u64 err_code;
	ADL_STRING err_str;
}ADL_FILE;


typedef struct ADL_FILEARGS
{

}ADL_FILEARGS;


void create_file(ADL_FILE *self,const char *name,ADL_FILEARGS args);

void open_file(ADL_FILE *self,ADL_FILEARGS args);

void read_file(ADL_FILE *self,void_ptr buf,u64 buf_size);

void write_file(ADL_FILE *self,const void_ptr buf,u64 buf_size);

void readv_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count);

void writev_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count);

void seek_file(ADL_FILE *self,s64 offset,u64 whence);

void pread_file(ADL_FILE *self,void_ptr buf,u64 bufsize,u64 offset);

void pwrite_file(ADL_FILE *self,const void_ptr buf,u64 bufsize,u64 offset);

void preadv_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count,u64 offset);

void pwritev_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count,u64 offset);

void truncate_file(ADL_FILE *self,u64 size);

void rename_file(ADL_FILE *self,const char *name);

void move_file(ADL_FILE *self,const char *path);

void copy_from_file_name(ADL_FILE *self,const char *src);

void copy_from_file_file(ADL_FILE *self,ADL_FILE *src);

void copy_to_file_name(ADL_FILE *self,const char *dst);

void copy_to_file_file(ADL_FILE *self,ADL_FILE *dst);

void fdatasync_file(ADL_FILE *self);

void fsync_file(ADL_FILE *self);

void sync_file(ADL_FILE *self);

void stat_file(ADL_FILE *self,ADL_Stat *buf);

void chmod_file(ADL_FILE *self,ADL_FILEARGS);

void chown_file(ADL_FILE *self,ADL_FILEARGS args);

void lchown_file(ADL_FILE *self,ADL_FILEARGS args);

void get_size_file(ADL_FILE *self);

void set_size_file(ADL_FILE *self,u64 size);

void close_file(ADL_FILE *self);


#endif

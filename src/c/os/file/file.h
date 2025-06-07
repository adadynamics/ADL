#ifndef ADL_OS_FILE_FILE_H
#define ADL_OS_FILE_FILE_H

#include "../os.h"


typedef struct ADL_File
{
	u64 fd;
	void_ptr handle;
	u64 bytes;
	u64 err_code;
	ADL_String err_str;
}ADL_File;


typedef struct ADL_FileArgs
{

}ADL_FileArgs;


void create_file(ADL_File *self,const char *name,ADL_FileArgs args);

void open_file(ADL_File *self,ADL_FileArgs args);

void read_file(ADL_File *self,void_ptr buf,u64 buf_size);

void write_file(ADL_File *self,const void_ptr buf,u64 buf_size);

void readv_file(ADL_File *self,const ADL_IoVector *iov,u64 count);

void writev_file(ADL_File *self,const ADL_IoVector *iov,u64 count);

void seek_file(ADL_File *self,i64 offset,u64 whence);

void pread_file(ADL_File *self,void_ptr buf,u64 bufsize,u64 offset);

void pwrite_file(ADL_File *self,const void_ptr buf,u64 bufsize,u64 offset);

void preadv_file(ADL_File *self,const ADL_IoVector *iov,u64 count,u64 offset);

void pwritev_file(ADL_File *self,const ADL_IoVector *iov,u64 count,u64 offset);

void truncate_file(ADL_File *self,u64 size);

void rename_file(ADL_File *self,const char *name);

void move_file(ADL_File *self,const char *path);

void fdatasync_file(ADL_File *self);

void fsync_file(ADL_File *self);

void sync_file(ADL_File *self);

void stat_file(ADL_File *self,ADL_Stat *buf);

void chmod_file(ADL_File *self,ADL_FileArgs);

void chown_file(ADL_File *self,ADL_FileArgs args);

void lchown_file(ADL_File *self,ADL_FileArgs args);

void close_file(ADL_File *self);


#endif

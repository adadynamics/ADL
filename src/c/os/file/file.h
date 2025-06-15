#ifndef ADL_OS_FILE_FILE_H
#define ADL_OS_FILE_FILE_H

#include "../os.h"
#include "../../include/os/files/file.h"

static void create_file(ADL_FILE *self,const char *name,ADL_FILEARGS args);

static void open_file(ADL_FILE *self,const char *name,ADL_FILEARGS args);

static void read_file(ADL_FILE *self,void_ptr buf,u64 buf_size);

static void write_file(ADL_FILE *self,const void_ptr buf,u64 buf_size);

/**
static void readv_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count);

static void writev_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count);

static void seek_file(ADL_FILE *self,s64 offset,u64 whence);

static void pread_file(ADL_FILE *self,void_ptr buf,u64 bufsize,u64 offset);

static void pwrite_file(ADL_FILE *self,const void_ptr buf,u64 bufsize,u64 offset);

static void preadv_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count,u64 offset);

static void pwritev_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count,u64 offset);

static void truncate_file(ADL_FILE *self,u64 size);

static void rename_file(ADL_FILE *self,const char *name);

static void move_file(ADL_FILE *self,const char *path);

static void copy_from_file_name(ADL_FILE *self,const char *src);

static void copy_from_file_file(ADL_FILE *self,ADL_FILE *src);

static void copy_to_file_name(ADL_FILE *self,const char *dst);

static void copy_to_file_file(ADL_FILE *self,ADL_FILE *dst);

static void fdatasync_file(ADL_FILE *self);

static void fsync_file(ADL_FILE *self);

static void sync_file(ADL_FILE *self);

static void stat_file(ADL_FILE *self,ADL_Stat *buf);

static void chmod_file(ADL_FILE *self,ADL_FILEARGS);

static void chown_file(ADL_FILE *self,ADL_FILEARGS args);

static void lchown_file(ADL_FILE *self,ADL_FILEARGS args);

static u64 get_size_file(ADL_FILE *self);

static void set_size_file(ADL_FILE *self,u64 size);
*/

static void close_file(ADL_FILE *self);

static bool check_error_file(ADL_FILE *self);

static void clear_error_file(ADL_FILE *self);


#endif

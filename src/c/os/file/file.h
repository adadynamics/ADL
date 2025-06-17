#ifndef ADL_OS_FILE_FILE_H
#define ADL_OS_FILE_FILE_H


#include "../../include/os/files/file.h"
#include "file_linux.h"

/*

static ADL_RESULT create_file_v2(const char *name,ADL_FILE_ARGS args);
static ADL_RESULT delete_file_v2(const char *name);
static ADL_RESULT open_file_v2(const char *name,ADL_FILE_ARGS args);
static ADL_RESULT read_file_v1(ADL_FILE_DESC fd,void_ptr buf,u64 buf_size);
static ADL_RESULT write_file_v1(ADL_FILE_DESC fd,const void_ptr buf,u64 buf_size);

static ADL_RESULT read_all_file_v1(ADL_FILE_DESC fd,void_ptr buf,u64 buf_size);
static ADL_RESULT write_all_file_v1(ADL_FILE_DESC fd,const void_ptr buf,u64 buf_size);


static ADL_RESULT readv_file_v1(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count);
static ADL_RESULT writev_file_v1(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count);
static ADL_RESULT seek_file_v1(ADL_FILE_DESC fd,s64 offset,u64 whence);
static ADL_RESULT pread_file_v1(ADL_FILE_DESC fd,void_ptr buf,u64 buf_size,u64 offset);
static ADL_RESULT pwrite_file_v1(ADL_FILE_DESC fd,const void_ptr buf,u64 buf_size,u64 offset);
static ADL_RESULT preadv_file_v1(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count,u64 offset);
static ADL_RESULT pwritev_file_v1(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count,u64 offset);
static ADL_RESULT truncate_file_v1(ADL_FILE_DESC fd,u64 size);
static ADL_RESULT truncate_file_v2(const char *name,u64 size);
static ADL_RESULT rename_file_v2(const char *oldname,const char *newname);
static ADL_RESULT move_file_v2(const char *oldname,const char *newname);
static ADL_RESULT fdatasync_file_v1(ADL_FILE_DESC fd);
static ADL_RESULT fsync_file_v1(ADL_FILE_DESC fd);
static ADL_RESULT sync_file_v1(void);
static ADL_RESULT stat_file_v1(ADL_FILE_DESC fd,ADL_STAT *buf);
static ADL_RESULT stat_file_v2(const char *name,ADL_STAT *buf);
static ADL_RESULT stat_file_v3(const char *name,ADL_STAT *buf);
static ADL_RESULT chmod_file_v1(ADL_FILE_DESC fd,ADL_FILE_ARGS args);
static ADL_RESULT chmod_file_v2(const char *name,ADL_FILE_ARGS args);
static ADL_RESULT chown_file_v1(ADL_FILE_DESC fd,ADL_FILE_ARGS args);
static ADL_RESULT chown_file_v2(const char *name,ADL_FILE_ARGS args);
static ADL_RESULT chown_file_v3(const char *name,ADL_FILE_ARGS args);
static ADL_RESULT get_size_file_v1(ADL_FILE_DESC fd);
static ADL_RESULT get_size_file_v2(const char *name);
static ADL_RESULT set_size_file_v1(ADL_FILE_DESC fd,u64 size);
static ADL_RESULT set_size_file_v2(const char *name,u64 size);
static ADL_RESULT close_file_v1(ADL_FILE_DESC fd);

*/


#endif

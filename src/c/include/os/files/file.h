#ifndef ADL_OS_FILES_FILE_H
#define ADL_OS_FILES_FILE_H

#include "../os.h"




typedef struct ADL_FILE_ARGS
{
	u64 flags;
	u64 mode;
	u32 uid;
	u32 gid;
}ADL_FILE_ARGS;




typedef struct ADL_FILE_DESC
{
	s64 fd;
	void *handle;
}ADL_FILE_DESC;


#ifndef ADL_FILE_DESC_INIT
#define ADL_FILE_DESC_INIT(id)  ADL_FILE_DESC id = (ADL_FILE_DESC){.fd = -1,.handle = NULL}
#endif




typedef struct ADL_FILE
{
	ADL_RESULT (*create_v2)(const char *name,ADL_FILE_ARGS args);
	ADL_RESULT (*delete_v2)(const char *name);
	ADL_RESULT (*open_v2)(const char *name,ADL_FILE_ARGS args);
	ADL_RESULT (*set_desc)(ADL_FILE_DESC *desc,ADL_RESULT res);
	ADL_RESULT (*read_v1)(ADL_FILE_DESC fd,void_ptr buf,u64 buf_size);
	ADL_RESULT (*write_v1)(ADL_FILE_DESC fd,const void_ptr buf,u64 buf_size);
	ADL_RESULT (*read_all_v1)(ADL_FILE_DESC fd,void_ptr buf,u64 buf_size);
	ADL_RESULT (*write_all_v1)(ADL_FILE_DESC fd,const void_ptr buf,u64 buf_size);
	
	ADL_RESULT (*readv_v1)(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count);
	ADL_RESULT (*writev_v1)(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count);
	ADL_RESULT (*seek_v1)(ADL_FILE_DESC fd,s64 offset,u64 whence);
	ADL_RESULT (*pread_v1)(ADL_FILE_DESC fd,void_ptr buf,u64 buf_size,u64 offset);
	ADL_RESULT (*pwrite_v1)(ADL_FILE_DESC fd,const void_ptr buf,u64 buf_size,u64 offset);
	ADL_RESULT (*preadv_v1)(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count,u64 offset);
	ADL_RESULT (*pwritev_v1)(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count,u64 offset);
	ADL_RESULT (*truncate_v1)(ADL_FILE_DESC fd,u64 size);
	ADL_RESULT (*truncate_v2)(const char *name,u64 size);
	ADL_RESULT (*rename_v2)(const char *oldname,const char *newname);
	ADL_RESULT (*move_v2)(const char *oldname,const char *newname);
	ADL_RESULT (*fdatasync_v1)(ADL_FILE_DESC fd);
	ADL_RESULT (*fsync_v1)(ADL_FILE_DESC fd);
	ADL_RESULT (*sync_v1)(void);
	ADL_RESULT (*stat_v1)(ADL_FILE_DESC fd,ADL_STAT *buf);
	ADL_RESULT (*stat_v2)(const char *name,ADL_STAT *buf);
	ADL_RESULT (*stat_v3)(const char *name,ADL_STAT *buf);
	ADL_RESULT (*chmod_v1)(ADL_FILE_DESC fd,ADL_FILE_ARGS args);
	ADL_RESULT (*chmod_v2)(const char *name,ADL_FILE_ARGS args);
	ADL_RESULT (*chown_v1)(ADL_FILE_DESC fd,ADL_FILE_ARGS args);
	ADL_RESULT (*chown_v2)(const char *name,ADL_FILE_ARGS args);
	ADL_RESULT (*chown_v3)(const char *name,ADL_FILE_ARGS args);
	ADL_RESULT (*get_size_v1)(ADL_FILE_DESC fd);
	ADL_RESULT (*get_size_v2)(const char *name);
	ADL_RESULT (*set_size_v1)(ADL_FILE_DESC fd,u64 size);
	ADL_RESULT (*set_size_v2)(const char *name,u64 size);
	ADL_RESULT (*close_v1)(ADL_FILE_DESC fd);
	bool (*check_error)(ADL_RESULT res);
	bool (*print_error)(ADL_RESULT res);
	bool (*clear_error)(ADL_RESULT res);
}ADL_FILE;



void ADL_FILE_init(ADL_FILE *file);

void ADL_FILE_fini(ADL_FILE *file);


#endif

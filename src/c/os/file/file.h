#ifndef ADL_OS_FILE_FILE_H
#define ADL_OS_FILE_FILE_H


#include "../../include/os/file/file.h"
#include "platform/file_linux.h"
#include "platform/file_windows.h"

// Core file operations
file_handle_t file_open(const char *path, int flags, int mode);
int file_close(file_handle_t handle);
ssize_t file_read(file_handle_t handle, void *buffer, size_t count);
ssize_t file_write(file_handle_t handle, const void *buffer, size_t count);
int64_t file_seek(file_handle_t handle, int64_t offset, int origin);
int file_truncate(file_handle_t handle, int64_t length);

//file_readv/writev
//file_pread/pwrite
//file_sync
//file_datasync
//file_sync_all
//file_truncate
//file_size
//file_attributes

// File metadata
int file_stat(const char *path, file_stat_t *info);
int file_fstat(file_handle_t handle, file_stat_t *info);
int file_exists(const char *path);
int file_is_dir(const char *path);
int file_chmod(const char *path, int mode);
int file_chown(const char *path, int uid, int gid);

// File utility operations
int file_copy(const char *src, const char *dst);
int file_move(const char *src, const char *dst);
int file_remove(const char *path);
int file_mkdir(const char *path, int mode);
int file_rmdir(const char *path);

// Symbolic/hard links
int file_symlink(const char *target, const char *linkpath);
int file_readlink(const char *path, char *buf, size_t bufsiz);
int file_hardlink(const char *existing, const char *newlink);

// Path utilities
int file_realpath(const char *path, char *resolved, size_t size);
int file_basename(const char *path, char *name, size_t size);
int file_dirname(const char *path, char *dir, size_t size);
int file_join_path(char *out, size_t size, const char *base, const char *append);
int file_is_absolute(const char *path);

// Temporary files
int file_tempfile(char *out_path, size_t size);
int file_tempdir(char *out_path, size_t size);

// Directory operations
file_dir_t *file_opendir(const char *path);
file_dirent_t *file_readdir(file_dir_t *dir);
int file_closedir(file_dir_t *dir);

// File locking (optional)
int file_lock(file_handle_t handle, int mode);  // 0 = shared, 1 = exclusive
int file_unlock(file_handle_t handle);

// File memory mapping (optional)
void *file_map(file_handle_t handle, size_t length, int prot, int flags);
int file_unmap(void *addr, size_t length);

// File descriptor utilities
int file_dup(file_handle_t handle);
int file_is_tty(file_handle_t handle);
int file_set_blocking(file_handle_t handle, int blocking);

// Timestamps
int file_get_times(const char *path, file_times_t *times);
int file_set_times(const char *path, const file_times_t *times);



#endif



#endif


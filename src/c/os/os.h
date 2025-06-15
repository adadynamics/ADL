#ifndef ADL_OS_H
#define ADL_OS_H

#define ADL_OS_UNIX
#if defined(ADL_OS_UNIX)

#include "../include/unix/unix.h"
#include <linux/if.h>


typedef struct iovec ADL_IOVEC;

#ifndef ADL_UNIX_BEGIN
#define ADL_UNIX_BEGIN #ifdef ADL_OS_UNIX
#endif

#ifndef ADL_UNIX_END
#define ADL_UNIX_END #endif
#endif

#else
#if defined(ADL_OS_WINDOWS)

#include "../include/windows/windows.h"

typedef struct ADL_IOVEC
{
	void_ptr base;
	u64 len;
}ADL_IOVEC;

#endif

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

#ifndef ADL_OS_UNIX
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



void ADL_Os_library_init();

#endif

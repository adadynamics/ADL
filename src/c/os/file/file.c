
#include "file.h"

#define ADL_OS_WINDOWS
#ifdef ADL_OS_UNIX

extern ADL_FILE_LINUX file_os;

#elif defined(ADL_OS_WINDOWS)

extern ADL_FILE_WINDOWS file_os;

#endif





ADL_RESULT Open(const char *path,ADL_FILE_ARGS args)
{

#if defined(ADL_OS_UNIX)
	return file_os.open(path,args1.flags,args.mode);
#elif defined(ADL_OS_WINDOWS)
	return file_os.CreateFile(path,args.access,args.share_mode,args.sa,args.create,args.attrs_flags,args.template);
#endif

}




ADL_RESULT Close(ADL_FILE_DESC fd)
{
#if defined(ADL_OS_UNIX)
	return file_os.close(fd);
#elif defined(ADL_OS_WINDOWS)
	return file_os.CloseHandle(fd);
#endif
}


ADL_RESULT Read(ADL_FILE_DESC fd,void *buf,u64 buf_size)
{
#if defined(ADL_OS_UNIX)
	return file_os.read(fd,buf,buf_size);
#elif defined(ADL_OS_WINDOWS)
	u64 numread = 0;
	ADL_RESULT_INIT(res_tmp);

	res_tmp = file_os.ReadFile(fd,buf,buf_size,(LPDWORD)&numread,NULL);
	if(!ADL_RESULT_CHECK_ERROR(res_tmp))
	{
		res_tmp.code = numread;
	}

	return res_tmp;
		
#endif
}


ADL_RESULT Write(ADL_FILE_DESC fd,const void *buf,u64 buf_size)
{
#if defined(ADL_OS_UNIX)
	return file_os.write(fd,buf,buf_size);
#elif defined(ADL_OS_WINDOWS)
	u64 numwrite = 0;
	ADL_RESULT_INIT(res_tmp);

	res_tmp = file_os.WriteFile(fd,buf,buf_size,(LPDWORD)&numwrite,NULL);
	if(!ADL_RESULT_CHECK_ERROR(res_tmp))
	{
		res_tmp.code = numwrite;
	}

	return res_tmp;
		
#endif
}



ADL_RESULT Seek(ADL_FILE_DESC fd,s64 offset,s32 origin)
{
#if defined(ADL_OS_UNIX)
	return file_os.lseek(fd,offset,origin);
#elif defined(ADL_OS_WINDOWS)
	LARGE_INTEGER pos;
	pos.QuadPart = offset;
	ADL_RESULT_INIT(res_tmp);

	res_tmp = file_os.SetFilePointerEx(fd,pos,&pos,origin);
	if(!ADL_RESULT_CHECK_ERROR(res_tmp))
	{
		res_tmp.code = pos.QuadPart;
	}

	return res_tmp;

#endif
}



ADL_RESULT Truncate(const char *path,u64 length)
{
#if defined(ADL_OS_UNIX)
	return file_os.truncate(path,length);
#elif defined(ADL_OS_WINDOWS)
	
	ADL_FILE_ARGS args;
	ADL_RESULT_INIT(res_tmp);

	res_tmp = Open(path,args);
	if(ADL_RESULT_CHECK_ERROR(res_tmp))
	{
		return res_tmp;
	}

	ADL_FILE_DESC fd = ADL_FILE_DESC_GET(res_tmp);
	res_tmp = Seek(fd,length,ADL_FILE_SEEK_SET);
	if(ADL_RESULT_CHECK_ERROR(res_tmp))
	{
		return res_tmp;
	}

	res_tmp = file_os.SetEndOfFile(fd);
	Close(fd);

	return res_tmp;
#endif
}

ADL_RESULT Ftruncate(ADL_FILE_DESC fd,u64 length)
{
#if defined(ADL_OS_UNIX)
	return file_os.ftruncate(fd,length);
#elif defined(ADL_OS_WINDOWS)
	
	ADL_RESULT_INIT(res_tmp);

	res_tmp = Seek(fd,length,ADL_FILE_SEEK_SET);
	if(ADL_RESULT_CHECK_ERROR(res_tmp))
	{
		return res_tmp;
	}

	res_tmp = file_os.SetEndOfFile(fd);
	Close(fd);

	return res_tmp;
#endif
}



static void windows_filetime_to_timespec(FILETIME ft, struct timespec *ts) 
{
#ifdef ADL_OS_WINDOWS
	ULARGE_INTEGER t;
    t.LowPart = ft.dwLowDateTime;
    t.HighPart = ft.dwHighDateTime;
    t.QuadPart -= 116444736000000000ULL; // Windows epoch -> Unix epoch
    ts->tv_sec  = t.QuadPart / 10000000ULL;
    ts->tv_nsec = (t.QuadPart % 10000000ULL) * 100;
#endif
}

ADL_RESULT Stat(const char *path,ADL_STAT *info)
{
	ADL_RESULT_INIT(rdr_res);
	if(ADL_CHECK_NULL(info))
	{
		rdr_res = ADL_RESULT_WRITE(0,-1,(ADL_STRING){},NULL);
		ADL_RETURN_DEFER(failed_call);
	}

#if defined(ADL_OS_UNIX)
	struct stat sb;

	rdr_res = file_os.stat(path,&sb);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	info->st_dev       = sb.st_dev;
	info->st_ino       = sb.st_ino;
	info->st_mode      = sb.st_mode;
	info->st_nlink     = sb.st_nlink;
	info->st_uid       = sb.st_uid;
	info->st_gid       = sb.st_gid;
	info->st_rdev      = sb.st_rdev;
	info->st_size      = sb.st_size;
	info->st_blksize   = sb.st_blksize;
	info->st_blocks    = sb.st_blocks;
	info->st_atim      = sb.st_atim;
	info->st_mtim      = sb.st_mtim;
	info->st_ctim      = sb.st_ctim;

#elif defined(ADL_OS_WINDOWS)
	
	ADL_FILE_ARGS args;
    rdr_res = Open(path,args);

	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	ADL_FILE_DESC fd = ADL_FILE_DESC_GET(rdr_res);
	rdr_res = Fstat(fd,info);
    Close(fd);
#endif
failed_call:
	return rdr_res;
}


ADL_RESULT Fstat(ADL_FILE_DESC fd,ADL_STAT *info)
{
	ADL_RESULT_INIT(rdr_res);
	if(ADL_CHECK_NULL(info))
	{
		rdr_res = ADL_RESULT_WRITE(0,-1,(ADL_STRING){},NULL);
		ADL_RETURN_DEFER(failed_call);
	}

#if defined(ADL_OS_UNIX)
	struct stat sb;

	rdr_res = file_os.fstat(fd,&sb);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	info->st_dev       = sb.st_dev;
	info->st_ino       = sb.st_ino;
	info->st_mode      = sb.st_mode;
	info->st_nlink     = sb.st_nlink;
	info->st_uid       = sb.st_uid;
	info->st_gid       = sb.st_gid;
	info->st_rdev      = sb.st_rdev;
	info->st_size      = sb.st_size;
	info->st_blksize   = sb.st_blksize;
	info->st_blocks    = sb.st_blocks;
	info->st_atim      = sb.st_atim;
	info->st_mtim      = sb.st_mtim;
	info->st_ctim      = sb.st_ctim;


#elif defined(ADL_OS_WINDOWS)
	
    BY_HANDLE_FILE_INFORMATION info_tmp;
    rdr_res = file_os.GetFileInformationByHandle(fd,&info_tmp);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}



    // Device (volume serial number)
    info->st_dev = (u64)info_tmp.dwVolumeSerialNumber;

    // Inode (combine high + low)
    info->st_ino = ((u64)info_tmp.nFileIndexHigh << 32) | info_tmp.nFileIndexLow;

    // Mode
    info->st_mode = 0;

    if (info_tmp.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
        info->st_mode |= 0x4000; // S_IFDIR
    } else {
        info->st_mode |= 0x8000; // S_IFREG
    }
    if (!(info_tmp.dwFileAttributes & FILE_ATTRIBUTE_READONLY)) {
        info->st_mode |= 0x0100; // S_IWUSR
    }

    // Link count
    info->st_nlink = info_tmp.nNumberOfLinks;

    // UID/GID not supported
    info->st_uid = 0;
    info->st_gid = 0;

    // Special file (rdev)
    info->st_rdev = 0;

    // File size
    info->st_size = ((u64)info_tmp.nFileSizeHigh << 32) | info_tmp.nFileSizeLow;

    // Timestamps
    windows_filetime_to_timespec(info_tmp.ftLastAccessTime, &info->st_atim);
    windows_filetime_to_timespec(info_tmp.ftLastWriteTime, &info->st_mtim);
    windows_filetime_to_timespec(info_tmp.ftCreationTime,     &info->st_ctim);

    // Optional: block size (dummy or from volume info)
    info->st_blksize = 4096;

    // Number of 512-byte blocks
    info->st_blocks = (info->st_size + 511) / 512;
#endif

failed_call:
	return rdr_res;
}


ADL_RESULT Lstat(const char *path,ADL_STAT *info)
{
	ADL_RESULT_INIT(rdr_res);
	if(ADL_CHECK_NULL(info))
	{
		rdr_res = ADL_RESULT_WRITE(0,-1,(ADL_STRING){},NULL);
		ADL_RETURN_DEFER(failed_call);
	}

#if defined(ADL_OS_UNIX)
	struct stat sb;

	rdr_res = file_os.lstat(path,&sb);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	info->st_dev       = sb.st_dev;
	info->st_ino       = sb.st_ino;
	info->st_mode      = sb.st_mode;
	info->st_nlink     = sb.st_nlink;
	info->st_uid       = sb.st_uid;
	info->st_gid       = sb.st_gid;
	info->st_rdev      = sb.st_rdev;
	info->st_size      = sb.st_size;
	info->st_blksize   = sb.st_blksize;
	info->st_blocks    = sb.st_blocks;
	info->st_atim      = sb.st_atim;
	info->st_mtim      = sb.st_mtim;
	info->st_ctim      = sb.st_ctim;

#elif defined(ADL_OS_WINDOWS)
	
	ADL_FILE_ARGS args;
	args.attrs_flags |= FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OPEN_REPARSE_POINT;

    rdr_res = Open(path,args);

	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	ADL_FILE_DESC fd = ADL_FILE_DESC_GET(rdr_res);
	rdr_res = Fstat(fd,info);
    Close(fd);
#endif
failed_call:
	return rdr_res;
}




ADL_RESULT Access(const char *path,ADL_FILE_ARGS args)
{

#if defined(ADL_OS_UNIX)
	return file_os.access(path,args.access);
#elif defined(ADL_OS_WINDOWS)
	    // Check if file exists
	ADL_RESULT_INIT(rdr_res);
	ADL_FILE_ARGS args1;

    rdr_res = file_os.GetFileAttributesA(path);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		return rdr_res;
	}

    if (args.mode == ADL_FILE_ACCESS_EXISTS) {
        return rdr_res; // Exists, no other check
    }

    // Check read access: try to open with GENERIC_READ
    if (args.mode & ADL_FILE_ACCESS_READ)
	{    
		args1.access       = GENERIC_READ;
        args1.share_mode   = FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE;
        args1.sa           = NULL;
        args1.create       = OPEN_EXISTING;
        args1.attrs_flags  = FILE_ATTRIBUTE_NORMAL;
        args1.template     = NULL;
		
		rdr_res = Open(path,args1);

        if (ADL_RESULT_CHECK_ERROR(rdr_res)) 
		{
            return rdr_res;
        }

        Close(ADL_FILE_DESC_GET(rdr_res));
    }

    // Check write access: try to open with GENERIC_WRITE
    if (args.mode & ADL_FILE_ACCESS_WRITE)
	{
		args1.access       = GENERIC_WRITE;
        args1.share_mode   = FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE;
        args1.sa           = NULL;
        args1.create       = OPEN_EXISTING;
        args1.attrs_flags  = FILE_ATTRIBUTE_NORMAL;
        args1.template     = NULL;
		
		rdr_res = Open(path,args1);

        if (ADL_RESULT_CHECK_ERROR(rdr_res)) 
		{
            return rdr_res;
        }

        Close(ADL_FILE_DESC_GET(rdr_res));
    }

    // Check execute permission: Windows does not have explicit execute bits,
    // check file extension as a heuristic.

    if (args.mode & ADL_FILE_ACCESS_EXECUTE) 
	{
        // Get file extension
        const char *ext = ADL_STRRCHR(path, '.');
        if (ADL_CHECK_NULL(ext))
		{
			// No extension = no exec
			rdr_res.code = -1;
			return rdr_res;
		}
        
		if (ADL_CHECK_EQUAL(_STRICMP(ext, ".exe"),0) || ADL_CHECK_EQUAL(_STRICMP(ext, ".bat"),0) ||ADL_CHECK_EQUAL(_STRICMP(ext, ".cmd"),0) ||ADL_CHECK_EQUAL(_STRICMP(ext, ".com"),0))
		{
            rdr_res.code = 0;
			return rdr_res;
        } 

        // Not executable extension
		rdr_res.code = -1;
    }

    return rdr_res;
#endif

}


ADL_RESULT Exists(const char *path)
{
	ADL_RESULT_INIT(rdr_res);
	ADL_FILE_ARGS args = {};
	args.access = ADL_FILE_ACCESS_EXISTS;
	return Access(path,args);
}


ADL_RESULT FileType(const char *path);


ADL_RESULT Chmod(const char *path,ADL_FILE_ARGS args);
ADL_RESULT Fchmod(ADL_FILE_DESC fd,ADL_FILE_ARGS args);
ADL_RESULT Chown(const char *path,ADL_FILE_ARGS args);
ADL_RESULT Fchown(ADL_FILE_DESC fd,ADL_FILE_ARGS args);
ADL_RESULT Lchown(const char *path,ADL_FILE_ARGS args);



ADL_RESULT HardLink(const char *linkpath,const char *targetpath,ADL_FILE_ARGS args)
{
#if defined(ADL_OS_UNIX)
	return file_os.link(targetpath,linkpath);
#elif defined(ADL_OS_WINDOWS)
	return file_os.CreateHardLink(linkpath,targetpath,args.sa);
#endif
}


ADL_RESULT SymLink(const char *linkpath,const char *targetpath,ADL_FILE_ARGS args)
{
#if defined(ADL_OS_UNIX)
	return file_os.symlink(targetpath,linkpath);
#elif defined(ADL_OS_WINDOWS)
	return file_os.CreateSymbolicLink(linkpath,targetpath,args.flags);
#endif
}



#ifdef _WIN32
// Windows implementation
#include <windows.h>
#include <winnt.h>
#include <stdio.h>

#define MAX_REPARSE_SIZE (16 * 1024)

int read_symlink(const char *path, char *target_buf, size_t buf_size) {
    wchar_t wpath[MAX_PATH];
    MultiByteToWideChar(CP_UTF8, 0, path, -1, wpath, MAX_PATH);

    HANDLE h = CreateFileW(
        wpath,
        0,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_OPEN_REPARSE_POINT | FILE_FLAG_BACKUP_SEMANTICS,
        NULL
    );

    if (h == INVALID_HANDLE_VALUE) {
        return -1;
    }

    BYTE reparse_buf[MAX_REPARSE_SIZE];
    DWORD bytes_returned;

    BOOL success = DeviceIoControl(
        h,
        FSCTL_GET_REPARSE_POINT,
        NULL, 0,
        reparse_buf, sizeof(reparse_buf),
        &bytes_returned,
        NULL
    );

    CloseHandle(h);

    if (!success) {
        return -1;
    }

    // Cast the buffer to REPARSE_DATA_BUFFER
    REPARSE_DATA_BUFFER *rdb = (REPARSE_DATA_BUFFER *)reparse_buf;

    WCHAR *target = NULL;
    USHORT target_len = 0;

    if (rdb->ReparseTag == IO_REPARSE_TAG_SYMLINK) {
        target = rdb->SymbolicLinkReparseBuffer.PathBuffer +
                 (rdb->SymbolicLinkReparseBuffer.PrintNameOffset / sizeof(WCHAR));
        target_len = rdb->SymbolicLinkReparseBuffer.PrintNameLength / sizeof(WCHAR);
    } else if (rdb->ReparseTag == IO_REPARSE_TAG_MOUNT_POINT) {
        target = rdb->MountPointReparseBuffer.PathBuffer +
                 (rdb->MountPointReparseBuffer.PrintNameOffset / sizeof(WCHAR));
        target_len = rdb->MountPointReparseBuffer.PrintNameLength / sizeof(WCHAR);
    } else {
        return -1;  // Not a recognized reparse type
    }

    // Convert to UTF-8
    int len = WideCharToMultiByte(CP_UTF8, 0, target, target_len, target_buf, (int)buf_size - 1, NULL, NULL);
    if (len <= 0) return -1;

    target_buf[len] = '\0';
    return len;
}

#else
// Unix implementation
#include <unistd.h>
#include <errno.h>
#include <string.h>

int read_symlink(const char *path, char *target_buf, size_t buf_size) {
    ssize_t len = readlink(path, target_buf, buf_size - 1);
    if (len == -1) return -1;
    target_buf[len] = '\0';
    return (int)len;
}
#endif


ADL_RESULT ReadLink(const char *path,void *buf,u64 bufsize)
{
	ADL_RESULT_INIT(rdr_res);
	ADL_S32_INIT(ret);

	ret = read_symlink(path,buf,bufsize);
	if(ADL_CHECK_EQUAL(ret,-1))
	{
		rdr_res = ADL_RESULT_WRITE(errno,-1,(ADL_STRING){},NULL);
	}

	return rdr_res;
}


ADL_RESULT Copy(const char *dst,const char *src,ADL_FILE_ARGS args)
{
}


ADL_RESULT Move(const char *dst,const char *src,ADL_FILE_ARGS args)
{
#if defined(ADL_OS_UNIX)
	return file_os.rename(src,dst);
#elif defined(ADL_OS_WINDOWS)
	return file_os.MoveFileEx(src,dst,args.flags);
#endif
}

ADL_RESULT Dup(ADL_FILE_DESC fd1,ADL_FILE_DESC fd2)
{

}


ADL_RESULT Delete(const char *path)
{
#if defined(ADL_OS_UNIX)
	return file_os.unlink(path);
#elif defined(ADL_OS_WINDOWS)
	return file_os.DeleteFile(path);
#endif
}












ADL_RESULT read_all_file_v1(ADL_FILE_DESC fd,void_ptr buf,u64 buf_size)
{
	ADL_RESULT_INIT(rdr_res);
	ADL_S64_INIT(numread);
	ADL_VOID_PTR_INIT(buf_tmp);
	buf_tmp = buf;

	while(true)
	{
		rdr_res = read_file_v1(fd,buf_tmp,buf_size);
		numread = ADL_RESULT_READ_CODE(rdr_res);
		if(ADL_RESULT_CHECK_ERROR(rdr_res))
		{
			if(ADL_CHECK_EQUAL(ADL_RESULT_READ_ERRNO(rdr_res),EINTR))
			{
				ADL_RESULT_FINI(rdr_res);
				continue;
			}

			ADL_RETURN_DEFER(failed_call);
		}
		else if(ADL_CHECK_EQUAL(numread,0))
		{
			ADL_RETURN_DEFER(success_call);
		}

		buf_tmp   += numread;
		buf_size  -= numread;
	}

success_call:
	rdr_res.code = (s64)(buf_tmp - buf);
failed_call:
	return rdr_res;
}



ADL_RESULT write_all_file_v1(ADL_FILE_DESC fd,const void_ptr buf,u64 buf_size)
{
	ADL_RESULT_INIT(rdr_res);
	ADL_S64_INIT(numwrite);
	ADL_VOID_PTR_INIT(buf_tmp);

	buf_tmp = buf;


	while(true)
	{
		rdr_res = write_file_v1(fd,buf_tmp,buf_size);
		numwrite = ADL_RESULT_READ_CODE(rdr_res);

		if(ADL_RESULT_CHECK_ERROR(rdr_res))
		{
			if(ADL_CHECK_EQUAL(ADL_RESULT_READ_ERRNO(rdr_res),EINTR))
			{
				ADL_RESULT_FINI(rdr_res);
				continue;
			}

			ADL_RETURN_DEFER(failed_call);
		}
		else if(ADL_CHECK_EQUAL(numwrite,0))
		{
			ADL_RETURN_DEFER(success_call);
		}

		buf_tmp   += numwrite;
		buf_size  -= numwrite;
	}

success_call:
	rdr_res.code = (s64)(buf_tmp - buf);
failed_call:
	return rdr_res;
}



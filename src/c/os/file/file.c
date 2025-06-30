
#include "file.h"


#ifdef ADL_OS_UNIX

extern ADL_FILE_LINUX file_os;

#elif defined(ADL_OS_WINDOWS)

extern ADL_FILE_WINDOWS file_os;

#endif



u32 unused_args(ADL_FILE_ARGS args)
{
	return args.flags;
}

ADL_RESULT Open(const char *path,ADL_FILE_ARGS args)
{

#if defined(ADL_OS_UNIX)
	return file_os.open(path,args.flags,args.mode);
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





ADL_RESULT ReadAll(ADL_FILE_DESC fd,void *buf,u64 buf_size)
{
    ADL_RESULT_INIT(rdr_res);
    ADL_U64_INIT(numread);
    ADL_U64_INIT(size_tmp);
    ADL_VOID_PTR_INIT(buffer_tmp);

    buffer_tmp = buf;
    size_tmp   = buf_size;

    while(1)
    {
        rdr_res = Read(fd,buffer_tmp,size_tmp);
        numread = ADL_RESULT_READ_CODE(rdr_res);

        if(ADL_RESULT_CHECK_ERROR(rdr_res))
        {
            ADL_RETURN_DEFER(failed_read);
        }
        else if(ADL_CHECK_EQUAL(numread,0))
        {
            ADL_RETURN_DEFER(success_read);
        }

        buffer_tmp += numread;
        size_tmp   -= numread;
    }

    rdr_res.code = (s64)(buffer_tmp - buf);

success_read:
failed_read:
    return rdr_res;
}



ADL_RESULT WriteAll(ADL_FILE_DESC fd,const void *buf,u64 buf_size)
{
    ADL_RESULT_INIT(rdr_res);
    ADL_U64_INIT(numwrite);
    ADL_U64_INIT(size_tmp);
    ADL_VOID_PTR_INIT(buffer_tmp);

    buffer_tmp = (char *)buf;
    size_tmp   = buf_size;

    while(1)
    {
        rdr_res = Write(fd,buffer_tmp,size_tmp);
        numwrite = ADL_RESULT_READ_CODE(rdr_res);

        if(ADL_RESULT_CHECK_ERROR(rdr_res))
        {
            ADL_RETURN_DEFER(failed_write);
        }
        else if(ADL_CHECK_EQUAL(numwrite,0))
        {
            ADL_RETURN_DEFER(success_write);
        }

        buffer_tmp += numwrite;
        size_tmp   -= numwrite;
    }

    rdr_res.code = (s64)(buffer_tmp - buf);

success_write:
failed_write:
    return rdr_res;
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


#if defined(ADL_OS_WINDOWS)
static void windows_filetime_to_timespec(FILETIME ft, struct timespec *ts) 
{

	ULARGE_INTEGER t;
    t.LowPart = ft.dwLowDateTime;
    t.HighPart = ft.dwHighDateTime;
    t.QuadPart -= 116444736000000000ULL; // Windows epoch -> Unix epoch
    ts->tv_sec  = t.QuadPart / 10000000ULL;
    ts->tv_nsec = (t.QuadPart % 10000000ULL) * 100;
}

#endif

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
	ADL_FILE_ARGS args = {};
	args.access = ADL_FILE_ACCESS_EXISTS;
	return Access(path,args);
}


ADL_RESULT FileType(const char *path)
{
	ADL_RESULT_INIT(rdr_res);
	ADL_STAT info = {0};
	rdr_res = Stat(path,&info);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	if(S_ISREG(info.st_mode))
	{
		rdr_res.code = ADL_FILE_TYPE_REGULAR;
	}
	else if(S_ISDIR(info.st_mode))
	{
		rdr_res.code = ADL_FILE_TYPE_DIRECTORY;
	}
	else
	{
		rdr_res.code = ADL_FILE_TYPE_UNKNOWN;
	}

failed_call:
	return rdr_res;
}


ADL_RESULT Chmod(const char *path,ADL_FILE_ARGS args);
ADL_RESULT Fchmod(ADL_FILE_DESC fd,ADL_FILE_ARGS args);
ADL_RESULT Chown(const char *path,ADL_FILE_ARGS args);
ADL_RESULT Fchown(ADL_FILE_DESC fd,ADL_FILE_ARGS args);
ADL_RESULT Lchown(const char *path,ADL_FILE_ARGS args);



ADL_RESULT HardLink(const char *linkpath,const char *targetpath,ADL_FILE_ARGS args)
{
#if defined(ADL_OS_UNIX)
	unused_args(args);
	return file_os.link(targetpath,linkpath);
#elif defined(ADL_OS_WINDOWS)
	return file_os.CreateHardLink(linkpath,targetpath,args.sa);
#endif
}


ADL_RESULT SymLink(const char *linkpath,const char *targetpath,ADL_FILE_ARGS args)
{
#if defined(ADL_OS_UNIX)
	unused_args(args);
	return file_os.symlink(targetpath,linkpath);
#elif defined(ADL_OS_WINDOWS)
	return file_os.CreateSymbolicLink(linkpath,targetpath,args.flags);
#endif
}



#ifdef ADL_OS_WINDOWS
#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <string.h>

#define MAX_REPARSE_DATA_BUFFER_SIZE (16 * 1024)

typedef struct
{
    DWORD ReparseTag;
    WORD ReparseDataLength;
    WORD Reserved;
    union
	{
        struct
		{
            WORD SubstituteNameOffset;
            WORD SubstituteNameLength;
            WORD PrintNameOffset;
            WORD PrintNameLength;
            ULONG Flags;
            WCHAR PathBuffer[1];
        } SymbolicLinkReparseBuffer;

        struct
		{
            WORD SubstituteNameOffset;
            WORD SubstituteNameLength;
            WORD PrintNameOffset;
            WORD PrintNameLength;
            WCHAR PathBuffer[1];
        } MountPointReparseBuffer;

        struct
		{
            UCHAR DataBuffer[1];
        } GenericReparseBuffer;
    };
} REPARSE_DATA_BUFFER;

int read_symlink(const char *linkPath, char *targetBuffer, size_t bufferSize)
{
    HANDLE hFile = CreateFileA(
        linkPath,
        0,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_OPEN_REPARSE_POINT | FILE_FLAG_BACKUP_SEMANTICS,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) 
	{
        fprintf(stderr, "Failed to open file: %lu\n", GetLastError());
        return -1;
    }

    BYTE reparseBuffer[MAX_REPARSE_DATA_BUFFER_SIZE];
    DWORD returnedLength;

    if (!DeviceIoControl(
        hFile,
        FSCTL_GET_REPARSE_POINT,
        NULL,
        0,
        reparseBuffer,
        MAX_REPARSE_DATA_BUFFER_SIZE,
        &returnedLength,
        NULL
    )) 
	{
        fprintf(stderr, "DeviceIoControl failed: %lu\n", GetLastError());
        CloseHandle(hFile);
        return -1;
    }

    CloseHandle(hFile);

    REPARSE_DATA_BUFFER *reparseData = (REPARSE_DATA_BUFFER *)reparseBuffer;

    WCHAR *wpathBuffer = NULL;
    USHORT offset = 0, length = 0;

    if (reparseData->ReparseTag == IO_REPARSE_TAG_SYMLINK) 
	{
        offset = reparseData->SymbolicLinkReparseBuffer.SubstituteNameOffset;
        length = reparseData->SymbolicLinkReparseBuffer.SubstituteNameLength;
        wpathBuffer = reparseData->SymbolicLinkReparseBuffer.PathBuffer;
    } else if (reparseData->ReparseTag == IO_REPARSE_TAG_MOUNT_POINT) 
	{
        offset = reparseData->MountPointReparseBuffer.SubstituteNameOffset;
        length = reparseData->MountPointReparseBuffer.SubstituteNameLength;
        wpathBuffer = reparseData->MountPointReparseBuffer.PathBuffer;
    } else 
	{
        fprintf(stderr, "Unsupported reparse tag: 0x%X\n", reparseData->ReparseTag);
        return -1;
    }

    WCHAR wtarget[MAX_PATH];
    wcsncpy(wtarget, wpathBuffer + (offset / sizeof(WCHAR)), length / sizeof(WCHAR));
    wtarget[length / sizeof(WCHAR)] = L'\0';

    // Convert wide string to ANSI
    if (WideCharToMultiByte(CP_ACP, 0, wtarget, -1, targetBuffer, (int)bufferSize, NULL, NULL) == 0) 
	{
        fprintf(stderr, "Failed to convert to ANSI: %lu\n", GetLastError());
        return -1;
    }

    return 0;
}

#elif defined(ADL_OS_UNIX)
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

/*
ADL_RESULT Copy(const char *dst,const char *src,ADL_FILE_ARGS args)
{
	ADL_RESULT_INIT(rdr_res);
	return rdr_res;
}
*/

ADL_RESULT Move(const char *dst,const char *src,ADL_FILE_ARGS args)
{
#if defined(ADL_OS_UNIX)
	unused_args(args);
	return file_os.rename(src,dst);
#elif defined(ADL_OS_WINDOWS)
	return file_os.MoveFileEx(src,dst,args.flags);
#endif
}

/**
ADL_RESULT Dup(ADL_FILE_DESC fd1,ADL_FILE_DESC fd2)
{
	ADL_RESULT_INIT(rdr_res);
	return rdr_res;
}
*/

ADL_RESULT Delete(const char *path)
{
#if defined(ADL_OS_UNIX)
	return file_os.unlink(path);
#elif defined(ADL_OS_WINDOWS)
	return file_os.DeleteFile(path);
#endif
}





void ADL_FILE_Init(ADL_FILE *class)
{
	if(ADL_CHECK_NULL(class))
	{
		ADL_RETURN_DEFER(null_class);
	}

	class->Open          = Open;
	class->Close         = Close;
	class->Read          = Read;
	class->Write         = Write;
	class->ReadAll       = ReadAll;
	class->WriteAll      = WriteAll;

	class->Seek          = Seek;
	class->Truncate      = Truncate;
	class->Ftruncate     = Ftruncate;

	class->Stat          = Stat;
	class->Fstat         = Fstat;
	class->Lstat         = Lstat;

	class->Access        = Access;
	class->Exists        = Exists;
	class->FileType      = FileType;

	class->HardLink      = HardLink;
	class->SymLink       = SymLink;
	class->ReadLink      = ReadLink;
	
	
	class->Move          = Move;
	class->Delete        = Delete;

null_class:
	return;
}

void ADL_FILE_Fini(ADL_FILE *class)
{
	if(ADL_CHECK_NULL(class))
	{
		ADL_RETURN_DEFER(null_class);
	}

	ADL_MEMSET(class,0,sizeof(ADL_FILE));

null_class:
	return;
}

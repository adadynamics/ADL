
#include "file.h"



extern ADL_FILE_LINUX file_linux;


ADL_RESULT create_file_v2(const char *name,ADL_FILE_ARGS args)
{
#ifdef ADL_OS_UNIX
	return file_linux.creat(name,args.mode);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT delete_file_v2(const char *name)
{
#ifdef ADL_OS_UNIX
	return file_linux.unlink(name);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT open_file_v2(const char *name,ADL_FILE_ARGS args)
{
#ifdef ADL_OS_UNIX
	args.flags &= O_CREAT;
	args.mode  = 0;
	return file_linux.open(name,args.flags,args.mode);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}




ADL_RESULT set_desc_file(ADL_FILE_DESC *desc,ADL_RESULT res)
{
	ADL_RESULT_INIT(rdr_res);

	if(ADL_CHECK_NULL(desc))
	{
		rdr_res = ADL_RESULT_WRITE(0,-1,(ADL_STRING){},NULL);	
		ADL_RETURN_DEFER(null_desc);
	}

	desc->fd = ADL_RESULT_READ_CODE(res);
	desc->handle = ADL_RESULT_READ_PTR(res);
	
	
null_desc:
	return rdr_res;
}



ADL_RESULT read_file_v1(ADL_FILE_DESC fd,void_ptr buf,u64 buf_size)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.read(desc,buf,buf_size);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT write_file_v1(ADL_FILE_DESC fd,const void_ptr buf,u64 buf_size)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.write(desc,buf,buf_size);
#else
#ifdef ADL_OS_WINDOWS

#endif
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




ADL_RESULT readv_file_v1(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.readv(desc,iov,count);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}


ADL_RESULT writev_file_v1(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.writev(desc,iov,count);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT seek_file_v1(ADL_FILE_DESC fd,s64 offset,u64 whence)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.lseek(desc,offset,whence);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT pread_file_v1(ADL_FILE_DESC fd,void_ptr buf,u64 buf_size,u64 offset)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.pread(desc,buf,buf_size,offset);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT pwrite_file_v1(ADL_FILE_DESC fd,const void_ptr buf,u64 buf_size,u64 offset)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.pwrite(desc,buf,buf_size,offset);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}


ADL_RESULT preadv_file_v1(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count,u64 offset)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.preadv(desc,iov,count,offset);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT pwritev_file_v1(ADL_FILE_DESC fd,const ADL_IOVEC *iov,u64 count,u64 offset)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.pwritev(desc,iov,count,offset);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}




ADL_RESULT truncate_file_v1(ADL_FILE_DESC fd,u64 size)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.ftruncate(desc,size);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT truncate_file_v2(const char *name,u64 size)
{
#ifdef ADL_OS_UNIX
	return file_linux.truncate(name,size);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT rename_file_v2(const char *oldname,const char *newname)
{
#ifdef ADL_OS_UNIX
	return file_linux.rename(oldname,newname);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT move_file_v2(const char *oldname,const char *newname)
{
	return rename_file_v2(oldname,newname);
}



ADL_RESULT fdatasync_file_v1(ADL_FILE_DESC fd)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.fdatasync(desc);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT fsync_file_v1(ADL_FILE_DESC fd)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.fsync(desc);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT sync_file_v1(void)
{
#ifdef ADL_OS_UNIX
	return file_linux.sync();
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT stat_file_v1(ADL_FILE_DESC fd,ADL_STAT *buf)
{
	ADL_RESULT_INIT(rdr_res);
	if(ADL_CHECK_NULL(buf))
	{
		rdr_res = ADL_RESULT_WRITE(0,-1,(ADL_STRING){},NULL);
		ADL_RETURN_DEFER(failed_call);
	}

#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	struct stat sb;

	rdr_res = file_linux.fstat(desc,&sb);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	buf->st_dev       = sb.st_dev;
	buf->st_ino       = sb.st_ino;
	buf->st_mode      = sb.st_mode;
	buf->st_nlink     = sb.st_nlink;
	buf->st_uid       = sb.st_uid;
	buf->st_gid       = sb.st_gid;
	buf->st_rdev      = sb.st_rdev;
	buf->st_size      = sb.st_size;
	buf->st_blksize   = sb.st_blksize;
	buf->st_blocks    = sb.st_blocks;
	buf->st_atim      = sb.st_atim;
	buf->st_mtim      = sb.st_mtim;
	buf->st_ctim      = sb.st_ctim;

#else
#ifdef ADL_OS_WINDOWS

#endif
#endif

failed_call:
	return rdr_res;
}



ADL_RESULT stat_file_v2(const char *name,ADL_STAT *buf)
{
	ADL_RESULT_INIT(rdr_res);
	if(ADL_CHECK_NULL(buf))
	{
		rdr_res = ADL_RESULT_WRITE(0,-1,(ADL_STRING){},NULL);
		ADL_RETURN_DEFER(failed_call);
	}

#ifdef ADL_OS_UNIX
	struct stat sb;

	rdr_res = file_linux.stat(name,&sb);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	buf->st_dev       = sb.st_dev;
	buf->st_ino       = sb.st_ino;
	buf->st_mode      = sb.st_mode;
	buf->st_nlink     = sb.st_nlink;
	buf->st_uid       = sb.st_uid;
	buf->st_gid       = sb.st_gid;
	buf->st_rdev      = sb.st_rdev;
	buf->st_size      = sb.st_size;
	buf->st_blksize   = sb.st_blksize;
	buf->st_blocks    = sb.st_blocks;
	buf->st_atim      = sb.st_atim;
	buf->st_mtim      = sb.st_mtim;
	buf->st_ctim      = sb.st_ctim;

#else
#ifdef ADL_OS_WINDOWS

#endif
#endif

failed_call:
	return rdr_res;
}



ADL_RESULT stat_file_v3(const char *name,ADL_STAT *buf)
{
	ADL_RESULT_INIT(rdr_res);
	if(ADL_CHECK_NULL(buf))
	{
		rdr_res = ADL_RESULT_WRITE(0,-1,(ADL_STRING){},NULL);
		ADL_RETURN_DEFER(failed_call);
	}

#ifdef ADL_OS_UNIX
	struct stat sb;

	rdr_res = file_linux.lstat(name,&sb);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	buf->st_dev       = sb.st_dev;
	buf->st_ino       = sb.st_ino;
	buf->st_mode      = sb.st_mode;
	buf->st_nlink     = sb.st_nlink;
	buf->st_uid       = sb.st_uid;
	buf->st_gid       = sb.st_gid;
	buf->st_rdev      = sb.st_rdev;
	buf->st_size      = sb.st_size;
	buf->st_blksize   = sb.st_blksize;
	buf->st_blocks    = sb.st_blocks;
	buf->st_atim      = sb.st_atim;
	buf->st_mtim      = sb.st_mtim;
	buf->st_ctim      = sb.st_ctim;

#else
#ifdef ADL_OS_WINDOWS

#endif
#endif

failed_call:
	return rdr_res;
}



ADL_RESULT chmod_file_v1(ADL_FILE_DESC fd,ADL_FILE_ARGS args)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.fchmod(desc,args.mode);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT chmod_file_v2(const char *name,ADL_FILE_ARGS args)
{
#ifdef ADL_OS_UNIX
	return file_linux.chmod(name,args.mode);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT chown_file_v1(ADL_FILE_DESC fd,ADL_FILE_ARGS args)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.fchown(desc,args.uid,args.gid);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT chown_file_v2(const char *name,ADL_FILE_ARGS args)
{
#ifdef ADL_OS_UNIX
	return file_linux.chown(name,args.uid,args.gid);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT chown_file_v3(const char *name,ADL_FILE_ARGS args)
{
#ifdef ADL_OS_UNIX
	return file_linux.lchown(name,args.uid,args.gid);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}



ADL_RESULT get_size_file_v1(ADL_FILE_DESC fd)
{
	ADL_RESULT_INIT(rdr_res);

	ADL_STAT stat_buf;
	rdr_res = stat_file_v1(fd,&stat_buf);

	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	rdr_res.code = stat_buf.st_size;


failed_call:
	return rdr_res;
}





ADL_RESULT get_size_file_v2(const char *name)
{
	ADL_RESULT_INIT(rdr_res);

	ADL_STAT stat_buf;
	rdr_res = stat_file_v2(name,&stat_buf);

	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	rdr_res.code = stat_buf.st_size;


failed_call:
	return rdr_res;
}



ADL_RESULT set_size_file_v1(ADL_FILE_DESC fd,u64 size)
{
	return truncate_file_v1(fd,size);
}



ADL_RESULT set_size_file_v2(const char *name,u64 size)
{
	return truncate_file_v2(name,size);
}



ADL_RESULT close_file_v1(ADL_FILE_DESC fd)
{
#ifdef ADL_OS_UNIX
	u64 desc = fd.fd;
	return file_linux.close(desc);
#else
#ifdef ADL_OS_WINDOWS

#endif
#endif
}


bool check_error_file(ADL_RESULT res)
{
	return ADL_RESULT_CHECK_ERROR(res);
}



bool print_error_file(ADL_RESULT res)
{
	if(ADL_CHECK_NULL(res.str.str))
	{
		ADL_RETURN_DEFER(null_str);
	}

	res.str.println(&res.str);
	return true;

null_str:
	return false;
}




bool clear_error_file(ADL_RESULT res)
{
	ADL_RESULT_FINI(res);
	return true;
}


void ADL_FILE_init(ADL_FILE *file)
{
	if(ADL_CHECK_NULL(file))
	{
		ADL_RETURN_DEFER(null_file);
	}


	file->create_v2     	= create_file_v2;
	file->delete_v2         = delete_file_v2;
	file->open_v2       	= open_file_v2;
	file->set_desc          = set_desc_file;
	file->read_v1       	= read_file_v1;
	file->write_v1      	= write_file_v1;
	file->read_all_v1       = read_all_file_v1;
	file->write_all_v1      = write_all_file_v1;

	file->readv_v1          = readv_file_v1;
	file->writev_v1         = writev_file_v1;
	file->seek_v1           = seek_file_v1;
	file->pread_v1          = pread_file_v1;
	file->pwrite_v1         = pwrite_file_v1;
	file->preadv_v1         = preadv_file_v1;
	file->pwritev_v1        = pwritev_file_v1;
	file->truncate_v1       = truncate_file_v1;
	file->truncate_v2       = truncate_file_v2;
	file->rename_v2         = rename_file_v2;
	file->move_v2           = move_file_v2;
	file->fdatasync_v1      = fdatasync_file_v1;
	file->fsync_v1          = fsync_file_v1;
	file->sync_v1           = sync_file_v1;
	file->stat_v1           = stat_file_v1;
	file->stat_v2           = stat_file_v2;
	file->stat_v3           = stat_file_v3;
	file->chmod_v1          = chmod_file_v1;
	file->chmod_v2          = chmod_file_v2;
	file->chown_v1          = chown_file_v1;
	file->chown_v2          = chown_file_v2;
	file->chown_v3          = chown_file_v3;
	file->get_size_v1       = get_size_file_v1;
	file->get_size_v2       = get_size_file_v2;
	file->set_size_v1       = set_size_file_v1;
	file->set_size_v2       = set_size_file_v2;
	file->close_v1      	= close_file_v1;
	file->check_error       = check_error_file;
	file->print_error       = print_error_file;
	file->clear_error       = clear_error_file;

null_file:
	return;
}




void ADL_FILE_fini(ADL_FILE *file)
{
	if(ADL_CHECK_NULL(file))
	{
		ADL_RETURN_DEFER(null_file);
	}

	ADL_MEMSET(file,0,sizeof(ADL_FILE));

null_file:
	return;
}





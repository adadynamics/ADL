
#include "file.h"


extern ADL_UNIX adl_os;

#ifndef ADL_CONSTRUCTOR_INIT
#define ADL_CONSTRUCTOR_INIT(self)	if(ADL_CHECK_NULL(self) || ADL_CHECK_NOT_EQUAL(self->error_code,0))					\
				      				{																					\
					      				ADL_RETURN_DEFER(null_self);													\
				      				}																					
#endif


#ifndef ADL_CONSTRUCTOR_FINI
#define ADL_CONSTRUCTOR_FINI()		failed_call:																		\
				      				null_self:																			\
					  				success_call:																		\
					  					return;			
#endif


#ifndef ADL_RESET_FILE_SELF
#define ADL_RESET_FILE_SELF(self)         (self)->error_code = 0; (self)->error_string = (ADL_STRING){}; (self)->bytes = 0
#endif






static void create_file(ADL_FILE *self,const char *name,ADL_FILEARGS args)
{

#ifdef ADL_OS_UNIX
	
	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);

	rdr_res = adl_os.open(name,args.flags,args.mode);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	char *name_tmp = (char *)name;
	ADL_STRING_init(&self->name,name_tmp);
	self->fd = ADL_RESULT_READ_CODE(rdr_res);
	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static void open_file(ADL_FILE *self,const char *name,ADL_FILEARGS args)
{

#ifdef ADL_OS_UNIX

		ADL_CONSTRUCTOR_INIT(self);
		ADL_RESET_FILE_SELF(self);
		ADL_RESULT_INIT(rdr_res);
		
		rdr_res = adl_os.open(name,args.flags,args.mode);
		if(ADL_RESULT_CHECK_ERROR(rdr_res))
		{
				self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
				self->error_string = ADL_RESULT_READ_STRING(rdr_res);
				ADL_RETURN_DEFER(failed_call);
		}

		char *name_tmp = (char *)name;
		ADL_STRING_init(&self->name,name_tmp);
		self->fd = ADL_RESULT_READ_CODE(rdr_res);
		ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static void read_file(ADL_FILE *self,void_ptr buf,u64 buf_size)
{

#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESULT_INIT(rdr_res);
	ADL_S64_INIT(numread);

	while(1)
	{
		rdr_res = adl_os.read(self->fd,buf,buf_size);
		numread = ADL_RESULT_READ_CODE(rdr_res);
		if(ADL_RESULT_CHECK_ERROR(rdr_res))
		{
			if(ADL_RESULT_READ_ERRNO(rdr_res) == EINTR)
			{
				ADL_RESULT_FINI(rdr_res);
				continue;
			}

			ADL_RETURN_DEFER(failed_read);
		}
		else if(ADL_CHECK_EQUAL(numread,0))
		{
			ADL_RETURN_DEFER(success_call);
		}

		buf      += numread;
		buf_size -= numread;
	}


	failed_read:
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res);
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
#endif

	ADL_CONSTRUCTOR_FINI();

}



static void write_file(ADL_FILE *self,const void_ptr buf,u64 buf_size)
{

#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESULT_INIT(rdr_res);
	ADL_S64_INIT(numwrite);
	ADL_VOID_PTR_INIT(buf_tmp);

	buf_tmp = buf;

	while(1)
	{
		rdr_res = adl_os.write(self->fd,buf_tmp,buf_size);
		numwrite = ADL_RESULT_READ_CODE(rdr_res);
		if(ADL_RESULT_CHECK_ERROR(rdr_res))
		{
			if(ADL_RESULT_READ_ERRNO(rdr_res) == EINTR)
			{
				ADL_RESULT_FINI(rdr_res);
				continue;
			}

			ADL_RETURN_DEFER(failed_read);
		}
		else if(ADL_CHECK_EQUAL(numwrite,0))
		{
			ADL_RETURN_DEFER(success_call);
		}

		buf_tmp      += numwrite;
		buf_size -= numwrite;
	}


	failed_read:
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res);
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
#endif

	ADL_CONSTRUCTOR_FINI();

}

/**

static void readv_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count)
{

}



static void writev_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count)
{

}

*/

static void seek_file(ADL_FILE *self,s64 offset,u64 whence)
{

#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	
	rdr_res = adl_os.lseek(self->fd,offset,whence);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	self->previous_offset = ADL_RESULT_READ_CODE(rdr_res);
	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static void pread_file(ADL_FILE *self,void_ptr buf,u64 bufsize,u64 offset)
{
#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	ADL_S64_INIT(numread);

	

	while(1)
	{
		rdr_res = adl_os.pread(self->fd,buf,bufsize,offset);
		numread = ADL_RESULT_READ_CODE(rdr_res);

		if(ADL_RESULT_CHECK_ERROR(rdr_res))
		{
			if(ADL_RESULT_READ_ERRNO(rdr_res) == EINTR)
			{
				ADL_RESULT_FINI(rdr_res);
				continue;
			}

			ADL_RETURN_DEFER(failed_read);
		}
		else if(ADL_CHECK_EQUAL(numread,0))
		{
			ADL_RETURN_DEFER(success_call);
		}

		buf       += numread;
		bufsize   -= numread;
		offset    += numread;
	}

	
	failed_read:
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
#endif

	ADL_CONSTRUCTOR_FINI();

}



static void pwrite_file(ADL_FILE *self,const void_ptr buf,u64 bufsize,u64 offset)
{
#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	ADL_S64_INIT(numread);
	ADL_VOID_PTR_INIT(buf_tmp);

	buf_tmp = buf;
	

	while(1)
	{
		rdr_res = adl_os.pread(self->fd,buf_tmp,bufsize,offset);
		numread = ADL_RESULT_READ_CODE(rdr_res);

		if(ADL_RESULT_CHECK_ERROR(rdr_res))
		{
			if(ADL_RESULT_READ_ERRNO(rdr_res) == EINTR)
			{
				ADL_RESULT_FINI(rdr_res);
				continue;
			}

			ADL_RETURN_DEFER(failed_read);
		}
		else if(ADL_CHECK_EQUAL(numread,0))
		{
			ADL_RETURN_DEFER(success_call);
		}

		buf_tmp       += numread;
		bufsize   -= numread;
		offset    += numread;
	}

	
	failed_read:
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
#endif

	ADL_CONSTRUCTOR_FINI();
}


/*
static void preadv_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count,u64 offset)
{

}



static void pwritev_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count,u64 offset)
{

}

*/



static void truncate_file(ADL_FILE *self,u64 size)
{

#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	
	rdr_res = adl_os.ftruncate(self->fd,size);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	self->size = size;
	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static void rename_file(ADL_FILE *self,const char *name)
{

#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	
	rdr_res = adl_os.rename(self->name.str,name);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	
	ADL_STRING_fini(&self->name);
	char *name_tmp = (char *)name;
	ADL_STRING_init(&self->name,name_tmp);
	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static void move_file(ADL_FILE *self,const char *path)
{
	return rename_file(self,path);
}


/*
static void copy_from_file_name(ADL_FILE *self,const char *src)
{

}



static void copy_from_file_file(ADL_FILE *self,ADL_FILE *src)
{

}



static void copy_to_file_name(ADL_FILE *self,const char *dst)
{

}



static void copy_to_file_file(ADL_FILE *self,ADL_FILE *dst)
{

}

*/


static void fdatasync_file(ADL_FILE *self)
{
	
#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	
	rdr_res = adl_os.fdatasync(self->fd);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static void fsync_file(ADL_FILE *self)
{
	
#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	
	rdr_res = adl_os.fsync(self->fd);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}


static void sync_file(ADL_FILE *self)
{
	
#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	
	rdr_res = adl_os.sync();
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static void stat_file(ADL_FILE *self,ADL_STAT *buf)
{
	
#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);

	if(ADL_CHECK_NULL(buf))
	{
		ADL_RETURN_DEFER(failed_call);
	}

	struct stat statbuf;
	
	
	rdr_res = adl_os.fstat(self->fd,&statbuf);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	
	buf->st_dev      = statbuf.st_dev;
	buf->st_ino      = statbuf.st_ino;
	buf->st_mode     = statbuf.st_mode;
	buf->st_nlink    = statbuf.st_nlink;
	buf->st_uid      = statbuf.st_uid;
	buf->st_gid      = statbuf.st_gid;
	buf->st_rdev     = statbuf.st_rdev;
	buf->st_size     = statbuf.st_size;
	buf->st_blksize  = statbuf.st_blksize;
	buf->st_blocks   = statbuf.st_blocks;
	buf->st_atim     = statbuf.st_atim;
	buf->st_mtim     = statbuf.st_mtim;
	buf->st_ctim     = statbuf.st_ctim;

	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static void chmod_file(ADL_FILE *self,ADL_FILEARGS args)
{
	
#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	
	rdr_res = adl_os.fchmod(self->fd,args.mode);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static void chown_file(ADL_FILE *self,ADL_FILEARGS args)
{
	
#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	
	rdr_res = adl_os.fchown(self->fd,args.uid,args.gid);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static void lchown_file(ADL_FILE *self,ADL_FILEARGS args)
{
	
#ifdef ADL_OS_UNIX

	ADL_CONSTRUCTOR_INIT(self);
	ADL_RESET_FILE_SELF(self);
	ADL_RESULT_INIT(rdr_res);
	
	rdr_res = adl_os.lchown(self->name.str,args.uid,args.gid);
	if(ADL_RESULT_CHECK_ERROR(rdr_res))
	{
		self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->error_string = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

	ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}



static u64 get_size_file(ADL_FILE *self)
{
	ADL_CONSTRUCTOR_INIT(self);
	ADL_STAT buf;

	stat_file(self,&buf);
	self->size = buf.st_size;

	return self->size;

null_self:
	return 0;
}



static void set_size_file(ADL_FILE *self,u64 size)
{
	return truncate_file(self,size);
}



static void close_file(ADL_FILE *self)
{

#ifdef ADL_OS_UNIX

		ADL_CONSTRUCTOR_INIT(self);
		ADL_RESULT_INIT(rdr_res);

		ADL_STRING_fini(&self->name);

		rdr_res = adl_os.close(self->fd);
		if(ADL_RESULT_CHECK_ERROR(rdr_res))
		{
				self->error_code  = ADL_RESULT_READ_ERRNO(rdr_res);
				self->error_string = ADL_RESULT_READ_STRING(rdr_res);
				ADL_RETURN_DEFER(failed_call);
		}
		
		ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}





static bool check_error_file(ADL_FILE *self)
{
	ADL_CONSTRUCTOR_INIT(self);
	
	if(ADL_CHECK_EQUAL(self->error_code,0))
	{
		ADL_RETURN_DEFER(success_call);
	}

null_self:
	return false;
success_call:
	return true;
}


static void clear_error_file(ADL_FILE *self)
{
	if(ADL_CHECK_NULL(self))
	{
		ADL_RETURN_DEFER(null_self);
	}

	self->error_code = 0;
	ADL_STRING_fini(&self->error_string);

null_self:
	return;
}






void ADL_FILE_init(ADL_FILE *file)
{
	if(ADL_CHECK_NULL(file))
	{
		ADL_RETURN_DEFER(null_file);
	}

	file->fd         	= 0;
	file->error_code   	= 0;
	file->error_string 		= (ADL_STRING){};
	file->handle     	= NULL;
	file->bytes      	= 0;

	file->create     	= create_file;
	file->open       	= open_file;
	file->read       	= read_file;
	file->write      	= write_file;
	file->seek          = seek_file;
	file->pread         = pread_file;
	file->pwrite        = pwrite_file;
	file->truncate      = truncate_file;
	file->rename        = rename_file;
	file->move          = move_file;
	file->fdatasync     = fdatasync_file;
	file->fsync         = fsync_file;
	file->sync          = sync_file;
	file->stat          = stat_file;
	file->chmod         = chmod_file;
	file->chown         = chown_file;
	file->lchown        = lchown_file;
	file->get_size      = get_size_file;
	file->set_size      = set_size_file;
	file->close      	= close_file;
	file->check_error	= check_error_file;
	file->clear_error   = clear_error_file;

null_file:
	return;
}




void ADL_FILE_fini(ADL_FILE *file)
{
	if(ADL_CHECK_NULL(file))
	{
		ADL_RETURN_DEFER(null_file);
	}

null_file:
	return;
}





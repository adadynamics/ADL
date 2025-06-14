
#include "file.h"


extern ADL_UNIX adl_os;

#ifndef ADL_CONSTRUCTOR_INIT
#define ADL_CONSTRUCTOR_INIT(self)	if(ADL_CHECK_NULL(self) || ADL_CHECK_NOT_EQUAL(self->err_code,0))					\
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
#define ADL_RESET_FILE_SELF(self)         (self)->err_code = 0; (self)->err_str = (ADL_STRING){}; (self)->bytes = 0
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
		self->err_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
		self->err_str = ADL_RESULT_READ_STRING(rdr_res);
		ADL_RETURN_DEFER(failed_call);
	}

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
				self->err_code  = ADL_RESULT_READ_ERRNO(rdr_res); 
				self->err_str = ADL_RESULT_READ_STRING(rdr_res);
				ADL_RETURN_DEFER(failed_call);
		}

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
		self->err_code  = ADL_RESULT_READ_ERRNO(rdr_res);
		self->err_str = ADL_RESULT_READ_STRING(rdr_res);
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
		self->err_code  = ADL_RESULT_READ_ERRNO(rdr_res);
		self->err_str = ADL_RESULT_READ_STRING(rdr_res);
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



static void seek_file(ADL_FILE *self,s64 offset,u64 whence)
{

}



static void pread_file(ADL_FILE *self,void_ptr buf,u64 bufsize,u64 offset)
{

}



static void pwrite_file(ADL_FILE *self,const void_ptr buf,u64 bufsize,u64 offset)
{

}



static void preadv_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count,u64 offset)
{

}



static void pwritev_file(ADL_FILE *self,const ADL_IOVEC *iov,u64 count,u64 offset)
{

}



static void truncate_file(ADL_FILE *self,u64 size)
{

}



static void rename_file(ADL_FILE *self,const char *name)
{

}



static void move_file(ADL_FILE *self,const char *path)
{

}



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



static void fdatasync_file(ADL_FILE *self)
{

}



static void fsync_file(ADL_FILE *self)
{

}


static void sync_file(ADL_FILE *self)
{

}



static void stat_file(ADL_FILE *self,ADL_Stat *buf)
{

}



static void chmod_file(ADL_FILE *self,ADL_FILEARGS)
{

}



static void chown_file(ADL_FILE *self,ADL_FILEARGS args)
{

}



static void lchown_file(ADL_FILE *self,ADL_FILEARGS args)
{

}



static void get_size_file(ADL_FILE *self)
{

}



static void set_size_file(ADL_FILE *self,u64 size)
{

}

*/


static void close_file(ADL_FILE *self)
{

#ifdef ADL_OS_UNIX

		ADL_CONSTRUCTOR_INIT(self);
		ADL_RESULT_INIT(rdr_res);
		
		rdr_res = adl_os.close(self->fd);
		if(ADL_RESULT_CHECK_ERROR(rdr_res))
		{
				self->err_code  = ADL_RESULT_READ_ERRNO(rdr_res);
				self->err_str = ADL_RESULT_READ_STRING(rdr_res);
				ADL_RETURN_DEFER(failed_call);
		}
		
		ADL_RETURN_DEFER(success_call);

#endif

	ADL_CONSTRUCTOR_FINI();

}





static bool check_error_file(ADL_FILE *self)
{
	ADL_CONSTRUCTOR_INIT(self);
	
	if(ADL_CHECK_EQUAL(self->err_code,0))
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

	self->err_code = 0;
	ADL_STRING_fini(&self->err_str);

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
	file->err_code   	= 0;
	file->err_str 		= (ADL_STRING){};
	file->handle     	= NULL;
	file->bytes      	= 0;

	file->create     	= create_file;
	file->open       	= open_file;
	file->read       	= read_file;
	file->write      	= write_file;
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





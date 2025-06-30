#include "directory.h"

#if defined(ADL_OS_UNIX)

extern ADL_FILE_LINUX file_os;

#elif defined(ADL_OS_WINDOWS)

extern ADL_FILE_WINDOWS file_os;

#endif



ADL_RESULT Create(const char *name,ADL_DIRECTORY_ARGS args)
{
#if defined(ADL_OS_UNIX)
    return file_os.mkdir(name,args.mode);
#elif defined(ADL_OS_WINDOWS)
    return file_os.CreateDirectory(name,args.sa);
#endif
}

ADL_RESULT Delete(const char *name)
{
#if defined(ADL_OS_UNIX)
    return file_os.rmdir(name);
#elif defined(ADL_OS_WINDOWS)
    return file_os.RemoveDirectory(name);
#endif
}


ADL_RESULT SetCurrent(const char *name)
{
#if defined(ADL_OS_UNIX)
    return file_os.chdir(name);
#elif defined(ADL_OS_WINDOWS)
    return file_os.SetCurrentDirectory(name);
#endif
}


ADL_RESULT GetCurrent()
{
    ADL_RESULT_INIT(rdr_res);
    char buf_tmp[PATH_MAX] = {0};

#if defined(ADL_OS_UNIX)
    rdr_res = file_os.getcwd(buf_tmp,PATH_MAX);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = file_os.GetCurrentDirectory(PATH_MAX,buf_tmp);
#endif
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_getcwd);
    }

    ADL_STRING_Init(&rdr_res.str,buf_tmp);

failed_getcwd:
    return rdr_res;
}


ADL_RESULT FindFirstFile(const char *name,ADL_DIRECTORY_ENTRY *buf)
{

    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(buf))
    {
        ADL_RETURN_DEFER(null_buf);
    }

    
#if defined(ADL_OS_UNIX)
    rdr_res = file_os.opendir(name);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_opendir);
    }


    struct dirent *dirent = NULL;

    DIR *dir_ptr = (DIR *)ADL_RESULT_READ_PTR(rdr_res);

    rdr_res = file_os.readdir(dir_ptr);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_readdir);
    }


    dirent = (struct dirent *)ADL_RESULT_READ_PTR(rdr_res);

    ADL_STRING str;
    ADL_STRING_Init(&str,(char *)name);
    str.append(&str,"/");
    str.append(&str,dirent->d_name);


    ADL_STAT stat_buf;
    rdr_res = Stat(str.str,&stat_buf);
    if(ADL-ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_stat);
    }

    ADL_STRING_Fini(&str);

    buf->inode_number = dirent->d_ino;
    buf->stat_buf           = stat_buf;
    ADL_STRING_Init(&buf->name,dirent->d_name);
    rdr_res.ptr = dir_ptr;

failed_stat:
failed_readdir:
failed_opendir:
#elif defined(ADL_OS_WINDOWS)
    WIN32_FIND_DATAA data;
    rdr_res = file_os.FindFirstFile(name,&data)
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_first_file);
    }

    ADL_FILE_DESC dir_ptr = ADL_RESULT_READ_PTR(rdr_res);
    ADL_STAT stat_buf;
    
    rdr_res = Stat(data.cFileName,&stat_buf);
    if(ADL-ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_stat);
    }

    buf->inode_number = 0;
    buf->stat_buf     = stat_buf;
    ADL_STRING_Init(&buf->name,data.cFileName);
    rdr_res.ptr = dir_ptr;

failed_stat:
failed_first_file:
#endif

null_buf:
    return rdr_res;
}



ADL_RESULT FindNextFile(ADL_DIRECTORY_DESC fd,ADL_DIRECTORY_ENTRY *buf)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(buf) || ADL_CHECK_NULL(fd.handle))
    {
        ADL_RETURN_DEFER(null_buf);
    }


#if defined(ADL_OS_UNIX)

    struct dirent *dirent = NULL;

    rdr_res = file_os.readdir((DIR *)fd.handle);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_readdir);
    }


    dirent = (struct dirent *)ADL_RESULT_READ_PTR(rdr_res);
 

    ADL_STRING str;
    ADL_STRING_Init(&str,fd.name.str);
    str.append(&str,"/");
    str.append(&str,dirent->d_name);


    ADL_STAT stat_buf;
    rdr_res = Stat(str.str,&stat_buf);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_stat);
    }

    ADL_STRING_Fini(&str);

    buf->inode_number = dirent->d_ino;
    buf->stat_buf           = stat_buf;
    ADL_STRING_Init(&buf->name,dirent->d_name);

failed_stat:
failed_readdir:
#elif defined(ADL_OS_WINDOWS)
    WIN32_FIND_DATAA data;
    rdr_res = file_os.FindNextFile(fd.handle,&data)
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_first_file);
    }

    ADL_STAT stat_buf;
    
    rdr_res = Fstat(fd.handle,&stat_buf);
    if(ADL-ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_stat);
    }

    buf->inode_number = 0;
    buf->stat_buf     = stat_buf;
    ADL_STRING_Init(&buf->name,data.cFileName);

failed_stat:
failed_first_file:
#endif

null_buf:
    return rdr_res;
}




ADL_RESULT FindClose(ADL_DIRECTORY_DESC fd)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(fd.handle))
    {
        ADL_RETURN_DEFER(null_handle);
    }

#if defined(ADL_OS_UNIX)
    rdr_res = file_os.closedir(fd.handle);
    ADL_STRING_Fini(&fd.name);
#elif defined(ADL_OS_WINDOWS)
    rdr_res = file_os.FindClose(fd.handle);
#endif

null_handle:
    return rdr_res;
}








void ADL_DIRECTORY_Init(ADL_DIRECTORY *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }


null_class:
    return;
}

void ADL_DIRECTORY_fini(ADL_DIRECTORY *class)
{
	if(ADL_CHECK_NULL(class))
	{
		ADL_RETURN_DEFER(null_class);
	}

    ADL_MEMSET(class,0,sizeof(ADL_DIRECTORY));

null_class:
	return;
}

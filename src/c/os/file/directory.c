#include "directory.h"



extern ADL_FILE_LINUX file_linux;


ADL_FILE file;

void ADL_FILE_Library_init()
{
	ADL_FILE_init(&file);
}



ADL_RESULT create_directory(const char *name,ADL_DIRECTORY_ARGS args)
{
#ifdef ADL_OS_UNIX
    return file_linux.mkdir(name,args.mode);
#endif
}



ADL_RESULT delete_directory(const char *name)
{
#ifdef ADL_OS_UNIX
    return file_linux.rmdir(name);
#endif
}



ADL_RESULT change_directory(const char *name)
{
#ifdef ADL_OS_UNIX
    return file_linux.chdir(name);
#endif
}



ADL_RESULT get_current_directory(ADL_STRING buf)
{
    ADL_RESULT_INIT(rdr_res);

#ifdef ADL_OS_UNIX
    char buf_tmp[PATH_MAX];
    rdr_res = file_linux.getcwd(buf_tmp,PATH_MAX);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_getcwd);
    }

    ADL_STRING_init(&buf,buf_tmp);

failed_getcwd:
    return rdr_res;
#endif
}



ADL_RESULT find_first_file_directory(const char *name,ADL_DIRECTORY_ENTRY *buf)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(buf))
    {
        ADL_RETURN_DEFER(null_buf);
    }

    
#ifdef ADL_OS_UNIX
    rdr_res = file_linux.opendir(name);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_opendir);
    }


    struct dirent *dirent = NULL;

    DIR *dir_ptr = (DIR *)ADL_RESULT_READ_PTR(rdr_res);

    rdr_res = file_linux.readdir(dir_ptr);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_readdir);
    }


    dirent = (struct dirent *)ADL_RESULT_READ_PTR(rdr_res);

    ADL_STRING str;
    ADL_STRING_init(&str,(char *)name);
    str.append(&str,"/");
    str.append(&str,dirent->d_name);


    ADL_STAT stat_buf;
    rdr_res = file.stat_v2(str.str,&stat_buf);
    if(file.check_error(rdr_res))
    {
        ADL_RETURN_DEFER(failed_stat);
    }

    ADL_STRING_fini(&str);

    buf->inode_number = dirent->d_ino;
    buf->sb           = stat_buf;
    ADL_STRING_init(&buf->name,dirent->d_name);
    ADL_STRING_init(&rdr_res.str,(char *)name);
    rdr_res.ptr = dir_ptr;

failed_stat:
failed_readdir:
failed_opendir:
#endif

null_buf:
    return rdr_res;
}



ADL_RESULT find_next_file_directory(ADL_DIRECTORY_DESC fd,ADL_DIRECTORY_ENTRY *buf)
{
    
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(buf) || ADL_CHECK_NULL(fd.handle))
    {
        ADL_RETURN_DEFER(null_buf);
    }


#ifdef ADL_OS_UNIX

    struct dirent *dirent = NULL;

    rdr_res = file_linux.readdir((DIR *)fd.handle);
    if(ADL_RESULT_CHECK_ERROR(rdr_res))
    {
        ADL_RETURN_DEFER(failed_readdir);
    }


    dirent = (struct dirent *)ADL_RESULT_READ_PTR(rdr_res);
 

    ADL_STRING str;
    ADL_STRING_init(&str,fd.name.str);
    str.append(&str,"/");
    str.append(&str,dirent->d_name);


    ADL_STAT stat_buf;
    rdr_res = file.stat_v2(str.str,&stat_buf);
    if(file.check_error(rdr_res))
    {
        ADL_RETURN_DEFER(failed_stat);
    }

    ADL_STRING_fini(&str);

    buf->inode_number = dirent->d_ino;
    buf->sb           = stat_buf;
    ADL_STRING_init(&buf->name,dirent->d_name);

failed_stat:
failed_readdir:
#endif

null_buf:
    return rdr_res;
}



ADL_RESULT find_close_directory(ADL_DIRECTORY_DESC fd)
{
    ADL_RESULT_INIT(rdr_res);

    if(ADL_CHECK_NULL(fd.handle))
    {
        ADL_RETURN_DEFER(null_handle);
    }

#ifdef ADL_OS_UNIX
    rdr_res = file_linux.closedir(fd.handle);
    ADL_STRING_fini(&fd.name);
#endif

null_handle:
    return rdr_res;
}



bool check_error_directory(ADL_RESULT res)
{
	return ADL_RESULT_CHECK_ERROR(res);
}



bool print_error_directory(ADL_RESULT res)
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




bool clear_error_directory(ADL_RESULT res)
{
	ADL_RESULT_FINI(res);
	return true;
}




void ADL_DIRECTORY_init(ADL_DIRECTORY *directory)
{
    if(ADL_CHECK_NULL(directory))
    {
        ADL_RETURN_DEFER(null_class);
    }

    directory->create           = create_directory;
    directory->delete           = delete_directory;
    directory->change           = change_directory;
    directory->get_current      = get_current_directory;
    directory->find_first_file  = find_first_file_directory;
    directory->find_next_file   = find_next_file_directory;
    directory->find_close       = find_close_directory;
    directory->check_error      = check_error_directory;
    directory->print_error      = print_error_directory;
    directory->clear_error      = clear_error_directory;

null_class:
    return;
}

void ADL_DIRECTORY_fini(ADL_DIRECTORY *directory)
{
	if(ADL_CHECK_NULL(directory))
	{
		ADL_RETURN_DEFER(null_class);
	}

    ADL_MEMSET(directory,0,sizeof(ADL_DIRECTORY));

null_class:
	return;
}

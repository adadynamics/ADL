#include "file.h"


#ifdef ADL_OS_WINDOWS




#ifndef ADL_WINDOWS_INIT
#define ADL_WINDOWS_INIT(val,valptr)    ADL_S64_INIT(val);  \
                                        ADL_VOID_PTR_INIT(valptr); \
                                        ADL_ERRNO_INIT();   \
                                        ADL_RESULT_RETURN_DEFER_INIT();
#endif




#ifndef ADL_WINDOWS_FINI
#define ADL_WINDOWS_FINI(val,valptr)    if(ADL_CHECK_EQUAL(val,-1))                                                                                 \
                                        {                                                                                                           \
                                            ADL_STRING str;                                                                                         \
                                            ADL_STRING_Init(&str,ADL_STRERROR(errno));                                                              \
                                            ADL_RESULT_RETURN_DEFER(failed_syscall, ADL_RESULT_WRITE(errno,val,str,valptr));                        \
                                        }                                                                                                           \
                                                                                                                                                    \
                                        ADL_RESULT_RETURN_DEFER(success_syscall,ADL_RESULT_WRITE(errno,val,(ADL_STRING){},valptr));                 \
                                                                                                                                                    \
                                        failed_syscall:                                                                                             \
                                        success_syscall:                                                                                            \
                                            ADL_RESULT_RETURN_DEFER_FINI()                                

#endif



/*

    MISCELLENIOUS

*/




ADL_RESULT adl_lib_AreFileApisANSI(void)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_AREFILEAPISANSI();
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_SetFileApisToANSI(void) __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_SETFILEAPISTOANSI();
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_SetFileApisToOEM(void) __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_SETFILEAPISTOOEM();
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_CancelIo(HANDLE handle) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    
    BOOL status = ADL_CANCELIO(handle);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}







/*

    INOTIFY(MONITOR)

*/



ADL_RESULT adl_lib_FindFirstChangeNotification(LPCTSTR name,BOOL watch_subtree,DWORD filter) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    
    HANDLE handle = ADL_FINDFIRSTCHANGENOTIFICATION(name,watch_subtree,filter);
    rdr_retptr = (void_ptr)handle;
    
    if(ADL_CHECK_EQUAL(handle,INVALID_HANDLE_VALUE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}






ADL_RESULT adl_lib_FindNextChangeNotification(HANDLE handle) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_FINDNEXTCHANGENOTIFICATION(handle);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_FindCloseChangeNotification(HANDLE handle) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_FINDCLOSECHANGENOTIFICATION(handle);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}








/*
        MMAP FILES

*/




ADL_RESULT adl_lib_CreateFileMapping(HANDLE file_handle,LPSECURITY_ATTRIBUTES sa,DWORD protect,DWORD size_high,DWORD size_low,LPCTSTR map_name) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    HANDLE handle = ADL_CREATEFILEMAPPING(file_handle,sa,protect,size_high,size_low,map_name);
    rdr_retptr = (void_ptr)handle;
    
    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }


    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}






ADL_RESULT adl_lib_OpenFileMapping(DWORD access,BOOL inherit,LPCTSTR name)   __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    HANDLE handle = ADL_OPENFILEMAPPING(access,inherit,name);
    rdr_retptr = (void_ptr)handle;
    
    if(ADL_CHECK_EQUAL(handle,NULL))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}





ADL_RESULT adl_lib_MapViewOfFile(HANDLE handle,DWORD access,DWORD offset_high,DWORD offset_low,DWORD size) __LPVOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    LPVOID addr = ADL_MAPVIEWOFFILE(handle,access,offset_high,offset_low,size);
    if(ADL_CHECK_NULL(addr))
    {
        rdr_ret = -1;
        rdr_retptr = addr;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_MapViewOfFileEx(HANDLE handle,DWORD access,DWORD offset_high,DWORD offset_low,DWORD size,LPVOID base_addr) __LPVOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    LPVOID addr = ADL_MAPVIEWOFFILEEX(handle,access,offset_high,offset_low,size,base_addr);
    if(ADL_CHECK_NULL(addr))
    {
        rdr_ret = -1;
        rdr_retptr = addr;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_FlushViewOfFile(LPCVOID addr,DWORD size)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_FLUSHVIEWOFFILE(addr,size);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_UnmapViewOfFile(LPVOID base_addr) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_UNMAPVIEWOFFILE(base_addr);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}










/*
        NORMAL FILES

*/






ADL_RESULT adl_lib_CreateFile(LPCTSTR name,DWORD access,DWORD share_mode,LPSECURITY_ATTRIBUTES sa,DWORD create,DWORD attr_flags,HANDLE template)  __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    HANDLE handle = ADL_CREATEFILE(name,access,share_mode,sa,create,attr_flags,template);
    rdr_retptr = (void_ptr)handle;
    
    if(ADL_CHECK_EQUAL(handle,INVALID_HANDLE_VALUE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}





ADL_RESULT adl_lib_ReadFile(HANDLE handle,LPVOID buf,DWORD size,LPDWORD numread,LPOVERLAPPED overlapped) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_READFILE(handle,buf,size,numread,overlapped);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




//ADL_RESULT adl_lib_ReadFileEx();



ADL_RESULT adl_lib_WriteFile(HANDLE handle,LPCVOID buf,DWORD size,LPDWORD numwrite,LPOVERLAPPED overlapped) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_WRITEFILE(handle,buf,size,numwrite,overlapped);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




//ADL_RESULT adl_lib_WriteFileEx();



ADL_RESULT adl_lib_CloseHandle(HANDLE handle) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_CLOSEHANDLE(handle);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_GetOverlappedResult(HANDLE handle,LPOVERLAPPED overlapped,LPDWORD num_transferred,BOOL wait)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_GETOVERLAPPEDRESULT(handle,overlapped,num_transferred,wait);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



//ADL_RESULT adl_lib_GetTempFileName(LPCTSTR path,LPCTSTR prefix,UINT unique,LPTSTR name_buf);  __UINT__
//ADL_RESULT adl_lib_GetTempPath(DWORD buf_size,LPTSTR buf);



ADL_RESULT adl_lib_FlushFileBuffers(HANDLE handle) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_FLUSHFILEBUFFERS(handle);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




//ADL_RESULT adl_lib_SetFilePointer();


ADL_RESULT adl_lib_SetFilePointerEx(HANDLE handle,LARGE_INTEGER offset,PLARGE_INTEGER new_file_pointer,DWORD whence) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_SETFILEPOINTEREX(handle,offset,new_file_pointer,whence);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_SetEndOfFile(HANDLE handle)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_SETENDOFFILE(handle);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_GetStdHandle(DWORD stdhandle)  __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    HANDLE handle = ADL_GETSTDHANDLE(stdhandle);
    if(ADL_CHECK_EQUAL(handle,INVALID_HANDLE_VALUE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}





ADL_RESULT adl_lib_SetStdHandle(DWORD stdhandle,HANDLE handle) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_SETSTDHANDLE(stdhandle,handle);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_DeleteFile(LPCTSTR name)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_DELETEFILE(name);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_CopyFile(LPCTSTR oldfile,LPCTSTR newfile,BOOL fail_if_exists)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_COPYFILE(oldfile,newfile,fail_if_exists);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



//ADL_RESULT adl_lib_CopyFileEx();




ADL_RESULT adl_lib_MoveFile(LPCTSTR oldfile,LPCTSTR newfile) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_MOVEFILE(oldfile,newfile);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_MoveFileEx(LPCTSTR oldfile,LPCTSTR newfile,DWORD flags) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_MOVEFILEEX(oldfile,newfile,flags);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_CreateHardLink(LPCTSTR new_file,LPCTSTR old_file,LPSECURITY_ATTRIBUTES sa) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_CREATEHARDLINK(new_file,old_file,sa);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_CreateSymbolicLink(LPCTSTR new_file,LPCTSTR old_file,DWORD flags) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_CREATESYMBOLICLINK(new_file,old_file,flags);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




//ADL_RESULT adl_lib_LockFile(HANDLE handle,DWORD offset_low,DWORD offset_high,DWORD lock_low,DWORD lock_high);  __BOOL__




ADL_RESULT adl_lib_LockFileEx(HANDLE handle,DWORD flags,DWORD reserved,DWORD bytes_lock_low,DWORD bytes_lock_high,LPOVERLAPPED overlapped)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_LOCKFILEEX(handle,flags,reserved,bytes_lock_low,bytes_lock_high,overlapped);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



//ADL_RESULT adl_lib_UnlockFile(HANDLE handle,DWORD offset_low,DWORD offset_high,DWORD unlock_low,DWORD unlock_high); __BOOL__




ADL_RESULT adl_lib_UnlockFileEx(HANDLE handle,DWORD reserved,DWORD bytes_lock_low,DWORD bytes_lock_high,LPOVERLAPPED overlapped)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_UNLOCKFILEEX(handle,reserved,bytes_lock_low,bytes_lock_high,overlapped);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}





/*

    FILE ATTRIBUTES

*/






//ADL_RESULT adl_lib_GetFileSize(HANDLE handle,LPDWORD size_high);  __DWORD__




ADL_RESULT adl_lib_GetFileSizeEx(HANDLE handle,PLARGE_INTEGER size)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_GETFILESIZEEX(handle,size);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_GetFileType(HANDLE handle) __DWORD__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    DWORD status = ADL_GETFILETYPE(handle);
    rdr_ret = status;

    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }


    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_GetFileInformationByHandle(HANDLE handle,LPBY_HANDLE_FILE_INFORMATION info)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_GETFILEINFORMATIONBYHANDLE(handle,info);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




//ADL_RESULT adl_lib_GetFullPathName(LPCTSTR NAME,DWORD buf_size,LPTSTR buf,LPTSTR *part);   __DWORD__
//ADL_RESULT adl_lib_GetShortPathName();
//ADL_RESULT adl_lib_SetFIleShortName();



ADL_RESULT adl_lib_GetFileTime(HANDLE handle,LPFILETIME creation,LPFILETIME access,LPFILETIME write)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_GETFILETIME(handle,creation,access,write);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_SetFileTime(HANDLE handle,const FILETIME *creation,const FILETIME *access,const FILETIME *write)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_SETFILETIME(handle,creation,access,write);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_CompareFileTime(const FILETIME *ft1,const FILETIME *ft2)     __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_COMPAREFILETIME(ft1,ft2);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_FileTimeToLocalFileTime(const FILETIME *ft,LPFILETIME local)   __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_FILETIMETOLOCALFILETIME(ft,local);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_FileTimeToSystemTime(const FILETIME *ft,LPSYSTEMTIME sys)   __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_FILETIMETOSYSTEMTIME(ft,sys);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_LocalFileTimeToFileTime(const FILETIME *local,LPFILETIME ft)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_LOCALFILETIMETOFILETIME(local,ft);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_SystemTimeToFileTime(const SYSTEMTIME *st,FILETIME *ft) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_SYSTEMTIMETOFILETIME(st,ft);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_GetFileAttributes(LPCTSTR name)  __DWORD__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    DWORD status = ADL_GETFILEATTRIBUTES(name);
    rdr_ret = status;

    if(ADL_CHECK_EQUAL(status,INVALID_FILE_ATTRIBUTES))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



//ADL_RESULT adl_lib_GetFileAttributesEx();



ADL_RESULT adl_lib_SetFileAttributes(LPCTSTR name,DWORD attributes) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_SETFILEATTRIBUTES(name,attributes);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}











/*

    CONSOLE

*/





ADL_RESULT adl_lib_SetConsoleMode(HANDLE handle,DWORD mode) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_SETCONSOLEMODE(handle,mode);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_ReadConsole(HANDLE handle,LPVOID buf,DWORD size,LPDWORD numread,LPVOID reserved) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_READCONSOLE(handle,buf,size,numread,reserved);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_WriteConsole(HANDLE handle,LPCVOID buf,DWORD size,LPDWORD numwrite,LPVOID reserved) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_WRITECONSOLE(handle,buf,size,numwrite,reserved);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_FreeConsole(void)  __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_FREECONSOLE();
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



ADL_RESULT adl_lib_AllocConsole(void)  __VOID__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);
    ADL_ALLOCCONSOLE();
    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}






/*
    
    DIRECTORIES

*/





ADL_RESULT adl_lib_CreateDirectory(LPCTSTR name,LPSECURITY_ATTRIBUTES sa)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_CREATEDIRECTORY(name,sa);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_CreateDirectoryEx(LPCTSTR template,LPCTSTR name,LPSECURITY_ATTRIBUTES sa) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_CREATEDIRECTORYEX(template,name,sa);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_RemoveDirectory(LPCTSTR name)   __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_REMOVEDIRECTORY(name);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



//ADL_RESULT adl_lib_SearchPath();



ADL_RESULT adl_lib_SetCurrentDirectory(LPCTSTR name) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_SETCURRENTDIRECTORY(name);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_GetCurrentDirectory(DWORD size,LPTSTR buf) __DWORD__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    DWORD status = ADL_GETCURRENTDIRECTORY(size,buf);
    rdr_ret = status;

    if(ADL_CHECK_EQUAL(status,0))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_FindFirstFile(LPCTSTR name,LPWIN32_FIND_DATA data) __HANDLE__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    HANDLE handle = ADL_FINDFIRSTFILE(name,data);
    rdr_retptr = (void_ptr)handle;
    
    if(ADL_CHECK_EQUAL(handle,INVALID_HANDLE_VALUE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}



//ADL_RESULT adl_lib_FindFirstFileEx();



ADL_RESULT adl_lib_FindNextFile(HANDLE handle,LPWIN32_FIND_DATA data) __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_FINDNEXTFILE(handle,data);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




ADL_RESULT adl_lib_FindClose(HANDLE handle)  __BOOL__
{
    ADL_WINDOWS_INIT(rdr_ret,rdr_retptr);

    BOOL status = ADL_FINDCLOSE(handle);
    if(ADL_CHECK_EQUAL(status,FALSE))
    {
        rdr_ret = -1;
    }

    ADL_WINDOWS_FINI(rdr_ret,rdr_retptr);
}




#endif

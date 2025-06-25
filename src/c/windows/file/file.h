#ifndef ADL_SRC_WINDOWS_FILE_FILE_H
#define ADL_SRC_WINDOWS_FILE_FILE_H


#include "../windows.h"


#ifdef ADL_OS_WINDOWS

/*

    MISCELLENIOUS

*/



#ifndef ADL_AREFILEAPISANSI
#define ADL_AREFILEAPISANSI AreFileApisANSI  
#endif



#ifndef ADL_SETFILEAPISTOANSI
#define ADL_SETFILEAPISTOANSI SetFileApisToANSI
#endif



#ifndef ADL_SETFILEAPISTOOEM
#define ADL_SETFILEAPISTOOEM SetFileApisToOEM
#endif



#ifndef ADL_CANCELIO
#define ADL_CANCELIO CancelIo
#endif



/*

    INOTIFY(MONITOR)

*/


#ifndef ADL_FINDFIRSTCHANGENOTIFICATION
#define ADL_FINDFIRSTCHANGENOTIFICATION FindFirstChangeNotification
#endif



#ifndef ADL_FINDNEXTCHANGENOTIFICATION
#define ADL_FINDNEXTCHANGENOTIFICATION FindNextChangeNotification
#endif


#ifndef ADL_FINDCLOSECHANGENOTIFICATION
#define ADL_FINDCLOSECHANGENOTIFICATION FindCloseChangeNotification
#endif





/*
        MMAP FILES

*/

#ifndef ADL_CREATEFILEMAPPING
#define ADL_CREATEFILEMAPPING CreateFileMapping
#endif


#ifndef ADL_OPENFILEMAPPING
#define ADL_OPENFILEMAPPING OpenFileMapping
#endif


#ifndef ADL_MAPVIEWOFFILE
#define ADL_MAPVIEWOFFILE MapViewOfFile
#endif


#ifndef ADL_MAPVIEWOFFILEEX
#define ADL_MAPVIEWOFFILEEX MapViewOfFileEx
#endif

#ifndef ADL_FLUSHVIEWOFFILE
#define ADL_FLUSHVIEWOFFILE FlushViewOfFile
#endif



#ifndef ADL_UNMAPVIEWOFFILE
#define ADL_UNMAPVIEWOFFILE UnmapViewOfFile
#endif



/*
        NORMAL FILES

*/



#ifndef ADL_CREATEFILE
#define ADL_CREATEFILE CreateFile
#endif


#ifndef ADL_READFILE
#define ADL_READFILE ReadFile
#endif


#ifndef ADL_READFILEEX
#define ADL_READFILEEX ReadFileEx
#endif


#ifndef ADL_WRITEFILE
#define ADL_WRITEFILE WriteFile
#endif


#ifndef ADL_WRITEFILEEX
#define ADL_WRITEFILEEX WriteFileEx
#endif



#ifndef ADL_CLOSEHANDLE
#define ADL_CLOSEHANDLE CloseHandle
#endif


#ifndef ADL_GETOVERLAPPEDRESULT
#define ADL_GETOVERLAPPEDRESULT GetOverlappedResult
#endif


#ifndef ADL_GETTEMPFILENAME
#define ADL_GETTEMPFILENAME GetTempFileName
#endif


#ifndef ADL_GETTEMPPATH
#define ADL_GETTEMPPATH GetTempPath
#endif


#ifndef ADL_FLUSHFILEBUFFERS
#define ADL_FLUSHFILEBUFFERS FlushFileBuffers
#endif


#ifndef ADL_SETFILEPOINTER
#define ADL_SETFILEPOINTER SetFilePointer
#endif


#ifndef ADL_SETFILEPOINTEREX
#define ADL_SETFILEPOINTEREX SetFilePointerEx
#endif


#ifndef ADL_SETENDOFFILE
#define ADL_SETENDOFFILE SetEndOfFile
#endif


#ifndef ADL_GETSTDHANDLE
#define ADL_GETSTDHANDLE GetStdHandle
#endif


#ifndef ADL_SETSTDHANDLE
#define ADL_SETSTDHANDLE SetStdHandle
#endif


#ifndef ADL_DELETEFILE
#define ADL_DELETEFILE DeleteFile
#endif


#ifndef ADL_COPYFILE
#define ADL_COPYFILE CopyFile
#endif


#ifndef ADL_COPYFILEEX
#define ADL_COPYFILEEX CopyFileEx
#endif



#ifndef ADL_MOVEFILE
#define ADL_MOVEFILE MoveFile
#endif


#ifndef ADL_MOVEFILEEX
#define ADL_MOVEFILEEX MoveFileEx
#endif



#ifndef ADL_CREATEHARDLINK
#define ADL_CREATEHARDLINK CreateHardLink
#endif



#ifndef ADL_CREATESYMBOLICLINK
#define ADL_CREATESYMBOLICLINK CreateSymbolicLink
#endif



#ifndef ADL_LOCKFILE
#define ADL_LOCKFILE LockFile
#endif


#ifndef ADL_LOCKFILEEX
#define ADL_LOCKFILEEX LockFileEx
#endif


#ifndef ADL_UNLOCKFILE
#define ADL_UNLOCKFILE UnlockFile
#endif


#ifndef ADL_UNLOCKFILEEX
#define ADL_UNLOCKFILEEX UnlockFileEx
#endif






/*

    FILE ATTRIBUTES

*/



#ifndef ADL_GETFILESIZE
#define ADL_GETFILESIZE GetFileSize
#endif


#ifndef ADL_GETFILESIZEEX
#define ADL_GETFILESIZEEX GetFileSizeEx
#endif


#ifndef ADL_GETFILETYPE
#define ADL_GETFILETYPE GetFileType
#endif



#ifndef ADL_GETFILEINFORMATIONBYHANDLE
#define ADL_GETFILEINFORMATIONBYHANDLE GetFileInformationByHandle
#endif




#ifndef ADL_GETFULLPATHNAME
#define ADL_GETFULLPATHNAME GetFullPathName
#endif



#ifndef ADL_GETSHORTPATHNAME
#define ADL_GETSHORTPATHNAME GetShortPathName
#endif



#ifndef ADL_SETFILESHORTNAME
#define ADL_SETFILESHORTNAME SetFIleShortName
#endif



#ifndef ADL_GETFILETIME
#define ADL_GETFILETIME GetFileTime
#endif


#ifndef ADL_SETFILETIME
#define ADL_SETFILETIME SetFileTime
#endif


#ifndef ADL_COMPAREFILETIME
#define ADL_COMPAREFILETIME CompareFileTime
#endif


#ifndef ADL_FILETIMETOLOCALFILETIME
#define ADL_FILETIMETOLOCALFILETIME FileTimeToLocalFileTime
#endif


#ifndef ADL_FILETIMETOSYSTEMTIME
#define ADL_FILETIMETOSYSTEMTIME FileTimeToSystemTime
#endif


#ifndef ADL_LOCALFILETIMETOFILETIME
#define ADL_LOCALFILETIMETOFILETIME LocalFileTimeToFileTime
#endif


#ifndef ADL_SYSTEMTIMETOFILETIME
#define ADL_SYSTEMTIMETOFILETIME SystemTimeToFileTime
#endif


#ifndef ADL_GETFILEATTRIBUTES
#define ADL_GETFILEATTRIBUTES GetFileAttributes
#endif


#ifndef ADL_GETFILEATTRIBUTESEX
#define ADL_GETFILEATTRIBUTESEX GetFileAttributesEx
#endif



#ifndef ADL_SETFILEATTRIBUTES
#define ADL_SETFILEATTRIBUTES SetFileAttributes
#endif


/*

    CONSOLE

*/


#ifndef ADL_SETCONSOLEMODE
#define ADL_SETCONSOLEMODE SetConsoleMode
#endif


#ifndef ADL_READCONSOLE
#define ADL_READCONSOLE ReadConsole
#endif


#ifndef ADL_WRITECONSOLE
#define ADL_WRITECONSOLE WriteConsole
#endif


#ifndef ADL_FREECONSOLE
#define ADL_FREECONSOLE FreeConsole
#endif


#ifndef ADL_ALLOCCONSOLE
#define ADL_ALLOCCONSOLE AllocConsole
#endif



/*
    
    DIRECTORIES

*/





#ifndef ADL_CREATEDIRECTORY
#define ADL_CREATEDIRECTORY CreateDirectory
#endif



#ifndef ADL_CREATEDIRECTORYEX
#define ADL_CREATEDIRECTORYEX CreateDirectoryEx
#endif


#ifndef ADL_REMOVEDIRECTORY
#define ADL_REMOVEDIRECTORY RemoveDirectory
#endif


#ifndef ADL_SEARCHPATH
#define ADL_SEARCHPATH SearchPath
#endif


#ifndef ADL_SETCURRENTDIRECTORY
#define ADL_SETCURRENTDIRECTORY SetCurrentDirectory
#endif



#ifndef ADL_GETCURRENTDIRECTORY
#define ADL_GETCURRENTDIRECTORY GetCurrentDirectory
#endif


#ifndef ADL_FINDFIRSTFILE
#define ADL_FINDFIRSTFILE FindFirstFile
#endif


#ifndef ADL_FINDFIRSTFILEEX
#define ADL_FINDFIRSTFILEEX FindFirstFileEx
#endif


#ifndef ADL_FINDNEXTFILE
#define ADL_FINDNEXTFILE FindNextFile
#endif


#ifndef ADL_FINDCLOSE
#define ADL_FINDCLOSE FindClose
#endif



/*

    MISCELLENIOUS

*/




ADL_RESULT adl_lib_AreFileApisANSI(void);  __BOOL__
ADL_RESULT adl_lib_SetFileApisToANSI(void); __VOID__
ADL_RESULT adl_lib_SetFileApisToOEM(void); __VOID__
ADL_RESULT adl_lib_CancelIo(HANDLE handle); __BOOL__




/*

    INOTIFY(MONITOR)

*/



ADL_RESULT adl_lib_FindFirstChangeNotification(LPCTSTR name,BOOL watch_subtree,DWORD filter); __HANDLE__
ADL_RESULT adl_lib_FindNextChangeNotification(HANDLE handle); __BOOL__
ADL_RESULT adl_lib_FindCloseChangeNotification(HANDLE handle); __BOOL__





/*
        MMAP FILES

*/




ADL_RESULT adl_lib_CreateFileMapping(HANDLE handle,LPSECURITY_ATTRIBUTES sa,DWORD protect,DWORD size_high,DWORD size_low,LPCTSTR map_name); __HANDLE__
ADL_RESULT adl_lib_OpenFileMapping(DWORD access,BOOL inherit,LPCTSTR name);   __HANDLE__
ADL_RESULT adl_lib_MapViewOfFile(HANDLE handle,DWORD access,DWORD offset_high,DWORD offset_low,DWORD size); __LPVOID__
ADL_RESULT adl_lib_MapViewOfFileEx(HANDLE handle,DWORD access,DWORD offset_high,DWORD offset_low,DWORD size,LPVOID base_addr); __LPVOID__
ADL_RESULT adl_lib_FlushViewOfFile(LPCVOID addr,DWORD size);  __BOOL__
ADL_RESULT adl_lib_UnmapViewOfFile(LPVOID base_addr); __BOOL__







/*
        NORMAL FILES

*/






ADL_RESULT adl_lib_CreateFile(LPCTSTR name,DWORD access,DWORD share_mode,LPSECURITY_ATTRIBUTES sa,DWORD create,DWORD attr_flags,HANDLE template);  __HANDLE__
ADL_RESULT adl_lib_ReadFile(HANDLE handle,LPVOID buf,DWORD size,LPDWORD numread,LPOVERLAPPED overlapped); __BOOL__
//ADL_RESULT adl_lib_ReadFileEx();
ADL_RESULT adl_lib_WriteFile(HANDLE handle,LPCVOID buf,DWORD size,LPDWORD numwrite,LPOVERLAPPED overlapped); __BOOL__
//ADL_RESULT adl_lib_WriteFileEx();
ADL_RESULT adl_lib_CloseHandle(HANDLE handle);        __BOOL__
ADL_RESULT adl_lib_GetOverlappedResult(HANDLE handle,LPOVERLAPPED overlapped,LPDWORD num_transferred,BOOL wait);  __DWORD__
//ADL_RESULT adl_lib_GetTempFileName(LPCTSTR path,LPCTSTR prefix,UINT unique,LPTSTR name_buf);  __UINT__
//ADL_RESULT adl_lib_GetTempPath(DWORD buf_size,LPTSTR buf);
ADL_RESULT adl_lib_FlushFileBuffers(HANDLE handle); __BOOL__
//ADL_RESULT adl_lib_SetFilePointer();
ADL_RESULT adl_lib_SetFilePointerEx(HANDLE handle,LARGE_INTEGER offset,PLARGE_INTEGER new_file_pointer,DWORD whence); __BOOL__
ADL_RESULT adl_lib_SetEndOfFile(HANDLE handle);  __BOOL__
ADL_RESULT adl_lib_GetStdHandle(DWORD stdhandle);  __HANDLE__
ADL_RESULT adl_lib_SetStdHandle(DWORD stdhandle,HANDLE handle); __BOOL__
ADL_RESULT adl_lib_DeleteFile(LPCTSTR name);  __BOOL__
ADL_RESULT adl_lib_CopyFile(LPCTSTR oldfile,LPCTSTR newfile,BOOL fail_if_exists);  __BOOL__

//ADL_RESULT adl_lib_CopyFileEx();

ADL_RESULT adl_lib_MoveFile(LPCTSTR oldfile,LPCTSTR newfile); __BOOL__
ADL_RESULT adl_lib_MoveFileEx(LPCTSTR oldfile,LPCTSTR newfile,DWORD flags); __BOOL__
ADL_RESULT adl_lib_CreateHardLink(LPCTSTR new_file,LPCTSTR old_file,LPSECURITY_ATTRIBUTES sa); __BOOL__
ADL_RESULT adl_lib_CreateSymbolicLink(LPCTSTR new_file,LPCTSTR old_file,DWORD flags); __BOOL__
//ADL_RESULT adl_lib_LockFile(HANDLE handle,DWORD offset_low,DWORD offset_high,DWORD lock_low,DWORD lock_high);  __BOOL__
ADL_RESULT adl_lib_LockFileEx(HANDLE handle,DWORD flags,DWORD reserved,DWORD bytes_lock_low,DWORD bytes_lock_high,LPOVERLAPPED overlapped);  __BOOL__
//ADL_RESULT adl_lib_UnlockFile(HANDLE handle,DWORD offset_low,DWORD offset_high,DWORD unlock_low,DWORD unlock_high); __BOOL__
ADL_RESULT adl_lib_UnlockFileEx(HANDLE handle,DWORD reserved,DWORD bytes_lock_low,DWORD bytes_lock_high,LPOVERLAPPED overlapped);  __BOOL__






/*

    FILE ATTRIBUTES

*/






//ADL_RESULT adl_lib_GetFileSize(HANDLE handle,LPDWORD size_high);  __DWORD__
ADL_RESULT adl_lib_GetFileSizeEx(HANDLE handle,PLARGE_INTEGER size);  __BOOL__
ADL_RESULT adl_lib_GetFileType(HANDLE handle); __DWORD__
ADL_RESULT adl_lib_GetFileInformationByHandle(HANDLE handle,LPBY_HANDLE_FILE_INFORMATION info);  __BOOL__
ADL_RESULT adl_lib_GetFullPathName(LPCTSTR NAME,DWORD buf_size,LPTSTR buf,LPTSTR *part);   __DWORD__
//ADL_RESULT adl_lib_GetShortPathName();
//ADL_RESULT adl_lib_SetFIleShortName();
ADL_RESULT adl_lib_GetFileTime(HANDLE handle,LPFILETIME creation,LPFILETIME access,LPFILETIME write);  __BOOL__
ADL_RESULT adl_lib_SetFileTime(HANDLE handle,const FILETIME *creation,const FILETIME *access,const FILETIME *write);  __BOOL__
ADL_RESULT adl_lib_CompareFileTime(const FILETIME *ft1,const FILETIME *ft2);     __BOOL__
ADL_RESULT adl_lib_FileTimeToLocalFileTime(const FILETIME *ft,LPFILETIME local);   __BOOL__
ADL_RESULT adl_lib_FileTimeToSystemTime(const FILETIME *ft,LPSYSTEMTIME sys);   __BOOL__
ADL_RESULT adl_lib_LocalFileTimeToFileTime(const FILETIME *local,LPFILETIME ft);  __BOOL__
ADL_RESULT adl_lib_SystemTimeToFileTime(const SYSTEMTIME *st,FILETIME *ft); __BOOL__
ADL_RESULT adl_lib_GetFileAttributes(LPCTSTR name);  __DWORD__
//ADL_RESULT adl_lib_GetFileAttributesEx();
ADL_RESULT adl_lib_SetFileAttributes(LPCTSTR name,DWORD attributes); __BOOL__






/*

    CONSOLE

*/





ADL_RESULT adl_lib_SetConsoleMode(HANDLE handle,DWORD mode); __BOOL__
ADL_RESULT adl_lib_ReadConsole(HANDLE handle,LPVOID buf,DWORD size,LPDWORD numread,LPVOID reserved); __BOOL__
ADL_RESULT adl_lib_WriteConsole(HANDLE handle,LPCVOID buf,DWORD size,LPDWORD numread,LPVOID reserved); __BOOL__
ADL_RESULT adl_lib_FreeConsole(void);  __VOID__
ADL_RESULT adl_lib_AllocConsole(void);  __VOID__






/*
    
    DIRECTORIES

*/





ADL_RESULT adl_lib_CreateDirectory(LPCTSTR name,LPSECURITY_ATTRIBUTES sa);  __BOOL__
ADL_RESULT adl_lib_CreateDirectoryEx(LPCTSTR template,LPCTSTR name,LPSECURITY_ATTRIBUTES sa); __BOOL__
ADL_RESULT adl_lib_RemoveDirectory(LPCTSTR name);   __BOOL__
//ADL_RESULT adl_lib_SearchPath();
ADL_RESULT adl_lib_SetCurrentDirectory(LPCTSTR name); __BOOL__
ADL_RESULT adl_lib_GetCurrentDirectory(DWORD size,LPTSTR buf); __DWORD__
ADL_RESULT adl_lib_FindFirstFile(LPCTSTR name,LPWIN32_FIND_DATA data); __HANDLE__
//ADL_RESULT adl_lib_FindFirstFileEx();
ADL_RESULT adl_lib_FindNextFile(HANDLE handle,LPWIN32_FIND_DATA data); __BOOL__
ADL_RESULT adl_lib_FindClose(HANDLE handle);  __BOOL__





#endif



#endif

#ifndef ADL_SRC_OS_FILES_PLATFORM_WINDOWS_FILE_WINDOWS_H
#define ADL_SRC_OS_FILES_PLATFORM_WINDOWS_FILE_WINDOWS_H

#include "../../../os.h"

#ifdef ADL_OS_WINDOWS



typedef struct ADL_FILE_WINDOWS
{

    ADL_RESULT (*AreFileApisANSI)(void); 
    ADL_RESULT (*SetFileApisToANSI)(void);
    ADL_RESULT (*SetFileApisToOEM)(void);
    ADL_RESULT (*CancelIo)(HANDLE handle);

    ADL_RESULT (*FindFirstChangeNotification)(LPCTSTR name,BOOL watch_subtree,DWORD filter); 
    ADL_RESULT (*FindNextChangeNotification)(HANDLE handle);
    ADL_RESULT (*FindCloseChangeNotification)(HANDLE handle);

    ADL_RESULT (*CreateFileMapping)(HANDLE handle,LPSECURITY_ATTRIBUTES sa,DWORD protect,DWORD size_high,DWORD size_low,LPCTSTR map_name); 
    ADL_RESULT (*OpenFileMapping)(DWORD access,BOOL inherit,LPCTSTR name);   
    ADL_RESULT (*MapViewOfFile)(HANDLE handle,DWORD access,DWORD offset_high,DWORD offset_low,DWORD size);
    ADL_RESULT (*MapViewOfFileEx)(HANDLE handle,DWORD access,DWORD offset_high,DWORD offset_low,DWORD size,LPVOID base_addr);
    ADL_RESULT (*FlushViewOfFile)(LPCVOID addr,DWORD size); 
    ADL_RESULT (*UnmapViewOfFile)(LPVOID base_addr);

    ADL_RESULT (*CreateFile)(LPCTSTR name,DWORD access,DWORD share_mode,LPSECURITY_ATTRIBUTES sa,DWORD create,DWORD attr_flags,HANDLE template);  
    ADL_RESULT (*ReadFile)(HANDLE handle,LPVOID buf,DWORD size,LPDWORD numread,LPOVERLAPPED overlapped);
    //ADL_RESULT (*ReadFileEx)();
    ADL_RESULT (*WriteFile)(HANDLE handle,LPCVOID buf,DWORD size,LPDWORD numwrite,LPOVERLAPPED overlapped);
    //ADL_RESULT (*WriteFileEx)();
    ADL_RESULT (*CloseHandle)(HANDLE handle);       
    ADL_RESULT (*GetOverlappedResult)(HANDLE handle,LPOVERLAPPED overlapped,LPDWORD num_transferred,BOOL wait); 
    //ADL_RESULT (*GetTempFileName)(LPCTSTR path,LPCTSTR prefix,UINT unique,LPTSTR name_buf);  __UINT__
    //ADL_RESULT (*GetTempPath)(DWORD buf_size,LPTSTR buf);
    ADL_RESULT (*FlushFileBuffers)(HANDLE handle);
    //ADL_RESULT (*SetFilePointer)();
    ADL_RESULT (*SetFilePointerEx)(HANDLE handle,LARGE_INTEGER offset,PLARGE_INTEGER new_file_pointer,DWORD whence);
    ADL_RESULT (*SetEndOfFile)(HANDLE handle); 
    ADL_RESULT (*GetStdHandle)(DWORD stdhandle);  
    ADL_RESULT (*SetStdHandle)(DWORD stdhandle,HANDLE handle);
    ADL_RESULT (*DeleteFile)(LPCTSTR name); 
    ADL_RESULT (*CopyFile)(LPCTSTR oldfile,LPCTSTR newfile,BOOL fail_if_exists); 
    //ADL_RESULT (*CopyFileEx)();
    ADL_RESULT (*MoveFile)(LPCTSTR oldfile,LPCTSTR newfile);
    ADL_RESULT (*MoveFileEx)(LPCTSTR oldfile,LPCTSTR newfile,DWORD flags);
    ADL_RESULT (*CreateHardLink)(LPCTSTR new_file,LPCTSTR old_file,LPSECURITY_ATTRIBUTES sa);
    ADL_RESULT (*CreateSymbolicLink)(LPCTSTR new_file,LPCTSTR old_file,DWORD flags);
    //ADL_RESULT (*LockFile)(HANDLE handle,DWORD offset_low,DWORD offset_high,DWORD lock_low,DWORD lock_high); 
    ADL_RESULT (*LockFileEx)(HANDLE handle,DWORD flags,DWORD reserved,DWORD bytes_lock_low,DWORD bytes_lock_high,LPOVERLAPPED overlapped); 
    //ADL_RESULT (*UnlockFile)(HANDLE handle,DWORD offset_low,DWORD offset_high,DWORD unlock_low,DWORD unlock_high);
    ADL_RESULT (*UnlockFileEx)(HANDLE handle,DWORD reserved,DWORD bytes_lock_low,DWORD bytes_lock_high,LPOVERLAPPED overlapped); 

    //ADL_RESULT (*GetFileSize)(HANDLE handle,LPDWORD size_high); 
    ADL_RESULT (*GetFileSizeEx)(HANDLE handle,PLARGE_INTEGER size); 
    ADL_RESULT (*GetFileType)(HANDLE handle);
    ADL_RESULT (*GetFileInformationByHandle)(HANDLE handle,LPBY_HANDLE_FILE_INFORMATION info); 
    ADL_RESULT (*GetFullPathName)(LPCTSTR NAME,DWORD buf_size,LPTSTR buf,LPTSTR *part);  
    //ADL_RESULT (*GetShortPathName)();
    //ADL_RESULT (*SetFIleShortName)();
    ADL_RESULT (*GetFileTime)(HANDLE handle,LPFILETIME creation,LPFILETIME access,LPFILETIME write); 
    ADL_RESULT (*SetFileTime)(HANDLE handle,const FILETIME *creation,const FILETIME *access,const FILETIME *write); 
    ADL_RESULT (*CompareFileTime)(const FILETIME *ft1,const FILETIME *ft2);    
    ADL_RESULT (*FileTimeToLocalFileTime)(const FILETIME *ft,LPFILETIME local);  
    ADL_RESULT (*FileTimeToSystemTime)(const FILETIME *ft,LPSYSTEMTIME sys);  
    ADL_RESULT (*LocalFileTimeToFileTime)(const FILETIME *local,LPFILETIME ft); 
    ADL_RESULT (*SystemTimeToFileTime)(const SYSTEMTIME *st,FILETIME *ft);
    ADL_RESULT (*GetFileAttributes)(LPCTSTR name); 
    //ADL_RESULT (*GetFileAttributesEx)();
    ADL_RESULT (*SetFileAttributes)(LPCTSTR name,DWORD attributes);

    ADL_RESULT (*SetConsoleMode)(HANDLE handle,DWORD mode);
    ADL_RESULT (*ReadConsole)(HANDLE handle,LPVOID buf,DWORD size,LPDWORD numread,LPVOID reserved);
    ADL_RESULT (*WriteConsole)(HANDLE handle,LPCVOID buf,DWORD size,LPDWORD numread,LPVOID reserved);
    ADL_RESULT (*FreeConsole)(void); 
    ADL_RESULT (*AllocConsole)(void); 

    ADL_RESULT (*CreateDirectory)(LPCTSTR name,LPSECURITY_ATTRIBUTES sa); 
    ADL_RESULT (*CreateDirectoryEx)(LPCTSTR template,LPCTSTR name,LPSECURITY_ATTRIBUTES sa);
    ADL_RESULT (*RemoveDirectory)(LPCTSTR name);  
    //ADL_RESULT (*SearchPath)();
    ADL_RESULT (*SetCurrentDirectory)(LPCTSTR name);
    ADL_RESULT (*GetCurrentDirectory)(DWORD size,LPTSTR buf);
    ADL_RESULT (*FindFirstFile)(LPCTSTR name,LPWIN32_FIND_DATA data); 
    //ADL_RESULT (*FindFirstFileEx)();
    ADL_RESULT (*FindNextFile)(HANDLE handle,LPWIN32_FIND_DATA data);
    ADL_RESULT (*FindClose)(HANDLE handle); 

}ADL_FILE_WINDOWS;



void ADL_FILE_WINDOWS_Init(ADL_FILE_WINDOWS *class);

void ADL_FILE_WINDOWS_Fini(ADL_FILE_WINDOWS *class);

#endif


#endif

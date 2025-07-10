#ifndef ADL_WINDOWS_WINDOWS_H
#define ADL_WINDOWS_WINDOWS_H

#include "../common/utils.h"
#include "../ds/string.h"



#ifdef ADL_OS_WINDOWS



#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <winioctl.h>

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif


#pragma comment(lib,"ws2_32.lib")



#ifndef ADL_SOCKET_DESC
#define ADL_SOCKET_DESC SOCKET
#endif


#ifndef ADL_INVALID_SOCKET
#define ADL_INVALID_SOCKET INVALID_SOCKET
#endif


#ifndef ADL_SOCKET_ERRNO
#define ADL_SOCKET_ERRNO WSAGetLastError()
#endif



typedef struct ADL_WINDOWS
{

    bool (*SocketInit)(void);
    bool (*SocketFini)(void);
    ADL_RESULT (*socket)(int domain,int type,int protocol);
    /**
    ADL_RESULT (*socketpair)(int domain,int type,int protocol,ADL_SOCKET_DESC sockfds[2]);
    */
    ADL_RESULT (*bind)(ADL_SOCKET_DESC sockfd,const struct sockaddr *addr,socklen_t addrlen);
    ADL_RESULT (*connect)(ADL_SOCKET_DESC sockfd,const struct sockaddr *addr,socklen_t addrlen);
    ADL_RESULT (*listen)(ADL_SOCKET_DESC sockfd,int backlog);
    ADL_RESULT (*accept)(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen);
    /*
    ADL_RESULT (*accept4)(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen,int flags);
    */
    ADL_RESULT (*recv)(ADL_SOCKET_DESC sockfd,void *buf,size_t buflen,int flags);
    ADL_RESULT (*recvfrom)(ADL_SOCKET_DESC sockfd,void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t *addrlen);
    /**
    ADL_RESULT (*recvmsg)(ADL_SOCKET_DESC sockfd,struct msghdr *msg,int flags);
    ADL_RESULT (*recvmmsg)(ADL_SOCKET_DESC sockfd,struct mmsghdr *msgvec,int vlen,int flags,struct timespec *timeout);
    */
    ADL_RESULT (*send)(ADL_SOCKET_DESC sockfd,const void *buf,size_t buflen,int flags);
    ADL_RESULT (*sendto)(ADL_SOCKET_DESC sockfd,const void *buf,size_t buflen,int flags,struct sockaddr *addr,socklen_t addrlen);
    /**
    ADL_RESULT (*sendmsg)(ADL_SOCKET_DESC sockfd,const struct msghdr *msg,int flags);
    ADL_RESULT (*sendmmsg)(ADL_SOCKET_DESC sockfd,struct mmsghdr *msgvec,int vlen,int flags);
    */
    ADL_RESULT (*shutdown)(ADL_SOCKET_DESC sockfd,int how);
    ADL_RESULT (*close)(ADL_SOCKET_DESC fd);
    ADL_RESULT (*getsockopt)(ADL_SOCKET_DESC sockfd,int level,int optname,void *optval,socklen_t *optlen);
    ADL_RESULT (*setsockopt)(ADL_SOCKET_DESC sockfd,int level,int optname,void *optval,socklen_t optlen);
    ADL_RESULT (*getsockname)(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen);
    ADL_RESULT (*getpeername)(ADL_SOCKET_DESC sockfd,struct sockaddr *addr,socklen_t *addrlen);
    ADL_RESULT (*getaddrinfo)(const char *host,const char *service,struct addrinfo *hints,struct addrinfo **res);
    ADL_RESULT (*freeaddrinfo)(struct addrinfo *res);
    ADL_RESULT (*getnameinfo)(const struct sockaddr *addr,socklen_t addrlen,char *host,socklen_t hostlen,char *service,socklen_t servicelen,int flags);
    ADL_RESULT (*htons)(u16 hostshort);
    ADL_RESULT (*htonl)(u32 hostlong);
    ADL_RESULT (*ntohs)(u16 netshort);
    ADL_RESULT (*ntohl)(u32 netlong);



    /*

        MISCELLENIOUS

    */

    ADL_RESULT (*AreFileApisANSI)(void); 
    ADL_RESULT (*SetFileApisToANSI)(void);
    ADL_RESULT (*SetFileApisToOEM)(void);
    ADL_RESULT (*CancelIo)(HANDLE handle);

    /*

        INOTIFY)(MONITOR)

    */

    ADL_RESULT (*FindFirstChangeNotification)(LPCTSTR name,BOOL watch_subtree,DWORD filter); 
    ADL_RESULT (*FindNextChangeNotification)(HANDLE handle);
    ADL_RESULT (*FindCloseChangeNotification)(HANDLE handle);

    /*
            MMAP FILES

    */

    ADL_RESULT (*CreateFileMapping)(HANDLE handle,LPSECURITY_ATTRIBUTES sa,DWORD protect,DWORD size_high,DWORD size_low,LPCTSTR map_name); 
    ADL_RESULT (*OpenFileMapping)(DWORD access,BOOL inherit,LPCTSTR name);   
    ADL_RESULT (*MapViewOfFile)(HANDLE handle,DWORD access,DWORD offset_high,DWORD offset_low,DWORD size);
    ADL_RESULT (*MapViewOfFileEx)(HANDLE handle,DWORD access,DWORD offset_high,DWORD offset_low,DWORD size,LPVOID base_addr);
    ADL_RESULT (*FlushViewOfFile)(LPCVOID addr,DWORD size); 
    ADL_RESULT (*UnmapViewOfFile)(LPVOID base_addr);

    /*
            NORMAL FILES

    */

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

    /*

        FILE ATTRIBUTES

    */

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

    /*

        CONSOLE

    */

    ADL_RESULT (*SetConsoleMode)(HANDLE handle,DWORD mode);
    ADL_RESULT (*ReadConsole)(HANDLE handle,LPVOID buf,DWORD size,LPDWORD numread,LPVOID reserved);
    ADL_RESULT (*WriteConsole)(HANDLE handle,LPCVOID buf,DWORD size,LPDWORD numread,LPVOID reserved);
    ADL_RESULT (*FreeConsole)(void); 
    ADL_RESULT (*AllocConsole)(void); 

    /*
        
        DIRECTORIES

    */

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









    ADL_RESULT (*CreateThread)(LPSECURITY_ATTRIBUTES sa,SIZE_T stack_size,LPTHREAD_START_ROUTINE subroutine,LPVOID args,DWORD flags,LPDWORD thread_id);
    ADL_RESULT (*OpenThread)(DWORD access,BOOL inherit,DWORD thread_id);
    ADL_RESULT (*ExitThread)(DWORD code);
    ADL_RESULT (*TerminateThread)(HANDLE handle,DWORD code);
    ADL_RESULT (*GetExitCodeThread)(HANDLE handle,LPDWORD code);
    ADL_RESULT (*ResumeThread)(HANDLE handle);
    ADL_RESULT (*SuspendThread)(HANDLE handle);
    ADL_RESULT (*GetThreadDescription)(HANDLE handle,PCSTR *description);
    ADL_RESULT (*SetThreadDescription)(HANDLE handle,PCSTR description);
    ADL_RESULT (*GetThreadTimes)(HANDLE handle,LPFILETIME creation,LPFILETIME exit,LPFILETIME kernel,LPFILETIME user);
    ADL_RESULT (*GetPriorityClass)(HANDLE handle);
    ADL_RESULT (*SetPriorityClass)(HANDLE handle,DWORD class);
    ADL_RESULT (*SetThreadPriority)(HANDLE handle,int priority);
    ADL_RESULT (*InitializeCriticalSection)(LPCRITICAL_SECTION cs);
    ADL_RESULT (*InitializeCriticalSectionEx)(LPCRITICAL_SECTION cs,DWORD spin_count,DWORD flags);
    ADL_RESULT (*InitializeCriticalSectionAndSpinCount)(LPCRITICAL_SECTION cs,DWORD spin_count);
    ADL_RESULT (*DeleteCriticalSection)(LPCRITICAL_SECTION cs);
    ADL_RESULT (*EnterCriticalSection)(LPCRITICAL_SECTION cs);
    ADL_RESULT (*TryEnterCriticalSection)(LPCRITICAL_SECTION cs);
    ADL_RESULT (*LeaveCriticalSection)(LPCRITICAL_SECTION cs);
    ADL_RESULT (*CreateMutex)(LPSECURITY_ATTRIBUTES sa,BOOL owner,LPCTSTR name);
    ADL_RESULT (*CreateMutexEx)(LPSECURITY_ATTRIBUTES sa,LPCTSTR name,DWORD flags,DWORD access);
    ADL_RESULT (*OpenMutex)(DWORD access,BOOL inherit,LPCTSTR name);
    ADL_RESULT (*WaitForSingleObject)(HANDLE handle,DWORD milli);
    ADL_RESULT (*ReleaseMutex)(HANDLE handle);
    ADL_RESULT (*CreateSemaphore)(LPSECURITY_ATTRIBUTES sa,LONG count,LONG max_count,LPCTSTR name);
    ADL_RESULT (*CreateSemaphoreEx)(LPSECURITY_ATTRIBUTES sa,LONG count,LONG max_count,LPCTSTR name,DWORD flags,DWORD access);
    ADL_RESULT (*OpenSemaphore)(DWORD access,DWORD inherit,LPCTSTR name);
    ADL_RESULT (*ReleaseSemaphore)(HANDLE handle,LONG count,LPLONG prev_count);
    ADL_RESULT (*CreateEvent)(LPSECURITY_ATTRIBUTES sa,BOOL manual_reset,BOOL initial_state,LPCTSTR name);
    ADL_RESULT (*CreateEventEx)(LPSECURITY_ATTRIBUTES sa,LPCTSTR name,DWORD flags,DWORD access);
    ADL_RESULT (*OpenEvent)(DWORD access,DWORD inherit,LPCTSTR name);
    ADL_RESULT (*SetEvent)(HANDLE handle);
    ADL_RESULT (*ResetEvent)(HANDLE handle);
    ADL_RESULT (*PulseEvent)(HANDLE handle);

    

}ADL_WINDOWS;


void ADL_WINDOWS_Init(ADL_WINDOWS *class);

void ADL_WINDOWS_Fini(ADL_WINDOWS *class);


#endif


#endif

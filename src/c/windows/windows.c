#include "file/file.h"
#include "net/net.h"
#include "thread/thread.h"


#ifdef ADL_OS_WINDOWS




void ADL_WINDOWS_Init(ADL_WINDOWS *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }


    class->SocketInit                  = adl_lib_SocketInit;
    class->SocketFini                  = adl_lib_SocketFini;
    class->socket                      = adl_lib_socket;
    /**
	class->socketpair                  = adl_lib_socketpair;
	*/
    class->bind                        = adl_lib_bind;
	class->connect                     = adl_lib_connect;
	class->listen                      = adl_lib_listen;
	class->accept                      = adl_lib_accept;
	/**
    class->accept4                     = adl_lib_accept4;
	*/
    class->recv                        = adl_lib_recv;
	class->recvfrom                    = adl_lib_recvfrom;
    /**
	class->recvmsg                     = adl_lib_recvmsg;
    class->recvmmsg                    = adl_lib_recvmmsg;
    */
	class->send                        = adl_lib_send;
	class->sendto                      = adl_lib_sendto;
	/**
    class->sendmsg                     = adl_lib_sendmsg;
	class->sendmmsg                    = adl_lib_sendmmsg;
	*/
    class->shutdown                    = adl_lib_shutdown;
	class->close                       = adl_lib_closesocket;
	class->getsockopt                  = adl_lib_getsockopt;
	class->setsockopt                  = adl_lib_setsockopt;
	class->getsockname                 = adl_lib_getsockname;
	class->getpeername                 = adl_lib_getpeername;
	class->getaddrinfo                 = adl_lib_getaddrinfo;
	class->freeaddrinfo                = adl_lib_freeaddrinfo;
	class->getnameinfo                 = adl_lib_getnameinfo;
	class->htons                       = adl_lib_htons;
	class->htonl                       = adl_lib_htonl;
	class->ntohs                       = adl_lib_ntohs;
	class->ntohl                       = adl_lib_ntohl;


    /*
        MISCELLENIOUS

    */

    class->AreFileApisANSI                                           = adl_lib_AreFileApisANSI;
    class->SetFileApisToANSI                                         = adl_lib_SetFileApisToANSI;
    class->SetFileApisToOEM                                          = adl_lib_SetFileApisToOEM;
    class->CancelIo                                                  = adl_lib_CancelIo;

    /*

        INOTIFY(MONITOR)

    */

    class->FindFirstChangeNotification                               = adl_lib_FindFirstChangeNotification;
    class->FindNextChangeNotification                                = adl_lib_FindNextChangeNotification;
    class->FindCloseChangeNotification                               = adl_lib_FindCloseChangeNotification;

    /*
            MMAP FILES

    */

    class->CreateFileMapping                                         = adl_lib_CreateFileMapping;  
    class->OpenFileMapping                                           = adl_lib_OpenFileMapping;
    class->MapViewOfFile                                             = adl_lib_MapViewOfFile;
    class->MapViewOfFileEx                                           = adl_lib_MapViewOfFileEx;
    class->FlushViewOfFile                                           = adl_lib_FlushViewOfFile;
    class->UnmapViewOfFile                                           = adl_lib_UnmapViewOfFile;

    /*
            NORMAL FILES

    */

    class->CreateFile                                                = adl_lib_CreateFile;
    class->ReadFile                                                  = adl_lib_ReadFile;
    //class->ReadFileEx                                              = adl_lib_ReadFileEx;
    class->WriteFile                                                 = adl_lib_WriteFile;
    //class->WriteFileEx                                             = adl_lib_WriteFileEx;
    class->CloseHandle                                               = adl_lib_CloseHandle;
    class->GetOverlappedResult                                       = adl_lib_GetOverlappedResult; 
    //class->GetTempFileName                                         = adl_lib_GetTempFileName;
    //class->GetTempPath                                             = adl_lib_GetTempPath;
    class->FlushFileBuffers                                          = adl_lib_FlushFileBuffers;
    //class->SetFilePointer                                          = adl_lib_SetFilePointer;
    class->SetFilePointerEx                                          = adl_lib_SetFilePointerEx;
    class->SetEndOfFile                                              = adl_lib_SetEndOfFile;
    class->GetStdHandle                                              = adl_lib_GetStdHandle;
    class->SetStdHandle                                              = adl_lib_SetStdHandle;
    class->DeleteFile                                                = adl_lib_DeleteFile;
    class->CopyFile                                                  = adl_lib_CopyFile;
    //class->CopyFileEx()                                            = adl_lib_CopyFileEx;
    class->MoveFile                                                  = adl_lib_MoveFile;
    class->MoveFileEx                                                = adl_lib_MoveFileEx;
    class->CreateHardLink                                            = adl_lib_CreateHardLink;
    class->CreateSymbolicLink                                        = adl_lib_CreateSymbolicLink;
    //class->LockFile                                                = adl_lib_LockFile; 
    class->LockFileEx                                                = adl_lib_LockFileEx; 
    //class->UnlockFile                                              = adl_lib_UnlockFile;
    class->UnlockFileEx                                              = adl_lib_UnlockFileEx;

    /*

        FILE ATTRIBUTES

    */

    //class->GetFileSize                                             = adl_lib_GetFileSize; 
    class->GetFileSizeEx                                             = adl_lib_GetFileSizeEx;
    class->GetFileType                                               = adl_lib_GetFileType;
    class->GetFileInformationByHandle                                = adl_lib_GetFileInformationByHandle;
    //class->GetFullPathName                                         = adl_lib_GetFullPathName;
    //class->GetShortPathName                                        = adl_lib_GetShortPathName;
    //class->SetFIleShortName();
    class->GetFileTime                                               = adl_lib_GetFileTime;  
    class->SetFileTime                                               = adl_lib_SetFileTime;
    class->CompareFileTime                                           = adl_lib_CompareFileTime;
    class->FileTimeToLocalFileTime                                   = adl_lib_FileTimeToLocalFileTime;
    class->FileTimeToSystemTime                                      = adl_lib_FileTimeToSystemTime;
    class->LocalFileTimeToFileTime                                   = adl_lib_LocalFileTimeToFileTime;
    class->SystemTimeToFileTime                                      = adl_lib_SystemTimeToFileTime;
    class->GetFileAttributes                                         = adl_lib_GetFileAttributes;
    //class->GetFileAttributesEx();                                  = adl_lib_GetFileAttributesEx;
    class->SetFileAttributes                                         = adl_lib_SetFileAttributes;

    /*

        CONSOLE

    */

    class->SetConsoleMode                                            = adl_lib_SetConsoleMode;
    class->ReadConsole                                               = adl_lib_ReadConsole;
    class->WriteConsole                                              = adl_lib_WriteConsole;
    class->FreeConsole                                               = adl_lib_FreeConsole;
    class->AllocConsole                                              = adl_lib_AllocConsole;

    /*
        
        DIRECTORIES

    */

    class->CreateDirectory                                           = adl_lib_CreateDirectory;
    class->CreateDirectoryEx                                         = adl_lib_CreateDirectoryEx;
    class->RemoveDirectory                                           = adl_lib_RemoveDirectory;
    //class->SearchPath                                              = adl_lib_SearchPath;
    class->SetCurrentDirectory                                       = adl_lib_SetCurrentDirectory;
    class->GetCurrentDirectory                                       = adl_lib_GetCurrentDirectory;
    class->FindFirstFile                                             = adl_lib_FindFirstFile;
    //class->FindFirstFileEx                                         = adl_lib_FindFirstFileEx;
    class->FindNextFile                                              = adl_lib_FindNextFile;
    class->FindClose                                                 = adl_lib_FindClose;












    class->CreateThread                                              = adl_lib_CreateThread;
    class->OpenThread                                                = adl_lib_OpenThread;
    class->ExitThread                                                = adl_lib_ExitThread;
    class->TerminateThread                                           = adl_lib_TerminateThread;
    class->GetExitCodeThread                                         = adl_lib_GetExitCodeThread;
    class->ResumeThread                                              = adl_lib_ResumeThread;
    class->SuspendThread                                             = adl_lib_SuspendThread;
  
    /*
    class->GetThreadDescription                                      = adl_lib_GetThreadDescription;
    class->SetThreadDescription                                      = adl_lib_SetThreadDescription;
    */
    
    class->GetThreadTimes                                            = adl_lib_GetThreadTimes;
    class->GetPriorityClass                                          = adl_lib_GetPriorityClass;
    class->SetPriorityClass                                          = adl_lib_SetPriorityClass;
    class->SetThreadPriority                                         = adl_lib_SetThreadPriority;
    class->InitializeCriticalSection                                 = adl_lib_InitializeCriticalSection;
    class->InitializeCriticalSectionEx                               = adl_lib_InitializeCriticalSectionEx;
    class->InitializeCriticalSectionAndSpinCount                     = adl_lib_InitializeCriticalSectionAndSpinCount;
    class->DeleteCriticalSection                                     = adl_lib_DeleteCriticalSection;
    class->EnterCriticalSection                                      = adl_lib_EnterCriticalSection;
    class->TryEnterCriticalSection                                   = adl_lib_TryEnterCriticalSection;
    class->LeaveCriticalSection                                      = adl_lib_LeaveCriticalSection;
    class->CreateMutex                                               = adl_lib_CreateMutex;
    class->CreateMutexEx                                             = adl_lib_CreateMutexEx;
    class->OpenMutex                                                 = adl_lib_OpenMutex;
    class->WaitForSingleObject                                       = adl_lib_WaitForSingleObject;
    class->ReleaseMutex                                              = adl_lib_ReleaseMutex;
    class->CreateSemaphore                                           = adl_lib_CreateSemaphore;
    class->CreateSemaphoreEx                                         = adl_lib_CreateSemaphoreEx;
    class->OpenSemaphore                                             = adl_lib_OpenSemaphore;
    class->ReleaseSemaphore                                          = adl_lib_ReleaseSemaphore;
    class->CreateEvent                                               = adl_lib_CreateEvent;
    class->CreateEventEx                                             = adl_lib_CreateEventEx;
    class->OpenEvent                                                 = adl_lib_OpenEvent;
    class->SetEvent                                                  = adl_lib_SetEvent;
    class->ResetEvent                                                = adl_lib_ResetEvent;
    class->PulseEvent                                                = adl_lib_PulseEvent;
    class->InitializeConditionVariable                               = adl_lib_InitializeConditionVariable;
    class->SleepConditionVariableCS                                  = adl_lib_SleepConditionVariableCS;
    class->WakeConditionVariable                                     = adl_lib_WakeConditionVariable;
    class->WakeAllConditionVariable                                  = adl_lib_WakeAllConditionVariable;



null_class:
    return;
}

void ADL_WINDOWS_Fini(ADL_WINDOWS *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_WINDOWS));

null_class:
    return;
}



#endif


#include "file/file.h"


#ifdef ADL_OS_WINDOWS




void ADL_WINDOWS_Init(ADL_WINDOWS *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

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


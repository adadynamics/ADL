#include "file_windows.h"



#ifdef ADL_OS_UNIX

$

void ADL_FILE_WINDOWS_Init(ADL_FILE_WINDOWS *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }


    class->AreFileApisANSI                                           = adl_os.AreFileApisANSI;
    class->SetFileApisToANSI                                         = adl_os.SetFileApisToANSI;
    class->SetFileApisToOEM                                          = adl_os.SetFileApisToOEM;
    class->CancelIo                                                  = adl_os.CancelIo;

    class->FindFirstChangeNotification                               = adl_os.FindFirstChangeNotification;
    class->FindNextChangeNotification                                = adl_os.FindNextChangeNotification;
    class->FindCloseChangeNotification                               = adl_os.FindCloseChangeNotification;

    class->CreateFileMapping                                         = adl_os.CreateFileMapping;  
    class->OpenFileMapping                                           = adl_os.OpenFileMapping;
    class->MapViewOfFile                                             = adl_os.MapViewOfFile;
    class->MapViewOfFileEx                                           = adl_os.MapViewOfFileEx;
    class->FlushViewOfFile                                           = adl_os.FlushViewOfFile;
    class->UnmapViewOfFile                                           = adl_os.UnmapViewOfFile;

    class->CreateFile                                                = adl_os.CreateFile;
    class->ReadFile                                                  = adl_os.ReadFile;
    //class->ReadFileEx                                              = adl_os.ReadFileEx;
    class->WriteFile                                                 = adl_os.WriteFile;
    //class->WriteFileEx                                             = adl_os.WriteFileEx;
    class->CloseHandle                                               = adl_os.CloseHandle;
    class->GetOverlappedResult                                       = adl_os.GetOverlappedResult; 
    //class->GetTempFileName                                         = adl_os.GetTempFileName;
    //class->GetTempPath                                             = adl_os.GetTempPath;
    class->FlushFileBuffers                                          = adl_os.FlushFileBuffers;
    //class->SetFilePointer                                          = adl_os.SetFilePointer;
    class->SetFilePointerEx                                          = adl_os.SetFilePointerEx;
    class->SetEndOfFile                                              = adl_os.SetEndOfFile;
    class->GetStdHandle                                              = adl_os.GetStdHandle;
    class->SetStdHandle                                              = adl_os.SetStdHandle;
    class->DeleteFile                                                = adl_os.DeleteFile;
    class->CopyFile                                                  = adl_os.CopyFile;
    //class->CopyFileEx()                                            = adl_os.CopyFileEx;
    class->MoveFile                                                  = adl_os.MoveFile;
    class->MoveFileEx                                                = adl_os.MoveFileEx;
    class->CreateHardLink                                            = adl_os.CreateHardLink;
    class->CreateSymbolicLink                                        = adl_os.CreateSymbolicLink;
    //class->LockFile                                                = adl_os.LockFile; 
    class->LockFileEx                                                = adl_os.LockFileEx; 
    //class->UnlockFile                                              = adl_os.UnlockFile;
    class->UnlockFileEx                                              = adl_os.UnlockFileEx;

    //class->GetFileSize                                             = adl_os.GetFileSize; 
    class->GetFileSizeEx                                             = adl_os.GetFileSizeEx;
    class->GetFileType                                               = adl_os.GetFileType;
    class->GetFileInformationByHandle                                = adl_os.GetFileInformationByHandle;
    //class->GetFullPathName                                         = adl_os.GetFullPathName;
    //class->GetShortPathName                                        = adl_os.GetShortPathName;
    //class->SetFIleShortName();
    class->GetFileTime                                               = adl_os.GetFileTime;  
    class->SetFileTime                                               = adl_os.SetFileTime;
    class->CompareFileTime                                           = adl_os.CompareFileTime;
    class->FileTimeToLocalFileTime                                   = adl_os.FileTimeToLocalFileTime;
    class->FileTimeToSystemTime                                      = adl_os.FileTimeToSystemTime;
    class->LocalFileTimeToFileTime                                   = adl_os.LocalFileTimeToFileTime;
    class->SystemTimeToFileTime                                      = adl_os.SystemTimeToFileTime;
    class->GetFileAttributes                                         = adl_os.GetFileAttributes;
    //class->GetFileAttributesEx();                                  = adl_os.GetFileAttributesEx;
    class->SetFileAttributes                                         = adl_os.SetFileAttributes;

    class->SetConsoleMode                                            = adl_os.SetConsoleMode;
    class->ReadConsole                                               = adl_os.ReadConsole;
    class->WriteConsole                                              = adl_os.WriteConsole;
    class->FreeConsole                                               = adl_os.FreeConsole;
    class->AllocConsole                                              = adl_os.AllocConsole;

    class->CreateDirectory                                           = adl_os.CreateDirectory;
    class->CreateDirectoryEx                                         = adl_os.CreateDirectoryEx;
    class->RemoveDirectory                                           = adl_os.RemoveDirectory;
    //class->SearchPath                                              = adl_os.SearchPath;
    class->SetCurrentDirectory                                       = adl_os.SetCurrentDirectory;
    class->GetCurrentDirectory                                       = adl_os.GetCurrentDirectory;
    class->FindFirstFile                                             = adl_os.FindFirstFile;
    //class->FindFirstFileEx                                         = adl_os.FindFirstFileEx;
    class->FindNextFile                                              = adl_os.FindNextFile;
    class->FindClose                                                 = adl_os.FindClose;



null_class:
    return;
}

void ADL_FILE_WINDOWS_Init(ADL_FILE_WINDOWS *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_FILE_WINDOWS));

null_class:
    return;
}



ADL_FILE_WINDOWS file_os;


void ADL_FILE_WINDOWS_library_init()
{
    ADL_FILE_WINDOWS_Init(&file_os);
}


#endif

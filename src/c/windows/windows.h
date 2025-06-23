#ifndef ADL_WINDOWS_WINDOWS_SRC_H
#define ADL_WINDOWS_WINDOWS_SRC_H


#include "../include/windows/windows.h"


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
#define ADL_CANCELIO CancelIO
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






#endif



#endif

#ifndef ADL_OS_FILE_DIRECTORY_H
#define ADL_OS_FILE_DIRECTORY_H



#include "../../include/os/file/directory.h"
#include "file.h"



ADL_RESULT Create(const char *name,ADL_DIRECTORY_ARGS);
ADL_RESULT Delete(const char *name);
ADL_RESULT SetCurrent(const char *name);
ADL_RESULT GetCurrent(ADL_STRING buf);
ADL_RESULT FindFirstFile(const char *name,ADL_DIRECTORY_ENTRY *buf);
ADL_RESULT FindNextFile(ADL_DIRECTORY_DESC fd,ADL_DIRECTORY_ENTRY *buf);
ADL_RESULT FindClose(ADL_DIRECTORY_DESC fd);



#endif

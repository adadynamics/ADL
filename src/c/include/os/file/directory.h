#ifndef ADL_OS_FILES_DIRECTORY_H
#define ADL_OS_FILES_DIRECTORY_H

#include "file.h"

typedef struct ADL_DIRECTORY_ENTRY
{
    u64 inode_number;
    ADL_STAT stat_buf;
    ADL_STRING name;
}ADL_DIRECTORY_ENTRY;

typedef struct ADL_DIRECTORY_ARGS
{
	u64 mode;
}ADL_DIRECTORY_ARGS;

typedef struct ADL_DIRECTORY_DESC
{
	void *handle;
#ifdef ADL_OS_UNIX
    ADL_STRING name;
#endif
}ADL_DIRECTORY_DESC;


typedef struct ADL_DIRECTORY
{
    ADL_RESULT (*Create)(const char *name,ADL_DIRECTORY_ARGS);
    ADL_RESULT (*Delete)(const char *name);
    ADL_RESULT (*SetCurrent)(const char *name);
    ADL_RESULT (*GetCurrent)(ADL_STRING buf);
    ADL_RESULT (*FindFirstFile)(const char *name,ADL_DIRECTORY_ENTRY *buf);
    ADL_RESULT (*FindNextFile)(ADL_DIRECTORY_DESC fd,ADL_DIRECTORY_ENTRY *buf);
    ADL_RESULT (*FindClose)(ADL_DIRECTORY_DESC fd);
}ADL_DIRECTORY;



void ADL_DIRECTORY_Init(ADL_DIRECTORY *class);

void ADL_DIRECTORY_Fini(ADL_DIRECTORY *class);


#endif

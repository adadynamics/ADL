#ifndef ADL_OS_FILES_DIRECTORY_H
#define ADL_OS_FILES_DIRECTORY_H

#include "file.h"

typedef struct ADL_DIRECTORY_ENTRY
{
    u64 inode_number;
    ADL_STAT sb;
    ADL_STRING name;
}ADL_DIRECTORY_ENTRY;

typedef struct ADL_DIRECTORY_ARGS
{
	u64 mode;
}ADL_DIRECTORY_ARGS;

typedef struct ADL_DIRECTORY_DESC
{
	void *handle;
    ADL_STRING name;
}ADL_DIRECTORY_DESC;


typedef struct ADL_DIRECTORY
{
    ADL_RESULT (*create)(const char *name,ADL_DIRECTORY_ARGS);
    ADL_RESULT (*delete)(const char *name);
    ADL_RESULT (*change)(const char *name);
    ADL_RESULT (*get_current)(ADL_STRING buf);
    ADL_RESULT (*find_first_file)(const char *name,ADL_DIRECTORY_ENTRY *buf);
    ADL_RESULT (*find_next_file)(ADL_DIRECTORY_DESC fd,ADL_DIRECTORY_ENTRY *buf);
    ADL_RESULT (*find_close)(ADL_DIRECTORY_DESC fd);
	bool (*check_error)(ADL_RESULT res);
	bool (*print_error)(ADL_RESULT res);
	bool (*clear_error)(ADL_RESULT res);
}ADL_DIRECTORY;



void ADL_DIRECTORY_init(ADL_DIRECTORY *directory);

void ADL_DIRECTORY_fini(ADL_DIRECTORY *directory);


#endif

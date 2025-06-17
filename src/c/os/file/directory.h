#ifndef ADL_OS_FILE_DIRECTORY_H
#define ADL_OS_FILE_DIRECTORY_H



#include "file.h"
#include "../../include/os/files/directory.h"




ADL_RESULT create_directory(const char *name,ADL_DIRECTORY_ARGS);
ADL_RESULT delete_directory(const char *name);
ADL_RESULT change_directory(const char *name);
ADL_RESULT get_current_directory(ADL_STRING buf);
ADL_RESULT find_first_file_directory(const char *name,ADL_DIRECTORY_ENTRY *buf);
ADL_RESULT find_next_file_directory(ADL_DIRECTORY_DESC fd,ADL_DIRECTORY_ENTRY *buf);
ADL_RESULT find_close_directory(ADL_DIRECTORY_DESC fd);
bool check_error_directory(ADL_RESULT res);
bool print_error_directory(ADL_RESULT res);
bool clear_error_directory(ADL_RESULT res);





#endif

#ifndef ADL_SRC_UNIX_USER_USER_H
#define ADL_SRC_UNIX_USER_USER_H


#include "../unix.h"

#ifdef ADL_OS_UNIX




#ifndef ADL_GETPWNAM
#define ADL_GETPWNAM getpwnam
#endif

#ifndef ADL_GETPWUID
#define ADL_GETPWUID getpwuid
#endif

#ifndef ADL_GETPWENT
#define ADL_GETPWENT getpwent
#endif

#ifndef ADL_SETPWENT
#define ADL_SETPWENT setpwent
#endif

#ifndef ADL_ENDPWENT
#define ADL_ENDPWENT endpwent
#endif


#ifndef ADL_GETGRNAM
#define ADL_GETGRNAM getgrnam
#endif

#ifndef ADL_GETGRGID
#define ADL_GETGRGID getgrgid
#endif

#ifndef ADL_GETGRENT
#define ADL_GETGRENT getgrent
#endif

#ifndef ADL_SETGRENT
#define ADL_SETGRENT setgrent
#endif

#ifndef ADL_ENDGRENT
#define ADL_ENDGRENT endgrent
#endif


#ifndef ADL_GETSPNAM
#define ADL_GETSPNAM getspnam
#endif

#ifndef ADL_GETSPENT
#define ADL_GETSPENT getspent
#endif

#ifndef ADL_SETSPENT
#define ADL_SETSPENT setspent
#endif

#ifndef ADL_ENDSPENT
#define ADL_ENDSPENT endspent
#endif

#ifndef ADL_CRYPT
#define ADL_CRYPT crypt
#endif


ADL_RESULT adl_lib_getpwnam(const char *name);
ADL_RESULT adl_lib_getpwuid(uid_t uid);
ADL_RESULT adl_lib_getpwent();
ADL_RESULT adl_lib_setpwent();
ADL_RESULT adl_lib_endpwent();
ADL_RESULT adl_lib_getgrnam(const char *name);
ADL_RESULT adl_lib_getgrgid(gid_t gid);
ADL_RESULT adl_lib_getgrent();
ADL_RESULT adl_lib_setgrent();
ADL_RESULT adl_lib_endgrent();
ADL_RESULT adl_lib_getspnam(const char *name);
ADL_RESULT adl_lib_getspent();
ADL_RESULT adl_lib_setspent();
ADL_RESULT adl_lib_endspent();
ADL_RESULT adl_lib_crypt(const char *key,const char *salt);




#endif


#endif

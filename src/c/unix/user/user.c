#include "user.h"


#ifdef ADL_OS_UNIX




/*
            USER ACCOUNT MANAGEMENT
*/




/*

ADL_RESULT adl_lib_getpwnam(const char *name)

            a wrapper for getpwnam library call on unix systems

            INPUT  : (const char *name)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_getpwnam(const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETPWNAM(name);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_getpwuid(uid_t uid)

            a wrapper for getpwuid library call on unix systems

            INPUT  : (uid_t uid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_getpwuid(uid_t uid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETPWUID(uid);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_getpwent()

            a wrapper for getpwent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_getpwent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETPWENT();
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_setpwent()

            a wrapper for setpwent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_setpwent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_SETPWENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_lib_endpwent()

            a wrapper for endpwent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_endpwent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_ENDPWENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_lib_getgrnam(const char *name)

            a wrapper for getgrnam library call on unix systems

            INPUT  : (const char *name)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_getgrnam(const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETGRNAM(name);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_getgrgid(gid_t gid)

            a wrapper for getgrgid library call on unix systems

            INPUT  : (gid_t gid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_getgrgid(gid_t gid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETGRGID(gid);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_getgrent()

            a wrapper for getgrent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_getgrent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETGRENT();
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_lib_setgrent()

            a wrapper for setgrent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_setgrent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_SETGRENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_endgrent()

            a wrapper for endgrent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_endgrent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_ENDGRENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_getspnam(const char *name)

            a wrapper for getpwuid library call on unix systems

            INPUT  : (const char *name)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_getspnam(const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETSPNAM(name);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_getspent()

            a wrapper for getspent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_getspent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_GETSPENT();
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_lib_setspent()

            a wrapper for setspent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_setspent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_SETSPENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_endspent()

            a wrapper for endspent library call on unix systems

            INPUT  : ()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_endspent()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    ADL_ENDSPENT();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

ADL_RESULT adl_lib_crypt(const char *key,const char *salt)

            a wrapper for crypt library call on unix systems

            INPUT  : (const char *key,const char *salt)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_lib_crypt(const char *key,const char *salt)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_CRYPT(key,salt);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}







#endif

#include "thread.h"


#ifdef ADL_OS_UNIX





/*
        PTHREADS
*/


/*

ADL_RESULT adl_lib_pthread_attr_destroy
    
            a wrapper for the pthread_attr_destroy system call on unix systems
            
            INPUT  : pthread_attr_t *attr
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_destroy(pthread_attr_t *attr)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_DESTROY(attr);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_getcpuclockid
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_getcpuclockid(pthread_t thread, clockid_t *clockid)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_GETCPUCLOCKID(thread,clockid);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_getaffinity_np(const pthread_attr_t *attr,size_t cpusetsize,cpu_set_t *cpuset)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_GETAFFINITY_NP(attr,cpusetsize,cpuset);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_getname_np(pthread_t thread, char *name,size_t size)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_GETNAME_NP(thread,name,size);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_getdetachstate(const pthread_attr_t *attr,int *detachstate)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_GETDETACHSTATE(attr,detachstate);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_getschedparam(pthread_t thread,int *restrict policy,struct sched_param *restrict param)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_GETSCHEDPARAM(thread,policy,param);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_getguardsize(const pthread_attr_t *restrict attr,size_t *restrict guardsize)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_GETGUARDSIZE(attr,guardsize);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_join(pthread_t thread,void **retval)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_JOIN(thread,retval);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_getinheritsched(const pthread_attr_t *restrict attr,int *restrict inheritsched)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_GETINHERITSCHED(attr,inheritsched);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_kill(pthread_t thread,int sig)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_KILL(thread,sig);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_getschedparam(const pthread_attr_t *restrict attr,struct sched_param *restrict param)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_GETSCHEDPARAM(attr,param);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_getschedpolicy(const pthread_attr_t *restrict attr,int *restrict policy)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_GETSCHEDPOLICY(attr,policy);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_mutexattr_getpshared(const pthread_mutexattr_t *restrict attr,int *restrict pshared)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_MUTEXATTR_GETPSHARED(attr,pshared);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_getscope(const pthread_attr_t *restrict attr,int *restrict scope)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_GETSCOPE(attr,scope);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_mutexattr_getrobust(const pthread_mutexattr_t *attr,int *robustness)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_MUTEXATTR_GETROBUST(attr,robustness);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_getsigmask_np(const pthread_attr_t *attr,sigset_t *sigmask)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_GETSIGMASK_NP(attr,sigmask);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_getstack(const pthread_attr_t *restrict attr,void **restrict stackaddr,size_t *restrict stacksize)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_GETSTACK(attr,stackaddr,stacksize);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_mutexattr_setpshared(pthread_mutexattr_t *attr,int pshared)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_MUTEXATTR_SETPSHARED(attr,pshared);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_mutexattr_setrobust(pthread_mutexattr_t *attr,int robustness)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_MUTEXATTR_SETROBUST(attr,robustness);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_getstacksize(const pthread_attr_t *restrict attr,size_t *restrict stacksize)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_GETSTACKSIZE(attr,stacksize);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_init(pthread_attr_t *attr)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_INIT(attr);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_mutex_consistent(pthread_mutex_t *mutex)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_MUTEX_CONSISTENT(mutex);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_setaffinity_np(pthread_attr_t *attr,size_t cpusetsize,const cpu_set_t *cpuset)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_SETAFFINITY_NP(attr,cpusetsize,cpuset);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_setdetachstate(pthread_attr_t *attr,int detachstate)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_SETDETACHSTATE(attr,detachstate);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t *restrict attr,int *restrict pref)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_RWLOCKATTR_GETKIND_NP(attr,pref);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_setguardsize(pthread_attr_t *attr,size_t guardsize)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_SETGUARDSIZE(attr,guardsize);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *attr,int pref)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_RWLOCKATTR_SETKIND_NP(attr,pref);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_setinheritsched(pthread_attr_t *attr,int inheritsched)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_SETINHERITSCHED(attr,inheritsched);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_self(void)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SELF();
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_setschedparam(pthread_attr_t *restrict attr,const struct sched_param *restrict param)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_SETSCHEDPARAM(attr,param);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_setaffinity_np(pthread_t thread,size_t cpusetsize,const cpu_set_t *cpuset)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SETAFFINITY_NP(thread,cpusetsize,cpuset);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_setschedpolicy(pthread_attr_t *attr,int policy)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_SETSCHEDPOLICY(attr,policy);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_setattr_default_np(const pthread_attr_t *attr)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SETATTR_DEFAULT_NP(attr);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_setscope(pthread_attr_t *attr,int scope)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_SETSCOPE(attr,scope);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_setcancelstate(int state,int *oldstate)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SETCANCELSTATE(state,oldstate);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_setsigmask_np(pthread_attr_t *attr,const sigset_t *sigmask)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_SETSIGMASK_NP(attr,sigmask);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_setcanceltype(int type,int *oldtype)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SETCANCELTYPE(type,oldtype);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_setstack(pthread_attr_t *attr,void *stackaddr,size_t stacksize)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_SETSTACK(attr,stackaddr,stacksize);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_setconcurrency(int new_level)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SETCONCURRENCY(new_level);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_setname_np(pthread_t thread,const char *name)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SETNAME_NP(thread,name);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_attr_setstacksize(pthread_attr_t *attr,size_t stacksize)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_ATTR_SETSTACKSIZE(attr,stacksize);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_setschedparam(pthread_t thread,int policy,const struct sched_param *param)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SETSCHEDPARAM(thread,policy,param);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_cancel(pthread_t thread)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_CANCEL(thread);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_setschedprio(pthread_t thread,int prio)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SETSCHEDPRIO(thread,prio);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

/**

ADL_RESULT adl_lib_pthread_cleanup_pop(int execute)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_CLEANUP_POP(execute);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}

*/





/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_sigmask(int how,const sigset_t *set,sigset_t *oldset)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SIGMASK(how,set,oldset);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


/**
ADL_RESULT adl_lib_pthread_cleanup_pop_restore_np(int execute)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_CLEANUP_POP_RESTORE_NP(execute);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}


*/




/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_sigqueue(pthread_t thread,int sig,const union sigval value)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SIGQUEUE(thread,sig,value);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


/**
ADL_RESULT adl_lib_pthread_cleanup_push(void (*routine)(void *),void *arg)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_CLEANUP_PUSH(routine,arg);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}



*/



/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_spin_destroy(pthread_spinlock_t *lock)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SPIN_DESTROY(lock);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_spin_init(pthread_spinlock_t *lock,int pshared)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SPIN_INIT(lock,pshared);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_create(pthread_t *restrict thread,const pthread_attr_t *restrict attr,void *(*start_routine)(void *),void *restrict arg)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_CREATE(thread,attr,start_routine,arg);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_spin_lock(pthread_spinlock_t *lock)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SPIN_LOCK(lock);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_detach(pthread_t thread)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_DETACH(thread);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_spin_trylock(pthread_spinlock_t *lock)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SPIN_TRYLOCK(lock);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_equal(pthread_t t1,pthread_t t2)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_EQUAL(t1,t2);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_spin_unlock(pthread_spinlock_t *lock)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_SPIN_UNLOCK(lock);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_exit(void *retval)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    ADL_PTHREAD_EXIT(retval);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_testcancel(void)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    ADL_PTHREAD_TESTCANCEL();
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_getaffinity_np(pthread_t thread,size_t cpusetsize,cpu_set_t *cpuset)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_GETAFFINITY_NP(thread,cpusetsize,cpuset);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_timedjoin_np(pthread_t thread,void **retval,const struct timespec *abstime)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_TIMEDJOIN_NP(thread,retval,abstime);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_getattr_default_np(pthread_attr_t *attr)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_GETATTR_DEFAULT_NP(attr);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_tryjoin_np(pthread_t thread,void **retval)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_TRYJOIN_NP(thread,retval);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}







/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_getattr_np(pthread_t thread,pthread_attr_t *attr)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_GETATTR_NP(thread,attr);
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
}








/*

ADL_RESULT adl_lib_pthread_
    
            a wrapper for the pthread_ system call on unix systems
            
            INPUT  : 
            OUTPUT : returns a ADL_RESULT structure


            ****
                on success the ret member of the structure contains zero

                on error the ret member of the structure is set to -1, the errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_lib_pthread_getconcurrency(void)
{
    ADL_UNIX_PTHREAD_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PTHREAD_GETCONCURRENCY();
    ADL_UNIX_PTHREAD_FINI(rdr_ret,rdr_retptr);
} 









#endif

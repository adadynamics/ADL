#include "time.h"


#ifdef ADL_OS_UNIX



/*

                TIME

*/



/*

ADL_RESULT adl_sys_pause(void)

            a wrapper for pause system call on unix systems

            INPUT  :(void)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pause(void)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_PAUSE();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_nanosleep(const struct timespec *duration,struct timespec *remaining)

            a wrapper for nanosleep system call on unix systems

            INPUT  :(const struct timespec *duration,struct timespec *remaining)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_nanosleep(const struct timespec *duration,struct timespec *remaining)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_NANOSLEEP(duration,remaining);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_getitimer(int which,struct itimerval *current)

            a wrapper for getitimer system call on unix systems

            INPUT  :(int which,struct itimerval *current)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_obsolete___

ADL_RESULT adl_sys_getitimer(int which,struct itimerval *current)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_GETITIMER(which,current);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_setitimer(int which,const struct itimerval *new,struct itimerval *old)

            a wrapper for setitimer system call on unix systems

            INPUT  :(int which,const struct itimerval *new,struct itimerval *old)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_setitimer(int which,const struct itimerval *new,struct itimerval *old)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_SETITIMER(which,new,old);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
___adl_end_obsolete___




/*

ADL_RESULT adl_sys_alarm(unsigned int seconds)

            a wrapper for alarm system call on unix systems

            INPUT  :(unsigned int seconds)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_alarm(unsigned int seconds)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_ALARM(seconds);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_gettimeofday(struct timeval *tv,struct timezone *tz)

            a wrapper for gettimeofday system call on unix systems

            INPUT  :(struct timeval *tv,struct timezone *tz)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_obsolete___

ADL_RESULT adl_sys_gettimeofday(struct timeval *tv,struct timezone *tz)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_GETTIMEOFDAY(tv,tz);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*
ADL_RESULT adl_sys_settimeofday(const struct timeval *tv,const struct timezone *tz)

            a wrapper for settimeofday system call on unix systems

            INPUT  :(const struct timeval *tv,const struct timezone *tz)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_settimeofday(const struct timeval *tv,const struct timezone *tz)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_SETTIMEOFDAY(tv,tz);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
___adl_end_obsolete___





/*

ADL_RESULT adl_sys_timer_create(clockid_t clockid,struct sigevent *sigevent,timer_t *timerid)

            a wrapper for timer_create system call on unix systems

            INPUT  :(clockid_t clockid,struct sigevent *sigevent,timer_t *timerid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_timer_create(clockid_t clockid,struct sigevent *sigevent,timer_t *timerid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMER_CREATE(clockid,sigevent,timerid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_timer_settime(timer_t timerid, int flags,const struct itimerspec *new,struct itimerspec *old)

            a wrapper timer_settime system call on unix systems

            INPUT  :(timer_t timerid, int flags,const struct itimerspec *new,struct itimerspec *old)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_timer_settime(timer_t timerid, int flags,const struct itimerspec *new,struct itimerspec *old)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMER_SETTIME(timerid,flags,new,old);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_timer_gettime(timer_t timerid, struct itimerspec *current)

            a wrapper for timer_gettime system call on unix systems

            INPUT  :(timer_t timerid, struct itimerspec *current)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_timer_gettime(timer_t timerid, struct itimerspec *current)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMER_GETTIME(timerid,current);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_timer_getoverrun(timer_t timerid)

            a wrapper for timer_getoverrun system call on unix systems

            INPUT  :(timer_t timerid)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_timer_getoverrun(timer_t timerid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMER_GETOVERRUN(timerid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_timer_delete(timer_t timerid)

            a wrapper for timer-delete system call on unix systems

            INPUT  :(timer_t timeri
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_timer_delete(timer_t timerid)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMER_DELETE(timerid);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_clock_settime(clockid_t clockid,const struct timespec *tp)

            a wrapper for clock_settime system call on unix systems

            INPUT  :(clockid_t clockid,const struct timespec *tp)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_clock_settime(clockid_t clockid,const struct timespec *tp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_CLOCK_SETTIME(clockid,tp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_clock_gettime(clockid_t clockid,struct timespec *tp)

            a wrapper for clock_gettime system call on unix systems

            INPUT  :(clockid_t clockid,struct timespec *tp)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_clock_gettime(clockid_t clockid,struct timespec *tp)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_CLOCK_GETTIME(clockid,tp);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_clock_getres(clockid_t clockid,struct timespec *res)

            a wrapper for clock_getres system call on unix systems

            INPUT  :(clockid_t clockid,struct timespec *res)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_clock_getres(clockid_t clockid,struct timespec *res)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_CLOCK_GETRES(clockid,res);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}


/*

ADL_RESULT adl_sys_clock_nanosleep(clockid_t clockid, int flags,const struct timespec *duration,struct timespec *remaining)

            a wrapper for clock_nanosleep system call on unix systems

            INPUT  :(clockid_t clockid, int flags,const struct timespec *duration,struct timespec *remaining)

            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_clock_nanosleep(clockid_t clockid, int flags,const struct timespec *duration,struct timespec *remaining)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_CLOCK_NANOSLEEP(clockid,flags,duration,remaining);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_clock_adjtime(clockid_t clockid,struct timex *buf)

            a wrapper for clock_adjtime system call on unix systems

            INPUT  :(clockid_t clockid,struct timex *buf)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_clock_adjtime(clockid_t clockid,struct timex *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_CLOCK_ADJTIME(clockid,buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_adjtimex(struct timex *buf)

            a wrapper for adjtimex system call on unix systems

            INPUT  :(struct timex *buf)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_adjtimex(struct timex *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_ADJTIMEX(buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_time(time_t *timep)

            a wrapper for time system call on unix systems

            INPUT  :(time_t *timep)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_time(time_t *timep)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIME(timep);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_timerfd_settime(int fd,int flags,const struct itimerspec *new,struct itimerspec *old)

            a wrapper timerfd_settime system call on unix systems

            INPUT  :(int fd,int flags,const struct itimerspec *new,struct itimerspec *old)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_timerfd_settime(int fd,int flags,const struct itimerspec *new,struct itimerspec *old)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMERFD_SETTIME(fd,flags,new,old);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_timerfd_gettime(int fd,struct itimerspec *current)

            a wrapper for timerfd_gettime system call on unix systems

            INPUT  :(const struct timespec *duration,struct timespec *remaining)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_timerfd_gettime(int fd,struct itimerspec *current)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMERFD_GETTIME(fd,current);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_timerfd_create(int clockid, int flags)

            a wrapper for timerfd_create system call on unix systems

            INPUT  :(int clockid, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_timerfd_create(int clockid, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret =  ADL_TIMERFD_CREATE(clockid,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}
___adl_end_linux___








#endif



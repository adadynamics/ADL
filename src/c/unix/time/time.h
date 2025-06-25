#ifndef ADL_SRC_UNIX_TIME_TIME_H
#define ADL_SRC_UNIX_TIME_TIME_H


#include "../unix.h"

#ifdef ADL_OS_UNIX





#ifndef ADL_PAUSE
#define ADL_PAUSE pause
#endif

#ifndef ADL_NANOSLEEP
#define ADL_NANOSLEEP nanosleep
#endif

#ifndef ADL_GETITIMER
#define ADL_GETITIMER getitimer
#endif

#ifndef ADL_ALARM
#define ADL_ALARM alarm
#endif

#ifndef ADL_SETITIMER
#define ADL_SETITIMER setitimer
#endif

#ifndef ADL_GETTIMEOFDAY
#define ADL_GETTIMEOFDAY gettimeofday
#endif

#ifndef ADL_SETTIMEOFDAY
#define ADL_SETTIMEOFDAY settimeofday 
#endif

#ifndef ADL_TIMER_CREATE
#define ADL_TIMER_CREATE timer_create 
#endif

#ifndef ADL_TIMER_SETTIME
#define ADL_TIMER_SETTIME timer_settime 
#endif

#ifndef ADL_TIMER_GETTIME
#define ADL_TIMER_GETTIME timer_gettime 
#endif

#ifndef ADL_TIMER_GETOVERRUN
#define ADL_TIMER_GETOVERRUN timer_getoverrun 
#endif

#ifndef ADL_TIMER_DELETE
#define ADL_TIMER_DELETE timer_delete 
#endif

#ifndef ADL_CLOCK_SETTIME
#define ADL_CLOCK_SETTIME clock_settime 
#endif

#ifndef ADL_CLOCK_GETTIME
#define ADL_CLOCK_GETTIME clock_gettime 
#endif

#ifndef ADL_CLOCK_GETRES
#define ADL_CLOCK_GETRES clock_getres 
#endif

#ifndef ADL_CLOCK_NANOSLEEP
#define ADL_CLOCK_NANOSLEEP clock_nanosleep 
#endif

#ifndef ADL_ADJTIMEX
#define ADL_ADJTIMEX adjtimex 
#endif

#ifndef ADL_CLOCK_ADJTIME
#define ADL_CLOCK_ADJTIME clock_adjtime 
#endif

#ifndef ADL_TIME
#define ADL_TIME time 
#endif



___adl_linux_std___

#ifndef ADL_TIMERFD_SETTIME
#define ADL_TIMERFD_SETTIME timerfd_settime 
#endif

#ifndef ADL_TIMERFD_GETTIME
#define ADL_TIMERFD_GETTIME timerfd_gettime 
#endif

#ifndef ADL_TIMERFD_CREATE
#define ADL_TIMERFD_CREATE timerfd_create 
#endif

___adl_end_linux___






ADL_RESULT adl_sys_pause(void);
ADL_RESULT adl_sys_nanosleep(const struct timespec *duration,struct timespec *remaining);
ADL_RESULT adl_sys_getitimer(int which,struct itimerval *current);
ADL_RESULT adl_sys_setitimer(int which,const struct itimerval *new,struct itimerval *old);
ADL_RESULT adl_sys_alarm(unsigned int seconds);
ADL_RESULT adl_sys_gettimeofday(struct timeval *tv,struct timezone *tz);
ADL_RESULT adl_sys_settimeofday(const struct timeval *tv,const struct timezone *tz);
ADL_RESULT adl_sys_timer_create(clockid_t clockid,struct sigevent *sigevent,timer_t *timerid);
ADL_RESULT adl_sys_timer_settime(timer_t timerid, int flags,const struct itimerspec *new,struct itimerspec *old);
ADL_RESULT adl_sys_timer_gettime(timer_t timerid, struct itimerspec *current);
ADL_RESULT adl_sys_timer_getoverrun(timer_t timerid);
ADL_RESULT adl_sys_timer_delete(timer_t timerid);
ADL_RESULT adl_sys_clock_settime(clockid_t clockid,const struct timespec *tp);
ADL_RESULT adl_sys_clock_gettime(clockid_t clockid,struct timespec *tp);
ADL_RESULT adl_sys_clock_getres(clockid_t clockid,struct timespec *res);
ADL_RESULT adl_sys_clock_nanosleep(clockid_t clockid, int flags,const struct timespec *duration,struct timespec *remaining);
ADL_RESULT adl_sys_clock_adjtime(clockid_t clockid,struct timex *buf);
ADL_RESULT adl_sys_adjtimex(struct timex *buf);
ADL_RESULT adl_sys_time(time_t *timep);
ADL_RESULT adl_sys_timerfd_settime(int fd,int flags,const struct itimerspec *new,struct itimerspec *old);
ADL_RESULT adl_sys_timerfd_gettime(int fd,struct itimerspec *current);
ADL_RESULT adl_sys_timerfd_create(int clockid, int flags);






#endif




#endif

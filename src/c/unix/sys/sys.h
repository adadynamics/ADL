#ifndef ADL_SRC_UNIX_SYS_SYS_H
#define ADL_SRC_UNIX_SYS_SYS_H


#include "../unix.h"

#ifdef ADL_OS_UNIX






___adl_linux_std___
___adl_syscall___

#ifndef ADL_REBOOT
#define ADL_REBOOT reboot
#endif

#ifndef ADL_DELETE_MODULE
#define ADL_DELETE_MODULE delete_module
#endif

#ifndef ADL_FINIT_MODULE
#define ADL_FINIT_MODULE finit_module
#endif


#ifndef ADL_INIT_MODULE
#define ADL_INIT_MODULE init_module
#endif

#ifndef ADL_KEXEC_FILE_LOAD
#define ADL_KEXEC_FILE_LOAD kexec_file_load
#endif

#ifndef ADL_KEXEC_LOAD
#define ADL_KEXEC_LOAD kexec_load
#endif

#ifndef ADL_SYSLOG
#define ADL_SYSLOG syslog
#endif

___adl_end_syscall___

#ifndef ADL_SYSINFO
#define ADL_SYSINFO sysinfo
#endif

#ifndef ADL_GETRANDOM
#define ADL_GETRANDOM getrandom
#endif

___adl_end_linux___

___adl_nostd___

#ifndef ADL_SETDOMAINNAME
#define ADL_SETDOMAINNAME setdomainname
#endif

#ifndef ADL_GETDOMAINNAME
#define ADL_GETDOMAINNAME getdomainname
#endif

#ifndef ADL_SETHOSTNAME
#define ADL_SETHOSTNAME sethostname
#endif

___adl_end_nostd___

#ifndef ADL_GETHOSTNAME
#define ADL_GETHOSTNAME gethostname
#endif






ADL_RESULT adl_sys_reboot(int magic,int magic2,int op,void *arg);
ADL_RESULT adl_sys_delete_module(const char *name,unsigned int flags);
ADL_RESULT adl_sys_finit_module(int fd,const char *param_values,int flags);
ADL_RESULT adl_sys_init_module(void *module_image,unsigned long len,const char *param_value);
ADL_RESULT adl_sys_kexec_file_load(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags);
ADL_RESULT adl_sys_kexec_load(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags);
ADL_RESULT adl_sys_syslog(int type,char *bufp,int len);
ADL_RESULT adl_sys_sysinfo(struct sysinfo *info);
ADL_RESULT adl_sys_getrandom(void *buf,size_t buflen,unsigned int flags);
ADL_RESULT adl_sys_setdomainname(const char *name,size_t len);
ADL_RESULT adl_sys_getdomainname(char *name,size_t len);
ADL_RESULT adl_sys_sethostname(const char *name,size_t len);
ADL_RESULT adl_sys_gethostname(char *name,size_t len);



#endif



#endif

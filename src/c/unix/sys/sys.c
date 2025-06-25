#include "sys.h"



#ifdef ADL_OS_UNIX





/*

                OVERALL SYSTEM

*/


/*

ADL_RESULT adl_sys_reboot(int magic,int magic2,int op,void *arg)

            a wrapper for reboot system call on unix systems

            INPUT  :(int magic,int magic2,int op,void *arg)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___
___adl_syscall___


ADL_RESULT adl_sys_reboot(int magic,int magic2,int op,void *arg)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_REBOOT(magic,magic2,op,arg);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_delete_module(const char *name,unsigned int flags)

            a wrapper for delete_module system call on unix systems

            INPUT  :(const char *name,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_delete_module(const char *name,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_DELETE_MODULE(name,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_finit_module(int fd,const char *param_values,int flags)

            a wrapper for finit_module system call on unix systems

            INPUT  :(int fd,const char *param_values,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_finit_module(int fd,const char *param_values,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FINIT_MODULE(fd,param_values,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_init_module(void *module_image,unsigned long len,const char *param_value)

            a wrapper for init_module system call on unix systems

            INPUT  :(void *module_image,unsigned long len,const char *param_value)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_init_module(void *module_image,unsigned long len,const char *param_value)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_INIT_MODULE(module_image,len,param_value);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_kexec_file_load(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags)

            a wrapper for kexec_file_load system call on unix systems

            INPUT  :(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags)

            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_kexec_file_load(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_KEXEC_FILE_LOAD(kernel_fd,initrd_fd,cmdline_len,cmdline,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_kexec_load(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags)

            a wrapper for kexec_load  system call on unix systems

            INPUT  :(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_kexec_load(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_KEXEC_LOAD(entry,nr_segments,segments,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_syslog(int type,char *bufp,int len)

            a wrapper for syslog system call on unix systems

            INPUT  :(int type,char *bufp,int len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_syslog(int type,char *bufp,int len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYSLOG(type,bufp,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___






/*

ADL_RESULT adl_sys_sysinfo(struct sysinfo *info)

            a wrapper for sysinfo system call on unix systems

            INPUT  :(struct sysinfo *info)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sysinfo(struct sysinfo *info)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SYSINFO(info);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_getrandom(void *buf,size_t buflen,unsigned int flags)

            a wrapper for getrandom system call on unix systems

            INPUT  :(void *buf,size_t buflen,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getrandom(void *buf,size_t buflen,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETRANDOM(buf,buflen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___





/*

ADL_RESULT adl_sys_setdomainname(const char *name,size_t len)

            a wrapper for setdomainname system call on unix systems

            INPUT  :(const char *name,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_nostd___


ADL_RESULT adl_sys_setdomainname(const char *name,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETDOMAINNAME(name,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_getdomainname(char *name,size_t len)

            a wrapper for getdomainname system call on unix systems

            INPUT  :(char *name,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_getdomainname(char *name,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETDOMAINNAME(name,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sethostname(const char *name,size_t len)

            a wrapper for sethostname system call on unix systems

            INPUT  :(const char *name,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sethostname(const char *name,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SETHOSTNAME(name,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_nostd___





/*

ADL_RESULT adl_sys_gethostname(char *name,size_t len)

            a wrapper for gethostname system call on unix systems

            INPUT  :(char *name,size_t len
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_gethostname(char *name,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GETHOSTNAME(name,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}










#endif


#include "memory.h"


#ifdef ADL_OS_UNIX






/*

                MEMORY MANAGEMENT

*/




/*

ADL_RESULT adl_sys_brk(void *addr)

            a wrapper for brk system call on unix systems

            INPUT  :(void *addr)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_nostd___

ADL_RESULT adl_sys_brk(void *addr)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_BRK(addr);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_sbrk(intptr_t increment)

            a wrapper for sbrk system call on unix systems

            INPUT  :(intptr_t increment)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_sbrk(intptr_t increment)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_SBRK(increment);
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_madvise(void *addr,size_t length,int advice)

            a wrapper for madvise system call on unix systems

            INPUT  :(void *addr,size_t length,int advice)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_madvise(void *addr,size_t length,int advice)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MADVISE(addr,length,advice);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_mincore(void *addr,size_t length,unsigned char *vec)

            a wrapper for mincore system call on unix systems

            INPUT  :(void *addr,size_t length,unsigned char *vec)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mincore(void *addr,size_t length,unsigned char *vec)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MINCORE(addr,length,vec);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_nostd___





/*

ADL_RESULT adl_sys_get_mempolicy(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags)

            a wrapper for get_mempolicy system call on unix systems

            INPUT  :(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___

ADL_RESULT adl_sys_get_mempolicy(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GET_MEMPOLICY(mode,nodemask,maxnode,addr,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_keyctl(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5)

            a wrapper for keyctl system call on unix systems

            INPUT  :(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_syscall___

ADL_RESULT adl_sys_keyctl(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_KEYCTL(operation,arg2,arg3,arg4,arg5);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_membarrier(int cmd,unsigned int flags,int cpu_id)

            a wrapper for membarrier system call on unix systems

            INPUT  :(int cmd,unsigned int flags,int cpu_id)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_membarrier(int cmd,unsigned int flags,int cpu_id)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MEMBARRIER(cmd,flags,cpu_id);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_memfd_secret(unsigned int flags)

            a wrapper for memfd_secret system call on unix systems

            INPUT  :(unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_memfd_secret(unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MEMFD_SECRET(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_userfaultfd(int flags)

            a wrapper for userfaultfd system call on unix systems

            INPUT  :(int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_userfaultfd(int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_USERFAULTFD(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___





/*

ADL_RESULT adl_sys_mbind(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags)

            a wrapper for mbind system call on unix systems

            INPUT  :(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mbind(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MBIND(addr,len,mode,nodemask,maxnode,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_memfd_create(const char *name,unsigned int flags)

            a wrapper for memfd_create system call on unix systems

            INPUT  :(const char *name,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_memfd_create(const char *name,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MEMFD_CREATE(name,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_migrate_pages(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes)

            a wrapper for migrate_pages system call on unix systems

            INPUT  :(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_migrate_pages(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MIGRATE_PAGES(pid,maxnode,old_nodes,new_nodes);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_mlock2(const void *addr,size_t len,unsigned int flags)

            a wrapper for mlock2 system call on unix systems

            INPUT  :(const void *addr,size_t len,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mlock2(const void *addr,size_t len,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MLOCK2(addr,len,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_mremap(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address)

            a wrapper for mremap system call on unix systems

            INPUT  :(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mremap(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_MREMAP(old_address,old_size,new_size,flags,new_address);
    if(ADL_CHECK_EQUAL(rdr_retptr,MAP_FAILED))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_move_pages(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags)

            a wrapper for move_pages system call on unix systems

            INPUT  :(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_move_pages(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MOVE_PAGES(pid,count,pages,nodes,status,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_request_key(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring)

            a wrapper for request_key system call on unix systems

            INPUT  :(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_request_key(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_REQUEST_KEY(type,description,callout_info,dest_keyring);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_pkey_alloc(unsigned int flags,unsigned int access_rights)

            a wrapper for pkey_alloc system call on unix systems

            INPUT  :(unsigned int flags,unsigned int access_rights)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pkey_alloc(unsigned int flags,unsigned int access_rights)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PKEY_ALLOC(flags,access_rights);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_pkey_free(int pkey)

            a wrapper for pkey_free system call on unix systems

            INPUT  :(int pkey)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pkey_free(int pkey)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PKEY_FREE(pkey);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_pkey_mprotect(void *addr,size_t len,int prot,int pkey)

            a wrapper for pkey_mprotect system call on unix systems

            INPUT  :(void *addr,size_t len,int prot,int pkey)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_pkey_mprotect(void *addr,size_t len,int prot,int pkey)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_PKEY_MPROTECT(addr,len,prot,pkey);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_set_mempolicy(int mode,const unsigned long *nodemask,unsigned long maxnode)

            a wrapper for set_mempolicy system call on unix systems

            INPUT  :(int mode,const unsigned long *nodemask,unsigned long maxnode)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_set_mempolicy(int mode,const unsigned long *nodemask,unsigned long maxnode)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SET_MEMPOLICY(mode,nodemask,maxnode);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_swapoff(const char *path)

            a wrapper for swapoff system call on unix systems

            INPUT  :(const char *path)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_swapoff(const char *path)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SWAPOFF(path);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_swapon(const char *path,int swapflags)

            a wrapper for swapon system call on unix systems

            INPUT  :(const char *path,int swapflags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_swapon(const char *path,int swapflags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SWAPON(path,swapflags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_vmsplice(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags)

            a wrapper for vmsplice system call on unix systems

            INPUT  :(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_sys_vmsplice(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_VMSPLICE(fd,iov,nr_segs,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_linux___




/*

ADL_RESULT adl_sys_mlock(void *addr,size_t len)

            a wrapper for mlock system call on unix systems

            INPUT  :(void *addr,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_sys_mlock(void *addr,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MLOCK(addr,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_mlockall(int flags)

            a wrapper for mlockall system call on unix systems

            INPUT  :(int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_sys_mlockall(int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MLOCKALL(flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_mmap(void *addr,size_t len,int prot,int flags,int fd,off_t offset)

            a wrapper for mmap system call on unix systems

            INPUT  :(void *addr,size_t len,int prot,int flags,int fd,off_t offset)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mmap(void *addr,size_t len,int prot,int flags,int fd,off_t offset)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_MMAP(addr,len,prot,flags,fd,offset);
    if(ADL_CHECK_EQUAL(rdr_retptr,MAP_FAILED))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

ADL_RESULT adl_sys_mprotect(void *addr,size_t len,int prot)

            a wrapper for mprotect  system call on unix systems

            INPUT  :(void *addr,size_t len,int prot)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_sys_mprotect(void *addr,size_t len,int prot)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MPROTECT(addr,len,prot);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

ADL_RESULT adl_sys_msync(void *addr,size_t len,int flags)

            a wrapper for msync system call on unix systems

            INPUT  :(void *addr,size_t len,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_sys_msync(void *addr,size_t len,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MSYNC(addr,len,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

ADL_RESULT adl_sys_munlock(const void *addr,size_t len)

            a wrapper for munlock system call on unix systems

            INPUT  :(const void *addr,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_munlock(const void *addr,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MUNLOCK(addr,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

ADL_RESULT adl_sys_munlockall()

            a wrapper for munlockall system call on unix systems

            INPUT  :()
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/



ADL_RESULT adl_sys_munlockall()
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MUNLOCKALL();
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}



/*

ADL_RESULT adl_sys_munmap(void *addr,size_t len)

            a wrapper for munmap system call on unix systems

            INPUT  :(void *addr,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_munmap(void *addr,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MUNMAP(addr,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}







#endif

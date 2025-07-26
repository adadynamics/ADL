#ifndef ADL_SRC_OS_MEMORY_PLATFORM_UNIX_MEMORY_LINUX_H
#define ADL_SRC_OS_MEMORY_PLATFORM_UNIX_MEMORY_LINUX_H

#include "../../../os.h"

#ifdef ADL_OS_UNIX

typedef struct ADL_MEMORY_LINUX
{
    ADL_RESULT (*brk)(void *addr);
    ADL_RESULT (*sbrk)(intptr_t increment);
    ADL_RESULT (*madvise)(void *addr,size_t length,int advice);
    ADL_RESULT (*mincore)(void *addr,size_t length,unsigned char *vec);
    ADL_RESULT (*get_mempolicy)(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags);
    ADL_RESULT (*keyctl)(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5);
    ADL_RESULT (*membarrier)(int cmd,unsigned int flags,int cpu_id);
    ADL_RESULT (*memfd_secret)(unsigned int flags);
    ADL_RESULT (*userfaultfd)(int flags);
    ADL_RESULT (*mbind)(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags);
    ADL_RESULT (*memfd_create)(const char *name,unsigned int flags);
    ADL_RESULT (*migrate_pages)(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes);
    ADL_RESULT (*mlock2)(const void *addr,size_t len,unsigned int flags);
    ADL_RESULT (*mremap)(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address);
    ADL_RESULT (*move_pages)(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags);
    ADL_RESULT (*request_key)(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring);
    ADL_RESULT (*pkey_alloc)(unsigned int flags,unsigned int access_rights);
    ADL_RESULT (*pkey_free)(int pkey);
    ADL_RESULT (*pkey_mprotect)(void *addr,size_t len,int prot,int pkey);
    ADL_RESULT (*set_mempolicy)(int mode,const unsigned long *nodemask,unsigned long maxnode);
    ADL_RESULT (*swapoff)(const char *path);
    ADL_RESULT (*swapon)(const char *path,int swapflags);
    ADL_RESULT (*vmsplice)(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags);
    ADL_RESULT (*mlock)(void *addr,size_t len);
    ADL_RESULT (*mlockall)(int flags);
    ADL_RESULT (*mmap)(void *addr,size_t len,int prot,int flags,int fd,off_t offset);
    ADL_RESULT (*mprotect)(void *addr,size_t len,int prot);
    ADL_RESULT (*msync)(void *addr,size_t len,int flags);
    ADL_RESULT (*munlock)(const void *addr,size_t len);
    ADL_RESULT (*munlockall)();
    ADL_RESULT (*munmap)(void *addr,size_t len);
}ADL_MEMORY_LINUX;




void ADL_MEMORY_LINUX_Init(ADL_MEMORY_LINUX *class);

void ADL_MEMORY_LINUX_Fini(ADL_MEMORY_LINUX *class);



#endif

#endif
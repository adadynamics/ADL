#ifndef ADL_SRC_UNIX_MEMORY_MEMORY_H
#define ADL_SRC_UNIX_MEMORY_MEMORY_H


#include "../unix.h"

#ifdef ADL_OS_UNIX





___adl_nostd___

#ifndef ADL_BRK
#define ADL_BRK brk
#endif

#ifndef ADL_SBRK
#define ADL_SBRK sbrk
#endif

#ifndef ADL_MADVISE
#define ADL_MADVISE madvise
#endif

#ifndef ADL_MINCORE
#define ADL_MINCORE mincore
#endif

___adl_end_nostd___



___adl_linux_std___

#ifndef ADL_GET_MEMPOLICY
#define ADL_GET_MEMPOLICY get_mempolicy
#endif

___adl_syscall___

#ifndef ADL_KEYCTL
#define ADL_KEYCTL keyctl
#endif

#ifndef ADL_MEMBARRIER
#define ADL_MEMBARRIER membarrier
#endif

#ifndef ADL_MEMFD_SECRET
#define ADL_MEMFD_SECRET memfd_secret
#endif

#ifndef ADL_USERFAULTFD
#define ADL_USERFAULTFD userfaultfd
#endif

___adl_end_syscall___

#ifndef ADL_MBIND
#define ADL_MBIND mbind
#endif

#ifndef ADL_MEMFD_CREATE
#define ADL_MEMFD_CREATE memfd_create
#endif

#ifndef ADL_MIGRATE_PAGES
#define ADL_MIGRATE_PAGES migrate_pages
#endif

#ifndef ADL_MLOCK2
#define ADL_MLOCK2 mlock2
#endif

#ifndef ADL_MREMAP
#define ADL_MREMAP mremap
#endif

#ifndef ADL_MOVE_PAGES
#define ADL_MOVE_PAGES move_pages
#endif

#ifndef ADL_REQUEST_KEY
#define ADL_REQUEST_KEY request_key
#endif

#ifndef ADL_PKEY_ALLOC
#define ADL_PKEY_ALLOC pkey_alloc
#endif

#ifndef ADL_PKEY_FREE
#define ADL_PKEY_FREE pkey_free
#endif

#ifndef ADL_PKEY_MPROTECT
#define ADL_PKEY_MPROTECT pkey_mprotect
#endif

#ifndef ADL_SET_MEMPOLICY
#define ADL_SET_MEMPOLICY set_mempolicy
#endif

#ifndef ADL_SWAPOFF
#define ADL_SWAPOFF swapoff
#endif

#ifndef ADL_SWAPON
#define ADL_SWAPON swapon
#endif

#ifndef ADL_VMSPLICE
#define ADL_VMSPLICE vmsplice
#endif

___adl_end_linux___

#ifndef ADL_MLOCK
#define ADL_MLOCK mlock
#endif

#ifndef ADL_MLOCKALL
#define ADL_MLOCKALL mlockall
#endif

#ifndef ADL_MMAP
#define ADL_MMAP mmap
#endif

#ifndef ADL_MPROTECT
#define ADL_MPROTECT mprotect
#endif

#ifndef ADL_MSYNC
#define ADL_MSYNC msync
#endif

#ifndef ADL_MUNLOCK
#define ADL_MUNLOCK munlock
#endif

#ifndef ADL_MUNLOCKALL
#define ADL_MUNLOCKALL munlockall
#endif

#ifndef ADL_MUNMAP
#define ADL_MUNMAP munmap
#endif





ADL_RESULT adl_sys_brk(void *addr);
ADL_RESULT adl_sys_sbrk(intptr_t increment);
ADL_RESULT adl_sys_madvise(void *addr,size_t length,int advice);
ADL_RESULT adl_sys_mincore(void *addr,size_t length,unsigned char *vec);
ADL_RESULT adl_sys_get_mempolicy(int *mode,unsigned long *nodemask,unsigned long maxnode,void *addr,unsigned long flags);
ADL_RESULT adl_sys_keyctl(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5);
ADL_RESULT adl_sys_membarrier(int cmd,unsigned int flags,int cpu_id);
ADL_RESULT adl_sys_memfd_secret(unsigned int flags);
ADL_RESULT adl_sys_userfaultfd(int flags);
ADL_RESULT adl_sys_mbind(void *addr,unsigned long len,int mode,const unsigned long *nodemask,unsigned long maxnode,unsigned int flags);
ADL_RESULT adl_sys_memfd_create(const char *name,unsigned int flags);
ADL_RESULT adl_sys_migrate_pages(int pid,unsigned long maxnode,const unsigned long *old_nodes,const unsigned long *new_nodes);
ADL_RESULT adl_sys_mlock2(const void *addr,size_t len,unsigned int flags);
ADL_RESULT adl_sys_mremap(void *old_address,size_t old_size,size_t new_size,int flags,void *new_address);
ADL_RESULT adl_sys_move_pages(int pid,unsigned long count,void **pages,const int *nodes,int *status,int flags);
ADL_RESULT adl_sys_request_key(const char *type,const char *description,const char *callout_info,key_serial_t dest_keyring);
ADL_RESULT adl_sys_pkey_alloc(unsigned int flags,unsigned int access_rights);
ADL_RESULT adl_sys_pkey_free(int pkey);
ADL_RESULT adl_sys_pkey_mprotect(void *addr,size_t len,int prot,int pkey);
ADL_RESULT adl_sys_set_mempolicy(int mode,const unsigned long *nodemask,unsigned long maxnode);
ADL_RESULT adl_sys_swapoff(const char *path);
ADL_RESULT adl_sys_swapon(const char *path,int swapflags);
ADL_RESULT adl_sys_vmsplice(int fd,const struct iovec *iov,size_t nr_segs,unsigned int flags);
ADL_RESULT adl_sys_mlock(void *addr,size_t len);
ADL_RESULT adl_sys_mlockall(int flags);
ADL_RESULT adl_sys_mmap(void *addr,size_t len,int prot,int flags,int fd,off_t offset);
ADL_RESULT adl_sys_mprotect(void *addr,size_t len,int prot);
ADL_RESULT adl_sys_msync(void *addr,size_t len,int flags);
ADL_RESULT adl_sys_munlock(const void *addr,size_t len);
ADL_RESULT adl_sys_munlockall();
ADL_RESULT adl_sys_munmap(void *addr,size_t len);






#endif


#endif

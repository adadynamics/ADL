#include "memory_linux.h"


#ifdef ADL_OS_UNIX

extern ADL_UNIX adl_os;



void ADL_MEMORY_LINUX_Init(ADL_MEMORY_LINUX *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

        
    class->brk                                             = adl_os.brk;
    class->sbrk                                            = adl_os.sbrk;
    class->madvise                                         = adl_os.madvise;
    class->mincore                                         = adl_os.mincore;
    class->get_mempolicy                                   = adl_os.get_mempolicy;
    class->keyctl                                          = adl_os.keyctl;
    class->membarrier                                      = adl_os.membarrier;
    class->memfd_secret                                    = adl_os.memfd_secret;
    class->userfaultfd                                     = adl_os.userfaultfd;
    class->mbind                                           = adl_os.mbind;
    class->memfd_create                                    = adl_os.memfd_create;
    class->migrate_pages                                   = adl_os.migrate_pages;
    class->mlock2                                          = adl_os.mlock2;
    class->mremap                                          = adl_os.mremap;
    class->move_pages                                      = adl_os.move_pages;
    class->request_key                                     = adl_os.request_key;
    class->pkey_alloc                                      = adl_os.pkey_alloc;
    class->pkey_free                                       = adl_os.pkey_free;
    class->pkey_mprotect                                   = adl_os.pkey_mprotect;
    class->set_mempolicy                                   = adl_os.set_mempolicy;
    class->swapoff                                         = adl_os.swapoff;
    class->swapon                                          = adl_os.swapon;
    class->vmsplice                                        = adl_os.vmsplice;
    class->mlock                                           = adl_os.mlock;
    class->mlockall                                        = adl_os.mlockall;
    class->mmap                                            = adl_os.mmap;
    class->mprotect                                        = adl_os.mprotect;
    class->msync                                           = adl_os.msync;
    class->munlock                                         = adl_os.munlock;
    class->munlockall                                      = adl_os.munlockall;
    class->munmap                                          = adl_os.munmap;



null_class:
    return;
}

void ADL_MEMORY_LINUX_Fini(ADL_MEMORY_LINUX *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_MEMORY_LINUX));

null_class:
    return;
}



ADL_MEMORY_LINUX memory_os;


void ADL_MEMORY_LINUX_library_init()
{
    ADL_MEMORY_LINUX_init(&memory_os);
}


#endif
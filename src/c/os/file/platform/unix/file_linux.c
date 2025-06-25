#include "file_linux.h"


#ifdef ADL_OS_UNIX


void ADL_FILE_LINUX_init(ADL_FILE_LINUX *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    
    class->open                                            = adl_os.open;
    class->creat                                           = adl_os.creat;
    class->openat                                          = adl_os.openat;
    class->openat2                                         = adl_os.openat2;
    class->read                                            = adl_os.read;
    class->write                                           = adl_os.write;
    class->sendfile                                        = adl_os.sendfile;
    class->close                                           = adl_os.close;
    class->stat                                            = adl_os.stat;
    class->fstat                                           = adl_os.fstat;
    class->lstat                                           = adl_os.lstat;
    class->fstatat                                         = adl_os.fstatat;
    class->poll                                            = adl_os.poll;
    class->ppoll                                           = adl_os.ppoll;
    class->lseek                                           = adl_os.lseek;
    class->ioctl                                           = adl_os.ioctl;
    class->pread                                           = adl_os.pread;
    class->pwrite                                          = adl_os.pwrite;
    class->readv                                           = adl_os.readv;
    class->writev                                          = adl_os.writev;
    class->preadv                                          = adl_os.preadv;
    class->pwritev                                         = adl_os.pwritev;
    class->preadv2                                         = adl_os.preadv2;
    class->pwritev2                                        = adl_os.pwritev2;
    class->pipe                                            = adl_os.pipe;
    class->pipe2                                           = adl_os.pipe2;
    class->select                                          = adl_os.select;
    class->pselect                                         = adl_os.pselect;
    class->dup                                             = adl_os.dup;
    class->dup2                                            = adl_os.dup2;
    class->dup3                                            = adl_os.dup3;
    class->flock                                           = adl_os.flock;
    class->fsync                                           = adl_os.fsync;
    class->fdatasync                                       = adl_os.fdatasync;
    class->truncate                                        = adl_os.truncate;
    class->ftruncate                                       = adl_os.ftruncate;
    class->getcwd                                          = adl_os.getcwd;
    class->chdir                                           = adl_os.chdir;
    class->fchdir                                          = adl_os.fchdir;
    class->rename                                          = adl_os.rename;
    class->renameat                                        = adl_os.renameat;
    class->renameat2                                       = adl_os.renameat2;
    class->mkdir                                           = adl_os.mkdir;
    class->mkdirat                                         = adl_os.mkdirat;
    class->rmdir                                           = adl_os.rmdir;
    class->link                                            = adl_os.link;
    class->linkat                                          = adl_os.linkat;
    class->unlink                                          = adl_os.unlink;
    class->unlinkat                                        = adl_os.unlinkat;
    class->symlink                                         = adl_os.symlink;
    class->symlinkat                                       = adl_os.symlinkat;
    class->readlink                                        = adl_os.readlink;
    class->readlinkat                                      = adl_os.readlinkat;
    class->chmod                                           = adl_os.chmod;
    class->fchmod                                          = adl_os.fchmod;
    class->fchmodat                                        = adl_os.fchmodat;
    class->chown                                           = adl_os.chown;
    class->lchown                                          = adl_os.lchown;
    class->fchown                                          = adl_os.fchown;
    class->fchownat                                        = adl_os.fchownat;
    class->umask                                           = adl_os.umask;
    class->mknod                                           = adl_os.mknod;
    class->mknodat                                         = adl_os.mknodat;
    class->statfs                                          = adl_os.statfs;
    class->fstatfs                                         = adl_os.fstatfs;
    class->vhangup                                         = adl_os.vhangup;
    class->pivot_root                                      = adl_os.pivot_root;
    class->chroot                                          = adl_os.chroot;
    class->sync                                            = adl_os.sync;
    class->syncfs                                          = adl_os.syncfs;
    class->mount                                           = adl_os.mount;
    class->umount                                          = adl_os.umount;
    class->umount2                                         = adl_os.umount2;
    class->ioperm                                          = adl_os.ioperm;
    class->readahead                                       = adl_os.readahead;
    class->setxattr                                        = adl_os.setxattr;
    class->lsetxattr                                       = adl_os.lsetxattr;
    class->fsetxattr                                       = adl_os.fsetxattr;
    class->getxattr                                        = adl_os.getxattr;
    class->lgetxattr                                       = adl_os.lgetxattr;
    class->fgetxattr                                       = adl_os.fgetxattr;
    class->listxattr                                       = adl_os.listxattr;
    class->llistxattr                                      = adl_os.llistxattr;
    class->flistxattr                                      = adl_os.flistxattr;
    class->removexattr                                     = adl_os.removexattr;
    class->lremovexattr                                    = adl_os.lremovexattr;
    class->fremovexattr                                    = adl_os.fremovexattr;
    class->ioprio_set                                      = adl_os.ioprio_set;
    class->ioprio_get                                      = adl_os.ioprio_get;
    class->inotify_init                                    = adl_os.inotify_init;
    class->inotify_init1                                   = adl_os.inotify_init1;
    class->inotify_add_watch                               = adl_os.inotify_add_watch;
    class->inotify_rm_watch                                = adl_os.inotify_rm_watch;
    class->access                                          = adl_os.access;
    class->faccessat                                       = adl_os.faccessat;
    class->faccessat2                                      = adl_os.faccessat2;
    class->quotactl                                        = adl_os.quotactl;
    class->io_setup                                        = adl_os.io_setup;
    class->io_destroy                                      = adl_os.io_destroy;
    class->io_getevents                                    = adl_os.io_getevents;
    class->io_submit                                       = adl_os.io_submit;
    class->io_cancel                                       = adl_os.io_cancel;
    class->lookup_dcookie                                  = adl_os.lookup_dcookie;
    class->epoll_create                                    = adl_os.epoll_create;
    class->epoll_create1                                   = adl_os.epoll_create1;
    class->epoll_wait                                      = adl_os.epoll_wait;
    class->epoll_pwait                                     = adl_os.epoll_pwait;
    class->epoll_pwait2                                    = adl_os.epoll_pwait2;
    class->epoll_ctl                                       = adl_os.epoll_ctl;
    class->splice                                          = adl_os.splice;
    class->tee                                             = adl_os.tee;
    class->posix_fadvise64                                 = adl_os.posix_fadvise64;
    class->utime                                           = adl_os.utime;
    class->utimes                                          = adl_os.utimes;
    class->utimensat                                       = adl_os.utimensat;
    class->futimens                                        = adl_os.futimens;
    class->sync_file_range                                 = adl_os.sync_file_range;
    class->fallocate                                       = adl_os.fallocate;
    class->fanotify_init                                   = adl_os.fanotify_init;
    class->fanotify_mark                                   = adl_os.fanotify_mark;
    class->name_to_handle_at                               = adl_os.name_to_handle_at;
    class->open_by_handle_at                               = adl_os.open_by_handle_at;
    class->copy_file_range                                 = adl_os.copy_file_range;
    class->statx                                           = adl_os.statx;
    class->close_range                                     = adl_os.close_range;
    class->mount_setattr                                   = adl_os.mount_setattr;
    class->mkfifo                                          = adl_os.mkfifo;
    class->mkfifoat                                        = adl_os.mkfifoat;
    class->opendir                                         = adl_os.opendir;
    class->fdopendir                                       = adl_os.fdopendir;
    class->readdir                                         = adl_os.readdir;
    class->rewinddir                                       = adl_os.rewinddir;
    class->closedir                                        = adl_os.closedir;
    class->dirfd                                           = adl_os.dirfd;


null_class:
    return;
}



void ADL_FILE_LINUX_fini(ADL_FILE_LINUX *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(class,0,sizeof(ADL_FILE_LINUX));

null_class:
    return;
}


ADL_FILE_LINUX file_linux;


void ADL_FILE_LINUX_library_init()
{
    ADL_FILE_LINUX_init(&file_linux);
}


#endif

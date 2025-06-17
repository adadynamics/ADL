#include "file_linux.h"





void ADL_FILE_LINUX_init(ADL_FILE_LINUX *file_linux)
{
    if(ADL_CHECK_NULL(file_linux))
    {
        ADL_RETURN_DEFER(null_class);
    }


    file_linux->open = adl_os.open;
    file_linux->creat = adl_os.creat;
    file_linux->openat = adl_os.openat;
    file_linux->openat2 = adl_os.openat2;
    file_linux->read = adl_os.read;
    file_linux->write = adl_os.write;
    file_linux->sendfile = adl_os.sendfile;
    file_linux->close = adl_os.close;
    file_linux->stat = adl_os.stat;
    file_linux->fstat = adl_os.fstat;
    file_linux->lstat = adl_os.lstat;
    file_linux->fstatat = adl_os.fstatat;
    file_linux->poll = adl_os.poll;
    file_linux->ppoll = adl_os.ppoll;
    file_linux->lseek = adl_os.lseek;
    file_linux->ioctl = adl_os.ioctl;
    file_linux->pread = adl_os.pread;
    file_linux->pwrite = adl_os.pwrite;
    file_linux->readv = adl_os.readv;
    file_linux->writev = adl_os.writev;
    file_linux->preadv = adl_os.preadv;
    file_linux->pwritev = adl_os.pwritev;
    file_linux->preadv2 = adl_os.preadv2;
    file_linux->pwritev2 = adl_os.pwritev2;
    file_linux->pipe = adl_os.pipe;
    file_linux->pipe2 = adl_os.pipe2;
    file_linux->select = adl_os.select;
    file_linux->pselect = adl_os.pselect;
    file_linux->dup = adl_os.dup;
    file_linux->dup2 = adl_os.dup2;
    file_linux->dup3 = adl_os.dup3;
    file_linux->flock = adl_os.flock;
    file_linux->fsync = adl_os.fsync;
    file_linux->fdatasync = adl_os.fdatasync;
    file_linux->truncate = adl_os.truncate;
    file_linux->ftruncate = adl_os.ftruncate;
    file_linux->getcwd = adl_os.getcwd;
    file_linux->chdir = adl_os.chdir;
    file_linux->fchdir = adl_os.fchdir;
    file_linux->rename = adl_os.rename;
    file_linux->renameat = adl_os.renameat;
    file_linux->renameat2 = adl_os.renameat2;
    file_linux->mkdir = adl_os.mkdir;
    file_linux->mkdirat = adl_os.mkdirat;
    file_linux->rmdir = adl_os.rmdir;
    file_linux->link = adl_os.link;
    file_linux->linkat = adl_os.linkat;
    file_linux->unlink = adl_os.unlink;
    file_linux->unlinkat = adl_os.unlinkat;
    file_linux->symlink = adl_os.symlink;
    file_linux->symlinkat = adl_os.symlinkat;
    file_linux->readlink = adl_os.readlink;
    file_linux->readlinkat = adl_os.readlinkat;
    file_linux->chmod = adl_os.chmod;
    file_linux->fchmod = adl_os.fchmod;
    file_linux->fchmodat = adl_os.fchmodat;
    file_linux->chown = adl_os.chown;
    file_linux->lchown = adl_os.lchown;
    file_linux->fchown = adl_os.fchown;
    file_linux->fchownat = adl_os.fchownat;
    file_linux->umask = adl_os.umask;
    file_linux->mknod = adl_os.mknod;
    file_linux->mknodat = adl_os.mknodat;
    file_linux->statfs = adl_os.statfs;
    file_linux->fstatfs = adl_os.fstatfs;
    file_linux->vhangup = adl_os.vhangup;
    file_linux->pivot_root = adl_os.pivot_root;
    file_linux->chroot = adl_os.chroot;
    file_linux->sync = adl_os.sync;
    file_linux->syncfs = adl_os.syncfs;
    file_linux->mount = adl_os.mount;
    file_linux->umount = adl_os.umount;
    file_linux->umount2 = adl_os.umount2;
    file_linux->ioperm = adl_os.ioperm;
    file_linux->readahead = adl_os.readahead;
    file_linux->setxattr = adl_os.setxattr;
    file_linux->lsetxattr = adl_os.lsetxattr;
    file_linux->fsetxattr = adl_os.fsetxattr;
    file_linux->getxattr = adl_os.getxattr;
    file_linux->lgetxattr = adl_os.lgetxattr;
    file_linux->fgetxattr = adl_os.fgetxattr;
    file_linux->listxattr = adl_os.listxattr;
    file_linux->llistxattr = adl_os.llistxattr;
    file_linux->flistxattr = adl_os.flistxattr;
    file_linux->removexattr = adl_os.removexattr;
    file_linux->lremovexattr = adl_os.lremovexattr;
    file_linux->fremovexattr = adl_os.fremovexattr;
    file_linux->ioprio_set = adl_os.ioprio_set;
    file_linux->ioprio_get = adl_os.ioprio_get;
    file_linux->inotify_init = adl_os.inotify_init;
    file_linux->inotify_init1 = adl_os.inotify_init1;
    file_linux->inotify_add_watch = adl_os.inotify_add_watch;
    file_linux->inotify_rm_watch = adl_os.inotify_rm_watch;
    file_linux->access = adl_os.access;
    file_linux->faccessat = adl_os.faccessat;
    file_linux->faccessat2 = adl_os.faccessat2;
    file_linux->quotactl = adl_os.quotactl;
    file_linux->io_setup = adl_os.io_setup;
    file_linux->io_destroy = adl_os.io_destroy;
    file_linux->io_getevents = adl_os.io_getevents;
    file_linux->io_submit = adl_os.io_submit;
    file_linux->io_cancel = adl_os.io_cancel;
    file_linux->lookup_dcookie = adl_os.lookup_dcookie;
    file_linux->epoll_create = adl_os.epoll_create;
    file_linux->epoll_create1 = adl_os.epoll_create1;
    file_linux->epoll_wait = adl_os.epoll_wait;
    file_linux->epoll_pwait = adl_os.epoll_pwait;
    file_linux->epoll_pwait2 = adl_os.epoll_pwait2;
    file_linux->epoll_ctl = adl_os.epoll_ctl;
    file_linux->splice = adl_os.splice;
    file_linux->tee = adl_os.tee;
    file_linux->posix_fadvise64 = adl_os.posix_fadvise64;
    file_linux->utime = adl_os.utime;
    file_linux->utimes = adl_os.utimes;
    file_linux->utimensat = adl_os.utimensat;
    file_linux->futimens = adl_os.futimens;
    file_linux->sync_file_range = adl_os.sync_file_range;
    file_linux->fallocate = adl_os.fallocate;
    file_linux->fanotify_init = adl_os.fanotify_init;
    file_linux->fanotify_mark = adl_os.fanotify_mark;
    file_linux->name_to_handle_at = adl_os.name_to_handle_at;
    file_linux->open_by_handle_at = adl_os.open_by_handle_at;
    file_linux->copy_file_range = adl_os.copy_file_range;
    file_linux->statx = adl_os.statx;
    file_linux->close_range = adl_os.close_range;
    file_linux->mount_setattr = adl_os.mount_setattr;
    file_linux->mkfifo = adl_os.mkfifo;
    file_linux->mkfifoat = adl_os.mkfifoat;
    file_linux->opendir = adl_os.opendir;
    file_linux->fdopendir = adl_os.fdopendir;
    file_linux->readdir = adl_os.readdir;
    file_linux->rewinddir = adl_os.rewinddir;
    file_linux->closedir = adl_os.closedir;
    file_linux->dirfd = adl_os.dirfd;

null_class:
    return;
}



void ADL_FILE_LINUX_fini(ADL_FILE_LINUX *file_linux)
{
    if(ADL_CHECK_NULL(file_linux))
    {
        ADL_RETURN_DEFER(null_class);
    }

    ADL_MEMSET(file_linux,0,sizeof(ADL_FILE_LINUX));

null_class:
    return;
}


ADL_FILE_LINUX file_linux;


void ADL_FILE_LINUX_library_init()
{
    ADL_FILE_LINUX_init(&file_linux);
}

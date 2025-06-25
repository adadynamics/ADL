#ifndef ADL_SRC_UNIX_UNIX_H
#define ADL_SRC_UNIX_UNIX_H


#include "../include/unix/unix.h"

#ifdef  ADL_OS_LINUX



#define ___adl_bsd_std___
#define ___adl_end_bsd___
#define ___adl_linux_std___
#define ___adl_end_linux___
#define ___adl_nostd___
#define ___adl_end_nostd___
#define ___adl_not_sys___
#define ___adl_end_not_sys___
#define ___adl_ret_charptr___

#define ___adl_syscall___
#define ___adl_end_syscall___

#define ___adl_obsolete___
#define ___adl_end_obsolete___

#define ___adl_not_for_apps_for_glibc___



int openat2(int dirfd,const char *pathname,struct open_how *how,size_t size);
int faccessat2(int dirfd,const char *path,int mode,int flags);
int pivot_root(const char *new_root, const char *put_old);
int io_setup(unsigned int nr_events,aio_context_t *ctx_id);
int io_destroy(aio_context_t ctx_id);
int io_getevents(aio_context_t ctx_id,long min_nr, long nr, struct io_event *events,struct timespec *timeout);
int io_submit(aio_context_t ctx_id, long nr, struct iocb **iocb);
int io_cancel(aio_context_t ctx_id, struct iocb *iocb,struct io_event *result);
int lookup_dcookie(uint64_t cookie, char *buffer,size_t len);
int ioprio_set(int which,int who,int ioprio);
int ioprio_get(int which,int who);
int mq_getsetattr(mqd_t mqdes,const struct mq_attr *newattr, struct mq_attr *oldattr);
int futex(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3);
int get_robust_list(int pid,struct robust_list_head **head_ptr, size_t *len_ptr);
int set_robust_list(struct robust_list_head *head,size_t len);
int capget(cap_user_header_t hdrp,cap_user_data_t datap);
int capset(cap_user_header_t hdrp,const cap_user_data_t datap);
long clone3(struct clone_args *cl_args, size_t size);
void exit_group(int status);
int get_thread_area(struct user_desc *u_info);
int pidfd_getfd(int pidfd, int targetfd,unsigned int flags);
int pidfd_open(pid_t pid,unsigned int flags);
int sched_getattr(pid_t pid,struct sched_attr *attr,unsigned int size,unsigned int flags);
int sched_setattr(pid_t pid, struct sched_attr *attr,unsigned int flags);
int set_thread_area(struct user_desc *u_info);
int set_tid_address(int *tidptr);
int modify_ldt(int func, void *ptr,unsigned long bytecount);
int seccomp(unsigned int operation,unsigned int flags,void *args);
int kcmp(pid_t pid1, pid_t pid2, int type,unsigned long idx1, unsigned long idx2);
int bpf(int cmd, union bpf_attr *attr, unsigned int size);
int pidfd_send_signal(int pidfd, int sig,siginfo_t *info, unsigned int flags);
int reboot(int magic,int magic2,int op,void *arg);
int delete_module(const char *name,unsigned int flags);
int init_module(void * module_image,unsigned long len,const char *param_values);
int finit_module(int fd,const char *param_values,int flags);
int kexec_file_load(int kernel_fd, int initrd_fd,unsigned long cmdline_len, const char *cmdline,unsigned long flags);
int kexec_load(unsigned long entry,unsigned long nr_segments,struct kexec_segment *segments,unsigned long flags);
int syslog(int type,char *bufp,int len);
/*
int keyctl(int operation,unsigned long arg2,unsigned long arg3,unsigned long arg4,unsigned long arg5);
*/
int membarrier(int cmd,unsigned int flags,int cpu_id);
int memfd_secret(unsigned int flags);
int userfaultfd(int flags);








#ifndef ADL_UNIX_INIT
#define ADL_UNIX_INIT(val,valptr)  ADL_S64_INIT(val);  \
                                   ADL_VOID_PTR_INIT(valptr); \
                                   ADL_ERRNO_INIT();   \
                                   ADL_RESULT_RETURN_DEFER_INIT();
#endif


#ifndef ADL_UNIX_PTHREAD_INIT
#define ADL_UNIX_PTHREAD_INIT ADL_UNIX_INIT
#endif


#ifndef ADL_UNIX_FINI
#define ADL_UNIX_FINI(val,valptr)  if(ADL_CHECK_EQUAL(val,-1))                                                  \
                            {                                                                                   \
                                ADL_STRING str;                                                                 \
                                ADL_STRING_Init(&str,ADL_STRERROR(errno));                                      \
                                ADL_RESULT_RETURN_DEFER(failed_syscall, ADL_RESULT_WRITE(errno,val,str,valptr));      \
                            }                                                                                   \
                                                                                                                \
                            ADL_RESULT_RETURN_DEFER(success_syscall,ADL_RESULT_WRITE(errno,val,(ADL_STRING){},valptr));  \
                                               \
                            failed_syscall:    \
                            success_syscall:   \
                                ADL_RESULT_RETURN_DEFER_FINI()                                

#endif




#ifndef ADL_UNIX_PTHREAD_FINI
#define ADL_UNIX_PTHREAD_FINI(val,valptr)  if(ADL_CHECK_NOT_EQUAL(val,0))                                                  \
                            {                                                                                   \
                                ADL_STRING str;                                                                 \
                                ADL_STRING_Init(&str,ADL_STRERROR(errno));                                      \
                                ADL_RESULT_RETURN_DEFER(failed_syscall, ADL_RESULT_WRITE(val,-1,str,valptr));      \
                            }                                                                                   \
                                                                                                                \
                            ADL_RESULT_RETURN_DEFER(success_syscall,ADL_RESULT_WRITE(0,val,(ADL_STRING){},valptr));  \
                                               \
                            failed_syscall:    \
                            success_syscall:   \
                                ADL_RESULT_RETURN_DEFER_FINI()                                

#endif





#endif


#endif

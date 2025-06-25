#ifndef ADL_SRC_UNIX_IPC_IPC_H
#define ADL_SRC_UNIX_IPC_IPC_H


#include "../unix.h"

#ifdef ADL_OS_UNIX





#ifndef ADL_SHMGET
#define ADL_SHMGET shmget
#endif

#ifndef ADL_SHMAT
#define ADL_SHMAT shmat
#endif

#ifndef ADL_SHMCTL
#define ADL_SHMCTL shmctl
#endif

#ifndef ADL_SHMDT
#define ADL_SHMDT shmdt
#endif

#ifndef ADL_MSGGET
#define ADL_MSGGET msgget
#endif

#ifndef ADL_MSGSND
#define ADL_MSGSND msgsnd
#endif

#ifndef ADL_MSGRCV
#define ADL_MSGRCV msgrcv
#endif

#ifndef ADL_MSGCTL
#define ADL_MSGCTL msgctl
#endif

#ifndef ADL_MQ_OPEN
#define ADL_MQ_OPEN mq_open 
#endif

#ifndef ADL_MQ_UNLINK
#define ADL_MQ_UNLINK mq_unlink 
#endif

#ifndef ADL_MQ_TIMEDSEND
#define ADL_MQ_TIMEDSEND mq_timedsend 
#endif

#ifndef ADL_MQ_TIMEDRECEIVE
#define ADL_MQ_TIMEDRECEIVE mq_timedreceive 
#endif

#ifndef ADL_MQ_NOTIFY
#define ADL_MQ_NOTIFY mq_notify 
#endif

___adl_not_for_apps_for_glibc___

#ifndef ADL_MQ_GETSETATTR
#define ADL_MQ_GETSETATTR mq_getsetattr 
#endif

#ifndef ADL_SEMGET
#define ADL_SEMGET semget
#endif

#ifndef ADL_SEMOP
#define ADL_SEMOP semop
#endif

#ifndef ADL_SEMTIMEDOP
#define ADL_SEMTIMEDOP semtimedop
#endif

#ifndef ADL_SEMCTL
#define ADL_SEMCTL semctl
#endif


___adl_linux_std___
___adl_syscall___


#ifndef ADL_FUTEX
#define ADL_FUTEX futex
#endif

#ifndef ADL_SET_ROBUST_LIST
#define ADL_SET_ROBUST_LIST set_robust_list
#endif

#ifndef ADL_GET_ROBUST_LIST
#define ADL_GET_ROBUST_LIST get_robust_list
#endif






ADL_RESULT adl_sys_shmget(key_t key,size_t size,int flags);
ADL_RESULT adl_sys_shmat(int id, const void *addr, int flags);
ADL_RESULT adl_sys_shmctl(int id, int op, struct shmid_ds *buf);
ADL_RESULT adl_sys_shmdt(const void *addr);
ADL_RESULT adl_sys_msgget(key_t key, int flags);
ADL_RESULT adl_sys_msgsnd(int id, const void *buf,size_t buflen,int flags);
ADL_RESULT adl_sys_msgrcv(int id,void *buf,size_t buflen,long type,int flags);
ADL_RESULT adl_sys_msgctl(int id, int op, struct msqid_ds *buf);
ADL_RESULT adl_sys_mq_open_v1(const char *name,int flags);
ADL_RESULT adl_sys_mq_open_v2(const char *name,int flags,mode_t mode,struct mq_attr *attr);
ADL_RESULT adl_sys_mq_unlink(const char *name);
ADL_RESULT adl_sys_mq_timedsend(mqd_t fd, const char *buf,size_t buflen, unsigned int priority,const struct timespec *timeout);
ADL_RESULT adl_sys_mq_timedreceive(mqd_t fd,char *buf,size_t buflen, unsigned int *priority,const struct timespec *timeout);
ADL_RESULT adl_sys_mq_notify(mqd_t fd, const struct sigevent *sigevent);
ADL_RESULT adl_sys_mq_getsetattr(mqd_t fd,const struct mq_attr *new,struct mq_attr *old);
ADL_RESULT adl_sys_semget(key_t key, int num, int flags);
ADL_RESULT adl_sys_semop(int id, struct sembuf *sops, size_t num);
ADL_RESULT adl_sys_semtimedop(int id, struct sembuf *sops, size_t num,const struct timespec *timeout);
ADL_RESULT adl_sys_semctl(int id, int num,int op,...);
ADL_RESULT adl_sys_futex(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3);
ADL_RESULT adl_sys_set_robust_list(struct robust_list_head *head,size_t len);
ADL_RESULT adl_sys_get_robust_list(int pid,struct robust_list_head **head, size_t *len);





#endif



#endif

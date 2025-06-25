#include "ipc.h"

#ifdef ADL_OS_UNIX









/*
    INTER-PROCESS COMMUNICATION
*/



/*

ADL_RESULT adl_sys_shmget(key_t key,size_t size,int flags)

            a wrapper for shmget system call on unix systems

            INPUT  :(key_t key,size_t size,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_shmget(key_t key,size_t size,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SHMGET(key,size,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_shmat(int id, const void *addr, int flags)

            a wrapper for shmat system call on unix systems

            INPUT  :(int id, const void *addr, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_shmat(int id, const void *addr, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_retptr = ADL_SHMAT(id,addr,flags);
    
    if(ADL_CHECK_NULL(rdr_retptr))
    {
        rdr_ret = -1;
    }

    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_shmctl(int id, int op, struct shmid_ds *buf)

            a wrapper for shmctl system call on unix systems

            INPUT  :(int id, int op, struct shmid_ds *buf)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_shmctl(int id, int op, struct shmid_ds *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SHMCTL(id,op,buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_shmdt(const void *addr)

            a wrapper for shmdt system call on unix systems

            INPUT  :(const void *addr)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_shmdt(const void *addr)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SHMDT(addr);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_msgget(key_t key, int flags)

            a wrapper for msgget system call on unix systems

            INPUT  :(key_t key, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_msgget(key_t key, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MSGGET(key,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}


/*

ADL_RESULT adl_sys_msgsnd(int id, const void *buf,size_t buflen,int flags)

            a wrapper for msgsnd system call on unix systems

            INPUT  :(int id, const void *buf,size_t buflen,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_msgsnd(int id, const void *buf,size_t buflen,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MSGSND(id,buf,buflen,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_msgrcv(int id,void *buf,size_t buflen,long type,int flags)

            a wrapper for msgrcv system call on unix systems

            INPUT  :(int id,void *buf,size_t buflen,long type,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_msgrcv(int id,void *buf,size_t buflen,long type,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MSGRCV(id,buf,buflen,type,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_msgctl(int id, int op, struct msqid_ds *buf)

            a wrapper for msgctl system call on unix systems

            INPUT  :(int id, int op, struct msqid_ds *buf)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_msgctl(int id, int op, struct msqid_ds *buf)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MSGCTL(id,op,buf);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_mq_open_v1(const char *name,int flags)

            a wrapper for mq_open_v1 system call on unix systems

            INPUT  :(const char *name,int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mq_open_v1(const char *name,int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_OPEN(name,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_mq_open_v2(const char *name,int flags,mode_t mode,struct mq_attr *attr)

            a wrapper for mq_open_v2 system call on unix systems

            INPUT  :(const char *name,int flags,mode_t mode,struct mq_attr *attr)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mq_open_v2(const char *name,int flags,mode_t mode,struct mq_attr *attr)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_OPEN(name,flags,mode,attr);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_mq_unlink(const char *name)

            a wrapper for mq_unlink system call on unix systems

            INPUT  :(const char *name)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mq_unlink(const char *name)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_UNLINK(name);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_mq_timedsend(mqd_t fd, const char *buf,size_t buflen, unsigned int priority,const struct timespec *timeout)

            a wrapper for mq_timedsend system call on unix systems

            INPUT  :(mqd_t fd, const char *buf,size_t buflen, unsigned int priority,const struct timespec *timeout
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mq_timedsend(mqd_t fd, const char *buf,size_t buflen, unsigned int priority,const struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_TIMEDSEND(fd,buf,buflen,priority,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}






/*

ADL_RESULT adl_sys_mq_timedreceive(mqd_t fd,char *buf,size_t buflen, unsigned int *priority,const struct timespec *timeout)

            a wrapper for mq_timedreceive system call on unix systems

            INPUT  :(mqd_t fd,char *buf,size_t buflen, unsigned int *priority,const struct timespec *timeout)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mq_timedreceive(mqd_t fd,char *buf,size_t buflen, unsigned int *priority,const struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_TIMEDRECEIVE(fd,buf,buflen,priority,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_mq_notify(mqd_t fd, const struct sigevent *sigevent)

            a wrapper for mq_notify system call on unix systems

            INPUT  :(mqd_t fd, const struct sigevent *sigevent)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_mq_notify(mqd_t fd, const struct sigevent *sigevent)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_NOTIFY(fd,sigevent);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}




/*

ADL_RESULT adl_sys_mq_getsetattr(mqd_t fd,const struct mq_attr *new,struct mq_attr *old)

            a wrapper for mq_getsetattr system call on unix systems

            INPUT  :(mqd_t fd,const struct mq_attr *new,struct mq_attr *old)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_not_for_apps_for_glibc___

ADL_RESULT adl_sys_mq_getsetattr(mqd_t fd,const struct mq_attr *new,struct mq_attr *old)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_MQ_GETSETATTR(fd,new,old);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}








/*
    SYNCHRONIZATION
*/



/*

ADL_RESULT adl_sys_semget(key_t key, int num, int flags)

            a wrapper for semget system call on unix systems

            INPUT  :(key_t key, int num, int flags)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_semget(key_t key, int num, int flags)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEMGET(key,num,flags);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_semop(int id, struct sembuf *sops, size_t num)

            a wrapper for semop system call on unix systems

            INPUT  :(int id, struct sembuf *sops, size_t num)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_semop(int id, struct sembuf *sops, size_t num)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEMOP(id,sops,num);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_semtimedop(int id, struct sembuf *sops, size_t num,const struct timespec *timeout)

            a wrapper for semptimedop system call on unix systems

            INPUT  :(int id, struct sembuf *sops, size_t num,const struct timespec *timeout)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_semtimedop(int id, struct sembuf *sops, size_t num,const struct timespec *timeout)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEMTIMEDOP(id,sops,num,timeout);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_semctl(int id, int num,int op,...)

            a wrapper for semctl system call on unix systems

            INPUT  :(int id, int num,int op,...
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_semctl(int id, int num,int op,...)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SEMCTL(id,num,op);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_futex(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3)

            a wrapper for futex system call on unix systems

            INPUT  :(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/

___adl_linux_std___
___adl_syscall___

ADL_RESULT adl_sys_futex(uint32_t *uaddr, int futex_op, uint32_t val,const struct timespec *timeout,uint32_t *uaddr2, uint32_t val3)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_FUTEX(uaddr,futex_op,val,timeout,uaddr2,val3);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_set_robust_list(struct robust_list_head *head,size_t len)

            a wrapper for set_robust_list system call on unix systems

            INPUT  :(struct robust_list_head *head,size_t len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_set_robust_list(struct robust_list_head *head,size_t len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_SET_ROBUST_LIST(head,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}





/*

ADL_RESULT adl_sys_get_robust_list(int pid,struct robust_list_head **head, size_t *len)

            a wrapper for get-robust_list system call on unix systems

            INPUT  :(int pid,struct robust_list_head **head, size_t *len)
            
            OUTPUT : returns a ADL_RESULT structure

            ****
                on success the ret member of the structure is set to zero

                on error the ret member of the structure is set to -1, the _errno member contains the error number and the errmsg member contains the description of the error
            ****

            ===>  NO DYNAMIC MEMORY IS USED
*/


ADL_RESULT adl_sys_get_robust_list(int pid,struct robust_list_head **head, size_t *len)
{
    ADL_UNIX_INIT(rdr_ret,rdr_retptr);
    rdr_ret = ADL_GET_ROBUST_LIST(pid,head,len);
    ADL_UNIX_FINI(rdr_ret,rdr_retptr);
}

___adl_end_syscall___
___adl_end_linux___









#endif

#ifndef ADL_DS_LIST_H
#define ADL_DS_LIST_H


#include "../common/types.h"
#include "../common/utils.h"


typedef struct ADL_DATA
{
    void *data;
    void (*Destroy)(struct ADL_DATA *self);
}ADL_DATA;

void ADL_DATA_Init(ADL_DATA *class,void *data,void (*Destroy)(struct ADL_DATA *self));

void ADL_DATA_Fini(ADL_DATA *class);


typedef struct ADL_SINGLY_NODE
{
    struct ADL_SINGLY_NODE *next;
    struct ADL_DATA data;
}ADL_NODE;

void ADL_SINGLY_NODE_Init(ADL_SINGLY_NODE *class,struct ADL_DATA data);

void ADL_SINGLY_NODE_Fini(ADL_SINGLY_NODE *class);






typedef struct ADL_LIST
{
    ADL_SINGLY_NODE *head;
    ADL_SINGLY_NODE *tail;

    void (*PushFront)(struct ADL_LIST *self,ADL_DATA data);
    void (*PushBack)(struct ADL_LIST *self,ADL_DATA data);
    void (*Insert)(struct ADL_LIST *self,ADL_DATA data,u64 position);
    void (*PopFront)(struct ADL_LIST *self);
    void (*PopBack)(struct ADL_LIST *self);
    void (*Remove)(struct ADL_LIST *self,u64 position);
    void (*Delete)(struct ADL_LIST *self,ADL_DATA data);
    void (*Reverse)(struct ADL_LIST *self);
    void (*Length)(struct ADL_LIST *self);
}ADL_LIST;


void ADL_LIST_Init(ADL_LIST *class);

void ADL_LIST_Fini(ADL_LIST *class);

#endif
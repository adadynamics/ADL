#include "../include/ds/list.h"



void ADL_DATA_Init(ADL_DATA *class,void *data,void (*Destroy)(struct ADL_DATA *self))
{
    if(ADL_CHECK_NULL(class) || ADL_CHECK_NULL(data) || ADL_CHECK_NULL(Destroy))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class->data       = data;
    class->Destroy    = Destroy;

null_class:
    return;
}

/*
void ADL_DATA_Fini(ADL_DATA *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class->data.Destroy(class);
    class->Destroy = NULL;

null_class:
    return;
}
*/

void ADL_SINGLY_NODE_Init(ADL_SINGLY_NODE *class,struct ADL_DATA data)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class->data = data;
    class->next = NULL;

null_class:
    return;
}

void ADL_SINGLY_NODE_Fini(ADL_SINGLY_NODE *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class.data.Destroy(&class->data);
    class->data = (ADL_DATA){};
    class->next = NULL;

null_class:
    return;
}



void ADL_LIST_PushFront(struct ADL_LIST *self,ADL_DATA data)
{
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    ADL_SINGLY_NODE *node = ADL_MALLOC(sizeof(ADL_SINGLY_NODE));
    ADL_SINGLY_NODE_Init(node);

    node.next = self.head;
    self.head = node;

    if(ADL_CHECK_NULL(self.tail))
    {
        self.tail = node;
    }

null_self:
    return;
}



void ADL_LIST_PushBack(struct ADL_LIST *self,ADL_DATA data)
{
    if(ADL_CHECK_NULL(self))
    {
        ADL_RETURN_DEFER(null_self);
    }

    ADL_SINGLY_NODE *node = ADL_MALLOC(sizeof(ADL_SINGLY_NODE));
    ADL_SINGLY_NODE_Init(node);


    if(ADL_CHECK_NULL(self->head))
    {
        self->head = node;
    }

    if(ADL_CHECK_NULL(self->tail))
    {
        self->tail = node;
    }
    else
    {
        self->tail->next = node;
    }
    
null_self:
    return;
}



void ADL_LIST_Insert(struct ADL_LIST *self,ADL_DATA data,u64 position)
{

}



void ADL_LIST_PopFront(struct ADL_LIST *self)
{

}



void ADL_LIST_PopBack(struct ADL_LIST *self)
{

}



void ADL_LIST_Remove(struct ADL_LIST *self,u64 position)
{

}



void ADL_LIST_Delete(struct ADL_LIST *self,ADL_DATA data)
{

}



void ADL_LIST_Reverse(struct ADL_LIST *self)
{

}



void ADL_LIST_Length(struct ADL_LIST *self)
{

}





void ADL_LIST_Init(ADL_LIST *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class->head     = NULL;
    class->tail     = NULL;

null_class:
    return;
}




void ADL_LIST_Fini(ADL_LIST *class)
{
    if(ADL_CHECK_NULL(class))
    {
        ADL_RETURN_DEFER(null_class);
    }

    class->head     = 

null_class:
    return;
}







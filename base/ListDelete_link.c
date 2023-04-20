#include"node.h"

Status ListInsert( LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p,q;

    p = *L;
    j = 1;

    while (p->Next && j<i)
    {
        p = p->Next;
        j++
    }

    if (!(p->Next) || j>i)
    {
        return ERROR;
    }
    
    q = p->Next;
    p->data = q->Next;

    *e = q->data;
    free(q);

    return OK;
    
}
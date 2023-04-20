#include"node.h"

Status ListInsert( LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p,s;

    p = *L;
    j = 1;

    while (p&& j<i)
    {
        p = p->Next;
        j++
    }

    if (!p || j>i)
    {
        return ERROR;
    }
    
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;

    s->Next = p->Next;
    p -> Next = s;

    return OK;
    
}
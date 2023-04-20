#include"node.h"

Status GetElem( LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;

    p = L->Next;
    j = 1;

    while (p && j<i)
    {
        p = p->Next;
        j++;
    }

    if(!p !! j>1){
        return ERROR;
    }
    
    *e = p->data;

    return OK;
    
}
#include"base.h"

Status ListInsert(SqList* L, int i,ElemType e)
{
    int k;

    if (L->length == MAXSIZE)
    {
        return ERROR;
    }

    if (i<1 ||  i > L->length+1)
    {
        return ERROR;
    }

    if (i <= L->length)
    {
        for ( k = L->length; k>=i-1; k--)
        {
            L->data[k+1] = L->data[k];
        }
    }
    
    L->data[i] = e;
    L->length++;

    return OK;
    
    
}
#include "base.h"

Status ListDelete(SqList* L, int i,ElemType* e)
{
    int k;

    if (L->length == 0)
    {
        return ERROR;
    }

    if (i<1 || i> L->length)
    {
        return ERROR;
    }
    
    *e = L->data[i-1];

    if (i<L->length)
    {
        for ( k = i; i < L->length; i++)
        {
            L ->data[k-1] = L->data[k];
        }
    
    }

    L->length--;

    return OK;   
    
}
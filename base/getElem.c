#include"base.h"


Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i<1 || i>L.length)
    {
        return ERROR;
    }
    *e = L.data[i-1];

    return OK;
}
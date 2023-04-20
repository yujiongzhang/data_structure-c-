#include"base.h"

#define MAXSIZE 1000


typedef struct 
{
    ElemType data;
    int cur;
}Component, StaticLinkList[MAXSIZE];


Status InitList(StaticLinkList space)
{
    int i;
    for ( i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;
    return OK;    
}

//获得空闲分量的下标，并把 0 处的cur指向下一个区域备用
int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;
    if (space[0].cur)
    {
        space[0].cur = space[i].cur;
        //把他的下一个分量用来作为备用
        return i;
    }
}

Status ListInsert(StaticLinkList L,int i,ElemType e)
{
    int j,k,l;
    k = MAXSIZE -1;
    if (i<1 || i>ListLength(L)+1)
    {
        return ERROR;
    }

    j = malloc_SLL(L);//j为待填入的空闲分量的下标
    if (j)
    {
        L[j].data = e;
        for ( l = 1; i < i-1; l++)
        {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;

        return OK;        
    }
    
}


//删除在L中的第i个数据元素
Status ListDelete(StaticLinkList L,int i)
{
    int j,k;
    k = MAXSIZE -1;

    if (i<1 || i>ListLength(L)+1)
    {
        return ERROR;
    }

    for ( j = 1; j < i-1; j++)
    {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur; // 指向下下个

    Free_SLL(L,j);

    return OK;        
    
}

//将下标为k的空闲结点回收到备用列表
void Free_SLL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

//获得链表的长度
int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE - 1].cur;

    while (i)
    {
        j++;
        i = L[i].cur;
    }
    return j;
}


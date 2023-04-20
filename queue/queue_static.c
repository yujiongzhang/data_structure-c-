#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 100

typedef char ElemType;

typedef struct
{
    ElemType *base;

    int front;
    int rear;
}cycleQueue;

initQueue(cycleQueue *q)
{
    q->base = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));
    if (!q->base)
    {
        exit(0);
    }
    q->front = q->rear = 0;
}

InsertQueue(cycleQueue *q,ElemType e)
{
    if ((q->rear+1)%MAXSIZE == q->front)
    {
        return;//队列已满
    }
    q->base[q->rear] = e;
    q->rear = (q->rear + 1)%MAXSIZE;
}

DeleteQueue(cycleQueue *q,ElemType *e)
{
    if (q->rear == q->front)
    {
        return;//队列空
    }
    *e = q->base[q->front];
    q->front = (q->front+1)%MAXSIZE;
}
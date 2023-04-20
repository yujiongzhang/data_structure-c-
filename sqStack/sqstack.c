#include"base.h"
#include"stdlib.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct 
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void initStack(sqStack *s){
    s->base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    if (!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

Push(sqStack *s, ElemType e)
{
    // 如果栈满，追加空间
    if (s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType * )realloc(s->base,(s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if (!s->base)
            exit(0);

        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }
    *(s->top) = e;
    s->top++ ;
}

Pop(sqStack *s, ElemType *e)
{
    if (s->top == s->base)
    {
        return;
    }
    s->top--;
    *e = *(s->top);
}

DestroyStack(sqStack *s)
{
    int i, len;
    len = s->stackSize;
    for ( i = 0; i < len; i++)
    {
        free(s->base);
        s->base++;
    }
    s->base = s->top =NULL;
    s->stackSize = 0;
}

int StackLen(sqStack s)
{
    return(s.top - s.base);
    //指针相减不是地址的差，而是指针之间的元素个数（非常智能）
    //指针不能相加
}



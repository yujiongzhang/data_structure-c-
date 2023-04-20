#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10

typedef double ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)
{
    if (s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREMENT)*sizeof(sqStack));
        if (!s->base)
        {
            exit(0);
        }
    }
    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
    if (s->top == s->base)
    {
        return;
    }
    s->top--;
    *e = *(s->top);
}

int StackLen(sqStack *s)
{
    return (s->top - s->base);
}

int main()
{
    //
    sqStack s;
    char c;
    double d,e;
    char str[MAXBUFFER];
    int i = 0;

    InitStack(&s);

    printf("以逆波兰表达式输入待计算的数据，数据与运算符之间用空格隔开，以#作为结束标志\n");
    scanf("%c",&c);
    while (c != '#')
    {

        while ( isdigit(c) || c == '.') //用于过滤数字
        {
            str[i] = c;
            i++;
            str[i] = '\0';
            if (i>=10)
            {
                printf("error: number too big!\n");
                return -1;
            }
            scanf("%c",&c);
            if (c == ' ')
            {
                d = atof(str);//字符串转数字
                Push(&s,d);
                i = 0;
                break;
            }
        }
        

        switch (c)
        {
        case '+':
            Pop(&s,&d);
            Pop(&s,&e);
            Push(&s,d+e);
            break;
        case '-':
            Pop(&s,&d);
            Pop(&s,&e);
            Push(&s,d-e);
            break;
        case '*':
            Pop(&s,&d);
            Pop(&s,&e);
            Push(&s,d*e);
            break;
        case '/':
            Pop(&s,&d);
            Pop(&s,&e);
            if (e!=0)
            {
                Push(&s,d/e);
            }
            else{
                printf(" zero error!\n");
                return -1;
            }
            break;

        }
        scanf("%c",&c);
    }
    Pop(&s,&d);
    printf("\nthe output is :%f\n",d);
    
    return 0;
}
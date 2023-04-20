#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
       
}Node, *LinkList;

//初始化带头节点的空链表
Status InitList( LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));

    if (!(*L))
    {
        return ERROR;
    }
    
    (*L)->next = NULL;
    return OK;
}

int ListLength(LinkList L)
{
    int i=0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;   
    
}

void CreateListHead(LinkList *L,int n)
{
    LinkList p;
    int i;

    srand(time(0));

    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    for ( i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next = (*L)->next;
        (*L)->next = p;          //(*L)一直为头
    }
}


//随机产生n个元素的值，建立带表头结点的单链表线性表L（尾插法）
void CreateListTail(LinkList *L, int n)
{
    LinkList p,r;
    int i;

    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;                               // r 为指向尾部的结点

    for ( i = 0; i < n; i++)
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = (*L)->next->next->next; //设置一个环
}

int HasLoop1(LinkList L)
{
    LinkList cur1 = L;
    int pos1 = 0;

    while (cur1)
    {
        LinkList cur2 = L;
        int pos2 = 0;
        while (cur2)
        {
            if (cur2 == cur1)
            {
                if (pos1 == pos2) //当cur1和cur2到达相同的结点时，走过的步数一样
                {                 //说明没有环
                    break;
                }
                else
                {
                    printf("环的位置在%d个结点处。\n\n",pos2);  //不一样则有环
                    return 1;
                }
            }
            cur2 = cur2->next;
            pos2++;
        }
        cur1 = cur1->next;
        pos1 ++;
    }
    return 0;
}

// 利用快慢指针的方法
int HasLoop2(LinkList L)
{
    int step1 = 1;
    int step2 = 2;
    LinkList p = L;
    LinkList q = L;

    while(p != NULL && q!= NULL && q->next != NULL)
    {
        p = p->next;
        if(p->next != NULL) q = q->next->next;

        printf("p:%d, q:%d \n",p->data,q->data);

        if (p == q)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    LinkList L;
    Status i;
    char opp;
    ElemType e;
    int find;
    int temp;

    i = InitList(&L);
    printf("初始化L后， ListLength（L） = %d\n",ListLength(L));

    printf("\n1.创建有环链表（尾插法）\n2.创建无环链表（头插法）\n3.判断是否有环\n0.退出\n\n");

    while (opp != '0')
    {
        scanf("%c",&opp);
        switch (opp)
        {
        case '1':
            CreateListTail(&L,20);
            printf("成功创建有环L\n");
            printf("\n");
            break;
        case '2':
            CreateListHead(&L,20);
            printf("成功创建无环L\n");
            printf("\n");
            break;  
        case '3':
            printf("方法一：\n\n");
            if (HasLoop1(L))
            {
                printf("有环！！\n");
            }
            else{
                printf("无环！！\n");
            }          
            break;     
        case '0':
            exit(0);
        }
    }
    
}
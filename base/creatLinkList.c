/* 头插法建立单链表示例 */

#include"node.h"

void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;

    srand(time(0));

    *L = (LinkList)malloc(sizeof(Node));
    (*L)->Next = NULL;

    for ( i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); //生成新的结点
        p -> data = rand()%100+1;
        p ->Next =(*L)->Next;
        (*L)->Next = p;
    }
    
}


void CreateListTail(LinkList *L, int n)
{
    LinkList p, r;
    int i;

    srand(time(0));

    *L = (LinkList)malloc(sizeof(Node));
    r = *L;

    for ( i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node)); //生成新的结点
        p -> data = rand()%100+1;
        r ->Next = p;
        r = p; // 等同于 r = r->Next
    }
    
}
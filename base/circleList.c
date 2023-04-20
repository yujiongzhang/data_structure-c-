#include"node.h"

typedef struct CLinkList
{
    int data;
    struct ClinkList *next;
}node;



void ds_init(node **pNode)
{
    int item;
    node *temp;
    node *target;

    printf("输入结点的值，输入0完成初始化：\n");

    while (1)
    {
        scanf("%d",&item);
        fflush(stdin);

        if(item == 0) return;

        if((*pNode)==NULL)
        {//循环链表中只有一个结点
            *pNode = (node*)malloc(sizeof(struct CLinkList));
            if(!(*pNode))
                exit(0);
            
            (*pNode)->data = item;
            (*pNode)->next = *pNode;
        }
        else
        {//找到next指向第一个结点的结点
            for (target = (*pNode); target->next != *pNode; target = target->next);
                        
            //生成一个新的结点
            temp = (node*)malloc(sizeof(struct CLinkList));
            if(!temp) exit(0);

            temp->data = item;
            temp->next = *pNode;
            target->next = temp;
        }
    }
    
}

void ds_insert(node **pNode, int i)
{
    node *temp;
    node *target;
    node *p;
    int item;
    int j=1;
    printf("输入要插入结点的值：");
    scanf("%d",&item);

    if (i==1)
    {
        temp = (node*)malloc(sizeof(struct Clinklist));
        if (!temp)
        {
            exit(0);
        }

        temp->data = item;

        for(target = (*pNode);target->next != (*pNode);target = target->next);//寻找最后一个结点

        temp->next = (*pNode);
        target->next = temp;
        *pNode = temp;
    }
    else
    {
        target = *pNode;

        for ( ; j < (i-1); ++j)
        {
            target = target->next;
        }

        temp = (node*)malloc(sizeof(struct CLinkList));
        if (!temp)
        {
            exit(0);
        }

        temp->data = item;
        p = target->next;//暂存一下target->next 指针
        target->next = temp;
        temp->next = p;

    }
    
}

//删除第i个元素
void ds_delete(node **pNode, int i)
{
    node *target;
    node *temp;
    int j =i;

    if (i==1)
    {//删除的是第一个结点
        //找到最后一个结点
        for (target = *pNode; target->next != *pNode; target = target->next);

        temp = *pNode;
        *pNode = (*pNode)->next;
        target -> next = *pNode;
        free(temp);              
    }
    else
    {
        target = *pNode;
        for ( ; j<i-1; ++j)
        {
            target = target->next;
        }
        temp = target->next;
        target->next = temp->next;
        free(temp);
    }
}


//返回结点所在位置
int ds_search(node *pNode, int elem)
{
    node *target;
    int i = 1;
    for (target = pNode; target->data != elem && target->next != pNode; i++)
    {
        target = target->next;
    }

    if (target->next == pNode)
        return 0;
    else
        return i;
}
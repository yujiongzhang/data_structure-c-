#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

//线索存储标志位
//Link(0):表示指向左右孩子的指针
//Thread(1): 表示指向前驱后继的线索
typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild, *rchild;
    PointerTag ltag;
    PointerTag rtag;
} BiThrNode, *BiThrTree;

//全局变量，始终指向刚刚访问过的结点
BiThrTree pre;

//创建一个二叉树，约定用户遵照前序遍历的方式输入数据
void CreateBiThrTree(BiThrTree *T)
{
    char c;
    scanf("%c",&c);
    if (' ' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiThrNode*)malloc(sizeof(BiThrNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;//先默认都有左右孩子

        CreateBiThrTree(&(*T)->lchild);
        CreateBiThrTree(&(*T)->rchild);
    }
}

//中序遍历线索化 （中序 ：左->中->右）前序：中->左->右
void InThreading(BiThrTree T)
{
    if (T)
    {
        InThreading(T->lchild); //递归左孩子线索化

        //结点处理
        if(!T->lchild) // 如果该结点 没有左孩子，则设置ltag为 Thread 并把 lchild 指向刚刚访问的结点
        {
            T->ltag = Thread;
            T->lchild = pre;//设置为前驱
        }

        if(!pre->rchild) // 如果前一个 结点 没有右孩子，则设置rtag为 Thread 并把 rchild 指向刚刚访问的结点
        {
            pre->rtag = Thread;
            pre->rchild = T;
        }

        pre = T;

        InThreading(T->rchild); //递归右孩子线索化
    }
}

void InOrderThreading( BiThrTree *p, BiThrTree T)
{
    *p = (BiThrTree)malloc(sizeof(BiThrNode));
    (*p)->ltag = Link;//左孩子指向第一个
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if (!T)
    {
        (*p)->lchild = *p;
    }
    else
    {
        (*p)->lchild = T;
        pre = *p;//给 pre 赋值
        InThreading(T); // 进入 InThreading递归
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}

//中序遍历二叉树
//访问二叉树结点的具体操作
void visit(char c)
{
    printf("%c",c);

}

//遍历二叉树
void InOrderTraverse(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;
    while (p!= T)
    {
        while (p->ltag == Link)
        {
            p = p->lchild;
        }
        visit(p->data);

        while (p->rtag == Thread && p->rchild != T)
        {
            p = p->rchild;
            visit(p->data);
        }
        p=p->rchild;
    }
}

int main()
{
    BiThrTree P,T = NULL;
    CreateBiThrTree(&T);
    InOrderThreading (&P,T);
    printf("中序遍历输出结果为：");
    InOrderTraverse(P);
    printf("\n");

    return 0;
}
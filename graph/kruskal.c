#include "stdio.h"
#include <stdlib.h>
#define MAX_VERtEX_NUM 20
#define VertexType int
typedef struct edge
{
    VertexType initial;
    VertexType end;
    VertexType weight;
}edge[MAX_VERtEX_NUM];

typedef struct 
{
    VertexType value;
    int sign;
}assist[MAX_VERtEX_NUM];

assist assists;

//qsort排序函数中使用，使edges结构体中的边按照权值大小升序排序
int cmp(const void *a,const void *b)
{
    return ((struct edge*)a)->weight - ((struct edge*)b)->weight;
}


//初始化连通网
void CreateUDN(edge *edges,int *vexnum,int *arcnum){
    printf("输入连通网的边数：\n");
    scanf("%d %d",&(*vexnum),&(*arcnum));
    printf("输入连通网的顶点：\n");
    for (int i=0; i<(*vexnum); i++) {
        scanf("%d",&(assists[i].value));
        assists[i].sign=i;
    }
    printf("输入各边的起始点和终点及权重：\n");
    for (int i=0 ; i<(*arcnum); i++) {
        scanf("%d,%d,%d",&(*edges)[i].initial,&(*edges)[i].end,&(*edges)[i].weight);
    }
}

//在assists数组中找到顶点point对应的位置下标
int Locatevex(int vexnum,int point){
    for (int i=0; i<vexnum; i++) {
        if (assists[i].value==point) {
            return i;
        }
    }
    return -1;
}
#include<stdio.h>
#define MAX_VERtEX_NUM 20
#define VRType int
#define InfoType char
#define VertexType int
typedef enum{DG,DN,UDG,UDN}GraphKind;

typedef struct 
{
    VRType adj;
    InfoType * info;
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct 
{
    VertexType vexs[MAX_VERtEX_NUM]; //存储图中顶点数据
    AdjMatrix arcs;                 //二维数组，记录顶点之间的关系
    int vexnum,arcnum;              //记录图的顶点数和弧（边）数
    GraphKind kind;
}MGraph;

int LocateVex(MGraph *G,VertexType v)
{
    int i = 0;

    for ( ; i < G->vexnum; i++)
    {
        if (G->vexs[i] == v)
        {
            break;
        }
    }
    
    if (i>G->vexnum)
    {
        printf("no such vertex.\n");
        return -1;
    }
    return i; 
}

void CreateDG(MGraph *G)
{
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));

    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%d",&(G->vexs[i]));
    }
    

    //初始化二维矩阵，全部归0，指针指向NUL
    for (int i = 0; i < G->vexnum; i++)
    {
        for (int j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }

    for (int i = 0; i < G->arcnum; i++)
    {
        int v1,v2;

        scanf("%d,%d",&v1,&v2);

        int n = LocateVex(G,v1);
        int m = LocateVex(G,v2);

        if (m== -1 || n==-1)
        {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = 1;

    } 
}


//构造无向图
void CreateDN(MGraph *G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2;
        scanf("%d,%d",&v1,&v2);
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=1;
        G->arcs[m][n].adj=1;//无向图的二阶矩阵沿主对角线对称
    }
}

//构造有向网，和有向图不同的是二阶矩阵中存储的是权值。
void CreateUDG(MGraph *G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=w;
    }
}

//构造无向网。和无向图唯一的区别就是二阶矩阵中存储的是权值
void CreateUDN(MGraph* G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int m=LocateVex(G, v1);
        int n=LocateVex(G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=w;
        G->arcs[m][n].adj=w;//矩阵对称
    }
}

void CreateGraph(MGraph *G){
    //选择图的类型
    scanf("%d",&(G->kind));
    //根据所选类型，调用不同的函数实现构造图的功能
    switch (G->kind) {
        case DG:
            return CreateDG(G);
            break;
        case DN:
            return CreateDN(G);
            break;
        case UDG:
            return CreateUDG(G);
            break;
        case UDN:
            return CreateUDN(G);
            break;
        default:
            break;
    }
}

//输出函数
void PrintGrapth(MGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            printf("%d ", G.arcs[i][j].adj);
        }
        printf("\n");
    }
}

int main()
{
    MGraph G;//建立一个图的变量
    CreateGraph(&G);//调用创建函数，传入地址参数
    PrintGrapth(G);//输出图的二阶矩阵
    return 0;
}
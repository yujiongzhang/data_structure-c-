#include <stdio.h>
#include <stdlib.h>
#define VertexType int
#define VRType int
#define MAX_VERtEX_NUM 20
#define InfoType char
#define INFINITY 65535
typedef struct 
{
    VRType adj;
    InfoType *info;
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct 
{
    VertexType vexs[MAX_VERtEX_NUM];
    AdjMatrix arcs;
    int vexnum,arcnum;
}MGraph;

int LocateVex(MGraph G,VertexType v)
{
    int i = 0;
    for (; i <G.vexnum; i++)
    {
        if (v == G.vexs[i])
        {
            return i;
        }
        
    }
    return -1;
}

//构造无向网
void CreateUDN(MGraph* G)
{
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=INFINITY;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int m=LocateVex(*G, v1);
        int n=LocateVex(*G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=w;
        G->arcs[m][n].adj=w;
    }
}


typedef struct 
{
    VertexType adjvex;
    VRType lowcost;
}closedge[MAX_VERtEX_NUM];

closedge theclose;//创建一个全局数组，因为每个函数中都会使用到

int minimun(MGraph G,closedge close)
{
    int min = INFINITY;
    int min_i = -1;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (close[i].lowcost > 0 && close[i].lowcost < min)
        {
            min = close[i].lowcost;
            min_i = i;
        }
    }
    //返回最小权值所在的数组下标
    return min_i;
}

void miniSpanTreePrim(MGraph G,VertexType u)
{
    int k = LocateVex(G,u);
    for (int i = 0; i < G.vexnum; i++)
    {
        if (i != k)
        {
            theclose[i].adjvex = k;
            theclose[i].lowcost = G.arcs[k][i].adj;
        }
    }

    theclose[k].lowcost = 0;

    for (int i = 0; i < G.vexnum; i++)
    {
        k = minimun(G,theclose);
        printf("v%d v%d\n",G.vexs[theclose[k].adjvex],G.vexs[k]);
        theclose[k].lowcost = 0;

        for (int j = 0; j < G.vexnum; j++)
        {
            if (G.arcs[k][j].adj < theclose[j].lowcost)
            {
                theclose[j].adjvex = k;
                theclose[j].lowcost = G.arcs[k][j].adj;
            }
        }
    }
    printf("\n");
   
    
}


int main(){
    MGraph G;
    CreateUDN(&G);
    miniSpanTreePrim(G, 1);
}
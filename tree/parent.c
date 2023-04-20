#define MAX_TREE_SIZE 100

typedef int ElemType;

typedef struct PTNode
{
    ElemType data;
    int parent;
}PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int r; // 根的位置
    int n; // 结点的数目
}PTree;

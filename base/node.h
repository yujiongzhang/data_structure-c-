#ifndef NODE_H
#define NODE_H

#include"base.h"

typedef struct Node
{
    ElemType data;
    struct Node* Next;
} Node;

typedef struct Node* LinkList;

#endif
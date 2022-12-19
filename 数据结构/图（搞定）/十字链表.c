#include <stdio.h>
#define MaxVerNum 20

//  十字链表边表的弧节点结构
typedef struct ArcNode
{
    int tailVex,headVex;            //该弧的尾和头顶点的位置
    struct ArcNode *hLink,*tLink;   //弧头相同和弧尾相同的指针域
}ArcNode;
//  顶点表的节点结构
typedef struct VexNode
{
    char verTex;
    ArcNode firstIn,firstOut;       //分别指向该顶点第一条入弧和出弧
}VexNode;
//  构建
typedef struct
{
    VexNode vlist[MaxVerNum];
    int vexNum,arcNum;
}OLGraph;
#include <stdio.h>
#define MAXVERNUM 10
/*
    普里姆算法步骤
        1. 首次将初始顶点u加入U中，将其顶点和其它顶点组成的边加入到Edge[j]数组中
        2. 循环n-1次，
            2.1 从各组边Edge中选出最小边Edge[k]，输出此边；
            2.2 将k加入U中
            2.3 更新剩余的最小边信息Edge[j]。新增加了一条从k到j的边，如果新边的权值比Edge[j].weigh小，则将Edge[j].weigh更新为新边的权值

*/
//  邻接矩阵结构
typedef struct
{
    int vexs[MAXVERNUM];
    int arcs[MAXVERNUM][MAXVERNUM];
    int vexnum, arcnum;
} MGraph;
//  辅助数组（记录了从顶点集U到V-U中代价最小的边）
struct edge
{
    int adjvex;
    int weigh;
} Edge[MAXVERNUM];
// 获取辅助数组中最小权值的弧头表示为下一个顶点
int Min(struct edge *e)
{
    int j;
    int index;
    index = 0;
    for (j = 1; j < MAXVERNUM; j++)         //寻找权值最小的顶点信息
    {
        if (e[j].weigh < e[index].weigh)
            index = j;
    }
    return e[j].adjvex;
}
// 普里姆算法
void PrimMinSpanTree(MGraph G, int u)
{
    int i, j, k;
    for (j = 0; j < G.vexnum; j++)          //辅助数组初始化
    {
        if (j != u)
            Edge[j] = {u, G.arcs[u][j]};
    }
    Edge[u].weigh = 0;                      //初始化U={u1};
    for (i = 0; i < G.vexnum; i++)
    {
        k = Min(Edge);
        printf("%d,%d", Edge[u].adjvex, G.vexs[u]); //输出生成树的一条边
        Edge[k].weigh = 0;
        for (j = 0; j < G.vexnum; j++)      //修改其它顶点的最小边
        {
            if (G.arcs[k][j] < Edge[j].weigh)
                Edge[j] = {G.vexs[k], G.arcs[k][j]};
        }
    }
}
//  主程序
int main()
{
    return 1;
}
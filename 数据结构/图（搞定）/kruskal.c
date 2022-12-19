#include <stdio.h>
#define MAXNUM 7
#define ARCNUM 6
/*
    克鲁斯卡尔算法的实现
        算法需要引入辅助的数据结构
        1. 结构体数组Edge：存储边的信息，包括边的两个顶点信息和权值
            辅助数组Edges的定义
            struct
            {
                int head;
                int tail;
                int weigh;
            }
        2. Vexset[i]：标识各个顶点所属的连通分量。初始值表示各个顶点自成一个连通分量
    克鲁斯卡尔算法步骤
        1. 将数组Edge中的元素按权值大小从小到大排序
        2. 依次查看数组Edge中的边，循转执行以下操作
            2.1 依次从排好序的数组Edge中选出一条边；
            2.2 在Vexset中分别查找v1和v2所在的连通分量vs1和vs2，进行判断
                2.2.1 如果vs1和vs2不等，表明所选的两个顶点不属于同一个连通分量，输出此边，并合并vs1和vs2两个连通分量
                2.2.2 如果vs1和vs2相等，表明所选的两个顶点属于同一个连通分量，舍去此边而选择下一条权值最小的边
*/
//  邻接矩阵
typedef struct
{
    int vexs[MAXNUM];
    int arcs[MAXNUM][MAXNUM];
    int vexnum, arcnum;
} AMGraph;
//  边集结构
typedef struct
{
    int head;   //开始点
    int tail;   //结束点
    int weight; //权值
} Edge[ARCNUM];
//  边集排序（从小到大）
void Sort(Edge *E)
{
    int i;
    int t;
    //  插入排序
    for (i = 1; i < 6; i++)
    {
        while (E[i]->weight < E[i - 1]->weight && i > 0)
        {
            t = E[i - 1]->weight;
            E[i - 1]->weight = E[i]->weight;
            E[i]->weight = t;
            i--;
        }
    }
}
//  边集初始化
Edge *Init_Edge()
{
    Edge *e=NULL;
    // Edge e[ARCNUM] = {
    //     {0, 2, 10},
    //     {4, 6, 12},
    //     {1, 3, 14},
    //     {1, 4, 16},
    //     {5, 6, 22},
    //     {2, 5, 25}};
    return e;
    // Edge *e={
    //     {0,28,10,100,100,100,100},
    //     {28,0,100,14,16,100,100},
    //     {10,100,0,100,100,25,100},
    //     {100,14,100,0,100,24,18},
    //     {100,100,25,24,100,0,22},
    //     {100,100,100,18,12,22,0}};
}
//  定位顶点在邻接矩阵中的位置
int LocVex(AMGraph G, int vex)
{
    int i;
    for (i = 0; i < G.vexnum; i++)
    {
        if (G.vexs[i] == vex)
            break;
    }
    return i;
}
//  克鲁斯卡尔算法
void KruscalMinTree(AMGraph G)
{
    Edge *E = Init_Edge();
    int i, j;
    int v1, v2;
    int vs1, vs2;
    int Vexset[G.vexnum];           //标识各个顶点所属的连通分量
    Sort(E);                        //按权值从小到大排序
    for (i = 0; i < G.vexnum; i++)
        Vexset[i] = i;              //辅助数组，表示各个顶点自成一个连通分量
    for (i = 0; i < G.arcnum; i++)
    {
        v1 = LocVex(G, E[i]->head); //获取边的始点下标
        v2 = LocVex(G, E[i]->tail); //获取边的终点下标
        vs1 = Vexset[v1];           //始点下标所属的连通分量信息
        vs2 = Vexset[v2];           //终点下标所属的连通分量信息
        if (vs1 != vs2)
        {
            printf("(v1,v2):%d", E[i]->weight);
            for (j = 0; j < G.vexnum; j++) //合并vs1和vs2两个连通分量
            {
                if (Vexset[j] == vs2)
                    Vexset[j] = vs1; //编号为vs2都改成vs1
            }
        }
    }
}
//  主程序
int main()
{
    return 0;
}

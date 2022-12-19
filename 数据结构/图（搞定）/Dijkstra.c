#include <stdio.h>
#define MaxVerNum 6
#define MAXINT 200
//  邻接矩阵结构
typedef struct
{
    char vers[MaxVerNum];               //顶点表
    int arcs[MaxVerNum][MaxVerNum];     //邻接矩阵
    int vernum, arcnum;                 //顶点数和边数
} MGraph;
//  迪杰特斯拉算法
void DIJ(MGraph G, int v0)
{
    /*
        初始化工作
    */
    //  建立两个辅助数据结构
    int visited[MaxVerNum];             //表示该顶点是否已经访问过了。（是否已被确定为最短路径长度）
    int distance[MaxVerNum];            //记录当前路径上最短路径的长度（存在就使用边的权值，否则使用无穷）
    int n = G.vernum;
    int v, i, w;
    for (v = 0; v < n; v++)
    {
        visited[v] = 0;                 // 0:表示没有访问，1：表示已经访问过了
        distance[v] = G.arcs[v0][v];
    }
    visited[v0] = 1;
    /*
        开始主循环，最短路径长度按递增的次序依次产生
    */
    for (i = 1; i < n; i++)
    {
        int min = MAXINT;
        for (w = 0; w < n; w++)
        {
            if (!visited[w] && (distance[w] < min))
            {
                v = w;
                min = distance[w];
            }
        }
        visited[v] = 1;                 //此顶点已经被访问了
        printf("%c\n",G.vers[v]);
        for (w = 0; w < n; w++)
        {
            if (!visited[w] && (distance[v] + G.arcs[v][w] < distance[w]))
                distance[w] = distance[v] + G.arcs[v][w];
        }
    }
}
//  主程序
int main()
{
    MGraph G={
        {'a','b','c','d','e','f'},
        {{1000,1000,10,1000,30,1000},
        {1000,1000,5,1000,1000,1000},
        {1000,1000,1000,50,1000,1000},
        {1000,1000,1000,1000,1000,10},
        {1000,1000,1000,20,1000,60},
        {1000,1000,1000,1000,1000,1000}},
        6,
        8};
    DIJ(G,0);
    return 0;
}
#include <stdio.h>
#define MaxVerNum 100 //最大顶点数
// typedef char VerType; 顶点类型设置为字符型
// typedef int ArcType; 边的权值设为整形

/*
    顶点信息使用“char”类型会出现错误（我暂时没有找到原因）
    所有顶点信息我使用"int"类型来代替实现效果
*/

//  邻接矩阵结构
typedef struct
{
    int vers[MaxVerNum];           //顶点表
    int arcs[MaxVerNum][MaxVerNum]; //邻接矩阵
    int vernum, arcnum;             //顶点数和边数
} MGraph;
//  定位
int Located(MGraph *G, int c)
{
    int i;
    for (i = 0; i < G->vernum; i++)
    {
        if (G->vers[i] == c)
            break;
    }
    return i;
}
//  创建邻接矩阵
void CreateMGraph(MGraph *G)
{
    int i, j, k;
    int aa,bb;
    printf("请输入顶点数和边数（输入格式为：顶点数,边数）:\n");
    scanf("%d,%d", &(G->vernum), &(G->arcnum)); //输入顶点数和边数
    printf("输入顶点信息:\n");
    for (i = 0; i < G->vernum; i++)
        scanf("\n%d", &(G->vers[i])); //输入顶点信息建立顶点表
    for (i = 0; i < G->vernum; i++)
    {
        for (j = 0; j < G->vernum; j++)
            G->arcs[i][j] = 0;
    }
    printf("请输入每条边对应的两个顶点信息（输入格式为：a,b）:\n");
    for (k = 0; k < G->vernum; k++)
    {
        scanf("%d,%d",&aa,&bb);
        i = Located(G, aa);
        j = Located(G, bb);
        G->arcs[i][j] = 1;             //若加入G->arcs[i][j]=1，则建立无向图的邻接矩阵
    }
    printf("邻接矩阵结构完毕！\n");
}
//  主程序
int main()
{
    MGraph G;
    CreateMGraph(&G);
    return 1;
}
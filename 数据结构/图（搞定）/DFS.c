#include <stdio.h>
#include <stdlib.h>
#define MaxVerNum 100
//  边表节点
typedef struct node
{
    int adjvex;           //邻接点域
    struct node *nextAdj; //指向下一个邻接点的指针域
} EdgeNode;
//  顶点表节点
typedef struct vnode
{
    char vertex;         //顶点域
    EdgeNode *firstEdge; //边表头指针
} VerNode, AdjList[MaxVerNum];
//  构建邻接表结构
typedef struct
{
    AdjList adjList;
    int vexnum, arcnum;
} ALGraph;
//  创建邻接表
void CreateALGraph(ALGraph *G)
{
    int i, j;
    int k;
    EdgeNode *E;
    printf("请输入顶点数和边数：\n");
    scanf("%d,%d", &(G->vexnum), &(G->arcnum)); //读入顶点数和边数
    printf("请输入顶点信息：\n");
    for (i = 0; i < G->vexnum; i++)             //建立G->vexnum个顶点的顶点表
    {
        scanf("\n%c", &(G->adjList[i].vertex)); //读入顶点信息
        G->adjList[i].firstEdge = NULL;         //顶点表的边指针设为空
    }
    printf("请输入边的信息：\n");
    for (k = 0; k < G->arcnum; k++)             //采用头插法建立边表
    {
        scanf("\n%d,%d", &i, &j);               //读入一条边中的顶点对应序号
        E = (EdgeNode *)malloc(sizeof(EdgeNode));
        E->adjvex = j;                          //邻接点的序号
        E->nextAdj = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = E;
    }
}
//  DFS
void DFS(ALGraph *G,int j)
{
    int i;
    int visited[G->vexnum];     //建立是否访问数组
    for(i=0;i<G->vexnum;i++)    //初始化数组，1：表示没有访问过，0：表示已经访问过
        visited[i]=1;
    EdgeNode *p;
    printf("visit vertex:%c\n",G->adjList[j].vertex);   //从这个顶点开始进行深度优先遍历图
    visited[j]=0;
    p=G->adjList[j].firstEdge;
    while (p)
    {
        if(visited[p->adjvex])      //该顶点没有被访问，则使用递归方式继续深度优先遍历
            DFS(G,p->adjvex);
        p=p->nextAdj;       //寻找下一个邻接点
    }
    
}
// 主程序
int main()
{
    ALGraph G;
    CreateALGraph(&G);
    DFS(&G,0);   //0:表示为第一个顶点
    return 1;
}


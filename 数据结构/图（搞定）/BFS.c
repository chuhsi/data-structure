#include <stdio.h>
#include "stdlib.h"
#define MAXSIZE 5
#define MaxVerNum 5 //最大顶点数
/*
    顶点信息使用“char”类型会出现错误（我暂时没有找到原因）
    所有顶点信息我使用"int"类型来代替实现效果
*/
//  队列结构
typedef struct
{
    int data[MAXSIZE];
    int front, rear;
} SeqQue;
//  初始化
SeqQue *Init_SQue()
{
    SeqQue *s;
    s = (SeqQue *)malloc(sizeof(SeqQue));
    s->front = s->rear = -1;
    printf("队列初始化完毕\n");
    return s;
}
//  入队
int Push_SeqQue(SeqQue *s, int e)
{
    if (s->rear == MAXSIZE - 1)
        return -1;
    else
    {
        s->rear++;
        s->data[s->rear] = e;
        return 0;
    }
}
//  出队
int Pop_SeqQue(SeqQue *s, int *e)
{
    int n = (s->rear) - (s->front);
    if (n == 0)
        return -1;
    s->front++;
    *e = s->data[s->front];
    return *e;
}
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
//  DFS
void DFS(MGraph *G,int a)
{
    int i,j,m,e;
    SeqQue *Q=Init_SQue();      //先初始化队列
    int visited[G->vernum];     //建立顶点是否访问存储数组
    for(i=0;i<G->vernum;i++)
        visited[i]=1;           //1：表示没有访问过，0：表示访问过
    printf("visit vertex:%c\n",a);
    m=Located(G,a);
    visited[m]=0;
    Push_SeqQue(Q,a);
    // k=Q->rear-Q->front;
    while (!(Q->rear-Q->front==0))
    {
        Pop_SeqQue(Q,&e);        //首次入队的元素出队
        i=Located(G,e);          //定位元素在矩阵中的序号
        for(j=0;j<G->vernum;j++)
        {
            if(G->arcs[i][j]==1 && visited[j])
            {
                Push_SeqQue(Q,G->vers[j]);                  //访问过的元素入队操作
                printf("visit vertex:%c\n",G->vers[j]);     //输入未访问过的信息
                visited[j]=0;
            }
        }
    }
    printf("广度优先遍历完毕\n");
}
//  主程序
int main()
{
    MGraph G;
    CreateMGraph(&G);
    DFS(&G,97);
    return 1;
}
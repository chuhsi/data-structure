#include <stdio.h>
#include "stdlib.h"
#define MAX 10
/*
    0:失败
    1:成功
*/
//  边表节点
typedef struct node
{
    int adjvex;
    struct node *nextAdj;
} EdgeNode;
//  顶点表节点
typedef struct
{
    int incount;
    int vertex;
    EdgeNode *firstEdge;
} VerNode, AdjList[MAX];
//  邻接表
typedef struct
{
    AdjList adjList;
    int vernum, arcnum;
} ALGraph;
//  顺序栈
typedef struct stack
{
    int data[MAX];
    int top;
} SeqStack;
//  使用邻接表结构构建有向图
void CreateALGraph(ALGraph *G)
{
    int i, j;
    int k;
    EdgeNode *E;
    printf("请输入顶点数和边数：\n");
    scanf("%d,%d", &(G->vernum), &(G->arcnum)); //读入顶点数和边数
    printf("请输入顶点信息和顶点入度信息：\n");
    for (i = 0; i < G->vernum; i++)             //建立G->vexnum个顶点的顶点表
    {
        scanf("\n%d,%d", &(G->adjList[i].vertex), &(G->adjList[i].incount)); //读入顶点信息
        G->adjList[i].firstEdge = NULL;                                      //顶点表的边指针设为空
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
//  栈初始化
SeqStack *Init_SStack()
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    if (s)
        s->top = -1;
    return s;
}
//  判断空栈
int Empty_SStack(SeqStack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
//  入栈
int Push_SStack(SeqStack *s, int e)
{
    if (s->top == MAX - 1)
        return 0;                               //栈满不能入栈
    else
    {
        s->top++;
        s->data[s->top] = e;
        return 1;
    }
}
//  出栈
int Pop_SStack(SeqStack *s, int *e)
{
    if (Empty_SStack(s))
        return 0;
    else
    {
        *e = s->data[s->top];
        s->top--;
        return 1;
    }
}
//  拓扑排序
int Topo_Sort(ALGraph *G)
{
    int i, j, k;
    EdgeNode *en;
    SeqStack *ss = Init_SStack();               //初始化栈
    for (i = 0; i < G->vernum; i++)
    {
        if (G->adjList[i].incount == 0)
            Push_SStack(ss, i);                 //把“入度为零“的顶点的序号“入栈”
    }
    for (i = 0; i < G->vernum; i++)
    {
        if (ss->top == -1)
            return 0;
        j = ss->data[ss->top];                  //获取栈顶的顶点信息的序号
        Pop_SStack(ss, &j);                     //把入栈的顶点执行出栈操作
        printf("%c\n", G->adjList[j].vertex);
        en = G->adjList[j].firstEdge;
        while (en != NULL)
        {
            k = en->adjvex;                     //邻节点域
            G->adjList[k].incount--;
            if (G->adjList[k].incount == 0)
                Push_SStack(ss, k);             //把“入度为零“的顶点的序号“入栈”
            en = en->nextAdj;
        }
    }
    return 1;
}
//  主程序
int main()
{
    ALGraph G;
    CreateALGraph(&G);
    Topo_Sort(&G);
    return 1;
}
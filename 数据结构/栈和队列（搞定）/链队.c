#include <stdlib.h>
#include <stdio.h>
//  链队结构
typedef struct node
{
    int data;
    struct node *next;
} QNode;
typedef struct
{
    QNode *front, *rear;
} Queue;
//  初始化（带头节点）
Queue *Init_Que()
{
    Queue *q;
    QNode *p;
    q = (Queue *)malloc(sizeof(Queue));
    p = (QNode *)malloc(sizeof(QNode));
    p->next = NULL;
    q->front = q->rear = p;
    return q;
}
//  入队
void In_Que(Queue *q, int e)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    printf("入队成功！\n");
}
//  对空判断
int Empty_Que(Queue *q)
{
    if (q->rear == q->front)
        return 1;
    else
        return 0;
}
//  出队
int Out_Que(Queue *q, int *e)
{
    QNode *p;
    if (Empty_Que(q))
        return -1;  //栈空
    else
    {
        p = q->front->next;
        q->front->next = p->next;
        *e = p->data;
        free(p);
        if (q->front->next == NULL)
            q->rear = q->front;     //当链队只有一个节点时
        return 0;
    }
}
//  主程序
int main()
{
    Queue *q = Init_Que();
    In_Que(q, 1);
    int j;
    Out_Que(q, &j);
    int rst = Empty_Que(q);
    printf("%d", rst);
    return 1;
}
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
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
//  主程序
int main()
{
    SeqQue *s = Init_SQue();
    int i;
    i = Pop_SeqQue(s, &i);
    printf("%d\n", i);
    return 0;
}
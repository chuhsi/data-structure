#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
//  循环队列结构(附加一个存储队列元素个数的变量)
typedef struct
{
    int data[MAXSIZE];
    int front, rear;
    int num;
} c_SeqQue;
//  置空队
c_SeqQue *Init_SeqQue()
{
    c_SeqQue *c;
    c = (c_SeqQue *)malloc(sizeof(c_SeqQue));
    c->front = c->rear = -1;
    c->num = 0;
    return c;
}
//  入队
int In_SeqQue(c_SeqQue *c, int e)
{
    if (c->num == MAXSIZE)
    {
        printf("队满\n");
        return -1;
    }
    else
    {
        c->rear = (c->rear + 1) % MAXSIZE;
        c->data[c->rear] = e;
        c->num++;
        return 1;
    }
}
//  出队
int Out_SeqQue(c_SeqQue *c, int *e)
{
    if (c->num == 0)
    {
        printf("队空");
        return -1;
    }
    else
    {
        c->front = (c->front + 1) % MAXSIZE;
        *e = c->data[c->front];
        c->num--;
        return 1;
    }
}
//  主程序
int main()
{
    c_SeqQue *c;
    c = Init_SeqQue();
    for (int i = 1; i <= 7; i++)
    {
        In_SeqQue(c, i);
    }
    return 1;
}
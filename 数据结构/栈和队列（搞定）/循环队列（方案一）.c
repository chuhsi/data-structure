#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
//  循环队列结构(少用一个元素空间)
typedef struct
{
    int data[MAXSIZE];
    int front, rear;
} c_SeqQue;
//  初始化
c_SeqQue *Init_SeqQue()
{
    c_SeqQue *c;
    c = (c_SeqQue *)malloc(sizeof(c_SeqQue));
    c->front = c->rear = 0;
    return c;
}
//  入队
int In_SeqQue(c_SeqQue *c, int e)
{
    if ((c->rear + 1) % MAXSIZE == c->front)
    {
        printf("队满");
        return -1;
    }
    else
    {
        c->rear = (c->rear + 1) % MAXSIZE; //第一次入队时，使用时数组0下标进行存储
        c->data[c->rear] = e;
        return 0;
    }
}
//  出队
int Out_SeqQue(c_SeqQue *c, int *e)
{
    if (c->front == c->rear)
    {
        printf("队空");
        return -1;
    }
    else
    {
        c->front = (c->front + 1) % MAXSIZE;
        return *e = c->data[c->front];
    }
}
//  判断队空
int Empty_SeqQue(c_SeqQue *c)
{
    if (c->front == c->rear)
        return -1;
    return 0;
}
//  主程序
int main()
{
    c_SeqQue *C = Init_SeqQue();
    In_SeqQue(C, 1);
    In_SeqQue(C, 11);
    In_SeqQue(C, 111);
    In_SeqQue(C, 111);
    int i;
    Out_SeqQue(C, &i);
    Out_SeqQue(C, &i);
    Out_SeqQue(C, &i);
    Out_SeqQue(C, &i);
    In_SeqQue(C, 1111);
    Out_SeqQue(C, &i);
    In_SeqQue(C, 11111);
    Out_SeqQue(C, &i);
    return 0;
}
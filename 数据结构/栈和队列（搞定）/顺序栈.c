#include <stdio.h>
#include <stdlib.h>
#define MAX 5
//  栈结构
typedef struct
{
    int data[MAX];
    int top;
} SeqStack;
//  初始化
SeqStack *Init_SStack()
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    if (s)
        s->top = -1;
    printf("初始化成功！\n");
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
        return 0; //栈满不能入栈
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
//  取栈顶元素
int GetTop_SStack(SeqStack *s)
{
    if (Empty_SStack(s))
        return 0;
    else
        return (s->data[s->top]);
}
//  主程序
int main()
{
    SeqStack *s;
    s = Init_SStack();
    return 1;
}
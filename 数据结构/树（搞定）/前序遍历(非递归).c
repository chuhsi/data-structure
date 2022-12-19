#include <stdlib.h>
#include <stdio.h>
#define maxsize 10
//  存储形式
typedef struct BTNode
{
    int data;
    struct BTNode *lchild, *rchild;
} BTNode, *BiTree;
//  栈结构
typedef struct
{
    BiTree elem[maxsize];
    int top;
}SqStack, *SStack;
//  初始化
SStack Init_SStack()
{
    SqStack *s;
    s = (SqStack *)malloc(sizeof(SqStack));
    if (s)
        s->top = -1;
    return s;
}
//
int Empty_SStack(SStack s)
{
    if (s->top == -1)
        return -1;
    else
        return 0;
}
//
void PreOrder(BiTree bt)
{
    SStack s1=Init_SStack();
    BiTree p;
    p=bt;
    while (p != NULL || Empty_SStack(s1))
    {
        while(p != NULL)
        {
            // visit(p->data);  访问根节点
            // push(s,p);    栈的push操作
            p=p->lchild;
        }
        if(!Empty_SStack(s1))
        {
            // p=pop(s);    栈的pop操作
            p=p->rchild;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
//  链栈结构
typedef struct node
{
    int data;
    struct node *next;
} StackNode, *LinkStack;
//  置空栈
LinkStack Init_LinkStack()
{
    return NULL;
}
//  判断栈空
int Empty_LinkStack(LinkStack top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
//  入栈
LinkStack Push_LinkStack(LinkStack top, int e)
{
    StackNode *s;
    s = (StackNode *)malloc(sizeof(StackNode));
    s->data = e;
    s->next = top;
    top = s;
    return top;
}
//  出栈
LinkStack Pop_LinkStack(LinkStack top, int *e)
{
    StackNode *s;
    if (top == NULL)
        return NULL; //判断栈是否为空
    else
    {
        *e = top->data;
        s = top;
        top = top->next;
        free(s);
        return top;
    }
}
//  取栈顶元素
int GetTop_LinkStack(LinkStack top)
{
    if(top == NULL) return 1;
    else return top->data;
}
//  主程序
int main()
{
    LinkStack top;
    for(int i=1;i<=10;i++)
        top=Push_LinkStack(top,i);
    int rst=GetTop_LinkStack(top);
    printf("%d\n",rst);
    return 1;
}

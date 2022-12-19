#include <stdio.h>
#include "stdlib.h"
//表结构
typedef struct node
{
    int data;
    struct node *next;
} LNode, *LinkList;
//建立单链表
LinkList Create_LinkList()
{
    LinkList L = NULL;
    LNode *s, *r;
    int e;
    scanf("%d", &e);
    while (e != 0)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        if (L == NULL)
            L = s;
        else
            r->next = s;
        r = s;
        scanf("%d", &e);
    }
    if (r != NULL)
        r->next = NULL;
    return L;
}
//  求表长（L是带头节点）
int Length_LinkList(LinkList L)
{
    LNode *p = L;
    int i = 0;
    while (p)
    {
        p = p->next;
        i++;
    }
    return i;
}
//求表长（L不是带头节点）
int Length_LinkLsit2(LinkList L)
{
    LNode *p = L;
    int i;
    if (p == NULL)
    {
        printf("空表");
        return -1;
    }
    i = 1;
    while (p->next)
    {
        p = p->next;
        i++;
    }
    return i;
}
//主程序
int main()
{
    LinkList L = Create_LinkList();
    printf("%p\n",L);
    return 0;
}
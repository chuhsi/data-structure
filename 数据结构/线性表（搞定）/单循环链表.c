#include <stdio.h>
#include <stdlib.h>
//  循环链表结构
typedef struct node
{
    int data;
    struct node *next;
} LNode, *LinkList;
//  建立循环链表
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
        r->next = L;
    return L;
}
//  求表长（带头节点）
int Length_LinkList(LinkList L)
{
    LNode *p = L;
    int i = 1;
    while (p->next != L)
    {
        p = p->next;
        i++;
    }
    return i;
}
//  按序号查找
LNode *Get_LinkList(LinkList L, int i)
{
    LNode *p = L;
    int j = 1;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (j == i)
        return p;
    else
        return NULL;
}
//  删除操作
int Del_LinkList(LinkList L, int i)
{
    LinkList p, s;
    p = Get_LinkList(L, i - 1);
    if (p == NULL)
        return -1;  //此i-1节点不存在
    else
    {
        s = p->next;
        p->next = s->next;
        printf("删除成功%d\n",s->data);
        free(s);
        return 0;
    }
}
//  主程序
int main()
{
    LinkList L = Create_LinkList();
    Del_LinkList(L,2);
    return 0;
}
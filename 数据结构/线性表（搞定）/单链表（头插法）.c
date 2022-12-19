#include <stdio.h>
#include <stdlib.h>
//链表结构
typedef struct node
{
    int data;
    struct node *next;
} LNode, *LinkList;
//  建立单链表
LinkList Create_LinkList()
{
    LinkList L = NULL; //空表
    LNode *s;
    int e;
    printf("请输入数据，来构建单链表\n");
    scanf("%d", &e);
    while (e != 0)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        scanf("%d", &e);
    }
    return L;
}
//  求表长
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
//  按序号查找操作
LNode *Get_LinkList(LinkList L, int i)
{
    LNode *p = L;
    int j = 1;  //与书中不同，若j=0，就不能访问一个节点。
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
//  按值查找操作
LNode *Locate_LinkList(LinkList L, int e)
{
    LNode *p = L;   //与书中的不同，若p=L->next,则找不到第一个节点
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}
//  定位插入
int Insert_LinkList(LinkList L, int i, int e)
{
    LNode *p, *s;
    p = Get_LinkList(L, (i - 1));
    if (p == NULL)
        return -1;      //插入的位置有误
    else
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        printf("插入成功！\n");
        return 1;
    }
}
//  删除操作
int Del_LinkList(LinkList L, int i)
{
    LinkList p, s;
    p = Get_LinkList(L, (i - 1));
    if (p == NULL)
        return -1;  //此i-1节点不存在
    else
    {
        if (p->next == NULL)
            return -1;  //此i节点不存在
        else
        {
            s = p->next;
            p->next = s->next;
            free(s);
            printf("删除成功");
            return 0;
        }
    }
}
//  遍历(自己添加的)
void ShowAll(LinkList L)
{
    LNode *p = L;
    int i;
    for (i = 0; i < 10 && p != NULL; i++)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
//主方法
int main()
{
    LinkList L = Create_LinkList();
    printf("%p\n",L);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
//  双向循环链表结构
typedef struct dunode
{
    int data;
    struct dunode *next, *prior;
} DuNode, *DuLinkList;
//  创建链表
DuLinkList create_DuLinkList()
{
    DuLinkList D = NULL;
    DuNode *s, *r;
    int e;
    scanf("%d", &e);
    while (e != 0)
    {
        s = (DuNode *)malloc(sizeof(DuNode));
        s->data = e;
        if (D == NULL)
        {
            s->prior = D;
            s->next = D;
            D = s;
        }
        else
        {
            r->next = s;
            s->prior = r;
            D->prior = s;
        }
        r = s;
        scanf("%d", &e);
    }
    if (r != NULL)
        r->next = D;
    return D;
}
//  按序号获取位置
DuNode *Get_DuLinkList(DuLinkList D, int i)
{
    DuNode *p = D;
    int j = 1;
    while (p->next != D && j < i)
    {
        p = p->next;
        j++;
    }
    if (j == i)
        return p;
    else
        return NULL;
}
//  表长
int Length_DuLinkList(DuLinkList D)
{
    DuNode *p = D;
    int i = 1;
    while (p->next != D)
    {
        p = p->next;
        i++;
    }
    return i;
}
//  删除操作
int Del_DuLinkList(DuLinkList D, int i)
{
    int j = Length_DuLinkList(D);
    if (i < 1 || i > j)
    {
        printf("删除的位置有误！\n");
        return -1;
    }
    DuNode *p, *s;
    p = Get_DuLinkList(D, i - 1);
    if (p == NULL)
        return -1;
    s = p->next;
    p->next = s->next;
    s->next->prior = s;
    printf("删除成功！%d\n", s->data);
    free(s);
    return 1;
}
//  主程序
int main()
{
    DuLinkList D = create_DuLinkList();
    Del_DuLinkList(D, 3);
    return 0;
}

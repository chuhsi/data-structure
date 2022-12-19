#include <stdio.h>
#include "stdlib.h"
//  二叉树结构
typedef struct node
{
    int data;
    struct node *Lchild;
    struct node *Rchild;
} BitreeNode;
//  插入
BitreeNode *InsertBN(BitreeNode *b, int k)
{
    BitreeNode *b1 = b;
    BitreeNode *b2 = NULL;
    while (b1 != NULL)
    {
        if (k == b1->data)
        {
            printf("插入失败！");
            return NULL;
        }
        b2 = b1;
        if (k > b1->data)
            b1 = b1->Rchild;
        else
            b1 = b1->Lchild;
    }
    b1 = (BitreeNode *)malloc(sizeof(BitreeNode));
    b1->data = k;
    b1->Lchild = b1->Rchild = NULL;
    if (b2 != NULL)
    {
        if (k < b2->data)
            b2->Lchild = b1;
        else
            b2->Rchild = b1;
        return b2;
    }
    else
        return b1;
}
//  查找
int SearchBitree(BitreeNode *t, int k)
{
    BitreeNode *p;
    if (t != NULL)
    {
        p = t;
        while (p)
        {
            if (p->data == k)
                return 1;
            else if (p->data > k)
                p = p->Lchild;
            else
                p = p->Rchild;
        }
    }
    return -1;
}
//  删除
void DelBitree(BitreeNode *t, int k)
{
    BitreeNode *p = t;
    BitreeNode *f = NULL; //双亲节点
    BitreeNode *q = NULL; //
    BitreeNode *s = NULL; //
    while (p)
    {
        if (p->data == k)
            break;
        f = p;
        if (k > p->data)
            p = p->Rchild;
        else
            p = p->Lchild;
    }
    if (!p)
        return;                         //找不到删除节点就返回
    q = p;
    if (p->Lchild && p->Rchild)         //被删除节点左右子树都不为空
    {
        s = p->Lchild;
        while (s->Rchild)
        {
            q = s;
            s = s->Rchild;
        }
        p->data = s->data;
        if (q != p)
            q->Rchild = s->Lchild;
        else
            q->Lchild = s->Lchild;
        free(s);
        return;
    }
    else if (p->Rchild)                 //被删除节点无右子树，只需要重接其左子树
        p = p->Rchild;
    else if (p->Lchild)                 //被删除节点无左子树，只需要重接其右子树
        p = p->Lchild;
    /* 将p所值的子树挂在其双亲节点f相应的位置 */
    if (!f)
        t = p;
    else if (p < f->Lchild)
        f->Lchild = p;
    else
        f->Rchild = p;
    free(q);
}
//  主程序
int main()
{
    BitreeNode *b = NULL;
    b = InsertBN(b, 9);
    b = InsertBN(b, 8);
    b = InsertBN(b, 12);
    DelBitree(b, 8);
    return 1;
}
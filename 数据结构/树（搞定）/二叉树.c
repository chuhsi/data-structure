#include <stdio.h>
#include <stdlib.h>
//  存储形式
typedef struct BTNode
{
    int data;
    struct BTNode *lchild, *rchild;
} BTNode, *BiTree;
//  初始化
BiTree Create(int root, BiTree lbt, BiTree rbt)
{
    BiTree p;
    p = (BTNode *)malloc(sizeof(BTNode));
    if (p == NULL)
        return NULL;
    p->data = root;
    p->lchild = lbt;
    p->rchild = rbt;
    printf("初始化成功\n");
    return p;
}
//  作为左孩子节点插入二叉树
BiTree InsertL(BiTree bt, int e, BiTree par)
{
    BiTree p;
    if (par == NULL)
    {
        printf("\n插入出错!");
        return NULL;
    }
    p = (BTNode *)malloc(sizeof(BTNode));
    if (p == NULL)
        return NULL;
    p->data = e;
    p->lchild = NULL;
    p->rchild = NULL;
    if (par->lchild == NULL)
        par->lchild = p;
    else
        p->lchild = par->lchild;
    par->lchild = p;
    return bt;
}
//  删除左子树
BiTree DeleteL(BiTree bt, BiTree par)
{
    BiTree p;
    if (par == NULL || par->lchild == NULL)
    {
        printf("\n删除出错!");
        return NULL;
    }
    p = par->lchild;
    par->lchild = NULL;
    if (p->lchild == NULL && p->rchild == NULL)
        free(p);

    else
    {
        /*
        当p为叶子节点时，释放所删节点p的空间。
        当p为非叶子节点时，free(p)操作仅仅释放了所删左子树根节点p的空间。
        实际需要删除左子树分支中的各节点，可借助遍历操作来实现。
        */
    }
    return bt;
}
//  主程序
int main()
{
    BiTree lbt=NULL;
    BiTree rbt=NULL;
    BiTree b=Create(10,lbt,rbt);
    b=InsertL(b,11,b);
    b=InsertL(b,12,b);
    b=InsertL(b,14,b);
    b=InsertL(b,15,b);
    return 0;
}
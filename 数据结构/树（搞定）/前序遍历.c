#include <stdio.h>
#include <stdlib.h>
//  存储形式
typedef struct BTNode
{
    int data;
    struct BTNode *lchild, *rchild;
} BTNode, *BiTree;
//  访问节点数据
void visit(int j)
{
    printf("%d",j);
}
//  波兰表达式
void PreOrder(BiTree bt)
{
    if(bt==NULL) return;
    visit(bt->data);
    /*
        visit()函数，该函数只是一个抽象意义上的函数，表示访问的意思
    */
   PreOrder(bt->lchild);
   PreOrder(bt->rchild);
}
//  主程序
int main()
{
    return 0;
}
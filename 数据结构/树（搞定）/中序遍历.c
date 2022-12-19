#include <stdlib.h>
//存储形式
typedef struct BTNode
{
    int data;
    struct BTNode *lchild, *rchild;
} BTNode, *BiTree;
//  中序遍历
void InOrder(BiTree bt)
{
    if(bt==NULL) return;
    InOrder(bt->lchild);
    // visit(bt->data);
    InOrder(bt->rchild);
}
//  主程序
int main()
{
    return 0;
}
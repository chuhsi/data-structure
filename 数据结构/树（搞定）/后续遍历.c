#include <stdlib.h>
//  存储形式
typedef struct BTNode
{
    int data;
    struct BTNode *lchild, *rchild;
} BTNode, *BiTree;
//  逆波兰表达式
void PostOrder(BiTree bt)
{
    if(bt == NULL) return;
    PostOrder(bt->rchild);
    PostOrder(bt->rchild);
    // visti(bt->data);
}
//  主程序
int main()
{
    return 0;
}
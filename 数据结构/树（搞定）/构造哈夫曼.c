#include <stdio.h>
#define MAXLeaf 4
#define MAXWeight 20
#define MAXNode MAXLeaf*2-1
//  HuffmanTree Constructure
typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
}HNode;
//  To contruct HuffmanTree
void HuffmanTree(HNode HuffmanNode[])
{
    int n;  //输入叶子节点数目
    int i,j;
    int a1,a2;  //用于保存权值
    int b1,b2;  //用户保存节点下标
    printf("请输入叶子节点的总数目，再输入节点对应的权值\n");
    scanf("%d",&n);  //输出叶子节点个树
    for(i=0;i<2*n-1;i++)
    {
        HuffmanNode[i].weight=0;
        HuffmanNode[i].parent=-1;
        HuffmanNode[i].lchild=-1;
        HuffmanNode[i].rchild=-1;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&HuffmanNode[i].weight);  //输出叶子节点的权值
    }
    //构造哈夫曼树
    for(i=0;i<n-1;i++)
    {
        a1=a2=MAXWeight;
        b1=b2=0;
        for(j=0;j<n+i;j++)
        {
            if(HuffmanNode[j].weight<a1 && HuffmanNode[j].parent==-1)
            {
                a2=a1;
                b2=b1;
                a1=HuffmanNode[j].weight;
                b1=j;
            }
            else if(HuffmanNode[j].weight<a2 && HuffmanNode[j].parent==-1)
            {
                a2=HuffmanNode[j].weight;
                b2=j;
            }
        }
        HuffmanNode[b1].parent=n+i; HuffmanNode[b2].parent=n+i;
        HuffmanNode[n+i].weight=HuffmanNode[b1].weight+HuffmanNode[b2].weight;
        HuffmanNode[n+i].lchild=b1; HuffmanNode[n+i].rchild=b2;
    }

}
//  Main procedure
int main()
{   
    HNode h[MAXNode];
    HuffmanTree(h);
    int i=h->parent;
    int m=h[i].parent;
    int j=h[m].parent;
    printf("数组下标为%d\n",h[j].parent);
    return 0;
}
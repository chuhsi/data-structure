#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
//  顺序表结构
typedef struct
{
    int data[MAXSIZE];
    int len;
} SeqList;
//  初始化
SeqList *Init_SeqList()
{
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList));//动态分配顺序表的存储空间
    L->len = -1;
    return L;
}
//  插入操作
int Insert_SeqList(SeqList *L, int i, int e)
{
    int j;
    if (L->len == MAXSIZE - 1)
        return 0;   //表满
    if (i < 1 && i > L->len+2)  //为什么加二不加一？
        return 0;   //插入位置出错
    for (j = L->len; j >= i - 1; j--)
        L->data[j + 1] = L->data[j];
    L->data[i - 1] = e;
    L->len++;
    return 1;
}
//  删除操作
int Delete_SeqList(SeqList *L, int i)
{
    int j;
    if (L->len == -1)
        return 0;   //表空
    if (i < 1 || i > L->len + 1)
        return 0;   //删除位置出错
    for (j = i; j <= L->len; j++)
        L->data[j - 1] = L->data[j];
    L->len--;
    return 1;
}
//  按值查找
int Locate_SeqList(SeqList *L, int v)
{
    int i = 0;
    while (i <= L->len && L->data[i] != v)
        i++;
    if (i > L->len)
        return -1;  //查找失败
    else
        return i;
}
//  取表中元素
int Get_SeqList(SeqList *L, int i)
{
    if (i < 1 || i > L->len + 1)
        return -1;  //不存在这个元素
    else
        return L->data[i - 1];
}
//  主方法
int main()
{
    SeqList *L = Init_SeqList();
    Insert_SeqList(L, 1, 11);
    Insert_SeqList(L, 2, 12);
    Insert_SeqList(L, 3, 13);
    Insert_SeqList(L, 4, 14);
    int i = Get_SeqList(L, 4);
    printf("%d\n", i);
    return 0;
}

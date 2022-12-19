#include <stdio.h>
/*
    算法描述：
        对给定的关键字，从顺序表的一端开始，逐个和各个数据元素的关键字进行比较，相等则成功，反之失败。
*/
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    int i;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == 3)
            printf("查找成功！\n");
    }
    return 1;
}
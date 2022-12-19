#include <stdio.h>


/*
    如果顺序表中的元素按关键字已经排序好了（递增或者递减），称为有序表
    有序表通过“折半查找”提高查找效率

    折半查找
*/

int main()
{
    int arr[] = {1, 20, 40, 60, 90};
    int mid, low = 0, high = 4;
    int i = 40;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (i == arr[mid])
        {
            printf("查找成功\n");
            return 1;
        }
        else if (i > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}
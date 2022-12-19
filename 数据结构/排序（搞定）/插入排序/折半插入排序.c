#include <stdio.h>
//没有理解透“折半插入排序”
void InsertSort(int *arr)
{
    int i, j, t, low, high, mid;
    for (i = 1; i < 14; i++)
    {
        t = arr[i];     //保存
        low = 0;
        high = i-1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (t < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; j--)
            arr[j + 1] = arr[j];
        arr[high + 1] = t;
    }
}
//  主程序
int main()
{
    int arr[] = {49, 38, 65, 97, 76, 13, 27, 49,90,1000,98,23,45,67};
    InsertSort(arr);
    int i;
    for (i = 0; i < 14; i++)
        printf("%d\n", arr[i]);
    return 0;
}
#include <stdio.h>
//  希尔插入
void shellinsert(int *arr, int dk)
{
    int i, j, t;
    for (i = dk; i < 10; i++)
    {
        if (arr[i] < arr[i - dk])
        {
            t = arr[i];
            for (j = i - dk; j >= 0 && t < arr[j]; j -= dk)
                arr[j + dk] = arr[j];
            arr[j + dk] = t;
        }
    }
}
//  希尔排序
void shellsort(int *arr, int *dk) 
{
    int i;
    for (i = 0; i < 3; i++)
        shellinsert(arr, dk[i]);
}
//  主程序
int main()
{
    int arr[] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
    int dk[] = {5, 3, 1};
    shellsort(arr, dk);
    int i;
    for (i = 0; i < 10; i++)
        printf("%d\n", arr[i]);
    return 0;
}
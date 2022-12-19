#include <stdio.h>
//  堆调整
void HeadAdjust(int *arr, int s, int m)
{
    int j;
    int k; 
    k= arr[s];     //保存第一个元素
    for (j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && arr[j] < arr[j + 1])
            j++;
        if (k >= arr[j])
            break;
        arr[s] = arr[j];
        s = j;
    }
    arr[s] = k;
}
//  创建堆
void CreateHeap(int *arr, int n)
{
    int i;
    for (i = n / 2; i > 1; i--)
        HeadAdjust(arr, i, n);
}
//  堆排序
void HeapSort(int *arr, int n)
{
    int i, t;
    CreateHeap(arr, n);
    for (i = n; i > 1; i--)
    {
        //   记录位置交换
        t = arr[1]; 
        arr[1] = arr[i];
        arr[i] = t;
        HeadAdjust(arr, 1, i - 1);
    }
}
//  主程序
int main()
{
    int arr[] = {7,49, 38, 65, 97, 76, 13, 27};
    int n = 8;
    HeapSort(arr, n);
    int k;
    for (k = 0; k < n; k++)
        printf("%d\n", arr[k]);
    return 0;
}
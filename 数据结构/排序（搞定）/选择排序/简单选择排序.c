#include <stdio.h>
//  简单选择排序
void selectSort(int arr[], int n)
{
    int i, j;
    int t;     //交换变量
    int index; //当前关键字最小值的位置
    for (i = 0; i < n; i++)
    {
        index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index])
                index = j;
        }
        if (index != i)
        {
            t = arr[i];
            arr[i] = arr[index];
            arr[index] = i;
        }
    }
}
int main()
{
    int arr[] = {51, 33, 62, 96, 87, 17, 28, 51};
    int n = 8;
    selectSort(arr, n);
    int k;
    for (k = 0; k < 8; k++)
        printf("%d\n", arr[k]);
    return 0;
}
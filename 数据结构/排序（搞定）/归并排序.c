#include <stdlib.h>
#include <stdio.h>
//
void Merge(int s[], int t[], int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;
    while (i != mid + 1 && j != end + 1)
    {
        if (s[i] > s[j])
            t[k++] = s[j++];
        else
            t[k++] = s[i++];
    }
    while (i != mid + 1)
        t[k++] = s[i++];
    while (j != end + 1)
        t[k++] = s[j++];
    for (i = start; i <= end; i++)
        s[i] = t[i];
}
//  内部使用递归
void MergeSort(int s[], int t[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = start + (end - start) / 2; //避免溢出int
        MergeSort(s, t, start, mid);
        MergeSort(s, t, mid + 1, end);
        Merge(s, t, start, mid, end);
    }
}
//  主程序
int main()
{
    int a[8] = {50, 10, 20, 30, 70, 40, 80, 60};
    // int a[7] = {51, 33, 62, 96, 87, 17, 28};
    int i, b[8];
    MergeSort(a, b, 0, 6);
    for (i = 0; i < 8; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
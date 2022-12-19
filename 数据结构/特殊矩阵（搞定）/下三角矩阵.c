#include <stdio.h>
/*
    本程序以行优先存储、五阶数组为例
    下三角矩阵和上三角
        存储空间 n(n+1)/2+1
        节省空间 n(n-1)/2-1
    下三角地址求法  k=i(i-1)/2+j-1  (i>=j)
    上三角地址求法  k=(i-1)(2n-i+2)/2+j-1 (i<=j)
*/
//  主程序
int main()
{
    int i, j;
    int k = 0;
    int Triangle[5][5] =
        {
            {3, 0, 0, 0, 0},
            {6, 2, 0, 0, 0},
            {4, 8, 1, 0, 0},
            {7, 4, 6, 0, 0},
            {8, 2, 9, 5, 7}};
    int n = 5;
    int sum = n * (n + 1) / 2+1;
    int SA[sum];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            SA[k] = Triangle[i][j];
            k++;
        }
    }
    SA[k]=Triangle[0][1];
    for (i = 0; i < sum; i++)
        printf("%d\n", SA[i]);
    return 1;
}
#include <stdio.h>
/*
    本程序以行优先存储、五阶数组为例
    存储空间 n(n+1)/2
    节省空间 n(n-1)/2
    地址k求法 k=i(i-1)/2+j-1
*/
//  主程序
int main()
{
    int i, j;
    int k = 0;
    int Symmetry[5][5] =
        {
            {3, 6, 4, 7, 8},
            {6, 2, 8, 4, 2},
            {4, 8, 1, 6, 9},
            {7, 4, 6, 0, 5},
            {8, 2, 9, 5, 7}};
    int n = 5;
    int sum = n * (n + 1) / 2;
    int SA[sum];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            SA[k] = Symmetry[i][j];
            k++;
        }
    }
    for (i = 0; i < sum; i++)
        printf("%d\n", SA[i]);
    return 1;
}
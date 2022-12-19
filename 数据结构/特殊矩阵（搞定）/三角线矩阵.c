#include <stdio.h>
/*
    本程序以行优先存储、五阶数组三对角线为例
    存储空间 3n-2 3为空对角线个数n为几阶矩阵
    地址求法 k=2(i-1)+j
*/
//  主程序
int main()
{
    int i, j;
    int k = 0;
    int TriangleLine[5][5] =
        {
            {3, 2, 0, 0, 0},
            {6, 2, 1, 0, 0},
            {0, 8, 1, 9, 0},
            {0, 0, 6, 7, 1},
            {0, 0, 0, 5, 7}};
    int n = 5;
    int sum = 3 * n - 2;
    int SA[sum];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (TriangleLine[i][j] != 0)
            {
                SA[k] = TriangleLine[i][j];
                k++;
            }
        }
    }
    for (i = 0; i < sum; i++)
        printf("%d\n", SA[i]);
    return 1;
}
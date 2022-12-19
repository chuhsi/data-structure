#include <stdio.h>

int main()
{
    int i, j, k;
    int n;
    printf("请输入一个数字:\n");
    scanf("%d", &n);
    for (i = 0, k = 1; i < n; i++)
    {
        for (j = 0; j < i + 1; j++, k++)
            printf("%4d", k);
        printf("\n");
    }
    return 0;
}
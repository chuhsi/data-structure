#include <stdio.h>

int main()
{
    int n;
    int i, j;
    printf("请输入你需要输出的金字塔三角形的行数:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
            printf(" ");
        for (j = 0; j < i + 1; j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}
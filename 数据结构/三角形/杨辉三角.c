#include <stdio.h>

int main()
{
    int rows = 0;   //行数
    int number = 1; //数字值
    int space = 0;  //空格
    int i, j = 0;   //控制循环

    printf("输入行数:");
    scanf("%d", &rows);
    for (i = 0; i < rows; i++)
    {
        for (space = 1; space <= rows - i; space++)
            printf("  ");
        for (j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
                number = 1;
            else
                number = number * (i - j + 1) / j;
            printf("%4d", number);
        }
        printf("\n");
    }
    return 0;
}
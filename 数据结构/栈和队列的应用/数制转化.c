#include <stdio.h>
#define MAX 10
//  转化方法
void conversion(int n, int r)
{
    int stack[MAX], top = -1; //定义一个顺序栈
    int x;
    while (n)
    {
        stack[top++] = n % r;
        n = n / r;
    }
    while (top != -1)
    {
        x = stack[top--];
        printf("%d\n", x);
    }
}
//  主程序
int main()
{
    int n = 3456, r = 8;
    conversion(n, r);
    return 1;
}
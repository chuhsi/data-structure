#include <stdio.h>
//  递归方法
int fac(int n)
{
    int f;
    if (n == 0)
        f = 1;
    else
        f = n * fac(n - 1);
    return f;
}
//  主程序
int main()
{
    int m,n=3;
    m=fac(n);
    printf("%d\n",m);
    return 1;
}
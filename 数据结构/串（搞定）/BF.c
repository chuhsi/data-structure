#include <stdio.h>
//  简单模式匹配
int BF(char *s, char *t)
{
    int i = 1;
    int j = 1;
    while (i <= s[0] && j <= t[0])
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > t[0])
        return (i - t[0]);
    else
        return 0;
}
//  主程序
int main()
{
    char s[] = {11, 'a', 'b', 'a', 'b', 'b', 'a', 'b', 'b', 'c', 'd', 'a'};
    char t[] = {5, 'a', 'b', 'b', 'c', 'd'};
    int len=BF(s,t);
    printf("%d\n",len);
    return 1;
}
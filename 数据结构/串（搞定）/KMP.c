#include <stdio.h>
//  求next[]值
void Next_value(char *t, int *next)
{
    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i < t[0])
    {
        if (j == 0 || t[i] == t[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
//  模式匹配KMP
int KMP(char *s, char *t, int *next)
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
            j = next[j];
    }
    if (j > t[0])
        return (i - t[0]);
    else
        return 0;
}
//  主程序
int main()
{
    char s[] = {15, 'a', 'b', 'a', 'b', 'b', 'a', 'a', 'b', 'b', 'a', 'b', 'b', 'c', 'd', 'e'};
    char t[] = {6, 'a', 'b', 'b', 'a', 'b', 'b'};
    int next[6];
    int j = KMP(s, t, next);
    printf("%d\n", j);
    return 1;
}
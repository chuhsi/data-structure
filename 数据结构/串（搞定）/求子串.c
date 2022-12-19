#include <stdio.h>
//  串长
int StrLength(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
//  求子串
int StrSub(char *sub, char *s, int i, int len)
{
    int slen, j;
    slen = StrLength(s);
    if (i < 1 || i > slen || len < 0 || len > slen - i + 1)
        return 0;   //参数不对
    for (j = 0; j < len; j++)
        sub[j] = s[i + j - 1];
    sub[j] = '\0';
    return 1;
}
//  主程序
int main()
{
    char sub[6];
    char s[] = "abcdefgfijk";
    StrSub(sub, s, 3, 5);
    int j;
    for (j = 0; j < StrLength(sub); j++)
    {
        putchar(sub[j]);
        printf("\n");
    }
    return 1;
}
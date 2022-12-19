#include <stdio.h>
#define MAXISIZE 20
//  串长
int StrLength(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
//  串连接
int StrConcat(char *s1, char *s2, char *s)
{
    int i = 0, j, len1, len2;
    len1 = StrLength(s1);
    len2 = StrLength(s2);
    if (len1 + len2 > MAXISIZE - 1) 
        return 0;       //新串s长度大了
    j = 0;
    while (s1[j] != '\0')
    {
        s[i] = s1[j];
        i++;
        j++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        s[i] = s2[j];
        i++;
        j++;
    }
    s[i] = '\0';
    return 1;
}
//  主程序
int main()
{
    char s1[] = "1234";
    char s2[] = "abcd";
    char s[MAXISIZE];
    StrConcat(s1, s2, s);
    int len = StrLength(s1) + StrLength(s2);
    for (int j = 0; j < len; j++)
    {
        putchar(s[j]);
        printf("\n");
    }
    return 0;
}
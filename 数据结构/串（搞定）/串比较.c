#include <stdio.h>
//  串比较
int StrComp(char *s1, char *s2)
{
    int j = 0;
    while (s1[j] == s2[j] && s1[j] != '\0')
        j++;
    return s1[j] - s2[j];
}
//  主程序
int main()
{
    char s1[] = "12345";
    char s2[] = "1234";
    int i = StrComp(s1, s2);
    printf("%d", i);
    return 0;
}
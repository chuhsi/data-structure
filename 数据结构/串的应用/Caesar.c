#include <stdio.h>
/*
    s为明文
    t为密文
    m代表移动位数
*/
//  加密
void CaesarEncode(char *s, char *t, int m)
{
    int i;
    t[0] = s[0];
    for (i = 1; i <= s[0]; i++)
        t[i] = (s[i] + m) % 26;
}
//  解密
void CaesarDecode(char *s, char *t, int m)
{
    int i;
    s[0] = t[0];
    for (i = 1; i <= t[0]; i++)
        // if (t[i] >= 'a' + m)
        //     s[i] = (t[i] - 'a' + m) % 26 + 'a';
        // else
            s[i] = t[i] + 26 - m;
}
//
int main()
{
    char s[] = "4data";
    char t[6];
    CaesarEncode(s, t, 3);
    // for (int i = 1; i < 5; i++)
    // {
    //     // printf("\n");
    //     printf("%d\n",t[i]);
    //     // putchar(t[i]);
    // }
    CaesarDecode(s,t,3);
    for (int i = 1; i < 5; i++)
    {
        // printf("\n");
        printf("%d\n",s[i]);
        // putchar(t[i]);
    }
    return 1;
}
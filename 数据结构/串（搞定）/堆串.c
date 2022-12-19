#include <stdio.h>
#include <stdlib.h>
//  堆存储结构
typedef struct
{
    char *ch;
    int length;
} HString;
//  串赋值
void StrAssign(HString *t, char *chars)
{
    if (t->ch)
        free(t->ch);
    int i;
    int len = 0;
    while (chars[len] != '\0')
        len++;
    if (!len)
    {
        t->ch = NULL;
        t->length = 0;
    }
    else
    {
        t->ch = (char *)malloc(len * sizeof(char)); //分配空间
        for (i = 0; i < len; i++)
            t->ch[i] = chars[i];
        t->length = len;
    }
}
//  串复制
void StrCopy(HString *s1, HString s2)
{
    int i;
    if (s1->ch)
        free(s1->ch);
    if (!s2.length)
    {
        s1->ch = NULL;
        s1->length = 0;
    }
    else
    {
        s1->ch = (char *)malloc(s2.length * sizeof(char));
        for (i = 0; i < s2.length; i++)
            s1->ch[i] = s2.ch[i];
        s1->length = s2.length;
    }
}
//  求子串
void SubStr(HString *sub, HString s, int i, int len)
{
    int j, k;
    int slen = 0;
    while (s.ch[slen] != '\0')
        slen++;
    if (i < 1 || i > slen || len < 0 || len > slen - i + 1)
        printf("参数不正确");
    if (!len)
    {
        sub->ch = NULL;
        sub->length = 0;
    }
    else
    {
        sub->ch = (char *)malloc(len * sizeof(char));
        for (j = 0, k = i - 1; j < len && k <= i + len - 2; j++, k++)
            sub->ch[j] = s.ch[k];
        sub->length = len;
    }
}
//  串连接
void Concat(HString *s, HString s1, HString s2)
{
    if (s->ch)
        free(s->ch);
    int i, j, k;
    int len = s1.length + s2.length;
    s->ch = (char *)malloc(len * sizeof(char));
    for (i = 0; i < s1.length; i++)
        s->ch[i] = s1.ch[i];
    for (j = s1.length, k = 0; j < len && k < s2.length; j++, k++)
        s->ch[j] = s2.ch[k];
    s->length = len;
}
//  主程序
int main()
{
    return 0;
}
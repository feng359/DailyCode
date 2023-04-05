#include <stdio.h>
#include <stdlib.h>

int main()
{

    //字符串和整型数字之间的转换，atoi()和itoa()的使用。
    int a = 0;
    a = atoi("123");
    printf("%d", a);
    puts("");

    char *p;
    itoa(a, p, 10);
    printf("%s", p);

    return 0;
}
#include<stdio.h>

void foo(char *cc)
{
    printf("%s\n",cc[0]);
    printf("%s\n",(0x0012FF5C));
    cc++;
    printf("%s\n",cc);
}

int main()
{
    char *c[] = {"Hello","World"};
    foo(c);
}


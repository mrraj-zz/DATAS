#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _struct {char *str;};

void allocate_and_initialize(struct _struct *s)
{
    s -> str = malloc(12);
    strcpy(s->str, "hello world");
}

void main(void)
{
    struct _struct _struct;
    allocate_and_initialize(&_struct);
    printf("%s\n", _struct.str);
}


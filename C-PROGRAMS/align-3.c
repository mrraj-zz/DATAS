#include <stdio.h>

struct my_float {
        float number;
}  __attribute__((aligned(0x1000)));

struct my_float a[4] = { {1.0}, {2.0}, {3.0}, {4.0} };

void
main(void)
{
        printf("%p %p %p %p\n", &a[0], &a[1], &a[2], &a[3]);
}


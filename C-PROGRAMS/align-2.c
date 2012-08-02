#include <stdio.h>

float a[4] __attribute__((aligned(0x1000))) = {1.0, 2.0, 3.0, 4.0};

void main(void)
{
        printf("%p %p %p %p\n", &a[0], &a[1], &a[2], &a[3]);
}


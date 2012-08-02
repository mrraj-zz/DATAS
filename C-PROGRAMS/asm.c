#include <stdio.h>
#include<linux/types.h>

static inline __u8 inb (__u16 port) {
    __u8 data;
    asm volatile("inb %1,%0" : "=a" (data) : "dN" (port));
    return data;
}

int main()
{
    __u16 p_port = 22;
    printf("hello world %u\n", inb(p_port));
    return 0;
}


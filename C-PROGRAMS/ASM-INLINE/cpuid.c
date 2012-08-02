#include<stdio.h>

static inline
void cpuid( int code, dword * a, dword * d )
{
    asm volatile( "cpuid"
                  : "=a"(*a), "=d"(*d) : "0"(code) : "ebx", "ecx");
}

void main()
{
}

#include<stdio.h>
#include<unistd.h>

static av_always_inline void AV_WN64(void *p, uint64_t v)
{
    __asm__ ("str  %Q2, %0  \n\t;"
         "str  %R2, %1  \n\t;"
         : "=m"(*(uint32_t*)p), "=m"(*((uint32_t*)p+1))
         : "r"(v));
}

void main(void)
{
  int a = 100, *ab;
  ab = &a;
  AV_WN64(ab, 100);
}

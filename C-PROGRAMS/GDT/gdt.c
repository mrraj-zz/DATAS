#include<stdio.h>

#define __AC(X, Y) (X##Y)


#define GDT_ENTRY(flags, base, limit)                   \
        ((((base)  & 0xff000000) << (56-24)) | \
         (((flags) & 0x0000f0ff) << 40) |      \
         (((limit) & 0x000f0000) << (48-16)) | \
         (((base)  & 0x00ffffff) << 16) |      \
         (((limit) & 0x0000ffff)))


void main(void)
{
  printf("ADDRESS : %u \n", GDT_ENTRY(0xc09b, 0, 0xfffff));
  printf("ADDRESS : %u \n", GDT_ENTRY(0xc093, 0, 0xfffff));
  printf("ADDRESS : %u \n", GDT_ENTRY(0x0089, 4096, 103));
}

#include<stdio.h>
#include<linux/types.h>

struct magic {
  __u16 cl_magic;
  __u16 cl_offset;
};

void main()

#include<stdio.h>

void asm_file(void *, void *);

void main(void)
{
  int i = 0;
  FILE *file_read = fopen("file_open.c", "r+");
  FILE *file_write = fopen("file_write.c", "r+");
  printf("File Pointer is : %p \n", file_read);
  printf("File Pointer is : %p \n", file_write);
    printf("%c", *file_read);
  asm_file(file_read, file_write);
}

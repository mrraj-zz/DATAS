#include<stdio.h>
#include<linux/types.h>

void main(void)
{
	FILE *file = fopen("fread", "rb");
	int read_blocks, block_size, blocks;

  // obtain file size:
  fseek (file , 0 , SEEK_END);
  blocks = ftell (file);
  rewind (file);
printf("dddddd : %d \n", blocks);
	char block_ptr[blocks];
	
	read_blocks = fread(block_ptr, 1, blocks, file);
	printf("readed blocks %d \n", read_blocks);
	printf("block_size %d \n", block_size);
	printf("no of blocks %d \n", blocks);
	printf("no of blocks %s \n", block_ptr);
}

#include<stdio.h>
#include<linux/types.h>

struct cmdline {
	__u16 cl_magic;
	__u16 cl_offset;
} __attribute__((packed));

#define OLD_CL_ADD 0x020;

void main(void)
{
	const struct cmdline *const cmd = (const struct cmdline *)OLD_CL_ADD;
	printf("%p \n", cmd);
	printf("%p \n", &cmd -> cl_magic);
	printf("%p \n", &cmd -> cl_offset);
}

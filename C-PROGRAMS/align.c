#include<stdio.h>

struct sandbox {
	int id;
	int num;
}__attribute__((packed));

struct sandbox_1 {
	int id;
};

void main(void)
{
	struct sandbox sandbox = { 10000, 20000 };
	printf("%d \n", sizeof sandbox);
	printf("%p \n", &sandbox.id);
	printf("%p \n", &sandbox.num);

	struct sandbox_1 sandbox_1;
	printf("%d \n", sizeof sandbox_1);

	int result __attribute__((at(0x500))) = 10;
	printf("%p \n", &result);
}

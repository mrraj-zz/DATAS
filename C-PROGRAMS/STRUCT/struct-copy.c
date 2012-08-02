#include<stdio.h>
#include<linux/types.h>
#include<stdlib.h>

struct empl_1 {
	__u16 value;
	__u8 name;
};

struct empl_2 {
	__u16 value_1;
	__u8 name_1;
};

void main(void)
{
	struct empl_1 emp_1 = {100, 50};
/*
	memcpy(&emp_2, &emp_1, sizeof emp_1);
	printf("value : %u \n", emp_2.value_1);
	printf("name : %u \n", emp_2.name_1);
*/
	struct empl_2 *emp_3 = (void *)&emp_1;
	printf("%u \n", emp_3 -> value_1);
	printf("%u \n", emp_3 -> name_1);
}

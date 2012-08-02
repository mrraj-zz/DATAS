#include<stdio.h>

struct employee {
	int id;
	char *name;
	char *address;
}empl_1 = { 10, "Mohanraj", "Chennai" }, empl_2 = { 2, "Soundar", "Pandruti" };

void main()
{
	struct employee *emp_1 = &empl_1;
	struct employee *emp_2 = &empl_2;

	printf("ID \t NAME \t ADDRESSS\n");

	printf("%d \t %s \t %s\n", emp_1 -> id, emp_1 -> name, emp_1 -> address);
	printf("%p \t %p \t %p\n", &(emp_1 -> id), &(emp_1 -> name), &(emp_1 -> address));

	printf("%d \t %s \t %s\n", emp_2 -> id, emp_2 -> name, emp_2 -> address);
	printf("%p \t %p \t %p\n", &(emp_2 -> id), &(emp_2 -> name), &(emp_2 -> address));
}

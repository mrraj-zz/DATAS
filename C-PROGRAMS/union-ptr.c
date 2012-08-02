#include<stdio.h>

union union_employee {
	char *name;
}union_emp = { "Ramanujam" };

void main()
{
	union union_employee *union_employee;
	union_employee = &union_emp;
	
	printf("%s \n", union_employee -> name);
	printf("%p \n", union_employee);
	printf("%p \n", &union_emp);
}

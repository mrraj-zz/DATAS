#include<stdio.h>

struct employee {
	int id;
	char *name;
	char *designation;
	long salary;	
};

void main()
{
	struct employee emp;
	emp.id = 1;
	emp.name = "Mohanraj";
	emp.designation = "Software Engineer";
	emp.salary = 20000;

	printf("ID \t NAME \t DESIGNATION \t SALARY\n");
	printf("%d \t %s \t %s \t %ld\n", emp.id, emp.name, emp.designation, emp.salary);
}

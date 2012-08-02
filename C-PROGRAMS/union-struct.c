#include<stdio.h>


struct struct_emp_1 {
	int id;
	char *name;
	char *address;
};

struct struct_emp_2 {
	int roll_no;
	char *name;
};

union employee {
	struct struct_emp_1 emp_1;
	struct struct_emp_2 emp_2;
};

void main()
{
	union employee union_emp;
	union_emp.emp_1;
	union_emp.emp_2;

	union_emp.emp_1.id = 1;
	union_emp.emp_1.name = "Mohanraj";
	union_emp.emp_1.address = "Chennai";
	
	printf("%d \t %s \t %s\n", union_emp.emp_1.id, union_emp.emp_1.name, union_emp.emp_1.address);

}

#include<stdio.h>

struct employee {
	int id;
	char *name;
	char *address;
}empl = { 10, "Soundara pandian", "Velleripattu" };

int main()
{
	struct employee *emp;
	emp = &empl;
	printf("Pointer address : %p\n", emp);

/*	emp -> id = 10;
	emp -> name = "Mohanraj";
	emp -> address = "Velleripattu";
*/
	printf("ID \t NAME \t ADDRESS\n");
	printf("%d \t %s \t %s\n", emp -> id, emp -> name, emp -> address);
}

/*
1 . Pointer to structure created here.
2 . We can assign the value to struct variable by different ways.
	a . Declare struct variable the assign using (.) operator.
	b . Declare pointer the assign struct variable to pointer, then assing using (.) or (->) operator.
3 . We can define a structure, and create a structured pointer,  is the good practice.
*/

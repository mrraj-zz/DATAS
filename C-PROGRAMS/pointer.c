#include<stdio.h>

struct emp_1 {
  int id;
  char *name;
};

struct company {
  int id;
  char *name;
  struct emp_1 emp;
};

void main(void)
{
  struct company company;
  struct emp_1 *emp = (struct emp_1 *)&company;
  
  company.id = 100;
  company.name = "Payoda";
  emp -> id = 100;
  emp -> name = "Mohanraj";

  printf("emp id is : %d \n", emp -> id);
  printf("emp name is : %s \n", emp -> name);
}

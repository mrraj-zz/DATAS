#include<stdio.h>

struct x { int a; int b; int c; };

void function(struct x *);

main()
{
  struct x z, *pz;	     /* 3 */
  pz = &z;		     /* 4 */
  z.a = 10;
  z.a++;

  function(pz);		     /* 5 */
}

void function(struct x * pz)
{			     /* 6 */
  printf(" first member %d \n", (*pz).a);   
}

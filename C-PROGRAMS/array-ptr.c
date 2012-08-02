
#include <stdio.h>
 
int array[] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
int *array_ptr;
 
int main()
{
    array_ptr = array;
    printf("%p\n ARRAY", array); /* array variable always contain the addres same as pointer*/
    while ((*array_ptr) != 0)
    {
        printf("%p\n", array_ptr);
        ++array_ptr;
    }
    printf("Number of elements before zero %d\n", array_ptr - array);
    return (0);
}

/*
1 . We can print the pointer variable address by using the '%p'.
2 . Array variable always contain the addres of starting(same as pointers).
3 . Pointers address are the virtual address, not exact RAM address.
*/

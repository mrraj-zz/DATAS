#include <varargs.h>
 
int summate(n, va_alist)
    va_dcl /* no semicolon here! */
{
    va_list ap;
    int i = 0;
 
    va_start(ap);
    for (; n; n--)
        i += va_arg(ap, int);
    va_end(ap);
    return i;
}

void main()
{
	printf("%d \n", summate(10,10));
}

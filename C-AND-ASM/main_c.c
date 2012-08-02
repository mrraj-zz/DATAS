#include <stdio.h>
const char* c_str = "Sup."; 
extern void s_func(void);

int main(void)
{
    printf(c_str); //prints as expected
    s_func(); //weird stuff
}


#include <stdio.h>

int main() {
    /* Add 10 and 20 and store result into register %eax */
    __asm__ ( "movl $10, %eax;"
                "movl $20, %ebx;"
                "addl %ebx, %eax;"
    );

    /* Subtract 20 from 10 and store result into register %eax */
    __asm__ ( "movl $10, %eax;"
                    "movl $20, %ebx;"
                    "subl %ebx, %eax;"
    );

    /* Multiply 10 and 20 and store result into register %eax */
    __asm__ ( "movl $10, %eax;"
                    "movl $20, %ebx;"
                    "imull %ebx, %eax;"
    );

    int result, eax = 100, ebx = 200;
    __asm__("addl %%ebx, %%eax;":"=a"(result):"a"(eax), "b"(ebx));
    printf("Addition: %d", result);

    __asm__("movl %0, %%eax;" : : "a" (eax));
    __asm__("movl %%eax, %0;" : "=a"(result));
    printf("Moved Data: %d \n", result);
    return 0 ;
}

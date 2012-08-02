#include<stdio.h>

typedef struct {  
    int recq;  
} dd;  

struct test {  
    dd a;  
};

void main(void){  
    struct test mm;
    printf("%p", &mm.a.recq); 
} 

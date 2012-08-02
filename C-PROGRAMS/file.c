#include<stdio.h>
main()
{
         FILE *fp;

         fp = fopen ( "struct.c","r" );
         if( fp == NULL )
         {
               puts("cannot open file");
         }
}

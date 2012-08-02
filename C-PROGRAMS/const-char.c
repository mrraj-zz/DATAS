#include<stdio.h>

const char *name = "Mohanraj\n"
		   "Ramanujam\n"
		   "Soundarapandian\n"
		   "Lakshmi kandan\n"
	 	   "Siva\n";
int prefixcmp(const char *str, const char *prefix)
{
        for (; ; str++, prefix++)
                if (!*prefix)
                        return 0;
                else if (*str != *prefix)
                        return (unsigned char)*prefix - (unsigned char)*str;
}

void main()
{
	printf("%s \n", name);
	printf("%d \n", prefixcmp("mohanraj", "soundarpandian"));
}

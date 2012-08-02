    #include<ctype.h>
    #include<stdio.h>
    #include<string.h>

    int main(void)
    {
      int loop;
      char string[]="THIS IS A TEST";

      for(loop=0;loop<strlen(string);loop++)
        string[loop]=tolower(string[loop]);

      printf("%s\n",string);
      return 0;
    }


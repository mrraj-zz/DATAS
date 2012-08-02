#include<stdio.h>
#include<string.h>

#define is_dir_sep(c) ((c) == '/' || (c) == '\\')

char *git_extract_argv0_path(const char *chr);

char *git_extract_argv0_path(const char *argv0)
{
        char *slash;

        if (!argv0 || !*argv0)
                return NULL;
        slash = argv0 + strlen(argv0);

	printf("%s \n", slash);
        while (argv0 <= slash && !is_dir_sep(*slash))
                slash--;
/*
        if (slash >= argv0) {
                argv0_path = xstrndup(argv0, slash - argv0);
                return slash + 1;
        }
*/
        return argv0;
}

void main()
{
	char *name = git_extract_argv0_path("/home/mohanraj");
	printf("%s \n", name);
}

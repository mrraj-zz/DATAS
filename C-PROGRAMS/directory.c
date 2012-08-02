/*
 * This program displays the names of all files in the current directory.
 */

#include <dirent.h> 
#include <stdio.h> 
#include <string.h>

void walk_dir(struct dirent *dir, DIR *d)
{
	if (d)
	{
		while((dir = readdir(d)) != NULL)
		{
			if(dir -> d_type == DT_DIR)
			{
				printf("%s\n", strcat("./",dir -> d_name));
				d = opendir(strcat("./",dir -> d_name));
				walk_dir(dir, d);
			}
			else
				printf("%s\n", dir -> d_name);
		}
		closedir(d);
	}
}

int main(void)
{
  DIR           *d;
  struct dirent *dir;
  d = opendir(".");
	walk_dir(dir, d);
  return(0);
}

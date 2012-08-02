#include<stdio.h>
#include<linux/screen_info.h>

struct new {
	int value;
};

void main(void)
{
	struct screen_info screen;
	screen.orig_x = 100;
	screen.orig_y = 100;
	printf("Size of screen structure %d \n", sizeof screen);
	struct new new;
	printf("Size of screen structure %d \n", sizeof new);
}

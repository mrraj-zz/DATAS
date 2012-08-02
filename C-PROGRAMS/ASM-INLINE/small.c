int tmult_ok2(int x, int y, int *dest)
{
	int result;
	*dest = x*y;
	asm("setae %%bl;"
	"movzbl %%bl,%[val];"
	: [val] "=r" (result)
	:
	: "%bl"
	);
}

void main(void)
{
	tmult_ok2(10, 100, 200);
}

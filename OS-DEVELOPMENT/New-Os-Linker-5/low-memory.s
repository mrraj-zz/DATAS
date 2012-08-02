	.text
	.globl low_memory
	.type low_memory, @function 
low_memory:
	xorw %ax, %ax
	int $0x12
	jc error
	test %ax, %ax
	jz error
error:	ret

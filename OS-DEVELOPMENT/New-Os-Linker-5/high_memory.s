	.text
	.globl high_memory
	.type high_memory, @function 
high_memory:
	movb $0x0A, %ah
	movb $0x68, %al
	int $0x10
	ret

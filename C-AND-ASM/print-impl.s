	.section .text
	.globl print
	.globl stop
	.type print, @function
	.type stop, @function
stop:
	movb $0x0, %ah
	int $0x16
	movb $0x4C, %ah
	int $0x21
	ret
	
print:
	push %bp
	mov %sp, %bp
	movb 8(%bp), %ah
	movb $0x0E, %ah
	int $0x10
	mov %bp, %sp
	pop %bp
	ret

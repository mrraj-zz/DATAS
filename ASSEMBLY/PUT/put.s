	.text
	.globl put_char

put_char:
	mov $0x0A, %ah
	mov $0x68, %al
	int $0x10

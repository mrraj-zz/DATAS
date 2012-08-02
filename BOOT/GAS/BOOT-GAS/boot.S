	.code16gcc
	.globl main

ljmp $0x0, $main

main:
	movw $0xa, %ax
	movw $0x7, %bx
	int $0x10

	.file	"cube.c"
	.section	.rodata
.LC0:
	.string	"%d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$2, 28(%esp)
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 28(%esp)
	addl	$1, 28(%esp)
	movl	28(%esp), %eax
	imull	28(%esp), %eax
	addl	$1, 28(%esp)
	movl	%eax, %edx
	imull	28(%esp), %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC0, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.1-9ubuntu3) 4.6.1"
	.section	.note.GNU-stack,"",@progbits

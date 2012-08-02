	.file	"kernel.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"Mohanraj Ramanujam =================================================================================================="
	.text
	.globl	kmain
	.type	kmain, @function
kmain:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$753664, -4(%ebp)
	movl	$0, -12(%ebp)
	movl	$.LC0, -8(%ebp)
	jmp	.L2
.L3:
	movl	-12(%ebp), %eax
	movl	-4(%ebp), %edx
	addl	%eax, %edx
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	addl	$1, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	-4(%ebp), %edx
	addl	%edx, %eax
	movb	$6, (%eax)
	addl	$1, -12(%ebp)
	addl	$1, -8(%ebp)
.L2:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L3
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	kmain, .-kmain
	.ident	"GCC: (Ubuntu/Linaro 4.6.1-9ubuntu3) 4.6.1"
	.section	.note.GNU-stack,"",@progbits

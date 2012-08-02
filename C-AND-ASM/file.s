
#VARIABLES: The registers have the following uses:
# description: this function takes an int array and multiplies
#              every element by 2 and adds 5.
# %edi - Holds the index of the data item being examined
# %ecx - size of the array
# %eax - pointer to first item in array
# %edx - used for scratch space
#
	.section .text
	.globl asm_file
	.type asm_file, @function
asm_file:
	popl %eax
	popl %ebx
	popl %eax
	popl %ebx
	ret                        # pop the return address and jmp to it

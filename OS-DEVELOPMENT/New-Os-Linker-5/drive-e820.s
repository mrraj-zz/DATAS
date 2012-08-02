	.text
	.globl do_e820
	.type do_e820, @function
	.set char_byte, 0xff
	.byte char_byte
do_e820:
	movb $0x0e, %ah
	movb $char_byte, %al
	int $0x10

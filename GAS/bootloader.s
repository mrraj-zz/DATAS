# .equ symbol, expression
# These directive set the value of the symbol to the expression
    .equ    BOOT_SEGMENT,0x07c0
    .equ    DISPLAY_SEGMENT,0xb800
    .equ	SECTOR_SIZE, 0x0200


.text               # Code segment
.globl    _start    # The entry point must be global
.code16             # Real mode

#
# The first instruction to execute in a program is called the entry
# point. The linker expects to find the entry point in the "symbol" _start
# (with underscore).
#

_start:
    jmp     over

drive_number:
	.byte	0x00
max_sector:
	.byte	0x00
max_head:
	.byte	0x00
os_size:
    # Area reserved for createimage to write the OS size
    .word   0
    .word   0

    # This is where the bootloader goes
    # Over prints a single character to the screen
over:
    movw    $DISPLAY_SEGMENT,%bx
    movw    %bx,%es
    movw    $0x074b,%es:(0x0)


movw	$BOOT_SEGMENT, %ax
movw	%ax, %ds

movb	%dl,drive_number

movb	$0x08, %ah
int	$0x13

andb	$0x3f, %cl
movb	%cl, max_sector

movb	%dh, max_head
movw	os_size, %bp

movw	$0x0002, %cx #sector number
movb	$0x00, %dh

movw	$0x0000, %ax
movw	%ax, %es
movw	$0x0100,%bx

	movw	$0,  %dx	
load_loop:	
	cmpw	$5, %dx		
	jge	loop1done	
 
	mov $0x0e,%ah
	mov $':',%al
	int $0x10

	#movw	%cx, %dx	
	incw	%dx

movb	drive_number, %dl
movw	$0x0201, %ax

xchgw	%bx, %bx

int $0x13
jc error

cmpb	max_sector, %cl
jnl	next_head
incb	%cl
jmp	after_next

jmp	load_loop


next_head:


	movb	$0x01, %cl
	cmpb	max_head, %dh
	jnl	next_cylinder
	incb	%dh
	jmp	after_next
next_cylinder:
	movb	$0x00, %dh
	incb	%ch
after_next:
	# Increment the destination
	addw	$SECTOR_SIZE, %bx
	# Check the carry bit
	jnc	load_loop
	# Advance the segment if it's on
	
	movw	%es, %ax
	addw	$0x1000, %ax
	movw	%ax, %es
	jmp	load_loop

error:

mov $0x0e,%ah
mov $'E',%al
int $0x10


forever: 
    # Loop forever
    hlt
    jmp     forever

loop1done:
mov $0x0e,%ah
mov $'C',%al
int $0x10


	#mov $0x9000,%bx
	#mov %bx,%ss
	#mov $0xfffe,%sp


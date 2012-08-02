entry start
start:
        mov     ah,#0x03                ; read cursor position.
        xor     bh,bh
        int     0x10		

        mov     cx,#26			; length of our beautiful string.
        mov     bx,#0x0007              ; page 0, attribute 7 (normal)
        mov     bp,#mymsg
        mov     ax,#0x1301              ; write string, move cursor
        int     0x10
loop1:	jmp	loop1


mymsg:
	.byte 13,10
	.ascii "Handling BIOS interrupts"





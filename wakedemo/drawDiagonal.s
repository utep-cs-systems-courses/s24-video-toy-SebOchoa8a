	.arch msp430g2553
	.p2align 1,0		; set memory boundary of 2 bytes with padding of zeroes


	
	.text
	.align 2
	.global drawLine
	.extern drawPixel

drawDiagonal:
	sub #6,r1
	mov.b r12, 0(r1)	; colo _col
	mov.b r13, 1(r1)	;row = _row
	mov.b r14, 2(r1)	;size = _size
	mov.b r15, 3(r1)	;color = _color
	mov.b #0, 4(r1) 	; val = 0
Top:
	cmp 2(r1), 4(r1)	;val-size
	jc Out
	call #drawPixel
	add #1, 0(r1)
	sub #1, 1(r1)
	add #1, 4(r1)
	jmp Top
Out:
	add #6, r1
	pop r0

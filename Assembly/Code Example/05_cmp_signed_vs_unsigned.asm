org 100h

mov ax, 1		; 0000 0000 0000 0001
mov bx, 0xFFFF	; 1111 1111 1111 1111
cmp ax, bx  
;jg end 	; uncomment this first - signed check (1 > -1)
;ja end 	; uncomment this aftewards - unsigned check (1 > 65535)

nop

end:
	mov     ah, 0 
	int     16h      
	ret     
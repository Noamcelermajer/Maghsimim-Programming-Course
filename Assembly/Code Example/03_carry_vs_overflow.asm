org 100h

; carry vs overflow

mov ax, 7fffh   ; 0111 1111 1111 1111
mov bx, 1       ; 0000 0000 0000 0001
add ax, bx   

mov ax, 0ffffh  ; 1111 1111 1111 1111
mov bx, 1       ; 0000 0000 0000 0001
add ax, bx 

mov ah, 0 
int 16h      
ret 
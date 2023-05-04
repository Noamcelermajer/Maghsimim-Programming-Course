	org  100h

	jmp start

; STRINGS SHOULD END WITH '\r\n$'                                    
str     db      'A','B','C',0Dh,0Ah,'$'
        
    start:   
; Example Print Fixed String
    PRINTN  "This is a fixed string"    
    
; Example Print String        
    
    lea     ax,str
    call	print_ax_str  
    
; Example Print Num
    mov     ax,123
    call    print_num
    PRINTN
    
; Example Print Char                
    mov     al,'Q'
    call	print_al_chr
    PRINTN

	ret


include magshimim.inc
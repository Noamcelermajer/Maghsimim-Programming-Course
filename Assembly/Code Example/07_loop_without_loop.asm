org 100h

    mov     ax,'A'
next:
    call    print_al_chr
    inc     ax
    cmp     ax,'Z'
    jbe     next
    
    mov     ah, 0 
	int     16h 
    ret   
 
include magshimim.inc
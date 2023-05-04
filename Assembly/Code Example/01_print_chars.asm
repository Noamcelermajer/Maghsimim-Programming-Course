ORG 100h            
    JMP start
    
str1 DB "coolio" 
str1_len EQU 6

start:
	MOV CX,str1_len
	MOV SI,OFFSET str1  
	
doloop:
	MOV AL,[SI]
	INC SI
	MOV AH,0h
	PUSH AX
	CALL printChar
	LOOP doloop
    JMP finish
    
    
printChar PROC
    push bp
	MOV BP, SP
	MOV DL, [BP+4]
	MOV AH, 2
	INT 21h 
	pop bp
	RETN 2 
printChar ENDP

finish: 
mov al,0
mov ah,4ch
int 21h    ;return 0
;ret return



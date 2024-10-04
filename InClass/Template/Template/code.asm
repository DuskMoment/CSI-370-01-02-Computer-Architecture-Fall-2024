;code.asm
extern testFunc : proto

.CODE

asmMain PROC
	;your code will go here
	mov r10, 10
	mov r11, 11

	add r11, r10

	call testFunc

	mov r10, rax

	mov rcx, 10 ;create perams
	mov rdx, 20 ;create persams

	call _masmTest

	ret
asmMain ENDP


_masmTest PROC
;prologe
	push rbp ;push rbp which is the bas frame pointer so that we know how to back
	sub rsp, 20h ;create shadow space for the fucntion (move the current stack pointer)
	lea rbp, [rsp + 20h] ;trasnfer control to the top of the function frame

	;function body
	mov rax, rcx
	add rax, rdx

	;epiloge
	lea rsp, [rbp]
	pop rbp
	ret
_masmTest EndP

END





;code.asm


.DATA
 ;array WORD 2,1,10,20,7
 array WORD 52, 7, 77, 20, 55, 86, 57, 56, 34, 19

 len equ ($ - array)

.CODE
asmMain PROC
	;your code will go here

	;get the size of the array in indexes 
	xor rdx, rdx
	mov rax, len
	
	mov rcx, 2
	DIV rcx 

	xor rcx, rcx ; clear out rcx

	lea rcx, array
	mov rdx, rax

	call _bubbleSort

	mov rcx, rax
	ret
asmMain ENDP

_bubbleSort proc
push rbp
sub rsp, 20h;shadow space
lea rbp, [rsp + 20h];start of function frame load effective address not mov

mov r12, 0;bool for if swaped
mov r10, 0;outer loop counter

outerLoop:
inc r10
mov r12, 0
	mov r11, -1;inner loop counter
	innerLoop:
		inc r11; inc counter

		;if statment
		mov ax, WORD PTR [rcx + r11 * 2] ; get first index position

		mov rsi, r11
		add rsi, 1
		mov bx, WORD PTR [rcx + rsi * 2]; get second index position

		cmp ax, bx
		jl skipTo

		mov r12, 1; we swapped so set it to true
		mov [rcx + rsi * 2], ax
		mov [rcx + r11 * 2], bx
		

		skipTo:
		;loop check
		mov rbx, rdx
		sub rbx, r10
		sub rbx, 1
		;mov rbx, [rdx-r10-1] ;get the right index for the cmp
		cmp r11, rbx
		jl innerLoop


;jump if we did not swap somthing 
cmp r12, 0
je loopBreak

cmp r10, rdx
jl outerLoop


loopBreak:

;epiloge code
mov rax, rcx;make sure the rax has the corret array

lea rsp, [rbp]
pop rbp

ret
_bubbleSort ENDP
	
END

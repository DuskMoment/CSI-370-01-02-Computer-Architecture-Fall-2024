; Program 3.1
; Sample Assembly Program - MASM (64-bit)
; Copyright (c) 2020 Hall & Slonka

extrn ExitProcess : proc ; This funciton is important its like return 0

.data ; setions inzalized and uninizalized 
sum QWORD 0

.code ;sections exicutable code / instructions 
_main PROC 
	mov rax, 25
	mov rbx, 50
	add rax, rbx
	mov sum, rax

xor rcx, rcx
call ExitProcess
_main ENDP
END

;0FFF0343h -> needs the 0 at the front to sigify number if it does not have one then it is a identifiyer  
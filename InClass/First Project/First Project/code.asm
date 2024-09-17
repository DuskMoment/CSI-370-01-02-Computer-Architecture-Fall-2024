; Program 3.1
; Sample Assembly Program - MASM (64-bit)
; Copyright (c) 2020 Hall & Slonka

extrn ExitProcess : proc ; This funciton is important its like return 0 function prototype for the exitProcess

.data ; setions inzalized and uninizalized - give it a guestion mark or a value
sum QWORD 0 ; other data types in slides for this week (week 3)
; arrays myArray QWORD 1,2,3,4 or charInput BYTE 'a'
; name type of array value comma seperated
; strings are in quotes !YOU HAVE TO MANUALY PUT IN THEEND CHARACHTER (,0)! newline value value is 0Dh 0Ah
; EQU cosntant infromation (name EQU data)
; $ current location counter

.code ;sections exicutable code / instructions 
_main PROC 
sub rsp, 28h
	mov rax, 25
	mov rbx, 50
	add rax, rbx
	mov sum, rax

xor rcx, rcx ; clears out the rcx register
call ExitProcess
_main ENDP
END

;0FFF0343h -> needs the 0 at the front to sigify number if it does not have one then it is a identifiyer  

;Labels - imortatnt for loops - like alias 
;	userLoop:
;			inc counter
;	otherLoop: inc counter2
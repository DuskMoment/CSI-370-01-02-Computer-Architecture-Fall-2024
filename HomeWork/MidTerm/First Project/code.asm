;Midterm- part 2 program 7.1
; William Mansfield

extrn ExitProcess : proc ; This funciton is important its like return 0 function prototype for the exitProcess

.data ; setions inzalized and uninizalized 
	string1 BYTE "Try harder still", 0
	str1Len equ ($ - string1)
	string2 BYTE "Try harder", 0
	str2Len equ ($ - string2)

.code ;sections exicutable code / instructions 
_main PROC ; start of the main procedure also indicates the entery point for the porgram
sub rsp, 28h ;create shadow space in the funciton

;load the array addresses

;find the bigger length
mov rax, str1Len
cmp rax, str2Len

jA firstCase
jmp secondCase

firstCase:
	lea rsi, string1
	lea rdi, string2

	mov rcx, str1Len
	mov r9, str1Len
	jmp endCase

secondCase:
	lea rsi, string2
	lea rdi, string1

	mov r9, str2Len
	mov rcx, str2Len

endCase:

repe cmpsb

;completly diffrent
sub r9, 1
cmp rcx, r9
je completyDiffrent

;broke early
cmp rcx, 0
ja diffrentAtCertainIndex

;no diff
jmp noDiff

completyDiffrent:

jmp skipToEnd

diffrentAtCertainIndex:

jmp skipToEnd

noDiff:

jmp skipToEnd


skipToEnd:
xor rcx, rcx ; 0s out the rcx register
call ExitProcess ; calls the exitProcess procedure and releases resources
_main ENDP ; marks the end of the _main proc
END ; indicates end of the program

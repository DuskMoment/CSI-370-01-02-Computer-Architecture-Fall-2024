;code.asm
 .data ; setions inzalized and uninizalized 
	string1 BYTE "Try harder still", 0
	str1Len equ ($ - string1)
	string2 BYTE "Try harder", 0
	str2Len equ ($ - string2)

	result QWORD ?; if word is 0 the it was a complete match... if result is 1 then the string is completey diffrent... if result is anyhting else then it was diffrent at that index
.code ;sections exicutable code / instructions 

asmMain PROC
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
mov result, 1

jmp skipToEnd

diffrentAtCertainIndex:
mov result, r9
sub result, rcx


jmp skipToEnd

noDiff:
mov result, -1

jmp skipToEnd


skipToEnd:
ret
asmMain ENDP
END

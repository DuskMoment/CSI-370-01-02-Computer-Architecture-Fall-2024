; alternate 2
; William Mansfield

extrn ExitProcess : proc ; This funciton is important its like return 0 function prototype for the exitProcess

.data ; setions inzalized and uninizalized 
	;pass
	pin DWORD 4,2,8,4 ;create a DWORD array with 4 numbers
	;pin DWORD 3,1,7,2
	;pin DWORD 6,4,9,5

	;fail bottom range
	;pin DWORD 1,2,8,4
	;pin DWORD 4,0,8,4
	;pin DWORD 4,2,6,4
	;pin DWORD 4,2,8,1

	;fail top range
	;pin DWORD 7,2,8,4
	;pin DWORD 4,5,8,4
	;pin DWORD 4,2,10,4
	;pin DWORD 4,2,8,6
	len EQU ($ - pin) ; get the length of the array
	firstValid DWORD 3,1,7,2 ;create a array of valid ranges
	firstLen EQU($- fisrtValid) ; get the length of the firstValid array
	secondValid DWORD 6,4,9,5; create a array of valid ranges
	secondLen EQU($- secondValid); get the length of secondValid array

	valid BYTE 0 ;create a BYTE var to store the score of the pin and see if it all pased (Should be 4 if pased)

.code ;sections exicutable code / instructions 
_main PROC ; start of the main procedure also indicates the entery point for the porgram
sub rsp, 28h ;create shadow space in the funciton

lea rsi, pin ;load the effective memeory address of pin
lea r12, firstValid ; load the effective memeory address of firstValid 
lea r14, secondValid; load the effective memeory address of secondValid

sub r11, 0; set r11 to zero

loopValid: ;lable for the loop
XOR eax, eax ;clear out eax of any junk (make it zero)
mov eax, [rsi + r11 * 4] ;move the index location of the pin array into eax

cmp eax, [r12 + r11 * 4] ;compair eax against our firstValid array at position r11
JB skipToEnd ;jump of the reslult is below 
cmp eax, [r14 + r11 * 4] ;compair eax against the secondValid array at pos r11
JA skipToEnd ;jump of the reslut was above

inc valid ;increase valid

;loop counter
cmp r11,3 ;compair our counter to the 3 literal
inc r11 ;inciment r11
JB loopValid; jump if below 3


skipToEnd: ;this is a label so we can jump to it to end the program

xor rcx, rcx ; 0s out the rcx register
call ExitProcess ; calls the exitProcess procedure and releases resources
_main ENDP ; marks the end of the _main proc
END ; indicates end of the program

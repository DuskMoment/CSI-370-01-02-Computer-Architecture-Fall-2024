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

	valid BYTE 0000b ;create a BYTE var to store the score of the pin and see if it all pased (Should be 15 if pased or 1111)

.code ;sections exicutable code / instructions 
_main PROC ; start of the main procedure also indicates the entery point for the porgram
sub rsp, 28h

lea rsi, pin ;load the effective memeory address of lea
;test first loction in the pin

cmp pin, 3 ;compair pin against 3
JB skipToEnd ;if the carry flag is below 3 then failed and skip to the end
cmp pin, 6 ;compair pin against 6
JA skipToEnd ;if the carry flag is above 6 then skip to the end

; add mask
OR valid , 1000b ;add a bit mask to valid so we have some data to check at the end

;validate second location
XOR eax, eax ;zero out location
mov eax, [rsi + 1 * 4] ;move the index location of the pin array into eax

cmp eax, 1 ;compair eax against 1
JB skipToEnd ;if the carry flag is below 1 then failed and skip to the end

cmp eax, 4 ;compair eax against 4
JA skipToEnd ;if the carry flag is above 4 then skip to the end

; add mask
OR valid , 0100b ;add a bit mask to valid so we have some data to check at the end

;validate third location
mov eax, [rsi + 2 * 4] ;move the index location of the pin array into eax

cmp eax, 7 ;compair eax against seven
JB skipToEnd ;if the carry flag is below 7 then failed and skip to the end

cmp eax, 9 ;compair eax against nine
JA skipToEnd ;if the carry flag is above 9 then skip to the end

; add mask
OR valid , 0010b ;add a bit mask to valid so we have some data to check at the end

;validate 4th location
mov eax, [rsi + 3 * 4] ;move the index location of the pin array into eax

cmp eax, 2 ;compair eax against 2
JB skipToEnd ;if the carry flag is below 2 then failed and skip to the end

cmp eax, 5 ;compair eax against 5
JA skipToEnd ;if the carry flag is above 5 then skip to the end

; add mask
OR valid , 0001b;add a bit mask to valid so we have some data to check at the end

skipToEnd: ;this is a label so we can jump to it to end the program

xor rcx, rcx ; 0s out the rcx register
call ExitProcess ; calls the exitProcess procedure and releases resources
_main ENDP ; marks the end of the _main proc
END ; indicates end of the program

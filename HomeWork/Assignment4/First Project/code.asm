; Program 3.4
; William Mansfield

extrn ExitProcess : proc ; This funciton is important its like return 0 function prototype for the exitProcess

.data ; setions inzalized and uninizalized 
	wArr WORD 5,10,15,20 ; delacre a WORD array with starting vals
		wLen equ ($ - wArr); gets the length of the array using the instruction pointer
	dArr DWORD 4 dup(?) ; declare DWORD array the same lenght as wArr but un inited
		dLen equ ($ - dArr); gets the length of the array using the instruction pointer

.code ;sections exicutable code / instructions 
_main PROC ; start of the main procedure also indicates the entery point for the porgram
sub rsp, 28h ;sub tracnt 28h from rsp (this is for the debugger)

mov ax, wArr ;move the first position of wArr into ax
mov dx, 8 ;move 8 into dx

mul dx ;multiply ax and dx
;store in dArr loc

LEA rsi, wArr; store the mem address of wArr
mov ax, [rsi + 2] ;take the mem address and add the offset pow(2) then move it to ax
mov dx, 8 ; move 8 into dx

mul dx;multiply ax and dx
;store in dArr loc

LEA rsi, wArr; store the mem address of wArr
mov ax, [rsi + 4] ;take the mem address and add the offset pow(2) then move it to ax
mov dx, 8 ; move 8 into dx

mul dx;multiply ax and dx
;store in dArr loc

LEA rsi, wArr; store the mem address of wArr
mov ax, [rsi + 16] ;take the mem address and add the offset pow(2) then move it to ax
mov dx, 8 ; move 8 into dx

mul dx ;multiply ax and dx




xor rcx, rcx ; 0s out the rcx register
call ExitProcess ; calls the exitProcess procedure and releases resources
_main ENDP ; marks the end of the _main proc
END ; indicates end of the program

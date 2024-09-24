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

LEA rsi, wArr ;load effective memeory address of wArr and place it in rsi
LEA rdi, dArr ;load effective memeory address of dArr and place it in rdi

;first multiplacation
mov ax, wArr ;move the first position of wArr into ax
mov dx, 8 ;move 8 into dx

mul dx ;multiply ax and dx
movzx ebx, ax ;store the 16 bit val in the 32 bit register using movzx (does not carry sign)
mov dArr, ebx ;store the val of ebx in the first pos of dArr 

;second multiplacation
mov ax, WORD PTR [rsi + 1 * 2] ;take the mem address and add the index * size and put it into ax
mov dx, 8 ; move 8 into dx

mul dx;multiply ax and dx
movzx ebx, ax ;store the 16 bit val in the 32 bit register using movzx (does not carry sign)
mov [rdi + 1 * 4], DWORD PTR ebx ;store the val of ebx in the correct index pos of dArr (locaiton + index * size)

;third multiplcation
mov ax, WORD PTR [rsi + 2 * 2] ;take the mem address and add the index * size and put it into ax
mov dx, 8 ; move 8 into dx

mul dx ;multiply ax and dx
movzx ebx, ax ;store the 16 bit val in the 32 bit register using movzx (does not carry sign)
mov [rdi + 2 * 4], ebx ;store the val of ebx in the correct index pos of dArr (locaiton + index * size)

;fourth mutliplcation
mov ax, [rsi + 3 * 2] ;take the mem address and add the index * size and put it into ax
mov dx, 8 ; move 8 into dx

mul dx ;multiply ax and dx
movzx ebx, ax;store the 16 bit val in the 32 bit register using movzx (does not carry sign)
mov [rdi + 3 * 4], ebx ;store the val of ebx in the correct index pos of dArr (locaiton + index * size)


xor rcx, rcx ; 0s out the rcx register
call ExitProcess ; calls the exitProcess procedure and releases resources
_main ENDP ; marks the end of the _main proc
END ; indicates end of the program

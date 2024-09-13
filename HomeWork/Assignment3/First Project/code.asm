; Program 3.4
; William Mansfield

extrn ExitProcess : proc ; This funciton is important its like return 0 function prototype for the exitProcess

.data ; setions inzalized and uninizalized 
	myString BYTE "The awnser is: ",0 ; we create inzialided data of size BYTE that contains a string 
									  ;we a ,0 to Signify the end

.code ;sections exicutable code / instructions 
_main PROC ; start of the main procedure also indicates the entery point for the porgram

mov rax , 1 ;moves the decimal 1 into the rax register
mov rbx , 2 ;moves the decunal 2 into the rbx register
add rax, rbx; adds the rbx and rax regisetrs and places it in rax

;define part two of the equation
mov rcx, 3 ;move the decimal 4 into the rcx register
mov rdx, 4 ;move the decimal 4 into the rdx register
add rcx, rdx ;add rdx to rcx sum is stored in the rcx register

sub rax, rcx ;subract the rcx regisert from the rax register and store in the rax register 
;(will return a negitive number)


xor rcx, rcx ; 0s out the rcx register
call ExitProcess ; calls the exitProcess procedure and releases resources
_main ENDP ; marks the end of the _main proc
END ; indicates end of the program

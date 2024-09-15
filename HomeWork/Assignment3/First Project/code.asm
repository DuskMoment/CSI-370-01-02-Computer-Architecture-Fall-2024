; Program 3.4
; William Mansfield

extrn ExitProcess : proc ; This funciton is important its like return 0 function prototype for the exitProcess

.data ; setions inzalized and uninizalized 
	myString BYTE "The awnser is: ",0 ; we create inzialided data of size BYTE that contains a string 
									  ;we a ,0 to Signify the end
	D DWORD 1 ;create a dword with the value 1 -> 4 bytes
	C DWORD 2 ;create a dword with the value 2 -> 4 bytes
	B DWORD 3 ;create a dword with the value 3 -> 4 bytes
	A DWORD 4 ;create a dword with the value 4 -> 4 bytes


.code ;sections exicutable code / instructions 
_main PROC ; start of the main procedure also indicates the entery point for the porgram

mov eax , A ;moves the DWORD A into the eax register
mov ebx , B ;moves the DWORD B into the ebx register
add eax, ebx; adds the eax and ebx regisetrs and places it in eax

;define part two of the equation
mov ecx, C ;move the DWORD C into the ecx register
mov edx, D ;move the DWORD D into the edx register
add ecx, edx ;add ecx to edx sum is stored in the rcx register

sub eax, ecx ;subract the ecx regisert from the eax register and store in the eax register 

xor rcx, rcx ; 0s out the rcx register
call ExitProcess ; calls the exitProcess procedure and releases resources
_main ENDP ; marks the end of the _main proc
END ; indicates end of the program

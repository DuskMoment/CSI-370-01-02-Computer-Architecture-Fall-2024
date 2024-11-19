; Program 3.4
; William Mansfield

extrn ExitProcess : proc ; This funciton is important its like return 0 function prototype for the exitProcess
extrn MessageBoxA : proc
extrn CreateFileA : proc
extrn ReadFile : proc
extrn CloseHandle : proc
extrn GetLastError :proc
extrn WriteFile : proc

.data ; setions inzalized and uninizalized 
	

	sucMessage BYTE "file has copied",0
	failMessage BYTE "Somthing has failed",0
	outputFileName BYTE "output.txt",0

	inputFile BYTE "input.txt", 0
	bufferSize QWORD 100
	buffer BYTE 101 dup(0)

	caption BYTE "myWindow",0

	;return data
	FD QWORD ?
	FD2 QWORD ?
	read QWORD ?
	charsRead QWORD ?
	button QWORD ?
	closed QWORD ?
	closed2 QWORD ?
	

.code ;sections exicutable code / instructions 
_main PROC ; start of the main procedure also indicates the entery point for the porgram

	sub rsp, 10h
	sub rsp, 18h
	sub rsp, 20h

	;open file
	lea rcx, inputFile ;load the name of the file into the first register
	mov rdx, 80000000h ;read only code
	xor r8,r8 ;share mode
	xor r9,r9; security
	;stack additions
	mov QWORD PTR [rsp + 48h - 28h], 3 ; open exsiting code (reversed)
	mov QWORD PTR [rsp + 48h - 20h], 80h ;flags
	mov QWORD PTR [rsp + 48h - 18h], 0 ;template
	call CreateFileA

	mov FD, rax

	;read file
	mov rcx, FD
	lea rdx, buffer
	mov r8, bufferSize
	lea r9, charsRead
	mov QWORD PTR[rsp + 48h - 28h], 0
	call ReadFile
	;mov FD, rax

	;create new file
	lea rcx, outputFileName
	mov rdx, 10000000h ;GENERIC_ALL
	xor r8, r8
	xor r9, r9
	mov QWORD PTR [rsp + 48h - 28h], 4 ;OPEN_ALWAYS
	mov QWORD PTR [rsp + 48h - 20h], 80h ;flags
	mov QWORD PTR [rsp + 48h - 18h], 0 ;template
	call CreateFileA

	mov FD2, rax

	;write to new file
	mov rcx, FD2
	lea rdx, buffer
	mov r8, bufferSize
	lea r9, charsRead
	mov QWORD PTR [rsp + 48h - 28h], 0 
	call WriteFile

	cmp RAX, 0

	jbe fail

	
		;display window
		xor rcx, rcx
		lea rdx, sucMessage
		lea r8, caption
		xor r9, r9
		call MessageBoxA
		mov button,rax
		jmp skipTo
	fail:
		;display window
		xor rcx, rcx
		lea rdx, failMessage
		lea r8, caption
		xor r9, r9
		call MessageBoxA
		mov button,rax

	skipTo:
	mov rcx, FD
	call CloseHandle
	mov closed,rax

	mov rcx, FD2
	call CloseHandle
	mov closed2, rax





call ExitProcess ; calls the exitProcess procedure and releases resources
_main ENDP ; marks the end of the _main proc
END ; indicates end of the program

;https://learn.microsoft.com/en-us/windows/win32/secauthz/generic-access-rights

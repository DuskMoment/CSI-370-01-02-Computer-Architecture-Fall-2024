; 6.4 normalizing vectors

extrn ExitProcess : proc 

Vector2f STRUCT	
	x REAL4 ?
	y REAL4 ?

Vector2f ENDS
.data 
align 16
testVecArray REAL4 4.5, 6.6

;main start
.code 
_main PROC 
	sub rsp, 28h

	lea rax, testVecArray

	vmovaps xmm1, XMMWORD PTR [rax]

	mov rcx, 2

	call _PowPacked

	;move reslut back into xmm1 for additon
	vmovaps xmm1, xmm0
	;clear zmm0
	XORPS xmm0, xmm0
	XORPS xmm2, xmm2

	call _GenSqrt

	;zero it out to the correct size of the vector
	andps xmm0, xmm1
	
	divps xmm0, xmm1

	;fix inf erros
	;orps xmm0, xmm1
	

	;clear xmm1
	xorps xmm1, xmm1	

	xor rcx, rcx ; clears out the rcx register
call ExitProcess
_main ENDP

;takes two things the number xmm1 and the exponet rcx
_Pow PROC
	push rbp
	sub rsp, 20h
	lea rbp, [rsp + 20h]

	dec rcx ;make it a 0-x range

	;save of the value
	movss xmm0, xmm1


	myLoop:
		mulps xmm0, xmm1
	loop myLoop

	lea rsp, [rbp]
	pop rbp
	ret
_Pow ENDP

;takes rcx counter and xmm1 as the operands
_PowPacked PROC
	push rbp
	sub rsp, 20h
	lea rbp, [rsp + 20h]

	sub rcx, 1

	;save the values
	vmovaps xmm0, xmm1

	powLoop:
		MULPS xmm0, xmm1
	loop powLoop
	
	lea rsp, [rbp]
	pop rbp
	ret
_PowPacked ENDP

_GenSqrt PROC
	push rbp
	sub rsp, 20h
	lea rbp, [rsp + 20h]

	;horizontal addition using AVX so i can palce the result in the first postion
	VHADDPS xmm0 ,xmm1, xmm0
	;spoof xmm2 for formating and getting one number
	VHADDPS xmm0, xmm0, xmm2

	;sqr root
	sqrtps xmm0, xmm0

	;creates a packed data full of the divisor
	haddps xmm0, xmm0
	haddps xmm0, xmm0

	

	lea rsp, [rbp]
	pop rbp
	ret
_GenSqrt ENDP
 END
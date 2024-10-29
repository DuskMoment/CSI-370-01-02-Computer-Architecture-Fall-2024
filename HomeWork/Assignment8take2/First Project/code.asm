; 6.4 normalizing vectors

extrn ExitProcess : proc 

Vector2f STRUCT	
	x REAL4 ?
	y REAL4 ?

Vector2f ENDS
.data 
align 16
testVecArray REAL4 4.5, 6.6

wallVec REAL4 2.2, 3.3
;givin some up vector (already normalized)
;wallNorm REAL4 1.0, 0.0

;main start
.code 
_main PROC 
	sub rsp, 28h

	lea rax, testVecArray

	vmovaps xmm0, XMMWORD PTR [rax]
	vmovaps xmm1, xmm0
	
	;square

	mulps xmm0, xmm0

	;add 

	haddps xmm0,xmm0
	haddps xmm0,xmm0

	shufps xmm0,xmm0, 8
	;root

	vsqrtps xmm0, xmm0
	

	;div
	vdivps xmm0, xmm1, xmm0
	;Noramilized!!

	;relfection vector
	lea rax, wallVec

	;some how geting a one 
	XORPS xmm2, xmm2
	vmovups xmm2, XMMWORD PTR [rax]

	;lea rax, wallNorm

	;vmovups xmm3, XMMWORD PTR [rax]

	;d - 2(d * n)n

	vmulps xmm4, xmm2, xmm3


	xor rcx, rcx ; clears out the rcx register
call ExitProcess
_main ENDP
 END
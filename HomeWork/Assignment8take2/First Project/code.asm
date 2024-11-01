; 6.4 normalizing vectors

extrn ExitProcess : proc 

Vector2f STRUCT	
	x REAL4 ?
	y REAL4 ?

Vector2f ENDS
.data 
align 16
vecArray2D REAL4 4.5, 6.6
align 16
vecArray3D REAL4 4.5, 6.6, 3.7

align 16
vecWall REAL4 1.0,4.8

align 16
;some up vec
vecNor REAL4 1.0,0.0

align 16
;const 
constant REAL4 -2.0

;main start
.code 
_main PROC 
	sub rsp, 28h

	lea rax, vecArray2D

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

	;2d relfection

	lea rax, vecWall

	vmovaps xmm3, XMMWORD PTR [rax]

	lea rax, vecNor

	vmovaps xmm4, XMMWORD PTR [rax]
	

	;d dot n (unnormalized d which is in xmm1)
	vmulps xmm5, xmm1, xmm4

	haddps xmm5, xmm5
	shufps xmm5,xmm5, 8

	lea rax, constant
	;-2(dn)
	vmovaps xmm6, XMMWORD PTR [rax]
	shufps xmm6,xmm6,128

	;mul 

	mulps xmm6, xmm5


	;2dn *n

	mulps xmm6, xmm4

	;add d -2dnn

	;reflection in xmm7
	vaddps xmm7, xmm0, xmm6

	;3d array
	lea rax, vecArray3D

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

	xor rcx, rcx ; clears out the rcx register
call ExitProcess
_main ENDP
 END
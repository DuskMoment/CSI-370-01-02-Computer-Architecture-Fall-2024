; 6.4 normalizing vectors

extrn ExitProcess : proc 

Vector2f STRUCT	
	x REAL4 ?
	y REAL4 ?

Vector2f ENDS
.data 
align 16
testVec Vector2f <4.5, 6.6>


.code 
_main PROC 
sub rsp, 28h

movss xmm1, testVec.x
movss xmm0, testVec.y

mov rcx, 2

call _Pow
movss testVec.x, xmm0



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

END




; Assignment 3.3
; Syntax Translation - GAS, Clang/LLVM on macOS (64-bit)
; Copyright (c) 2019 Hall & Slonka

extern ExitProcess : proc
;source and destination are switched
.data

letter BYTE ? ;.lcomm letter, 1
r DWORD ? ;.lcomm r, 4
s DWORD ? ;.lcomm s, 4
t DWORD ? ;.lcomm t, 4
x WORD ? ;.lcomm x, 2
y WORD ? ;.lcomm y, 2
z WORD ? ;.lcomm z, 2

.code ;.text
;.global _main
;_main:
_main PROC

mov letter, 077h ;movb $0x77, letter(%rip) ; all in hex
mov r, 05h;movl $0x5, r(%rip) - potentaily incorrect
mov s, 02h ;movl $0x2, s(%rip)
mov x, 0ah ;movw $0xa, x(%rip)
mov y, 04h ;movw $0x4, y(%rip)

mov ax, x ;movw x(%rip), %ax
add ax, y ;addw y(%rip), %ax
mov z, ax ;movw %ax, z(%rip)

mov ax, x ;movw x(%rip), %ax
sub ax, y ;subw y(%rip), %ax
mov z, ax ;movw %ax, z(%rip)

mov edx, 00h;movl $0x0, %edx
mov eax, r ;movl r(%rip), %eax
mov ecx, s ;movl s(%rip), %ecx
div ecx ;divl %ecx
mov t, eax ;movl %eax, t(%rip)

mov edx, 00h ;movl $0x0, %edx
mov eax, r ;movl r(%rip), %eax
mov ecx, s ;movl s(%rip), %ecx
div ecx ;divl %ecx
mov t, edx ;movl %edx, t(%rip)

;mov rax, 02000001h ;movq $0x2000001, %rax
;xorq %rdi, %rdi
;syscall
;.end
xor rcx, rcx
call ExitProcess
_main ENDP
END
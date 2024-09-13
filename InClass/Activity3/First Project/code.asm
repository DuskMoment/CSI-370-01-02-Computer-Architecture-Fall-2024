# Assignment 3.3
# Syntax Translation - GAS, Clang/LLVM on macOS (64-bit)
# Copyright (c) 2019 Hall & Slonka

extrn ExitProcess : proc
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

movb $0x77, letter(%rip) ; all in hex
movl $0x5, r(%rip)
movl $0x2, s(%rip)
movw $0xa, x(%rip)
movw $0x4, y(%rip)

movw x(%rip), %ax
addw y(%rip), %ax
movw %ax, z(%rip)

movw x(%rip), %ax
subw y(%rip), %ax
movw %ax, z(%rip)

movl $0x0, %edx
movl r(%rip), %eax
movl s(%rip), %ecx
divl %ecx
movl %eax, t(%rip)

movl $0x0, %edx
movl r(%rip), %eax
movl s(%rip), %ecx
divl %ecx
movl %edx, t(%rip)

movq $0x2000001, %rax
xorq %rdi, %rdi
syscall
.end
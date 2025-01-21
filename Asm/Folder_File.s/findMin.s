.section .data
data:
.short 4,2,3,1,123, 12, 0
.section .text
.globl _start
_start:
#movl: move long
#movw: move word
movl $0,%edi
movw data(,%edi,2),%ax
movw %ax,%bx

start_loop:
cmpw $12, %ax
je loop_exit
incl %edi
movw data(,%edi,2),%ax
cmpw %bx, %ax
jge start_loop
movw %ax, %bx
jmp start_loop

loop_exit:
movl $1, %eax
int $0x80

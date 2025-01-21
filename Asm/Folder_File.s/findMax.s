.section .data
data:
.long 2,3,5,123,23,51,300,11,0
.section .text
.globl _start
_start:
movl $0, %edi
movl data(,%edi,4), %eax
movl %eax, %ebx

#function loop
start_loop:
cmpl $0, %eax
#jump if equal
je loop_exit

incl %edi #increase index
movl data(,%edi,4),%eax
cmpl %ebx, %eax
#jump if less than or equal
jle start_loop


movl %eax, %ebx
#jump no matter what
jmp start_loop
loop_exit:
movl $1, %eax #exit syscall
int $0x80


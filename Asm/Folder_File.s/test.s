.section .data
print:
.ascii "hello World!\0"
data:
.int 2
.section .text
.globl _start
_start:
#print Hello World!
movl $4,%eax; #call sys_write
movl $1,%ebx; #File description stdout
movl $print, %ecx #address of the string to print
movl $12, %edx; #length of the string (12 characters)
int $0x80
#add with data
movl $data, %edx;
addl $2,%edx;
movl $1,%eax;	#sys_exit
movl $0,%ebx;	#Exit status
int $0x80

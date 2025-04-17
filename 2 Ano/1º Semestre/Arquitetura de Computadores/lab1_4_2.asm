.data

.text
.globl main

main:
 
 li $v0,5
 syscall
 li $a1,1
 li $a0,1
 li $t0,0
 move $a1,$v0
 
 
 loop:
 addi $t0,$t0,1
 mul $a0,$a0,$t0
 bne $t0,$a1,loop
 
 
 li $v0,1
 syscall
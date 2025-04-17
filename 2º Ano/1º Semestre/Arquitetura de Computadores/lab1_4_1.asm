.data

.text
.globl main

main:
 
 li $v0,5
 syscall
 li $a1,0
 li $a0,0
 li $t0,0
 move $a1,$v0
 mul $t0,$a1,3
 subi $t0,$t0,1
 
 loop:
 addi $a0,$a0,1
 li $v0,1
 syscall
 bne $a0,$t0,loop
.data 

.text
.globl main

main:
li $a0,0
li $v0, 0
li $t0, 0
li $t1, 100


MikeDi: addi $t0, $t0,1
	add $v0, $v0, $t0
	bne $t0, $t1,MikeDi

move $a0,$v0

li $v0,1

syscall
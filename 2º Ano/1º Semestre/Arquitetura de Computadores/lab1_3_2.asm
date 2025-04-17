.data
tab: .word 2,1,0,10,10,12,1,1,1,100
.text
.globl main

main:
la $t0,tab
li $a0,0
li $a1,1
li $v0,1

loop:
    lw $t2,0($t0)
    bge $t2,$a0,label
    addi $a1,$a1,1
    addi $t0,$t0,4
    beq $a1,11,exit
    j loop

label:
    move $a0,$t2
    addi $a1,$a1,1
    addi $t0,$t0,4
    beq $a1,11,exit
    j loop

exit:
    syscall
    li $v0,10
    syscall
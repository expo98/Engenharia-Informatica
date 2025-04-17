.data

esq: .word 0xFFFF0011
dir: .word 0xFFFF0010


.text
.globl main

main:

la $t0, dir
lw $s0, 0($t0)

li $a0,1

li $t0,0
loop:
sb $a0,($s0)
sll $a0,$a0,1

addi $t0, $t0, 1
bne $t0,8,loop
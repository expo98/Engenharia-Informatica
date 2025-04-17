.data 

lista: .byte 0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0xF7,0xFF,0xB9,0xBF,0XF9,0xF1
direita: .word 0xFFFF0010
esquerda: .word 0xFFFF0011


.text
.globl main

main:

la $t0, direita
lw $a0, 0($t0)

la $t1, esquerda
lw $a1, 0($t1)

li $s0,0
li $t3,0
li $s1,15


la $t7,lista
loop2:
la $s2,lista
li $s0,0

loop:

lbu $s3,($s2)
sb $s3,($a0)
addi $s2,$s2,1
addi $s0,$s0,1
bne $s0,$s1,loop
beq $t3,$s1,fim
lbu $s4,($t7)
sb $s4,($a1)
addi $t7,$t7,1
addi $t3,$t3,1
j loop2

fim:

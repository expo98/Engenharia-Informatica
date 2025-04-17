.data 

disp: .word 0x10010000
azul: .word 0x000000FF
magenta: .word 0x00FF00FF

.text
.globl main

main:

la $t0, disp
lw $s0, 0($t0)
# ou apenas li $s0, 0x1001000

la $t0, azul
lw $a0, 0($t0)
#ou apenas li $a0, 0x00FFFF00

la $t0, magenta
lw $a1, 0($t0)

#Limites do ecrã
li $t2, 32
li $t3, 64

#Inicio do quadrado
li $t5, 12
li $t6, 28

#Limite do quadrado
li $t7, 20
li $t8, 36


li $t0, 0

loop2:
li $t1, 0

loop:	
mul $t4, $t0, 64
add $t4, $t4, $t1
mul $t4, $t4, 4
add $t4, $s0, $t4
sw $a0, 0($t4)
addi $t1, $t1, 1
blt $t1, $t3, loop
addi $t0, $t0, 1
blt $t0, $t2, loop2


li $t5, 12
loop3:
li $t6, 28
loop4:
mul $t4, $t5, 64
add $t4, $t4, $t6
mul $t4, $t4, 4
add $t4, $s0, $t4
sw $a1, 0($t4)
addi $t6, $t6, 1
blt $t6, $t8, loop4
addi $t5, $t5, 1
blt $t5, $t7, loop3
	
	

	

 


.data

.text

li $t0, 12
li $t1, 18

main:

	sub $a0, $t0, $t1
	bgtz $a0, fim
	mul $a0, $a0, -1
	
	
fim:

li $v0,1
syscall


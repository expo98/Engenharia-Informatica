.data

numero: .word 0x10203040

.text

main:
	la $t0, numero
	lw $a0, 0($t0)	
	
	jal func
	
	move $a0,$v0
	
	li $v0,34
	syscall
	j fim


	func:
	andi $t0, $a0, 0x000000FF
	sll $v0,$t0,24
	
	andi $t0,$a0, 0x0000FF00
	sll $t0,$t0,8
	or $v0,$v0,$t0

	andi $t0,$a0, 0x00FF0000
	srl $t0,$t0,8
	or $v0,$v0,$t0	
	
	andi $t0, $a0, 0xFF000000
	srl $t0,$t0,24
	or $v0,$v0,$t0
	
	jr $ra
	
fim:


	
	
	

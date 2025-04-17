		.data

		.text
		.globl	polycalc
polycalc:

	# Codigo da fun��o aqui
	lw $t0,16($sp)
	
	move $v0, $t0
	mul $v0,$v0,$a3
	mul $v0,$a3,3
	
	sub $v0,$a3,$v0
	
	add $t1,$a0,$a1
	mul $t1,$t1,5
	mul $v0,$v0,$t1

	jr	$ra

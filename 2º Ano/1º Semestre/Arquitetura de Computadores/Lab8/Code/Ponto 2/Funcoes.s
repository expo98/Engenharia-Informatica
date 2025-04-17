	.data
	
	.text
	.globl	max
	.globl	min
	
max:

	#Codigo da fun��o max aqui!
	move $v0,$a0
	
	bgt $a1,$v0,cg1
	cpg1:
	bgt $a2,$v0,cg2
	cpg2:
	bgt $a3,$v0,cg3
	j exitg
	
	cg1:
	move $v0,$a1
	j cpg1
	
	cg2:
	move $v0,$a2
	j cpg2
	
	cg3:
	move $v0,$a3
	
	exitg:
	
	jr $ra

min:

	#Codigo da fun��o min aqui!
	
		move $v0,$a0
	
	blt $a1,$v0,cl1
	cpl1:
	blt $a2,$v0,cl2
	cpl2:
	blt $a3,$v0,cl3
	j exitl
	
	cl1:
	move $v0,$a1
	j cpl1
	
	cl2:
	move $v0,$a2
	j cpl2
	
	cl3:
	move $v0,$a3
	j exitl
	
	exitl:
	
	jr	$ra

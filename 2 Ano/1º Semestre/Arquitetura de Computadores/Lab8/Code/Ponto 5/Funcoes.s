	.data
	
	.text
	.globl	max
	
max:
	li $t1,0
	
	lw $t2, 0($a0)
	move $v0,$t2
	
	loop:
		beq $t1,$a1,exit
		
		bgt $t2,$v0,checkpoint
	
		
	checkpoint:
		move $v0,$t2
		addi $a0,$a0,4
		lw $t2, 0($a0)
		addi $t1,$t1,1
		j loop
	
	
	addi $a0,$a0,4
	lw $t2, 0($a0)
	addi $t1,$t1,1
	j loop
	
	exit:
	
	
	jr $ra


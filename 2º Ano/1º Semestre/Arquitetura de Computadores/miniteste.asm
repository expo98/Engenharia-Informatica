	.data
	
	.text
	.globl manipula
	
manipula:
	
	la $t1, 0($a0)
	lw $s1, $t1
	
	li $s2, $a1
	
	loop:
	
		sll $t1,$s1,3
		and $t2, $t1, 255
		
		srl $t1, $s1,8
		and $t3, $t1, 255
	
		and $s1, $s1, 0
	
		or $s1, $s1, $t2
		or $s1, $s1, $t3
	
		addi $s1, $s1, 8
		
		addi $s2,$s2,-1
		bgt $s2,0,loop
	
	

	move $v0,$s2

	jr $ra
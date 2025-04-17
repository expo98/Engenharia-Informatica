	.data
	
	.text
	.globl	conta_char
	
conta_char:

	li $t0, 0                    

    loop:
        lb $t2, 0($a0)    
        beqz $t2, fim

        beq $t2, $a1, contador 

        addi $a0, $a0, 1    
        j loop

    contador:
        addi $t0, $t0, 1    

        addi $a0, $a0, 1
        j loop

    fim:
        move $v0, $t0

	jr	$ra

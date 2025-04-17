	.data
	
	.text
	.globl	Mandelbrot
	.globl  Square

	
Mandelbrot:

	#Codigo da função Mandelbrot aqui!
	
	 beqz $a1, exit
	 
	
	
	
	
	exit:
		move $v0,$a0
		
	jr	$ra




Square:
	mul $a0,$a0,$a0
	move $v0,$a0
	
	jr	$ra

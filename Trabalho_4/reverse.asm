.data

.text

	xor $s1, $s1, $s1 # contador 
	xor $s5, $s5, $s5 # número
	xor $s6, $s6, $s6 # rotação 
	
	add $s5, $zero, 1
	
	
	for:
		#add $s0, $zero .1 # mascara	
		add $s0, $zero, 1
		
		and $s0, $s0, $s5 # pega o último bit
		
		or $s6, $s6, $s0 #salva no registrador $s6


		add $s7, $zero ,$s6
	
		srl $s5, $s5, 1
		sll $s6, $s6, 1
	
		
		add $s1, $s1, 1
		
	bne $s1, 32, for 
		 
	
	
	
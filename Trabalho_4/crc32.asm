.data
buffer: .space 17	# Aloca 16 bytes de espaço para o buffer sem contar o terminador
msg1:	.asciiz "Digite a mensagem para ser convertida para crc32 (maximo 16 caracteres): "
quebra: .ascii 	"\n"
.text
main:
	jal le_string	# Leitura de string
	la $a0, buffer
	addi $v0, $0, 4
	syscall
	jal calc_crc32
calc_main:
	move $a0, $v0	# Carrega a resposta do calculo do crc pra printar
	jal imprime_saida	# Imprime a saida	
	addi $v0, $0, 10
	syscall		# Finaliza programa
endmain:

le_string:
	la $a0, msg1	# Carrega o endereco da mensagem na memoria
	addi $v0, $0, 4	
	syscall		# Imprime a mensagem no terminal
	
	la $a0, buffer	# Carrega o endereco do buffer na memoria
	addi $a1, $0, 17# Carrega o numero maximo de caracteres q podem ser lidas
			# contando com o terminador
	addi $v0, $0, 8	
	syscall		# Le a string
end_le_string:

reverse:
	move $s5, $a0	# Inicializando o $s5 com o valor da 
	xor $s1, $s1, $s1 # contador 
	xor $s6, $s6, $s6 # rotação 

	for_reverse:
		#add $s0, $zero .1 # mascara	
		add $s0, $zero, 1
		and $s0, $s0, $s5 # pega o último bit
		or $s6, $s6, $s0 # salva no registrador $s6
		add $s7, $zero ,$s6
		srl $s5, $s5, 1
		sll $s6, $s6, 1
		add $s1, $s1, 1
	bne $s1, 32, for_reverse
	
	move $v0, $s6	# Move a resposta para o registrador de retorno 
	jr $ra	# Retorna
end_reverse:

calc_crc32:
	# As proximas 2 linhas zeram os registrador
	move $t9, $0	# Contador para a mensagem
	move $t7, $0	# Registrador para o byte
	addi $t6, $0, 0xffffffff	# Mascata 0xFFFFFFFF do CRC		
	addi $t5, $0, 0x04c11db7	# Mascara do or 0x04C11DB7
	la $t4, buffer	# Carrega endereço da paralvra lida

	while:
		lb $t7, 0($t4)	# Carrega o byte da mensagem para o registrador
		beqz $t7, exit_while	# Verifica se e o terminador da string
		lb $t0, quebra	# Carrega a quebra de linha
		beq $t7, $t0, exit_while	#Verifica se e quebra de linha
		# Funcao de reverse
		move $a0, $t7
		jal reverse
		move $t7, $v0	# Move a resposta de $v0 para $t7
		
		move $t8, $0	# Zera contador do for
		for_crc:
			bgt $t8, 7, end_for_crc	# Se for maior do que 7 finaliza o for
			if:
				xor $t3, $t6, $t7	# byte xor crc mascara
				bgtz $t3, else	# Verifica se e menor que zero
				beqz $t3, else	# Verifica se e igual a zero
				sll $t6, $t6, 1	# Shift pra esquerda do crc
				xor $t6, $t6, $t5	#  crc xor 0x04C11DB7
				j end_if
			else:
				sll $t6, $t6, 1	# Shift pra esquerda do crc				
			end_if:
			sll $t7, $t7, 1	# Shift pra esquerda no byte da mensagem
			addi $t8, $t8, 1	# Adiciona 1 ao contador
			j for_crc	# retorna pro inicio do for
		end_for_crc:
		addi $t4, $t4, 1	# Adiciona 8 para ler o proximo byte da mensagem
		j while	# Retorna para o inicio do while
	exit_while:
	not $t6, $t6	# Faz um not crc
	# Funcao de reverse
	move $a0, $t6
	jal reverse
	j calc_main	# Retorna a funcao com o crc revertido
end_calc_crc_32:


imprime_saida:
	addi $v0, $0, 34	# Carrega numero referente ao print em hexadecimal
	syscall
end_imprime_saida:
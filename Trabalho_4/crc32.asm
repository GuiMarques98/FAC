.data
buffer: .space 17	# Aloca 16 bytes de espaço para o buffer sem contar o terminador
msg1:	.asciiz "Digite a mensagem para ser convertida para crc32 (maximo 16 caracteres): "
quebra: .ascii 	"\n"
.text
main:

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

reverse:


calc_crc32:


imprime_saida:

#include <stdio.h>

unsigned reverse(unsigned x) {
	x = ((x & 0x55555555) <<  1) | ((x >>  1) & 0x55555555);
	x = ((x & 0x33333333) <<  2) | ((x >>  2) & 0x33333333);
	x = ((x & 0x0F0F0F0F) <<  4) | ((x >>  4) & 0x0F0F0F0F);
	x = (x << 24) | ((x & 0xFF00) << 8) |
	((x >> 8) & 0xFF00) | (x >> 24);
	return x;
}

unsigned int crc32a(unsigned char *message) {
	int i, j;
	unsigned int byte, crc;

	i = 0;
	crc = 0xFFFFFFFF;
	while (message[i] != 0) {
		byte = message[i];            // Get next byte.
		byte = reverse(byte);         // 32-bit reversal.
		for (j = 0; j <= 7; j++) {    // Do eight times.
			if ((int)(crc ^ byte) < 0)
				crc = (crc << 1) ^ 0x04C11DB7;
			else 
				crc = crc << 1;
			byte = byte << 1;          // Ready next msg bit.
		}
		i = i + 1;
	}
	return reverse(~crc);
}

int main(int argc, char const *argv[]) {
	char in[16];
	unsigned a = 1;
	printf("unsigned int = %x ; reverse = %x\n", a, reverse(a));
	//scanf("%[^\n]", in);
	//printf("%x\n", crc32a(in));
	return 0;
}


/*
Questao 2: Perceba que o programa mantém registros excluídos no vetor e mantém um status no registro de cada 
aluno.  Porque  esse  campo  foi  necessário?  Responda  procurando  avaliar  vantagens  e  desvantagens  dessa estratégia. 
Você teria uma solução mais interessante em relação ao que foi proposto?
Para que se saiba se o elemento foi excluido ou não do vetor na hora de printar. As vantagens são na hora de escrever o 
algoritmo de exclusão do elemento q se faz mais facil, a desvantagem é na memória pois todos os elementos inseridos continuam
na memória do pc independente se foi excluido ou não. Sim, excluiria o elemento do vetor.
*/
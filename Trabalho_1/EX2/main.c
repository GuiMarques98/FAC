#include <stdio.h>

int main(int argc, char const *argv[]) {
	
	printf("Nome do executavel: %s\n",argv[0]);
	for (int i = 1; i < argc; ++i)
	{	
		printf("Parametro #%d: %s\n",i, argv[i]);
	}
	return 0;
}


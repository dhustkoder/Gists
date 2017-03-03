#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int i;
	int testcases;

	int aux;
	int lowest;
	int pos = 0;

	scanf("%d", &testcases);
	scanf("%d", &lowest);


	for (i = 1; i < testcases; ++i) {
		scanf("%d", &aux);
		if (aux < lowest) {
			lowest = aux;
			pos = i;
		}
	}

	printf("Menor valor: %d\nPosicao: %d\n", lowest, pos);

	return EXIT_SUCCESS;
}


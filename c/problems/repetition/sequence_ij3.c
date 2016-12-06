#include <stdio.h>

int main(void)
{
	int i, j, aux;
	
	for (i = 1, j = 7; i < 10; i += 2, j += 2) {
		for (aux = j; aux >= j - 2; --aux)
			printf("I=%d J=%d\n", i, aux);
	}

	return 0;
}



#include <stdio.h>

int main(void)
{
	int x, y, i, aux;
	scanf("%d %d", &x, &y);
	
	if (x > y) {
		aux = x;
		x = y;
		y = aux;
	}

	for (i = x + 1; i < y; ++i) {
		aux = i % 5;
		if (aux == 2 || aux == 3)
			printf("%d\n", i);
	}

	return 0;
}


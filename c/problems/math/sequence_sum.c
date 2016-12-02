#include <stdio.h>

int main()
{
	long x, y, aux, i;

	while (1) {
		scanf("%ld %ld", &x, &y);
		if (x <= 0 || y <= 0)
			break;

		if (x > y) {
			aux = y;
			y = x;
			x = aux;
		}

		for (i = x; i <= y; ++i)
			printf("%ld ", i);

		aux = ((x + y) * ((y - x) + 1)) / 2;
		printf("Sum=%ld\n", aux);
	}
	
	return 0;
}


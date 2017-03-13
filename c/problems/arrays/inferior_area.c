#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char op;
	int i, j;
	float value;
	float res = 0;
	
	scanf("%c", &op);

	for (i = 0; i < 7; ++i)
		for (j = 0; j < 12; ++j)
			scanf("%*f");


	for (i = 0; i < 5; ++i) {

		for (j = 0; j < (5 - i); ++j)
			scanf("%*f");

		for (; j < (7 + i); ++j) {
			scanf("%f", &value);
			res += value;
		}

		for ( ; j < 12; ++j)
			scanf("%*f");
	}

	printf("%.1f\n", op == 'S' ? res : res / 30);

	return EXIT_SUCCESS;
}


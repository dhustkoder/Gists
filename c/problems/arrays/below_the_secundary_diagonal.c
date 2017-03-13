#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	char op;
	int i, j;
	float value;
	float res = 0;

	scanf("%c", &op);

	for (i = 0; i < 12; ++i) {

		for (j = 0; j < (12 - i); ++j)
			scanf("%*f");

		for ( ; j < 12; ++j) {
			scanf("%f", &value);
			res += value;
		}
	}

	printf("%.1f\n", op == 'S' ? res : res / 66);

	return EXIT_SUCCESS;
}


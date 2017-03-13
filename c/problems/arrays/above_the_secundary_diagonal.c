#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char op;
	float value;
	float res = 0;
	int i, j;

	scanf("%c", &op);

	for (i = 0; i < 12; ++i) {

		for (j = 0; j < (11 - i); ++j) {
			scanf("%f", &value);
			res += value;
		}

		for (; j < 12; ++j)
			scanf("%*f");
	}

	printf("%.1f\n", op == 'S' ? res : res / 66);

	return EXIT_SUCCESS;
}



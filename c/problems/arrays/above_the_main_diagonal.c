#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int i, j;
	char op;
	float value;
	float result = 0;

	scanf("%c\n", &op);

	for (i = 0; i < 12; ++i) {
		for (j = 0; j <= i; ++j)
			scanf("%*f");

		for (; j < 12; ++j) {
			scanf("%f", &value);
			result += value;
		}
	}

	printf("%.1f\n", op == 'M' ? result / 66 : result);

	return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char op;
	int i, j;
	float value;
	float result = 0;

	scanf("%c", &op);

	for (i = 0; i < 12; ++i) {

		for (j = 0; j < i; ++j) {
			scanf("%f", &value);
			result += value;
		}

		for (; j < 12; ++j)
			scanf("%*f");
	}

	printf("%.1f\n", op == 'M' ? result / 66 : result);

	return EXIT_SUCCESS;
}




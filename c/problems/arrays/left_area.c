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

		for (j = 0; (i < 6 && j < i) || (i > 5 && j < (11 - i)) ; ++j) {
			scanf("%f", &value);
			res += value;
		}

		for (; j < 12; ++j)
			scanf("%*f");
	}

	printf("%.1f\n", op == 'S' ? res : res / 30);

	return EXIT_SUCCESS;

}




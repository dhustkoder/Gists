#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int divisor = 0;
	float res = 0;
	int input;


	for (;;) {

		if (scanf("%*[^\n]") == EOF)
			break;
		else if (scanf("%d\n", &input) == EOF)
			break;

		res += input;
		++divisor;
	}


	printf("%.1f\n", res / divisor);

	return EXIT_SUCCESS;
}


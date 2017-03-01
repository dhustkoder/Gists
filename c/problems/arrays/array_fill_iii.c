#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	double x;

	scanf("%lf", &x);

	for (i = 0; i < 100; ++i) {
		printf("N[%d] = %.4lf\n", i, x);
		x /= 2;
	}

	return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	const double kSqrt5 = sqrt(5);
	int n;

	scanf("%d", &n);

	printf("%.1lf\n", (pow((1 + kSqrt5) / 2, n) - pow((1 - kSqrt5) / 2, n)) / kSqrt5);

	return EXIT_SUCCESS;
}



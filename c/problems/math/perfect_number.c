#include <stdio.h>


int main(void)
{
	int test_cases, i;
	long x, sum, j;

	scanf("%d", &test_cases);

	for (i = 0; i < test_cases; ++i) {
		scanf("%ld", &x);

		for (j = 1, sum = 0; j < x; ++j) {
			if ((x % j) == 0)
				sum += j;

		}

		printf("%ld %s\n", x,
		       (sum == x) ? "eh perfeito" : "nao eh perfeito");

	}


	return 0;
}


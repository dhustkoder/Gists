#include <stdio.h>



int main(void)
{
	int i;
	float n;
	for (i = 0; i < 100; ++i) {
		scanf("%f", &n);
		if (n <= 10)
			printf("A[%d] = %.1f\n", i, n);
	}

	return 0;
}


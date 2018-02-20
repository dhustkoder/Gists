#include <stdio.h>


int main(void)
{
	int ninput;
	int x, y, i, j;
	long sum;

	scanf("%d", &ninput);

	for (i = 0; i < ninput; ++i) {
		scanf("%d %d", &x, &y);
		if ((x % 2) == 0)
			++x;

		for (j = 0, sum = 0; j < y; ++j, x += 2)
			sum += x;

		printf("%ld\n", sum);

	}

	return 0;
}


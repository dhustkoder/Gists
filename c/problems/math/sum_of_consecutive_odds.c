#include <stdio.h>

int main(void)
{
	int ninput, i, j, x, y;
	int begin, end;
	long sum;
	scanf("%d", &ninput);
	
	for (i = 0; i < ninput; ++i) {
		scanf("%d %d", &x, &y);
		sum = 0;

		if (x > y) {
			begin = ((y % 2) == 0) ? y + 1 : y + 2;
			end = x;
		} else {
			begin = ((x % 2) == 0) ? x + 1 : x + 2;
			end = y;
		}

		for (j = begin; j < end; j += 2)
			sum += j;

		printf("%ld\n", sum);
	}

	return 0;
}


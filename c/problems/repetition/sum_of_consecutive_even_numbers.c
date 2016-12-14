#include <stdio.h>


int main(void)
{
	int x, i;
	long sum;
	
	while (1) {
		scanf("%d", &x);

		if (x == 0)
			break;
		
		if ((x % 2) != 0)
			++x;

		for (i = 0, sum = 0; i < 5; ++i, x += 2)
			sum += x;

		printf("%ld\n", sum);
	}

	return 0;
}



#include <stdio.h>

int main(void)
{
	long x, y, begin, end, i;
	long sum = 0;
	scanf("%ld %ld", &x, &y);
	
	if (x > y) {
		begin = y;
		end = x + 1;
	} else {
		begin = x;
		end = y + 1;
	}

	for (i = begin; i < end; ++i) {
		if ((i % 13) != 0)
			sum += i;
	}

	printf("%ld\n", sum);
	return 0;
}

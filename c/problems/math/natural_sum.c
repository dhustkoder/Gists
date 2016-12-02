#include <stdio.h>

int main(void)
{
	long long a, b, sum;
	scanf("%lld %lld", &a, &b);

	sum = ((a + b) * ((b - a) + 1)) >> 1;
	printf("%lld\n", sum);
	
	return 0;
}


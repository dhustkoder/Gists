#include <stdio.h>


int main(void)
{
	int n;
	long result;
	scanf("%d", &n);

	for (result = n; n > 2; --n)
		result *= n - 1;

	printf("%ld\n", result);

	return 0;
}


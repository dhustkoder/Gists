#include <stdio.h>

int main(void)
{
	int a, n, sum, i;

	scanf("%d %d", &a, &n);

	while (n < 1)
		scanf("%d", &n);

	for (i = 0, sum = 0; i < n; ++i)
		sum += a++;

	printf("%d\n", sum);
	return 0;
}


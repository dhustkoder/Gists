#include <stdio.h>

int main(void)
{
	int n, i;
	while (scanf("%d", &n) != EOF) {
		for (i = 2; i <= n; ++i) {
			if ((i % 2) == 0) {
				printf("%d^2 = %d\n", i, i*i);
			}
		}
	}

	return 0;
}

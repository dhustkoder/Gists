#include <stdio.h>

int main()
{
	int i, j, n;
	scanf("%i", &n);
	for(i = 0, j = 1; i < n; ++i) {
		printf("%i %i %i PUM\n", j, j + 1, j + 2);
		j += 4;
	}
}

#include <stdio.h>

int main(void)
{
	int i, j, n;
	scanf("%i", &n);

	for(i = 0, j = 1; i < n; ++i, j += 4)
		printf("%i %i %i PUM\n", j, j + 1, j + 2);
	
	return 0;
}

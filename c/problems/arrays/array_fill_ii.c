#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int t;
	int i = 0;
	int j = 0;

	scanf("%d", &t);

	do {
		
		printf("N[%d] = %d\n", i, j);
		
		++i;
		++j;

		if (j >= t)
			j = 0;

	} while (i < 1000);
	

	return EXIT_SUCCESS;
}


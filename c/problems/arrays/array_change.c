#include <stdio.h>


int main(void)
{
	int array[20];
	register int i;

	for (i = 19; i >= 0; --i)
		scanf("%i", &array[i]);
	for (i = 0; i < 20; ++i)
		printf("N[%i] = %i\n", i, array[i]);

	return 0;
}


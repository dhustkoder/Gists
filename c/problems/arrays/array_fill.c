#include <stdio.h>

int main(void)
{
	int array[10];
	int x, i;
	scanf("%d", &x);
	array[0] = x;
	for (i = 1; i < 10; ++i)
		array[i] = array[i - 1] * 2;

	printf("N[0] = %d\nN[1] = %d\nN[2] = %d\nN[3] = %d\n"
	       "N[4] = %d\nN[5] = %d\nN[6] = %d\nN[7] = %d\n"
	       "N[8] = %d\nN[9] = %d\n",
	        array[0], array[1], array[2], array[3], array[4],
	        array[5], array[6], array[7], array[8], array[9]);
	return 0;
}


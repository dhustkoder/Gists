#include <stdio.h>

static int read_greater(const int num)
{
	int input;
	
	do {
		scanf("%d", &input);
	} while (input <= num);

	return input;
}

int main(void)
{
	int x, z, i, sum;
	
	scanf("%d", &x);

	z = read_greater(x);

	for (i = 0, sum = 0; sum < z; ++i)
		sum += x++;

	printf("%d\n", i);

	return 0;
}


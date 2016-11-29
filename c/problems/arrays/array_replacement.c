#include <stdio.h>

int main()
{
	int i;
	int input;
	for (i = 0; i < 10; i++) {
		scanf("%d", &input);
		if (input <= 0)
			printf("X[%d] = 1\n", i);
		else
			printf("X[%d] = %d\n", i, input);

	}

	return 0;
}


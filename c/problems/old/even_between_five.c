#include <stdio.h>

int main(void)
{
	int input;
	int evenCount = 0;
	int i;
	for(i = 0; i < 5 ; ++i) {
		scanf("%i", &input);
		if((input % 2) == 0)
			++evenCount;
	}

	printf("%i valores pares\n", evenCount);

	return 0;
}

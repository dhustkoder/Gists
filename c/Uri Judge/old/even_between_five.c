#include <stdio.h>

int main()
{
	int input;
	int evenCount = 0;
	for(int i = 0; i < 5 ; ++i) {
		scanf("%i", &input);
		if((input % 2) == 0)
			++evenCount;
	}

	printf("%i valores pares\n", evenCount);


}
#include <stdio.h>

int main(void)
{
	int nOfInputs;
	int total = 0;
	int input = 1;
	while(input > 0) {
		scanf("%i", &input);
		total += input, ++nOfInputs;
	}

	printf("%.2f\n", ((float)total / nOfInputs));
}

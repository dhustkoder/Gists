#include <stdio.h>


int main(void)
{
	enum { evens, odds, positives, negatives };
	int results[4];
	int input[5];
	int i;

	scanf("%i %i %i %i %i", &input[0], &input[1],
	      &input[2], &input[3], &input[4]);

	for(i = 0; i < 5; ++i) {
		if(input[i] == 0) {
			++results[evens];
			continue;
		}

		if((input[i] % 2) == 0)
			++results[evens];
		else
			++results[odds];

		if(input[i] > 0)
			++results[positives];
		else if(input[i] < 0)
			++results[negatives];
	}

	printf("%i valor(es) par(es)\n"
	       "%i valor(es) impar(es)\n"
	       "%i valor(es) positivo(s)\n"
	       "%i valor(es) negativo(s)\n",
	        results[evens], results[odds],
	        results[positives], results[negatives]);

	return 0;
}
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int dist;
	int dist_sum = 0;
	int divisor = 0;

	size_t size = 256;
	char* buffer = malloc(sizeof(char) * size);

	for (;;) {
		if (getline(&buffer, &size, stdin) == -1)
			break;
		else if (scanf("%d%*c", &dist) == EOF)
			break;

		dist_sum += dist;
		++divisor;
	}

	printf("%.1f\n", (float)dist_sum / (float)divisor);


	free(buffer);
	return EXIT_SUCCESS;
}


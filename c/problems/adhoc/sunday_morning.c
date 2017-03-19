#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int hours;
	int minutes;

	while (scanf("%d:%d", &hours, &minutes) != EOF) {
		minutes += hours * 60;
		minutes -= 7 * 60;
		printf("Atraso maximo: %d\n", minutes > 0 ? minutes : 0);
	}

	return EXIT_SUCCESS;
}


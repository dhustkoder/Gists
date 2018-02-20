#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long drakes, races, denom;
	div_t divr;
	scanf("%ld", &drakes);

	while (drakes > 0) {
		races = 0;
		
		while (drakes > 1) {
			denom = drakes > 2 ? 3 : 2;
			divr = div(drakes, denom);
			drakes = divr.quot + (divr.rem > 1 ? 1 : divr.rem);
			races += drakes;
		}

		printf("%ld\n", races);
		scanf("%ld", &drakes);
	}

	return 0;
}


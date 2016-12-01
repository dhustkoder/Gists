#include <stdio.h>

int main()
{
	long drakes, races, div, left, divider;
	scanf("%ld", &drakes);

	while (drakes > 0) {
		races = 0;
		while (drakes > 1) {
			divider = drakes > 2 ? 3 : 2;
			div = drakes / divider;
			left = (drakes % divider);
			left = left > 1 ? left / 2 : left;
			drakes = div + left;
			races += drakes;
		}	
		printf("%ld\n", races);
		scanf("%ld", &drakes);
	}

	return 0;
}


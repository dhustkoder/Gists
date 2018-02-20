#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int i;
	int t;
	long years;
	int pa, pb;
	double g1, g2;

	scanf("%d", &t);

	for (i = 0; i < t; ++i) {

		scanf("%d %d %lf %lf", &pa, &pb, &g1, &g2);
		years = 0;
		
		do {
			// floating point to int cast truncates toward 0
			// we're dealing with positive values, then the effect
			// is the same as floor
			pa += ((pa * g1) / 100.0);
			pb += ((pb * g2) / 100.0);
			++years;

			if (years > 100)
				break;
			
		} while (pa <= pb);

		if (years <= 100)
			printf("%ld anos.\n", years);
		else
			printf("Mais de 1 seculo.\n");
	}

	return EXIT_SUCCESS;
}



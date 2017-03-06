#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int i;
	int t;
	long years;
	double pa, pb;
	double g1, g2;

	scanf("%d", &t);

	for (i = 0; i < t; ++i) {

		scanf("%lf %lf %lf %lf", &pa, &pb, &g1, &g2);
		years = 0;
		
		do {
			pa += floor((pa * g1) / 100.0);
			pb += floor((pb * g2) / 100.0);
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



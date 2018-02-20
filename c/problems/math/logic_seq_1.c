#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, i, aux = 1;
	scanf("%d", &n);
	n *= 2;
	for (i = 0; i < n; ++i) {
		if ((i % 2) == 0) {
			printf("%.0f %.0f %.0f\n", pow(aux, 1), 
			        pow(aux, 2), pow(aux, 3));
		} else {
			printf("%.0f %.0f %.0f\n", pow(aux, 1), 
			        pow(aux, 2) + 1, pow(aux, 3) + 1);
			++aux;
		}
	}

	return 0;
}


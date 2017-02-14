#include <stdio.h>

int main(void)
{
	int ncases, i;
	long number, j;
	unsigned char is_prime;

	scanf("%i", &ncases);

	for (i = 0; i < ncases; ++i) {
		scanf("%ld", &number);
		
		if (number < 2) {
			is_prime = 0;
		} else {
			is_prime = 1;
			for (j = 2; j < number; ++j) {
				if ((number % j) == 0) {
					is_prime = 0;
					break;
				}
			}
		}

		printf("%ld %s primo\n", number, is_prime ? "eh" : "nao eh");
	}

	return 0;
}


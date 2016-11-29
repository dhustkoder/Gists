#include <stdio.h>

int main()
{
	unsigned long int ninput, first, second, i, j;
	scanf("%lu", &ninput);

	for (i = 0; i < ninput; ++i) {
		scanf("%lu %lu", &first, &second);
		if (second > first) {
			goto dont_fit;
		} else if (second != first) {
			for (j = 10; ; j *= 10) {
				const unsigned long int divisor = j / 10;
				const unsigned long int num1 = 
					(first % j) / divisor;
				const unsigned long int num2 =
					(second % j) / divisor;
				if (num1 != num2)
					goto dont_fit;
				else if (j > second)
					goto fit;
			}
		}

		fit:
			printf("encaixa\n");
			continue;
		dont_fit:
			printf("nao encaixa\n");
	}

	return 0;
}

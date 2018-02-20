#include <stdio.h>

int main(void)
{
	int ninput, i, n;
	int total_animals;
	int rabbits = 0, rats = 0, frogs = 0;
	char type;

	scanf("%d", &ninput);
	for (i = 0; i < ninput; ++i) {
		scanf("%d %c", &n, &type);
		switch (type) {
		case 'C': rabbits += n; break;
		case 'R': rats += n; break;
		case 'S': frogs += n; break;
		default: break;
		}
	}
	
	total_animals = rabbits + rats + frogs;

	printf("Total: %d cobaias\n"
	       "Total de coelhos: %d\n"
	       "Total de ratos: %d\n"
	       "Total de sapos: %d\n"
	       "Percentual de coelhos: %.2f %%\n"
	       "Percentual de ratos: %.2f %%\n"
	       "Percentual de sapos: %.2f %%\n",
	       total_animals, rabbits, rats, frogs,
	       (100.00 * rabbits) / total_animals,
	       (100.00 * rats) / total_animals,
	       (100.00 * frogs) / total_animals);

	return 0;
}


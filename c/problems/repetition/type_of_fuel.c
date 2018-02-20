#include <stdio.h>

static int read_option(void)
{
	int num;

	do {
		scanf("%d", &num);
	} while (num < 1 || num > 4);

	return num - 1;
}

int main(void)
{
	enum FuelTypes { Alcohol, Gasoline, Diesel };
	int fuel_cnt[3] = { 0 };
	int option;
	
	while ((option = read_option()) < 3)
		++fuel_cnt[option];

	printf("MUITO OBRIGADO\n"
	       "Alcool: %d\n"
	       "Gasolina: %d\n"
	       "Diesel: %d\n",
	       fuel_cnt[Alcohol],
	       fuel_cnt[Gasoline],
	       fuel_cnt[Diesel]);

	return 0;
}


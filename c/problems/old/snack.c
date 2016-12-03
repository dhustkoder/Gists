#include <stdio.h>

int main(void)
{
	enum PriceIndex { 
		Hotdog, SaladCheese, BaconCheese, 
		SimpleToast, Soda 
	};

	const float prices[5] = { 4.00, 4.50, 5.00, 2.00, 1.50 };
	enum PriceIndex x = 0;
	int qnt = 0;
	scanf("%i %i", ((int*)&x), &qnt);
	--x;
	if (x >= Hotdog || x <= Soda)
		printf("Total: R$ %.2f\n", prices[x] * qnt);

	return 0;

}

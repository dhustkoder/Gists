#include <stdio.h>
#include <math.h>

int main(void)
{
	int test_cases, i;
	int squares;
	long double grains;

	scanf("%d", &test_cases);

	for (i = 0; i < test_cases; ++i) {
		scanf("%d", &squares);
		grains = powl(2, squares);
		printf("%llu kg\n", (unsigned long long)((grains / 12) / 1000));
	}

	return 0;
}


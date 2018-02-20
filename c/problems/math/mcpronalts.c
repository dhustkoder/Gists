#include <stdlib.h>
#include <stdio.h>


int main(void)
{
	const float kPrices[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };

	int i;
	int idx;
	int qnt;
	int testcases;
	float result = 0;

	scanf("%d", &testcases);


	for (i = 0; i < testcases; ++i) {
		scanf("%d %d", &idx, &qnt);
		result += kPrices[idx - 1001] * qnt;
	}

	printf("%.2f\n", result);

	return EXIT_SUCCESS;
}



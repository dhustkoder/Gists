#include <stdio.h>
#include <stdlib.h>


inline float sum(const float values[12])
{
	int i;
	float res = 0;

	for (i = 0; i < 12; ++i)
		res += values[i];

	return res;
}


int main(void)
{
	int i, j;
	char op;
	float values[12];
	float result;

	scanf("%c\n", &op);

	for (j = 0; j < 12; ++j) {

		for (i = 0; i < j; ++i)
			scanf("%*f");

		scanf("%f", &values[j]);
		
		for (++i; i < 12; ++i)
			scanf("%*f");
	}

	if (op == 'S')
		result = sum(values);
	else
		result = sum(values) / 12;

	printf("%.1f\n", result);

	return EXIT_SUCCESS;
}


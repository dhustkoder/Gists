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
	int column;
	char op;
	float values[12];
	float result;

	scanf("%d %c", &column, &op);

	for (i = 0; i < 12; ++i) {
		
		for (j = 0; j < column; ++j)
			scanf("%*f");

		scanf("%f", &values[i]);

		for (++j; j < 12; ++j)
			scanf("%*f");

	}

	if (op == 'S')
		result = sum(values);
	else
		result = sum(values) / 12;

	printf("%.1f\n", result);

	return EXIT_SUCCESS;
}



#include <stdio.h>

int main()
{
	long double sum = 0;
	long double input;
	int i, j;
	char op_type;
	
	scanf("%c", &op_type);

	for (i = 1; i <= 5; ++i) {
		for (j = 0; j < i; ++j)
			scanf("%*f");

		for (j = i; j <= 11 - i; ++j) {
			scanf("%Lf", &input);
			sum += input;
		}

		for (j = 0; j < i; ++j)
			scanf("%*f");
	}

	if (op_type == 'S')
		printf("%.1Lf\n", sum);
	else
		printf("%.1Lf\n", sum / 30);

	return 0;
}

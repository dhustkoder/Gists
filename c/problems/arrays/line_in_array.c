#include <stdio.h>
#include <stdlib.h>

inline float sum(const float array[12])
{
	int i;
	float res = 0;
	for (i = 0; i < 12; ++i)
		res += array[i];

	return res;
}


int main(void)
{
	int i;
	int line;
	char op;
	float array[12];
	float result;

	scanf("%d %c", &line, &op);

	for (i = 0; i < line; ++i)
		scanf("%*f %*f %*f %*f %*f %*f %*f %*f %*f %*f %*f %*f");

	scanf("%f %f %f %f %f %f %f %f %f %f %f %f",
	       &array[0], &array[1], &array[2], &array[3], &array[4], &array[5],
	       &array[6], &array[7], &array[8], &array[9], &array[10], &array[11]);

	if (op == 'S')
		result = sum(array);
	else
		result = sum(array) / 12;

	printf("%.1f\n", result);

	return EXIT_SUCCESS;
}











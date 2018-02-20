#include <stdio.h>

int main(void)
{
	int ninput, i, x, y;
	scanf("%d", &ninput);
	for (i = 0; i < ninput; ++i) {
		scanf("%d %d", &x, &y);
		if (y != 0)
			printf("%.1f\n", ((float)x) / y);
		else
			printf("divisao impossivel\n");
	}

	return 0;
}

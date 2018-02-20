#include <stdio.h>

int main(void)
{
	int x, y;
	while (1) {
		scanf("%d %d", &x, &y);
		if (x == y)
			break;
		puts(x < y ? "Crescente" : "Decrescente");
	}

	return 0;
}


#include <stdio.h>

int main(void)
{
	int ncases;
	scanf("%d", &ncases);

	for (int i = 0; i < ncases; ++i) {
		int r1, r2;
		scanf("%d %d", &r1, &r2);
		printf("%d\n", r1 + r2);
	}

	return 0;
}

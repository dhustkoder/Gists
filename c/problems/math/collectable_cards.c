#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ninput, a, b, q, r, i;
	scanf("%d", &ninput);

	for (i = 0; i < ninput; ++i) {
		scanf("%d %d", &a, &b);	
		
		while (b != 0) {
			q = a / b;
			r = a - b * q;
			a = b;
			b = r;
		}

		printf("%d\n", a);
	}

	return 0;
}



#include <stdio.h>

int main()
{
	for (;;) {
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		int v = 1;
		int p = 0;
		int q = 0;

		int ara[n][n];

		int c = n;
		int r = 0;

		if (n%2 == 0)
			r = n / 2;
		else if (n%2 == 1)
			r = (n / 2) + 1;

		for (int i = 1; i <= r; i++) {
			for (int j = p; j < c; j++) {
				for (int k = q; k < c; k++)
		    		ara[j][k]=v;
			}
			v++;
			p++; q++; c--;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == 0)
	    			printf("%3d",ara[i][j]);
				else
					printf(" %3d",ara[i][j]);
			}
			printf("\n");
		}

		printf("\n");

	}

	return 0;
}

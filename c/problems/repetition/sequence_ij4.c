#include <stdio.h>

int main(void)
{
	float i;
	int j;
	int i_as_integer;

	for (i = 0; i < 2.2; i += 0.2) {
		i_as_integer = ((int)i);
		if ((i - i_as_integer) < 0.2) {
			for (j = 1; j < 4; ++j)
				printf("I=%d J=%d\n", i_as_integer, j + i_as_integer);
		} else {
			for (j = 1; j < 4; ++j)
				printf("I=%.1f J=%.1f\n", i, i + j);
		}
	}

	return 0;
}


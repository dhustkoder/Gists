#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	int64_t a, b;
	while (scanf("%" PRId64 " %" PRId64, &a, &b) != EOF) {
		if (a > b)
			printf("%" PRId64 "\n", a - b);
		else
			printf("%" PRId64 "\n", b - a);
	}

	return 0;
}


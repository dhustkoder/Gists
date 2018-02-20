#include <stdio.h>
#include <stdint.h>

int main(void)
{
	long long a, b;
	char buffer[512];
	int buffer_index = 0;
	while (scanf("%lld %lld", &a, &b) != EOF) {
		buffer_index += sprintf(&buffer[buffer_index], "%lld\n",
		                        a > b ? a - b : b - a);
		if (buffer_index > 450) {
			printf("%s", buffer);
			buffer_index = 0;
		}
	}

	if (buffer_index > 0)
		printf("%s", buffer);

	return 0;
}


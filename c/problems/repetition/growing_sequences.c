#include <stdio.h>

static char buffer[32767 * 6];

int main(void)
{
	int x, i;
	char* buffer_itr;

	while (1) {
		scanf("%d", &x);
		if (x == 0)
			break;

		for (i = 1, buffer_itr = &buffer[0]; i < x; ++i)
			buffer_itr += sprintf(buffer_itr, "%d ", i);
		sprintf(buffer_itr, "%d", i);
		puts(&buffer[0]);
	}

	return 0;
}

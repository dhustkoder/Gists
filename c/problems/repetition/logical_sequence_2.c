#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x, y, i;
	char* buffer;
	char* buffer_itr;

	buffer = buffer_itr = malloc(sizeof(char) * 600000);
	scanf("%d %d", &x, &y);
	
	for (i = 1; i <= y; ++i) {
		if ((i % x) != 0)
			buffer_itr += sprintf(buffer_itr, "%d ", i);
		else
			buffer_itr += sprintf(buffer_itr, "%d\n", i);
	}

	printf("%s", buffer);
	free(buffer);
	return 0;
}



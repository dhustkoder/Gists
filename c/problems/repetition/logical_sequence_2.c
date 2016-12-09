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
		buffer_itr += 
		  sprintf(buffer_itr, ((i % x) != 0) ? "%d " : "%d\n", i);
	}

	printf("%s", buffer);
	free(buffer);
	return 0;
}



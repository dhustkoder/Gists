#include <stdio.h>

static char buffer[600000];

int main(void)
{
	int x, y, i;
	char* buffer_itr = &buffer[0];
	scanf("%d %d", &x, &y);
	
	for (i = 1; i <= y; ++i) {
		buffer_itr += 
		  sprintf(buffer_itr, ((i % x) != 0) ? "%d " : "%d\n", i);
	}

	printf("%s", buffer);
	return 0;
}



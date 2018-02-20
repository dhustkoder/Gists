#include <stdio.h>
#include <stdlib.h>

inline void write_ho(char** itr)
{
	**itr = 'H';
	++(*itr);
	**itr = 'o';
	++(*itr);
}

int main(void)
{
	long n, i;
	scanf("%ld", &n);
	char* const buffer = malloc(sizeof(char) * (n * 3) + 2);
	char* itr = buffer;

	for (i = 0; i < (n - 1); ++i) {
		write_ho(&itr);
		*itr++ = ' ';
	}

	write_ho(&itr);
	*itr++ = '!';
	*itr++ = '\0';

	puts(buffer);
	free(buffer);
	return 0;
}


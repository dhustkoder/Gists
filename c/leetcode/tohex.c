#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

static char* tohex(const int32_t num)
{
	const char* const hex = "0123456789abcdef";
	char* const buff = calloc(10, sizeof(char));
	uint32_t n = (uint32_t)num;
	unsigned idx = 9;
	unsigned i;

	do {
		buff[--idx] = hex[n&0x0F];
		n >>= 4;
	} while (n != 0);

	for (i = 0; i < (9 - idx); ++i)
		buff[i] = buff[idx + i];
	buff[i] = '\0';

	return buff;
}


int main(void)
{
	char* h1 = tohex(15);
	char* h2 = tohex(32);
	char* h3 = tohex(-1);
	printf("15 = %s\n32 = %s\n-1 = %s\n", h1, h2, h3);
	free(h1);
	free(h2);
	free(h3);
	return 0;
}




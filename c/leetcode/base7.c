#include <stdlib.h>
#include <stdio.h>
#include <string.h>


static char* base7(const int num)
{
	static const char* const digits = "0123456";

	char* const str = malloc(32);

	if (num == 0) {
		str[0] = '0';
		str[1] = '\0';
		return str;
	}

	int n = num > 0 ? num : -num;
	int i = 31;

	do {
		str[i--] = digits[n % 7];
		n /= 7;
	} while (n != 0);

	if (num < 0)
		str[i--] = '-';

	memcpy(str, str + i + 1, 32 - i);
	str[32 - i] = '\0';

	return str;
}

int main(void)
{
	char* const a = base7(100);
	char* const b = base7(-7);

	printf("%s\n%s\n", a, b);

	free(a);
	free(b);
	return 0;
}


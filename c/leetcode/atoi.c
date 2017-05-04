#include <stdio.h>
#include <stdint.h>
#include <limits.h>


static int atoi(const char* const str)
{
	char aux;
	int sign = 1;
	int64_t r = 0;
	const char* p = str;

	while ((*p < '0' || *p > '9') && *p != '\0')
		++p;

	if (*p == '\0')
		return r;

	if (p != str) {
		aux = *(p - 1);
		if (aux != '-' && aux != '+' && aux != ' ')
			return r;
		else if (aux == '-')
			sign = -1;

		if ((p - str) > 1) {
			aux = *(p - 2);
			if (aux != ' ' && aux != '\t')
				return r;
		}
	}

	for (; *p >= '0' && *p <= '9'; ++p)
		r = (r * 10) + (*p - '0');

	r *= sign;

	return r > INT_MAX ? INT_MAX : r < INT_MIN ? INT_MIN : r;
}



int main(void)
{
	const char* const strs[] = { "015", "-015", "123", "321", "-9999", "+9999", "+-2", "    010", "2147483648" };
	int i;

	for (i = 0; i < (int)(sizeof(strs)/sizeof(strs[0])); ++i)
		printf("%d\n", atoi(strs[i]));

	return 0;
}


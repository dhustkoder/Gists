#include <stdio.h>
#include <stdint.h>
#include <limits.h>


static int atoi(const char* const str)
{
	int sign;
	int64_t limit;
	int64_t r = 0;
	const char* p = str;

	while (*p == ' ')
		++p;

	if (*p == '-') {
		limit = -((uint64_t)INT_MIN);
		sign = -1;
	} else {
		limit = INT_MAX;
		sign = 1;
	}

	if (*p == '-' || *p == '+')
		++p;

	for (; *p >= '0' && *p <= '9'; ++p) {
		r = (r * 10) + (*p - '0');
		if (r >= limit)
			return sign > 0 ? INT_MAX : INT_MIN;
	}

	return (int) (r * sign);
}


int main(void)
{
	const char* const strs[] = {
		"015", "-015", "123", "321", "-9999",
		"+9999", "+-2", "    010", "2147483648","  +  413",
		"9223372036854775809", "-2147483649", "18446744073709551617"
	};
	
	int i;

	for (i = 0; i < (int)(sizeof(strs)/sizeof(strs[0])); ++i)
		printf("%d\n", atoi(strs[i]));

	return 0;
}


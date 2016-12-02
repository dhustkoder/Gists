#include <stdio.h>

int main(void)
{
	const char* const base32_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
	char base32_str[128];
	base32_str[127] = '\0';
	unsigned long long number;
	int str_index;

	scanf("%llu", &number);
	while (number > 0) {
		str_index = 126;
		do {
			base32_str[str_index--] = base32_digits[number % 32];
			number /= 32;
		}  while (number > 0);
		printf("%s\n", &base32_str[str_index + 1]);
		scanf("%llu", &number);
	};
	puts("0");
	return 0;
}


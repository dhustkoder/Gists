#include <stdio.h>

int main(void)
{
	const char* const base32_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
	char base32_str[16];
	base32_str[15] = '\0';
	int str_index;
	unsigned long long input, number;

	do {
		scanf("%llu", &input);
		
		number = input;
		str_index = 14;
		
		do {
			base32_str[str_index--] = base32_digits[number % 32];
			number /= 32;
		}  while (number > 0);

		printf("%s\n", &base32_str[str_index + 1]);

	} while (input > 0);

	return 0;
}


#include <stdio.h>

int main(void)
{
	char base_32_digits[32] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
	  	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
	  	'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
	  	'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'
	};

	char converted_str[128];
	converted_str[127] = '\0';
	int index;
	unsigned long long number_to_convert;

	scanf("%llu", &number_to_convert);
	while (number_to_convert > 0) {
		index = 126;
		do {
			converted_str[index--] = 
				base_32_digits[number_to_convert % 32];
			number_to_convert /= 32;
		}  while (number_to_convert > 0);
		printf("%s\n", &converted_str[index + 1]);
		scanf("%llu", &number_to_convert);
	};

	return 0;
}

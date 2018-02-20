#include <stdio.h>

int main(void)
{
	const int leds_num[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	char buffer[110];
	int i, j, ninput;
	long sum;
	
	scanf("%d", &ninput);

	for (i = 0; i < ninput; ++i) {
		scanf("%s", buffer);
		
		for (j = 0, sum = 0; buffer[j] != '\0'; ++j)
			sum += leds_num[buffer[j] - '0'];

		printf("%ld leds\n", sum);
	}

	return 0;
}


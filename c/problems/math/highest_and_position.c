#include <stdio.h>

int main(void)
{
	int highest = 0, pos = 0, input, i;
	for (i = 1; i <= 100; ++i) {
		scanf("%d", &input);
		if (input > highest) {
			highest = input;
			pos = i;
		}
	}

	printf("%d\n%d\n", highest, pos);
	return 0;
}


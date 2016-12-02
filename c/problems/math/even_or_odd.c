#include <stdio.h>

int main(void)
{
	int ninput, i;
	long input;
	scanf("%d", &ninput);

	for (i = 0; i < ninput; ++i) {
		scanf("%ld", &input);
		
		if (input == 0) {
			printf("NULL\n");
			continue;
		}

		printf("%s %s\n", ((input % 2) == 0) ? "EVEN" : "ODD",
		       input < 0 ? "NEGATIVE" : "POSITIVE");
	}

	return 0;
}

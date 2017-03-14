#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int i;
	int tea;
	int answer;
	int result = 0;

	scanf("%d", &tea);

	for (i = 0; i < 5; ++i) {
		scanf("%d", &answer);
		if (answer == tea)
			++result;
	}

	printf("%d\n", result);

	return EXIT_SUCCESS;
}






#include <stdio.h>

static float read_note(void)
{
	float note;
	
	while (1) {
		scanf("%f", &note);
		if (note >= 0.0 && note <= 10.0)
			break;
		puts("nota invalida\n");
	}

	return note;
}

int main(void)
{
	float a = read_note();
	float b = read_note();
	printf("media = %.2f\n", (a + b) / 2);
	return 0;
}


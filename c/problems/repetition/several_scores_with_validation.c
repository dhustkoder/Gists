#include <stdio.h>

static float read_note(void)
{
	float note;

	while (1) {
		scanf("%f", &note);
		if (note >= 0.0 && note <= 10.0)
			break;
		puts("nota invalida");
	}

	return note;
}

static int read_option(void)
{
	int opt;
	
	do {
		printf("novo calculo (1-sim 2-nao)\n");
		scanf("%d", &opt);
	} while (opt != 1 && opt != 2);

	return opt;
}

int main(void)
{
	float a, b;
	
	do {
		a = read_note();
		b = read_note();
		printf("media = %.2f\n", (a + b) / 2);
	} while (read_option() == 1);

	return 0;
}


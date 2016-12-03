#include <stdio.h>

typedef struct Sides {
	float a, b, c;
} sides_t;

int is_triangle(sides_t*);

int main(void)
{
	sides_t sides;
	scanf("%f %f %f", &sides.a, &sides.b, &sides.c);

	if (is_triangle(&sides))
		printf("Perimetro = %.1f\n", sides.a + sides.b + sides.c);
	else
		printf("Area = %.1f\n", ((sides.a + sides.b) * sides.c) * 0.5f);
	
	return 0;
}


int is_triangle(sides_t* const sides)
{
	return (sides->a + sides->b) > sides->c
		&& (sides->a + sides->c) > sides->b
		&& (sides->b + sides->c) > sides->a;
}




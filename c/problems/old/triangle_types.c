#include <stdio.h>
#include <math.h>

typedef struct Sides {
	double a, b, c;
	int typesSize;
	const char* types[6];
} Sides;


static int is_not_triangle(Sides*);
static int is_rectangle(Sides*);
static int is_obtuse(Sides*);
static int is_acutangle(Sides*);
static int is_equilateral(Sides*);
static int is_isosceles(Sides*);
static void classify_triangle(Sides*);

int main(void)
{
	static Sides sides;
	int i;
	scanf("%lf %lf %lf", &sides.a, &sides.b, &sides.c);
	classify_triangle(&sides);

	for (i = 0; i < sides.typesSize; ++i)
		printf("%s\n", sides.types[i]);

	return 0;
}


void classifyTriangle(Sides* sides)
{
	sides->typesSize = 0;
	if (is_not_triangle(sides)) {
		sides->types[sides->typesSize++] = "NAO FORMA TRIANGULO";
		return;
	}

	if (is_rectangle(sides))
		sides->types[sides->typesSize++] = "TRIANGULO RETANGULO";

	else if (is_obtuse(sides))
		sides->types[sides->typesSize++] = "TRIANGULO OBTUSANGULO";

	else if (is_acutangle(sides))
		sides->types[sides->typesSize++] = "TRIANGULO ACUTANGULO";

	if(is_equilateral(sides))
		sides->types[sides->typesSize++] = "TRIANGULO EQUILATERO";
		
	else if (is_isosceles(sides)) 
		sides->types[sides->typesSize++] = "TRIANGULO ISOSCELES";
}


int is_not_triangle(Sides* const sides) 
{
	return (sides->a >= (sides->b + sides->c))
		|| (sides->b >= (sides->a + sides->c))
		|| (sides->c >= (sides->a + sides->b));
}

int is_rectangle(Sides* const sides) 
{
	return (pow(sides->a, 2) == (pow(sides->b, 2) + pow(sides->c, 2)))
		|| (pow(sides->b, 2) == (pow(sides->a, 2) + pow(sides->c, 2)))
		|| (pow(sides->c, 2) == (pow(sides->a, 2) + pow(sides->b, 2)));
}

int is_obtuse(Sides* const sides) 
{
	return (pow(sides->a, 2) > (pow(sides->b, 2) + pow(sides->c, 2)))
		|| (pow(sides->b, 2) > (pow(sides->a, 2) + pow(sides->c, 2)))
		|| (pow(sides->c, 2) > (pow(sides->a, 2) + pow(sides->b, 2)));
}

int is_acutangle(Sides* const sides) 
{
	return (pow(sides->a, 2) < (pow(sides->b, 2) + pow(sides->c, 2)))
		|| (pow(sides->b, 2) < (pow(sides->a, 2) + pow(sides->c, 2)))
		|| (pow(sides->c, 2) < (pow(sides->a, 2) + pow(sides->b, 2)));
}

int is_equilateral(Sides* const sides) 
{
	return sides->a == sides->b && sides->b == sides->c;
}

int is_isosceles(Sides* const sides) 
{
	return (sides->a == sides->b && sides->b != sides->c)
		|| (sides->b == sides->c && sides->c != sides->a)
		|| (sides->c == sides->a && sides->a != sides->b);
}

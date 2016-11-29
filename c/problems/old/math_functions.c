#include <stdio.h>
#include <math.h>

static int raf_func(const int x, const int y)
{
	return pow(x * 3, 2) + pow(y, 2);
}

static int beto_func(const int x, const int y)
{
	return ( pow(x, 2) * 2)  + pow(y * 5, 2);
}

static int carl_func(const int x, const int y)
{
	return (-100 * x) + pow(y, 3);
}


int main()
{
	int inputsz;
	int inX, inY, r, b, c;
	scanf("%i", &inputsz);
	for(; inputsz > 0; --inputsz) {
		scanf("%i %i", &inX, &inY);
		r = raf_func(inX, inY);
		b = beto_func(inX, inY);
		c = carl_func(inX, inY);
		if( r > b && r > c)
			printf("Rafael ganhou\n");
		else if(b > r && b > c)
			printf("Beto ganhou\n");
		else if(c > r && c > b)
			printf("Carlos ganhou\n");
	}



}
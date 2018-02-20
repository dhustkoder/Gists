/*
 * Write a function that computes the list of the first 100 Fibonacci numbers.
 * By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
 * and each subsequent number is the sum of the previous two. As an example,
 * here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.
 * */

/* Rafael Moura: rafaelmoura.dev@gmail.com
 * Language: C11
 * */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long double a = 0, b = 1, c, aux;

	printf("0: 0\n1: 1\n");

	for (int i = 2; i < 100; ++i) {
		c = a + b;

		printf("%d: %.0Lf\n", i, c);

		aux = b;
		b = c;
		a = aux;
	}


	return EXIT_SUCCESS;
}



/*
 * Write a function that combines two lists by alternatingly taking elements.
 * For example: given the two lists [a, b, c] and [1, 2, 3], the function should return [a, 1, b, 2, c, 3].
 * */


/* Rafael Moura: rafaelmoura.dev@gmail.com
 * Language: C11
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


static int* combine(const int* a, const int* b, const int size)
{
	int* c = malloc(sizeof(int) * size * 2);

	for (int i = 0; i < size; ++i) {

		*c = *a;
		++a;
		++c;

		*c = *b;
		++b;
		++c;
	}

	return c - (size * 2);
}

int main(void)
{
	const int a[3] = { 1, 2, 3 };
	const int b[3] = { 4, 5, 6 };
	_Static_assert(sizeof(a) == sizeof(b), "");
	const int size = sizeof(a) / sizeof(a[0]);

	int* const result = combine(a, b, size);

	for (int i = 0; i < size * 2; ++i)
		printf("%d\n", result[i]); 

	free(result);

	return EXIT_SUCCESS;
}



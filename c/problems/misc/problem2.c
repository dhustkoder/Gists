
/*
 * Write a function that combines two lists by alternatingly taking elements.
 * For example: given the two lists [a, b, c] and [1, 2, 3], the function should return [a, 1, b, 2, c, 3].
 * */


/* Rafael Moura: rafaelmoura.dev@gmail.com
 * Language: C11
 * */

#include <stdio.h>
#include <stdlib.h>


static void combine(const int* a, const int* b, const int size, int* dest)
{
	for (int i = 0; i < size; ++i) {

		*dest = *a;
		++a;
		++dest;

		*dest = *b;
		++b;
		++dest;
	}
}


static void print_nums(const int* const nums, const int size)
{
	if (size > 0) {
		printf("[%d", nums[0]);
		for (int i = 1; i < size; ++i)
			printf(", %d", nums[i]);
		printf("]\n");
	} else {
		printf("[]\n");
	}
}


int main(void)
{
	const int a[] = { 1, 2, 3 };
	const int b[] = { 4, 5, 6 };
	_Static_assert(sizeof(a) == sizeof(b), "");

	const int size = sizeof(a) / sizeof(a[0]);
	const int dest_size = size * 2;
	int dest[dest_size];

	printf("A: ");
	print_nums(a, size);
	printf("B: ");
	print_nums(b, size);

	combine(a, b, size, dest);

	printf("RESULT: ");
	print_nums(dest, dest_size);

	return EXIT_SUCCESS;
}



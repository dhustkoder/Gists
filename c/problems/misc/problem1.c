/* Write three functions that compute the sum of the numbers
 * in a given list using a for-loop, a while-loop, and recursion
 * */


/* Rafael Moura: rafaelmoura.dev@gmail.com
 * Language: C11
 * */


#include <stdio.h>
#include <stdlib.h>


static int sum_forloop(const int* const numbers, const int size)
{
	int result = 0;
	for (int i = 0; i < size; ++i)
		result += numbers[i];

	return result;
}


static int sum_whileloop(const int* const numbers, int size)
{
	int result = 0;
	while (--size >= 0)
		result += numbers[size];
	
	return result;
}


static int sum_recursive(const int* const numbers, const int size)
{
	if (size == 1)
		return numbers[0];
	return numbers[size - 1] + sum_recursive(numbers, size - 1);
}


int main(void)
{
	const int numbers[5] = { 10, 10, 10, 10, 10 };
	const int size = sizeof(numbers) / sizeof(numbers[0]);

	printf("FOR-LOOP: %d\n"
	       "WHILE-LOOP: %d\n"
	       "RECURSIVE: %d\n",
	       sum_forloop(numbers, size),
	       sum_whileloop(numbers, size),
	       sum_recursive(numbers, size));

	return EXIT_SUCCESS;
}




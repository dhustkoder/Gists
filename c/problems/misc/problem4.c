
/*
 * Write a function that given a list of non negative integers,
 * arranges them such that they form the largest possible number.
 * For example, given [50, 2, 1, 9], the largest formed number is 95021.
 * */

#include <stdio.h>
#include <stdlib.h>

/* Rafael Moura: rafaelmoura.dev@gmail.com
 * Language: C11
 * */


static void arrange(unsigned int* const nums, const unsigned char size)
{
	int leftmost_digits[size];
	for (int i = 0; i < size; ++i) {
		int number = nums[i];
		while (number != 0) {
			leftmost_digits[i] = number % 10;
			number /= 10;
		}
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (leftmost_digits[j + 1] > leftmost_digits[j]) {
				int aux = leftmost_digits[j];
				leftmost_digits[j] = leftmost_digits[j + 1];
				leftmost_digits[j + 1] = aux;

				aux = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = aux;
			}
		}
	}
}


static void print_nums(const unsigned int* const nums, const unsigned char size)
{
	printf("[%d", nums[0]);
	for (int i = 1; i < size; ++i)
		printf(", %d", nums[i]);
	printf("]\n");
}


int main(void)
{
	unsigned int nums[4] = {50, 2, 1, 9};
	const unsigned char size = sizeof(nums) / sizeof(nums[0]);
	printf("BEFORE: ");
	print_nums(nums, size);
	arrange(nums, size);
	printf("AFTER: ");
	print_nums(nums, size);

	return EXIT_SUCCESS;
}

/*
 * Write a program that outputs all possibilities 
 * to put + or - or nothing between the numbers 1, 2, ..., 9 (in this order)
 * such that the result is always 100. For example: 1 + 2 + 34 – 5 + 67 – 8 + 9 = 100.
 * */

/* Rafael Moura: rafaelmoura.dev@gmail.com
 * Language: C11
 * */

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	const int kTargetSum = 100;
	const int kNums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	const int kNumsSize = sizeof(kNums) / sizeof(kNums[0]);

	int r = 0;
	for (int i = 0; i < kNumsSize; ++i) {
		r += kNums[i];
	}

	printf("%d\n", r);

	return EXIT_SUCCESS;
}


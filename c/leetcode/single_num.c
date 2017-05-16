#include <stdio.h>
#include <stdlib.h>



static int singleNumber(const int* const nums, const int size)
{
	int i, j;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size; ++j)
			if (j != i && nums[i] == nums[j])
				break;
		if (j >= size)
			break;
	}
	return nums[i];
}





int main(void)
{
	const int cols = 5;
	const int rows = 3;
	const int a[3][5] = {
		{1, 1, 2, 2, 3},
		{1, 1, 2, 3, 3},
		{1, 2, 2, 3, 3}
	};

	int i;

	for (i = 0; i < rows; ++i)
		printf("%d\n", singleNumber(a[i], cols));

	return 0;
}





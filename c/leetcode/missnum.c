#include <stdlib.h>

int cmp(const void* const a, const void* const b)
{
	return (*((int*)a)) - (*((int*)b));
}

int missingNumber(const int* const nums, const int size)
{
	qsort(nums, size, sizeof(int), cmp);
	for (int i = 0; i < size; ++i) {
		if (nums[i] != i)
			return i;
	}
	return size;
}


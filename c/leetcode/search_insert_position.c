#include <stdio.h>
#include <stdlib.h>


static int searchInsert(const int* const nums, const int size, const int target)
{
	int i;
	for (i = 0; i < size; ++i)
		if (nums[i] >= target)
			break;
	return i;
}



int main(void)
{
	const int a[] = {1, 3, 5, 6};
	const int size = sizeof(a) / sizeof(a[0]);

	printf("%d\n%d\n%d\n%d\n",
	       searchInsert(a, size, 5),
	       searchInsert(a, size, 2),
	       searchInsert(a, size, 7),
	       searchInsert(a, size, 0));

	return 0;
}




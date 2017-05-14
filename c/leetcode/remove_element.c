#include <stdio.h>
#include <stdlib.h>


static int removeElement(int* const nums, int size, const int target)
{
	int i, j;

	for (i = 0; i < size;) {
		if (nums[i] == target) {
			for (j = i; j < (size - 1); ++j)
				nums[j] = nums[j + 1];
			--size;
		} else {
			++i;
		}
	}

	return size;
}


int main(void)
{
	int i;
	int arr[] = {3, 3, 2, 2, 3, 3};
	int size = sizeof(arr) / sizeof(arr[0]);

	puts("ARRAY:");
	for (i = 0; i < size; ++i)
		printf("%d\n", arr[i]);

	size = removeElement(arr, size, 3);

	puts("REMOVED ARRAY:");
	for (i = 0; i < size; ++i)
		printf("%d\n", arr[i]);

	return 0;
}

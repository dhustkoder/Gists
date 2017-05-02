#include <stdio.h>
#include <stdlib.h>


static int* twoSum(const int* const nums, const int size, const int target)
{
	int i, j;
	int* const r = malloc(sizeof(int) * 2);

	for (i = 0; i < size; ++i) {
		for (j = i + 1; j < size; ++j) {
			if ((nums[i] + nums[j]) == target) {
				r[0] = i;
				r[1] = j;
				return r;
			}
		}
	}

	free(r);
	return NULL;
}


int main(void)
{
	const int nums[] = {5, 2, 3, 4};
	int* const r = twoSum(nums, sizeof(nums) / sizeof(nums[0]), nums[0] + nums[3]);
	printf("[%d] = %d\n[%d] = %d\n", r[0], nums[r[0]], r[1], nums[r[1]]);
	return 0;
}


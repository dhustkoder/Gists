/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* const nums, const int size, const int target)
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


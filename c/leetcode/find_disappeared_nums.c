#include <stdlib.h>
#include <stdio.h>


#define abs(x) (x >= 0 ? x : -x)


int* find_disappeared_nums(int* const nums, int size, int* const retsize)
{
	int* buffer = malloc(sizeof(int) * size);
	int bufflen = 0;
	int i;
	int idx;

	for (i = 0; i < size; ++i) {
		idx = abs(nums[i]) - 1;
		nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
	}

	for (i = 0; i < size; ++i) {
		if (nums[i] > 0)
			buffer[bufflen++] = i + 1;
	}

	buffer = realloc(buffer, sizeof(int) * bufflen);
	*retsize = bufflen;
	return buffer;
}

int main(void)
{
	int nums[] = { 4, 3, 2, 7, 8, 2, 3, 1 };
	const int size = sizeof(nums) / sizeof(nums[0]);
	int i;
	int rsize;
	int* r;
	
	r = find_disappeared_nums(nums, size, &rsize);
	
	for (i = 0; i < rsize; ++i)
		printf("%d\n", r[i]);

	free(r);
	return 0;
}


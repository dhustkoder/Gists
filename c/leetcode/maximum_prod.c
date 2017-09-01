#include <stdio.h>
#include <stdint.h>



static int maximum_prod(const int* const nums, const int size)
{
	int vmax[3];
	int vmin[3];
	int vimax[3] = { -1, -1, -1 };
	int vimin[3] = { -1, -1, -1 };
	long max, min;
	int i, j;

	for (i = 0; i < 3; ++i) {
		max = 0;
		min = 0;
		for (j = 0; j < size; ++j) {
			if (nums[j] > max) {
				if (j == vimax[0] || j == vimax[1] || j == vimax[2])
					continue;
				max = nums[j];
				vimax[i] = j;
			} else if (nums[j] < min) {
				if (j == vimin[0] || j == vimin[1] || j == vimin[2])
					continue;
				min = nums[j];
				vimin[i] = j;
			}
		}
		vmax[i] = max;
		vmin[i] = min;
	}

	if ((vmin[0] * vmin[1]) > (vmax[1] * vmax[2])) {
		vmax[1] = -vmin[0];
		vmax[2] = -vmin[1];
		if (vmax[0] == 0)
			vmax[0] = vmin[2];
	}

	return vmax[0] * vmax[1] * vmax[2];
}



int main(void)
{
	const int nums[] = { -4, -3, -2, -1, 60 };
	const int size = sizeof(nums) / sizeof(nums[0]);
	printf("%d\n", maximum_prod(nums, size));
	return 0;
}



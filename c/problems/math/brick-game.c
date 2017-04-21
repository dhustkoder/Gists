#include <stdio.h>
#include <stdlib.h>


static inline void sort(int* const d, const int size)
{
	int i, j, tmp;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < (size - 1 - i); ++j) {
			if (d[j] > d[j + 1]) {
				tmp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = tmp;
			}
		}
	}
}


int main(void)
{
	int nums[11];
	int t;
	int size;
	int i, j;
	int aux;

	scanf("%d", &t);
	for (i = 0; i < t; ++i) {
		scanf("%d", &size);
		for (j = 0; j < size; ++j) {
			scanf("%d", &aux);
			nums[j] = aux;
		}
		sort(nums, size);
		printf("Case %d: %d\n", i + 1, nums[size / 2]);
	}

	return EXIT_SUCCESS;
}




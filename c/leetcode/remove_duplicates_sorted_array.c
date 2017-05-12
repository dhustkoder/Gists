#include <stdio.h>
#include <stdlib.h>


static int removeDuplicates(int* const a, int size)
{
	int sattled_pos = 0, examine_pos = 1;

	if (size < 1)
		return size;

	while (examine_pos < size) {
		while (a[examine_pos] == a[sattled_pos])
			++examine_pos;

		if (examine_pos >= size)
			break;

		++sattled_pos;

		if (sattled_pos != examine_pos)
			a[sattled_pos] = a[examine_pos];

		++examine_pos;
	}

	return sattled_pos + 1;
}


int main(void)
{
	int a[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9 };
	int size = sizeof(a) / sizeof(a[0]);
	int i;

	puts("ARRAY:");
	for (i = 0; i < size; ++i)
		printf("%d\n", a[i]);

	size = removeDuplicates(a, size);

	puts("REMOVED DUPLICATED ARRAY:");
	for (i = 0; i < size; ++i)
		printf("%d\n", a[i]);

	return 0;
}



#include <stdio.h>
#include <stdlib.h>


static double findMedianSortedArrays(const int* const array1, const int m, const int* const array2, const int n)
{
	double mid;
	int i, a, b;
	const int rsz = m + n;
	const int midx = rsz / 2;
	int* const r = malloc(sizeof(int) * rsz);

	for (i = a = b = 0; i < rsz; ++i) {
		if (a < m && b < n) {
			if (array1[a] < array2[b])
				r[i] = array1[a++];
			else
				r[i] = array2[b++];
		} else {
			if (a < m)
				r[i] = array1[a++];
			else
				r[i] = array2[b++];
		}
	}

	if ((rsz % 2) != 0)
		mid = r[midx];
	else
		mid = (r[midx] + r[midx - 1]) / 2.0;

	free(r);
	return mid;
}


int main(void)
{
	const int a[2] = { 1, 2 };
	const int b[2] = { 3, 4 };
	const int c[2] = { 1, 3 };
	const int d[1] = { 2 };
	printf("%f\n%f\n", findMedianSortedArrays(a, 2, b, 2),
	       findMedianSortedArrays(c, 2, d, 1));
	return 0;
}


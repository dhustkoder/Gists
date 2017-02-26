#include <stdio.h>
#include <stdlib.h>

struct Fib {
	int n;
	unsigned long long r;
};


inline struct Fib calc_fib(const int n)
{
	struct Fib ret;
	
	unsigned long long prev = 0;
	unsigned long long cur = 1;
	unsigned long long aux;
	int i;

	if (n > 0) {

		for (i = 1; i < n; ++i) {
			aux = cur;
			cur += prev;
			prev = aux;
		}

		ret.n = n;
		ret.r = cur;

	} else {

		ret.n = 0;
		ret.r = 0;

	}

	return ret;
}


int main (void)
{
	struct Fib* array;
	int testcount;
	int n;
	int i;

	scanf("%d", &testcount);

	array = malloc(sizeof(struct Fib) * testcount);

	for (i = 0; i < testcount; ++i) {
		scanf("%d", &n);
		array[i] = calc_fib(n);
	}

	for (i = 0; i < testcount; ++i)
		printf("Fib(%d) = %llu\n", array[i].n, array[i].r);

	free(array);
	return EXIT_SUCCESS;
}


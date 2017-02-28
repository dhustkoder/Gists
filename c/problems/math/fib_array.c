#include <stdio.h>
#include <stdlib.h>


typedef struct fib_t {
	int n;
	unsigned long long r;
} fib_t;


inline fib_t fib(const int n)
{
	fib_t ret;

	int i;
	unsigned long long aux;
	unsigned long long prev = 0;
	unsigned long long cur = 1;


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


int main(void)
{
	fib_t* array;

	int num_tests;
	int n;
	int i;

	
	scanf("%d", &num_tests);

	array = malloc(sizeof(fib_t) * num_tests);

	for (i = 0; i < num_tests; ++i) {
		scanf("%d", &n);
		array[i] = fib(n);
	}

	for (i = 0; i < num_tests; ++i)
		printf("Fib(%d) = %llu\n", array[i].n, array[i].r);

	free(array);
	return EXIT_SUCCESS;
}


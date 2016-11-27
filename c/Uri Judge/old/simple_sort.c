#include <stdio.h>

void msort(int* arr, int qnt);

int main()
{

	int a, b, c;
	scanf("%i %i %i", &a, &b, &c);
	int arr[3] = { a, b, c };
	msort(&arr[0], 3);

	for (int i = 0; i < 3; ++i)
		printf("%i\n", arr[i]);

	printf("\n%i\n%i\n%i\n", a, b, c);

	return 0;
}


void msort(int* const arr, const int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int hold = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = hold;
			}
		}
	}
}
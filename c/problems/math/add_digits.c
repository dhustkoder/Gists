#include <stdio.h>


static int add_digits(int num)
{
	while (num > 9) {
		int sum = 0;
		do {
			sum += num % 10;
			num /= 10;
		} while (num != 0);
		num = sum;
	}

	return num;
}


int main(void)
{
	const int nums[] = {
		38, 22, 33
	};
	
	const unsigned size = sizeof(nums)/sizeof(nums[0]);

	for (unsigned i = 0; i < size; ++i)
		printf("%d\n", add_digits(nums[i]));

	return 0;
}

#include <stdio.h>
#include <limits.h>
#include <stdint.h>


static int reverse(int n)
{
	int64_t r = 0;

	while (n != 0) {
		r = r * 10 + (n % 10);
		n /= 10;
	}

	return (r > INT_MAX || r < INT_MIN) ? 0 : (int) r;
}


int main(void)
{
	printf("x =  123, return  %d\nx = -123, return %d\n",
	       reverse(123), reverse(-123));

	return 0;
}

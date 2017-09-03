

int sum(int x, int y)
{
	int carry;
	while (y != 0) {
		carry = x&y;
		x ^= y;
		y = carry<<1;
	}

	return x;
}


int main(void)
{
	printf("%d\n", sum(10, 15));
	return 0;
}



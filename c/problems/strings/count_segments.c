#include <stdio.h>


static int count_segments(char* s)
{

	unsigned char seg = 0;
	int n = 0;
	while (*s != '\0') {
		if (*s != ' ' && !seg) {
			++n;
			seg = 1;
		} else if (*s == ' ') {
			seg = 0;
		}
		++s;
	}

	return n;
}


int main(void)
{
	printf("%d\n", count_segments("Hello, my name is John"));
	return 0;
}

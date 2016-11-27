#include <stdio.h>

int main()
{
	int in = 0;
	int out = 0;
	int num;
	int i;
	scanf("%i", &i);
	for(; i > 0; --i) {
		scanf("%i", &num);
		if( num < 10 || num > 20)
			++out;
		else
			++in;
	}

	printf("%i in\n%i out\n", in, out);
}

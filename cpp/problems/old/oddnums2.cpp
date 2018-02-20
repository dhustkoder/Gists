/*
	Read an integer value X and print the 6 consecutive odd numbers from X, 
	a value per line,  including X if it is the case.
*/

#include <cstdio>


int main()
{
	unsigned int X;
	std::scanf("%u", &X);

	for(unsigned int n = X, cnt = 0; cnt < 6; ++n)  {
		if( (n % 2) != 0 ) {
			std::printf("%u\n", n);
			++cnt;
		}
	}
}

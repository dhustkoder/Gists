#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char* intToRoman(int num)
{
	const int vals[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	const char* const algs[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	const int vals_size = sizeof(vals) / sizeof(vals[0]);
	int i;
	char* const str = calloc(10, sizeof(char));

	for (i = 0; i < vals_size; ++i) {
		while (num >= vals[i]) {
			num -= vals[i];
			strcat(str, algs[i]);
		}
	}

	return str;
}


int main(void)
{
	int i;

	for (i = 1; i < 10; ++i)
		printf("%s\n", intToRoman(i));

	return 0;
}


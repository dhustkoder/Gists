#include <stdio.h>

inline int is_multiple(const int a, const int b) 
{
	return (a % b == 0) || (b % a == 0);
}

int main()
{
	int a, b;
	scanf("%i %i", &a, &b);

	if (is_multiple(a, b))
		printf("Sao Multiplos\n");
	else
		printf("Nao sao Multiplos\n");
	
	return 0;
}
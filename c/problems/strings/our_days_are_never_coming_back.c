#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(void)
{
	const char* const kQuote = "LIFE IS NOT A PROBLEM TO BE SOLVED";
	char quote[35];
	int n;

	scanf("%d", &n);

	memcpy(&quote[0], kQuote, n);
	quote[n] = '\0';

	printf("%s\n", &quote[0]);

	return EXIT_SUCCESS;
}




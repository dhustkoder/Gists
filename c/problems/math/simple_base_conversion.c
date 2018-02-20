#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	long long num;
	char buffer[12];	

	for (;;) {

		scanf("%s", buffer);

		num = strtoll(buffer, NULL, 0);

		if (num < 0)
			break;

		printf(buffer[1] == 'x' ? "%lld\n" : "0x%llX\n", num);
	}



	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
	char msg[102];
	int i;
	int len;
	int ones = 0;

	scanf("%s", &msg[0]);
	len = (int) strlen(msg);

	for (i = 0; i < len; ++i)
		if (msg[i] == '1')
			++ones;

	msg[len] = (ones % 2) != 0 ? '1': '0';
	msg[len + 1] = '\0';

	printf("%s\n", msg);
	
	return EXIT_SUCCESS;
}




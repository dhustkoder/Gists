#include <stdio.h>


int main(void)
{
	char buffer[262];
	char* buffer_itr = &buffer[0];

	int n, i;
	long first, second, next;
	
	scanf("%d", &n);
	
	if (n < 3) {
		puts((n == 1) ? "0" : "0 1");
	} else {
		
		first = 0;
		second = 1;
		buffer_itr += sprintf(buffer_itr, "0 1");

		for (i = 2; i < n; ++i) {
			next = first + second;
			first = second;
			second = next;
			buffer_itr += sprintf(buffer_itr, " %ld", next);
		}

		puts(&buffer[0]);
	}

	return 0;
}


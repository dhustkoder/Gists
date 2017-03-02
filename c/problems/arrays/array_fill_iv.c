#include <stdio.h>
#include <stdlib.h>


static void print_array(const char* fmt, const int* array, const int count)
{
	int i;
	for (i = 0; i < count; ++i)
		printf(fmt, i, array[i]);
}

int main(void)
{
	int evens[5];
	int odds[5];
	int evenscount = 0;
	int oddscount = 0;

	int num;
	int i;

	for (i = 0; i < 15; ++i) {
		scanf("%d", &num);
		
		if ((num % 2) == 0) {
			evens[evenscount++] = num;

			if (evenscount > 4) {
				print_array("par[%d] = %d\n", evens, evenscount);
				evenscount = 0;
			} 

		} else {
			odds[oddscount++] = num;
			
			if (oddscount > 4) {
				print_array("impar[%d] = %d\n", odds, oddscount);
				oddscount = 0;
			}
		}
	}

	if (oddscount)
		print_array("impar[%d] = %d\n", odds, oddscount);
	if (evenscount)
		print_array("par[%d] = %d\n", evens, evenscount);

	return EXIT_SUCCESS;
}

